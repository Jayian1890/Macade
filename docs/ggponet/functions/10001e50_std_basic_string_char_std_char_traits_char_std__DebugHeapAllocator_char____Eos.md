# 10001e50 `std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001e50 |
| `name` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos |
| `namespace` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> (GhidraClass) |
| `signature` | void __thiscall _Eos(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> * this, uint param_1) |
| `size_bytes` | 52 |
| `stack_frame_size` | 20 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?_Eos@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@IAEXI@Z, std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos |

## Decompiled C

```c

/* Library Function - Single Match
    protected: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Eos(unsigned int)
   
   Library: Visual Studio 2005 Debug */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1)

{
  int iVar1;
  undefined1 local_5;
  
  local_5 = 0;
  *(uint *)(this + 0x14) = param_1;
  iVar1 = FID_conflict__Myptr(&local_5);
  FUN_10001090(iVar1 + param_1);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10001e6d` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001e76` | `10001090` | `UNCONDITIONAL_CALL` | FUN_10001090 | `10001090` |

## Callers

| From | Function |
| --- | --- |
| `1000193b` | FUN_100018d0 |
| `10001d96` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001888` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001e36` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase |
| `10001f10` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow |
| `10002407` | FUN_100023b5 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001e50` | `55` | `PUSH EBP` |
| `10001e51` | `8b ec` | `MOV EBP,ESP` |
| `10001e53` | `83 ec 08` | `SUB ESP,0x8` |
| `10001e56` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10001e59` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10001e5d` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001e60` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10001e63` | `89 48 14` | `MOV dword ptr [EAX + 0x14],ECX` |
| `10001e66` | `8d 55 ff` | `LEA EDX,[EBP + -0x1]` |
| `10001e69` | `52` | `PUSH EDX` |
| `10001e6a` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001e6d` | `e8 de fa ff ff` | `CALL 0x10001950` |
| `10001e72` | `03 45 08` | `ADD EAX,dword ptr [EBP + 0x8]` |
| `10001e75` | `50` | `PUSH EAX` |
| `10001e76` | `e8 15 f2 ff ff` | `CALL 0x10001090` |
| `10001e7b` | `83 c4 08` | `ADD ESP,0x8` |
| `10001e7e` | `8b e5` | `MOV ESP,EBP` |
| `10001e80` | `5d` | `POP EBP` |
| `10001e81` | `c2 04 00` | `RET 0x4` |
