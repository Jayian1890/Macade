# 1001dccd `__unlock_fhandle`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001dccd |
| `name` | __unlock_fhandle |
| `namespace` | Global |
| `signature` | void __cdecl __unlock_fhandle(int _Filehandle) |
| `size_bytes` | 39 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __unlock_fhandle |

## Decompiled C

```c

/* Library Function - Single Match
    __unlock_fhandle
   
   Library: Visual Studio 2008 Release */

void __cdecl __unlock_fhandle(int _Filehandle)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_13439540)[_Filehandle >> 5] + 0xc + (_Filehandle & 0x1fU) * 0x40));
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001dcec` | `EXTERNAL:00000042` | `COMPUTED_CALL` | KERNEL32.DLL::LeaveCriticalSection | `` |

## Callers

| From | Function |
| --- | --- |
| `1001a3e7` | FUN_1001a3e4 |
| `1001bac3` | FUN_1001bac0 |
| `1001d587` | FUN_1001d560 |
| `1001a4c8` | FUN_1001a4c5 |
| `10018c3e` | FUN_10018c3b |
| `10018dd9` | FUN_10018dd6 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001dcdd` | `13439540` | `DATA` | DAT_13439540 |
| `1001dcec` | `1002e0c0` | `READ` | PTR_LeaveCriticalSection_1002e0c0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001dccd` | `8b ff` | `MOV EDI,EDI` |
| `1001dccf` | `55` | `PUSH EBP` |
| `1001dcd0` | `8b ec` | `MOV EBP,ESP` |
| `1001dcd2` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001dcd5` | `8b c8` | `MOV ECX,EAX` |
| `1001dcd7` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001dcda` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001dcdd` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001dce4` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001dce7` | `8d 44 01 0c` | `LEA EAX,[ECX + EAX*0x1 + 0xc]` |
| `1001dceb` | `50` | `PUSH EAX` |
| `1001dcec` | `ff 15 c0 e0 02 10` | `CALL dword ptr [0x1002e0c0]` |
| `1001dcf2` | `5d` | `POP EBP` |
| `1001dcf3` | `c3` | `RET` |
