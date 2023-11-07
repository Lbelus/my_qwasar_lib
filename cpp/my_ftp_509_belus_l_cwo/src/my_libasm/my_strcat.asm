section .text
global _my_strcat

_my_strcat:
    ; rdi - destination
    ; rsi - source 
    xor rax, rax ; counter 

.loop: 
    cmp byte [rdi + rax], 0 ; check if we hit the null-terminating character
    jz .cpy_src
    inc rax ; increment counter
    jmp .loop ; if not, continue loop

.cpy_src:
    xor rcx, rcx
.cpy_loop:
    mov bl, byte [rsi + rcx]
    mov [rdi + rax], bl
    inc rax
    inc rcx ; increment counter
    cmp byte [rsi + rcx], 0 ; check if we hit the null-terminating character
    jne .cpy_loop ; if not, continue loop
    mov byte [rdi + rax], 0
    ret