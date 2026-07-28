# 1001f7bc `___ansicp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f7bc |
| `name` | ___ansicp |
| `namespace` | Global |
| `signature` | undefined ___ansicp(void) |
| `size_bytes` | 73 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___ansicp |

## Decompiled C

```c

/* Library Function - Single Match
    ___ansicp
   
   Library: Visual Studio 2008 Release */

void ___ansicp(LCID param_1)

{
  int iVar1;
  CHAR local_10 [6];
  undefined1 local_a;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_a = 0;
  iVar1 = GetLocaleInfoA(param_1,0x1004,local_10,6);
  if (iVar1 != 0) {
    _atol(local_10);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f7e0` | `EXTERNAL:00000065` | `COMPUTED_CALL` | KERNEL32.DLL::GetLocaleInfoA | `` |
| `1001f7f3` | `10011a4e` | `UNCONDITIONAL_CALL` | _atol | `10011a4e` |
| `1001f7fe` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001e17f` | __crtCompareStringA_stat |
| `1001eeaf` | __crtGetStringTypeA_stat |
| `1001ebd0` | __crtLCMapStringA_stat |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f7c4` | `10037490` | `READ` | DAT_10037490 |
| `1001f7e0` | `1002e14c` | `READ` | PTR_GetLocaleInfoA_1002e14c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f7bc` | `8b ff` | `MOV EDI,EDI` |
| `1001f7be` | `55` | `PUSH EBP` |
| `1001f7bf` | `8b ec` | `MOV EBP,ESP` |
| `1001f7c1` | `83 ec 0c` | `SUB ESP,0xc` |
| `1001f7c4` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001f7c9` | `33 c5` | `XOR EAX,EBP` |
| `1001f7cb` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001f7ce` | `6a 06` | `PUSH 0x6` |
| `1001f7d0` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `1001f7d3` | `50` | `PUSH EAX` |
| `1001f7d4` | `68 04 10 00 00` | `PUSH 0x1004` |
| `1001f7d9` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f7dc` | `c6 45 fa 00` | `MOV byte ptr [EBP + -0x6],0x0` |
| `1001f7e0` | `ff 15 4c e1 02 10` | `CALL dword ptr [0x1002e14c]` |
| `1001f7e6` | `85 c0` | `TEST EAX,EAX` |
| `1001f7e8` | `75 05` | `JNZ 0x1001f7ef` |
| `1001f7ea` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001f7ed` | `eb 0a` | `JMP 0x1001f7f9` |
| `1001f7ef` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `1001f7f2` | `50` | `PUSH EAX` |
| `1001f7f3` | `e8 56 22 ff ff` | `CALL 0x10011a4e` |
| `1001f7f8` | `59` | `POP ECX` |
| `1001f7f9` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001f7fc` | `33 cd` | `XOR ECX,EBP` |
| `1001f7fe` | `e8 c8 14 ff ff` | `CALL 0x10010ccb` |
| `1001f803` | `c9` | `LEAVE` |
| `1001f804` | `c3` | `RET` |
