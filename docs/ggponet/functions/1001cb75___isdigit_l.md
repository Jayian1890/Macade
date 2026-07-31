# 1001cb75 `__isdigit_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001cb75 |
| `name` | __isdigit_l |
| `namespace` | Global |
| `signature` | int __cdecl __isdigit_l(int _C, _locale_t _Locale) |
| `size_bytes` | 81 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __isdigit_l |

## Decompiled C

```c

/* Library Function - Single Match
    __isdigit_l
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl __isdigit_l(int _C,_locale_t _Locale)

{
  uint uVar1;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,_Locale);
  if ((int)(local_14.locinfo)->locale_name[3] < 2) {
    uVar1 = *(ushort *)(local_14.locinfo[1].lc_category[0].locale + _C * 2) & 4;
  }
  else {
    uVar1 = __isctype_l(_C,4,&local_14);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cb83` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001cb9d` | `1001cc14` | `UNCONDITIONAL_CALL` | __isctype_l | `1001cc14` |

## Callers

| From | Function |
| --- | --- |
| `1001cbeb` | _isdigit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001cb75` | `8b ff` | `MOV EDI,EDI` |
| `1001cb77` | `55` | `PUSH EBP` |
| `1001cb78` | `8b ec` | `MOV EBP,ESP` |
| `1001cb7a` | `83 ec 10` | `SUB ESP,0x10` |
| `1001cb7d` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001cb80` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001cb83` | `e8 2e 87 ff ff` | `CALL 0x100152b6` |
| `1001cb88` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001cb8b` | `83 b8 ac 00 00 00 01` | `CMP dword ptr [EAX + 0xac],0x1` |
| `1001cb92` | `7e 13` | `JLE 0x1001cba7` |
| `1001cb94` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001cb97` | `50` | `PUSH EAX` |
| `1001cb98` | `6a 04` | `PUSH 0x4` |
| `1001cb9a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001cb9d` | `e8 72 00 00 00` | `CALL 0x1001cc14` |
| `1001cba2` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001cba5` | `eb 10` | `JMP 0x1001cbb7` |
| `1001cba7` | `8b 80 c8 00 00 00` | `MOV EAX,dword ptr [EAX + 0xc8]` |
| `1001cbad` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001cbb0` | `0f b7 04 48` | `MOVZX EAX,word ptr [EAX + ECX*0x2]` |
| `1001cbb4` | `83 e0 04` | `AND EAX,0x4` |
| `1001cbb7` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1001cbbb` | `74 07` | `JZ 0x1001cbc4` |
| `1001cbbd` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001cbc0` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001cbc4` | `c9` | `LEAVE` |
| `1001cbc5` | `c3` | `RET` |
