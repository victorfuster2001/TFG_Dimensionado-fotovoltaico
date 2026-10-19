# Guía de pruebas

Cómo comprobar que la aplicación compila, arranca y calcula lo que debe. Hay dos niveles:

- **Que el programa hace lo que describe `FUNCIONAMIENTO.md`** → se comprueba con los casos de abajo y con
  `tools/calculo_referencia.py`, un cálculo independiente en Python que reproduce el algoritmo (incluidos redondeos).
- **Que el método es físicamente razonable** → no lo puede demostrar ningún caso numérico del propio programa; se contrasta con
  una herramienta externa (apartado 6).

## 0. Preparación
1. Abre `Prueba1.sln` y compila en Debug/x64 (ver README). El evento posterior a la compilación copia junto al `.exe`
   (`x64\Debug\`) **los cuatro ficheros**: `Factor_Correccion_PCT.txt`, `Capitales_V2.txt`, y `Irradiancia.txt` y
   `perfil_elec_V2_puntos.txt` de `data/ejemplo_Valencia/`. Si no usas el `.sln`, cópialos a mano.
2. En todos los campos numéricos escribe los decimales **con punto** (con coma se leería solo la parte entera; ver
   `PROBLEMAS_CONOCIDOS.md`, punto 4).
3. Para el cálculo de referencia: `pip install numpy` y ejecuta desde la raíz del repositorio.

## 1. Pruebas de humo
| Prueba | Resultado esperado |
|---|---|
| Arrancar el `.exe` | Se abre la ventana «DIMENSIONADO BÁSICO» sin errores; el panel precargado es 42.06 / 10.7 / 450 / 50.43 / 11.36 / 170 / 2.20. |
| Botón *Cambiar* | El rótulo alterna entre «Peor mes» y «Promedio mensual». |
| *Actualizar valores* | Aparece «Valores actualizados». *(El precio del panel pasa a valer el área: error conocido nº 1.)* |
| *Comzar estudio detallado* | Se abre a pantalla completa la pestaña «ESTUDIO AVANZADO»; al cerrarla se vuelve a la primera. |

## 2. Validación de entradas
| Entrada | Resultado esperado con el código actual |
|---|---|
| Dejar campos vacíos y pulsar *Calcula* | Aviso «Error introduciendo los siguientes datos» con la lista de campos. |
| Texto no numérico (p. ej. `abc`) en un campo | El campo aparece en esa lista. |
| Latitud 46 o 24 / longitud 6 o −20 | Aviso con «Latitud» o «Longitud». |
| Latitud 31 (válida, pero sin datos de factor *k*) | Aviso «No hay factores de correccion para la latitud introducida…» y no calcula. |
| Latitud `39,5` (con coma) | **Se lee 39** sin avisar (error conocido nº 4). |
| Un campo con solo `.` o `-` | La aplicación falla con una excepción (error conocido nº 11). |
| Pestaña 2 sin `Irradiancia.txt` o sin el perfil | Aviso «No se han podido leer los ficheros de datos…». |

## 3. Pestaña 1 — casos con valores esperados
Entradas comunes: consumo mensual `250 230 220 200 190 200 260 270 210 200 220 260` kWh, latitud `39.445`, longitud `-0.431`,
inclinación `18`, azimut `45`, potencia `1500` W y el panel por defecto. Al pulsar *Calcula* aparecen **dos cuadros de depuración**
(valores de `Epanel` y `Ctmax`); acéptalos.

| Magnitud | Caso 1: *Peor mes* (código actual) | Caso 2: *Promedio mensual* |
|---|---|---|
| Cuadros de depuración (`Epanel` / `Ctmax`) | 992 / 480.03 | 1778 / 441.94 |
| Tensión nominal | 24 V | 24 V |
| Paneles serie / paralelo / total | 1 / 12 / 12 | 1 / 6 / 6 |
| Área ocupada | 26.4 m² | 13.2 m² |
| Capacidad de batería | 2743.03 Ah | 2525.39 Ah |
| Potencia del inversor | 5400 W | 2700 W |
| Regulador: tensión / corriente máx. | 55.473 V / 163.584 A | 55.473 V / 81.792 A |
| Inversión: paneles / inversor / soporte / instalación / ingeniería | 2040 / 1232 / 240 / 1200 / 500 | 1020 / 796 / 120 / 600 / 500 |
| **Total inversión** | **5212 €** | **3036 €** |

Comprueba también (intermedios que verás reflejados en el resultado):
- Capital elegida: **Valencia** (clave `39504`); latitud entera 39 e inclinación usada **20** (múltiplo de 5 más próximo a 18).
- HSP mensual esperada (kWh/m²·día): `2.45 3.28 4.38 5.00 5.48 5.94 6.33 5.77 5.00 3.87 2.94 2.20`.
- En el caso 1 el código elige **enero** como peor mes (error conocido nº 2): `Etmedio = 8064.5 Wh/día`. Con el criterio previsto
  (mayor consumo/HSP) saldría **diciembre**: 14 paneles. Se obtiene con `--peor-mes-correcto`.

Reproducción por línea de comandos:
```
python tools/calculo_referencia.py basico --lat 39.445 --lon -0.431 --incl 18 --az 45 --pt 1500 \
   --consumo 250 230 220 200 190 200 260 270 210 200 220 260 --modo peor
```
(`--modo promedio` para el caso 2.)

**Referencia adicional del autor.** Las etiquetas del diseñador de `Form1.h` traen valores de una ejecución anterior
(48 V, 3157.894775 W, 55.473 V, 27.264 A) que corresponden a `Pt = 3000 W` con 2 paneles (1 en serie, 2 en paralelo). Si introduces
`Pt = 3000` y obtienes 2 paneles, esos cuatro valores deben salir idénticos.

## 4. Pestaña 2 — caso con valores esperados
Entradas: consumo anual `3500`, número de paneles `10`, panel por defecto, ficheros de `data/ejemplo_Valencia/`. Pulsa *Buscar en fichero*.

| Mes | Consumo | Generación | Excedentes | Autoconsumo |
|---|---:|---:|---:|---:|
| Enero | 333 | 410 | 296 | 113 |
| Febrero | 329 | 481 | 356 | 124 |
| Marzo | 312 | 638 | 504 | 133 |
| Abril | 291 | 806 | 657 | 149 |
| Mayo | 270 | 743 | 597 | 146 |
| Junio | 253 | 775 | 635 | 140 |
| Julio | 248 | 813 | 675 | 138 |
| Agosto | 252 | 784 | 649 | 135 |
| Septiembre | 269 | 619 | 492 | 126 |
| Octubre | 291 | 489 | 373 | 115 |
| Noviembre | 312 | 422 | 307 | 115 |
| Diciembre | 340 | 346 | 236 | 109 |
| **Total** | **3500** | **7326** | **5777** | **1543** |

Otros valores: autoconsumo sobre consumo **44.1 %**; sobre producción **21.1 %**; ahorro **617.2 €/año** por autoconsumo y
**577.7 €/año** por excedentes; inversión mostrada **5900 €** (1700 + 200 + 3500 + 500, el código no suma el inversor);
recuperación **4.94 años** (error conocido nº 3; con el inversor serían 6957 € y ≈5.8 años).
Las cifras mensuales deben coincidir **exactamente**; si algún valor difiere en ±1 es redondeo de coma flotante y no es un fallo.
(El perfil del ejemplo es sintético: estos números solo sirven para validar el programa, no para dimensionar nada.)

```
python tools/calculo_referencia.py detallado --consumo-anual 3500 --paneles 10
```

## 5. Pruebas de coherencia (no necesitan valores de referencia)
| Prueba | Debe cumplirse |
|---|---|
| Pestaña 2 con 20 paneles en vez de 10 | La generación total se duplica (14657 ≈ 2 × 7326, salvo truncados mensuales); el autoconsumo **no** se duplica (1630) y su % sobre producción baja (11.1 %). |
| Pulsar *Buscar en fichero* dos veces seguidas | Mismos resultados las dos veces (no hay acumulación). |
| Cualquier fila mensual | `excedentes = generación − autoconsumo` y `autoconsumo ≤ min(consumo, generación)` (±1 por truncado). |
| Columna *Consumo* | Suma exactamente el consumo anual introducido (diciembre absorbe el ajuste). |
| Pestaña 1: azimut 0 / 45 / 90 | HSP de enero 2.64 / 2.45 / 1.89 (factor 1, 0.929 y 0.717 = `1 − az²·3,5·10⁻⁵`). |
| Pestaña 1: azimut 45 y −45 | Resultados idénticos. |
| Pestaña 1: *Promedio* frente a *Peor mes* con consumo estacional | Con *Peor mes* corregido salen más paneles que con *Promedio*. |
| Subir el consumo | Aumentan paneles, batería e inversión; nunca bajan. |

## 6. Contraste con una fuente externa
- **Generación anual.** En [PVGIS](https://re.jrc.ec.europa.eu/pvg_tools/es/) (sistema conectado a la red) introduce 4,5 kWp, la misma
  ubicación, inclinación 18 º, azimut 45 º y unas pérdidas del 20 %. La producción anual debería quedar en el mismo orden que los
  7326 kWh de la pestaña 2 (unos 7000–7700 kWh); si sale muy distinta, revisa los datos de entrada. *(Este contraste no se ha
  ejecutado aún; el CSV de ejemplo es de PVGIS-SARAH3, año 2023.)*
- **Las dos pestañas usan fuentes distintas.** La pestaña 1 usa tablas históricas por capital y la pestaña 2 la serie de PVGIS. En el
  ejemplo de Valencia la HSP media de la tabla es 4.39 kWh/m²·día (con las pérdidas por azimut) y la serie de PVGIS 2023 da
  5.59 kWh/m²·día en el plano inclinado: esa diferencia es esperable y no indica un error de código, pero conviene saber que el
  número de paneles de la pestaña 1 será conservador frente a la producción de la pestaña 2.

## 7. Comprobación de los datos
```
wc -l data/Capitales_V2.txt data/Factor_Correccion_PCT.txt      # 52 y 266 líneas
grep -P "^39504\t" data/Capitales_V2.txt                         # Valencia: 2.1111 2.9444 4.1389 ...
grep -P "^3935\t"  data/Factor_Correccion_PCT.txt                # latitud 39, inclinación 35
python tools/generar_datos.py && git diff --stat data            # regenerar no debe producir cambios
```
La fila de Valencia debe ser el Excel dividido entre 3,6 (enero: 7,6 MJ/m² → 2.1111 kWh/m²).

## 8. Lista de verificación
- [ ] Compila sin errores y arranca.
- [ ] Validaciones del apartado 2 se comportan como se indica.
- [ ] Casos 1 y 2 (apartado 3) coinciden con la tabla.
- [ ] Caso de la pestaña 2 (apartado 4) coincide con la tabla.
- [ ] Pruebas de coherencia (apartado 5) superadas.
- [ ] Contraste con PVGIS (apartado 6) en el mismo orden de magnitud.
