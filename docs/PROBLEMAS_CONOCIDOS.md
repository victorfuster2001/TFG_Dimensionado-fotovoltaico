# Problemas conocidos del código

Se han mantenido tal cual estaban en el proyecto original para no alterar los resultados sin que el autor lo decida.
Ordenados por impacto.

## Errores que dan resultados incorrectos
1. **«Actualizar valores» sobrescribe el precio del panel con su área** (`button2_Click`, en `Form1.h` y `Resultado.h`).
   La línea `prpan = stof(sarea);` debería ser `areapanel = stof(sarea);`. Tras pulsar el botón el panel pasa a costar 2,2 €
   (el valor del campo *Área*) y el área real nunca se actualiza.
2. **Modo *Peor mes* elige siempre enero** (`Form1.h`). Se compara `Emes[i] / Gmes[i]` (kWh por hora de sol) con `Etmedio`,
   que está en Wh/día y es mucho mayor; solo se actualiza con el primer mes, así que los demás nunca ganan. Debería compararse
   con el mayor cociente encontrado hasta el momento.
3. **El total de la inversión de la pestaña 2 no incluye el inversor** (`prtotal = prpaneles + prsoporte + prinstalacion + pring`).
   Falta `+ prinversor`, por lo que el tiempo de recuperación sale optimista.
4. **Decimales con coma.** Los campos de texto aceptan «150,5» (`esNumerico` admite la coma), pero después se convierte con
   `stof`, que se detiene en la coma: se lee 150. Lo mismo ocurre con latitud, longitud, precio, etc. Conviene escribir con punto
   o convertir la coma antes de llamar a `stof`.

## Incoherencias y aproximaciones
5. El coste de instalación es 100 €/panel en la pestaña 1 y 350 €/panel en la pestaña 2.
6. La pestaña 2 reparte las 8760 horas en 12 bloques de 730 h (no son meses naturales) y el bloque ignora su primera hora
   (`j > aux·x`), por lo que cada mes pierde una hora de generación.
7. El campo *Demanda anual* de la pestaña 2 y las etiquetas «Consumo kW», «Generación kW», etc. están rotulados en kW cuando
   las magnitudes son kWh.
8. La pestaña 1 no pasa ningún dato a la pestaña 2: hay que volver a introducir consumo anual y número de paneles.
9. El dimensionado usa un único rendimiento global (`kt = 0,7`, `npanel = 0,9`, `0,8` en el estudio horario) sin modelar
   temperatura, sombras, degradación ni pérdidas de cableado.
10. Precios fijos (paneles, inversores Huawei del 23/11/2023, soporte, instalación, ingeniería) y tarifas fijas
    (0,40 €/kWh autoconsumido y 0,10 €/kWh de excedente): hay que actualizarlos para que el presupuesto sea realista.

## Robustez
11. Un campo que solo contiene «.» o «-» pasa la validación (`esNumerico`) y hace lanzar una excepción a `stof`.
12. Los factores de corrección solo existen para las latitudes 28, 29 y 34–45 º; el rango de entrada permitido es 25–45 º
    (en las latitudes sin datos el programa muestra un aviso y no calcula).
13. El nombre del inversor de 3 kW figura como `SUN2000_3KT_L1` (probable errata de `3KTL`) y el de 20 kW como
    `SUN2000_2KTL_M2`; estos nombres no se muestran en la interfaz.
14. El botón inferior de la pestaña 1 dice «Comzar estudio detallado» (errata en la interfaz).
15. Al pulsar *Calcula* en la pestaña 1 se muestran dos cuadros de mensaje de depuración (valores de `Epanel` y `Ctmax`); son restos de pruebas y conviene eliminarlos (`MessageBox::Show` justo antes de calcular `Nps`).
