			global	_ft_strdup
			section	.text
			extern	_malloc
			extern	_ft_strlen
			extern	_ft_strcpy
_ft_strdup:
			mov		rdx, rdi
			push	rdi

.scale_len:
			mov		rdi, rdx
			call	_ft_strlen
			mov		rcx, rax

.malloc_rax:
			inc		rcx
			mov		rdi, rcx
			call	_malloc
			cmp		rax, 0
			je		.err_exit

.str_cpy:
			mov		rdi, rax
			pop		rsi
			call	_ft_strcpy

.done:
			mov		rdi, rax
			ret

.err_exit:
			ret