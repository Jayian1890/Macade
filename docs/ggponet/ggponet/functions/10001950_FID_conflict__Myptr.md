# 10001950 `FID_conflict:_Myptr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001950 |
| `name` | FID_conflict:_Myptr |
| `namespace` | Global |
| `signature` | undefined FID_conflict:_Myptr(void) |
| `size_bytes` | 45 |
| `stack_frame_size` | 16 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ?_Myptr@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@IAEPADXZ, ?_Myptr@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IAEPADXZ, FID_conflict:_Myptr |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    protected: char * __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Myptr(void)
    protected: char * __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Myptr(void)
   
   Library: Visual Studio 2005 Debug */

int FID_conflict__Myptr(void)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    local_c = in_ECX + 4;
  }
  else {
    local_c = *(int *)(in_ECX + 4);
  }
  return local_c;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10001e6d` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos |
| `10001d41` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001d81` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001860` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001873` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001df9` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase |
| `10001e12` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase |
| `100023c9` | FUN_100023b5 |
| `10002430` | FID_conflict:_Inside |
| `1000243d` | FID_conflict:_Inside |
| `100015aa` | FUN_100015a0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001950` | `55` | `PUSH EBP` |
| `10001951` | `8b ec` | `MOV EBP,ESP` |
| `10001953` | `83 ec 08` | `SUB ESP,0x8` |
| `10001956` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001959` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000195c` | `83 78 18 10` | `CMP dword ptr [EAX + 0x18],0x10` |
| `10001960` | `72 0b` | `JC 0x1000196d` |
| `10001962` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001965` | `8b 51 04` | `MOV EDX,dword ptr [ECX + 0x4]` |
| `10001968` | `89 55 f8` | `MOV dword ptr [EBP + -0x8],EDX` |
| `1000196b` | `eb 09` | `JMP 0x10001976` |
| `1000196d` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001970` | `83 c0 04` | `ADD EAX,0x4` |
| `10001973` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10001976` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001979` | `8b e5` | `MOV ESP,EBP` |
| `1000197b` | `5d` | `POP EBP` |
| `1000197c` | `c3` | `RET` |
