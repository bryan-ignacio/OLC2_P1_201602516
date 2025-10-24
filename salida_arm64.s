// Archivo generado por el generador ARM64 (esqueleto)
.text
.global main

# Sección de comentarios (extraídos del texto fuente):
#  Programa de prueba mínimo para el generador ARM64
#  Debe usar declaraciones locales, inicializadores y operaciones aritméticas
# -- Nodo AST en linea 1 --
# -- Nodo AST en linea 1 --
#  Declaraciones con inicializadores (enteros)
# -- Nodo AST en linea 6 --
# -- Nodo AST en linea 6 --
# -- Nodo AST en linea 7 --
# -- Nodo AST en linea 7 --
#  Declaración sin inicializador y asignación posterior
# -- Nodo AST en linea 10 --
# -- Nodo AST en linea 11 --
# -- Nodo AST en linea 11 --
#  Operación combinada
# -- Nodo AST en linea 14 --
# -- Nodo AST en linea 14 --
# -- Nodo AST en linea 14 --
# -- Nodo AST en linea 14 --
#  Cambio de valor
# -- Nodo AST en linea 17 --
# -- Nodo AST en linea 17 --
# Sección de código: emitiendo funciones con frame y variables locales

main:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    sub sp, sp, #32
# declaracion variable a (tipo=3)
# cargar literal 5 en x0
    mov x0, #5
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# declaracion variable b (tipo=3)
# cargar identificador a en x0
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 3 en x1
    mov x1, #3
# emitir suma x0 = x0 + x1
    add x0, x0, x1
    // almacenar x0 en variable local b (offset=24)
    sub x12, x29, #24
    str x0, [x12]
# declaracion variable c (tipo=3)
# asignacion a c
# cargar identificador b en x0
    // cargar variable local b (offset=24) en x0
    sub x12, x29, #24
    ldr x0, [x12]
# cargar literal 2 en x1
    mov x1, #2
# emitir multiplicación x0 = x0 * x1
    mul x0, x0, x1
    // almacenar x0 en variable local c (offset=16)
    sub x12, x29, #16
    str x0, [x12]
# declaracion variable d (tipo=3)
# cargar identificador a en x0
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar identificador b en x1
    // cargar variable local b (offset=24) en x1
    sub x12, x29, #24
    ldr x1, [x12]
# emitir suma x0 = x0 + x1
    add x0, x0, x1
# cargar identificador c en x1
    // cargar variable local c (offset=16) en x1
    sub x12, x29, #16
    ldr x1, [x12]
# cargar literal 2 en x1
    mov x1, #2
# emitir división x1 = x1 / x1 (signed)
    sdiv x1, x1, x1
# emitir resta x0 = x0 - x1
    sub x0, x0, x1
    // almacenar x0 en variable local d (offset=8)
    sub x12, x29, #8
    str x0, [x12]
# asignacion a a
# cargar identificador d en x0
    // cargar variable local d (offset=8) en x0
    sub x12, x29, #8
    ldr x0, [x12]
# cargar literal 10 en x1
    mov x1, #10
# emitir suma x0 = x0 + x1
    add x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
    add sp, sp, #32
    ldp x29, x30, [sp], #16
    ret

// Fin del archivo generado (placeholder)
