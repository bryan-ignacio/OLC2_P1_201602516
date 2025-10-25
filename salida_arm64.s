// Archivo generado por el generador ARM64 (esqueleto)
.text
.globl _main

# Sección de código: emitiendo funciones con frame y variables locales

_main:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    sub sp, sp, #32
# declaracion variable a (tipo=3)
# cargar literal 2 en x0
    mov x0, #2
    // almacenar x0 en variable local a (offset=24)
    sub x12, x29, #24
    str x0, [x12]
# declaracion variable b (tipo=3)
# cargar literal 3 en x0
    mov x0, #3
    // almacenar x0 en variable local b (offset=16)
    sub x12, x29, #16
    str x0, [x12]
# declaracion variable c (tipo=3)
# cargar identificador a en x0
    // cargar variable local a (offset=24) en x0
    sub x12, x29, #24
    ldr x0, [x12]
# cargar identificador b en x1
    // cargar variable local b (offset=16) en x1
    sub x12, x29, #16
    ldr x1, [x12]
# emitir suma x0 = x0 + x1
    add x0, x0, x1
    // almacenar x0 en variable local c (offset=8)
    sub x12, x29, #8
    str x0, [x12]
# cargar identificador c en x1
    // cargar variable local c (offset=8) en x1
    sub x12, x29, #8
    ldr x1, [x12]
    // Cargar la dirección de la cadena LS_1 en x0 (uso adrp/add para macOS)
    adrp x0, LS_1@PAGE
    add x0, x0, LS_1@PAGEOFF
    bl _printf
    mov x0, #10
    bl _putchar
    add sp, sp, #32
    ldp x29, x30, [sp], #16
    ret

// Fin del archivo generado (placeholder)

.data
LS_1:
    .asciz "%d"
LS_2:
    .asciz "%g"
LS_3:
    .asciz "%.15g"
LS_4:
    .asciz "%c"
LS_5:
    .asciz "%s"
