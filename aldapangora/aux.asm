segment .data
	msg_error_indice_vector	db "Indice de vector fuera de rango", 0
	msg_error_div_zero	db "ERROR: Division por 0", 0
segment .bss
	__esp resd 1
segment .txt
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string, malloc, free
main:
	mov dword [__esp], esp
	push dword 8
