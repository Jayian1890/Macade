# 1002a44c `__cftoe_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a44c |
| `name` | __cftoe_l |
| `namespace` | Global |
| `signature` | undefined __cftoe_l(void) |
| `size_bytes` | 208 |
| `stack_frame_size` | 52 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cftoe_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cftoe_l
   
   Library: Visual Studio 2008 Release */

void __cftoe_l(double *param_1,undefined1 *param_2,int param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

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
      _SizeInBytes = (param_3 - (uint)(local_30.sign == 0x2d)) - (uint)(0 < param_4);
    }
    eVar2 = __fptostr(param_2 + (uint)(0 < param_4) + (uint)(local_30.sign == 0x2d),_SizeInBytes,
                      param_4 + 1,&local_30);
    if (eVar2 == 0) {
      __cftoe2_l(param_3,param_4,param_5,&local_30,0,param_6);
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
| `1002a478` | `1002af99` | `UNCONDITIONAL_CALL` | __fltout2 | `1002af99` |
| `1002a486` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a492` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002a4e4` | `1002ae1d` | `UNCONDITIONAL_CALL` | __fptostr | `1002ae1d` |
| `1002a505` | `1002a2dd` | `UNCONDITIONAL_CALL` | __cftoe2_l | `1002a2dd` |
| `1002a515` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002a532` | __cftoe |
| `1002abd9` | __cfltcvt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002a454` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a44c` | `8b ff` | `MOV EDI,EDI` |
| `1002a44e` | `55` | `PUSH EBP` |
| `1002a44f` | `8b ec` | `MOV EBP,ESP` |
| `1002a451` | `83 ec 2c` | `SUB ESP,0x2c` |
| `1002a454` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002a459` | `33 c5` | `XOR EAX,EBP` |
| `1002a45b` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002a45e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002a461` | `53` | `PUSH EBX` |
| `1002a462` | `56` | `PUSH ESI` |
| `1002a463` | `57` | `PUSH EDI` |
| `1002a464` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1002a467` | `6a 16` | `PUSH 0x16` |
| `1002a469` | `5e` | `POP ESI` |
| `1002a46a` | `56` | `PUSH ESI` |
| `1002a46b` | `8d 4d e4` | `LEA ECX,[EBP + -0x1c]` |
| `1002a46e` | `51` | `PUSH ECX` |
| `1002a46f` | `8d 4d d4` | `LEA ECX,[EBP + -0x2c]` |
| `1002a472` | `51` | `PUSH ECX` |
| `1002a473` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1002a476` | `ff 30` | `PUSH dword ptr [EAX]` |
| `1002a478` | `e8 1c 0b 00 00` | `CALL 0x1002af99` |
| `1002a47d` | `33 db` | `XOR EBX,EBX` |
| `1002a47f` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a482` | `3b fb` | `CMP EDI,EBX` |
| `1002a484` | `75 18` | `JNZ 0x1002a49e` |
| `1002a486` | `e8 7e ac fe ff` | `CALL 0x10015109` |
| `1002a48b` | `53` | `PUSH EBX` |
| `1002a48c` | `53` | `PUSH EBX` |
| `1002a48d` | `53` | `PUSH EBX` |
| `1002a48e` | `53` | `PUSH EBX` |
| `1002a48f` | `53` | `PUSH EBX` |
| `1002a490` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1002a492` | `e8 18 72 fe ff` | `CALL 0x100116af` |
| `1002a497` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a49a` | `8b c6` | `MOV EAX,ESI` |
| `1002a49c` | `eb 6f` | `JMP 0x1002a50d` |
| `1002a49e` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1002a4a1` | `3b c3` | `CMP EAX,EBX` |
| `1002a4a3` | `76 e1` | `JBE 0x1002a486` |
| `1002a4a5` | `8b 75 14` | `MOV ESI,dword ptr [EBP + 0x14]` |
| `1002a4a8` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1002a4ab` | `75 05` | `JNZ 0x1002a4b2` |
| `1002a4ad` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1002a4b0` | `eb 14` | `JMP 0x1002a4c6` |
| `1002a4b2` | `33 c9` | `XOR ECX,ECX` |
| `1002a4b4` | `83 7d d4 2d` | `CMP dword ptr [EBP + -0x2c],0x2d` |
| `1002a4b8` | `0f 94 c1` | `SETZ CL` |
| `1002a4bb` | `2b c1` | `SUB EAX,ECX` |
| `1002a4bd` | `33 c9` | `XOR ECX,ECX` |
| `1002a4bf` | `3b f3` | `CMP ESI,EBX` |
| `1002a4c1` | `0f 9f c1` | `SETG CL` |
| `1002a4c4` | `2b c1` | `SUB EAX,ECX` |
| `1002a4c6` | `8d 4d d4` | `LEA ECX,[EBP + -0x2c]` |
| `1002a4c9` | `51` | `PUSH ECX` |
| `1002a4ca` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `1002a4cd` | `51` | `PUSH ECX` |
| `1002a4ce` | `50` | `PUSH EAX` |
| `1002a4cf` | `33 c0` | `XOR EAX,EAX` |
| `1002a4d1` | `83 7d d4 2d` | `CMP dword ptr [EBP + -0x2c],0x2d` |
| `1002a4d5` | `0f 94 c0` | `SETZ AL` |
| `1002a4d8` | `33 c9` | `XOR ECX,ECX` |
| `1002a4da` | `3b f3` | `CMP ESI,EBX` |
| `1002a4dc` | `0f 9f c1` | `SETG CL` |
| `1002a4df` | `03 c7` | `ADD EAX,EDI` |
| `1002a4e1` | `03 c8` | `ADD ECX,EAX` |
| `1002a4e3` | `51` | `PUSH ECX` |
| `1002a4e4` | `e8 34 09 00 00` | `CALL 0x1002ae1d` |
| `1002a4e9` | `83 c4 10` | `ADD ESP,0x10` |
| `1002a4ec` | `3b c3` | `CMP EAX,EBX` |
| `1002a4ee` | `74 04` | `JZ 0x1002a4f4` |
| `1002a4f0` | `88 1f` | `MOV byte ptr [EDI],BL` |
| `1002a4f2` | `eb 19` | `JMP 0x1002a50d` |
| `1002a4f4` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002a4f7` | `8d 45 d4` | `LEA EAX,[EBP + -0x2c]` |
| `1002a4fa` | `53` | `PUSH EBX` |
| `1002a4fb` | `50` | `PUSH EAX` |
| `1002a4fc` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002a4ff` | `8b c7` | `MOV EAX,EDI` |
| `1002a501` | `56` | `PUSH ESI` |
| `1002a502` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002a505` | `e8 d3 fd ff ff` | `CALL 0x1002a2dd` |
| `1002a50a` | `83 c4 18` | `ADD ESP,0x18` |
| `1002a50d` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002a510` | `5f` | `POP EDI` |
| `1002a511` | `5e` | `POP ESI` |
| `1002a512` | `33 cd` | `XOR ECX,EBP` |
| `1002a514` | `5b` | `POP EBX` |
| `1002a515` | `e8 b1 67 fe ff` | `CALL 0x10010ccb` |
| `1002a51a` | `c9` | `LEAVE` |
| `1002a51b` | `c3` | `RET` |
