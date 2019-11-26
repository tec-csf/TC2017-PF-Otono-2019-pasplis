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

Esperamos que este programa pueda ser usados para los tranportes publicos los cuales son los mas usuales en Mexico, ka forma en lo que lo hicimos es usando diagramas de grafos de *Prim* el peso siendo el nivel de trafico de la calle que usaremos, de este forma se puede calcuar la mejor ruta para llegar a todas las paradas.

## 3. Solución secuencial

Para la solución secuencial de este problema, nos enfocamos en analizar un coche a la vez, mas que nada por la falta de recursos que se tiene en la programación secuencial. Al intentar resolver este problema, de la manera propuesta, podemos llegar a ver como habíamos planteado el problema e incluso podemos decir si vale la pena hacer *n* número de paradas, ocasionando que el piloto analice la situación y deduzca si vale la pena seguir en la carrera con el mismo _set_ de llantas o cambiarlo por uno nuevo.</br> 

## 4. Análisis de los inhibidores del paralelismo

Los inhibidores principales de paralelismo que se encontraron fueron los siguientes:</br>

* No se modificó la sección en donde se añaden/remueven nodos debido a que le tomaría mas tiempo por la cantidad de veces que debería llevarse a cabo

## 5. Solución paralela

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados

La tabla de resultados puede ser encontrada en [este](https://github.com/tec-csf/TC2017-PF-Otono-2019-pasplis/blob/master/docs/Resultados.xlsx) Excel, se separaron en cuatro tablas, cada una con el diferente tipo de balanceo que se solicitó, lo demás son los datos que se usaron para poder correrlo.

## 7. Gráfica(s) comparativa(s)

Para las gráficas comparativas, las colocamos en el folder llamado _docs_, puede ser encontrado [aquí](https://github.com/tec-csf/TC2017-PF-Otono-2019-pasplis/tree/master/docs).</br>

## 8. Interpretación de los resultados

Este proyecto nos enseñó unos resultados que no parecen tener mucho sentido al verlos sin entender lo que está pasando en el fondo, como los algoritmos paralelos, tienen que pasar *n* número de veces para poder obtener un resultado concreto, este va a demorar unos milisegundos mas, por esto mismo.</br>

Al correr el código secuencial, se está pasando una sola vez por el mismo proceso y es por esto mismo que es un código mas rápido en el sentido que su tiempo de ejecución, en algunos casos, es menor al del programa paralelo.

## 9. Guía paso a paso

Para poder ejecutar el código en paralelo es necesario estar en la carpeta correcta, esta siendo *paralelo* y posteriormente correr el siguiente comando en su terminal:</br>

gcc -fopenmp PrimPar.c</br>

Al correrlo se debería ver un documento llamado *a.out*, para poder correrlo se escribe, en la misma carpeta el siguiente comando:</br>

*./a.out* </br>

Al hacerlo, le va a pedir al usuario que inserte el número de paradas que deberá hacer el camión, por lo tanto el usuario deberá insertar un número positivo y este mismo conllevará a que se inicializen los pesos de este algoritmo en aleatorio.</br>

Para poder ejecutarlo en secuencial se deberá cambiar de carpeta, esta tiene el nombre de *secuencial* y allí se compilará con este comando en su terminal:</br>

gcc -fopenmp PrimSec.c</br>

Aunque este no sea en paralelo, se tuvieron dificultades al intentar medir el tiempo de este mismo, por lo tanto se usó una función de la librería de OpenMP para que la medición de su tiempo fuese igual.</br>

Ahora, para poder correr el código, es necesario escribir el siguiente comando en su terminal:</br>

*./a.out*</br>

Este igual le pedirá un número para que se puedan inicializar la cantidad de veces que se debería de detener el camión y, posteriormente, se inicializarán los pesos con números aleatorios, estos dependiendo de que valor se haya ingresado anteriormente.</br>

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
