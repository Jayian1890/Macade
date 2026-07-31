# 0077c31c `___tmainCRTStartup`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 0077c31c |
| `name` | ___tmainCRTStartup |
| `namespace` | Global |
| `signature` | undefined ___tmainCRTStartup(void) |
| `size_bytes` | 310 |
| `stack_frame_size` | 112 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___tmainCRTStartup |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x0077c383) */
/* Library Function - Single Match
    ___tmainCRTStartup
   
   Library: Visual Studio 2008 Release */

int ___tmainCRTStartup(void)

{
  int iVar1;
  undefined4 uVar2;
  _STARTUPINFOA local_6c;
  int local_24;
  int local_20;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x77c328;
  local_8 = 0;
  GetStartupInfoA(&local_6c);
  local_8 = 0xfffffffe;
  local_20 = 0;
  iVar1 = __heap_init();
  if (iVar1 == 0) {
    fast_error_exit(0x1c);
  }
  iVar1 = __mtinit();
  if (iVar1 == 0) {
    fast_error_exit(0x10);
  }
  __RTC_Initialize();
  local_8 = 1;
  iVar1 = __ioinit();
  if (iVar1 < 0) {
    __amsg_exit(0x1b);
  }
  DAT_00b1d010 = GetCommandLineA();
  DAT_009aa818 = ___crtGetEnvironmentStringsA();
  iVar1 = __setargv();
  if (iVar1 < 0) {
    __amsg_exit(8);
  }
  iVar1 = __setenvp();
  if (iVar1 < 0) {
    __amsg_exit(9);
  }
  iVar1 = __cinit(1);
  if (iVar1 != 0) {
    __amsg_exit(iVar1);
  }
  uVar2 = __wincmdln();
  if (((byte)local_6c.dwFlags & 1) == 0) {
    local_6c.wShowWindow = 10;
  }
  local_24 = FUN_00457270(0x400000,0,uVar2,local_6c.wShowWindow);
  if (local_20 != 0) {
    __cexit();
    return local_24;
  }
                    /* WARNING: Subroutine does not return */
  _exit(local_24);
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `0077c323` | `00782584` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `00782584` |
| `0077c331` | `EXTERNAL:000000da` | `COMPUTED_CALL` | KERNEL32.DLL::GetStartupInfoA | `` |
| `0077c38a` | `007818df` | `UNCONDITIONAL_CALL` | __heap_init | `007818df` |
| `0077c396` | `0077c2f3` | `UNCONDITIONAL_CALL` | fast_error_exit | `0077c2f3` |
| `0077c39c` | `007868ff` | `UNCONDITIONAL_CALL` | __mtinit | `007868ff` |
| `0077c3a7` | `0077c2f3` | `UNCONDITIONAL_CALL` | fast_error_exit | `0077c2f3` |
| `0077c3ad` | `0078a015` | `UNCONDITIONAL_CALL` | __RTC_Initialize | `0078a015` |
| `0077c3b5` | `007838d4` | `UNCONDITIONAL_CALL` | __ioinit | `007838d4` |
| `0077c3c0` | `0077f2cb` | `UNCONDITIONAL_CALL` | __amsg_exit | `0077f2cb` |
| `0077c3c6` | `EXTERNAL:000000c7` | `COMPUTED_CALL` | KERNEL32.DLL::GetCommandLineA | `` |
| `0077c3d1` | `00789ede` | `UNCONDITIONAL_CALL` | ___crtGetEnvironmentStringsA | `00789ede` |
| `0077c3db` | `00789e23` | `UNCONDITIONAL_CALL` | __setargv | `00789e23` |
| `0077c3e6` | `0077f2cb` | `UNCONDITIONAL_CALL` | __amsg_exit | `0077f2cb` |
| `0077c3ec` | `00789bab` | `UNCONDITIONAL_CALL` | __setenvp | `00789bab` |
| `0077c3f7` | `0077f2cb` | `UNCONDITIONAL_CALL` | __amsg_exit | `0077f2cb` |
| `0077c3fe` | `0077f38a` | `UNCONDITIONAL_CALL` | __cinit | `0077f38a` |
| `0077c409` | `0077f2cb` | `UNCONDITIONAL_CALL` | __amsg_exit | `0077f2cb` |
| `0077c40f` | `00789b4c` | `UNCONDITIONAL_CALL` | __wincmdln | `00789b4c` |
| `0077c42a` | `00457270` | `UNCONDITIONAL_CALL` | FUN_00457270 | `00457270` |
| `0077c438` | `0077f53b` | `UNCONDITIONAL_CALL` | _exit | `0077f53b` |
| `0077c43d` | `0077f567` | `UNCONDITIONAL_CALL` | __cexit | `0077f567` |
| `0077c494` | `007825c9` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `007825c9` |

## Callers

| From | Function |
| --- | --- |
| `0077c49f` | entry |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `0077c31e` | `0081b888` | `DATA` | DAT_0081b888 |
| `0077c331` | `007991a4` | `READ` | PTR_GetStartupInfoA_007991a4 |
| `0077c342` | `00400000` | `READ` | IMAGE_DOS_HEADER_00400000 |
| `0077c34b` | `0040003c` | `READ` | IMAGE_DOS_HEADER_00400000.e_lfanew |
| `0077c350` | `00400150` | `READ` | IMAGE_NT_HEADERS32_00400150 |
| `0077c361` | `00400168` | `READ` | IMAGE_NT_HEADERS32_00400150.OptionalHeader.Magic |
| `0077c36a` | `004001c4` | `READ` | IMAGE_NT_HEADERS32_00400150.OptionalHeader.NumberOfRvaAndSizes |
| `0077c375` | `00400238` | `READ` | IMAGE_NT_HEADERS32_00400150.OptionalHeader.DataDirectory[14].VirtualAddress |
| `0077c3c6` | `00799158` | `READ` | PTR_GetCommandLineA_00799158 |
| `0077c3cc` | `00b1d010` | `WRITE` | DAT_00b1d010 |
| `0077c3d6` | `009aa818` | `WRITE` | DAT_009aa818 |
| `0077c425` | `00400000` | `DATA` | IMAGE_DOS_HEADER_00400000 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `0077c31c` | `6a 58` | `PUSH 0x58` |
| `0077c31e` | `68 88 b8 81 00` | `PUSH 0x81b888` |
| `0077c323` | `e8 5c 62 00 00` | `CALL 0x00782584` |
| `0077c328` | `33 f6` | `XOR ESI,ESI` |
| `0077c32a` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `0077c32d` | `8d 45 98` | `LEA EAX,[EBP + -0x68]` |
| `0077c330` | `50` | `PUSH EAX` |
| `0077c331` | `ff 15 a4 91 79 00` | `CALL dword ptr [0x007991a4]` |
| `0077c337` | `6a fe` | `PUSH -0x2` |
| `0077c339` | `5f` | `POP EDI` |
| `0077c33a` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `0077c33d` | `b8 4d 5a 00 00` | `MOV EAX,0x5a4d` |
| `0077c342` | `66 39 05 00 00 40 00` | `CMP word ptr [0x00400000],AX` |
| `0077c349` | `75 38` | `JNZ 0x0077c383` |
| `0077c34b` | `a1 3c 00 40 00` | `MOV EAX,[0x0040003c]` |
| `0077c350` | `81 b8 00 00 40 00 50 45 00 00` | `CMP dword ptr [EAX + 0x400000],0x4550` |
| `0077c35a` | `75 27` | `JNZ 0x0077c383` |
| `0077c35c` | `b9 0b 01 00 00` | `MOV ECX,0x10b` |
| `0077c361` | `66 39 88 18 00 40 00` | `CMP word ptr [EAX + 0x400018],CX` |
| `0077c368` | `75 19` | `JNZ 0x0077c383` |
| `0077c36a` | `83 b8 74 00 40 00 0e` | `CMP dword ptr [EAX + 0x400074],0xe` |
| `0077c371` | `76 10` | `JBE 0x0077c383` |
| `0077c373` | `33 c9` | `XOR ECX,ECX` |
| `0077c375` | `39 b0 e8 00 40 00` | `CMP dword ptr [EAX + 0x4000e8],ESI` |
| `0077c37b` | `0f 95 c1` | `SETNZ CL` |
| `0077c37e` | `89 4d e4` | `MOV dword ptr [EBP + -0x1c],ECX` |
| `0077c381` | `eb 03` | `JMP 0x0077c386` |
| `0077c383` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `0077c386` | `33 db` | `XOR EBX,EBX` |
| `0077c388` | `43` | `INC EBX` |
| `0077c389` | `53` | `PUSH EBX` |
| `0077c38a` | `e8 50 55 00 00` | `CALL 0x007818df` |
| `0077c38f` | `59` | `POP ECX` |
| `0077c390` | `85 c0` | `TEST EAX,EAX` |
| `0077c392` | `75 08` | `JNZ 0x0077c39c` |
| `0077c394` | `6a 1c` | `PUSH 0x1c` |
| `0077c396` | `e8 58 ff ff ff` | `CALL 0x0077c2f3` |
| `0077c39b` | `59` | `POP ECX` |
| `0077c39c` | `e8 5e a5 00 00` | `CALL 0x007868ff` |
| `0077c3a1` | `85 c0` | `TEST EAX,EAX` |
| `0077c3a3` | `75 08` | `JNZ 0x0077c3ad` |
| `0077c3a5` | `6a 10` | `PUSH 0x10` |
| `0077c3a7` | `e8 47 ff ff ff` | `CALL 0x0077c2f3` |
| `0077c3ac` | `59` | `POP ECX` |
| `0077c3ad` | `e8 63 dc 00 00` | `CALL 0x0078a015` |
| `0077c3b2` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `0077c3b5` | `e8 1a 75 00 00` | `CALL 0x007838d4` |
| `0077c3ba` | `85 c0` | `TEST EAX,EAX` |
| `0077c3bc` | `7d 08` | `JGE 0x0077c3c6` |
| `0077c3be` | `6a 1b` | `PUSH 0x1b` |
| `0077c3c0` | `e8 06 2f 00 00` | `CALL 0x0077f2cb` |
| `0077c3c5` | `59` | `POP ECX` |
| `0077c3c6` | `ff 15 58 91 79 00` | `CALL dword ptr [0x00799158]` |
| `0077c3cc` | `a3 10 d0 b1 00` | `MOV [0x00b1d010],EAX` |
| `0077c3d1` | `e8 08 db 00 00` | `CALL 0x00789ede` |
| `0077c3d6` | `a3 18 a8 9a 00` | `MOV [0x009aa818],EAX` |
| `0077c3db` | `e8 43 da 00 00` | `CALL 0x00789e23` |
| `0077c3e0` | `85 c0` | `TEST EAX,EAX` |
| `0077c3e2` | `7d 08` | `JGE 0x0077c3ec` |
| `0077c3e4` | `6a 08` | `PUSH 0x8` |
| `0077c3e6` | `e8 e0 2e 00 00` | `CALL 0x0077f2cb` |
| `0077c3eb` | `59` | `POP ECX` |
| `0077c3ec` | `e8 ba d7 00 00` | `CALL 0x00789bab` |
| `0077c3f1` | `85 c0` | `TEST EAX,EAX` |
| `0077c3f3` | `7d 08` | `JGE 0x0077c3fd` |
| `0077c3f5` | `6a 09` | `PUSH 0x9` |
| `0077c3f7` | `e8 cf 2e 00 00` | `CALL 0x0077f2cb` |
| `0077c3fc` | `59` | `POP ECX` |
| `0077c3fd` | `53` | `PUSH EBX` |
| `0077c3fe` | `e8 87 2f 00 00` | `CALL 0x0077f38a` |
| `0077c403` | `59` | `POP ECX` |
| `0077c404` | `3b c6` | `CMP EAX,ESI` |
| `0077c406` | `74 07` | `JZ 0x0077c40f` |
| `0077c408` | `50` | `PUSH EAX` |
| `0077c409` | `e8 bd 2e 00 00` | `CALL 0x0077f2cb` |
| `0077c40e` | `59` | `POP ECX` |
| `0077c40f` | `e8 38 d7 00 00` | `CALL 0x00789b4c` |
| `0077c414` | `84 5d c4` | `TEST byte ptr [EBP + -0x3c],BL` |
| `0077c417` | `74 06` | `JZ 0x0077c41f` |
| `0077c419` | `0f b7 4d c8` | `MOVZX ECX,word ptr [EBP + -0x38]` |
| `0077c41d` | `eb 03` | `JMP 0x0077c422` |
| `0077c41f` | `6a 0a` | `PUSH 0xa` |
| `0077c421` | `59` | `POP ECX` |
| `0077c422` | `51` | `PUSH ECX` |
| `0077c423` | `50` | `PUSH EAX` |
| `0077c424` | `56` | `PUSH ESI` |
| `0077c425` | `68 00 00 40 00` | `PUSH 0x400000` |
| `0077c42a` | `e8 41 ae cd ff` | `CALL 0x00457270` |
| `0077c42f` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `0077c432` | `39 75 e4` | `CMP dword ptr [EBP + -0x1c],ESI` |
| `0077c435` | `75 06` | `JNZ 0x0077c43d` |
| `0077c437` | `50` | `PUSH EAX` |
| `0077c438` | `e8 fe 30 00 00` | `CALL 0x0077f53b` |
| `0077c43d` | `e8 25 31 00 00` | `CALL 0x0077f567` |
| `0077c442` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `0077c445` | `eb 35` | `JMP 0x0077c47c` |
| `0077c47c` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `0077c47f` | `eb 13` | `JMP 0x0077c494` |
| `0077c494` | `e8 30 61 00 00` | `CALL 0x007825c9` |
| `0077c499` | `c3` | `RET` |
