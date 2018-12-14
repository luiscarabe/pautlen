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
	push dword _x1
	push dword _x2
	pop dword edx
	mov dword ebx, [edx]
	pop dword edx
	mov dword eax, [edx]
	cmp eax, ebx
	je near branch_2
	mov dword eax, 0
	jmp near branchend_2
branch_2:
	mov dword eax, 1
branchend_2:
	push dword eax
	pop dword eax
	cmp eax, 0
	je near fin_then2
	push dword 1
	call print_int
	add esp, 4
	call print_endofline
	push dword 2
	call print_int
	add esp, 4
	call print_endofline
	push dword _x1
	push dword 1
	pop dword ebx
	pop dword edx
	mov dword eax, [edx]
	cmp eax, ebx
	je near branch_4
	mov dword eax, 0
	jmp near branchend_4
branch_4:
	mov dword eax, 1
branchend_4:
	push dword eax
	pop dword eax
	cmp eax, 0
	je near fin_then4
	push dword 3
	call print_int
	add esp, 4
	call print_endofline
fin_then4:
fin_then2:
	jmp fin
	divisor_zero:
	push dword msg_error_div_zero
	call print_string
	add esp, 4
	call print_endofline
fin:
	mov dword esp, [__esp]
	ret
