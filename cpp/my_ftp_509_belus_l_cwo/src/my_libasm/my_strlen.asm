section .text
global _my_strlen

_my_strlen:
    ; rdi - source string
    mov rax, -1 ; counter (strlen minus 1)

.loop:
    inc rax ; increment counter
    cmp byte [rdi + rax], 0 ; check if we hit the null-terminating character
    jne .loop ; if not, continue loop
    ; return length
    ret