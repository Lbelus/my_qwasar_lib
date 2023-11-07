section .text
global _my_strcasecmp

_my_strcasecmp:
    ; rdi - src on dest
    ; rsi - target char on src
    mov rax, -1 ; counter (strlen minus 1)
    ; mov dl, sil

.loop:
    inc rax ; increment counter
    mov cl, byte [rdi + rax] ; Optimized to 8-bit reg. 
    mov dl, byte [rsi + rax] ; Optimized to 8-bit reg.
.adjust_a:
    cmp cl, 'A'
    jl .adjust_b
    cmp cl, 'Z'
    jg .adjust_b
    add cl, 32
.adjust_b:
    cmp dl, 'A'
    jl .cmp_oper
    cmp dl, 'Z'
    jg .cmp_oper
    add dl, 32
.cmp_oper:
    cmp cl, dl ; check if we hit target char
    jne .return_diff ; if ZF is set
    cmp cl, 0 ; check if we hit NULL
    jne .loop ; if ZF is NOT set
    xor rax, rax ;return NULL
    ret

.return_diff:
    sub cl, dl ; substract
    movsx rax, cl ; sx = sign extension
    ret