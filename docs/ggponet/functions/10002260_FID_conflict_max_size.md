# 10002260 `FID_conflict:max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002260 |
| `name` | FID_conflict:max_size |
| `namespace` | Global |
| `signature` | undefined FID_conflict:max_size(void) |
| `size_bytes` | 51 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ?max_size@?$basic_string@DU?$char_traits@D@std@@V?$_DebugHeapAllocator@D@2@@std@@QBEIXZ, ?max_size@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEIXZ, ?max_size@?$basic_string@GU?$char_traits@G@std@@V?$allocator@G@2@@std@@QBEIXZ, ?max_size@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QBEIXZ, FID_conflict:max_size |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: unsigned int __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::max_size(void)const 
   
   Library: Visual Studio 2003 Debug */

int FID_conflict_max_size(void)

{
  uint uVar1;
  allocator<char> *in_ECX;
  undefined4 local_10;
  
  uVar1 = std::allocator<char>::max_size(in_ECX);
  if (uVar1 < 2) {
    local_10 = 1;
  }
  else {
    local_10 = uVar1 - 1;
  }
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000226c` | `10002500` | `UNCONDITIONAL_CALL` | std::allocator<char>::max_size | `10002500` |

## Callers

| From | Function |
| --- | --- |
| `10001e9c` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow |
| `100022db` | FUN_100022a0 |
| `10002310` | FUN_100022a0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002260` | `55` | `PUSH EBP` |
| `10002261` | `8b ec` | `MOV EBP,ESP` |
| `10002263` | `83 ec 0c` | `SUB ESP,0xc` |
| `10002266` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10002269` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1000226c` | `e8 8f 02 00 00` | `CALL 0x10002500` |
| `10002271` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10002274` | `83 7d fc 01` | `CMP dword ptr [EBP + -0x4],0x1` |
| `10002278` | `77 09` | `JA 0x10002283` |
| `1000227a` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10002281` | `eb 09` | `JMP 0x1000228c` |
| `10002283` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10002286` | `83 e8 01` | `SUB EAX,0x1` |
| `10002289` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1000228c` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1000228f` | `8b e5` | `MOV ESP,EBP` |
| `10002291` | `5d` | `POP EBP` |
| `10002292` | `c3` | `RET` |
