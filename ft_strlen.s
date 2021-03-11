			section .text
			global _ft_strlen

_ft_strlen:
			xor		rax, rax
			cmp		rdi, 0
			je		.done
			jmp		.compare

.increment:
			inc		rax

.compare:
			cmp		BYTE [rdi + rax], 0
			jne		.increment

.done:
	ret

