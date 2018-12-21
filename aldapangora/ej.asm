segment .data
	msg_error_indice_vector	db "ERROR: Indice de vector fuera de rango", 0
	msg_error_div_zero	db "ERROR: Division por 0", 0

segment .bss
	__esp resd 1

	_m resd 1

	_d1 resd 1

	_c1 resd 1

	_c2 resd 1

	_c3 resd 1

	_vector_int resd 4

	_Vobjs resd 3

segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string, malloc, free

	extern  _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1,     _offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1
_main_factorial@o2:
	push ebp
	mov ebp, esp
	sub esp, 8

	push dword 28
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax

	lea eax, [ebp-8]
	push eax

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 9999

	lea eax, [ebp-8]
	push eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	lea eax, [ebp-8]
	push eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword 111111

	lea eax, [ebp-8]
	push eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	lea eax, [ebp-8]
	push eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword 100

	lea eax, [ebp-4]
	push eax

	; asignarDestinoEnPila(0)
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

	push dword 333

	lea eax, [ebp+8]
	push eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	lea eax, [ebp+8]
	push eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	lea eax, [ebp-8]
	push eax

	pop dword edx
	mov eax, [edx]
	mov dword esp, ebp
	pop dword ebp
	ret

main:
	mov dword [__esp], esp

	call _create_ms_table
	push dword 28
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax

	push dword _c1

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 99

	push dword _c1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword _c1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _c1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msA1]
	lea ecx, [ebx + ecx]
	mov dword ecx, [ecx]
	call ecx

	push dword _c1

	pop dword edx
	mov dword eax, [edx]

	push eax

	call _main_factorial@o2
	add esp, 4

	push dword eax

	pop dword [_c2]

	push dword _c1

	pop ebx
	push dword [ebx]
	call free
	add esp, 4

	push dword _c2

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword 36
	call malloc
	add esp, 4
	mov dword [eax], _msD
	push eax

	push dword _d1

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 28
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax

	push dword _d1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiD2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword _d1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiD2]
	lea ecx, [ebx+ecx]
	push dword ecx

	push dword _c1

	; asignarDestinoEnPila(1)
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword [eax], ebx
	push dword 99

	push dword _c1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 20

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword _m

	push dword 0

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jg near branch_1
	mov dword eax, 0
	jmp near branchend_1
branch_1:
	mov dword eax, 1
branchend_1:
	push dword eax


	pop dword eax

	cmp eax, 0
	je near fin_then1


	push dword 0

	call print_int
	add esp, 4
	call print_endofline

	push dword _m

	push dword 2

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jg near branch_2
	mov dword eax, 0
	jmp near branchend_2
branch_2:
	mov dword eax, 1
branchend_2:
	push dword eax


	push dword 22

	call print_int
	add esp, 4
	call print_endofline

fin_else2:

inicio_while3:

	push dword _m

	push dword 0

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jge near branch_3
	mov dword eax, 0
	jmp near branchend_3
branch_3:
	mov dword eax, 1
branchend_3:
	push dword eax


	pop dword eax

	cmp eax, 0
	je near fin_while3

	push dword _m

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _m

	push dword 1

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	sub eax, ebx
	push dword eax

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	jmp near inicio_while3
fin_while3:

	jmp near fin_else1
fin_then1:

	push dword 1

	call print_int
	add esp, 4
	call print_endofline

	push dword _m

	push dword -11

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jl near branch_4
	mov dword eax, 0
	jmp near branchend_4
branch_4:
	mov dword eax, 1
branchend_4:
	push dword eax


	push dword -11

	call print_int
	add esp, 4
	call print_endofline

fin_else4:

fin_else1:

	push dword 0

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
inicio_while5:

	push dword _m

	push dword 3

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jle near branch_5
	mov dword eax, 0
	jmp near branchend_5
branch_5:
	mov dword eax, 1
branchend_5:
	push dword eax


	pop dword eax

	cmp eax, 0
	je near fin_while5

	push dword _m

	push dword 10

	pop dword ecx

	pop dword edx
	mov dword eax, [edx]

	imul ecx
	push dword eax

	push dword _m

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	jl near index_error
	cmp eax, 3
	jg near index_error
	mov dword edx, _vector_int
	lea eax, [edx + eax*4]
	push dword eax

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword _m

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	jl near index_error
	cmp eax, 3
	jg near index_error
	mov dword edx, _vector_int
	lea eax, [edx + eax*4]
	push dword eax

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _m

	push dword 1

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	add eax, ebx
	push dword eax

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	jmp near inicio_while5
fin_while5:

	push dword 2

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 3
	jg near index_error
	mov dword edx, _vector_int
	lea eax, [edx + eax*4]
	push dword eax

	push dword _m

	; asignarDestinoEnPila(1)
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword [eax], ebx
	push dword _m

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword 999999999

	call print_int
	add esp, 4
	call print_endofline

	push dword 20
	call malloc
	add esp, 4
	mov dword [eax], _msB
	push eax

	push dword 0

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 28
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax

	push dword 1

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 36
	call malloc
	add esp, 4
	mov dword [eax], _msD
	push eax

	push dword 2

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 0

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
inicio_while6:

	push dword _m

	push dword 2

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jle near branch_6
	mov dword eax, 0
	jmp near branchend_6
branch_6:
	mov dword eax, 1
branchend_6:
	push dword eax


	pop dword eax

	cmp eax, 0
	je near fin_while6

	push dword _m

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _m

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msA1]
	lea ecx, [ebx + ecx]
	mov dword ecx, [ecx]
	call ecx

	push dword _m

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msA2]
	lea ecx, [ebx + ecx]
	mov dword ecx, [ecx]
	call ecx

	push dword _m

	push dword 1

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	add eax, ebx
	push dword eax

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	jmp near inicio_while6
fin_while6:

	push dword 0

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
inicio_while7:

	push dword _m

	push dword 2

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	cmp eax, ebx
	jle near branch_7
	mov dword eax, 0
	jmp near branchend_7
branch_7:
	mov dword eax, 1
branchend_7:
	push dword eax


	pop dword eax

	cmp eax, 0
	je near fin_while7

	push dword _m

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _m

	pop dword edx
	mov dword eax, [edx]

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	pop ebx
	push dword [ebx]
	call free
	add esp, 4

	push dword _m

	push dword 1

	pop dword ebx

	pop dword edx
	mov dword eax, [edx]

	add eax, ebx
	push dword eax

	push dword _m

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	jmp near inicio_while7
fin_while7:

	push dword _c2

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _c2

	push dword 2

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	; asignarDestinoEnPila(1)
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword [eax], ebx
	push dword 28
	call malloc
	add esp, 4
	mov dword [eax], _msC
	push eax

	push dword _c3

	; asignarDestinoEnPila(0)
	pop dword eax
	pop dword ebx
	mov dword [eax], ebx
	push dword 2

	pop dword eax

	cmp eax, 0
	jl near index_error
	cmp eax, 2
	jg near index_error
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	push dword _c3

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	; asignarDestinoEnPila(1)
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword [eax], ebx
	push dword _c3

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop dword ecx
	push dword [ecx]
	call print_int
	add esp, 4
	call print_endofline

	push dword _c3

	pop ebx
	push dword [ebx]
	call free
	add esp, 4

	push dword _c2

	pop ebx
	push dword [ebx]
	call free
	add esp, 4

	push dword _d1

	pop ebx
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_aiD2]
	lea ecx, [ebx+ecx]
	push dword ecx

	pop ebx
	push dword [ebx]
	call free
	add esp, 4

	push dword _d1

	pop ebx
	push dword [ebx]
	call free
	add esp, 4

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

