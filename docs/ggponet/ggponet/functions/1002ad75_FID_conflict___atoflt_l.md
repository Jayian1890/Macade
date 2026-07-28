# 1002ad75 `FID_conflict:__atoflt_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002ad75 |
| `name` | FID_conflict:__atoflt_l |
| `namespace` | Global |
| `signature` | int __cdecl FID_conflict:__atoflt_l(_CRT_FLOAT * _Result, char * _Str, _locale_t _Locale) |
| `size_bytes` | 168 |
| `stack_frame_size` | 60 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | FID_conflict:__atoflt_l, __atodbl_l, __atoflt_l |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    __atodbl_l
    __atoflt_l
   
   Library: Visual Studio 2008 Release */

int __cdecl FID_conflict___atoflt_l(_CRT_FLOAT *_Result,char *_Str,_locale_t _Locale)

{
  INTRNCVT_STATUS IVar1;
  int iVar2;
  char *local_2c;
  localeinfo_struct local_28;
  int local_20;
  char local_1c;
  uint local_18;
  _LDBL12 local_14;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_28,_Locale);
  local_18 = ___strgtold12_l(&local_14,&local_2c,_Str,0,0,0,0,&local_28);
  IVar1 = FID_conflict___ld12tod(&local_14,(_CRT_DOUBLE *)_Result);
  if ((local_18 & 3) == 0) {
    if (IVar1 == INTRNCVT_OVERFLOW) {
LAB_1002adce:
      if (local_1c != '\0') {
        *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
      }
      goto LAB_1002ae0e;
    }
    if (IVar1 != INTRNCVT_UNDERFLOW) {
LAB_1002ae00:
      if (local_1c != '\0') {
        *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
      }
      goto LAB_1002ae0e;
    }
  }
  else if ((local_18 & 1) == 0) {
    if ((local_18 & 2) == 0) goto LAB_1002ae00;
    goto LAB_1002adce;
  }
  if (local_1c != '\0') {
    *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
  }
LAB_1002ae0e:
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002ad96` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1002adae` | `1002bc23` | `UNCONDITIONAL_CALL` | ___strgtold12_l | `1002bc23` |
| `1002adbb` | `1002b6df` | `UNCONDITIONAL_CALL` | FID_conflict:__ld12tod | `1002b6df` |
| `1002ae16` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002a26c` | __fassign_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002ad7d` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002ad75` | `8b ff` | `MOV EDI,EDI` |
| `1002ad77` | `55` | `PUSH EBP` |
| `1002ad78` | `8b ec` | `MOV EBP,ESP` |
| `1002ad7a` | `83 ec 28` | `SUB ESP,0x28` |
| `1002ad7d` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002ad82` | `33 c5` | `XOR EAX,EBP` |
| `1002ad84` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002ad87` | `53` | `PUSH EBX` |
| `1002ad88` | `56` | `PUSH ESI` |
| `1002ad89` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1002ad8c` | `57` | `PUSH EDI` |
| `1002ad8d` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002ad90` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1002ad93` | `8d 4d dc` | `LEA ECX,[EBP + -0x24]` |
| `1002ad96` | `e8 1b a5 fe ff` | `CALL 0x100152b6` |
| `1002ad9b` | `8d 45 dc` | `LEA EAX,[EBP + -0x24]` |
| `1002ad9e` | `50` | `PUSH EAX` |
| `1002ad9f` | `33 db` | `XOR EBX,EBX` |
| `1002ada1` | `53` | `PUSH EBX` |
| `1002ada2` | `53` | `PUSH EBX` |
| `1002ada3` | `53` | `PUSH EBX` |
| `1002ada4` | `53` | `PUSH EBX` |
| `1002ada5` | `57` | `PUSH EDI` |
| `1002ada6` | `8d 45 d8` | `LEA EAX,[EBP + -0x28]` |
| `1002ada9` | `50` | `PUSH EAX` |
| `1002adaa` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1002adad` | `50` | `PUSH EAX` |
| `1002adae` | `e8 70 0e 00 00` | `CALL 0x1002bc23` |
| `1002adb3` | `89 45 ec` | `MOV dword ptr [EBP + -0x14],EAX` |
| `1002adb6` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1002adb9` | `56` | `PUSH ESI` |
| `1002adba` | `50` | `PUSH EAX` |
| `1002adbb` | `e8 1f 09 00 00` | `CALL 0x1002b6df` |
| `1002adc0` | `83 c4 28` | `ADD ESP,0x28` |
| `1002adc3` | `f6 45 ec 03` | `TEST byte ptr [EBP + -0x14],0x3` |
| `1002adc7` | `75 2b` | `JNZ 0x1002adf4` |
| `1002adc9` | `83 f8 01` | `CMP EAX,0x1` |
| `1002adcc` | `75 11` | `JNZ 0x1002addf` |
| `1002adce` | `38 5d e8` | `CMP byte ptr [EBP + -0x18],BL` |
| `1002add1` | `74 07` | `JZ 0x1002adda` |
| `1002add3` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002add6` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002adda` | `6a 03` | `PUSH 0x3` |
| `1002addc` | `58` | `POP EAX` |
| `1002addd` | `eb 2f` | `JMP 0x1002ae0e` |
| `1002addf` | `83 f8 02` | `CMP EAX,0x2` |
| `1002ade2` | `75 1c` | `JNZ 0x1002ae00` |
| `1002ade4` | `38 5d e8` | `CMP byte ptr [EBP + -0x18],BL` |
| `1002ade7` | `74 07` | `JZ 0x1002adf0` |
| `1002ade9` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002adec` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002adf0` | `6a 04` | `PUSH 0x4` |
| `1002adf2` | `eb e8` | `JMP 0x1002addc` |
| `1002adf4` | `f6 45 ec 01` | `TEST byte ptr [EBP + -0x14],0x1` |
| `1002adf8` | `75 ea` | `JNZ 0x1002ade4` |
| `1002adfa` | `f6 45 ec 02` | `TEST byte ptr [EBP + -0x14],0x2` |
| `1002adfe` | `75 ce` | `JNZ 0x1002adce` |
| `1002ae00` | `38 5d e8` | `CMP byte ptr [EBP + -0x18],BL` |
| `1002ae03` | `74 07` | `JZ 0x1002ae0c` |
| `1002ae05` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002ae08` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002ae0c` | `33 c0` | `XOR EAX,EAX` |
| `1002ae0e` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002ae11` | `5f` | `POP EDI` |
| `1002ae12` | `5e` | `POP ESI` |
| `1002ae13` | `33 cd` | `XOR ECX,EBP` |
| `1002ae15` | `5b` | `POP EBX` |
| `1002ae16` | `e8 b0 5e fe ff` | `CALL 0x10010ccb` |
| `1002ae1b` | `c9` | `LEAVE` |
| `1002ae1c` | `c3` | `RET` |
