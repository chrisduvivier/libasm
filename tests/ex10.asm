; C defines the _start entrypoint for you. You are expected to prvide _main

        global  _main
        extern  _printf

        section .text
_main:
		push	ebp
		mov		ebp, esp
		push	123							; passing 2nd arg
		push	msg							; passing 1st arg
		call	_printf
		mov		eax, 0						; returning value of main 
		mov		esp, ebp					; epilogue
		pop		ebp
		ret

		section		.data
		msg db "Testing %i...", 0x0a, 0x00 ; 0x00 refers to the NULL terminator