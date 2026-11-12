# Compilación de ejercicios
Este documento explica como compilar los ejercicios que hice de las guías de preparación para los laboratorios de lenguajes. Se asume que los compiladores a utilizar son [Free Pascal](https://es.wikipedia.org/wiki/Free_Pascal) y [GCC](https://es.wikipedia.org/wiki/GNU_Compiler_Collection) (provisto en Windows como parte de [MinGW](https://es.wikipedia.org/wiki/MinGW)), ya que son los recomendados por la cátedra.

## Compilación manual de ejercicios
* __Pascal__: los ejercicios pueden ser compilados tanto en Linux como en Windows con una simple invocación al compilador: `fpc <nombre del archivo>.pas`.
* __C__: los ejercicios pueden ser compilados tanto en Linux como en Windows con una simple invocación al compilador: `gcc <nombre del archivo>.c -o <nombre del archivo>`.

## Compilación utilizando lang.py
Los ejercicios de laboratorio también pueden ser compilados y ejecutados automáticamente (y más!) mediante el uso del script "lang.py" ubicado en la carpeta "_scripts" en la raíz del repositorio. Pueden verse instrucciones de uso en el documento de nombre "USO-LANGPY.md", ubicado en la carpeta "_docs", que también se encuentra en la raíz del repositorio.
