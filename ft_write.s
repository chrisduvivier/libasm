extern __errno_location

SYS_WRITE_MAC equ 0x02000004
SYS_WRITE_LINUX equ 1

section .text
global ft_write
	
ft_write:                  	;tell linker entry point
   mov   rax, SYS_WRITE_LINUX	;system call number (sys_write)
   syscall		  			      ;call kernel
   cmp   rax, 0               ;if rax less than 0
   jl    ret_error
   ret

ret_error:
   neg   rax                  ;the return error value (stored in rax) was negative, so make it positive
   push  rax                  ;push returned value from syscall (stored in rax) to stack
   call  __errno_location     ;address errnum to rax
   mov   rdi, rax             ;move retured address to rdi
   pop   rax                  ;retrive rax value
   mov   [rdi], rax           ;set rax value to the address of rdi
   mov   rax, -1              ;set function return value to -1
   ret

; write(fd, ptr, len)
;      (rdi, rsi, rdx)