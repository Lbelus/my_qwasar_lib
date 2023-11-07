section .text
global restore_state
restore_state:
    ; rdi contains the pointer to the struct

    ; Restore rsp
    mov rsp, [rdi]

    ; Restore rbp
    mov rbp, [rdi + 8]

    ; Restore rax
    mov rax, [rdi + 16]

    ; Restore rbx
    mov rbx, [rdi + 24]

    ; Restore rcx
    mov rcx, [rdi + 32]

    ; Restore rdx
    mov rdx, [rdi + 40]

    ret