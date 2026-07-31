# 10017e67 `__lock_file2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017e67 |
| `name` | __lock_file2 |
| `namespace` | Global |
| `signature` | void __cdecl __lock_file2(int _Index, void * _File) |
| `size_bytes` | 50 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __lock_file2 |

## Decompiled C

```c

/* Library Function - Single Match
    __lock_file2
   
   Library: Visual Studio 2008 Release */

void __cdecl __lock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    __lock(_Index + 0x10);
    *(uint *)((int)_File + 0xc) = *(uint *)((int)_File + 0xc) | 0x8000;
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017e78` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `10017e91` | `EXTERNAL:00000043` | `COMPUTED_CALL` | KERNEL32.DLL::EnterCriticalSection | `` |

## Callers

| From | Function |
| --- | --- |
| `1001823b` | __getstream |
| `1001457f` | flsall |
| `10012362` | _puts |
| `10011fd6` | _printf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017e91` | `1002e0c4` | `READ` | PTR_EnterCriticalSection_1002e0c4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017e67` | `8b ff` | `MOV EDI,EDI` |
| `10017e69` | `55` | `PUSH EBP` |
| `10017e6a` | `8b ec` | `MOV EBP,ESP` |
| `10017e6c` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10017e6f` | `83 f8 14` | `CMP EAX,0x14` |
| `10017e72` | `7d 16` | `JGE 0x10017e8a` |
| `10017e74` | `83 c0 10` | `ADD EAX,0x10` |
| `10017e77` | `50` | `PUSH EAX` |
| `10017e78` | `e8 86 e3 ff ff` | `CALL 0x10016203` |
| `10017e7d` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10017e80` | `81 48 0c 00 80 00 00` | `OR dword ptr [EAX + 0xc],0x8000` |
| `10017e87` | `59` | `POP ECX` |
| `10017e88` | `5d` | `POP EBP` |
| `10017e89` | `c3` | `RET` |
| `10017e8a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10017e8d` | `83 c0 20` | `ADD EAX,0x20` |
| `10017e90` | `50` | `PUSH EAX` |
| `10017e91` | `ff 15 c4 e0 02 10` | `CALL dword ptr [0x1002e0c4]` |
| `10017e97` | `5d` | `POP EBP` |
| `10017e98` | `c3` | `RET` |
