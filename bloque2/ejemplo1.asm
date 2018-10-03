segment .data
	msg_error_indice_vector	db "Indice de vector fuera de rango", 0
	msg_error_div_zero	db "Division por 0", 0
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
main:
	mov dword [__esp], esp
	push dword 8

pop dword [_x]
	call scan_int
	add esp, 4
	push dword _x
	push dword _y
	pop dword eax
	mov dword eax, [eax]
	pop dword ebx
	mov dword ebx, [ebx]
	add eax, ebx
	push dword eax

pop dword [_z]
	push dword _z
	call print_int
	call print_endofline
	add esp, 4
	push dword 7
	push dword _y
	pop dword eax
	mov dword eax, [eax]
	pop dword ebx
	add eax, ebx
	push dword eax

pop dword [_z]
	push dword _z
	call print_int
	call print_endofline
	add esp, 4
fin:
	mov dword esp, [__esp]
	ret
