			global	_ft_write
			section	.text
_ft_write:
			mov	rax, 0x2000004
			syscall
			jc	.error
			jmp	.done

.error:
			mov	rax, -1
			jmp	.done

.done:
			ret
