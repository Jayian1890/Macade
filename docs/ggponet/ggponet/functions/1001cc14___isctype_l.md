# 1001cc14 `__isctype_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001cc14 |
| `name` | __isctype_l |
| `namespace` | Global |
| `signature` | int __cdecl __isctype_l(int _C, int _Type, _locale_t _Locale) |
| `size_bytes` | 184 |
| `stack_frame_size` | 44 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __isctype_l |

## Decompiled C

```c

/* Library Function - Single Match
    __isctype_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __isctype_l(int _C,int _Type,_locale_t _Locale)

{
  int iVar1;
  BOOL BVar2;
  CHAR CVar3;
  localeinfo_struct local_1c;
  int local_14;
  char local_10;
  CHAR local_c;
  CHAR local_b;
  undefined1 local_a;
  ushort local_8 [2];
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_1c,_Locale);
  if (_C + 1U < 0x101) {
    local_8[0] = *(ushort *)(local_1c.locinfo[1].lc_category[0].locale + _C * 2);
  }
  else {
    iVar1 = __isleadbyte_l(_C >> 8 & 0xff,&local_1c);
    CVar3 = (CHAR)_C;
    if (iVar1 == 0) {
      local_b = '\0';
      iVar1 = 1;
      local_c = CVar3;
    }
    else {
      _C._0_1_ = (CHAR)((uint)_C >> 8);
      local_c = (CHAR)_C;
      local_a = 0;
      iVar1 = 2;
      local_b = CVar3;
    }
    BVar2 = ___crtGetStringTypeA
                      (&local_1c,1,&local_c,iVar1,local_8,(local_1c.locinfo)->lc_codepage,
                       (BOOL)(local_1c.locinfo)->lc_category[0].wlocale);
    if (BVar2 == 0) {
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
      return 0;
    }
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return (uint)local_8[0] & _Type;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cc23` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001cc58` | `1001c708` | `UNCONDITIONAL_CALL` | __isleadbyte_l | `1001c708` |
| `1001cc99` | `1001ef17` | `UNCONDITIONAL_CALL` | ___crtGetStringTypeA | `1001ef17` |

## Callers

| From | Function |
| --- | --- |
| `10017b78` | strtoxl |
| `1001fb61` | __tolower_l |
| `1001cb9d` | __isdigit_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001cc14` | `8b ff` | `MOV EDI,EDI` |
| `1001cc16` | `55` | `PUSH EBP` |
| `1001cc17` | `8b ec` | `MOV EBP,ESP` |
| `1001cc19` | `83 ec 18` | `SUB ESP,0x18` |
| `1001cc1c` | `53` | `PUSH EBX` |
| `1001cc1d` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001cc20` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1001cc23` | `e8 8e 86 ff ff` | `CALL 0x100152b6` |
| `1001cc28` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1001cc2b` | `8d 43 01` | `LEA EAX,[EBX + 0x1]` |
| `1001cc2e` | `3d 00 01 00 00` | `CMP EAX,0x100` |
| `1001cc33` | `77 0f` | `JA 0x1001cc44` |
| `1001cc35` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1001cc38` | `8b 80 c8 00 00 00` | `MOV EAX,dword ptr [EAX + 0xc8]` |
| `1001cc3e` | `0f b7 04 58` | `MOVZX EAX,word ptr [EAX + EBX*0x2]` |
| `1001cc42` | `eb 75` | `JMP 0x1001ccb9` |
| `1001cc44` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `1001cc47` | `c1 7d 08 08` | `SAR dword ptr [EBP + 0x8],0x8` |
| `1001cc4b` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001cc4e` | `50` | `PUSH EAX` |
| `1001cc4f` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001cc52` | `25 ff 00 00 00` | `AND EAX,0xff` |
| `1001cc57` | `50` | `PUSH EAX` |
| `1001cc58` | `e8 ab fa ff ff` | `CALL 0x1001c708` |
| `1001cc5d` | `59` | `POP ECX` |
| `1001cc5e` | `59` | `POP ECX` |
| `1001cc5f` | `85 c0` | `TEST EAX,EAX` |
| `1001cc61` | `74 12` | `JZ 0x1001cc75` |
| `1001cc63` | `8a 45 08` | `MOV AL,byte ptr [EBP + 0x8]` |
| `1001cc66` | `6a 02` | `PUSH 0x2` |
| `1001cc68` | `88 45 f8` | `MOV byte ptr [EBP + -0x8],AL` |
| `1001cc6b` | `88 5d f9` | `MOV byte ptr [EBP + -0x7],BL` |
| `1001cc6e` | `c6 45 fa 00` | `MOV byte ptr [EBP + -0x6],0x0` |
| `1001cc72` | `59` | `POP ECX` |
| `1001cc73` | `eb 0a` | `JMP 0x1001cc7f` |
| `1001cc75` | `33 c9` | `XOR ECX,ECX` |
| `1001cc77` | `88 5d f8` | `MOV byte ptr [EBP + -0x8],BL` |
| `1001cc7a` | `c6 45 f9 00` | `MOV byte ptr [EBP + -0x7],0x0` |
| `1001cc7e` | `41` | `INC ECX` |
| `1001cc7f` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1001cc82` | `6a 01` | `PUSH 0x1` |
| `1001cc84` | `ff 70 14` | `PUSH dword ptr [EAX + 0x14]` |
| `1001cc87` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1001cc8a` | `8d 45 fc` | `LEA EAX,[EBP + -0x4]` |
| `1001cc8d` | `50` | `PUSH EAX` |
| `1001cc8e` | `51` | `PUSH ECX` |
| `1001cc8f` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001cc92` | `50` | `PUSH EAX` |
| `1001cc93` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001cc96` | `6a 01` | `PUSH 0x1` |
| `1001cc98` | `50` | `PUSH EAX` |
| `1001cc99` | `e8 79 22 00 00` | `CALL 0x1001ef17` |
| `1001cc9e` | `83 c4 20` | `ADD ESP,0x20` |
| `1001cca1` | `85 c0` | `TEST EAX,EAX` |
| `1001cca3` | `75 10` | `JNZ 0x1001ccb5` |
| `1001cca5` | `38 45 f4` | `CMP byte ptr [EBP + -0xc],AL` |
| `1001cca8` | `74 07` | `JZ 0x1001ccb1` |
| `1001ccaa` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001ccad` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001ccb1` | `33 c0` | `XOR EAX,EAX` |
| `1001ccb3` | `eb 14` | `JMP 0x1001ccc9` |
| `1001ccb5` | `0f b7 45 fc` | `MOVZX EAX,word ptr [EBP + -0x4]` |
| `1001ccb9` | `23 45 0c` | `AND EAX,dword ptr [EBP + 0xc]` |
| `1001ccbc` | `80 7d f4 00` | `CMP byte ptr [EBP + -0xc],0x0` |
| `1001ccc0` | `74 07` | `JZ 0x1001ccc9` |
| `1001ccc2` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001ccc5` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001ccc9` | `5b` | `POP EBX` |
| `1001ccca` | `c9` | `LEAVE` |
| `1001cccb` | `c3` | `RET` |
