# 100118d1 `std::bad_alloc::bad_alloc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100118d1 |
| `name` | std::bad_alloc::bad_alloc |
| `namespace` | std::bad_alloc (GhidraClass) |
| `signature` | undefined __thiscall bad_alloc(bad_alloc * this) |
| `size_bytes` | 27 |
| `stack_frame_size` | 4 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0bad_alloc@std@@QAE@XZ, std::bad_alloc::bad_alloc |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::bad_alloc::bad_alloc(void)
   
   Library: Visual Studio 2008 Release */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this)

{
  exception::exception((exception *)this,&PTR_s_bad_allocation_1003747c,1);
  *(undefined ***)this = vftable;
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100118dd` | `10011183` | `UNCONDITIONAL_CALL` | std::exception::exception | `10011183` |

## Callers

| From | Function |
| --- | --- |
| `10011929` | FUN_100118ec |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100118d6` | `1003747c` | `DATA` | PTR_s_bad_allocation_1003747c |
| `100118e2` | `1002ef5c` | `DATA` | std::bad_alloc::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100118d1` | `8b ff` | `MOV EDI,EDI` |
| `100118d3` | `56` | `PUSH ESI` |
| `100118d4` | `6a 01` | `PUSH 0x1` |
| `100118d6` | `68 7c 74 03 10` | `PUSH 0x1003747c` |
| `100118db` | `8b f1` | `MOV ESI,ECX` |
| `100118dd` | `e8 a1 f8 ff ff` | `CALL 0x10011183` |
| `100118e2` | `c7 06 5c ef 02 10` | `MOV dword ptr [ESI],0x1002ef5c` |
| `100118e8` | `8b c6` | `MOV EAX,ESI` |
| `100118ea` | `5e` | `POP ESI` |
| `100118eb` | `c3` | `RET` |
