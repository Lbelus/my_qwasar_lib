section .text
global _my_read

_my_read:
    ; rdi - file descriptor
    ; rsi - buffer
    ; rdx - count
    mov eax, 0 ; syscall read = 0
    syscall
    ret