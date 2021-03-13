			global	_ft_strcpy
			section	.text
_ft_strcpy:
			xor		rdx, rdx
			xor		rcx, rcx
			cmp		rsi, 0
			je		.done
			jmp		.copy

.increment:
			inc		rcx

.copy:
			mov		dl, byte[rsi + rcx]
			mov		byte[rdi + rcx], dl
			cmp		dl, 0
			jnz		.increment

.done:
			mov		rax, rdi
			ret
