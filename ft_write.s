			global	_ft_write
			section	.text
			extern	___error
_ft_write:
			mov		rax, 0x2000004
			syscall
			jc		.error
			jmp		.done

.error:
			push	rax
			call	___error
			pop		qword [rax]
			mov		rax, -1

.done:
			ret
