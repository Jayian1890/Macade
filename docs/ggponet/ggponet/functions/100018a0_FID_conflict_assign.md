# 100018a0 `FID_conflict:assign`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100018a0 |
| `name` | FID_conflict:assign |
| `namespace` | Global |
| `signature` | undefined FID_conflict:assign(void) |
| `size_bytes` | 38 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ?assign@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@QAEAAV12@PBD@Z, ?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV12@PBD@Z, FID_conflict:assign |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(char const *)
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *)
   
   Library: Visual Studio 2005 Debug */

void FID_conflict_assign(char *param_1)

{
  uint uVar1;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *in_ECX;
  
  uVar1 = length(param_1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
            (in_ECX,param_1,uVar1);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100018ab` | `100010a0` | `UNCONDITIONAL_CALL` | length | `100010a0` |
| `100018bb` | `10001d20` | `UNCONDITIONAL_CALL` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign | `10001d20` |

## Callers

| From | Function |
| --- | --- |
| `1000152c` | basic_string<> |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100018a0` | `55` | `PUSH EBP` |
| `100018a1` | `8b ec` | `MOV EBP,ESP` |
| `100018a3` | `51` | `PUSH ECX` |
| `100018a4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `100018a7` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100018aa` | `50` | `PUSH EAX` |
| `100018ab` | `e8 f0 f7 ff ff` | `CALL 0x100010a0` |
| `100018b0` | `83 c4 04` | `ADD ESP,0x4` |
| `100018b3` | `50` | `PUSH EAX` |
| `100018b4` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100018b7` | `51` | `PUSH ECX` |
| `100018b8` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100018bb` | `e8 60 04 00 00` | `CALL 0x10001d20` |
| `100018c0` | `8b e5` | `MOV ESP,EBP` |
| `100018c2` | `5d` | `POP EBP` |
| `100018c3` | `c2 04 00` | `RET 0x4` |
