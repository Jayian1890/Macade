# 10014d98 `___report_gsfailure`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014d98 |
| `name` | ___report_gsfailure |
| `namespace` | Global |
| `signature` | noreturn void __cdecl ___report_gsfailure(void) |
| `size_bytes` | 262 |
| `stack_frame_size` | 816 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___report_gsfailure |

## Decompiled C

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___report_gsfailure(void)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 unaff_retaddr;
  UINT uExitCode;
  undefined4 local_32c;
  undefined4 local_328;
  
  _DAT_10038ba0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10038ba4 = &stack0x00000004;
  _DAT_10038ae0 = 0x10001;
  _DAT_10038a88 = 0xc0000409;
  _DAT_10038a8c = 1;
  local_32c = DAT_10037490;
  local_328 = DAT_10037494;
  _DAT_10038a94 = unaff_retaddr;
  _DAT_10038b6c = in_GS;
  _DAT_10038b70 = in_FS;
  _DAT_10038b74 = in_ES;
  _DAT_10038b78 = in_DS;
  _DAT_10038b7c = unaff_EDI;
  _DAT_10038b80 = unaff_ESI;
  _DAT_10038b84 = unaff_EBX;
  _DAT_10038b88 = in_EDX;
  _DAT_10038b8c = in_ECX;
  _DAT_10038b90 = in_EAX;
  _DAT_10038b94 = unaff_EBP;
  DAT_10038b98 = unaff_retaddr;
  _DAT_10038b9c = in_CS;
  _DAT_10038ba8 = in_SS;
  DAT_10038ad8 = IsDebuggerPresent();
  FUN_10017107(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1002f024);
  if (DAT_10038ad8 == 0) {
    FUN_10017107(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014e53` | `EXTERNAL:00000035` | `COMPUTED_CALL` | KERNEL32.DLL::IsDebuggerPresent | `` |
| `10014e60` | `10017107` | `UNCONDITIONAL_CALL` | FUN_10017107 | `10017107` |
| `10014e68` | `EXTERNAL:00000034` | `COMPUTED_CALL` | KERNEL32.DLL::SetUnhandledExceptionFilter | `` |
| `10014e73` | `EXTERNAL:00000033` | `COMPUTED_CALL` | KERNEL32.DLL::UnhandledExceptionFilter | `` |
| `10014e84` | `10017107` | `UNCONDITIONAL_CALL` | FUN_10017107 | `10017107` |
| `10014e8f` | `EXTERNAL:00000032` | `COMPUTED_CALL` | KERNEL32.DLL::GetCurrentProcess | `` |
| `10014e96` | `EXTERNAL:00000031` | `COMPUTED_CALL` | KERNEL32.DLL::TerminateProcess | `` |

## Callers

| From | Function |
| --- | --- |
| `10010cd5` | __security_check_cookie |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10014da3` | `10038b90` | `WRITE` | DAT_10038b90 |
| `10014da8` | `10038b8c` | `WRITE` | DAT_10038b8c |
| `10014dae` | `10038b88` | `WRITE` | DAT_10038b88 |
| `10014db4` | `10038b84` | `WRITE` | DAT_10038b84 |
| `10014dba` | `10038b80` | `WRITE` | DAT_10038b80 |
| `10014dc0` | `10038b7c` | `WRITE` | DAT_10038b7c |
| `10014dc6` | `10038ba8` | `WRITE` | DAT_10038ba8 |
| `10014dcd` | `10038b9c` | `WRITE` | DAT_10038b9c |
| `10014dd4` | `10038b78` | `WRITE` | DAT_10038b78 |
| `10014ddb` | `10038b74` | `WRITE` | DAT_10038b74 |
| `10014de2` | `10038b70` | `WRITE` | DAT_10038b70 |
| `10014de9` | `10038b6c` | `WRITE` | DAT_10038b6c |
| `10014df1` | `10038ba0` | `WRITE` | DAT_10038ba0 |
| `10014dfa` | `10038b94` | `WRITE` | DAT_10038b94 |
| `10014e02` | `10038b98` | `WRITE` | DAT_10038b98 |
| `10014e0a` | `10038ba4` | `WRITE` | DAT_10038ba4 |
| `10014e15` | `10038ae0` | `WRITE` | DAT_10038ae0 |
| `10014e1f` | `10038b98` | `READ` | DAT_10038b98 |
| `10014e24` | `10038a94` | `WRITE` | DAT_10038a94 |
| `10014e29` | `10038a88` | `WRITE` | DAT_10038a88 |
| `10014e33` | `10038a8c` | `WRITE` | DAT_10038a8c |
| `10014e3d` | `10037490` | `READ` | DAT_10037490 |
| `10014e48` | `10037494` | `READ` | DAT_10037494 |
| `10014e53` | `1002e08c` | `READ` | PTR_IsDebuggerPresent_1002e08c |
| `10014e59` | `10038ad8` | `WRITE` | DAT_10038ad8 |
| `10014e68` | `1002e088` | `READ` | PTR_SetUnhandledExceptionFilter_1002e088 |
| `10014e6e` | `1002f024` | `DATA` | PTR_DAT_1002f024 |
| `10014e73` | `1002e084` | `READ` | PTR_UnhandledExceptionFilter_1002e084 |
| `10014e79` | `10038ad8` | `READ` | DAT_10038ad8 |
| `10014e8f` | `1002e080` | `READ` | PTR_GetCurrentProcess_1002e080 |
| `10014e96` | `1002e07c` | `READ` | PTR_TerminateProcess_1002e07c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014d98` | `8b ff` | `MOV EDI,EDI` |
| `10014d9a` | `55` | `PUSH EBP` |
| `10014d9b` | `8b ec` | `MOV EBP,ESP` |
| `10014d9d` | `81 ec 28 03 00 00` | `SUB ESP,0x328` |
| `10014da3` | `a3 90 8b 03 10` | `MOV [0x10038b90],EAX` |
| `10014da8` | `89 0d 8c 8b 03 10` | `MOV dword ptr [0x10038b8c],ECX` |
| `10014dae` | `89 15 88 8b 03 10` | `MOV dword ptr [0x10038b88],EDX` |
| `10014db4` | `89 1d 84 8b 03 10` | `MOV dword ptr [0x10038b84],EBX` |
| `10014dba` | `89 35 80 8b 03 10` | `MOV dword ptr [0x10038b80],ESI` |
| `10014dc0` | `89 3d 7c 8b 03 10` | `MOV dword ptr [0x10038b7c],EDI` |
| `10014dc6` | `66 8c 15 a8 8b 03 10` | `MOV word ptr [0x10038ba8],SS` |
| `10014dcd` | `66 8c 0d 9c 8b 03 10` | `MOV word ptr [0x10038b9c],CS` |
| `10014dd4` | `66 8c 1d 78 8b 03 10` | `MOV word ptr [0x10038b78],DS` |
| `10014ddb` | `66 8c 05 74 8b 03 10` | `MOV word ptr [0x10038b74],ES` |
| `10014de2` | `66 8c 25 70 8b 03 10` | `MOV word ptr [0x10038b70],FS` |
| `10014de9` | `66 8c 2d 6c 8b 03 10` | `MOV word ptr [0x10038b6c],GS` |
| `10014df0` | `9c` | `PUSHFD` |
| `10014df1` | `8f 05 a0 8b 03 10` | `POP dword ptr [0x10038ba0]` |
| `10014df7` | `8b 45 00` | `MOV EAX,dword ptr [EBP]` |
| `10014dfa` | `a3 94 8b 03 10` | `MOV [0x10038b94],EAX` |
| `10014dff` | `8b 45 04` | `MOV EAX,dword ptr [EBP + 0x4]` |
| `10014e02` | `a3 98 8b 03 10` | `MOV [0x10038b98],EAX` |
| `10014e07` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `10014e0a` | `a3 a4 8b 03 10` | `MOV [0x10038ba4],EAX` |
| `10014e0f` | `8b 85 e0 fc ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffce0]` |
| `10014e15` | `c7 05 e0 8a 03 10 01 00 01 00` | `MOV dword ptr [0x10038ae0],0x10001` |
| `10014e1f` | `a1 98 8b 03 10` | `MOV EAX,[0x10038b98]` |
| `10014e24` | `a3 94 8a 03 10` | `MOV [0x10038a94],EAX` |
| `10014e29` | `c7 05 88 8a 03 10 09 04 00 c0` | `MOV dword ptr [0x10038a88],0xc0000409` |
| `10014e33` | `c7 05 8c 8a 03 10 01 00 00 00` | `MOV dword ptr [0x10038a8c],0x1` |
| `10014e3d` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10014e42` | `89 85 d8 fc ff ff` | `MOV dword ptr [EBP + 0xfffffcd8],EAX` |
| `10014e48` | `a1 94 74 03 10` | `MOV EAX,[0x10037494]` |
| `10014e4d` | `89 85 dc fc ff ff` | `MOV dword ptr [EBP + 0xfffffcdc],EAX` |
| `10014e53` | `ff 15 8c e0 02 10` | `CALL dword ptr [0x1002e08c]` |
| `10014e59` | `a3 d8 8a 03 10` | `MOV [0x10038ad8],EAX` |
| `10014e5e` | `6a 01` | `PUSH 0x1` |
| `10014e60` | `e8 a2 22 00 00` | `CALL 0x10017107` |
| `10014e65` | `59` | `POP ECX` |
| `10014e66` | `6a 00` | `PUSH 0x0` |
| `10014e68` | `ff 15 88 e0 02 10` | `CALL dword ptr [0x1002e088]` |
| `10014e6e` | `68 24 f0 02 10` | `PUSH 0x1002f024` |
| `10014e73` | `ff 15 84 e0 02 10` | `CALL dword ptr [0x1002e084]` |
| `10014e79` | `83 3d d8 8a 03 10 00` | `CMP dword ptr [0x10038ad8],0x0` |
| `10014e80` | `75 08` | `JNZ 0x10014e8a` |
| `10014e82` | `6a 01` | `PUSH 0x1` |
| `10014e84` | `e8 7e 22 00 00` | `CALL 0x10017107` |
| `10014e89` | `59` | `POP ECX` |
| `10014e8a` | `68 09 04 00 c0` | `PUSH 0xc0000409` |
| `10014e8f` | `ff 15 80 e0 02 10` | `CALL dword ptr [0x1002e080]` |
| `10014e95` | `50` | `PUSH EAX` |
| `10014e96` | `ff 15 7c e0 02 10` | `CALL dword ptr [0x1002e07c]` |
| `10014e9c` | `c9` | `LEAVE` |
| `10014e9d` | `c3` | `RET` |
