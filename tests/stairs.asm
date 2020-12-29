

			global		start
			section		.text
start:
			mov			r8, output				;get the address of output
			mov			r9, 0					;current nuymber of * written
			mov			r10,1					;initial line length
line:
			mov			byte [r8], '*'
			inc			r8					;move ptr
			inc			r9					;increment number of star
			cmp			r10, r9
			jne			line
lineDone:
			mov			byte [r8], 10		;10 correspond to '\n'
			inc			r8					;inc ptr
			inc			r10					;inc num line
			mov			r9, 0				;reset num of starts
			cmp			r10, maxLines		;cmp num of lines
			jne			line
done:
			mov			rax, 0x02000004		;write syscall
			mov			rdi, 1				;stdout
			mov			rsi, output			;address of string to output
			mov			rdx, byteSize		;number of bytes (of the string to write
			syscall							;do write
			mov			rax, 0x02000001
			xor			rdi, rdi
			syscall

			section		.bss				;the .bss section is for writable data
maxLines	equ			8
byteSize	equ			44
output:		resb		byteSize