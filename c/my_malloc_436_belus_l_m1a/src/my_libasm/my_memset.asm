section .text
global _my_memset

_my_memset:
    ; rdi - dest ptr
    ; rsi - source target char 
    ; rdx - size_t n
    mov rcx, -1 ; counter (strlen minus 1)

.loop:
    inc rcx ; increment counter
    mov [rdi], sil 
    inc rdi
    cmp rcx, rdx ; check if we hit size_t n
    jne .loop ; if ZF is NOT set
    ret