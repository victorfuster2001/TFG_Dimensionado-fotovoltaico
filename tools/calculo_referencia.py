#!/usr/bin/env python3
"""Calculo de referencia (en Python) de las dos pestanas, para comparar con la aplicacion.

Reproduce paso a paso el algoritmo de src/Form1.h (dimensionado basico) y src/Resultado.h (estudio avanzado),
incluidos los redondeos a entero y las operaciones en coma flotante de 32 bits. NO es una validacion fisica del metodo:
sirve para comprobar que el .exe calcula lo mismo que el algoritmo descrito en docs/FUNCIONAMIENTO.md.

Ejemplos (desde la raiz del repositorio):
  python tools/calculo_referencia.py basico   --lat 39.445 --lon -0.431 --incl 18 --az 45 --pt 1500 \
         --consumo 250 230 220 200 190 200 260 270 210 200 220 260 --modo peor
  python tools/calculo_referencia.py detallado --consumo-anual 3500 --paneles 10 --carpeta data/ejemplo_Valencia
Requiere: pip install numpy
"""
import argparse, os, sys
import numpy as np

F32 = np.float32
RAIZ = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")

ECAP = [(42.9,-2.7),(39.0,-1.8),(38.4,-0.5),(36.9,-2.4),(43.4,-5.8),(40.7,-4.9),(38.9,-7.0),(39.6,2.6),
 (41.4,2.2),(42.3,-3.7),(39.5,-6.4),(36.5,-6.3),(43.5,-3.8),(40.0,0.0),(35.9,-5.3),(39.0,-3.9),(37.9,-4.8),
 (43.4,-8.4),(40.1,-2.1),(42.0,2.7),(37.2,-3.7),(40.6,-3.2),(43.3,-2.0),(37.3,-6.9),(42.1,-0.4),(37.8,-3.8),
 (42.6,-5.6),(41.7,1.2),(43.0,-7.6),(40.4,-3.7),(36.7,-4.4),(35.3,-3.0),(38.0,-1.1),(42.8,-1.6),(42.3,-7.8),
 (42.0,-4.5),(28.2,-15.4),(42.4,-8.6),(42.5,-2.4),(41.0,-5.6),(28.5,-16.2),(41.0,-4.1),(37.4,-6.0),(41.8,-2.5),
 (41.1,1.2),(40.4,-1.1),(39.9,-4.0),(39.5,-0.4),(41.7,-4.7),(43.3,-3.0),(41.5,-5.7),(41.7,-0.9)]
NOMBRES = ("ALAVA ALBACETE ALICANTE ALMERIA ASTURIAS AVILA BADAJOZ BALEARES BARCELONA BURGOS CACERES CADIZ CANTABRIA "
 "CASTELLON CEUTA CIUDAD_REAL CORDOBA LA_CORUNA CUENCA GIRONA GRANADA GUADALAJARA GUIPUZCOA HUELVA HUESCA JAEN LEON "
 "LERIDA LUGO MADRID MALAGA MELILLA MURCIA NAVARRA ORENSE PALENCIA LAS_PALMAS PONTEVEDRA LA_RIOJA SALAMANCA TENERIFE "
 "SEGOVIA SEVILLA SORIA TARRAGONA TERUEL TOLEDO VALENCIA VALLADOLID VIZCAYA ZAMORA ZARAGOZA").split()
DATOS_INV = [(2000,676.40),(3000,796.88),(4000,973.60),(5000,1057.15),(6000,1232.54),(10000,2820.95),(20000,3151.71)]
DIAS = [31,28,31,30,31,30,31,31,30,31,30,31]

def fila(path, clave):
    """Igual que buscarTerminoEnArchivo: fila que empieza por clave + TAB; devuelve los 12 valores."""
    for l in open(path, encoding="utf-8"):
        t = l.rstrip("\r\n").split("\t")
        if t[0] == clave: return [float(x) for x in t[1:13]]
    sys.exit("No hay datos para la clave %s en %s" % (clave, path))

def inversor(pot):
    aux = 0; pos = None
    while pos is None:
        for i, (p, _) in enumerate(DATOS_INV):
            if pot < p + aux * DATOS_INV[6][0] and pos is None: pos = i
        if pos is None: aux += 1
    return DATOS_INV[pos][0], int(DATOS_INV[pos][1] + aux * DATOS_INV[6][1]), 1 + aux

# ---------------------------------------------------------------- pestana 1
def basico(a):
    Pm, Vm, Voc, Isc, prpan, areap = a.pmp, a.vmp, a.voc, a.isc, a.precio, a.area
    npanel, kt, Daut, Pdmax, ninv = 0.9, 0.7, 4, 0.7, 0.95
    E = a.consumo if len(a.consumo) == 12 else a.consumo * 12
    incmenos = incmas = int(a.incl)
    while incmenos % 5 != 0 and incmas % 5 != 0: incmenos -= 1; incmas += 1
    inc = incmas if incmas % 5 == 0 else incmenos
    latent = int(a.lat)
    k = fila(os.path.join(a.datos, "Factor_Correccion_PCT.txt"), "%d%d" % (latent, inc))
    d = [np.sqrt((a.lat - la) ** 2 + (a.lon - lo) ** 2) for la, lo in ECAP]
    cap = int(np.argmin(d))
    clave = int(F32(ECAP[cap][0]) * F32(1000) - F32(ECAP[cap][1]) * F32(10))
    H = fila(os.path.join(a.datos, "Capitales_V2.txt"), str(clave))
    perd = a.az ** 2 * 3.5 * 0.00001
    G = [k[i] * H[i] * (1 - perd) for i in range(12)]
    if a.modo == "peor":
        if a.peor_mes_correcto:
            i = max(range(12), key=lambda m: E[m] / G[m]); Etm = E[i] * 1000 / 31; HSP = G[i]
        else:                                   # comportamiento actual del codigo (ver PROBLEMAS_CONOCIDOS.md, punto 2)
            Etm = 0.0; HSP = 0.0
            for i in range(12):
                if E[i] / G[i] > Etm: Etm = E[i] * 1000 / 31; HSP = G[i]
    else:
        Etm = sum(e * 1000 for e in E) / 365
        HSP = sum(G[i] * DIAS[i] for i in range(12)) / 365
    Pt = a.pt
    Vnom = 12 if Pt < 800 else 24 if Pt < 1600 else 48 if Pt < 3200 else 120
    Ctmax = (Etm / Vnom) / kt
    Epanel = int(npanel * HSP * Pm)
    x = Vnom / Vm; Nps = int(x); Nps += 1 if x - Nps > 0.2 else 0
    x = (Ctmax * Vnom) / Epanel; Npt = int(x); Npt += 1 if x - Npt > 0.2 else 0
    Npt = max(Npt, Nps)
    while Npt % Nps: Npt += 1
    Npp = Npt // Nps
    Cnom = Ctmax * Daut / Pdmax
    Vin, Iin = 1.1 * Nps * Voc, 1.2 * Npp * Isc
    Pinv = Pt / ninv
    if Npt * Pm * 1.5 > Pinv: Pinv = Npt * Pm
    _, prinv, Ninv = inversor(Pinv)
    prpan_t = int(Npt * prpan); prsop = Npt * 20; prins = Npt * 100; pring = 1000 if Pinv > 10000 else 500
    print("== PESTANA 1: DIMENSIONADO BASICO (modo: %s) ==" % ("peor mes" if a.modo == "peor" else "promedio mensual"))
    print("Latitud entera %d, inclinacion usada %d, capital mas cercana %s (clave %d)" % (latent, inc, NOMBRES[cap], clave))
    print("HSP por mes:", " ".join("%.2f" % g for g in G))
    print("Etmedio = %.1f Wh/dia   HSP de diseño = %.3f" % (Etm, HSP))
    print("Cuadros de depuracion que muestra la aplicacion al pulsar Calcula: Epanel = %d ; Ctmax = %.4f" % (Epanel, Ctmax))
    print("Tension nominal      %d V" % Vnom)
    print("Paneles  serie %d | paralelo %d | total %d | area %.2f m2" % (Nps, Npp, Npt, areap * Npt))
    print("Bateria  capacidad %.2f Ah a %d V" % (Cnom, Vnom))
    print("Inversor potencia nominal %.2f W  (%d ud.)" % (Pinv, Ninv))
    print("Regulador tension maxima %.3f V | corriente maxima %.3f A" % (Vin, Iin))
    print("Inversion: paneles %d | inversor %d | soporte %d | instalacion %d | ingenieria %d | TOTAL %d" %
          (prpan_t, prinv, prsop, prins, pring, prpan_t + prinv + prsop + prins + pring))

# ---------------------------------------------------------------- pestana 2
def leer_serie(path):
    v = []
    for l in open(path, encoding="utf-8", errors="ignore").read().replace("\r", "\n").split("\n"):
        l = l.strip()
        if len(l) > 14 and l[8] == ":" and l[13] == "," and l[:8].isdigit() and l[9:13].isdigit():
            l = l[14:].split(",")[0]
        try: v.append(F32(float(l.replace(",", "."))))
        except ValueError: pass
    return v

def detallado(a):
    Pm, prpan = a.pmp, a.precio
    Ea, Np = F32(a.consumo_anual), int(a.paneles)
    irr = leer_serie(os.path.join(a.carpeta, "Irradiancia.txt"))
    per = leer_serie(os.path.join(a.carpeta, "perfil_elec_V2_puntos.txt"))
    c = 0
    while len(per) < len(irr): per.append(per[c]); c += 1
    c = 0
    while len(per) > len(irr): irr.append(irr[c]); c += 1
    n = len(per); eauto = []
    for i in range(n):
        per[i] = F32(per[i] * Ea)
        irr[i] = F32(float(F32(F32(F32(irr[i] / F32(1000)) / F32(1000)) * F32(Pm)) * F32(Np)) * 0.8)
        eauto.append(irr[i] if per[i] > irr[i] else per[i])
    aux = n // 12
    G = [F32(0)] * 12; A = [F32(0)] * 12; Em = [F32(0)] * 12
    Gm = [0] * 12; Au = [0] * 12; Ex = [0] * 12; Emi = [0] * 12
    Gt = Et = Autot = Etot = 0
    for x in range(12):
        for j in range(n):
            if aux * x < j < aux * (x + 1):
                G[x] = F32(G[x] + irr[j]); A[x] = F32(A[x] + eauto[j])
                if x < 11: Em[x] = F32(Em[x] + per[j])
        Etot = int(F32(Em[x] + F32(Etot)))
        if x == 11: Em[x] = F32(Ea - F32(Etot))
        Gm[x], Au[x], Ex[x], Emi[x] = int(G[x]), int(A[x]), int(F32(G[x] - A[x])), int(Em[x])
        Gt += Gm[x]; Et += Ex[x]; Autot += Au[x]
    pc = Autot / float(Ea) * 100; pp = Autot / float(Gt) * 100
    ah_a, ah_e = Autot * 0.4, Et * 0.1
    prp = int(Np * prpan); prs = Np * 20; pri = Np * 350; pot = int(Np * Pm)
    _, prinv, _ = inversor(pot); pring = 1000 if pot > 10000 else 500
    tot = prp + prs + pri + pring        # el codigo original NO suma el inversor (PROBLEMAS_CONOCIDOS.md, punto 3)
    print("== PESTANA 2: ESTUDIO AVANZADO  (%d paneles, %.0f kWh/ano, %d horas) ==" % (Np, Ea, n))
    m = "Ene Feb Mar Abr May Jun Jul Ago Sep Oct Nov Dic".split()
    print("mes   consumo generacion excedentes autoconsumo")
    for x in range(12): print("%s %9d %10d %10d %11d" % (m[x], Emi[x], Gm[x], Ex[x], Au[x]))
    print("TOTAL %9d %10d %10d %11d" % (int(Ea), Gt, Et, Autot))
    print("Autoconsumo sobre consumo   %.1f %%" % pc)
    print("Autoconsumo sobre produccion %.1f %%" % pp)
    print("Ahorro autoconsumo %.1f EUR/ano | excedentes %.1f EUR/ano" % (ah_a, ah_e))
    print("Inversion (sin inversor, como el codigo original): paneles %d + soporte %d + instalacion %d + ingenieria %d = %d EUR" % (prp, prs, pri, pring, tot))
    print("   (inversor que corresponderia: %d EUR  ->  total con inversor %d EUR)" % (prinv, tot + prinv))
    print("Tiempo de recuperacion: %.2f anos (segun el codigo original)" % (tot / (ah_a + ah_e)))

if __name__ == "__main__":
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    s = p.add_subparsers(dest="cmd", required=True)
    for nombre in ("basico", "detallado"):
        q = s.add_parser(nombre)
        q.add_argument("--pmp", type=float, default=450); q.add_argument("--precio", type=float, default=170)
    q = s.choices["basico"]
    q.add_argument("--lat", type=float, required=True); q.add_argument("--lon", type=float, required=True)
    q.add_argument("--incl", type=float, required=True); q.add_argument("--az", type=float, required=True)
    q.add_argument("--pt", type=float, required=True)
    q.add_argument("--consumo", type=float, nargs="+", required=True, help="12 valores mensuales (kWh) o uno solo repetido")
    q.add_argument("--modo", choices=["peor", "promedio"], default="peor")
    q.add_argument("--peor-mes-correcto", action="store_true", help="usa el criterio previsto (mayor consumo/HSP) en vez del del codigo actual")
    q.add_argument("--vmp", type=float, default=42.06); q.add_argument("--voc", type=float, default=50.43)
    q.add_argument("--isc", type=float, default=11.36); q.add_argument("--area", type=float, default=2.20)
    q.add_argument("--datos", default=os.path.join(RAIZ, "data"))
    q = s.choices["detallado"]
    q.add_argument("--consumo-anual", type=float, required=True); q.add_argument("--paneles", type=int, required=True)
    q.add_argument("--carpeta", default=os.path.join(RAIZ, "data", "ejemplo_Valencia"))
    a = p.parse_args()
    basico(a) if a.cmd == "basico" else detallado(a)
