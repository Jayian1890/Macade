# 1001497b `FID_conflict:_CallMemberFunction1`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001497b |
| `name` | FID_conflict:_CallMemberFunction1 |
| `namespace` | Global |
| `signature` | undefined FID_conflict:_CallMemberFunction1(void) |
| `size_bytes` | 7 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ?_CallMemberFunction1@@YGXPAX00@Z, ?_CallMemberFunction2@@YGXPAX00H@Z, FID_conflict:_CallMemberFunction1 |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,code *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x10014980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001ae6d` | ___DestructExceptionObject |
| `1001b2f2` | ___BuildCatchObject |
| `1001b30c` | ___BuildCatchObject |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001497b` | `58` | `POP EAX` |
| `1001497c` | `59` | `POP ECX` |
| `1001497d` | `87 04 24` | `XCHG dword ptr [ESP],EAX` |
| `10014980` | `ff e0` | `JMP EAX` |
