# 1001c708 `__isleadbyte_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c708 |
| `name` | __isleadbyte_l |
| `namespace` | Global |
| `signature` | int __cdecl __isleadbyte_l(int _C, _locale_t _Locale) |
| `size_bytes` | 56 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __isleadbyte_l |

## Decompiled C

```c

/* Library Function - Single Match
    __isleadbyte_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __isleadbyte_l(int _C,_locale_t _Locale)

{
  ushort uVar1;
  int local_14 [2];
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,_Locale);
  uVar1 = *(ushort *)(*(int *)(local_14[0] + 200) + (_C & 0xffU) * 2);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1 & 0x8000;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c716` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |

## Callers

| From | Function |
| --- | --- |
| `1001c74a` | _isleadbyte |
| `1001e785` | __mbtowc_l |
| `1001cc58` | __isctype_l |
| `1001fbc2` | __tolower_l |
| `10015777` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c708` | `8b ff` | `MOV EDI,EDI` |
| `1001c70a` | `55` | `PUSH EBP` |
| `1001c70b` | `8b ec` | `MOV EBP,ESP` |
| `1001c70d` | `83 ec 10` | `SUB ESP,0x10` |
| `1001c710` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001c713` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001c716` | `e8 9b 8b ff ff` | `CALL 0x100152b6` |
| `1001c71b` | `0f b6 45 08` | `MOVZX EAX,byte ptr [EBP + 0x8]` |
| `1001c71f` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001c722` | `8b 89 c8 00 00 00` | `MOV ECX,dword ptr [ECX + 0xc8]` |
| `1001c728` | `0f b7 04 41` | `MOVZX EAX,word ptr [ECX + EAX*0x2]` |
| `1001c72c` | `25 00 80 00 00` | `AND EAX,0x8000` |
| `1001c731` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1001c735` | `74 07` | `JZ 0x1001c73e` |
| `1001c737` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001c73a` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001c73e` | `c9` | `LEAVE` |
| `1001c73f` | `c3` | `RET` |
