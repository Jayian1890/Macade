# 10014a0c `CatchGuardHandler`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014a0c |
| `name` | CatchGuardHandler |
| `namespace` | Global |
| `signature` | _EXCEPTION_DISPOSITION __cdecl CatchGuardHandler(EHExceptionRecord * param_1, CatchGuardRN * param_2, void * param_3, void * param_4) |
| `size_bytes` | 51 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?CatchGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUCatchGuardRN@@PAX2@Z, CatchGuardHandler |

## Decompiled C

```c

/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl CatchGuardHandler(struct EHExceptionRecord *,struct
   CatchGuardRN *,void *,void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_EXCEPTION_DISPOSITION __cdecl
CatchGuardHandler(EHExceptionRecord *param_1,CatchGuardRN *param_2,void *param_3,void *param_4)

{
  _EXCEPTION_DISPOSITION _Var1;
  
  __security_check_cookie(*(uint *)(param_2 + 8) ^ (uint)param_2);
  _Var1 = ___InternalCxxFrameHandler
                    (param_1,*(undefined4 *)(param_2 + 0x10),param_3,0,
                     *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x14),param_2,0);
  return _Var1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014a1b` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10014a34` | `1001b7f1` | `UNCONDITIONAL_CALL` | ___InternalCxxFrameHandler | `1001b7f1` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014a0c` | `8b ff` | `MOV EDI,EDI` |
| `10014a0e` | `55` | `PUSH EBP` |
| `10014a0f` | `8b ec` | `MOV EBP,ESP` |
| `10014a11` | `56` | `PUSH ESI` |
| `10014a12` | `fc` | `CLD` |
| `10014a13` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10014a16` | `8b 4e 08` | `MOV ECX,dword ptr [ESI + 0x8]` |
| `10014a19` | `33 ce` | `XOR ECX,ESI` |
| `10014a1b` | `e8 ab c2 ff ff` | `CALL 0x10010ccb` |
| `10014a20` | `6a 00` | `PUSH 0x0` |
| `10014a22` | `56` | `PUSH ESI` |
| `10014a23` | `ff 76 14` | `PUSH dword ptr [ESI + 0x14]` |
| `10014a26` | `ff 76 0c` | `PUSH dword ptr [ESI + 0xc]` |
| `10014a29` | `6a 00` | `PUSH 0x0` |
| `10014a2b` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10014a2e` | `ff 76 10` | `PUSH dword ptr [ESI + 0x10]` |
| `10014a31` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10014a34` | `e8 b8 6d 00 00` | `CALL 0x1001b7f1` |
| `10014a39` | `83 c4 20` | `ADD ESP,0x20` |
| `10014a3c` | `5e` | `POP ESI` |
| `10014a3d` | `5d` | `POP EBP` |
| `10014a3e` | `c3` | `RET` |
