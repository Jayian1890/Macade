# 10011890 `type_info::`scalar_deleting_destructor'`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011890 |
| `name` | type_info::`scalar_deleting_destructor' |
| `namespace` | type_info (GhidraClass) |
| `signature` | void * __thiscall `scalar_deleting_destructor'(type_info * this, uint param_1) |
| `size_bytes` | 33 |
| `stack_frame_size` | 8 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??_Gtype_info@@UAEPAXI@Z, type_info::`scalar_deleting_destructor' |

## Decompiled C

```c

/* Library Function - Single Match
    public: virtual void * __thiscall type_info::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

void * __thiscall type_info::_scalar_deleting_destructor_(type_info *this,uint param_1)

{
  ~type_info(this);
  if ((param_1 & 1) != 0) {
    FUN_100117f8(this);
  }
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011898` | `10011880` | `UNCONDITIONAL_CALL` | type_info::~type_info | `10011880` |
| `100118a4` | `100117f8` | `UNCONDITIONAL_CALL` | FUN_100117f8 | `100117f8` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011890` | `8b ff` | `MOV EDI,EDI` |
| `10011892` | `55` | `PUSH EBP` |
| `10011893` | `8b ec` | `MOV EBP,ESP` |
| `10011895` | `56` | `PUSH ESI` |
| `10011896` | `8b f1` | `MOV ESI,ECX` |
| `10011898` | `e8 e3 ff ff ff` | `CALL 0x10011880` |
| `1001189d` | `f6 45 08 01` | `TEST byte ptr [EBP + 0x8],0x1` |
| `100118a1` | `74 07` | `JZ 0x100118aa` |
| `100118a3` | `56` | `PUSH ESI` |
| `100118a4` | `e8 4f ff ff ff` | `CALL 0x100117f8` |
| `100118a9` | `59` | `POP ECX` |
| `100118aa` | `8b c6` | `MOV EAX,ESI` |
| `100118ac` | `5e` | `POP ESI` |
| `100118ad` | `5d` | `POP EBP` |
| `100118ae` | `c2 04 00` | `RET 0x4` |
