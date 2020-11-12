
		global  _ft_strlen
		section .text

_ft_strlen:
		xor		rax, rax			; set register rax = 0
		jmp		compare				; skip 1st increment by jumping to cmp first

increment:
		inc		rax

; rdi gets the 1st param passed by the function call
compare:
		cmp		BYTE[rdi + rax], 0
		jne		increment
		ret