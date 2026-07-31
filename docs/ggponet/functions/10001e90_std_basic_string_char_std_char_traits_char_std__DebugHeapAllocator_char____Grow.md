# 10001e90 `std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001e90 |
| `name` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow |
| `namespace` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> (GhidraClass) |
| `signature` | bool __thiscall _Grow(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> * this, uint param_1, bool param_2) |
| `size_bytes` | 148 |
| `stack_frame_size` | 21 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@IAE_NI_N@Z, std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow |

## Decompiled C

```c

/* Library Function - Single Match
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Grow(unsigned int,bool)
   
   Library: Visual Studio 2005 Debug */

bool __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1,bool param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FID_conflict_max_size();
  if (uVar1 < param_1) {
    FUN_10010c50();
  }
  if (*(uint *)(this + 0x18) < param_1) {
    FUN_100022a0(param_1,*(undefined4 *)(this + 0x14));
  }
  else if ((param_2) && (param_1 < 0x10)) {
    if (param_1 < *(uint *)(this + 0x14)) {
      local_c = param_1;
    }
    else {
      local_c = *(uint *)(this + 0x14);
    }
    FUN_100018d0(1,local_c);
  }
  else if (param_1 == 0) {
    _Eos(this,0);
  }
  return param_1 != 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10001e9c` | `10002260` | `UNCONDITIONAL_CALL` | FID_conflict:max_size | `10002260` |
| `10001ea6` | `10010c50` | `UNCONDITIONAL_CALL` | FUN_10010c50 | `10010c50` |
| `10001ec4` | `100022a0` | `UNCONDITIONAL_CALL` | FUN_100022a0 | `100022a0` |
| `10001efe` | `100018d0` | `UNCONDITIONAL_CALL` | FUN_100018d0 | `100018d0` |
| `10001f10` | `10001e50` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos | `10001e50` |

## Callers

| From | Function |
| --- | --- |
| `10001d63` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `1000184d` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001e90` | `55` | `PUSH EBP` |
| `10001e91` | `8b ec` | `MOV EBP,ESP` |
| `10001e93` | `83 ec 08` | `SUB ESP,0x8` |
| `10001e96` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001e99` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001e9c` | `e8 bf 03 00 00` | `CALL 0x10002260` |
| `10001ea1` | `3b 45 08` | `CMP EAX,dword ptr [EBP + 0x8]` |
| `10001ea4` | `73 05` | `JNC 0x10001eab` |
| `10001ea6` | `e8 a5 ed 00 00` | `CALL 0x10010c50` |
| `10001eab` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001eae` | `8b 48 18` | `MOV ECX,dword ptr [EAX + 0x18]` |
| `10001eb1` | `3b 4d 08` | `CMP ECX,dword ptr [EBP + 0x8]` |
| `10001eb4` | `73 15` | `JNC 0x10001ecb` |
| `10001eb6` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `10001eb9` | `8b 42 14` | `MOV EAX,dword ptr [EDX + 0x14]` |
| `10001ebc` | `50` | `PUSH EAX` |
| `10001ebd` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10001ec0` | `51` | `PUSH ECX` |
| `10001ec1` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001ec4` | `e8 d7 03 00 00` | `CALL 0x100022a0` |
| `10001ec9` | `eb 4a` | `JMP 0x10001f15` |
| `10001ecb` | `0f b6 55 0c` | `MOVZX EDX,byte ptr [EBP + 0xc]` |
| `10001ecf` | `85 d2` | `TEST EDX,EDX` |
| `10001ed1` | `74 32` | `JZ 0x10001f05` |
| `10001ed3` | `83 7d 08 10` | `CMP dword ptr [EBP + 0x8],0x10` |
| `10001ed7` | `73 2c` | `JNC 0x10001f05` |
| `10001ed9` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001edc` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10001edf` | `3b 48 14` | `CMP ECX,dword ptr [EAX + 0x14]` |
| `10001ee2` | `73 08` | `JNC 0x10001eec` |
| `10001ee4` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10001ee7` | `89 55 f8` | `MOV dword ptr [EBP + -0x8],EDX` |
| `10001eea` | `eb 09` | `JMP 0x10001ef5` |
| `10001eec` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001eef` | `8b 48 14` | `MOV ECX,dword ptr [EAX + 0x14]` |
| `10001ef2` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10001ef5` | `8b 55 f8` | `MOV EDX,dword ptr [EBP + -0x8]` |
| `10001ef8` | `52` | `PUSH EDX` |
| `10001ef9` | `6a 01` | `PUSH 0x1` |
| `10001efb` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001efe` | `e8 cd f9 ff ff` | `CALL 0x100018d0` |
| `10001f03` | `eb 10` | `JMP 0x10001f15` |
| `10001f05` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10001f09` | `75 0a` | `JNZ 0x10001f15` |
| `10001f0b` | `6a 00` | `PUSH 0x0` |
| `10001f0d` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001f10` | `e8 3b ff ff ff` | `CALL 0x10001e50` |
| `10001f15` | `33 c0` | `XOR EAX,EAX` |
| `10001f17` | `3b 45 08` | `CMP EAX,dword ptr [EBP + 0x8]` |
| `10001f1a` | `1b c0` | `SBB EAX,EAX` |
| `10001f1c` | `f7 d8` | `NEG EAX` |
| `10001f1e` | `8b e5` | `MOV ESP,EBP` |
| `10001f20` | `5d` | `POP EBP` |
| `10001f21` | `c2 08 00` | `RET 0x8` |
