			global	_ft_read
			extern	___error

			section	.text
_ft_read:
			mov		rax, 0x2000003
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
