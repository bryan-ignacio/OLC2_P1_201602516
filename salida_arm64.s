// Archivo generado por el generador ARM64 (esqueleto)
.text
.global main

# Sección de código: emitiendo funciones con frame y variables locales

main:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    sub sp, sp, #16
# declaracion variable numero (tipo=3)
# cargar literal 42 en x0
    mov x0, #42
    // almacenar x0 en variable local numero (offset=16)
    sub x12, x29, #16
    str x0, [x12]
# declaracion variable mensaje (tipo=6)
# cargar literal string El número es:  en x0 via LS_1
    adr x0, LS_1
    // almacenar x0 en variable local mensaje (offset=8)
    sub x12, x29, #8
    str x0, [x12]
    adr x0, SVBUF_8
    mov x1, #64
    adr x2, LS_9
# cargar identificador numero en x3
    // cargar variable local numero (offset=16) en x3
    sub x12, x29, #16
    ldr x3, [x12]
    bl snprintf
    adr x0, SVBUF_8
    mov x2, x0
# cargar identificador mensaje en x0
    // cargar variable local mensaje (offset=8) en x0
    sub x12, x29, #8
    ldr x0, [x12]
    mov x1, x0
    adr x0, LS_7
    bl printf
    mov x0, #10
    bl putchar
    add sp, sp, #16
    ldp x29, x30, [sp], #16
    ret

// Fin del archivo generado (placeholder)

.data
LS_1:
    .asciz "El número es: "
LS_2:
    .asciz "%d"
LS_3:
    .asciz "%g"
LS_4:
    .asciz "%.15g"
LS_5:
    .asciz "%c"
LS_6:
    .asciz "%s"
LS_7:
    .asciz "%s%s"
LS_9:
    .asciz "%d"
SVBUF_8:
    .space 64
