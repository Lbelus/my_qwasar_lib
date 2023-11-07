section .text
global save_state
save_state:
    ; rdi contains the pointer to the struct

    ; Save rsp
    mov [rdi], rsp

    ; Save rbp
    mov [rdi + 8], rbp

    ; Save rax
    mov [rdi + 16], rax

    ; Save rbx
    mov [rdi + 24], rbx

    ; Save rcx
    mov [rdi + 32], rcx

    ; Save rdx
    mov [rdi + 40], rdx

    ret