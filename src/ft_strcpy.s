; char	*ft_strcpy(char *dest, const char *src);
;  rax					rdi				   rsi

global ft_strcpy			; Declare as global for external use

ft_strcpy:
	mov	rcx, 0					; Initialize index counter to 0 in rcx
.copy_loop:
	cmp	BYTE [rsi + rcx], 0		; Check if end of string
	je	.end
	mov	al, BYTE [rsi + rcx]	; We can't move from one address to another, we need a temp var to store the byte, here al
	mov	BYTE [rdi + rcx], al	; al is a reg meant to store a single byte
	inc	rcx						; Increment counter
	jmp	.copy_loop				; Jump to loop again
.end:
	mov	al, BYTE [rsi + rcx]	; Copy NULL byte
	mov	BYTE [rdi + rcx], al
	mov	rax, rdi				; Setting dest ptr as the return value
	ret

; To avoid warnings from linker about stack section - Not needed on LH 42's PC
; section .note.GNU-stack noalloc noexec
