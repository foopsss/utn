# Uso de lang.py
```lang.py``` es un script multiplataforma de Python que sirve para automatizar la compilación y ejecución de distintos programas en el repositorio, así como la remoción de los ejecutables generados y cualquier otro archivo residual que pudiera llegar a quedar tras el proceso de compilación. Es uno de los scripts disponible en la carpeta «_scripts/» en la raiz del repositorio, y debe ejecutarse desde ahi. Cuenta con los siguientes parámetros:

* ```-c```/```--compile```: indica que solo se desea compilar un ejercicio dado.
* ```-e```/```--execute```: indica que se desea compilar y ejecutar un ejercicio dado.
* ```-r```/```--remove```: indica que se desean remover los archivos resultantes de la compilación de un ejercicio dado.

Estos parámetros son excluyentes entre sí, lo que implica que solo se pueden usar individualmente y no en conjunto. Uno de ellos debe ser provisto obligatoriamente a la hora de ejecutar el script. 

En caso de usar los parámetros ```-c``` o ```-e``` también es posible incluir el parámetro ```-d```/```--debug```, con el cual se pueden producir ejecutables con símbolos de depuración. Si se indican los parámetros ```-e``` y ```-d```, el script ejecutará el programa indicado con un depurador de forma automática.

## Soporte para compiladores y depuradores
```lang.py``` trata de ofrecer soporte donde sea posible para múltiples compiladores y depuradores. Para ver la lista de herramientas admitidas por cada lenguaje, se recomienda revisar las propiedades/atributos de nombre «admitted_compilers» y «admitted_debuggers» en las clases que definen el soporte para un lenguaje dado dentro del código.

El programa tratará por defecto de utilizar el primer programa que esté disponible en el sistema y se encuentre dentro de la lista de programas admitidos para un propósito dado. En caso de no encontrar ninguna herramienta adecuada se le informará al usuario oportunamente. En caso de querer utilizar herramientas de elección propia véase la sección «Variables de entorno».

## Ejemplo de uso
El script puede ejecutarse de la siguiente forma:

```
python lang.py <archivo a compilar> <parámetros>
```

Entonces, si se quisiera compilar y ejecutar el programa 1-1.pas ubicado en «/algoritmos/(X) Adicionales/(X.2) Práctica para laboratorios/(X.2.1) Ejercicios de Pascal/G1» debería escribirse lo siguiente:

```
python lang.py 1-1.pas -e
```

El script determina automáticamente la ubicación del programa a través de una búsqueda recursiva en el repositorio. En caso de haber múltiples archivos con el mismo nombre el script le avisará al usuario para que tome las medidas correspondientes a fin de corregir esa situación.

## Variables de entorno
```lang.py``` admite el uso de las siguientes variables de entorno para modificar su comportamiento en tiempo de ejecución:
* ```COMPILER```: permite especificar un compilador alternativo para usar.
* ```OVERRIDE_FLAGS```: permite especificar un nuevo conjunto de parámetros de compilación a utilizar. Puede dejarse en blanco para compilar sin parámetros específicos más allá de aquellos que un compilador puede incluir por defecto.
* ```ADD_FLAGS```: permite especificar un conjunto de parámetros de compilación a utilizar en conjunción con aquellos definidos dentro del programa.
* ```DEBUGGER```: permite especificar un depurador alternativo para usar.

Las variables de entorno se especifican en una invocación al programa con la forma ```VARIABLE="VALOR"```. «VALOR» debe tratarse de una palabra, o de una cadena de palabras si se desea especificar parámetros personalizados de compilación.

De esta forma, si se deseara compilar con Clang y ejecutar el programa 1-1.c ubicado en «/algoritmos/(X) Adicionales/(X.2) Práctica para laboratorios/(X.2.2) Ejercicios de C/G1» debería escribirse lo siguiente:

```
COMPILER="clang" python lang.py 1-1.c -e
```

Si se deseara compilar con parámetros personalizados, sobreescribiendo aquellos definidos por defecto en el programa, debería escribirse lo siguiente:

```
OVERRIDE_FLAGS="-O3 -flto" python lang.py 1-1.c -e
```

La misma lógica se aplica para las otras variables de entorno.
