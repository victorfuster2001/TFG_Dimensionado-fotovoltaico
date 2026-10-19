# Funcionamiento y metodología

Este documento describe, paso a paso, lo que calcula cada pestaña. Las fórmulas son las que implementa el código; los nombres
entre paréntesis son las variables de `src/Form1.h` y `src/Resultado.h`.

## 1. Pestaña «Dimensionado básico» (`Form1.h`)

### 1.1 Entradas y validación
- Consumo de los 12 meses (`E1…E12`, kWh) y potencia requerida `Pt` (W).
- Latitud (25–45 º), longitud (−19–5 º), inclinación y azimut. Fuera de rango se muestra un aviso con los campos erróneos.
- Datos del panel (`Vm`, `Im`, `Pm`, `Voc`, `Isc`, precio, área). Valores por defecto: 42,06 V · 10,7 A · 450 Wp · 50,43 V · 11,36 A · 170 € · 2,20 m².
- Método de diseño (`tipo`): *Peor mes* (por defecto) o *Promedio mensual*.

### 1.2 Irradiación en el plano del generador
1. **Latitud entera** = parte entera de la latitud. **Inclinación** = múltiplo de 5 º más próximo.
2. **Factor de corrección k** por mes: fila de `Factor_Correccion_PCT.txt` cuya clave es `latitud_entera` + `inclinación`
   (por ejemplo, 39 º y 35 º → `3935`). *k* es el cociente entre la energía diaria sobre una superficie orientada al ecuador e
   inclinada y la que recibe una superficie horizontal.
3. **Capital más cercana**: la de menor distancia euclídea `√(Δlat² + Δlong²)` (en grados) entre las 52 capitales del array `Ecapitales`.
4. **Irradiación horizontal** `H` (kWh/m²·día, por mes) de esa capital, de `Capitales_V2.txt`. La clave de la fila es
   `int(lat·1000 − long·10)` de la capital (Valencia: 39,5 / −0,4 → `39504`).
5. **Pérdidas por orientación** = `azimut² · 3,5·10⁻⁵` (azimut en grados; 45 º → 7,1 %, 90 º → 28,4 %). La fórmula es simétrica y
   supone 0 º = sur.
6. **HSP del mes** (`Gmes[i]`) = `k · H · (1 − pérdidas)`; equivale a las horas de sol pico diarias.

### 1.3 Energía diaria y horas de sol de diseño
| Método | Energía diaria `Etmedio` (Wh/día) | `HSP` |
|---|---|---|
| Peor mes | `E_mes · 1000 / 31` del mes más desfavorable (mayor cociente consumo/HSP) | HSP de ese mes |
| Promedio mensual | `Σ E_mes · 1000 / 365` | media de los 12 HSP ponderada por días del mes |

> El criterio de selección del peor mes tiene un error en el código actual (ver `PROBLEMAS_CONOCIDOS.md`).

### 1.4 Dimensionado
| Magnitud | Fórmula | Notas |
|---|---|---|
| Tensión nominal `Vnom` | 12 V si `Pt` < 800 W; 24 V si < 1600 W; 48 V si < 3200 W; si no, 120 V | |
| Carga diaria `Ctmax` (Ah/día) | `(Etmedio / Vnom) / kt` | `kt` = 0,7 (factor de pérdidas globales) |
| Energía por panel `Epanel` (Wh/día) | `npanel · HSP · Pm` | `npanel` = 0,9; se trunca a entero |
| Paneles en serie `Nps` | `Vnom / Vm` | parte entera; si la fracción es > 0,2 se sube uno |
| Paneles totales `Npt` | `Ctmax · Vnom / Epanel` | mismo redondeo; mínimo `Nps`; se sube hasta ser múltiplo de `Nps` |
| Ramas en paralelo `Npp` | `Npt / Nps` | |
| Área ocupada | `área_panel · Npt` | no se descuentan sombras ni separación entre filas |
| Capacidad de batería `Cnombat` (Ah) | `Ctmax · Daut / Pdmax` | `Daut` = 4 días de autonomía, `Pdmax` = 0,7 (profundidad de descarga) |
| Regulador | `Vinmax = 1,1 · Nps · Voc`; `Iinmax = 1,2 · Npp · Isc` | márgenes de seguridad del 10 % y 20 % |
| Potencia del inversor `Pinv` (W) | `Pt / ninv` (`ninv` = 0,95); si `Npt · Pm · 1,5 > Pinv`, entonces `Pinv = Npt · Pm` | comprueba que el inversor admita la potencia pico del campo |

### 1.5 Inversor y presupuesto
El inversor se elige de una tabla de Huawei SUN2000 (precios de AUTOSOLAR del 23/11/2023): el primero cuya capacidad es mayor que
`Pinv`. Si `Pinv` supera 20 kW se suman unidades de 20 kW (columna *Unidades* del desglose) y se elige además el modelo
adicional necesario.

| Modelo | Potencia (W) | Precio (€) |
|---|---|---|
| SUN2000-2KTL-L1 | 2000 | 676,40 |
| SUN2000-3KT-L1 | 3000 | 796,88 |
| SUN2000-4KTL-L1 | 4000 | 973,60 |
| SUN2000-5KTL-L1 | 5000 | 1057,15 |
| SUN2000-6KTL-L1 | 6000 | 1232,54 |
| SUN2000-10KTL-M1 | 10000 | 2820,95 |
| SUN2000-2KTL-M2 (unidad de 20 kW) | 20000 | 3151,71 |

El nombre que lleva el código para la última fila es `SUN2000_2KTL_M2`; por su potencia y precio corresponde a la unidad de 20 kW.

Desglose: paneles `Npt · precio` · soporte `20 €/panel` · instalación `100 €/panel` · inversor (tabla) · ingeniería `500 €`
(`1000 €` si `Pinv` > 10 kW) · **total** = suma.

## 2. Pestaña «Estudio avanzado» (`Resultado.h`)

Se ejecuta con el botón *Buscar en fichero* y necesita `Irradiancia.txt` y `perfil_elec_V2_puntos.txt` junto al `.exe`.

1. **Lectura**: cada fichero se convierte en un vector de 8760 valores (ver `DATOS.md`). Si tienen distinta longitud (p. ej. año
   bisiesto) se completa el más corto repitiendo valores desde el principio.
2. **Por hora** `i`:
   - consumo `C_i = perfil_i · consumo_anual` (kWh);
   - generación `P_i = G_i / 1000 / 1000 · Pm · Np · 0,8` (kWh): irradiancia en kW/m² por potencia pico del campo (en kW) y
     rendimiento global 0,8;
   - autoconsumo `A_i = min(C_i, P_i)`; déficit/superávit `C_i − P_i`.
3. **Agrupación mensual**: las 8760 horas se reparten en 12 bloques de 730 h (aproximación, no meses naturales). Para cada bloque
   se suman consumo, generación y autoconsumo; los excedentes son `generación − autoconsumo`. El consumo de diciembre se ajusta
   para que el total coincida con el consumo anual introducido.
4. **Indicadores**:
   - *Autoconsumo sobre consumo* = `Σ A_i / consumo anual · 100`
   - *Autoconsumo sobre producción* = `Σ A_i / Σ P_i · 100`
5. **Ahorro anual** = `0,40 €/kWh · autoconsumo` + `0,10 €/kWh · excedentes`.
6. **Inversión**: paneles `Np · precio` · soporte `20 €/panel` · instalación `350 €/panel` · inversor (misma tabla; se elige por
   `Np · Pm`) · ingeniería `500 €` (`1000 €` si la potencia instalada supera 10 kW).
7. **Amortización** = `inversión total / ahorro anual` (años).

## 3. Constantes del modelo

| Constante | Valor | Dónde | Significado |
|---|---|---|---|
| `kt` | 0,7 | Form1 | Factor de pérdidas globales del sistema autónomo |
| `npanel` | 0,9 | Form1 | Rendimiento del panel en el dimensionado básico |
| `Daut` | 4 días | Form1 | Autonomía de la batería |
| `Pdmax` | 0,7 | Form1 | Profundidad máxima de descarga |
| `ninv` | 0,95 | Form1 | Rendimiento del inversor |
| 0,8 | — | Resultado | Rendimiento global en el estudio horario |
| 0,40 / 0,10 €/kWh | — | Resultado | Valor del kWh autoconsumido / excedente |
| 20 €, 100 € / 350 € | por panel | Form1 / Resultado | Soporte; instalación (pestaña 1 / pestaña 2) |
| 500 € / 1000 € | — | ambas | Ingeniería (hasta / más de 10 kW) |
