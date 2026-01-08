; char	*ft_strdup(const char *s);
;  rax                       rdi

global	ft_strdup			; Declare as global for external use
extern	malloc				; To be able to external functions
extern	ft_strlen
extern	ft_strcpy

ft_strdup:
	mov		rax, 0
	mov		rsi, 0
	call	ft_strlen
	push	rdi
	inc		rax
	mov		rdi, rax
	call	malloc wrt ..plt
	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	ret
