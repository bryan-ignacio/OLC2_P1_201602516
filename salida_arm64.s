// Archivo generado por el generador ARM64 (esqueleto)
.text
.global main

# Sección de comentarios (extraídos del texto fuente):
# -- Nodo AST en linea 1 --
# -- Nodo AST en linea 1 --
# -- Nodo AST en linea 2 --
# -- Nodo AST en linea 2 --
#  Declaraciones iniciales
# -- Nodo AST en linea 5 --
# -- Nodo AST en linea 6 --
#  Asignaciones simples
#  reasignación simple
# -- Nodo AST en linea 9 --
#  Asignaciones compuestas enteras
# -- Nodo AST en linea 12 --
# -- Nodo AST en linea 13 --
# -- Nodo AST en linea 14 --
# -- Nodo AST en linea 15 --
# -- Nodo AST en linea 16 --
# -- Nodo AST en linea 17 --
# -- Nodo AST en linea 18 --
# -- Nodo AST en linea 19 --
# -- Nodo AST en linea 19 --
# -- Nodo AST en linea 20 --
# -- Nodo AST en linea 21 --
#  Flotantes
# -- Nodo AST en linea 24 --
# -- Nodo AST en linea 25 --
# -- Nodo AST en linea 26 --
#  Double
# -- Nodo AST en linea 29 --
# -- Nodo AST en linea 30 --
# -- Nodo AST en linea 31 --
#  Mostrar resultados
# -- Nodo AST en linea 34 --
# -- Nodo AST en linea 34 --
# -- Nodo AST en linea 35 --
# -- Nodo AST en linea 35 --
#  Comentarios para que el generador también los capture
#  Comentario de línea
/*  Comentario
       multilínea  */
# -- Nodo AST en linea 36 --
# -- Nodo AST en linea 36 --
# Sección de código: emitiendo funciones con frame y variables locales

main:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    sub sp, sp, #32
# primitivo no soportado para codegen: tipo=6
# declaracion variable a (tipo=3)
# cargar literal 10 en x0
    mov x0, #10
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# declaracion variable b (tipo=3)
# cargar literal 3 en x0
    mov x0, #3
    // almacenar x0 en variable local b (offset=24)
    sub x12, x29, #24
    str x0, [x12]
# asignacion a a
# cargar literal 5 en x0
    mov x0, #5
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=0
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 7 en x1
    mov x1, #7
    add x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=1
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 2 en x1
    mov x1, #2
    sub x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=2
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 3 en x1
    mov x1, #3
    mul x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=3
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 4 en x1
    mov x1, #4
    sdiv x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=4
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 3 en x1
    mov x1, #3
    sdiv x2, x0, x1
    mul x3, x2, x1
    sub x0, x0, x3
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=5
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 1 en x1
    mov x1, #1
    and x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=6
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 2 en x1
    mov x1, #2
    orr x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=7
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar identificador b en x1
    // cargar variable local b (offset=24) en x1
    sub x12, x29, #24
    ldr x1, [x12]
    eor x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=8
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 1 en x1
    mov x1, #1
    lslv x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# asignacion compuesta a a operador=9
    // cargar variable local a (offset=32) en x0
    sub x12, x29, #32
    ldr x0, [x12]
# cargar literal 2 en x1
    mov x1, #2
    asrv x0, x0, x1
    // almacenar x0 en variable local a (offset=32)
    sub x12, x29, #32
    str x0, [x12]
# declaracion variable f (tipo=4)
# cargar literal float 1.500000 en s0 via LC_1
    // cargar float desde etiqueta LC_1 en s0
    adr x12, LC_1
    ldr s0, [x12]
    // almacenar x0 en variable local f (offset=16)
    sub x12, x29, #16
    str x0, [x12]
# asignacion compuesta a f operador=0
    // cargar variable local f (offset=16) en s0
    sub x12, x29, #16
    ldr s0, [x12]
# cargar literal float 2.250000 en s1 via LC_2
    // cargar float desde etiqueta LC_2 en s1
    adr x12, LC_2
    ldr s1, [x12]
    fadd s0, s0, s1
    // almacenar s0 en variable local f (offset=16)
    sub x12, x29, #16
    str s0, [x12]
# asignacion compuesta a f operador=2
    // cargar variable local f (offset=16) en s0
    sub x12, x29, #16
    ldr s0, [x12]
# cargar literal float 0.000000 en s1 via LC_3
    // cargar float desde etiqueta LC_3 en s1
    adr x12, LC_3
    ldr s1, [x12]
    fmul s0, s0, s1
    // almacenar s0 en variable local f (offset=16)
    sub x12, x29, #16
    str s0, [x12]
# declaracion variable d (tipo=5)
# cargar literal double 1.234500 en d0 via LC_4
    // cargar double desde etiqueta LC_4 en d0
    adr x12, LC_4
    ldr d0, [x12]
    // almacenar x0 en variable local d (offset=8)
    sub x12, x29, #8
    str x0, [x12]
# asignacion compuesta a d operador=3
    // cargar variable local d (offset=8) en d0
    sub x12, x29, #8
    ldr d0, [x12]
# cargar literal double 2.000000 en d1 via LC_5
    // cargar double desde etiqueta LC_5 en d1
    adr x12, LC_5
    ldr d1, [x12]
    fdiv d0, d0, d1
    // almacenar d0 en variable local d (offset=8)
    sub x12, x29, #8
    str d0, [x12]
# asignacion compuesta a d operador=0
    // cargar variable local d (offset=8) en d0
    sub x12, x29, #8
    ldr d0, [x12]
# cargar literal double 3.141590 en d1 via LC_6
    // cargar double desde etiqueta LC_6 en d1
    adr x12, LC_6
    ldr d1, [x12]
    fadd d0, d0, d1
    // almacenar d0 en variable local d (offset=8)
    sub x12, x29, #8
    str d0, [x12]
# primitivo no soportado para codegen: tipo=6
# emitir suma x0 = x0 + x1
    add x0, x0, x1
# primitivo no soportado para codegen: tipo=6
# emitir suma x0 = x0 + x1
    add x0, x0, x1
# primitivo no soportado para codegen: tipo=6
# emitir suma x0 = x0 + x1
    add x0, x0, x1
    add sp, sp, #32
    ldp x29, x30, [sp], #16
    ret

// Fin del archivo generado (placeholder)

.data
LC_1:
    .float 1.500000
LC_2:
    .float 2.250000
LC_3:
    .float 0.000000
LC_4:
    .double 1.234500
LC_5:
    .double 2.000000
LC_6:
    .double 3.141590
