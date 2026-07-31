# 100017e0 `std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100017e0 |
| `name` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `namespace` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> (GhidraClass) |
| `signature` | basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall assign(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> * this, basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * param_1, uint param_2, uint param_3) |
| `size_bytes` | 182 |
| `stack_frame_size` | 28 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?assign@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@QAEAAV12@ABV12@II@Z, std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |

## Decompiled C

```c

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(class
   std::basic_string<char,struct std::char_traits<char>,class std::_DebugHeapAllocator<char> > const
   &,unsigned int,unsigned int)
   
   Library: Visual Studio 2005 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
          *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint local_8;
  
  uVar2 = FUN_100015c0();
  if (uVar2 < param_2) {
    FUN_10010c88();
  }
  iVar3 = FUN_100015c0();
  local_8 = iVar3 - param_2;
  if (param_3 < local_8) {
    local_8 = param_3;
  }
  if (this == (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1)
  {
    erase(this,param_2 + local_8,0xffffffff);
    erase(this,0,param_2);
  }
  else {
    bVar1 = _Grow(this,local_8,false);
    if (bVar1) {
      uVar6 = local_8;
      iVar3 = FID_conflict__Myptr();
      pcVar4 = (char *)(iVar3 + param_2);
      uVar2 = *(uint *)(this + 0x18);
      pcVar5 = (char *)FID_conflict__Myptr();
      _Traits_helper::copy_s<std::char_traits<char>_>(pcVar5,uVar2,pcVar4,uVar6);
      _Eos(this,local_8);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100017ec` | `100015c0` | `UNCONDITIONAL_CALL` | FUN_100015c0 | `100015c0` |
| `100017f6` | `10010c88` | `UNCONDITIONAL_CALL` | FUN_10010c88 | `10010c88` |
| `100017fe` | `100015c0` | `UNCONDITIONAL_CALL` | FUN_100015c0 | `100015c0` |
| `1000182f` | `10001db0` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase | `10001db0` |
| `1000183d` | `10001db0` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase | `10001db0` |
| `1000184d` | `10001e90` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow | `10001e90` |
| `10001860` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001873` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001879` | `10002610` | `UNCONDITIONAL_CALL` | std::_Traits_helper::copy_s<std::char_traits<char>_> | `10002610` |
| `10001888` | `10001e50` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos | `10001e50` |

## Callers

| From | Function |
| --- | --- |
| `10001d53` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `1000156f` | FUN_10001540 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1000181f` | `100330ec` | `READ` | DAT_100330ec |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100017e0` | `55` | `PUSH EBP` |
| `100017e1` | `8b ec` | `MOV EBP,ESP` |
| `100017e3` | `83 ec 08` | `SUB ESP,0x8` |
| `100017e6` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `100017e9` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100017ec` | `e8 cf fd ff ff` | `CALL 0x100015c0` |
| `100017f1` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `100017f4` | `73 05` | `JNC 0x100017fb` |
| `100017f6` | `e8 8d f4 00 00` | `CALL 0x10010c88` |
| `100017fb` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100017fe` | `e8 bd fd ff ff` | `CALL 0x100015c0` |
| `10001803` | `2b 45 0c` | `SUB EAX,dword ptr [EBP + 0xc]` |
| `10001806` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10001809` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1000180c` | `3b 45 fc` | `CMP EAX,dword ptr [EBP + -0x4]` |
| `1000180f` | `73 06` | `JNC 0x10001817` |
| `10001811` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10001814` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001817` | `8b 55 f8` | `MOV EDX,dword ptr [EBP + -0x8]` |
| `1000181a` | `3b 55 08` | `CMP EDX,dword ptr [EBP + 0x8]` |
| `1000181d` | `75 25` | `JNZ 0x10001844` |
| `1000181f` | `a1 ec 30 03 10` | `MOV EAX,[0x100330ec]` |
| `10001824` | `50` | `PUSH EAX` |
| `10001825` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10001828` | `03 4d fc` | `ADD ECX,dword ptr [EBP + -0x4]` |
| `1000182b` | `51` | `PUSH ECX` |
| `1000182c` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1000182f` | `e8 7c 05 00 00` | `CALL 0x10001db0` |
| `10001834` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10001837` | `52` | `PUSH EDX` |
| `10001838` | `6a 00` | `PUSH 0x0` |
| `1000183a` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1000183d` | `e8 6e 05 00 00` | `CALL 0x10001db0` |
| `10001842` | `eb 49` | `JMP 0x1000188d` |
| `10001844` | `6a 00` | `PUSH 0x0` |
| `10001846` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001849` | `50` | `PUSH EAX` |
| `1000184a` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1000184d` | `e8 3e 06 00 00` | `CALL 0x10001e90` |
| `10001852` | `0f b6 c8` | `MOVZX ECX,AL` |
| `10001855` | `85 c9` | `TEST ECX,ECX` |
| `10001857` | `74 34` | `JZ 0x1000188d` |
| `10001859` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `1000185c` | `52` | `PUSH EDX` |
| `1000185d` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10001860` | `e8 eb 00 00 00` | `CALL 0x10001950` |
| `10001865` | `03 45 0c` | `ADD EAX,dword ptr [EBP + 0xc]` |
| `10001868` | `50` | `PUSH EAX` |
| `10001869` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1000186c` | `8b 48 18` | `MOV ECX,dword ptr [EAX + 0x18]` |
| `1000186f` | `51` | `PUSH ECX` |
| `10001870` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001873` | `e8 d8 00 00 00` | `CALL 0x10001950` |
| `10001878` | `50` | `PUSH EAX` |
| `10001879` | `e8 92 0d 00 00` | `CALL 0x10002610` |
| `1000187e` | `83 c4 10` | `ADD ESP,0x10` |
| `10001881` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `10001884` | `52` | `PUSH EDX` |
| `10001885` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001888` | `e8 c3 05 00 00` | `CALL 0x10001e50` |
| `1000188d` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001890` | `8b e5` | `MOV ESP,EBP` |
| `10001892` | `5d` | `POP EBP` |
| `10001893` | `c2 0c 00` | `RET 0xc` |
