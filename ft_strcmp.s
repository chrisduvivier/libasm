;   The strcmp() and strncmp() functions lexicographically
;   compare the null-terminated strings s1 and s2.
;   int strcmp(const char *s1, const char *s2)


		section	.text
		global	_ft_strcmp

_ft_strcmp:
	xor		rcx, rcx							; set i = 0
	xor		rax, rax				    		; set diff = 0
    jmp     compare

check_null:
    cmp		BYTE[rdi + rcx], 0					; if s1[i] == NULL
	je		equal								;	then done
    inc		rcx									; else i++
    jmp		compare                             ; and continue

compare:
    mov		al, BYTE[rdi + rcx]                 ; tmp  = s1[i]
    sub     al, BYTE[rsi + rcx]                 ; tmp -= s2[i]
	cmp		al, 0	                            ; if s1[i] == s2[i]
	je		check_null							;	then check null
	jl      less
    jg      bigger

bigger:                                         ; s1[i] > s2[i] on last char i
    mov     rax, 1
    ret

less:                                           ; s1[i] < s2[i] on last char i
    mov     rax, -1
    ret

equal:                                          ; s1 == s2
	mov     rax, 0
    ret											; return