"""Genera Factor_Correccion_PCT.txt y Capitales_V2.txt a partir de los Excel.
Uso (desde la raiz del repositorio):
    python tools/generar_datos.py
  usa por defecto data/fuentes/*.XLSX y escribe en data/.  Tambien admite rutas explicitas:
    python tools/generar_datos.py <Irradiacion_PCT.XLSX> <Factor_Correccion_PCT.XLSX> <carpeta_salida>
Requiere: pip install openpyxl numpy
Formato: una linea por registro, campos separados por TAB, clave en la primera columna.
"""
import sys, os, re
import numpy as np
from openpyxl import load_workbook

# Mismo orden y mismas coordenadas que el array Ecapitales[52][2] de Form1.h
ECAP = [(42.9,-2.7),(39.0,-1.8),(38.4,-0.5),(36.9,-2.4),(43.4,-5.8),(40.7,-4.9),(38.9,-7.0),(39.6,2.6),
 (41.4,2.2),(42.3,-3.7),(39.5,-6.4),(36.5,-6.3),(43.5,-3.8),(40.0,0.0),(35.9,-5.3),(39.0,-3.9),(37.9,-4.8),
 (43.4,-8.4),(40.1,-2.1),(42.0,2.7),(37.2,-3.7),(40.6,-3.2),(43.3,-2.0),(37.3,-6.9),(42.1,-0.4),(37.8,-3.8),
 (42.6,-5.6),(41.7,1.2),(43.0,-7.6),(40.4,-3.7),(36.7,-4.4),(35.3,-3.0),(38.0,-1.1),(42.8,-1.6),(42.3,-7.8),
 (42.0,-4.5),(28.2,-15.4),(42.4,-8.6),(42.5,-2.4),(41.0,-5.6),(28.5,-16.2),(41.0,-4.1),(37.4,-6.0),(41.8,-2.5),
 (41.1,1.2),(40.4,-1.1),(39.9,-4.0),(39.5,-0.4),(41.7,-4.7),(43.3,-3.0),(41.5,-5.7),(41.7,-0.9)]

MJ_A_KWH = 3.6

def num(v):
    # El Excel tiene 3 celdas con errores de OCR (p.ej. 'l,25' en vez de 1,25; 'l,5l' en vez de 1,51)
    if isinstance(v, str):
        print("  aviso: celda corregida", repr(v), "->", v.replace('l', '1').replace(',', '.'))
        return float(v.replace('l', '1').replace(',', '.'))
    return v   # MJ/m2 -> kWh/m2 (= horas sol pico, HSP, por dia)

def main(irr_xlsx, fac_xlsx, out):
    os.makedirs(out, exist_ok=True)
    # ---- Capitales_V2.txt ----
    ws = load_workbook(irr_xlsx, data_only=True).active
    filas = [r for r in ws.iter_rows(values_only=True) if isinstance(r[0], (int, float))]
    assert len(filas) == 52
    claves = set()
    with open(os.path.join(out, "Capitales_V2.txt"), "w", encoding="utf-8", newline="\n") as fh:
        for (lat, lon), r in zip(ECAP, filas):
            # misma operacion que en el programa: float * int - float * int -> int
            k = int(np.float32(lat) * np.float32(1000) - np.float32(lon) * np.float32(10))
            assert k not in claves, "clave duplicada"; claves.add(k)
            vals = [v / MJ_A_KWH for v in r[2:14]]
            fh.write("\t".join([str(k)] + ["%.4f" % v for v in vals]) + "\n")
    # ---- Factor_Correccion_PCT.txt ----
    ws = load_workbook(fac_xlsx, data_only=True).active
    lat = None; n = 0
    with open(os.path.join(out, "Factor_Correccion_PCT.txt"), "w", encoding="utf-8", newline="\n") as fh:
        for r in ws.iter_rows(values_only=True):
            if isinstance(r[0], str):
                m = re.search(r"LATITUD\s*=\s*(\d+)", r[0])
                if m: lat = int(m.group(1))
            elif isinstance(r[0], (int, float)) and lat is not None:
                fh.write("\t".join([f"{lat}{int(r[0])}"] + ["%g" % num(v) for v in r[1:13]]) + "\n"); n += 1
    print("Capitales_V2.txt: 52 registros | Factor_Correccion_PCT.txt:", n, "registros")

if __name__ == "__main__":
    raiz = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
    args = sys.argv[1:4]
    if not args:
        args = [os.path.join(raiz, "data", "fuentes", "Irradiacion_PCT.XLSX"),
                os.path.join(raiz, "data", "fuentes", "Factor_Correccion_PCT.XLSX"),
                os.path.join(raiz, "data")]
    main(*args)
