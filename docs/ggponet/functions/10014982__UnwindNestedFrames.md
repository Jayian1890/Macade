# 10014982 `_UnwindNestedFrames`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014982 |
| `name` | _UnwindNestedFrames |
| `namespace` | Global |
| `signature` | void __stdcall _UnwindNestedFrames(EHRegistrationNode * param_1, EHExceptionRecord * param_2) |
| `size_bytes` | 84 |
| `stack_frame_size` | 24 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | ?_UnwindNestedFrames@@YGXPAUEHRegistrationNode@@PAUEHExceptionRecord@@@Z, _UnwindNestedFrames |

## Decompiled C

```c

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 2008 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x100149ad,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100149a8` | `1001fcd2` | `UNCONDITIONAL_CALL` | KERNEL32.DLL::RtlUnwind | `1001fcd2` |

## Callers

| From | Function |
| --- | --- |
| `1001b76c` | FindHandler |
| `1001b355` | CatchIt |
| `10014b81` | TranslatorGuardHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001498c` | `ffdff000` | `READ` | ExceptionList |
| `100149bc` | `ffdff000` | `READ` | ExceptionList |
| `100149c8` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014982` | `8b ff` | `MOV EDI,EDI` |
| `10014984` | `55` | `PUSH EBP` |
| `10014985` | `8b ec` | `MOV EBP,ESP` |
| `10014987` | `51` | `PUSH ECX` |
| `10014988` | `51` | `PUSH ECX` |
| `10014989` | `53` | `PUSH EBX` |
| `1001498a` | `56` | `PUSH ESI` |
| `1001498b` | `57` | `PUSH EDI` |
| `1001498c` | `64 8b 35 00 00 00 00` | `MOV ESI,dword ptr FS:[0x0]` |
| `10014993` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `10014996` | `c7 45 f8 ad 49 01 10` | `MOV dword ptr [EBP + -0x8],0x100149ad` |
| `1001499d` | `6a 00` | `PUSH 0x0` |
| `1001499f` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `100149a2` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `100149a5` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100149a8` | `e8 25 b3 00 00` | `CALL 0x1001fcd2` |
| `100149ad` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `100149b0` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `100149b3` | `83 e0 fd` | `AND EAX,0xfffffffd` |
| `100149b6` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `100149b9` | `89 41 04` | `MOV dword ptr [ECX + 0x4],EAX` |
| `100149bc` | `64 8b 3d 00 00 00 00` | `MOV EDI,dword ptr FS:[0x0]` |
| `100149c3` | `8b 5d fc` | `MOV EBX,dword ptr [EBP + -0x4]` |
| `100149c6` | `89 3b` | `MOV dword ptr [EBX],EDI` |
| `100149c8` | `64 89 1d 00 00 00 00` | `MOV dword ptr FS:[0x0],EBX` |
| `100149cf` | `5f` | `POP EDI` |
| `100149d0` | `5e` | `POP ESI` |
| `100149d1` | `5b` | `POP EBX` |
| `100149d2` | `c9` | `LEAVE` |
| `100149d3` | `c2 08 00` | `RET 0x8` |
