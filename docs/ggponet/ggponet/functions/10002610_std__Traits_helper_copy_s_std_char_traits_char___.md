# 10002610 `std::_Traits_helper::copy_s<std::char_traits<char>_>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002610 |
| `name` | std::_Traits_helper::copy_s<std::char_traits<char>_> |
| `namespace` | std::_Traits_helper |
| `signature` | char * __cdecl copy_s<std::char_traits<char>_>(char * param_1, uint param_2, char * param_3, uint param_4) |
| `size_bytes` | 45 |
| `stack_frame_size` | 25 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ??$copy_s@U?$char_traits@D@std@@@_Traits_helper@std@@YAPADPADIPBDI@Z, std::_Traits_helper::copy_s<std::char_traits<char>_> |

## Decompiled C

```c

/* Library Function - Single Match
    char * __cdecl std::_Traits_helper::copy_s<struct std::char_traits<char> >(char *,unsigned
   int,char const *,unsigned int)
   
   Library: Visual Studio 2008 Debug */

char * __cdecl
std::_Traits_helper::copy_s<std::char_traits<char>_>
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
| `10002614` | `100027a0` | `UNCONDITIONAL_CALL` | _Char_traits_cat<> | `100027a0` |
| `10002631` | `100027b0` | `UNCONDITIONAL_CALL` | FID_conflict:copy_s<std::char_traits<wchar_t>_> | `100027b0` |

## Callers

| From | Function |
| --- | --- |
| `1000190c` | FUN_100018d0 |
| `10001d87` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `10001879` | std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign |
| `100023da` | FUN_100023b5 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002610` | `55` | `PUSH EBP` |
| `10002611` | `8b ec` | `MOV EBP,ESP` |
| `10002613` | `51` | `PUSH ECX` |
| `10002614` | `e8 87 01 00 00` | `CALL 0x100027a0` |
| `10002619` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `1000261c` | `0f b6 45 ff` | `MOVZX EAX,byte ptr [EBP + -0x1]` |
| `10002620` | `50` | `PUSH EAX` |
| `10002621` | `8b 4d 14` | `MOV ECX,dword ptr [EBP + 0x14]` |
| `10002624` | `51` | `PUSH ECX` |
| `10002625` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `10002628` | `52` | `PUSH EDX` |
| `10002629` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1000262c` | `50` | `PUSH EAX` |
| `1000262d` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10002630` | `51` | `PUSH ECX` |
| `10002631` | `e8 7a 01 00 00` | `CALL 0x100027b0` |
| `10002636` | `83 c4 14` | `ADD ESP,0x14` |
| `10002639` | `8b e5` | `MOV ESP,EBP` |
| `1000263b` | `5d` | `POP EBP` |
| `1000263c` | `c3` | `RET` |
