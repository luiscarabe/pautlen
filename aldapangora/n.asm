segment .data
_offset_msA1 dd 0
_offset_msA2 dd 4
_offset_msB1 dd 8
_offset_msB2 dd 12
_offset_msC1 dd 16
_offset_msC2 dd 20
_offset_msD1 dd 24
_offset_msD2 dd 28


segment .bss
	_msA resd 2
	_msB resd 4
	_msC resd 8
	_msD resd 10
	_AA_a1 resd dd 1

_create_ms_table:
	mov dword [_msAA], _msAA_mA1@1
	ret
