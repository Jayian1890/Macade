# 1002a9a6 `__cftof_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a9a6 |
| `name` | __cftof_l |
| `namespace` | Global |
| `signature` | undefined __cftof_l(void) |
| `size_bytes` | 187 |
| `stack_frame_size` | 52 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cftof_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cftof_l
   
   Library: Visual Studio 2008 Release */

void __cftof_l(double *param_1,undefined1 *param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  size_t _SizeInBytes;
  errno_t eVar2;
  _strflt local_30;
  char local_20 [24];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  __fltout2((_CRT_DOUBLE)*param_1,&local_30,local_20,0x16);
  if ((param_2 == (undefined1 *)0x0) || (param_3 == 0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
  }
  else {
    if (param_3 == -1) {
      _SizeInBytes = 0xffffffff;
    }
    else {
      _SizeInBytes = param_3 - (uint)(local_30.sign == 0x2d);
    }
    eVar2 = __fptostr(param_2 + (local_30.sign == 0x2d),_SizeInBytes,local_30.decpt + param_4,
                      &local_30);
    if (eVar2 == 0) {
      __cftof2_l(param_3,param_4,0,param_5);
    }
    else {
      *param_2 = 0;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a9d2` | `1002af99` | `UNCONDITIONAL_CALL` | __fltout2 | `1002af99` |
| `1002a9e0` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a9ec` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002aa2d` | `1002ae1d` | `UNCONDITIONAL_CALL` | __fptostr | `1002ae1d` |
| `1002aa4a` | `1002a8af` | `UNCONDITIONAL_CALL` | __cftof2_l | `1002a8af` |
| `1002aa5a` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002ab81` | __cfltcvt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002a9ae` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a9a6` | `8b ff` | `MOV EDI,EDI` |
| `1002a9a8` | `55` | `PUSH EBP` |
| `1002a9a9` | `8b ec` | `MOV EBP,ESP` |
| `1002a9ab` | `83 ec 2c` | `SUB ESP,0x2c` |
| `1002a9ae` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002a9b3` | `33 c5` | `XOR EAX,EBP` |
| `1002a9b5` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002a9b8` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002a9bb` | `53` | `PUSH EBX` |
| `1002a9bc` | `56` | `PUSH ESI` |
| `1002a9bd` | `57` | `PUSH EDI` |
| `1002a9be` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1002a9c1` | `6a 16` | `PUSH 0x16` |
| `1002a9c3` | `5e` | `POP ESI` |
| `1002a9c4` | `56` | `PUSH ESI` |
| `1002a9c5` | `8d 4d e4` | `LEA ECX,[EBP + -0x1c]` |
| `1002a9c8` | `51` | `PUSH ECX` |
| `1002a9c9` | `8d 4d d4` | `LEA ECX,[EBP + -0x2c]` |
| `1002a9cc` | `51` | `PUSH ECX` |
| `1002a9cd` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1002a9d0` | `ff 30` | `PUSH dword ptr [EAX]` |
| `1002a9d2` | `e8 c2 05 00 00` | `CALL 0x1002af99` |
| `1002a9d7` | `33 db` | `XOR EBX,EBX` |
| `1002a9d9` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a9dc` | `3b fb` | `CMP EDI,EBX` |
| `1002a9de` | `75 18` | `JNZ 0x1002a9f8` |
| `1002a9e0` | `e8 24 a7 fe ff` | `CALL 0x10015109` |
| `1002a9e5` | `53` | `PUSH EBX` |
| `1002a9e6` | `53` | `PUSH EBX` |
| `1002a9e7` | `53` | `PUSH EBX` |
| `1002a9e8` | `53` | `PUSH EBX` |
| `1002a9e9` | `53` | `PUSH EBX` |
| `1002a9ea` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1002a9ec` | `e8 be 6c fe ff` | `CALL 0x100116af` |
| `1002a9f1` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a9f4` | `8b c6` | `MOV EAX,ESI` |
| `1002a9f6` | `eb 5a` | `JMP 0x1002aa52` |
| `1002a9f8` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1002a9fb` | `3b c3` | `CMP EAX,EBX` |
| `1002a9fd` | `76 e1` | `JBE 0x1002a9e0` |
| `1002a9ff` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1002aa02` | `75 04` | `JNZ 0x1002aa08` |
| `1002aa04` | `0b c0` | `OR EAX,EAX` |
| `1002aa06` | `eb 0b` | `JMP 0x1002aa13` |
| `1002aa08` | `33 c9` | `XOR ECX,ECX` |
| `1002aa0a` | `83 7d d4 2d` | `CMP dword ptr [EBP + -0x2c],0x2d` |
| `1002aa0e` | `0f 94 c1` | `SETZ CL` |
| `1002aa11` | `2b c1` | `SUB EAX,ECX` |
| `1002aa13` | `8b 75 14` | `MOV ESI,dword ptr [EBP + 0x14]` |
| `1002aa16` | `8d 4d d4` | `LEA ECX,[EBP + -0x2c]` |
| `1002aa19` | `51` | `PUSH ECX` |
| `1002aa1a` | `8b 4d d8` | `MOV ECX,dword ptr [EBP + -0x28]` |
| `1002aa1d` | `03 ce` | `ADD ECX,ESI` |
| `1002aa1f` | `51` | `PUSH ECX` |
| `1002aa20` | `50` | `PUSH EAX` |
| `1002aa21` | `33 c0` | `XOR EAX,EAX` |
| `1002aa23` | `83 7d d4 2d` | `CMP dword ptr [EBP + -0x2c],0x2d` |
| `1002aa27` | `0f 94 c0` | `SETZ AL` |
| `1002aa2a` | `03 c7` | `ADD EAX,EDI` |
| `1002aa2c` | `50` | `PUSH EAX` |
| `1002aa2d` | `e8 eb 03 00 00` | `CALL 0x1002ae1d` |
| `1002aa32` | `83 c4 10` | `ADD ESP,0x10` |
| `1002aa35` | `3b c3` | `CMP EAX,EBX` |
| `1002aa37` | `74 04` | `JZ 0x1002aa3d` |
| `1002aa39` | `88 1f` | `MOV byte ptr [EDI],BL` |
| `1002aa3b` | `eb 15` | `JMP 0x1002aa52` |
| `1002aa3d` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002aa40` | `8d 45 d4` | `LEA EAX,[EBP + -0x2c]` |
| `1002aa43` | `53` | `PUSH EBX` |
| `1002aa44` | `56` | `PUSH ESI` |
| `1002aa45` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002aa48` | `8b cf` | `MOV ECX,EDI` |
| `1002aa4a` | `e8 60 fe ff ff` | `CALL 0x1002a8af` |
| `1002aa4f` | `83 c4 10` | `ADD ESP,0x10` |
| `1002aa52` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002aa55` | `5f` | `POP EDI` |
| `1002aa56` | `5e` | `POP ESI` |
| `1002aa57` | `33 cd` | `XOR ECX,EBP` |
| `1002aa59` | `5b` | `POP EBX` |
| `1002aa5a` | `e8 6c 62 fe ff` | `CALL 0x10010ccb` |
| `1002aa5f` | `c9` | `LEAVE` |
| `1002aa60` | `c3` | `RET` |
