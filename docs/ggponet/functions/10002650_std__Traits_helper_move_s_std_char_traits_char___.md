# 10002650 `std::_Traits_helper::move_s<std::char_traits<char>_>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002650 |
| `name` | std::_Traits_helper::move_s<std::char_traits<char>_> |
| `namespace` | std::_Traits_helper |
| `signature` | char * __cdecl move_s<std::char_traits<char>_>(char * param_1, uint param_2, char * param_3, uint param_4) |
| `size_bytes` | 45 |
| `stack_frame_size` | 25 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ??$move_s@U?$char_traits@D@std@@@_Traits_helper@std@@YAPADPADIPBDI@Z, std::_Traits_helper::move_s<std::char_traits<char>_> |

## Decompiled C

```c

/* Library Function - Single Match
    char * __cdecl std::_Traits_helper::move_s<struct std::char_traits<char> >(char *,unsigned
   int,char const *,unsigned int)
   
   Library: Visual Studio 2008 Debug */

char * __cdecl
std::_Traits_helper::move_s<std::char_traits<char>_>
          (char *param_1,uint param_2,char *param_3,uint param_4)

{
  undefined1 uVar1;
  char *pcVar2;
  
  uVar1 = _Char_traits_cat<>();
  pcVar2 = (char *)FID_conflict_copy_s<std::char_traits<wchar_t>_>
                             (param_1,param_2,param_3,param_4,uVar1);
  return pcVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10002654` | `100027a0` | `UNCONDITIONAL_CALL` | _Char_traits_cat<> | `100027a0` |
| `10002671` | `100027d0` | `UNCONDITIONAL_CALL` | FID_conflict:copy_s<std::char_traits<wchar_t>_> | `100027d0` |

## Callers

| From | Function |
| --- | --- |
| `10001e1b` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002650` | `55` | `PUSH EBP` |
| `10002651` | `8b ec` | `MOV EBP,ESP` |
| `10002653` | `51` | `PUSH ECX` |
| `10002654` | `e8 47 01 00 00` | `CALL 0x100027a0` |
| `10002659` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `1000265c` | `0f b6 45 ff` | `MOVZX EAX,byte ptr [EBP + -0x1]` |
| `10002660` | `50` | `PUSH EAX` |
| `10002661` | `8b 4d 14` | `MOV ECX,dword ptr [EBP + 0x14]` |
| `10002664` | `51` | `PUSH ECX` |
| `10002665` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `10002668` | `52` | `PUSH EDX` |
| `10002669` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1000266c` | `50` | `PUSH EAX` |
| `1000266d` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10002670` | `51` | `PUSH ECX` |
| `10002671` | `e8 5a 01 00 00` | `CALL 0x100027d0` |
| `10002676` | `83 c4 14` | `ADD ESP,0x14` |
| `10002679` | `8b e5` | `MOV ESP,EBP` |
| `1000267b` | `5d` | `POP EBP` |
| `1000267c` | `c3` | `RET` |
