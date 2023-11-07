section .text
global _my_write

_my_write:
    ; rdi - file descriptor
    ; rsi - buffer
    ; rdx - count
    mov eax, 4 ; syscall read = 0
    syscall
    ret