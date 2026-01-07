; int	ft_strcmp(const char *s1, const char *s2);
; rax						 rdi			 rsi

global ft_strcmp

ft_strcmp:
	mov		rcx, 0
	mov		rax, 0
	mov		r8, 0
.check_loop:
	movzx	rax, BYTE [rdi + rcx]
	movzx	r8, BYTE [rsi + rcx]
	cmp		BYTE [rdi + rcx], 0
	je		.end
	cmp		BYTE [rsi + rcx], 0
	je		.end
	cmp		rax, r8
	jne		.end
	inc		rcx
	jmp		.check_loop
.end:
	sub		rax, r8
	ret

; To avoid warnings from linker about stack section
section .note.GNU-stack noalloc noexec
