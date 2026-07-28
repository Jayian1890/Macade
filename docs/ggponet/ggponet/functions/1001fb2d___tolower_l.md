# 1001fb2d `__tolower_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001fb2d |
| `name` | __tolower_l |
| `namespace` | Global |
| `signature` | int __cdecl __tolower_l(int _C, _locale_t _Locale) |
| `size_bytes` | 277 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __tolower_l |

## Decompiled C

```c

/* Library Function - Single Match
    __tolower_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __tolower_l(int _C,_locale_t _Locale)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  CHAR CVar5;
  localeinfo_struct local_1c;
  int local_14;
  char local_10;
  byte local_c;
  undefined1 local_b;
  CHAR local_8;
  CHAR local_7;
  undefined1 local_6;
  
  iVar1 = _C;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_1c,_Locale);
  if ((uint)_C < 0x100) {
    if ((int)(local_1c.locinfo)->locale_name[3] < 2) {
      uVar2 = *(ushort *)(local_1c.locinfo[1].lc_category[0].locale + _C * 2) & 1;
    }
    else {
      uVar2 = __isctype_l(_C,1,&local_1c);
    }
    if (uVar2 == 0) {
LAB_1001fb8e:
      if (local_10 == '\0') {
        return iVar1;
      }
      *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)local_1c.locinfo[1].lc_category[0].wlocale + _C);
  }
  else {
    CVar5 = (CHAR)_C;
    if (((int)(local_1c.locinfo)->locale_name[3] < 2) ||
       (iVar3 = __isleadbyte_l(_C >> 8 & 0xff,&local_1c), iVar3 == 0)) {
      piVar4 = __errno();
      *piVar4 = 0x2a;
      local_7 = '\0';
      iVar3 = 1;
      local_8 = CVar5;
    }
    else {
      _C._0_1_ = (CHAR)((uint)_C >> 8);
      local_8 = (CHAR)_C;
      local_6 = 0;
      iVar3 = 2;
      local_7 = CVar5;
    }
    iVar3 = ___crtLCMapStringA(&local_1c,(local_1c.locinfo)->lc_category[0].wlocale,0x100,&local_8,
                               iVar3,(LPSTR)&local_c,3,(local_1c.locinfo)->lc_codepage,1);
    if (iVar3 == 0) goto LAB_1001fb8e;
    uVar2 = (uint)local_c;
    if (iVar3 != 1) {
      uVar2 = (uint)CONCAT11(local_c,local_b);
    }
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return uVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001fb3d` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001fb61` | `1001cc14` | `UNCONDITIONAL_CALL` | __isctype_l | `1001cc14` |
| `1001fbc2` | `1001c708` | `UNCONDITIONAL_CALL` | __isleadbyte_l | `1001c708` |
| `1001fbdf` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001fc0f` | `1001ed18` | `UNCONDITIONAL_CALL` | ___crtLCMapStringA | `1001ed18` |

## Callers

| From | Function |
| --- | --- |
| `1001f729` | __strnicmp_l |
| `1001f73b` | __strnicmp_l |
| `1001fc65` | _tolower |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001fb2d` | `8b ff` | `MOV EDI,EDI` |
| `1001fb2f` | `55` | `PUSH EBP` |
| `1001fb30` | `8b ec` | `MOV EBP,ESP` |
| `1001fb32` | `83 ec 18` | `SUB ESP,0x18` |
| `1001fb35` | `53` | `PUSH EBX` |
| `1001fb36` | `56` | `PUSH ESI` |
| `1001fb37` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001fb3a` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1001fb3d` | `e8 74 57 ff ff` | `CALL 0x100152b6` |
| `1001fb42` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1001fb45` | `be 00 01 00 00` | `MOV ESI,0x100` |
| `1001fb4a` | `3b de` | `CMP EBX,ESI` |
| `1001fb4c` | `73 54` | `JNC 0x1001fba2` |
| `1001fb4e` | `8b 4d e8` | `MOV ECX,dword ptr [EBP + -0x18]` |
| `1001fb51` | `83 b9 ac 00 00 00 01` | `CMP dword ptr [ECX + 0xac],0x1` |
| `1001fb58` | `7e 14` | `JLE 0x1001fb6e` |
| `1001fb5a` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001fb5d` | `50` | `PUSH EAX` |
| `1001fb5e` | `6a 01` | `PUSH 0x1` |
| `1001fb60` | `53` | `PUSH EBX` |
| `1001fb61` | `e8 ae d0 ff ff` | `CALL 0x1001cc14` |
| `1001fb66` | `8b 4d e8` | `MOV ECX,dword ptr [EBP + -0x18]` |
| `1001fb69` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001fb6c` | `eb 0d` | `JMP 0x1001fb7b` |
| `1001fb6e` | `8b 81 c8 00 00 00` | `MOV EAX,dword ptr [ECX + 0xc8]` |
| `1001fb74` | `0f b7 04 58` | `MOVZX EAX,word ptr [EAX + EBX*0x2]` |
| `1001fb78` | `83 e0 01` | `AND EAX,0x1` |
| `1001fb7b` | `85 c0` | `TEST EAX,EAX` |
| `1001fb7d` | `74 0f` | `JZ 0x1001fb8e` |
| `1001fb7f` | `8b 81 cc 00 00 00` | `MOV EAX,dword ptr [ECX + 0xcc]` |
| `1001fb85` | `0f b6 04 18` | `MOVZX EAX,byte ptr [EAX + EBX*0x1]` |
| `1001fb89` | `e9 a3 00 00 00` | `JMP 0x1001fc31` |
| `1001fb8e` | `80 7d f4 00` | `CMP byte ptr [EBP + -0xc],0x0` |
| `1001fb92` | `74 07` | `JZ 0x1001fb9b` |
| `1001fb94` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001fb97` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001fb9b` | `8b c3` | `MOV EAX,EBX` |
| `1001fb9d` | `e9 9c 00 00 00` | `JMP 0x1001fc3e` |
| `1001fba2` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1001fba5` | `83 b8 ac 00 00 00 01` | `CMP dword ptr [EAX + 0xac],0x1` |
| `1001fbac` | `7e 31` | `JLE 0x1001fbdf` |
| `1001fbae` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `1001fbb1` | `c1 7d 08 08` | `SAR dword ptr [EBP + 0x8],0x8` |
| `1001fbb5` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001fbb8` | `50` | `PUSH EAX` |
| `1001fbb9` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001fbbc` | `25 ff 00 00 00` | `AND EAX,0xff` |
| `1001fbc1` | `50` | `PUSH EAX` |
| `1001fbc2` | `e8 41 cb ff ff` | `CALL 0x1001c708` |
| `1001fbc7` | `59` | `POP ECX` |
| `1001fbc8` | `59` | `POP ECX` |
| `1001fbc9` | `85 c0` | `TEST EAX,EAX` |
| `1001fbcb` | `74 12` | `JZ 0x1001fbdf` |
| `1001fbcd` | `8a 45 08` | `MOV AL,byte ptr [EBP + 0x8]` |
| `1001fbd0` | `6a 02` | `PUSH 0x2` |
| `1001fbd2` | `88 45 fc` | `MOV byte ptr [EBP + -0x4],AL` |
| `1001fbd5` | `88 5d fd` | `MOV byte ptr [EBP + -0x3],BL` |
| `1001fbd8` | `c6 45 fe 00` | `MOV byte ptr [EBP + -0x2],0x0` |
| `1001fbdc` | `59` | `POP ECX` |
| `1001fbdd` | `eb 15` | `JMP 0x1001fbf4` |
| `1001fbdf` | `e8 25 55 ff ff` | `CALL 0x10015109` |
| `1001fbe4` | `c7 00 2a 00 00 00` | `MOV dword ptr [EAX],0x2a` |
| `1001fbea` | `33 c9` | `XOR ECX,ECX` |
| `1001fbec` | `88 5d fc` | `MOV byte ptr [EBP + -0x4],BL` |
| `1001fbef` | `c6 45 fd 00` | `MOV byte ptr [EBP + -0x3],0x0` |
| `1001fbf3` | `41` | `INC ECX` |
| `1001fbf4` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1001fbf7` | `6a 01` | `PUSH 0x1` |
| `1001fbf9` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1001fbfc` | `8d 55 f8` | `LEA EDX,[EBP + -0x8]` |
| `1001fbff` | `6a 03` | `PUSH 0x3` |
| `1001fc01` | `52` | `PUSH EDX` |
| `1001fc02` | `51` | `PUSH ECX` |
| `1001fc03` | `8d 4d fc` | `LEA ECX,[EBP + -0x4]` |
| `1001fc06` | `51` | `PUSH ECX` |
| `1001fc07` | `56` | `PUSH ESI` |
| `1001fc08` | `ff 70 14` | `PUSH dword ptr [EAX + 0x14]` |
| `1001fc0b` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001fc0e` | `50` | `PUSH EAX` |
| `1001fc0f` | `e8 04 f1 ff ff` | `CALL 0x1001ed18` |
| `1001fc14` | `83 c4 24` | `ADD ESP,0x24` |
| `1001fc17` | `85 c0` | `TEST EAX,EAX` |
| `1001fc19` | `0f 84 6f ff ff ff` | `JZ 0x1001fb8e` |
| `1001fc1f` | `83 f8 01` | `CMP EAX,0x1` |
| `1001fc22` | `0f b6 45 f8` | `MOVZX EAX,byte ptr [EBP + -0x8]` |
| `1001fc26` | `74 09` | `JZ 0x1001fc31` |
| `1001fc28` | `0f b6 4d f9` | `MOVZX ECX,byte ptr [EBP + -0x7]` |
| `1001fc2c` | `c1 e0 08` | `SHL EAX,0x8` |
| `1001fc2f` | `0b c1` | `OR EAX,ECX` |
| `1001fc31` | `80 7d f4 00` | `CMP byte ptr [EBP + -0xc],0x0` |
| `1001fc35` | `74 07` | `JZ 0x1001fc3e` |
| `1001fc37` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001fc3a` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001fc3e` | `5e` | `POP ESI` |
| `1001fc3f` | `5b` | `POP EBX` |
| `1001fc40` | `c9` | `LEAVE` |
| `1001fc41` | `c3` | `RET` |
