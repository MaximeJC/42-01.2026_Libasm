; int	ft_strcmp(const char *s1, const char *s2);
; rax						 rdi			 rsi

global ft_strcmp

ft_strcmp:
	mov	rcx, 0
	mov rax, 0
	mov r8, 0
.check_loop:
	cmp	BYTE [rdi + rcx], 0
	je	.end
	cmp	BYTE [rsi + rcx], 0
	je	.end
	cmp	[rdi + rcx], [rsi + rcx]
	jne	.end
	inc	rcx
	jmp	.check_loop
.end:
	movzx	rax, BYTE [rdi + rcx]
	sub	rax, [rsi + rcx]
	ret

; To avoid warnings from linker about stack section
section .note.GNU-stack noalloc noexec
