; char	*ft_strdup(const char *s);
;  rax                       rdi

global	ft_strdup			; Declare as global for external use
extern	malloc				; To be able to external functions
extern	ft_strlen
extern	ft_strcpy

ft_strdup:
	call	ft_strlen			; First, call strlen, getting len of rdi into rax
	push	rdi					; Store rdi in stack to be able to use it for malloc call
	inc		rax					; Add space for null byte
	mov		rdi, rax			; Set strlen to rdi
	call	malloc wrt ..plt	; Malloc with rdi size, getting void ptr into rax
	pop		rsi					; Get back *s into rsi
	mov		rdi, rax			; Move malloc'ed void ptr to rdi
	call	ft_strcpy			; Use strcpy
	ret							; Return new string (rax from strcpy)
