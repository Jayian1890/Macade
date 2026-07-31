# 1001e8f6 `x_ismbbtype_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e8f6 |
| `name` | x_ismbbtype_l |
| `namespace` | Global |
| `signature` | int __cdecl x_ismbbtype_l(localeinfo_struct * param_1, uint param_2, int param_3, int param_4) |
| `size_bytes` | 83 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?x_ismbbtype_l@@YAHPAUlocaleinfo_struct@@IHH@Z, x_ismbbtype_l |

## Decompiled C

```c

/* Library Function - Single Match
    int __cdecl x_ismbbtype_l(struct localeinfo_struct *,unsigned int,int,int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl x_ismbbtype_l(localeinfo_struct *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,param_1);
  if ((*(byte *)(local_10 + 0x1d + (param_2 & 0xff)) & (byte)param_4) == 0) {
    if (param_3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)*(ushort *)(*(int *)(local_14 + 200) + (param_2 & 0xff) * 2) & param_3;
    }
    iVar2 = 0;
    if (uVar1 == 0) goto LAB_1001e93a;
  }
  iVar2 = 1;
LAB_1001e93a:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e904` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |

## Callers

| From | Function |
| --- | --- |
| `1001e957` | __ismbblead |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e8f6` | `8b ff` | `MOV EDI,EDI` |
| `1001e8f8` | `55` | `PUSH EBP` |
| `1001e8f9` | `8b ec` | `MOV EBP,ESP` |
| `1001e8fb` | `83 ec 10` | `SUB ESP,0x10` |
| `1001e8fe` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e901` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001e904` | `e8 ad 69 ff ff` | `CALL 0x100152b6` |
| `1001e909` | `0f b6 45 0c` | `MOVZX EAX,byte ptr [EBP + 0xc]` |
| `1001e90d` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `1001e910` | `8a 55 14` | `MOV DL,byte ptr [EBP + 0x14]` |
| `1001e913` | `84 54 01 1d` | `TEST byte ptr [ECX + EAX*0x1 + 0x1d],DL` |
| `1001e917` | `75 1e` | `JNZ 0x1001e937` |
| `1001e919` | `83 7d 10 00` | `CMP dword ptr [EBP + 0x10],0x0` |
| `1001e91d` | `74 12` | `JZ 0x1001e931` |
| `1001e91f` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001e922` | `8b 89 c8 00 00 00` | `MOV ECX,dword ptr [ECX + 0xc8]` |
| `1001e928` | `0f b7 04 41` | `MOVZX EAX,word ptr [ECX + EAX*0x2]` |
| `1001e92c` | `23 45 10` | `AND EAX,dword ptr [EBP + 0x10]` |
| `1001e92f` | `eb 02` | `JMP 0x1001e933` |
| `1001e931` | `33 c0` | `XOR EAX,EAX` |
| `1001e933` | `85 c0` | `TEST EAX,EAX` |
| `1001e935` | `74 03` | `JZ 0x1001e93a` |
| `1001e937` | `33 c0` | `XOR EAX,EAX` |
| `1001e939` | `40` | `INC EAX` |
| `1001e93a` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1001e93e` | `74 07` | `JZ 0x1001e947` |
| `1001e940` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001e943` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001e947` | `c9` | `LEAVE` |
| `1001e948` | `c3` | `RET` |
