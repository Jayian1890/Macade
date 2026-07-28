# 100118b1 `type_info::operator==`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100118b1 |
| `name` | type_info::operator== |
| `namespace` | type_info (GhidraClass) |
| `signature` | bool __thiscall operator==(type_info * this, type_info * param_1) |
| `size_bytes` | 32 |
| `stack_frame_size` | 8 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??8type_info@@QBE_NABV0@@Z, type_info::operator== |

## Decompiled C

```c

/* Library Function - Single Match
    public: bool __thiscall type_info::operator==(class type_info const &)const 
   
   Library: Visual Studio 2008 Release */

bool __thiscall type_info::operator==(type_info *this,type_info *param_1)

{
  int iVar1;
  
  iVar1 = _strcmp((char *)(param_1 + 9),(char *)(this + 9));
  return (bool)('\x01' - (iVar1 != 0));
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100118c1` | `10011770` | `UNCONDITIONAL_CALL` | _strcmp | `10011770` |

## Callers

| From | Function |
| --- | --- |
| `1001b5b8` | FindHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100118b1` | `8b ff` | `MOV EDI,EDI` |
| `100118b3` | `55` | `PUSH EBP` |
| `100118b4` | `8b ec` | `MOV EBP,ESP` |
| `100118b6` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100118b9` | `83 c1 09` | `ADD ECX,0x9` |
| `100118bc` | `51` | `PUSH ECX` |
| `100118bd` | `83 c0 09` | `ADD EAX,0x9` |
| `100118c0` | `50` | `PUSH EAX` |
| `100118c1` | `e8 aa fe ff ff` | `CALL 0x10011770` |
| `100118c6` | `f7 d8` | `NEG EAX` |
| `100118c8` | `59` | `POP ECX` |
| `100118c9` | `1b c0` | `SBB EAX,EAX` |
| `100118cb` | `59` | `POP ECX` |
| `100118cc` | `40` | `INC EAX` |
| `100118cd` | `5d` | `POP EBP` |
| `100118ce` | `c2 04 00` | `RET 0x4` |
