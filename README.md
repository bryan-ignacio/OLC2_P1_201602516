# Analizador JavaLang - OLC2 Proyecto 1

Este proyecto implementa un analizador sintáctico y semántico para el lenguaje JavaLang, desarrollado como parte del curso de Organización de Lenguajes y Compiladores 2.

## Características

- Análisis léxico y sintáctico completo
- Generación de Árbol de Sintaxis Abstracta (AST)
- Interpretación de código JavaLang
- Reportes de errores detallados
- Reporte visual del AST
- Reporte de tabla de símbolos
- **Interfaz gráfica con GTK3**
- Interfaz de línea de comandos

## Compilación

### Prerrequisitos

Para compilar el proyecto necesitas tener instalado:

- GCC
- Bison
- Flex
- Make
- GTK3 development libraries (para la versión GUI)

En sistemas basados en Fedora/Red Hat:
```bash
sudo dnf install gcc bison flex make gtk3-devel pkg-config
```

En sistemas basados en Ubuntu/Debian:
```bash
sudo apt install gcc bison flex make libgtk-3-dev pkg-config
```

### Compilar ambas versiones

```bash
make clean
make console  # Compila la versión de línea de comandos
make gui      # Compila la versión con interfaz gráfica
```

## Uso

### Versión con Interfaz Gráfica (Recomendada)

```bash
./build/calc-gui
```

La interfaz gráfica incluye:

1. **Editor de entrada**: Para escribir código JavaLang
2. **Botón "Abrir Archivo .usl"**: Para cargar archivos desde el sistema
3. **Botón "Limpiar Editor"**: Para limpiar el área de entrada
4. **Botón "Analizar"**: Para ejecutar el análisis del código
5. **Área de salida**: Muestra los resultados de la ejecución
6. **Botones de reportes**:
   - **"ver reporte Errores"**: Abre el reporte de errores en el navegador
   - **"ver AST"**: Abre la visualización del AST
   - **"ver reporte Tabla Símbolos"**: Abre el reporte de la tabla de símbolos

### Versión de Línea de Comandos

```bash
# Analizar desde archivo
./build/calc archivo.usl

# Analizar desde entrada estándar
./build/calc
```

## Archivos de Salida

El analizador genera varios archivos de salida:

- `salida.txt`: Salida del programa interpretado
- `reporte_errores.html`: Reporte detallado de errores
- `reporte_ast.dot`: Archivo DOT para visualizar el AST
- `tabla_simbolos.html`: Reporte de la tabla de símbolos

## Ejemplo de Código JavaLang

```java
void main() {
    int x = 5;
    int y = 10;
    int resultado = x + y;
    println("El resultado es: " + resultado);
    
    int[] numeros = new int[3];
    numeros[0] = 1;
    numeros[1] = 2;
    numeros[2] = 3;
    
    for (int i = 0; i < numeros.length; i++) {
        println("Numero " + i + ": " + numeros[i]);
    }
}
```

## Características Soportadas

- Variables: `int`, `float`, `string`, `boolean`, `char`
- Arrays y matrices
- Operadores aritméticos, lógicos y relacionales
- Estructuras de control: `if`, `while`, `for`, `switch`
- Funciones definidas por el usuario
- Función `main()` como punto de entrada
- Instrucciones de salida: `print`, `println`
- Funciones integradas para manejo de tipos y arrays

## Estructura del Proyecto

```
src/
├── main.c              # Punto de entrada para versión consola
├── main_gui.c          # Punto de entrada para versión GUI
├── gui/                # Interfaz gráfica
│   ├── main_window.h
│   └── main_window.c
├── ast/                # Árbol de sintaxis abstracta
├── context/            # Contexto y tabla de símbolos
└── entriesTools/       # Analizador léxico y sintáctico
    ├── lexer.l
    └── parser.y
```

## Autor

Bryan Ignacio - 201602516

## Licencia

Este proyecto es parte de un curso académico de la Universidad de San Carlos de Guatemala.
