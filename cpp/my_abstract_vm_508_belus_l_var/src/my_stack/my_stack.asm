; section .data
;     stack db 256
;     sp db 0

; section .text
;     global _push_byte, _pop

; _push_byte:
;     lea rax, stack
;     ;add al, [sp]
;     ;mov [rax], dil
;     add rsp, 8
;     ;ret

; _pop:
;     ;mov rdi, stack
;     ;dec byte [sp]
;     ;ret
