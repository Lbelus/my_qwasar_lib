section .text
global _my_strncmp

_my_strncmp:
    ; rdi - src on dest
    ; rsi - target char on src
    mov rax, -1 ; counter (strlen minus 1)
    ; mov dl, sil

.loop:
    inc rax ; increment counter
    mov cl, byte [rdi + rax] ; Optimized to 8-bit reg. 
    mov bl, byte [rsi + rax] ; Optimized to 8-bit reg. 
    cmp cl, bl ; check if we hit target char
    jne .return_diff ; if ZF is set
    cmp rax, rdx ; check if we hit target char
    je .return_null ; if ZF is set
    cmp cl, 0 ; check if we hit NULL
    jne .loop ; if ZF is NOT set
    xor rax, rax ;return NULL
    ret

.return_diff:
    sub cl, bl ; substract
    movsx rax, cl ; sx = sign extension
    ret

.return_null:
    xor rax,rax
    ret
