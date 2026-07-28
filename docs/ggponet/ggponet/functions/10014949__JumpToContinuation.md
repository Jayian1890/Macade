# 10014949 `_JumpToContinuation`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014949 |
| `name` | _JumpToContinuation |
| `namespace` | Global |
| `signature` | void __stdcall _JumpToContinuation(void * param_1, EHRegistrationNode * param_2) |
| `size_bytes` | 45 |
| `stack_frame_size` | 20 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | ?_JumpToContinuation@@YGXPAXPAUEHRegistrationNode@@@Z, _JumpToContinuation |

## Decompiled C

```c

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x10014974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001b392` | CatchIt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10014959` | `ffdff000` | `READ` | ExceptionList |
| `10014962` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014949` | `8b ff` | `MOV EDI,EDI` |
| `1001494b` | `55` | `PUSH EBP` |
| `1001494c` | `8b ec` | `MOV EBP,ESP` |
| `1001494e` | `51` | `PUSH ECX` |
| `1001494f` | `53` | `PUSH EBX` |
| `10014950` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014953` | `83 c0 0c` | `ADD EAX,0xc` |
| `10014956` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10014959` | `64 8b 1d 00 00 00 00` | `MOV EBX,dword ptr FS:[0x0]` |
| `10014960` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `10014962` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014968` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001496b` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `1001496e` | `8b 6d fc` | `MOV EBP,dword ptr [EBP + -0x4]` |
| `10014971` | `8b 63 fc` | `MOV ESP,dword ptr [EBX + -0x4]` |
| `10014974` | `ff e0` | `JMP EAX` |
