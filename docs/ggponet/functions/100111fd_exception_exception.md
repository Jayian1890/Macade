# 100111fd `exception::~exception`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100111fd |
| `name` | exception::~exception |
| `namespace` | exception (GhidraClass) |
| `signature` | void __thiscall ~exception(exception * this) |
| `size_bytes` | 22 |
| `stack_frame_size` | 4 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??1exception@@UAE@XZ, exception::~exception |

## Decompiled C

```c

/* Library Function - Single Match
    public: virtual __thiscall exception::~exception(void)
   
   Library: Visual Studio 2008 Release */

void __thiscall exception::~exception(exception *this)

{
  *(undefined ***)this = std::exception::vftable;
  if (*(int *)(this + 8) != 0) {
    _free(*(void **)(this + 4));
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001120c` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `1002d803` | Unwind@1002d800 |
| `10001043` | FUN_10001030 |
| `1000121e` | FID_conflict:~logic_error |
| `10011228` | FUN_10011220 |
| `1001ac55` | FUN_1001ac47 |
| `1002d9ba` |  |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10011201` | `1002efb4` | `DATA` | std::exception::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100111fd` | `83 79 08 00` | `CMP dword ptr [ECX + 0x8],0x0` |
| `10011201` | `c7 01 b4 ef 02 10` | `MOV dword ptr [ECX],0x1002efb4` |
| `10011207` | `74 09` | `JZ 0x10011212` |
| `10011209` | `ff 71 04` | `PUSH dword ptr [ECX + 0x4]` |
| `1001120c` | `e8 30 00 00 00` | `CALL 0x10011241` |
| `10011211` | `59` | `POP ECX` |
| `10011212` | `c3` | `RET` |
