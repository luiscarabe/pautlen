segment .data
	_offset_msAA_mA1@1 dd 0
	_offset_aiAA_sa1 dd 4

segment .bss
	_msAA resd 1
	_AA_a1 resd dd 1

_create_ms_table:
	mov dword [_msAA], _msAA_mA1@1
	ret
