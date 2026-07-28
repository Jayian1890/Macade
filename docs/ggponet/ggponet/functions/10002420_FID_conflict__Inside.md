# 10002420 `FID_conflict:_Inside`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002420 |
| `name` | FID_conflict:_Inside |
| `namespace` | Global |
| `signature` | undefined FID_conflict:_Inside(void) |
| `size_bytes` | 57 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ?_Inside@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@IAE_NPBD@Z, ?_Inside@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IAE_NPBD@Z, FID_conflict:_Inside |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Inside(char const *)
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Inside(char const *)
   
   Library: Visual Studio 2008 Debug */

uint FID_conflict__Inside(uint param_1)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  
  if ((param_1 != 0) && (in_EAX = FID_conflict__Myptr(), in_EAX <= param_1)) {
    iVar1 = FID_conflict__Myptr();
    in_EAX = iVar1 + *(int *)(in_ECX + 0x14);
    if (param_1 < in_EAX) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10002430` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |
| `1000243d` | `10001950` | `UNCONDITIONAL_CALL` | FID_conflict:_Myptr | `10001950` |

## Callers

| From | Function |
| --- | --- |
| `10001d2e` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002420` | `55` | `PUSH EBP` |
| `10002421` | `8b ec` | `MOV EBP,ESP` |
| `10002423` | `51` | `PUSH ECX` |
| `10002424` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10002427` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1000242b` | `74 20` | `JZ 0x1000244d` |
| `1000242d` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10002430` | `e8 1b f5 ff ff` | `CALL 0x10001950` |
| `10002435` | `39 45 08` | `CMP dword ptr [EBP + 0x8],EAX` |
| `10002438` | `72 13` | `JC 0x1000244d` |
| `1000243a` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000243d` | `e8 0e f5 ff ff` | `CALL 0x10001950` |
| `10002442` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10002445` | `03 41 14` | `ADD EAX,dword ptr [ECX + 0x14]` |
| `10002448` | `3b 45 08` | `CMP EAX,dword ptr [EBP + 0x8]` |
| `1000244b` | `77 06` | `JA 0x10002453` |
| `1000244d` | `32 c0` | `XOR AL,AL` |
| `1000244f` | `eb 04` | `JMP 0x10002455` |
| `10002453` | `b0 01` | `MOV AL,0x1` |
| `10002455` | `8b e5` | `MOV ESP,EBP` |
| `10002457` | `5d` | `POP EBP` |
| `10002458` | `c2 04 00` | `RET 0x4` |
