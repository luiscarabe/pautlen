segment .data
	msg_error_indice_vector	db "ERROR: Indice de vector fuera de rango", 0
	msg_error_div_zero	db "ERROR: Division por 0", 0

segment .bss
	__esp resd 1

	_v1 resd 1

	_v2 resd 1

	_v3 resd 1

	_v4 resd 1

segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string, malloc, free

_main_f1@3@3:
	push ebp
	mov ebp, esp
	sub esp, 8

	push dword 1

	lea eax, [ebp-4]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 40

	pop dword [_v1]

	push dword 0

	lea eax, [ebp-8]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	lea eax, [ebp+12]
	push eax

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	je near fin_then0


	push dword _v1

	push dword 2

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	add eax, ebx
	push dword eax

	lea eax, [ebp-4]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 1

	lea eax, [ebp-8]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 2

	call print_int
	add esp, 4
	call print_endofline

	jmp near fin_else0
fin_then0:

	lea eax, [ebp+8]
	push eax

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	je near fin_then1


	push dword 10

	call print_int
	add esp, 4
	call print_endofline

fin_then1:

fin_else0:

	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

