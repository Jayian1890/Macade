# 10012490 `___crtExitProcess`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012490 |
| `name` | ___crtExitProcess |
| `namespace` | Global |
| `signature` | void __cdecl ___crtExitProcess(int param_1) |
| `size_bytes` | 23 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtExitProcess |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtExitProcess
   
   Library: Visual Studio 2008 Release */

void __cdecl ___crtExitProcess(int param_1)

{
  ___crtCorExitProcess(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10012498` | `10012465` | `UNCONDITIONAL_CALL` | ___crtCorExitProcess | `10012465` |
| `100124a1` | `EXTERNAL:00000038` | `COMPUTED_CALL_TERMINATOR` | KERNEL32.DLL::ExitProcess | `` |

## Callers

| From | Function |
| --- | --- |
| `1001616d` | __mtinitlocknum |
| `10011352` | _malloc |
| `1001268f` | doexit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100124a1` | `1002e098` | `READ` | PTR_ExitProcess_1002e098 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012490` | `8b ff` | `MOV EDI,EDI` |
| `10012492` | `55` | `PUSH EBP` |
| `10012493` | `8b ec` | `MOV EBP,ESP` |
| `10012495` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10012498` | `e8 c8 ff ff ff` | `CALL 0x10012465` |
| `1001249d` | `59` | `POP ECX` |
| `1001249e` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100124a1` | `ff 15 98 e0 02 10` | `CALL dword ptr [0x1002e098]` |
