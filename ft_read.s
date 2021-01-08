extern ___error

SYS_READ_MAC equ 0x02000003

section .text
   global _ft_read
	
_ft_read:
   mov   rax, SYS_READ_MAC	    ;system call number (sys_read)
   syscall		  			    ;call kernel
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

; ssize_t read(int fildes, void *buf, size_t nbyte);
;              (rdi, rsi, rdx)