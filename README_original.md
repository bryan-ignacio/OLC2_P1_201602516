# Documentación

Se hace uso de los esquemas de traducción para armar un árbol sintáctico. Luego utilizar el patrón interprete para interpretar el `archivo de entrada`. La carpeta `src` se divide en:

### Archivo main.c

Contiene la ejecución principal y la construcción del ámbito padre ademas de realizar el primer `interpret` utilizando `recursividad indirecta`.

### entriesTools

En esta carpeta se guardan los archivos de entrada para las herramientas flex y bison. Estos dos archivos se comunican a través de los encabezados generados por bison (`*.tab.h`), leer la documentación de cada herramienta para entender cada parte. Al finalizar el análisis sintáctico la raíz del arbol a utilizar en el patrón intérprete se guarda en producción del símbolo inicial de la gramatica.

### Context

Archivos de consumo para utilizar y guardar información en el proceso de interpretado, se envía en cada función `interpret` y puede agregar entradas a la tabla o árbol de ámbitos así como controlar la tabla de símbolos entre otra funcionalidad que se requiera en el proceso. Aquí se específica el archivo `result.h`.

### ast

La carpeta tiene el encabezado de la clase abstracta para implementar en todos los nodos terminales y no terminales del árbol sintáctico generado por el análisis sintáctico con bison. Tiene múltiples carpetas dividos por subcategorías de los componentes del lenguaje de entrada que implementan la clase abstracta.

## Reportes Generados

El sistema genera automáticamente varios reportes durante la ejecución:

### Reporte de Tabla de Símbolos

- **Archivo**: `tabla_simbolos.html`
- **Descripción**: Tabla HTML con todas las variables, funciones y símbolos declarados
- **Información**: Nombre, tipo, valor, ámbito, línea y columna de declaración

### Reporte de Árbol AST (Nuevo)

- **Archivos**: `reporte_ast.dot` y `reporte_ast.png`
- **Descripción**: Representación visual del Árbol de Sintaxis Abstracta
- **Características**:
  - Generación automática usando Graphviz
  - Colores diferenciados por tipo de nodo
  - Información de línea y columna
  - Estructura jerárquica del código analizado
- **Requisito**: Graphviz instalado (`sudo apt-get install graphviz`)

### Reporte de Errores

- **Archivo**: Salida en consola
- **Descripción**: Lista de errores sintácticos y semánticos encontrados
- **Información**: Tipo de error, línea, columna y descripción

## Compilación

Con el comando `make` ejecuta el archivo y busca todos los archivos con extensión c dentro de la carpeta definida en la variable `SRC`. Los pasos que el Makefile realiza son:

1. Crear la carpeta build, todos los compilados se generan en esta carpeta.
2. Generar el parser en c utilizando el archivo de entrada para bison en la carpeta `entriesTools` y con la opción para generar los encabezados `*.tab.h`
3. Generar el lexer en c utilizando el archivo de entrada para flex en la misma carpeta del paso anterior.
4. Compilar los archivos .c en las carpetas de la variable `SRC` a codigo objeto extensión .o
5. Compilar los archivos .c y .h de bison a código objeto (.o).
6. Compilar los archivos .c de flex a código objeto (.o).
7. Por último crear un único compilado en el archivo llamado `calc`.

## Ejecución

En la ruta `build/calc` tenemos el archivo compilado de nuestro proyecto, la función main recibe un argumento que es la ruta al `archivo de entrada`.

### Comandos de Ejecución

```bash
# Compilar el proyecto
make

# Ejecutar con archivo de entrada
./build/calc archivo_entrada.usl

# Limpiar archivos compilados
make clean
```

### Archivos de Salida

Después de ejecutar el programa, se generan automáticamente:

- `salida.txt`: Resultado de la interpretación del código
- `tabla_simbolos.html`: Reporte de tabla de símbolos
- `reporte_ast.dot`: Descripción del AST en formato DOT
- `reporte_ast.png`: Imagen visual del AST (requiere Graphviz)

### Ejemplo de Uso

```bash
# Crear archivo de prueba
echo 'System.out.println("Hola mundo");' > prueba.usl

# Compilar y ejecutar
make
./build/calc prueba.usl

# Ver resultados
cat salida.txt
xdg-open reporte_ast.png  # Linux
open reporte_ast.png      # macOS
```

Para más información sobre el reporte AST, consultar `REPORTE_AST_DOCUMENTACION.md`.
