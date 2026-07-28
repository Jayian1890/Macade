# 10014ccf `_CallCatchBlock2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014ccf |
| `name` | _CallCatchBlock2 |
| `namespace` | Global |
| `signature` | void * __cdecl _CallCatchBlock2(EHRegistrationNode * param_1, _s_FuncInfo * param_2, void * param_3, int param_4, ulong param_5) |
| `size_bytes` | 96 |
| `stack_frame_size` | 52 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?_CallCatchBlock2@@YAPAXPAUEHRegistrationNode@@PBU_s_FuncInfo@@PAXHK@Z, _CallCatchBlock2 |

## Decompiled C

```c

/* Library Function - Single Match
    void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void
   *,int,unsigned long)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void * __cdecl
_CallCatchBlock2(EHRegistrationNode *param_1,_s_FuncInfo *param_2,void *param_3,int param_4,
                ulong param_5)

{
  void *pvVar1;
  void *local_1c;
  code *local_18;
  uint local_14;
  _s_FuncInfo *local_10;
  EHRegistrationNode *local_c;
  int local_8;
  
  local_14 = DAT_10037490 ^ (uint)&local_1c;
  local_10 = param_2;
  local_8 = param_4 + 1;
  local_18 = CatchGuardHandler;
  local_c = param_1;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_1c;
  return pvVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014d1b` | `1001b8e0` | `UNCONDITIONAL_CALL` | __CallSettingFrame@12 | `1001b8e0` |

## Callers

| From | Function |
| --- | --- |
| `1001affd` | CallCatchBlock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10014cd7` | `10037490` | `READ` | DAT_10037490 |
| `10014cf5` | `10014a0c` | `DATA` | ?CatchGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUCatchGuardRN@@PAX2@Z, CatchGuardHandler |
| `10014d02` | `ffdff000` | `READ` | ExceptionList |
| `10014d0e` | `ffdff000` | `WRITE` | ExceptionList |
| `10014d25` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014ccf` | `8b ff` | `MOV EDI,EDI` |
| `10014cd1` | `55` | `PUSH EBP` |
| `10014cd2` | `8b ec` | `MOV EBP,ESP` |
| `10014cd4` | `83 ec 18` | `SUB ESP,0x18` |
| `10014cd7` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10014cdc` | `83 65 e8 00` | `AND dword ptr [EBP + -0x18],0x0` |
| `10014ce0` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `10014ce3` | `33 c1` | `XOR EAX,ECX` |
| `10014ce5` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10014ce8` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `10014ceb` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014cee` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10014cf1` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10014cf4` | `40` | `INC EAX` |
| `10014cf5` | `c7 45 ec 0c 4a 01 10` | `MOV dword ptr [EBP + -0x14],0x10014a0c` |
| `10014cfc` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10014cff` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10014d02` | `64 a1 00 00 00 00` | `MOV EAX,FS:[0x0]` |
| `10014d08` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `10014d0b` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `10014d0e` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014d14` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `10014d17` | `51` | `PUSH ECX` |
| `10014d18` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10014d1b` | `e8 c0 6b 00 00` | `CALL 0x1001b8e0` |
| `10014d20` | `8b c8` | `MOV ECX,EAX` |
| `10014d22` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `10014d25` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014d2b` | `8b c1` | `MOV EAX,ECX` |
| `10014d2d` | `c9` | `LEAVE` |
| `10014d2e` | `c3` | `RET` |
