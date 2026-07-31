# 1001e71d `__mbtowc_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e71d |
| `name` | __mbtowc_l |
| `namespace` | Global |
| `signature` | int __cdecl __mbtowc_l(wchar_t * _DstCh, char * _SrcCh, size_t _SrcSizeInBytes, _locale_t _Locale) |
| `size_bytes` | 279 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbtowc_l |

## Decompiled C

```c

/* Library Function - Single Match
    __mbtowc_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbtowc_l(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale)

{
  wchar_t *pwVar1;
  int iVar2;
  int *piVar3;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  if ((_SrcCh != (char *)0x0) && (_SrcSizeInBytes != 0)) {
    if (*_SrcCh != '\0') {
      _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,_Locale);
      if ((local_14.locinfo)->lc_category[0].wlocale != (wchar_t *)0x0) {
        iVar2 = __isleadbyte_l((uint)(byte)*_SrcCh,&local_14);
        if (iVar2 == 0) {
          iVar2 = MultiByteToWideChar((local_14.locinfo)->lc_codepage,9,_SrcCh,1,_DstCh,
                                      (uint)(_DstCh != (wchar_t *)0x0));
          if (iVar2 != 0) goto LAB_1001e76c;
        }
        else {
          pwVar1 = (local_14.locinfo)->locale_name[3];
          if ((((1 < (int)pwVar1) && ((int)pwVar1 <= (int)_SrcSizeInBytes)) &&
              (iVar2 = MultiByteToWideChar((local_14.locinfo)->lc_codepage,9,_SrcCh,(int)pwVar1,
                                           _DstCh,(uint)(_DstCh != (wchar_t *)0x0)), iVar2 != 0)) ||
             (((local_14.locinfo)->locale_name[3] <= _SrcSizeInBytes && (_SrcCh[1] != '\0')))) {
            pwVar1 = (local_14.locinfo)->locale_name[3];
            if (local_8 == '\0') {
              return (int)pwVar1;
            }
            *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
            return (int)pwVar1;
          }
        }
        piVar3 = __errno();
        *piVar3 = 0x2a;
        if (local_8 != '\0') {
          *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
        }
        return -1;
      }
      if (_DstCh != (wchar_t *)0x0) {
        *_DstCh = (ushort)(byte)*_SrcCh;
      }
LAB_1001e76c:
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      return 1;
    }
    if (_DstCh != (wchar_t *)0x0) {
      *_DstCh = L'\0';
    }
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e751` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001e785` | `1001c708` | `UNCONDITIONAL_CALL` | __isleadbyte_l | `1001c708` |
| `1001e7b6` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001e7ee` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e824` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |

## Callers

| From | Function |
| --- | --- |
| `1001e844` | _mbtowc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001e7b6` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |
| `1001e824` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e71d` | `8b ff` | `MOV EDI,EDI` |
| `1001e71f` | `55` | `PUSH EBP` |
| `1001e720` | `8b ec` | `MOV EBP,ESP` |
| `1001e722` | `83 ec 10` | `SUB ESP,0x10` |
| `1001e725` | `53` | `PUSH EBX` |
| `1001e726` | `56` | `PUSH ESI` |
| `1001e727` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001e72a` | `33 db` | `XOR EBX,EBX` |
| `1001e72c` | `3b f3` | `CMP ESI,EBX` |
| `1001e72e` | `74 15` | `JZ 0x1001e745` |
| `1001e730` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001e733` | `74 10` | `JZ 0x1001e745` |
| `1001e735` | `38 1e` | `CMP byte ptr [ESI],BL` |
| `1001e737` | `75 12` | `JNZ 0x1001e74b` |
| `1001e739` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001e73c` | `3b c3` | `CMP EAX,EBX` |
| `1001e73e` | `74 05` | `JZ 0x1001e745` |
| `1001e740` | `33 c9` | `XOR ECX,ECX` |
| `1001e742` | `66 89 08` | `MOV word ptr [EAX],CX` |
| `1001e745` | `33 c0` | `XOR EAX,EAX` |
| `1001e747` | `5e` | `POP ESI` |
| `1001e748` | `5b` | `POP EBX` |
| `1001e749` | `c9` | `LEAVE` |
| `1001e74a` | `c3` | `RET` |
| `1001e74b` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001e74e` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001e751` | `e8 60 6b ff ff` | `CALL 0x100152b6` |
| `1001e756` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001e759` | `39 58 14` | `CMP dword ptr [EAX + 0x14],EBX` |
| `1001e75c` | `75 1f` | `JNZ 0x1001e77d` |
| `1001e75e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001e761` | `3b c3` | `CMP EAX,EBX` |
| `1001e763` | `74 07` | `JZ 0x1001e76c` |
| `1001e765` | `66 0f b6 0e` | `MOVZX CX,byte ptr [ESI]` |
| `1001e769` | `66 89 08` | `MOV word ptr [EAX],CX` |
| `1001e76c` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e76f` | `74 07` | `JZ 0x1001e778` |
| `1001e771` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001e774` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001e778` | `33 c0` | `XOR EAX,EAX` |
| `1001e77a` | `40` | `INC EAX` |
| `1001e77b` | `eb ca` | `JMP 0x1001e747` |
| `1001e77d` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001e780` | `50` | `PUSH EAX` |
| `1001e781` | `0f b6 06` | `MOVZX EAX,byte ptr [ESI]` |
| `1001e784` | `50` | `PUSH EAX` |
| `1001e785` | `e8 7e df ff ff` | `CALL 0x1001c708` |
| `1001e78a` | `59` | `POP ECX` |
| `1001e78b` | `59` | `POP ECX` |
| `1001e78c` | `85 c0` | `TEST EAX,EAX` |
| `1001e78e` | `74 7d` | `JZ 0x1001e80d` |
| `1001e790` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001e793` | `8b 88 ac 00 00 00` | `MOV ECX,dword ptr [EAX + 0xac]` |
| `1001e799` | `83 f9 01` | `CMP ECX,0x1` |
| `1001e79c` | `7e 25` | `JLE 0x1001e7c3` |
| `1001e79e` | `39 4d 10` | `CMP dword ptr [EBP + 0x10],ECX` |
| `1001e7a1` | `7c 20` | `JL 0x1001e7c3` |
| `1001e7a3` | `33 d2` | `XOR EDX,EDX` |
| `1001e7a5` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001e7a8` | `0f 95 c2` | `SETNZ DL` |
| `1001e7ab` | `52` | `PUSH EDX` |
| `1001e7ac` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e7af` | `51` | `PUSH ECX` |
| `1001e7b0` | `56` | `PUSH ESI` |
| `1001e7b1` | `6a 09` | `PUSH 0x9` |
| `1001e7b3` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1001e7b6` | `ff 15 60 e0 02 10` | `CALL dword ptr [0x1002e060]` |
| `1001e7bc` | `85 c0` | `TEST EAX,EAX` |
| `1001e7be` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001e7c1` | `75 10` | `JNZ 0x1001e7d3` |
| `1001e7c3` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001e7c6` | `3b 88 ac 00 00 00` | `CMP ECX,dword ptr [EAX + 0xac]` |
| `1001e7cc` | `72 20` | `JC 0x1001e7ee` |
| `1001e7ce` | `38 5e 01` | `CMP byte ptr [ESI + 0x1],BL` |
| `1001e7d1` | `74 1b` | `JZ 0x1001e7ee` |
| `1001e7d3` | `8b 80 ac 00 00 00` | `MOV EAX,dword ptr [EAX + 0xac]` |
| `1001e7d9` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e7dc` | `0f 84 65 ff ff ff` | `JZ 0x1001e747` |
| `1001e7e2` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001e7e5` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001e7e9` | `e9 59 ff ff ff` | `JMP 0x1001e747` |
| `1001e7ee` | `e8 16 69 ff ff` | `CALL 0x10015109` |
| `1001e7f3` | `c7 00 2a 00 00 00` | `MOV dword ptr [EAX],0x2a` |
| `1001e7f9` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e7fc` | `74 07` | `JZ 0x1001e805` |
| `1001e7fe` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001e801` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001e805` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001e808` | `e9 3a ff ff ff` | `JMP 0x1001e747` |
| `1001e80d` | `33 c0` | `XOR EAX,EAX` |
| `1001e80f` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001e812` | `0f 95 c0` | `SETNZ AL` |
| `1001e815` | `50` | `PUSH EAX` |
| `1001e816` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e819` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001e81c` | `6a 01` | `PUSH 0x1` |
| `1001e81e` | `56` | `PUSH ESI` |
| `1001e81f` | `6a 09` | `PUSH 0x9` |
| `1001e821` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1001e824` | `ff 15 60 e0 02 10` | `CALL dword ptr [0x1002e060]` |
| `1001e82a` | `85 c0` | `TEST EAX,EAX` |
| `1001e82c` | `0f 85 3a ff ff ff` | `JNZ 0x1001e76c` |
| `1001e832` | `eb ba` | `JMP 0x1001e7ee` |
