; ssize_t	ft_write(int fd, const void *buf, size_t count);
;	rax					 rdi			 rsi		  rdx

global	ft_write			; Declare as global for external use
extern	__errno_location	; To be able to use C errno value

ft_write:
	mov		rax, 4				; Syscall number for sys_write
	syscall
	jc		.error
	ret
.error:
	mov		r8, rax				; Saving rax as it is our error value
	call	__errno_location	; Put errno address into rax
	mov		[rax], r8			; Put back our error code into rax pointed value
	mov		rax, -1				; Setting return rax value to -1
	ret

; To avoid warnings from linker about stack section
section .note.GNU-stack noalloc noexec
