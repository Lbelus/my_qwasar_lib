section .text
global _my_strcpy

_my_strcpy:
    ; rdi - dest
    ; rsi - source
    xor rax, rax ; counter

.loop:
    mov bl, byte [rsi + rax]
    mov byte [rdi + rax], bl
    inc rax ; increment counter
    cmp byte [rsi + rax], 0 ; check if we hit the null-terminating character
    jne .loop ; if not, continue loop
    mov byte [rdi + rax], 0
    ; return length
    ret
