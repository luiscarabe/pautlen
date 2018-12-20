segment .data
	global  _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1,     _offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1
	_offset_msA1 dd 0
	_offset_msA2 dd 4
	_offset_msB1 dd 8
	_offset_msB2 dd 12
	_offset_msC1 dd 16
	_offset_msC2 dd 20
	_offset_msD1 dd 24
	_offset_msD2 dd 28
	_offset_aiA1 dd 4 ; 4+0
  _offset_aiA2 dd 8 ; 4+4
  _offset_aiB1 dd 12 ; 4+8
  _offset_aiB2 dd 16 ; 4 + 12
  _offset_aiC1 dd 20 ; 4+ 16
  _offset_aiC2 dd 24 ; 4+20
  _offset_aiD1 dd 28 ; 4+24
  _offset_aiD2 dd 32 ; 4+28


segment .bss
	_msA resd 2
	_msB resd 4
	_msC resd 8
	_msD resd 10
	_object_a1 resd 1
	_object_b1 resd 1
	_object_c1 resd 1
  _object_c2 resd 1
  _object_d1 resd 1
	_acA1 resd 1
  _acB1 resd 1
  _acC1 resd 1
  _acD1 resd 1

segment .txt
_create_ms_table:
  mov dword [_msA], _msA1        
  mov dword [_msA+4], _msA2        
  mov dword [_msB], _BmsA1        
  mov dword [_msB+4], _msA2        
  mov dword [_msB+8], _msB1
  mov dword [_msB+12], _msB2        
  mov dword [_msC], _CmsA1        
  mov dword [_msC+4], _CmsA2
  mov dword [_msC+8], _no_defined_method
  mov dword [_msC+12], _no_defined_method        
  mov dword [_msC+16], _msC1        
  mov dword [_msC+20], _msC2        
  mov dword [_msD], _BmsA1        
  mov dword [_msD+4], _msA2        
  mov dword [_msD+8], _msB1
  mov dword [_msD+12], _msB2        
  mov dword [_msD+16], _msC1        
  mov dword [_msD+20], _msC2        
  mov dword [_msD+24], _msD1        
  mov dword [_msD+28], _msD2        
  ret

_msA1:
	ret
_msA2:
	ret
_msB1:
	ret
_msB2:
	ret
_msC1:
	ret
_msC2:
	ret
_msD1:
	ret
_msD2:
	ret
_BmsA1:
	ret
_CmsA1:
	ret
_CmsA2:
	ret
_no_defined_method:
	ret
_mnsA1:
	ret
_mnsB1:
	ret
_mnsC1:
	ret
_mnsD1:
	ret
	_set_offsets: 
	ret
