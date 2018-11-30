segment .data
	_offset_msA_msa1 dd 0
	_offset_msA_msa2 dd 4
	_offset_msB_msb1 dd 8
	_offset_msB_msb2 dd 12
	_offset_msC_msc1 dd 16
	_offset_msC_msc2 dd 20
	_offset_msD_msd1 dd 24
	_offset_msD_msd2 dd 28
	_offset_msD_msa2 dd 32

segment .bss
	_msA resd 2
	_msB resd 4
	_msC resd 6
	_msD resd 9

_create_ms_table:
	mov dword [_msA], _msA_msa1
	mov dword [_msA+4], _msA_msa2
	mov dword [_msB], _msB_msb1
	mov dword [_msB+4], _msB_msb2
	mov dword [_msC], _msA_msa1
	mov dword [_msC+4], _msA_msa2
	mov dword [_msC+8], _msB_msb1
	mov dword [_msC+12], _msB_msb2
	mov dword [_msC+16], _msC_msc1
	mov dword [_msC+20], _msC_msc2
	mov dword [_msD], _msA_msa1
	mov dword [_msD+4], _msD_msa2
	mov dword [_msD+8], _msB_msb1
	mov dword [_msD+12], _msB_msb2
	mov dword [_msD+16], _msD_msd1
	mov dword [_msD+20], _msD_msd2
	ret
