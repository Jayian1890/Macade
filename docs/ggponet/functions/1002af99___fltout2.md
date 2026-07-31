# 1002af99 `__fltout2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002af99 |
| `name` | __fltout2 |
| `namespace` | Global |
| `signature` | STRFLT __cdecl __fltout2(_CRT_DOUBLE _Dbl, STRFLT _Flt, char * _ResultStr, size_t _SizeInBytes) |
| `size_bytes` | 141 |
| `stack_frame_size` | 76 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fltout2 |

## Decompiled C

```c

/* Library Function - Single Match
    __fltout2
   
   Library: Visual Studio 2008 Release */

STRFLT __cdecl __fltout2(_CRT_DOUBLE _Dbl,STRFLT _Flt,char *_ResultStr,size_t _SizeInBytes)

{
  int iVar1;
  errno_t eVar2;
  STRFLT p_Var3;
  undefined4 in_stack_ffffffb0;
  undefined2 uVar4;
  short local_30;
  char local_2e;
  char local_2c [24];
  undefined4 local_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  uint local_8;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffb0 >> 0x10);
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ___dtold(&local_14,&_Dbl);
  iVar1 = _I10_OUTPUT(local_14,uStack_10,CONCAT22(uVar4,uStack_c),0x11,0,&local_30);
  _Flt->flag = iVar1;
  _Flt->sign = (int)local_2e;
  _Flt->decpt = (int)local_30;
  eVar2 = _strcpy_s(_ResultStr,_SizeInBytes,local_2c);
  if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  _Flt->mantissa = _ResultStr;
  p_Var3 = (STRFLT)__security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return p_Var3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002afbf` | `1002aedc` | `UNCONDITIONAL_CALL` | ___dtold | `1002aedc` |
| `1002afda` | `1002c31b` | `UNCONDITIONAL_CALL` | $I10_OUTPUT | `1002c31b` |
| `1002affa` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1002b00d` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1002b022` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002a478` | __cftoe_l |
| `1002a9d2` | __cftof_l |
| `1002aa8d` | __cftog_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002afa1` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002af99` | `8b ff` | `MOV EDI,EDI` |
| `1002af9b` | `55` | `PUSH EBP` |
| `1002af9c` | `8b ec` | `MOV EBP,ESP` |
| `1002af9e` | `83 ec 30` | `SUB ESP,0x30` |
| `1002afa1` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002afa6` | `33 c5` | `XOR EAX,EBP` |
| `1002afa8` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002afab` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1002afae` | `53` | `PUSH EBX` |
| `1002afaf` | `8b 5d 10` | `MOV EBX,dword ptr [EBP + 0x10]` |
| `1002afb2` | `56` | `PUSH ESI` |
| `1002afb3` | `89 45 d0` | `MOV dword ptr [EBP + -0x30],EAX` |
| `1002afb6` | `57` | `PUSH EDI` |
| `1002afb7` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `1002afba` | `50` | `PUSH EAX` |
| `1002afbb` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1002afbe` | `50` | `PUSH EAX` |
| `1002afbf` | `e8 18 ff ff ff` | `CALL 0x1002aedc` |
| `1002afc4` | `59` | `POP ECX` |
| `1002afc5` | `59` | `POP ECX` |
| `1002afc6` | `8d 45 d4` | `LEA EAX,[EBP + -0x2c]` |
| `1002afc9` | `50` | `PUSH EAX` |
| `1002afca` | `6a 00` | `PUSH 0x0` |
| `1002afcc` | `6a 11` | `PUSH 0x11` |
| `1002afce` | `83 ec 0c` | `SUB ESP,0xc` |
| `1002afd1` | `8d 75 f0` | `LEA ESI,[EBP + -0x10]` |
| `1002afd4` | `8b fc` | `MOV EDI,ESP` |
| `1002afd6` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002afd7` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002afd8` | `66 a5` | `MOVSW ES:EDI,ESI` |
| `1002afda` | `e8 3c 13 00 00` | `CALL 0x1002c31b` |
| `1002afdf` | `8b 75 d0` | `MOV ESI,dword ptr [EBP + -0x30]` |
| `1002afe2` | `89 43 08` | `MOV dword ptr [EBX + 0x8],EAX` |
| `1002afe5` | `0f be 45 d6` | `MOVSX EAX,byte ptr [EBP + -0x2a]` |
| `1002afe9` | `89 03` | `MOV dword ptr [EBX],EAX` |
| `1002afeb` | `0f bf 45 d4` | `MOVSX EAX,word ptr [EBP + -0x2c]` |
| `1002afef` | `89 43 04` | `MOV dword ptr [EBX + 0x4],EAX` |
| `1002aff2` | `8d 45 d8` | `LEA EAX,[EBP + -0x28]` |
| `1002aff5` | `50` | `PUSH EAX` |
| `1002aff6` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002aff9` | `56` | `PUSH ESI` |
| `1002affa` | `e8 7c af fe ff` | `CALL 0x10015f7b` |
| `1002afff` | `83 c4 24` | `ADD ESP,0x24` |
| `1002b002` | `85 c0` | `TEST EAX,EAX` |
| `1002b004` | `74 0f` | `JZ 0x1002b015` |
| `1002b006` | `33 c0` | `XOR EAX,EAX` |
| `1002b008` | `50` | `PUSH EAX` |
| `1002b009` | `50` | `PUSH EAX` |
| `1002b00a` | `50` | `PUSH EAX` |
| `1002b00b` | `50` | `PUSH EAX` |
| `1002b00c` | `50` | `PUSH EAX` |
| `1002b00d` | `e8 75 65 fe ff` | `CALL 0x10011587` |
| `1002b015` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b018` | `5f` | `POP EDI` |
| `1002b019` | `89 73 0c` | `MOV dword ptr [EBX + 0xc],ESI` |
| `1002b01c` | `5e` | `POP ESI` |
| `1002b01d` | `8b c3` | `MOV EAX,EBX` |
| `1002b01f` | `33 cd` | `XOR ECX,EBP` |
| `1002b021` | `5b` | `POP EBX` |
| `1002b022` | `e8 a4 5c fe ff` | `CALL 0x10010ccb` |
| `1002b027` | `c9` | `LEAVE` |
| `1002b028` | `c3` | `RET` |
