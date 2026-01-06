; char	*ft_strcpy(char *dest, const char *src);
;  rax					rdi				   rsi

global ft_strcpy			; Declare as global for external use

ft_strcpy:
	mov	rcx, 0					; Initialize index counter to 0 in rcx
.copy_loop:
	mov	al, BYTE [rsi + rcx]	; We can't move from one address to another, we need a temp var to store the byte, here al
	mov	BYTE [rdi + rcx], al	; al is a reg meant to store a single byte
	inc	rcx						; Increment counter
	cmp	BYTE [rsi + rcx], 0		; Check if end of string
	jne	.copy_loop				; Jump if not equal, can replace the three following lines:
								; 	 	je	.loop_end	- End loop if null char of src
								; 		jmp	.copy_loop	- Else, continue loop
								; 	.loop_end:
	mov	rax, rdi				; Setting dest ptr as the return value
	ret

; To avoid warnings from linker about stack section
section .note.GNU-stack noalloc noexec
