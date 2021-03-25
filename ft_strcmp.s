			global	_ft_strcmp

			section	.text
_ft_strcmp:
			xor		rax, rax
			xor		rcx, rcx
			xor		rdx, rdx
			jmp		.cmp

.increment:
			inc		rcx

.cmp:
			mov		al, byte [rdi + rcx]
			mov		dl, byte [rsi + rcx]
			cmp		al, 0
			je		.end_cmp
			cmp		al, dl
			jne		.end_cmp
			jmp		.increment

.end_cmp:
			sub		rax, rdx
			jmp		.done

.done:
			ret
