; int	ft_strcmp(const char *s1, const char *s2);
; rax						 rdi			 rsi

global ft_strcmp

ft_strcmp:
; Vars init
	mov		rcx, 0
	mov		rax, 0
	mov		r8, 0
.check_loop:
	movzx	rax, BYTE [rdi + rcx]	; Getting current char
	movzx	r8, BYTE [rsi + rcx]
	cmp		BYTE [rdi + rcx], 0		; Check for NULL char
	je		.end					; If found, end loop
	cmp		BYTE [rsi + rcx], 0
	je		.end
	cmp		rax, r8					; If 2 non-null, compare chars
	jne		.end					; If non-zero, end loop
	inc		rcx						; Else, increment counter and loop
	jmp		.check_loop
.end:
	sub		rax, r8					; Get result in the return value rax
	ret

; To avoid warnings from linker about stack section
section .note.GNU-stack noalloc noexec
