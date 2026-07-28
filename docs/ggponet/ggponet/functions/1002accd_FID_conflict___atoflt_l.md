# 1002accd `FID_conflict:__atoflt_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002accd |
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
LAB_1002ad26:
      if (local_1c != '\0') {
        *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
      }
      goto LAB_1002ad66;
    }
    if (IVar1 != INTRNCVT_UNDERFLOW) {
LAB_1002ad58:
      if (local_1c != '\0') {
        *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
      }
      goto LAB_1002ad66;
    }
  }
  else if ((local_18 & 1) == 0) {
    if ((local_18 & 2) == 0) goto LAB_1002ad58;
    goto LAB_1002ad26;
  }
  if (local_1c != '\0') {
    *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
  }
LAB_1002ad66:
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002acee` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1002ad06` | `1002bc23` | `UNCONDITIONAL_CALL` | ___strgtold12_l | `1002bc23` |
| `1002ad13` | `1002b19b` | `UNCONDITIONAL_CALL` | FID_conflict:__ld12tod | `1002b19b` |
| `1002ad6e` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002a253` | __fassign_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002acd5` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002accd` | `8b ff` | `MOV EDI,EDI` |
| `1002accf` | `55` | `PUSH EBP` |
| `1002acd0` | `8b ec` | `MOV EBP,ESP` |
| `1002acd2` | `83 ec 28` | `SUB ESP,0x28` |
| `1002acd5` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002acda` | `33 c5` | `XOR EAX,EBP` |
| `1002acdc` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002acdf` | `53` | `PUSH EBX` |
| `1002ace0` | `56` | `PUSH ESI` |
| `1002ace1` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1002ace4` | `57` | `PUSH EDI` |
| `1002ace5` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002ace8` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1002aceb` | `8d 4d dc` | `LEA ECX,[EBP + -0x24]` |
| `1002acee` | `e8 c3 a5 fe ff` | `CALL 0x100152b6` |
| `1002acf3` | `8d 45 dc` | `LEA EAX,[EBP + -0x24]` |
| `1002acf6` | `50` | `PUSH EAX` |
| `1002acf7` | `33 db` | `XOR EBX,EBX` |
| `1002acf9` | `53` | `PUSH EBX` |
| `1002acfa` | `53` | `PUSH EBX` |
| `1002acfb` | `53` | `PUSH EBX` |
| `1002acfc` | `53` | `PUSH EBX` |
| `1002acfd` | `57` | `PUSH EDI` |
| `1002acfe` | `8d 45 d8` | `LEA EAX,[EBP + -0x28]` |
| `1002ad01` | `50` | `PUSH EAX` |
| `1002ad02` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1002ad05` | `50` | `PUSH EAX` |
| `1002ad06` | `e8 18 0f 00 00` | `CALL 0x1002bc23` |
| `1002ad0b` | `89 45 ec` | `MOV dword ptr [EBP + -0x14],EAX` |
| `1002ad0e` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1002ad11` | `56` | `PUSH ESI` |
| `1002ad12` | `50` | `PUSH EAX` |
| `1002ad13` | `e8 83 04 00 00` | `CALL 0x1002b19b` |
| `1002ad18` | `83 c4 28` | `ADD ESP,0x28` |
| `1002ad1b` | `f6 45 ec 03` | `TEST byte ptr [EBP + -0x14],0x3` |
| `1002ad1f` | `75 2b` | `JNZ 0x1002ad4c` |
| `1002ad21` | `83 f8 01` | `CMP EAX,0x1` |
| `1002ad24` | `75 11` | `JNZ 0x1002ad37` |
| `1002ad26` | `38 5d e8` | `CMP byte ptr [EBP + -0x18],BL` |
| `1002ad29` | `74 07` | `JZ 0x1002ad32` |
| `1002ad2b` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002ad2e` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002ad32` | `6a 03` | `PUSH 0x3` |
| `1002ad34` | `58` | `POP EAX` |
| `1002ad35` | `eb 2f` | `JMP 0x1002ad66` |
| `1002ad37` | `83 f8 02` | `CMP EAX,0x2` |
| `1002ad3a` | `75 1c` | `JNZ 0x1002ad58` |
| `1002ad3c` | `38 5d e8` | `CMP byte ptr [EBP + -0x18],BL` |
| `1002ad3f` | `74 07` | `JZ 0x1002ad48` |
| `1002ad41` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002ad44` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002ad48` | `6a 04` | `PUSH 0x4` |
| `1002ad4a` | `eb e8` | `JMP 0x1002ad34` |
| `1002ad4c` | `f6 45 ec 01` | `TEST byte ptr [EBP + -0x14],0x1` |
| `1002ad50` | `75 ea` | `JNZ 0x1002ad3c` |
| `1002ad52` | `f6 45 ec 02` | `TEST byte ptr [EBP + -0x14],0x2` |
| `1002ad56` | `75 ce` | `JNZ 0x1002ad26` |
| `1002ad58` | `38 5d e8` | `CMP byte ptr [EBP + -0x18],BL` |
| `1002ad5b` | `74 07` | `JZ 0x1002ad64` |
| `1002ad5d` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002ad60` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002ad64` | `33 c0` | `XOR EAX,EAX` |
| `1002ad66` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002ad69` | `5f` | `POP EDI` |
| `1002ad6a` | `5e` | `POP ESI` |
| `1002ad6b` | `33 cd` | `XOR ECX,EBP` |
| `1002ad6d` | `5b` | `POP EBX` |
| `1002ad6e` | `e8 58 5f fe ff` | `CALL 0x10010ccb` |
| `1002ad73` | `c9` | `LEAVE` |
| `1002ad74` | `c3` | `RET` |
