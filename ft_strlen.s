			global	_ft_strlen
			section	.text
_ft_strlen:
			xor		rax, rax
			jmp		.compare

.increment:
			inc		rax

.compare:
			cmp		BYTE [rdi + rax], 0
			jne		.increment

.done:
			ret

