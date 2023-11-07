section .text
global _my_strchr

_my_strchr:
    ; rdi - src on dest
    ; rsi - target char on src
    mov rcx, -1 ; counter (strlen minus 1)
    ; mov dl, sil

.loop:
    inc rcx ; increment counter
    mov dl, byte [rdi + rcx] ; Optimized to 8-bit reg. 
    cmp dl, sil ; check if we hit target char
    je .return_ptr ; if ZF is set
    cmp dl, 0 ; check if we hit NULL
    jne .loop ; if ZF is NOT set
    xor rax, rax ;return NULL
    ret

.return_ptr:
    ; return ptr
    lea rax, [rdi + rcx]
    ret