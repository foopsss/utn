# Compilación de ejercicios
Este documento explica como compilar los ejercicios que hice de las guías de preparación para los laboratorios de lenguajes. Se asume que los compiladores a utilizar son [Free Pascal](https://es.wikipedia.org/wiki/Free_Pascal) y [GCC](https://es.wikipedia.org/wiki/GNU_Compiler_Collection) (provisto en Windows como parte de [MinGW](https://es.wikipedia.org/wiki/MinGW)), ya que son los recomendados por la cátedra.

## Compilación manual de ejercicios
* __Pascal__: los ejercicios pueden ser compilados tanto en Linux como en Windows con una simple invocación al compilador: `fpc <nombre del archivo>.pas`.
* __C__: los ejercicios pueden ser compilados tanto en Linux como en Windows con una simple invocación al compilador: `gcc <nombre del archivo>.c -o <nombre del archivo>`.

## Compilación utilizando lang.py
```lang.py``` es un «pequeño» script multiplataforma de Python que sirve para automatizar la compilación y ejecución de los programas, así como la remoción de los ejecutables generados y cualquier otro archivo residual que pudiera llegar a quedar tras el proceso de compilación. Cuenta con los siguientes parámetros:

* ```-c```/```--compile```: indica que solo se desea compilar un ejercicio dado.
* ```-e```/```--execute```: indica que se desea compilar y ejecutar un ejercicio dado.
* ```-r```/```--remove```: indica que se desean remover los archivos resultantes de la compilación de un ejercicio dado.

Estos parámetros son excluyentes entre sí, lo que implica que solo se pueden usar individualmente y no en conjunto. Uno de ellos debe ser provisto obligatoriamente a la hora de ejecutar el script. 

En caso de usar los parámetros ```-c``` o ```-e``` también es posible incluir el parámetro ```-d```/```--debug```, con el cual se pueden producir ejecutables con símbolos de depuración. Si se indican los parámetros ```-e``` y ```-d```, el script ejecutará el programa indicado con GDB de forma automática.

El script puede ejecutarse de la siguiente forma:

```
python lang.py <archivo a compilar> <parámetros>
```

Entonces, si se quisiera compilar y ejecutar el programa 1-1.pas ubicado en «(X.2.1) Ejercicios de Pascal/G1» debería escribirse lo siguiente:

```
python lang.py 1-1.pas -e
```

El script determina automáticamente la ubicación del programa a través de una búsqueda recursiva en el directorio actual y en posibles subdirectorios existentes. En caso de haber múltiples archivos con el mismo nombre el script le avisará al usuario para que tome las medidas correspondientes a fin de corregir esa situación.
