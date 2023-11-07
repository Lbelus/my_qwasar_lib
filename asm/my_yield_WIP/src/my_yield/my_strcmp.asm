section .text
global _my_strcmp

_my_strcmp:
    ; rdi - src on dest
    ; rsi - target char on src
    mov rcx, -1 ; counter (strlen minus 1)
    ; mov dl, sil

.loop:
    inc rcx ; increment counter
    mov bl, byte [rdi + rcx] ; Optimized to 8-bit reg. 
    mov dl, byte [rsi + rcx] ; Optimized to 8-bit reg. 
    cmp bl, dl ; check if we hit target char
    jne .return_diff ; if ZF is set
    cmp bl, 0 ; check if we hit NULL
    jne .loop ; if ZF is NOT set
    xor rax, rax ;return NULL
    ret

.return_diff:
    sub bl, dl ; substract
    movsx rax, bl ; sx = sign extension
    ret