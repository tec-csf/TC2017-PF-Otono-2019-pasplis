# *Las paradas de un camión*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *Luis Daniel Roa González*           *A01021960*
2. *Christian Alberto Dalma Schultz*    *A01423166*

---
## 1. Aspectos generales

### 1.1 Requerimientos

A continuación se mencionan los requerimientos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir el problema a resolver.
* El proyecto deberá utilizar [OpenMP](https://www.openmp.org/) para la implementación del código paralelo.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.

### 1.2 Estructura del repositorio
El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# este archivo
    - secuencial		# Carpeta con la solución secuencial
    - paralelo			# Carpeta con la solución paralela
    - docs              # Carpeta con los documentos, tablas, gráficas, imágenes
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Descripción de la solución secuencial con referencia (enlace) al código secuencial alojado en la carpeta [secuencial](secuencial/).
* Análisis de los inhibidores de paralelismo presente y una explicación de cómo se solucionaron.
* Descripción de la solución paralela con referencia (enlace) al código paralelo alojado en la carpeta [paralelo](paralelo/).
* Tabla de resultados con los tiempos de ejecución medidos para cada variante de la solución secuencial vs. la solución paralela, teniendo en cuenta: 5 tamaños diferentes de las entradas, 5 opciones diferentes de números de CPU (threads), 4 ocpiones diferentes de balanceo (*auto, guided, static, dynamic*).
* Gráfica(s) comparativa(s) de los resultados obtenidos en las mediciones.
* Interpretación de los resultados obtenidos.
* Guía paso a paso para la ejecución del código y replicar los resultados obtenidos.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Descripción del problema

La *Ciudad de México* es uno de los estados de la republica que sufre de la mayor cantidad de trafico en la Republica Mexicana devido a la cantidad de carros en ella, esto es un problema ya que los ciudadanos quieren llegar  asus destinos de la manera mas rapida posible, y no confian en el transporte publico y las rutas que llevan.</br>

Con este programa estamos enfocados en utilizar un progrmama que le permita  alos usuarios encontrar el mejor camino que puede haber para llegar a todos los lugares de la forma mas eficientes.</br>

Esperamos que este programa pueda ser usados para los tranportes publicos los cuales son los mas usuales en Mexico, ka forma en lo que lo hicimos es usando diagramas de grafos de "Prim" el peso siendo el nivel de trafico de la calle que usaremos, de este forma se puede calcuar la mejor ruta para llegar a todas las paradas.

## 3. Solución secuencial

Para la solución secuencial de este problema, nos enfocamos en analizar un coche a la vez, mas que nada por la falta de recursos que se tiene en la programación secuencial. Al intentar resolver este problema, de la manera propuesta, podemos llegar a ver como habíamos planteado el problema e incluso podemos decir si vale la pena hacer *n* número de paradas, ocasionando que el piloto analice la situación y deduzca si vale la pena seguir en la carrera con el mismo _set_ de llantas o cambiarlo por uno nuevo.</br> 

## 4. Análisis de los inhibidores del paralelismo

*[Incluya aquí el análisis de los inhibidores presentes en su problema, así como la solución a los mismos.]*

## 5. Solución paralela

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados

*[Incluya aquí la tabla con los resultados de las mediciones.]*

## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*

## 8. Interpretación de los resultados

*[Incluya aquí la interpretación de los resultados.]*

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
