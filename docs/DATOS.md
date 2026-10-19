# Formato de los ficheros de datos

El programa busca los cuatro ficheros en **la carpeta del ejecutable** (`.exe`). Todos son texto plano.

## Tablas incluidas (`data/`)

Las genera `tools/generar_datos.py` a partir de los Excel de `data/fuentes/`. Una fila por línea, campos separados por **tabulador**,
clave en la primera columna. El programa busca la fila cuya línea **empieza** por la clave seguida de un tabulador.

### `Factor_Correccion_PCT.txt`
Clave = `latitud` + `inclinación`, sin separador (`28` + `0` → `280`; `39` + `35` → `3935`), seguida de 12 factores *k* (enero–diciembre).
- Latitudes disponibles: 28, 29 y 34–45 º (si se introduce otra, el programa avisa de que no hay datos).
- Inclinaciones: 0 a 90 º en pasos de 5 º → 14 latitudes × 19 inclinaciones = 266 filas.
```
3935	1.38	1.25	1.12	...        (39 º de latitud, 35 º de inclinación)
```

### `Capitales_V2.txt`
Clave = `int(lat·1000 − long·10)` calculada en coma flotante de 32 bits con las coordenadas de la capital (igual que hace el programa),
seguida de 12 valores de irradiación diaria media mensual sobre superficie horizontal en **kWh/m²·día** (horas de sol pico).
El Excel de origen está en MJ/m²·día; el generador divide entre 3,6.
```
39504	2.1111	2.9444	4.1389	...       (Valencia: 39,5 / −0,4)
```
Las 52 filas siguen el orden y las coordenadas del array `Ecapitales` de `Form1.h`.

### Regenerar
```
pip install openpyxl numpy
python tools/generar_datos.py          # lee data/fuentes/*.XLSX y escribe en data/
```
El Excel de factores tenía tres celdas con errores de OCR (`l,25`, `l,5l`, `l,25`, todas en latitud 39) que el generador corrige a 1,25 / 1,51 / 1,25.

## Ficheros del usuario

### `Irradiancia.txt` — serie horaria de PVGIS
Irradiancia global sobre el plano del generador, en W/m², una hora por fila (8760 valores en un año normal).
1. Entra en la herramienta de series horarias de [PVGIS](https://re.jrc.ec.europa.eu/pvg_tools/es/) e indica la ubicación.
2. Marca la irradiancia sobre el plano inclinado y fija **la misma inclinación y azimut** que usarás en el diseño
   (en PVGIS el azimut 0 º es el sur y 90 º el oeste).
3. Descarga el CSV y cópialo junto al `.exe` con el nombre `Irradiancia.txt`.

Se puede usar el CSV **tal cual** (el programa ignora la cabecera y el pie y toma la columna `G(i)` de las filas
`AAAAMMDD:HHMM,G(i),…`) o una lista simple con un número por línea (coma o punto decimal; saltos `\r`, `\n` o `\r\n`).
Las líneas no numéricas se ignoran. Ejemplo: `data/ejemplo_Valencia/Irradiancia.txt`.

### `perfil_elec_V2_puntos.txt` — perfil de consumo horario
Un valor por línea, 8760 valores, **normalizado para que la suma del año sea 1** (fracción del consumo anual que corresponde a
cada hora). El programa lo multiplica por el consumo anual introducido. Mismo formato de lectura que el anterior (usa punto decimal).

`data/ejemplo_Valencia/perfil_elec_V2_puntos.txt` es un perfil **sintético** (curva diaria con picos de mañana y tarde y ligera
variación estacional) generado solo para poder probar la pestaña; sustitúyelo por el perfil real del hogar.

### Coherencia entre ambos
Las dos series deben cubrir el mismo periodo. Si difieren en longitud (p. ej. 8760 frente a 8784 por año bisiesto), el programa
completa la más corta repitiendo valores desde el principio.
