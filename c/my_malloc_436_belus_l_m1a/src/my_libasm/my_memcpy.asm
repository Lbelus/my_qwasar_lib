section .text
global _my_memcpy

_my_memcpy:
    ; rdi - dest
    ; rsi - source
    ; rdx - size_t n
    mov rcx, 0 ; counter (strlen minus 1)

.loop:
    mov bl, byte [rsi + rcx]
    mov [rdi], bl
    ; movzx rdi, byte [rsi + rax]
    inc rcx ; increment counter
    inc rdi
    cmp rcx, rdx ; check if we hit size_t n
    jne .loop ; if ZF is NOT set
    ret    