# 10003f80 `std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10003f80 |
| `name` | std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back |
| `namespace` | std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> (GhidraClass) |
| `signature` | wchar_t * __thiscall back(basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> * this) |
| `size_bytes` | 45 |
| `stack_frame_size` | 28 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?back@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QAEAA_WXZ, std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back |

## Decompiled C

```c

/* Library Function - Single Match
    public: wchar_t & __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::back(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

wchar_t * __thiscall
std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
          (basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *this)

{
  wchar_t *pwVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  uVar3 = 1;
  puVar2 = local_14;
  FUN_100041f0(local_c);
  FUN_10004560(puVar2,uVar3);
  pwVar1 = (wchar_t *)FUN_10004540(this);
  return pwVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10003f96` | `100041f0` | `UNCONDITIONAL_CALL` | FUN_100041f0 | `100041f0` |
| `10003f9d` | `10004560` | `UNCONDITIONAL_CALL` | FUN_10004560 | `10004560` |
| `10003fa4` | `10004540` | `UNCONDITIONAL_CALL` | FUN_10004540 | `10004540` |

## Callers

| From | Function |
| --- | --- |
| `10003eca` | FUN_10003ec0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10003f80` | `55` | `PUSH EBP` |
| `10003f81` | `8b ec` | `MOV EBP,ESP` |
| `10003f83` | `83 ec 14` | `SUB ESP,0x14` |
| `10003f86` | `89 4d ec` | `MOV dword ptr [EBP + -0x14],ECX` |
| `10003f89` | `6a 01` | `PUSH 0x1` |
| `10003f8b` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `10003f8e` | `50` | `PUSH EAX` |
| `10003f8f` | `8d 4d f8` | `LEA ECX,[EBP + -0x8]` |
| `10003f92` | `51` | `PUSH ECX` |
| `10003f93` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `10003f96` | `e8 55 02 00 00` | `CALL 0x100041f0` |
| `10003f9b` | `8b c8` | `MOV ECX,EAX` |
| `10003f9d` | `e8 be 05 00 00` | `CALL 0x10004560` |
| `10003fa2` | `8b c8` | `MOV ECX,EAX` |
| `10003fa4` | `e8 97 05 00 00` | `CALL 0x10004540` |
| `10003fa9` | `8b e5` | `MOV ESP,EBP` |
| `10003fab` | `5d` | `POP EBP` |
| `10003fac` | `c3` | `RET` |
