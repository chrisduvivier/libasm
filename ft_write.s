extern ___error

SYS_WRITE_MAC equ 0x02000004

section .text
   global _ft_write
	
_ft_write:                  	;tell linker entry point
   mov   rax, SYS_WRITE_MAC	;system call number (sys_write)
   syscall		  			      ;call kernel
   jc    _ret_error
   ret

_ret_error:
   push  rax,                 ;push returned value from syscall (stored in rax) to stack
   call  ___error,            ;address errnum to rax
   mov   rdi, rax,            ;move retured address to rdi
   pop   rax                  ;retrive rax value
   mov   [rdi], rax           ;set rax value to the address of rdi
   mov   rax, -1              ;set function return value to -1
   ret

; write(fd, ptr, len)
;      (rdi, rsi, rdx)