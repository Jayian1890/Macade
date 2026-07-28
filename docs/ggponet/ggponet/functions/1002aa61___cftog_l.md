# 1002aa61 `__cftog_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002aa61 |
| `name` | __cftog_l |
| `namespace` | Global |
| `signature` | undefined __cftog_l(void) |
| `size_bytes` | 250 |
| `stack_frame_size` | 56 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cftog_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cftog_l
   
   Library: Visual Studio 2008 Release */

void __cftog_l(double *param_1,undefined1 *param_2,int param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

{
  char *pcVar1;
  int *piVar2;
  errno_t eVar3;
  size_t _SizeInBytes;
  char *pcVar4;
  _strflt local_34;
  int local_24;
  char local_20 [24];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  __fltout2((_CRT_DOUBLE)*param_1,&local_34,local_20,0x16);
  if ((param_2 == (undefined1 *)0x0) || (param_3 == 0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    __invalid_parameter(0,0,0,0,0);
  }
  else {
    local_24 = local_34.decpt + -1;
    if (param_3 == -1) {
      _SizeInBytes = 0xffffffff;
    }
    else {
      _SizeInBytes = param_3 - (uint)(local_34.sign == 0x2d);
    }
    eVar3 = __fptostr(param_2 + (local_34.sign == 0x2d),_SizeInBytes,param_4,&local_34);
    if (eVar3 == 0) {
      local_34.decpt = local_34.decpt + -1;
      if ((local_34.decpt < -4) || (param_4 <= local_34.decpt)) {
        __cftoe2_l(param_3,param_4,param_5,&local_34,1,param_6);
      }
      else {
        pcVar1 = param_2 + (local_34.sign == 0x2d);
        if (local_24 < local_34.decpt) {
          do {
            pcVar4 = pcVar1;
            pcVar1 = pcVar4 + 1;
          } while (*pcVar4 != '\0');
          pcVar4[-1] = '\0';
        }
        __cftof2_l(param_3,param_4,1,param_6);
      }
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
| `1002aa8d` | `1002af99` | `UNCONDITIONAL_CALL` | __fltout2 | `1002af99` |
| `1002aa9b` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002aaa7` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002aae4` | `1002ae1d` | `UNCONDITIONAL_CALL` | __fptostr | `1002ae1d` |
| `1002ab26` | `1002a8af` | `UNCONDITIONAL_CALL` | __cftof2_l | `1002a8af` |
| `1002ab44` | `1002a2dd` | `UNCONDITIONAL_CALL` | __cftoe2_l | `1002a2dd` |
| `1002ab54` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002aba7` | __cfltcvt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002aa69` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002aa61` | `8b ff` | `MOV EDI,EDI` |
| `1002aa63` | `55` | `PUSH EBP` |
| `1002aa64` | `8b ec` | `MOV EBP,ESP` |
| `1002aa66` | `83 ec 30` | `SUB ESP,0x30` |
| `1002aa69` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002aa6e` | `33 c5` | `XOR EAX,EBP` |
| `1002aa70` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002aa73` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002aa76` | `53` | `PUSH EBX` |
| `1002aa77` | `56` | `PUSH ESI` |
| `1002aa78` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1002aa7b` | `57` | `PUSH EDI` |
| `1002aa7c` | `6a 16` | `PUSH 0x16` |
| `1002aa7e` | `5f` | `POP EDI` |
| `1002aa7f` | `57` | `PUSH EDI` |
| `1002aa80` | `8d 4d e4` | `LEA ECX,[EBP + -0x1c]` |
| `1002aa83` | `51` | `PUSH ECX` |
| `1002aa84` | `8d 4d d0` | `LEA ECX,[EBP + -0x30]` |
| `1002aa87` | `51` | `PUSH ECX` |
| `1002aa88` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1002aa8b` | `ff 30` | `PUSH dword ptr [EAX]` |
| `1002aa8d` | `e8 07 05 00 00` | `CALL 0x1002af99` |
| `1002aa92` | `33 db` | `XOR EBX,EBX` |
| `1002aa94` | `83 c4 14` | `ADD ESP,0x14` |
| `1002aa97` | `3b f3` | `CMP ESI,EBX` |
| `1002aa99` | `75 1b` | `JNZ 0x1002aab6` |
| `1002aa9b` | `e8 69 a6 fe ff` | `CALL 0x10015109` |
| `1002aaa0` | `53` | `PUSH EBX` |
| `1002aaa1` | `53` | `PUSH EBX` |
| `1002aaa2` | `53` | `PUSH EBX` |
| `1002aaa3` | `53` | `PUSH EBX` |
| `1002aaa4` | `53` | `PUSH EBX` |
| `1002aaa5` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `1002aaa7` | `e8 03 6c fe ff` | `CALL 0x100116af` |
| `1002aaac` | `83 c4 14` | `ADD ESP,0x14` |
| `1002aaaf` | `8b c7` | `MOV EAX,EDI` |
| `1002aab1` | `e9 96 00 00 00` | `JMP 0x1002ab4c` |
| `1002aab6` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1002aab9` | `3b cb` | `CMP ECX,EBX` |
| `1002aabb` | `76 de` | `JBE 0x1002aa9b` |
| `1002aabd` | `8b 45 d4` | `MOV EAX,dword ptr [EBP + -0x2c]` |
| `1002aac0` | `48` | `DEC EAX` |
| `1002aac1` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1002aac4` | `33 c0` | `XOR EAX,EAX` |
| `1002aac6` | `83 7d d0 2d` | `CMP dword ptr [EBP + -0x30],0x2d` |
| `1002aaca` | `0f 94 c0` | `SETZ AL` |
| `1002aacd` | `8d 3c 30` | `LEA EDI,[EAX + ESI*0x1]` |
| `1002aad0` | `83 f9 ff` | `CMP ECX,-0x1` |
| `1002aad3` | `75 04` | `JNZ 0x1002aad9` |
| `1002aad5` | `0b c9` | `OR ECX,ECX` |
| `1002aad7` | `eb 02` | `JMP 0x1002aadb` |
| `1002aad9` | `2b c8` | `SUB ECX,EAX` |
| `1002aadb` | `8d 45 d0` | `LEA EAX,[EBP + -0x30]` |
| `1002aade` | `50` | `PUSH EAX` |
| `1002aadf` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002aae2` | `51` | `PUSH ECX` |
| `1002aae3` | `57` | `PUSH EDI` |
| `1002aae4` | `e8 34 03 00 00` | `CALL 0x1002ae1d` |
| `1002aae9` | `83 c4 10` | `ADD ESP,0x10` |
| `1002aaec` | `3b c3` | `CMP EAX,EBX` |
| `1002aaee` | `74 04` | `JZ 0x1002aaf4` |
| `1002aaf0` | `88 1e` | `MOV byte ptr [ESI],BL` |
| `1002aaf2` | `eb 58` | `JMP 0x1002ab4c` |
| `1002aaf4` | `8b 45 d4` | `MOV EAX,dword ptr [EBP + -0x2c]` |
| `1002aaf7` | `48` | `DEC EAX` |
| `1002aaf8` | `39 45 e0` | `CMP dword ptr [EBP + -0x20],EAX` |
| `1002aafb` | `0f 9c c1` | `SETL CL` |
| `1002aafe` | `83 f8 fc` | `CMP EAX,-0x4` |
| `1002ab01` | `7c 2d` | `JL 0x1002ab30` |
| `1002ab03` | `3b 45 14` | `CMP EAX,dword ptr [EBP + 0x14]` |
| `1002ab06` | `7d 28` | `JGE 0x1002ab30` |
| `1002ab08` | `3a cb` | `CMP CL,BL` |
| `1002ab0a` | `74 0a` | `JZ 0x1002ab16` |
| `1002ab0c` | `8a 07` | `MOV AL,byte ptr [EDI]` |
| `1002ab0e` | `47` | `INC EDI` |
| `1002ab0f` | `84 c0` | `TEST AL,AL` |
| `1002ab11` | `75 f9` | `JNZ 0x1002ab0c` |
| `1002ab13` | `88 5f fe` | `MOV byte ptr [EDI + -0x2],BL` |
| `1002ab16` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002ab19` | `8d 45 d0` | `LEA EAX,[EBP + -0x30]` |
| `1002ab1c` | `6a 01` | `PUSH 0x1` |
| `1002ab1e` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002ab21` | `8b ce` | `MOV ECX,ESI` |
| `1002ab23` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002ab26` | `e8 84 fd ff ff` | `CALL 0x1002a8af` |
| `1002ab2b` | `83 c4 10` | `ADD ESP,0x10` |
| `1002ab2e` | `eb 1c` | `JMP 0x1002ab4c` |
| `1002ab30` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002ab33` | `8d 45 d0` | `LEA EAX,[EBP + -0x30]` |
| `1002ab36` | `6a 01` | `PUSH 0x1` |
| `1002ab38` | `50` | `PUSH EAX` |
| `1002ab39` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002ab3c` | `8b c6` | `MOV EAX,ESI` |
| `1002ab3e` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002ab41` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002ab44` | `e8 94 f7 ff ff` | `CALL 0x1002a2dd` |
| `1002ab49` | `83 c4 18` | `ADD ESP,0x18` |
| `1002ab4c` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002ab4f` | `5f` | `POP EDI` |
| `1002ab50` | `5e` | `POP ESI` |
| `1002ab51` | `33 cd` | `XOR ECX,EBP` |
| `1002ab53` | `5b` | `POP EBX` |
| `1002ab54` | `e8 72 61 fe ff` | `CALL 0x10010ccb` |
| `1002ab59` | `c9` | `LEAVE` |
| `1002ab5a` | `c3` | `RET` |
