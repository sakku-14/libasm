			global	_ft_strcpy

			section	.text
_ft_strcpy:
			xor		rcx, rcx
			jmp		.copy

.increment:
			inc		rcx

.copy:
			cmp		byte [rsi + rcx], 0
			je		.done
			mov		al, byte [rsi + rcx]
			mov		byte [rdi + rcx], al
			jne		.increment

.done:
			mov		byte [rdi + rcx], 0
			mov		rax, rdi
			ret
