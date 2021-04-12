			global	_ft_strcmp2

			section	.text
_ft_strcmp2:
			xor		rax, rax
			xor		rdx, rdx
			cld
			jmp		.cmp

.cmp:
			mov		al, [rdi]
			test	al, [rsi]
			jz		.end_cmp
			cmpsb
			je		.cmp
			jmp		.end_cmp2

.end_cmp:
			mov		al, [rdi]
			sub		al, [rsi]
			movsx	rax, al
			jmp		.done

.end_cmp2:
			dec		rdi
			dec		rsi
			mov		al, [rdi]
			sub		al, [rsi]
			movsx	rax, al
			jmp		.done

.done:
			ret
