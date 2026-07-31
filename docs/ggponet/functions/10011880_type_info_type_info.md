# 10011880 `type_info::~type_info`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011880 |
| `name` | type_info::~type_info |
| `namespace` | type_info (GhidraClass) |
| `signature` | void __thiscall ~type_info(type_info * this) |
| `size_bytes` | 16 |
| `stack_frame_size` | 4 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??1type_info@@UAE@XZ, type_info::~type_info |

## Decompiled C

```c

/* Library Function - Single Match
    public: virtual __thiscall type_info::~type_info(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __thiscall type_info::~type_info(type_info *this)

{
  *(undefined ***)this = vftable;
  _Type_info_dtor(this);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011889` | `10017800` | `UNCONDITIONAL_CALL` | type_info::_Type_info_dtor | `10017800` |

## Callers

| From | Function |
| --- | --- |
| `10011898` | type_info::`scalar_deleting_destructor' |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10011883` | `1002efd4` | `DATA` | type_info::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011880` | `8b ff` | `MOV EDI,EDI` |
| `10011882` | `51` | `PUSH ECX` |
| `10011883` | `c7 01 d4 ef 02 10` | `MOV dword ptr [ECX],0x1002efd4` |
| `10011889` | `e8 72 5f 00 00` | `CALL 0x10017800` |
| `1001188e` | `59` | `POP ECX` |
| `1001188f` | `c3` | `RET` |
