# 10017ed5 `__unlock_file2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017ed5 |
| `name` | __unlock_file2 |
| `namespace` | Global |
| `signature` | void __cdecl __unlock_file2(int _Index, void * _File) |
| `size_bytes` | 47 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __unlock_file2 |

## Decompiled C

```c

/* Library Function - Single Match
    __unlock_file2
   
   Library: Visual Studio 2008 Release */

void __cdecl __unlock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    *(uint *)((int)_File + 0xc) = *(uint *)((int)_File + 0xc) & 0xffff7fff;
    FUN_10016129(_Index + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017ef0` | `10016129` | `UNCONDITIONAL_CALL` | FUN_10016129 | `10016129` |
| `10017efc` | `EXTERNAL:00000042` | `COMPUTED_CALL` | KERNEL32.DLL::LeaveCriticalSection | `` |

## Callers

| From | Function |
| --- | --- |
| `10018252` | __getstream |
| `100145e4` | FUN_100145db |
| `10012404` | FUN_100123f9 |
| `10012039` | FUN_1001202e |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017efc` | `1002e0c0` | `READ` | PTR_LeaveCriticalSection_1002e0c0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017ed5` | `8b ff` | `MOV EDI,EDI` |
| `10017ed7` | `55` | `PUSH EBP` |
| `10017ed8` | `8b ec` | `MOV EBP,ESP` |
| `10017eda` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10017edd` | `83 f9 14` | `CMP ECX,0x14` |
| `10017ee0` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10017ee3` | `7d 13` | `JGE 0x10017ef8` |
| `10017ee5` | `81 60 0c ff 7f ff ff` | `AND dword ptr [EAX + 0xc],0xffff7fff` |
| `10017eec` | `83 c1 10` | `ADD ECX,0x10` |
| `10017eef` | `51` | `PUSH ECX` |
| `10017ef0` | `e8 34 e2 ff ff` | `CALL 0x10016129` |
| `10017ef5` | `59` | `POP ECX` |
| `10017ef6` | `5d` | `POP EBP` |
| `10017ef7` | `c3` | `RET` |
| `10017ef8` | `83 c0 20` | `ADD EAX,0x20` |
| `10017efb` | `50` | `PUSH EAX` |
| `10017efc` | `ff 15 c0 e0 02 10` | `CALL dword ptr [0x1002e0c0]` |
| `10017f02` | `5d` | `POP EBP` |
| `10017f03` | `c3` | `RET` |
