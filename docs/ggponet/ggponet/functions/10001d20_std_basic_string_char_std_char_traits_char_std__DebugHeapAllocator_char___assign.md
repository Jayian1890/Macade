# 10001d20 `std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001d20 |
| `name` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `namespace` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> (GhidraClass) |
| `signature` | basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall assign(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> * this, char * param_1, uint param_2) |
| `size_bytes` | 132 |
| `stack_frame_size` | 20 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?assign@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@QAEAAV12@PBDI@Z, std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |

## Decompiled C

```c

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2005 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          char *param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  cVar1 = FID_conflict__Inside(param_1);
  if (cVar1 == '\0') {
    bVar2 = _Grow(this,param_2,false);
    if (bVar2) {
      uVar5 = *(uint *)(this + 0x18);
      uVar6 = param_2;
      pcVar4 = (char *)FID_conflict__Myptr();
      _Traits_helper::copy_s<std::char_traits<char>_>(pcVar4,uVar5,param_1,uVar6);
      _Eos(this,param_2);
    }
  }
  else {
    iVar3 = FID_conflict__Myptr();
    this = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
           assign(this,(basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                        *)this,(int)param_1 - iVar3,param_2);
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10001d2e` | `10002420` | `UNCONDITIONAL_CALL` | FID_conflict:_Inside | `10002420` |
| `10001d41` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001d53` | `100017e0` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign | `100017e0` |
| `10001d63` | `10001e90` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow | `10001e90` |
| `10001d81` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `10001d87` | `10002610` | `UNCONDITIONAL_CALL` | std::_Traits_helper::copy_s<std::char_traits<char>_> | `10002610` |
| `10001d96` | `10001e50` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos | `10001e50` |

## Callers

| From | Function |
| --- | --- |
| `100018bb` | FID_conflict:assign |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001d20` | `55` | `PUSH EBP` |
| `10001d21` | `8b ec` | `MOV EBP,ESP` |
| `10001d23` | `51` | `PUSH ECX` |
| `10001d24` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001d27` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10001d2a` | `50` | `PUSH EAX` |
| `10001d2b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d2e` | `e8 ed 06 00 00` | `CALL 0x10002420` |
| `10001d33` | `0f b6 c8` | `MOVZX ECX,AL` |
| `10001d36` | `85 c9` | `TEST ECX,ECX` |
| `10001d38` | `74 20` | `JZ 0x10001d5a` |
| `10001d3a` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10001d3d` | `52` | `PUSH EDX` |
| `10001d3e` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d41` | `e8 0a fc ff ff` | `CALL 0x10001950` |
| `10001d46` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10001d49` | `2b c8` | `SUB ECX,EAX` |
| `10001d4b` | `51` | `PUSH ECX` |
| `10001d4c` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `10001d4f` | `52` | `PUSH EDX` |
| `10001d50` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d53` | `e8 88 fa ff ff` | `CALL 0x100017e0` |
| `10001d58` | `eb 44` | `JMP 0x10001d9e` |
| `10001d5a` | `6a 00` | `PUSH 0x0` |
| `10001d5c` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10001d5f` | `50` | `PUSH EAX` |
| `10001d60` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d63` | `e8 28 01 00 00` | `CALL 0x10001e90` |
| `10001d68` | `0f b6 c8` | `MOVZX ECX,AL` |
| `10001d6b` | `85 c9` | `TEST ECX,ECX` |
| `10001d6d` | `74 2c` | `JZ 0x10001d9b` |
| `10001d6f` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10001d72` | `52` | `PUSH EDX` |
| `10001d73` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10001d76` | `50` | `PUSH EAX` |
| `10001d77` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d7a` | `8b 51 18` | `MOV EDX,dword ptr [ECX + 0x18]` |
| `10001d7d` | `52` | `PUSH EDX` |
| `10001d7e` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d81` | `e8 ca fb ff ff` | `CALL 0x10001950` |
| `10001d86` | `50` | `PUSH EAX` |
| `10001d87` | `e8 84 08 00 00` | `CALL 0x10002610` |
| `10001d8c` | `83 c4 10` | `ADD ESP,0x10` |
| `10001d8f` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10001d92` | `50` | `PUSH EAX` |
| `10001d93` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001d96` | `e8 b5 00 00 00` | `CALL 0x10001e50` |
| `10001d9b` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001d9e` | `8b e5` | `MOV ESP,EBP` |
| `10001da0` | `5d` | `POP EBP` |
| `10001da1` | `c2 08 00` | `RET 0x8` |
