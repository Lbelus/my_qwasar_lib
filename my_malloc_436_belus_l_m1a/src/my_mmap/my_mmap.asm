section .text
    global my_mmap
    my_mmap:

    ; RDI already contains the first argument (size from C function call)

    mov rax, 9      
    xor rsi, rsi    ; addr = NULL (let the kernel choose the location)
    mov rsi, rdi    ; len = size (from C function call)
    mov rdx, 3      ; or 0x3  : (0x1 |0x2)   ; PROT_READ | PROT_WRITE
    mov r10, 34     ; or 0x22 : (0x20 | 0x2) ; MAP_ANONYMOUS | MAP_PRIVATE
    mov r8, -1      ; fd = -1
    xor r9, r9      ; offset = 0 
    syscall

    ret            
