# 10014b16 `TranslatorGuardHandler`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014b16 |
| `name` | TranslatorGuardHandler |
| `namespace` | Global |
| `signature` | _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(EHExceptionRecord * param_1, TranslatorGuardRN * param_2, void * param_3, void * param_4) |
| `size_bytes` | 154 |
| `stack_frame_size` | 28 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?TranslatorGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUTranslatorGuardRN@@PAX2@Z, TranslatorGuardHandler |

## Decompiled C

```c

/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(struct EHExceptionRecord *,struct
   TranslatorGuardRN *,void *,void *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

_EXCEPTION_DISPOSITION __cdecl
TranslatorGuardHandler
          (EHExceptionRecord *param_1,TranslatorGuardRN *param_2,void *param_3,void *param_4)

{
  _EXCEPTION_DISPOSITION _Var1;
  code *local_8;
  
  __security_check_cookie(*(uint *)(param_2 + 8) ^ (uint)param_2);
  if ((*(uint *)(param_1 + 4) & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0x10),param_3,0,*(undefined4 *)(param_2 + 0xc),
             *(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames((EHRegistrationNode *)param_2,param_1);
  }
  _CallSETranslator((EHExceptionRecord *)0x123,(EHRegistrationNode *)&local_8,(void *)0x0,
                    (void *)0x0,(_s_FuncInfo *)0x0,0,(EHRegistrationNode *)0x0);
                    /* WARNING: Could not recover jumptable at 0x10014bad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (*local_8)();
  return _Var1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014b27` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10014b6a` | `1001b7f1` | `UNCONDITIONAL_CALL` | ___InternalCxxFrameHandler | `1001b7f1` |
| `10014b81` | `10014982` | `UNCONDITIONAL_CALL` | _UnwindNestedFrames | `10014982` |
| `10014b99` | `10014a3f` | `UNCONDITIONAL_CALL` | _CallSETranslator | `10014a3f` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014b16` | `8b ff` | `MOV EDI,EDI` |
| `10014b18` | `55` | `PUSH EBP` |
| `10014b19` | `8b ec` | `MOV EBP,ESP` |
| `10014b1b` | `51` | `PUSH ECX` |
| `10014b1c` | `53` | `PUSH EBX` |
| `10014b1d` | `fc` | `CLD` |
| `10014b1e` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b21` | `8b 48 08` | `MOV ECX,dword ptr [EAX + 0x8]` |
| `10014b24` | `33 4d 0c` | `XOR ECX,dword ptr [EBP + 0xc]` |
| `10014b27` | `e8 9f c1 ff ff` | `CALL 0x10010ccb` |
| `10014b2c` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014b2f` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `10014b32` | `83 e0 66` | `AND EAX,0x66` |
| `10014b35` | `74 11` | `JZ 0x10014b48` |
| `10014b37` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b3a` | `c7 40 24 01 00 00 00` | `MOV dword ptr [EAX + 0x24],0x1` |
| `10014b41` | `33 c0` | `XOR EAX,EAX` |
| `10014b43` | `40` | `INC EAX` |
| `10014b44` | `eb 6c` | `JMP 0x10014bb2` |
| `10014b48` | `6a 01` | `PUSH 0x1` |
| `10014b4a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b4d` | `ff 70 18` | `PUSH dword ptr [EAX + 0x18]` |
| `10014b50` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b53` | `ff 70 14` | `PUSH dword ptr [EAX + 0x14]` |
| `10014b56` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b59` | `ff 70 0c` | `PUSH dword ptr [EAX + 0xc]` |
| `10014b5c` | `6a 00` | `PUSH 0x0` |
| `10014b5e` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10014b61` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b64` | `ff 70 10` | `PUSH dword ptr [EAX + 0x10]` |
| `10014b67` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10014b6a` | `e8 82 6c 00 00` | `CALL 0x1001b7f1` |
| `10014b6f` | `83 c4 20` | `ADD ESP,0x20` |
| `10014b72` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014b75` | `83 78 24 00` | `CMP dword ptr [EAX + 0x24],0x0` |
| `10014b79` | `75 0b` | `JNZ 0x10014b86` |
| `10014b7b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10014b7e` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10014b81` | `e8 fc fd ff ff` | `CALL 0x10014982` |
| `10014b86` | `6a 00` | `PUSH 0x0` |
| `10014b88` | `6a 00` | `PUSH 0x0` |
| `10014b8a` | `6a 00` | `PUSH 0x0` |
| `10014b8c` | `6a 00` | `PUSH 0x0` |
| `10014b8e` | `6a 00` | `PUSH 0x0` |
| `10014b90` | `8d 45 fc` | `LEA EAX,[EBP + -0x4]` |
| `10014b93` | `50` | `PUSH EAX` |
| `10014b94` | `68 23 01 00 00` | `PUSH 0x123` |
| `10014b99` | `e8 a1 fe ff ff` | `CALL 0x10014a3f` |
| `10014b9e` | `83 c4 1c` | `ADD ESP,0x1c` |
| `10014ba1` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10014ba4` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `10014ba7` | `8b 63 1c` | `MOV ESP,dword ptr [EBX + 0x1c]` |
| `10014baa` | `8b 6b 20` | `MOV EBP,dword ptr [EBX + 0x20]` |
| `10014bad` | `ff e0` | `JMP EAX` |
| `10014bb2` | `5b` | `POP EBX` |
| `10014bb3` | `c9` | `LEAVE` |
| `10014bb4` | `c3` | `RET` |
