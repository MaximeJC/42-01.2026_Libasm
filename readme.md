

## Registers
ASM works with processors registers to store variables. Existing registers in our case are:

We have to be careful when putting data in those registers, because they can be used by the system at any time (read or written).

	rax is used to store the return value of a function.
	rcx is used as a counter in loops.
	rbx
	rsp is used to store the stack pointer.
	rbp is used to store the base pointer.
	rdi, rsi, rdx, rcx, r8, r9 are used respectively to pass arguments, vulgarly like function(rdi, rsi, rdx, rcx, r8, r9). Other arguments when more than 6 are stored on the stack
	rip

	This may seem like an inconvenience, but it is actually very useful to manipulate the behavior of the program.
	For instance, if we want to call `sys_write`:
	We put the syscall number (4 for `sys_write`) in `rax`.
	We put the file descriptor in `rdi`.
	We put the address of the buffer in `rsi`.
	We put the number of bytes to write in `rdx`.
	We call the `syscall` instruction.

The conclusion is: the little boxes are very useful as intermediate storage for data, but we have to be careful not to overwrite them when we (or the system) need them.

## Syntax
The syntax used in this repository is the Intel syntax. It is the most common syntax used in assembly programming, and a requisite of the subject. It is characterized by the fact that the destination operand is on the left and the source operand is on the right.


## Useful commands:
`nano /usr/include/x86_64-linux-gnu/asm/unistd_32.h`: Check syscalls numbers (like exit, read, write, etc.)

#define __NR_restart_syscall 0
#define __NR_exit 1
#define __NR_fork 2
#define __NR_read 3
#define __NR_write 4
#define __NR_open 5
#define __NR_close 6
