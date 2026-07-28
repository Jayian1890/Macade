# 100024e0 `std::allocator<char>::allocate`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100024e0 |
| `name` | std::allocator<char>::allocate |
| `namespace` | std::allocator<char> (GhidraClass) |
| `signature` | char * __thiscall allocate(allocator<char> * this, uint param_1) |
| `size_bytes` | 27 |
| `stack_frame_size` | 16 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?allocate@?$allocator@D@std@@QAEPADI@Z, std::allocator<char>::allocate |

## Decompiled C

```c

/* Library Function - Single Match
    public: char * __thiscall std::allocator<char>::allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

char * __thiscall std::allocator<char>::allocate(allocator<char> *this,uint param_1)

{
  char *pcVar1;
  
  pcVar1 = _Allocate<char>(param_1,(char *)0x0);
  return pcVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100024ed` | `10002720` | `UNCONDITIONAL_CALL` | std::_Allocate<char> | `10002720` |

## Callers

| From | Function |
| --- | --- |
| `10002348` | FUN_100022a0 |
| `1000236f` | Catch_All@10002358 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100024e0` | `55` | `PUSH EBP` |
| `100024e1` | `8b ec` | `MOV EBP,ESP` |
| `100024e3` | `51` | `PUSH ECX` |
| `100024e4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `100024e7` | `6a 00` | `PUSH 0x0` |
| `100024e9` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100024ec` | `50` | `PUSH EAX` |
| `100024ed` | `e8 2e 02 00 00` | `CALL 0x10002720` |
| `100024f2` | `83 c4 08` | `ADD ESP,0x8` |
| `100024f5` | `8b e5` | `MOV ESP,EBP` |
| `100024f7` | `5d` | `POP EBP` |
| `100024f8` | `c2 04 00` | `RET 0x4` |
