segment .data
	msg_error_indice_vector	db "ERROR: Indice de vector fuera de rango", 0
	msg_error_div_zero	db "ERROR: Division por 0", 0

segment .bss
	__esp resd 1

	_x1 resd 10

segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string, malloc, free

main:
	mov dword [__esp], esp

	push dword 1

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 9
	jg near index_error
	mov dword edx, _x1
	lea eax, [edx + eax*4]
	push dword eax

	push dword 5

	push dword 0

	pop dword ecx

	pop dword eax

	cmp ecx, 0
	je near divisor_zero
	cdq
	idiv ecx
	push dword eax

	pop dword eax

	pop dword edx

	mov dword [edx] , eax

	jmp near fin
index_error:
	push dword msg_error_indice_vector
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
divisor_zero:
	push dword msg_error_div_zero
	call print_string
	add esp, 4
	call print_endofline
fin:
	mov dword esp, [__esp]
	ret

