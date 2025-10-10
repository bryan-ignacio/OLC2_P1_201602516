# Reporte de Árbol de Sintaxis Abstracta (AST)

## Descripción

El sistema de reporte AST genera una representación visual del árbol de sintaxis abstracta producido durante el análisis sintáctico del código fuente. Utiliza Graphviz para crear representaciones gráficas en formato PNG.

## Características Implementadas

### 1. Generación Automática

- Se ejecuta automáticamente después del análisis sintáctico exitoso
- Genera dos archivos:
  - `reporte_ast.dot`: Archivo de descripción del grafo en formato DOT
  - `reporte_ast.png`: Imagen visual del árbol AST

### 2. Información Visual

- **Colores diferenciados por tipo específico de nodo:**
  - Cian claro: Declaraciones de variables y constantes
  - Rosa claro: Asignaciones de variables
  - Azul claro: Nodos terminales (literales, identificadores)
  - Verde marino claro: Operaciones unarias
  - Salmón claro: Operaciones binarias
  - Violeta claro: Operaciones ternarias
  - Dorado claro: Lista de instrucciones (>15 hijos)
  - Caqui claro: Bloques de código (5-15 hijos)
  - Cardo: Expresiones n-arias

### 3. Información Detallada Mejorada

- **Tipos específicos de nodos:**
  - "Declaración" vs "Asignación" vs "Terminal"
  - "Expresión Binaria" vs "Expresión Unaria"
  - "Bloque" vs "Lista Instrucciones"
- **Información contextual:**
  - Número de parámetros para funciones
  - Número de hijos para expresiones complejas
  - Clasificación por estructura (Declaración/Expresión/etc.)
- **Posición exacta**: Línea y columna en el código fuente
- **Estructura jerárquica**: Mejor identificación de la relación padre-hijo

### 4. Protecciones de Seguridad

- Límite de profundidad de recursión (50 niveles)
- Verificación de punteros válidos
- Detección de auto-referencias
- Límites en el número de hijos por nodo

## Uso

### Ejecución Automática

El reporte se genera automáticamente al ejecutar el compilador:

```bash
./build/calc archivo_entrada.usl
```

### Archivos Generados

- `reporte_ast.dot`: Archivo de texto con la descripción del grafo
- `reporte_ast.png`: Imagen PNG del árbol AST

### Requisitos

- **Graphviz**: Necesario para la conversión de DOT a PNG
  - Ubuntu/Debian: `sudo apt-get install graphviz`
  - CentOS/RHEL: `sudo yum install graphviz`
  - Arch Linux: `sudo pacman -S graphviz`
  - macOS: `brew install graphviz`

## Estructura del Código

### Archivos Principales

- `src/context/ast_report.h`: Definiciones y declaraciones
- `src/context/ast_report.c`: Implementación de las funciones

### Funciones Principales

```c
// Generar reporte completo (DOT + PNG)
void generarReporteASTCompleto(AbstractExpresion *raiz, const char *nombreArchivoBase);

// Generar solo archivo DOT
void generarReporteAST(AbstractExpresion *raiz, const char *nombreArchivo);

// Convertir DOT a imagen
void convertirDOTaImagen(const char *archivoDOT, const char *archivoImagen);
```

### Estructura del Contexto

```c
typedef struct {
    int contador;        // Contador de nodos
    FILE *archivo;       // Archivo de salida DOT
    int profundidad;     // Control de recursión
} ASTReportContext;
```

## Interpretación del Reporte

### Lectura del Árbol

- **Dirección**: De arriba hacia abajo (Top-Bottom)
- **Raíz**: Nodo superior, generalmente "Instrucciones"
- **Hojas**: Nodos sin hijos, representan elementos terminales
- **Aristas**: Conectan padres con hijos

### Información de los Nodos

```
Tipo_de_Nodo
L:línea C:columna
Información adicional
```

### Ejemplos de Tipos de Nodos Mejorados

- **Declaración**: Declaraciones de variables y constantes con tipo de dato
- **Asignación**: Asignaciones simples y compuestas a variables
- **Terminal**: Literales, identificadores, valores constantes
- **Expresión Unaria**: Operaciones con un operando (negación, incremento)
- **Expresión Binaria**: Operaciones con dos operandos (suma, resta, comparación)
- **Expresión Ternaria**: Operaciones con tres operandos (operador ternario ?:)
- **Bloque**: Nodos con 5-15 hijos (estructuras de control, funciones)
- **Lista Instrucciones**: Nodos con más de 15 hijos (programa principal)
- **Literal**: Valores específicos como números, strings, booleanos

### Información Específica por Tipo de Nodo

Cada tipo de nodo ahora muestra información específica:

```
Declaración              Expresión Binaria         Terminal
Declaración              Operador                  Terminal
Hijos: 1                 Binario                   Primitivo
L:4 C:5                  L:9 C:15                  L:4 C:12
```

### Interpretación del Formato de Etiquetas

```
[Tipo de Nodo]
[Información Específica]
[Detalles Estructurales]
L:[línea] C:[columna]
```

Ejemplos:

- `Declaración\nDeclaración\nHijos: 1\nL:4 C:5` - Una declaración de variable
- `Terminal\nTerminal\nPrimitivo\nL:0 C:0` - Un valor literal
- `Expresión Binaria\nOperador\nBinario\nL:9 C:15` - Una operación como suma o resta

## Solución de Problemas

### Error: "Graphviz no está instalado"

Instalar Graphviz según el sistema operativo.

### Error: "No se pudo crear el archivo"

Verificar permisos de escritura en el directorio actual.

### Imagen muy grande

Para archivos de código muy extensos, la imagen puede ser muy grande.
Usar un visor de imágenes que permita zoom.

### Archivo DOT corrupto

Verificar que el análisis sintáctico fue exitoso antes de la generación del reporte.

## Personalización

### Modificar Colores

Editar la función `obtenerColorNodo()` en `ast_report.c`.

### Cambiar Formato de Salida

Modificar el comando en `convertirDOTaImagen()`:

- PNG: `dot -Tpng`
- SVG: `dot -Tsvg`
- PDF: `dot -Tpdf`

### Agregar Información

Modificar `obtenerEtiquetaNodo()` para incluir más detalles.

## Ejemplos de Uso

### Código Simple

```java
int x = 5;
int y = 10;
int suma = x + y;
```

Genera un árbol con:

- Nodo raíz "Instrucciones" (3 hijos)
- Tres nodos de declaración
- Nodos terminales para valores y variables

### Código Complejo

Para programas más grandes, el árbol mostrará:

- Estructuras de control (if, while, for)
- Funciones y llamadas
- Expresiones complejas
- Arrays y accesos

## Mantenimiento

### Agregar Nuevos Tipos de Nodos

1. Actualizar `obtenerTipoNodo()` con nueva heurística
2. Agregar color en `obtenerColorNodo()`
3. Opcionalmente, actualizar `obtenerEtiquetaNodo()`

### Mejorar Identificación

Crear mapeo de funciones interpret a nombres específicos
en lugar de usar solo heurísticas.
