# 10003df0 `std::allocator<char>::allocator<char>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10003df0 |
| `name` | std::allocator<char>::allocator<char> |
| `namespace` | std::allocator<char> (GhidraClass) |
| `signature` | undefined __thiscall allocator<char>(allocator<char> * this, allocator<char> * param_1) |
| `size_bytes` | 16 |
| `stack_frame_size` | 16 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0?$allocator@D@std@@QAE@ABV01@@Z, std::allocator<char>::allocator<char> |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::allocator<char>::allocator<char>(class std::allocator<char> const &)
   
   Library: Visual Studio 2003 Debug */

allocator<char> * __thiscall
std::allocator<char>::allocator<char>(allocator<char> *this,allocator<char> *param_1)

{
  return this;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000198e` | _String_val<> |
| `100019ae` | FUN_100019a0 |
| `10002123` | FUN_10002110 |
| `1000213a` | FUN_10002110 |
| `100024b3` | FUN_100024a0 |
| `100024ca` | FUN_100024a0 |
| `10002571` | FUN_10002530 |
| `10004ef2` | FUN_10004ec0 |
| `10006313` | FUN_10006300 |
| `1000632e` | FUN_10006300 |
| `100071f3` | FUN_100071e0 |
| `1000720e` | FUN_100071e0 |
| `100075f3` | FUN_100075e0 |
| `10007611` | FUN_100075e0 |
| `10007733` | FUN_10007720 |
| `10001cd3` | FUN_10001cc0 |
| `10001cea` | FUN_10001cc0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10003df0` | `55` | `PUSH EBP` |
| `10003df1` | `8b ec` | `MOV EBP,ESP` |
| `10003df3` | `51` | `PUSH ECX` |
| `10003df4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10003df7` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10003dfa` | `8b e5` | `MOV ESP,EBP` |
| `10003dfc` | `5d` | `POP EBP` |
| `10003dfd` | `c2 04 00` | `RET 0x4` |
