extern __errno_location

SYS_READ_MAC equ 0x02000003
SYS_READ_LINUX equ 0

section .text
global ft_read
	
ft_read:
   mov   rax, SYS_READ_LINUX	;system call number (sys_read)
   syscall		  			      ;call kernel
   cmp   rax, 0
   jl    ret_error
   ret

ret_error:
   neg   rax                  ;returned number is negative, so set to positive
   mov   rdi, rax             ;store value to rdi
   call  __errno_location     ;address errnum gets returned to rax
   mov   [rax], rdi             ;set rax value to the address of errno
   mov   rax, -1              ;set function return value to -1
   ret

; ssize_t read(int fildes, void *buf, size_t nbyte);
;              (rdi, rsi, rdx)