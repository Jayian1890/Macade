# 1001fcd2 `KERNEL32.DLL::RtlUnwind`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001fcd2 |
| `name` | KERNEL32.DLL::RtlUnwind |
| `namespace` | KERNEL32.DLL |
| `signature` | void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue) |
| `size_bytes` | 6 |
| `stack_frame_size` | 20 |
| `calling_convention` | __stdcall |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x1001fcd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100149a8` | _UnwindNestedFrames |
| `1001843a` | _EH4_GlobalUnwind |
| `1001d98b` | __global_unwind2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001fcd2` | `ff 25 ac e0 02 10` | `JMP dword ptr [0x1002e0ac]` |
