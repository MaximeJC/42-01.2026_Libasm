; size_t	ft_strlen(const char *s);
;  rax							rdi

global ft_strlen			; Declare as global for external use

ft_strlen:
	mov	rcx, 0				; Initialize length counter to 0 in rcx, usually used for counters
.loop:
	cmp	BYTE [rdi + rcx], 0	; Compare byte at address (rdi + *rcx) with 0 (null char).
							; rdi is a reg. that typically holds the ptr to the function first argument (here, the string)
	je	.end				; If the byte is 0, jump to .end
	inc	rcx					; Increment length counter
	jmp	.loop				; Repeat the loop
.end:
	mov	rax, rcx			; Move the length from rcx to rax (return value)
	ret						; Return from function

; To avoid warnings from linker about stack section
section .note.GNU-stack noalloc noexec
