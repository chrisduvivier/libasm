extern __errno_location
extern ft_strlen
extern malloc
extern ft_strcpy

section .text
global ft_strdup

ft_strdup:
    push    rdi                 ; store the src string to stack
    call    ft_strlen           ; result goes to rax
    inc     rax                 ; increrment by +1 for the \0 char 
    mov     rdi, rax            ; pass the length of string (to use in malloc)
    call    malloc              ; gets rdi BYTE, and rax gets the address back
    cmp     rax, 0
    jl      ret_error
    mov     rdi, rax            ; dest string passed to rdi
    pop     rsi                 ; pop the src string from stack, and pass to rsi
    call    ft_strcpy
    ret

ret_error:
   neg   rax                  ;the return error value (stored in rax) was negative, so make it positive
   mov   rdi, rax             ;rax = the actual errno number
   call  __errno_location     ;address errnum to rax
   mov   [rax], rdi
   mov   rax, -1              ;set function return value to -1
   ret
