# 100179ae `_abort`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100179ae |
| `name` | _abort |
| `namespace` | Global |
| `signature` | noreturn void __cdecl _abort(void) |
| `size_bytes` | 279 |
| `stack_frame_size` | 816 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _abort |

## Decompiled C

```c

/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 2008 Release */

void __cdecl _abort(void)

{
  code *pcVar1;
  _PHNDLR p_Var2;
  EXCEPTION_RECORD local_32c;
  _EXCEPTION_POINTERS local_2dc;
  undefined4 local_2d4;
  
  if (((byte)DAT_100377fc & 1) != 0) {
    __NMSG_WRITE(10);
  }
  p_Var2 = ___get_sigabrt();
  if (p_Var2 != (_PHNDLR)0x0) {
    _raise(0x16);
  }
  if (((byte)DAT_100377fc & 2) != 0) {
    local_2d4 = 0x10001;
    _memset(&local_32c,0,0x50);
    local_2dc.ExceptionRecord = &local_32c;
    local_2dc.ContextRecord = (PCONTEXT)&local_2d4;
    local_32c.ExceptionCode = 0x40000015;
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
    UnhandledExceptionFilter(&local_2dc);
  }
  __exit(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100179cf` | `10016eec` | `UNCONDITIONAL_CALL` | __NMSG_WRITE | `10016eec` |
| `100179d5` | `10019718` | `UNCONDITIONAL_CALL` | ___get_sigabrt | `10019718` |
| `100179e0` | `10019725` | `UNCONDITIONAL_CALL` | _raise | `10019725` |
| `10017a78` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `10017aaa` | `EXTERNAL:00000034` | `COMPUTED_CALL` | KERNEL32.DLL::SetUnhandledExceptionFilter | `` |
| `10017ab7` | `EXTERNAL:00000033` | `COMPUTED_CALL` | KERNEL32.DLL::UnhandledExceptionFilter | `` |
| `10017abf` | `100126c2` | `UNCONDITIONAL_CALL` | __exit | `100126c2` |

## Callers

| From | Function |
| --- | --- |
| `100194db` | terminate |
| `10011976` | __purecall |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100179b9` | `10037490` | `READ` | DAT_10037490 |
| `100179c3` | `100377fc` | `READ` | DAT_100377fc |
| `100179e6` | `100377fc` | `READ` | DAT_100377fc |
| `10017aaa` | `1002e088` | `READ` | PTR_SetUnhandledExceptionFilter_1002e088 |
| `10017ab7` | `1002e084` | `READ` | PTR_UnhandledExceptionFilter_1002e084 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100179ae` | `8b ff` | `MOV EDI,EDI` |
| `100179b0` | `55` | `PUSH EBP` |
| `100179b1` | `8b ec` | `MOV EBP,ESP` |
| `100179b3` | `81 ec 28 03 00 00` | `SUB ESP,0x328` |
| `100179b9` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `100179be` | `33 c5` | `XOR EAX,EBP` |
| `100179c0` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `100179c3` | `f6 05 fc 77 03 10 01` | `TEST byte ptr [0x100377fc],0x1` |
| `100179ca` | `56` | `PUSH ESI` |
| `100179cb` | `74 08` | `JZ 0x100179d5` |
| `100179cd` | `6a 0a` | `PUSH 0xa` |
| `100179cf` | `e8 18 f5 ff ff` | `CALL 0x10016eec` |
| `100179d4` | `59` | `POP ECX` |
| `100179d5` | `e8 3e 1d 00 00` | `CALL 0x10019718` |
| `100179da` | `85 c0` | `TEST EAX,EAX` |
| `100179dc` | `74 08` | `JZ 0x100179e6` |
| `100179de` | `6a 16` | `PUSH 0x16` |
| `100179e0` | `e8 40 1d 00 00` | `CALL 0x10019725` |
| `100179e5` | `59` | `POP ECX` |
| `100179e6` | `f6 05 fc 77 03 10 02` | `TEST byte ptr [0x100377fc],0x2` |
| `100179ed` | `0f 84 ca 00 00 00` | `JZ 0x10017abd` |
| `100179f3` | `89 85 e0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde0],EAX` |
| `100179f9` | `89 8d dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],ECX` |
| `100179ff` | `89 95 d8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd8],EDX` |
| `10017a05` | `89 9d d4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd4],EBX` |
| `10017a0b` | `89 b5 d0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd0],ESI` |
| `10017a11` | `89 bd cc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdcc],EDI` |
| `10017a17` | `66 8c 95 f8 fd ff ff` | `MOV word ptr [EBP + 0xfffffdf8],SS` |
| `10017a1e` | `66 8c 8d ec fd ff ff` | `MOV word ptr [EBP + 0xfffffdec],CS` |
| `10017a25` | `66 8c 9d c8 fd ff ff` | `MOV word ptr [EBP + 0xfffffdc8],DS` |
| `10017a2c` | `66 8c 85 c4 fd ff ff` | `MOV word ptr [EBP + 0xfffffdc4],ES` |
| `10017a33` | `66 8c a5 c0 fd ff ff` | `MOV word ptr [EBP + 0xfffffdc0],FS` |
| `10017a3a` | `66 8c ad bc fd ff ff` | `MOV word ptr [EBP + 0xfffffdbc],GS` |
| `10017a41` | `9c` | `PUSHFD` |
| `10017a42` | `8f 85 f0 fd ff ff` | `POP dword ptr [EBP + 0xfffffdf0]` |
| `10017a48` | `8b 75 04` | `MOV ESI,dword ptr [EBP + 0x4]` |
| `10017a4b` | `8d 45 04` | `LEA EAX,[EBP + 0x4]` |
| `10017a4e` | `89 85 f4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdf4],EAX` |
| `10017a54` | `c7 85 30 fd ff ff 01 00 01 00` | `MOV dword ptr [EBP + 0xfffffd30],0x10001` |
| `10017a5e` | `89 b5 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],ESI` |
| `10017a64` | `8b 40 fc` | `MOV EAX,dword ptr [EAX + -0x4]` |
| `10017a67` | `6a 50` | `PUSH 0x50` |
| `10017a69` | `89 85 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EAX` |
| `10017a6f` | `8d 85 d8 fc ff ff` | `LEA EAX,[EBP + 0xfffffcd8]` |
| `10017a75` | `6a 00` | `PUSH 0x0` |
| `10017a77` | `50` | `PUSH EAX` |
| `10017a78` | `e8 73 9c ff ff` | `CALL 0x100116f0` |
| `10017a7d` | `8d 85 d8 fc ff ff` | `LEA EAX,[EBP + 0xfffffcd8]` |
| `10017a83` | `83 c4 0c` | `ADD ESP,0xc` |
| `10017a86` | `89 85 28 fd ff ff` | `MOV dword ptr [EBP + 0xfffffd28],EAX` |
| `10017a8c` | `8d 85 30 fd ff ff` | `LEA EAX,[EBP + 0xfffffd30]` |
| `10017a92` | `6a 00` | `PUSH 0x0` |
| `10017a94` | `c7 85 d8 fc ff ff 15 00 00 40` | `MOV dword ptr [EBP + 0xfffffcd8],0x40000015` |
| `10017a9e` | `89 b5 e4 fc ff ff` | `MOV dword ptr [EBP + 0xfffffce4],ESI` |
| `10017aa4` | `89 85 2c fd ff ff` | `MOV dword ptr [EBP + 0xfffffd2c],EAX` |
| `10017aaa` | `ff 15 88 e0 02 10` | `CALL dword ptr [0x1002e088]` |
| `10017ab0` | `8d 85 28 fd ff ff` | `LEA EAX,[EBP + 0xfffffd28]` |
| `10017ab6` | `50` | `PUSH EAX` |
| `10017ab7` | `ff 15 84 e0 02 10` | `CALL dword ptr [0x1002e084]` |
| `10017abd` | `6a 03` | `PUSH 0x3` |
| `10017abf` | `e8 fe ab ff ff` | `CALL 0x100126c2` |
| `10017ac4` | `cc` | `INT3` |
