segment .data
	msg_error_indice_vector	db "Indice de vector fuera de rango", 0
	msg_error_div_zero	db "ERROR: Division por 0", 0
segment .bss
	__esp resd 1
	_x1 resd 1
	_x2 resd 1
	_y1 resd 1
segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
main:
	mov dword [__esp], esp
	push dword _x1
	call scan_int
	add esp, 4
	push dword _x2
	call scan_int
	add esp, 4
	push dword 3
	push dword _x1
	pop dword edx
	mov dword ebx, [edx]
	pop dword eax
	add eax, ebx
	push dword eax
	push dword _x2
	pop dword edx
	mov dword ebx, [edx]
	pop dword eax
	add eax, ebx
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _x1
	push dword _x2
	pop dword edx
	mov dword ebx, [edx]
	pop dword edx
	mov dword eax, [edx]
	cmp eax, ebx
	je near branch_1
	mov dword eax, 0
	jmp near branchend_1
branch_1:
	mov dword eax, 1
branchend_1:
	push dword eax
	pop dword [_y1]
	push dword _y1
	pop dword ecx
	push dword [ecx]
	call print_boolean
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
