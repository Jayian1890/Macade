# 10011587 `__invoke_watson`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011587 |
| `name` | __invoke_watson |
| `namespace` | Global |
| `signature` | noreturn void __cdecl __invoke_watson(wchar_t * param_1, wchar_t * param_2, wchar_t * param_3, uint param_4, uintptr_t param_5) |
| `size_bytes` | 296 |
| `stack_frame_size` | 836 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __invoke_watson |

## Decompiled C

```c

/* Library Function - Single Match
    __invoke_watson
   
   Library: Visual Studio 2008 Release */

void __cdecl
__invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  uint uVar1;
  BOOL BVar2;
  LONG LVar3;
  HANDLE hProcess;
  UINT uExitCode;
  EXCEPTION_RECORD local_32c;
  _EXCEPTION_POINTERS local_2dc;
  undefined4 local_2d4;
  
  uVar1 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_32c.ExceptionCode = 0;
  _memset(&local_32c.ExceptionFlags,0,0x4c);
  local_2dc.ExceptionRecord = &local_32c;
  local_2dc.ContextRecord = (PCONTEXT)&local_2d4;
  local_2d4 = 0x10001;
  local_32c.ExceptionCode = 0xc0000417;
  local_32c.ExceptionFlags = 1;
  BVar2 = IsDebuggerPresent();
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar3 = UnhandledExceptionFilter(&local_2dc);
  if ((LVar3 == 0) && (BVar2 == 0)) {
    FUN_10017107();
  }
  uExitCode = 0xc0000417;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100115af` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `10011663` | `EXTERNAL:00000035` | `COMPUTED_CALL` | KERNEL32.DLL::IsDebuggerPresent | `` |
| `1001166d` | `EXTERNAL:00000034` | `COMPUTED_CALL` | KERNEL32.DLL::SetUnhandledExceptionFilter | `` |
| `1001167a` | `EXTERNAL:00000033` | `COMPUTED_CALL` | KERNEL32.DLL::UnhandledExceptionFilter | `` |
| `1001168a` | `10017107` | `UNCONDITIONAL_CALL` | FUN_10017107 | `10017107` |
| `10011695` | `EXTERNAL:00000032` | `COMPUTED_CALL` | KERNEL32.DLL::GetCurrentProcess | `` |
| `1001169c` | `EXTERNAL:00000031` | `COMPUTED_CALL` | KERNEL32.DLL::TerminateProcess | `` |
| `100116a8` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `10016f73` | __NMSG_WRITE |
| `10016fb7` | __NMSG_WRITE |
| `10016ffa` | __NMSG_WRITE |
| `1001701e` | __NMSG_WRITE |
| `10017043` | __NMSG_WRITE |
| `1001cdee` | __tsopen_nolock |
| `1001e5e9` | ___crtsetenv |
| `1001f9fb` | __strdup |
| `1001a68f` | __setenvp |
| `100116d0` | __invalid_parameter |
| `1002ac27` | __setdefaultprecision |
| `1002a3d1` | __cftoe2_l |
| `1002b00d` | __fltout2 |
| `1002c443` | $I10_OUTPUT |
| `1002c46f` | $I10_OUTPUT |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10011592` | `10037490` | `READ` | DAT_10037490 |
| `10011663` | `1002e08c` | `READ` | PTR_IsDebuggerPresent_1002e08c |
| `1001166d` | `1002e088` | `READ` | PTR_SetUnhandledExceptionFilter_1002e088 |
| `1001167a` | `1002e084` | `READ` | PTR_UnhandledExceptionFilter_1002e084 |
| `10011695` | `1002e080` | `READ` | PTR_GetCurrentProcess_1002e080 |
| `1001169c` | `1002e07c` | `READ` | PTR_TerminateProcess_1002e07c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011587` | `8b ff` | `MOV EDI,EDI` |
| `10011589` | `55` | `PUSH EBP` |
| `1001158a` | `8b ec` | `MOV EBP,ESP` |
| `1001158c` | `81 ec 28 03 00 00` | `SUB ESP,0x328` |
| `10011592` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10011597` | `33 c5` | `XOR EAX,EBP` |
| `10011599` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001159c` | `83 a5 d8 fc ff ff 00` | `AND dword ptr [EBP + 0xfffffcd8],0x0` |
| `100115a3` | `53` | `PUSH EBX` |
| `100115a4` | `6a 4c` | `PUSH 0x4c` |
| `100115a6` | `8d 85 dc fc ff ff` | `LEA EAX,[EBP + 0xfffffcdc]` |
| `100115ac` | `6a 00` | `PUSH 0x0` |
| `100115ae` | `50` | `PUSH EAX` |
| `100115af` | `e8 3c 01 00 00` | `CALL 0x100116f0` |
| `100115b4` | `8d 85 d8 fc ff ff` | `LEA EAX,[EBP + 0xfffffcd8]` |
| `100115ba` | `89 85 28 fd ff ff` | `MOV dword ptr [EBP + 0xfffffd28],EAX` |
| `100115c0` | `8d 85 30 fd ff ff` | `LEA EAX,[EBP + 0xfffffd30]` |
| `100115c6` | `83 c4 0c` | `ADD ESP,0xc` |
| `100115c9` | `89 85 2c fd ff ff` | `MOV dword ptr [EBP + 0xfffffd2c],EAX` |
| `100115cf` | `89 85 e0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde0],EAX` |
| `100115d5` | `89 8d dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],ECX` |
| `100115db` | `89 95 d8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd8],EDX` |
| `100115e1` | `89 9d d4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd4],EBX` |
| `100115e7` | `89 b5 d0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd0],ESI` |
| `100115ed` | `89 bd cc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdcc],EDI` |
| `100115f3` | `66 8c 95 f8 fd ff ff` | `MOV word ptr [EBP + 0xfffffdf8],SS` |
| `100115fa` | `66 8c 8d ec fd ff ff` | `MOV word ptr [EBP + 0xfffffdec],CS` |
| `10011601` | `66 8c 9d c8 fd ff ff` | `MOV word ptr [EBP + 0xfffffdc8],DS` |
| `10011608` | `66 8c 85 c4 fd ff ff` | `MOV word ptr [EBP + 0xfffffdc4],ES` |
| `1001160f` | `66 8c a5 c0 fd ff ff` | `MOV word ptr [EBP + 0xfffffdc0],FS` |
| `10011616` | `66 8c ad bc fd ff ff` | `MOV word ptr [EBP + 0xfffffdbc],GS` |
| `1001161d` | `9c` | `PUSHFD` |
| `1001161e` | `8f 85 f0 fd ff ff` | `POP dword ptr [EBP + 0xfffffdf0]` |
| `10011624` | `8b 45 04` | `MOV EAX,dword ptr [EBP + 0x4]` |
| `10011627` | `8d 4d 04` | `LEA ECX,[EBP + 0x4]` |
| `1001162a` | `c7 85 30 fd ff ff 01 00 01 00` | `MOV dword ptr [EBP + 0xfffffd30],0x10001` |
| `10011634` | `89 85 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],EAX` |
| `1001163a` | `89 8d f4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdf4],ECX` |
| `10011640` | `8b 49 fc` | `MOV ECX,dword ptr [ECX + -0x4]` |
| `10011643` | `89 8d e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],ECX` |
| `10011649` | `c7 85 d8 fc ff ff 17 04 00 c0` | `MOV dword ptr [EBP + 0xfffffcd8],0xc0000417` |
| `10011653` | `c7 85 dc fc ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffcdc],0x1` |
| `1001165d` | `89 85 e4 fc ff ff` | `MOV dword ptr [EBP + 0xfffffce4],EAX` |
| `10011663` | `ff 15 8c e0 02 10` | `CALL dword ptr [0x1002e08c]` |
| `10011669` | `6a 00` | `PUSH 0x0` |
| `1001166b` | `8b d8` | `MOV EBX,EAX` |
| `1001166d` | `ff 15 88 e0 02 10` | `CALL dword ptr [0x1002e088]` |
| `10011673` | `8d 85 28 fd ff ff` | `LEA EAX,[EBP + 0xfffffd28]` |
| `10011679` | `50` | `PUSH EAX` |
| `1001167a` | `ff 15 84 e0 02 10` | `CALL dword ptr [0x1002e084]` |
| `10011680` | `85 c0` | `TEST EAX,EAX` |
| `10011682` | `75 0c` | `JNZ 0x10011690` |
| `10011684` | `85 db` | `TEST EBX,EBX` |
| `10011686` | `75 08` | `JNZ 0x10011690` |
| `10011688` | `6a 02` | `PUSH 0x2` |
| `1001168a` | `e8 78 5a 00 00` | `CALL 0x10017107` |
| `1001168f` | `59` | `POP ECX` |
| `10011690` | `68 17 04 00 c0` | `PUSH 0xc0000417` |
| `10011695` | `ff 15 80 e0 02 10` | `CALL dword ptr [0x1002e080]` |
| `1001169b` | `50` | `PUSH EAX` |
| `1001169c` | `ff 15 7c e0 02 10` | `CALL dword ptr [0x1002e07c]` |
| `100116a2` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100116a5` | `33 cd` | `XOR ECX,EBP` |
| `100116a7` | `5b` | `POP EBX` |
| `100116a8` | `e8 1e f6 ff ff` | `CALL 0x10010ccb` |
| `100116ad` | `c9` | `LEAVE` |
| `100116ae` | `c3` | `RET` |
