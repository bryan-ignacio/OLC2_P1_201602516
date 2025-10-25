// Archivo generado por el generador ARM64 (esqueleto)
.text
.global main

# Sección de código: emitiendo funciones con frame y variables locales

main:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    sub sp, sp, #32
# declaracion variable a (tipo=3)
# cargar literal 3 en x0
    mov x0, #3
    // almacenar x0 en variable local a (offset=24)
    sub x12, x29, #24
    str x0, [x12]
# declaracion variable b (tipo=3)
# cargar literal 2 en x0
    mov x0, #2
    // almacenar x0 en variable local b (offset=16)
    sub x12, x29, #16
    str x0, [x12]
# declaracion variable c (tipo=3)
# cargar literal 3 en x0
    mov x0, #3
# cargar literal 5 en x1
    mov x1, #5
# emitir suma x0 = x0 + x1
    add x0, x0, x1
    // almacenar x0 en variable local c (offset=8)
    sub x12, x29, #8
    str x0, [x12]
# cargar literal string hola mundo en x0 via LS_6
    adr x0, LS_6
    cmp x0, xzr
    b.eq L_print_null_7
    bl puts
    b L_print_end_8

L_print_null_7:
    adr x0, LS_9
    bl puts

L_print_end_8:
    mov x0, #10
    bl putchar
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
LS_6:
    .asciz "hola mundo"
LS_9:
    .asciz "null"
