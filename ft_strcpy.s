; The strcpy() function copy the string src to dst (including the terminating `\0' character.)
; strcpy(char * dst, const char * src);


		section	.text
		global	_ft_strcpy

_ft_strcpy:
	xor		rcx, rcx				; set i = 0
	jmp		compare

copy:
	mov		dl, BYTE[rsi + rcx]		; copying like BYTE[rdi + rcx], BYTE[rsi + rcx] doesn't work, so need tmp operation
	mov		BYTE[rdi + rcx], dl
	inc		rcx

compare:
	cmp		BYTE[rsi + rcx], 0		; if src[i] == 0
	jz		done					;	then done
	jmp		copy					; else: copy

done:
	mov		BYTE[rdi + rcx], 0
	mov		rax, rdi				; return_value = dst
	ret								; return
