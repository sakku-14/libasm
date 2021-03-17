			global	_ft_strcmp
			section	.text
_ft_strcmp:
			xor		rax, rax
			xor		rcx, rcx
			xor		rdx, rdx
			cmp		byte [rdi], 0
			je		.end_cmp
			cmp		byte [rsi], 0
			je		.end_cmp
			jmp		.cmp

.increment:
			inc		rcx

.cmp:
			mov		al, byte [rdi + rcx]
			mov		dl, byte [rsi + rcx]
			cmp		al, 0
			je		.end_cmp
			cmp		dl, 0
			je		.end_cmp
			cmp		al, dl
			je		.increment
			jne		.done

.end_cmp:
			mov		al, byte [rdi + rcx]
			mov		dl, byte [rsi + rcx]
			sub		rax, rdx
			jmp		.done

.done:
			ret
