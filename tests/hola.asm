; nasm -f macho64 hola.asm
; gcc hola.o && ./a.out

			global	_main
			extern	_puts

			section	.text
_main:		
			push	rbx
			lea		rdi, [rel message]
			call	_puts
			pop		rbx
			ret

			section	.data
message:	db		"hola, mundo", 0