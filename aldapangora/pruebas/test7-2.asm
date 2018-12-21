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
	push dword 80

	call print_int
	add esp, 4
	call print_endofline

	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

	push dword 500

	call print_int
	add esp, 4
	call print_endofline

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

fin_then0:

	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

	push dword 0

	lea eax, [ebp-8]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 70

	call print_int
	add esp, 4
	call print_endofline

	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

	push dword 90

	call print_int
	add esp, 4
	call print_endofline

	lea eax, [ebp-4]
	push eax

	pop dword edx
	mov eax, [edx]
	mov dword esp, ebp
	pop dword ebp
	ret

_main_f2@3:
	push ebp
	mov ebp, esp
	sub esp, 4

	push dword 90

	lea eax, [ebp-4]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 40

	pop dword [_v1]

	push dword 800

	call print_int
	add esp, 4
	call print_endofline

	push dword 0

	lea eax, [ebp-8]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

	push dword 0

	lea eax, [ebp-4]
	push eax

	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	lea eax, [ebp-4]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword 1000

	call print_int
	add esp, 4
	call print_endofline

	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

	push dword 2000

	call print_int
	add esp, 4
	call print_endofline

	lea eax, [ebp+8]
	push eax

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	je near fin_then1


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

fin_then1:

	lea eax, [ebp-8]
	push eax

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

	lea eax, [ebp-4]
	push eax

	pop dword edx
	mov eax, [edx]
	mov dword esp, ebp
	pop dword ebp
	ret

main:
	mov dword [__esp], esp

	push dword 1

	pop dword [_v1]

	push dword 1

	pop dword [_v4]

	push dword _v4

	pop dword edx
	mov dword eax, [edx]

	push eax

	push dword 1

	call _main_f1@3@3
	add esp, 8

	push dword eax

	call print_int
	add esp, 4
	call print_endofline

	push dword 0

	call _main_f2@3
	add esp, 4

	push dword eax

	call print_int
	add esp, 4
	call print_endofline

	push dword _v1

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _v4

	pop dword ecx
	push dword [ecx]
	call print_boolean
	add esp, 4
	call print_endofline

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

