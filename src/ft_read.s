; ssize_t	ft_read(int fd, void *buf, size_t count);
;	rax					rdi		  rsi		  rdx

global	ft_read							; Declare as global for external use
extern	__errno_location				; To be able to use C errno value

ft_read:
	mov		rax, 0						; Syscall number for sys_read
	syscall								; Call system read
	cmp		rax, 0
	jl		.error						; Jump if in previous cmp op1 was strictly lower than op2
	ret
.error:
	neg		rax							; Errno code is given in negative form, so you have to invert it
	mov		r8, rax						; Saving rax as it is our error value
	call	__errno_location wrt ..plt	; Put errno address into rax | "wrt ..plt" needed to correct "relocation R_X86_64_PC32" error
	mov		[rax], r8					; Put back our error code into rax pointed value
	mov		rax, -1						; Setting return rax value to -1
	ret

; To avoid warnings from linker about stack section - Not needed on LH 42's PC
; section .note.GNU-stack noalloc noexec
