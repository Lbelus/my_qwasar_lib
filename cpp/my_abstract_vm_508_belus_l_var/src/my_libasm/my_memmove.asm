section .text
global _my_memmove

_my_memmove:
    ; rdi - dest
    ; rsi - source
    ; rdx - size_t n
    mov rcx, rdx ; Save n in rcx
    sub rsp, rcx ; Allocate n bytes on the stack
    mov rbx, rsp ; rbx now points to the temporary buffer

.src_to_tmp:
    movzx rax, byte [rsi] ; Load a byte from source
    mov [rbx], al ; Store the byte in the temporary buffer
    inc rsi ; Increment source
    inc rbx ; Increment pointer to the temporary buffer
    dec rcx ; Decrement n
    jnz .src_to_tmp ; Repeat until n is zero

    mov rcx, rdx ; Restore n
    mov rbx, rsp ; Restore pointer to the start of the temporary buffer

.tmp_to_dest:
    movzx rax, byte [rbx] ; Load a byte from the temporary buffer
    mov [rdi], al ; Store the byte at dest
    inc rdi ; Increment dest
    inc rbx ; Increment pointer to the temporary buffer
    dec rcx ; Decrement n
    jnz .tmp_to_dest ; Repeat until n is zero

    add rsp, rdx ; Clean up the stack
    ret