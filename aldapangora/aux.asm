segment .data
	msg_error_indice_vector	db "Indice de vector fuera de rango", 0
	msg_error_div_zero	db "ERROR: Division por 0", 0
segment .bss
	__esp resd 1
	_x resd 1
segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
main:
	mov dword [__esp], esp
	push dword 8
	pop dword [_x]
	push dword _x
	pop dword ecx
	push dword [ecx]
	add esp, 4
	call print_endofline
	jmp fin
	divisor_zero:
	push dword msg_error_div_zero
	call print_string
	add esp, 4
	call print_endofline
fin:
	mov dword esp, [__esp]
	ret
