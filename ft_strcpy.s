			global	_ft_strcpy
			section	.text
_ft_strcpy:
			xor		rax, rax
			xor		rcx, rcx
			cmp		byte [rsi], 0
			je		.done
			jmp		.copy

.increment:
			inc		rcx

.copy:
			mov		al, byte [rsi + rcx]
			mov		byte [rdi + rcx], al
			cmp		al, 0
			jne		.increment

.done:
			mov		rax, rdi
			ret
