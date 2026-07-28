# 10001db0 `std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001db0 |
| `name` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase |
| `namespace` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> (GhidraClass) |
| `signature` | basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall erase(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> * this, uint param_1, uint param_2) |
| `size_bytes` | 148 |
| `stack_frame_size` | 24 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?erase@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@QAEAAV12@II@Z, std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase |

## Decompiled C

```c

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::erase(unsigned int,unsigned int)
   
   Library: Visual Studio 2008 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(uint *)(this + 0x14) < param_1) {
    FUN_10010c88();
  }
  if (*(int *)(this + 0x14) - param_1 < param_2) {
    param_2 = *(int *)(this + 0x14) - param_1;
  }
  if (param_2 != 0) {
    uVar4 = (*(int *)(this + 0x14) - param_1) - param_2;
    iVar1 = FID_conflict__Myptr();
    pcVar2 = (char *)(iVar1 + param_1 + param_2);
    uVar3 = *(int *)(this + 0x18) - param_1;
    iVar1 = FID_conflict__Myptr();
    _Traits_helper::move_s<std::char_traits<char>_>((char *)(iVar1 + param_1),uVar3,pcVar2,uVar4);
    _Eos(this,*(int *)(this + 0x14) - param_2);
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10001dc4` | `10010c88` | `UNCONDITIONAL_CALL` | FUN_10010c88 | `10010c88` |
| `10001df9` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001e12` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001e1b` | `10002650` | `UNCONDITIONAL_CALL` | std::_Traits_helper::move_s<std::char_traits<char>_> | `10002650` |
| `10001e36` | `10001e50` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos | `10001e50` |

## Callers

| From | Function |
| --- | --- |
| `1000182f` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `1000183d` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001db0` | `55` | `PUSH EBP` |
| `10001db1` | `8b ec` | `MOV EBP,ESP` |
| `10001db3` | `83 ec 08` | `SUB ESP,0x8` |
| `10001db6` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10001db9` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001dbc` | `8b 48 14` | `MOV ECX,dword ptr [EAX + 0x14]` |
| `10001dbf` | `3b 4d 08` | `CMP ECX,dword ptr [EBP + 0x8]` |
| `10001dc2` | `73 05` | `JNC 0x10001dc9` |
| `10001dc4` | `e8 bf ee 00 00` | `CALL 0x10010c88` |
| `10001dc9` | `8b 55 f8` | `MOV EDX,dword ptr [EBP + -0x8]` |
| `10001dcc` | `8b 42 14` | `MOV EAX,dword ptr [EDX + 0x14]` |
| `10001dcf` | `2b 45 08` | `SUB EAX,dword ptr [EBP + 0x8]` |
| `10001dd2` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `10001dd5` | `73 0c` | `JNC 0x10001de3` |
| `10001dd7` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001dda` | `8b 51 14` | `MOV EDX,dword ptr [ECX + 0x14]` |
| `10001ddd` | `2b 55 08` | `SUB EDX,dword ptr [EBP + 0x8]` |
| `10001de0` | `89 55 0c` | `MOV dword ptr [EBP + 0xc],EDX` |
| `10001de3` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `10001de7` | `76 52` | `JBE 0x10001e3b` |
| `10001de9` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001dec` | `8b 48 14` | `MOV ECX,dword ptr [EAX + 0x14]` |
| `10001def` | `2b 4d 08` | `SUB ECX,dword ptr [EBP + 0x8]` |
| `10001df2` | `2b 4d 0c` | `SUB ECX,dword ptr [EBP + 0xc]` |
| `10001df5` | `51` | `PUSH ECX` |
| `10001df6` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001df9` | `e8 52 fb ff ff` | `CALL 0x10001950` |
| `10001dfe` | `03 45 08` | `ADD EAX,dword ptr [EBP + 0x8]` |
| `10001e01` | `03 45 0c` | `ADD EAX,dword ptr [EBP + 0xc]` |
| `10001e04` | `50` | `PUSH EAX` |
| `10001e05` | `8b 55 f8` | `MOV EDX,dword ptr [EBP + -0x8]` |
| `10001e08` | `8b 42 18` | `MOV EAX,dword ptr [EDX + 0x18]` |
| `10001e0b` | `2b 45 08` | `SUB EAX,dword ptr [EBP + 0x8]` |
| `10001e0e` | `50` | `PUSH EAX` |
| `10001e0f` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001e12` | `e8 39 fb ff ff` | `CALL 0x10001950` |
| `10001e17` | `03 45 08` | `ADD EAX,dword ptr [EBP + 0x8]` |
| `10001e1a` | `50` | `PUSH EAX` |
| `10001e1b` | `e8 30 08 00 00` | `CALL 0x10002650` |
| `10001e20` | `83 c4 10` | `ADD ESP,0x10` |
| `10001e23` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001e26` | `8b 51 14` | `MOV EDX,dword ptr [ECX + 0x14]` |
| `10001e29` | `2b 55 0c` | `SUB EDX,dword ptr [EBP + 0xc]` |
| `10001e2c` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `10001e2f` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001e32` | `50` | `PUSH EAX` |
| `10001e33` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001e36` | `e8 15 00 00 00` | `CALL 0x10001e50` |
| `10001e3b` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001e3e` | `8b e5` | `MOV ESP,EBP` |
| `10001e40` | `5d` | `POP EBP` |
| `10001e41` | `c2 08 00` | `RET 0x8` |
