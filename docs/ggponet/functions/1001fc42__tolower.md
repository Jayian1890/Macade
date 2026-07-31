# 1001fc42 `_tolower`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001fc42 |
| `name` | _tolower |
| `namespace` | Global |
| `signature` | int __cdecl _tolower(int _C) |
| `size_bytes` | 44 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _tolower |

## Decompiled C

```c

/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 2008 Release */

int __cdecl _tolower(int _C)

{
  if (DAT_100393a0 == 0) {
    if (_C - 0x41U < 0x1a) {
      return _C + 0x20;
    }
  }
  else {
    _C = __tolower_l(_C,(_locale_t)0x0);
  }
  return _C;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001fc65` | `1001fb2d` | `UNCONDITIONAL_CALL` | __tolower_l | `1001fb2d` |

## Callers

| From | Function |
| --- | --- |
| `1002a146` | __forcdecpt_l |
| `1002a163` | __forcdecpt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001fc47` | `100393a0` | `READ` | DAT_100393a0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001fc42` | `8b ff` | `MOV EDI,EDI` |
| `1001fc44` | `55` | `PUSH EBP` |
| `1001fc45` | `8b ec` | `MOV EBP,ESP` |
| `1001fc47` | `83 3d a0 93 03 10 00` | `CMP dword ptr [0x100393a0],0x0` |
| `1001fc4e` | `75 10` | `JNZ 0x1001fc60` |
| `1001fc50` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001fc53` | `8d 48 bf` | `LEA ECX,[EAX + -0x41]` |
| `1001fc56` | `83 f9 19` | `CMP ECX,0x19` |
| `1001fc59` | `77 11` | `JA 0x1001fc6c` |
| `1001fc5b` | `83 c0 20` | `ADD EAX,0x20` |
| `1001fc5e` | `5d` | `POP EBP` |
| `1001fc5f` | `c3` | `RET` |
| `1001fc60` | `6a 00` | `PUSH 0x0` |
| `1001fc62` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001fc65` | `e8 c3 fe ff ff` | `CALL 0x1001fb2d` |
| `1001fc6a` | `59` | `POP ECX` |
| `1001fc6b` | `59` | `POP ECX` |
| `1001fc6c` | `5d` | `POP EBP` |
| `1001fc6d` | `c3` | `RET` |
