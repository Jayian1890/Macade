# 1002b6df `FID_conflict:__ld12tod`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002b6df |
| `name` | FID_conflict:__ld12tod |
| `namespace` | Global |
| `signature` | INTRNCVT_STATUS __cdecl FID_conflict:__ld12tod(_LDBL12 * _Ifp, _CRT_DOUBLE * _D) |
| `size_bytes` | 1348 |
| `stack_frame_size` | 60 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | FID_conflict:__ld12tod, __ld12tod, __ld12tof |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 2008 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  undefined4 uVar1;
  int iVar2;
  INTRNCVT_STATUS IVar3;
  int iVar4;
  byte bVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  _LDBL12 *p_Var9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  uint local_24 [4];
  uint local_14;
  uint local_10;
  int local_c;
  _LDBL12 *local_8;
  
  local_24[3] = *(ushort *)(_Ifp->ld12 + 10) & 0x8000;
  uVar10 = *(uint *)(_Ifp->ld12 + 6);
  local_24[0] = uVar10;
  uVar1 = *(undefined4 *)(_Ifp->ld12 + 2);
  uVar11 = *(ushort *)(_Ifp->ld12 + 10) & 0x7fff;
  iVar12 = uVar11 - 0x3fff;
  iVar2 = (uint)*(ushort *)_Ifp->ld12 << 0x10;
  local_24[1] = uVar1;
  local_24[2] = iVar2;
  if (iVar12 == -0x3fff) {
    iVar12 = 0;
    iVar2 = 0;
    do {
      if (local_24[iVar2] != 0) {
        local_24[0] = 0;
        local_24[1] = 0;
        IVar3 = INTRNCVT_UNDERFLOW;
        goto LAB_1002bbe0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    IVar3 = INTRNCVT_OK;
  }
  else {
    _Ifp = (_LDBL12 *)0x0;
    iVar13 = DAT_10038730 - 1;
    iVar4 = (int)(DAT_10038730 + ((int)DAT_10038730 >> 0x1f & 0x1fU)) >> 5;
    uVar8 = DAT_10038730 & 0x8000001f;
    local_14 = iVar12;
    local_10 = iVar4;
    if ((int)uVar8 < 0) {
      uVar8 = (uVar8 - 1 | 0xffffffe0) + 1;
    }
    puVar7 = local_24 + iVar4;
    bVar5 = (byte)(0x1f - uVar8);
    local_c = 0x1f - uVar8;
    if ((*puVar7 & 1 << (bVar5 & 0x1f)) != 0) {
      uVar8 = local_24[iVar4] & ~(-1 << (bVar5 & 0x1f));
      while( true ) {
        if (uVar8 != 0) {
          iVar4 = (int)(iVar13 + (iVar13 >> 0x1f & 0x1fU)) >> 5;
          local_8 = (_LDBL12 *)0x0;
          p_Var9 = (_LDBL12 *)(1 << (0x1f - ((byte)iVar13 & 0x1f) & 0x1f));
          puVar6 = local_24 + iVar4;
          _Ifp = (_LDBL12 *)(p_Var9->ld12 + *puVar6);
          if (_Ifp < (_LDBL12 *)*puVar6) goto LAB_1002b814;
          bVar14 = _Ifp < p_Var9;
          do {
            local_8 = (_LDBL12 *)0x0;
            if (!bVar14) goto LAB_1002b81b;
LAB_1002b814:
            do {
              local_8 = (_LDBL12 *)0x1;
LAB_1002b81b:
              iVar4 = iVar4 + -1;
              *puVar6 = (uint)_Ifp;
              if ((iVar4 < 0) || (local_8 == (_LDBL12 *)0x0)) {
                _Ifp = local_8;
                goto LAB_1002b829;
              }
              local_8 = (_LDBL12 *)0x0;
              puVar6 = local_24 + iVar4;
              _Ifp = (_LDBL12 *)(((_LDBL12 *)*puVar6)->ld12 + 1);
            } while (_Ifp < (_LDBL12 *)*puVar6);
            bVar14 = _Ifp == (_LDBL12 *)0x0;
          } while( true );
        }
        iVar4 = iVar4 + 1;
        if (2 < iVar4) break;
        uVar8 = local_24[iVar4];
      }
    }
LAB_1002b829:
    *puVar7 = *puVar7 & -1 << ((byte)local_c & 0x1f);
    iVar4 = local_10 + 1;
    if (iVar4 < 3) {
      puVar7 = local_24 + iVar4;
      for (iVar13 = 3 - iVar4; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
    if (_Ifp != (_LDBL12 *)0x0) {
      iVar12 = uVar11 - 0x3ffe;
    }
    if (iVar12 < (int)(DAT_1003872c - DAT_10038730)) {
      local_24[0] = 0;
      local_24[1] = 0;
    }
    else {
      if (DAT_1003872c < iVar12) {
        if (iVar12 < DAT_10038728) {
          local_24[0] = local_24[0] & 0x7fffffff;
          iVar12 = iVar12 + DAT_1003873c;
          iVar2 = (int)(DAT_10038734 + ((int)DAT_10038734 >> 0x1f & 0x1fU)) >> 5;
          uVar10 = DAT_10038734 & 0x8000001f;
          if ((int)uVar10 < 0) {
            uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
          }
          local_10 = 0;
          _Ifp = (_LDBL12 *)0x0;
          local_8 = (_LDBL12 *)(0x20 - uVar10);
          do {
            local_14 = local_24[(int)_Ifp] & ~(-1 << ((byte)uVar10 & 0x1f));
            local_24[(int)_Ifp] = local_24[(int)_Ifp] >> ((byte)uVar10 & 0x1f) | local_10;
            _Ifp = (_LDBL12 *)(_Ifp->ld12 + 1);
            local_10 = local_14 << ((byte)(0x20 - uVar10) & 0x1f);
          } while ((int)_Ifp < 3);
          iVar4 = 2;
          puVar7 = local_24 + (2 - iVar2);
          do {
            if (iVar4 < iVar2) {
              local_24[iVar4] = 0;
            }
            else {
              local_24[iVar4] = *puVar7;
            }
            iVar4 = iVar4 + -1;
            puVar7 = puVar7 + -1;
          } while (-1 < iVar4);
          IVar3 = INTRNCVT_OK;
        }
        else {
          local_24[1] = 0;
          local_24[2] = 0;
          local_24[0] = 0x80000000;
          iVar12 = (int)(DAT_10038734 + ((int)DAT_10038734 >> 0x1f & 0x1fU)) >> 5;
          uVar10 = DAT_10038734 & 0x8000001f;
          if ((int)uVar10 < 0) {
            uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
          }
          local_10 = 0;
          _Ifp = (_LDBL12 *)0x0;
          local_8 = (_LDBL12 *)(0x20 - uVar10);
          do {
            uVar11 = local_24[(int)_Ifp];
            local_14 = uVar11 & ~(-1 << ((byte)uVar10 & 0x1f));
            local_24[(int)_Ifp] = uVar11 >> ((byte)uVar10 & 0x1f) | local_10;
            _Ifp = (_LDBL12 *)(_Ifp->ld12 + 1);
            local_10 = local_14 << ((byte)(0x20 - uVar10) & 0x1f);
          } while ((int)_Ifp < 3);
          iVar2 = 2;
          puVar7 = local_24 + (2 - iVar12);
          do {
            if (iVar2 < iVar12) {
              local_24[iVar2] = 0;
            }
            else {
              local_24[iVar2] = *puVar7;
            }
            iVar2 = iVar2 + -1;
            puVar7 = puVar7 + -1;
          } while (-1 < iVar2);
          iVar12 = DAT_1003873c + DAT_10038728;
          IVar3 = INTRNCVT_OVERFLOW;
        }
        goto LAB_1002bbe0;
      }
      local_14 = DAT_1003872c - local_14;
      local_24[0] = uVar10;
      local_24[1] = uVar1;
      iVar12 = (int)(local_14 + ((int)local_14 >> 0x1f & 0x1fU)) >> 5;
      uVar10 = local_14 & 0x8000001f;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
      }
      local_10 = 0;
      _Ifp = (_LDBL12 *)0x0;
      local_8 = (_LDBL12 *)(0x20 - uVar10);
      do {
        uVar11 = local_24[(int)_Ifp];
        local_14 = uVar11 & ~(-1 << ((byte)uVar10 & 0x1f));
        local_24[(int)_Ifp] = uVar11 >> ((byte)uVar10 & 0x1f) | local_10;
        _Ifp = (_LDBL12 *)(_Ifp->ld12 + 1);
        local_10 = local_14 << ((byte)(0x20 - uVar10) & 0x1f);
      } while ((int)_Ifp < 3);
      iVar2 = 2;
      puVar7 = local_24 + (2 - iVar12);
      do {
        if (iVar2 < iVar12) {
          local_24[iVar2] = 0;
        }
        else {
          local_24[iVar2] = *puVar7;
        }
        iVar2 = iVar2 + -1;
        puVar7 = puVar7 + -1;
      } while (-1 < iVar2);
      iVar2 = DAT_10038730 - 1;
      iVar12 = (int)(DAT_10038730 + ((int)DAT_10038730 >> 0x1f & 0x1fU)) >> 5;
      uVar10 = DAT_10038730 & 0x8000001f;
      local_10 = iVar12;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
      }
      bVar5 = (byte)(0x1f - uVar10);
      puVar7 = local_24 + iVar12;
      local_14 = 0x1f - uVar10;
      if ((*puVar7 & 1 << (bVar5 & 0x1f)) != 0) {
        uVar10 = local_24[iVar12] & ~(-1 << (bVar5 & 0x1f));
        while (uVar10 == 0) {
          iVar12 = iVar12 + 1;
          if (2 < iVar12) goto LAB_1002b9cc;
          uVar10 = local_24[iVar12];
        }
        iVar12 = (int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5;
        bVar14 = false;
        uVar8 = 1 << (0x1f - ((byte)iVar2 & 0x1f) & 0x1f);
        uVar11 = local_24[iVar12];
        uVar10 = uVar11 + uVar8;
        if ((uVar10 < uVar11) || (uVar10 < uVar8)) {
          bVar14 = true;
        }
        local_24[iVar12] = uVar10;
        while ((iVar12 = iVar12 + -1, -1 < iVar12 && (bVar14))) {
          uVar11 = local_24[iVar12];
          uVar10 = uVar11 + 1;
          bVar14 = false;
          if ((uVar10 < uVar11) || (uVar10 == 0)) {
            bVar14 = true;
          }
          local_24[iVar12] = uVar10;
        }
      }
LAB_1002b9cc:
      *puVar7 = *puVar7 & -1 << ((byte)local_14 & 0x1f);
      iVar12 = local_10 + 1;
      if (iVar12 < 3) {
        puVar7 = local_24 + iVar12;
        for (iVar2 = 3 - iVar12; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
      }
      uVar10 = DAT_10038734 + 1;
      iVar12 = (int)(uVar10 + ((int)uVar10 >> 0x1f & 0x1fU)) >> 5;
      uVar10 = uVar10 & 0x8000001f;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
      }
      local_10 = 0;
      _Ifp = (_LDBL12 *)0x0;
      local_8 = (_LDBL12 *)(0x20 - uVar10);
      do {
        uVar11 = local_24[(int)_Ifp];
        local_14 = uVar11 & ~(-1 << ((byte)uVar10 & 0x1f));
        local_24[(int)_Ifp] = uVar11 >> ((byte)uVar10 & 0x1f) | local_10;
        _Ifp = (_LDBL12 *)(_Ifp->ld12 + 1);
        local_10 = local_14 << ((byte)(0x20 - uVar10) & 0x1f);
      } while ((int)_Ifp < 3);
      iVar2 = 2;
      puVar7 = local_24 + (2 - iVar12);
      do {
        if (iVar2 < iVar12) {
          local_24[iVar2] = 0;
        }
        else {
          local_24[iVar2] = *puVar7;
        }
        iVar2 = iVar2 + -1;
        puVar7 = puVar7 + -1;
      } while (-1 < iVar2);
    }
    iVar12 = 0;
    IVar3 = INTRNCVT_UNDERFLOW;
  }
LAB_1002bbe0:
  local_24[0] = iVar12 << (0x1fU - (char)DAT_10038734 & 0x1f) |
                -(uint)(local_24[3] != 0) & 0x80000000 | local_24[0];
  if (DAT_10038738 == 0x40) {
    *(uint *)((int)&_D->x + 4) = local_24[0];
    *(uint *)&_D->x = local_24[1];
  }
  else if (DAT_10038738 == 0x20) {
    *(uint *)&_D->x = local_24[0];
  }
  return IVar3;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002adbb` | FID_conflict:__atoflt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002b759` | `10038730` | `READ` | DAT_10038730 |
| `1002b850` | `1003872c` | `READ` | DAT_1003872c |
| `1002b857` | `10038730` | `READ` | DAT_10038730 |
| `1002b90a` | `10038730` | `READ` | DAT_10038730 |
| `1002b9ec` | `10038734` | `READ` | DAT_10038734 |
| `1002ba85` | `10038728` | `READ` | DAT_10038728 |
| `1002ba8b` | `10038734` | `READ` | DAT_10038734 |
| `1002bb2e` | `10038728` | `READ` | DAT_10038728 |
| `1002bb33` | `1003873c` | `READ` | DAT_1003873c |
| `1002bb44` | `1003873c` | `READ` | DAT_1003873c |
| `1002bbe3` | `10038734` | `READ` | DAT_10038734 |
| `1002bbfa` | `10038738` | `READ` | DAT_10038738 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002b6df` | `8b ff` | `MOV EDI,EDI` |
| `1002b6e1` | `55` | `PUSH EBP` |
| `1002b6e2` | `8b ec` | `MOV EBP,ESP` |
| `1002b6e4` | `83 ec 2c` | `SUB ESP,0x2c` |
| `1002b6e7` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002b6ea` | `0f b7 48 0a` | `MOVZX ECX,word ptr [EAX + 0xa]` |
| `1002b6ee` | `53` | `PUSH EBX` |
| `1002b6ef` | `8b d9` | `MOV EBX,ECX` |
| `1002b6f1` | `81 e1 00 80 00 00` | `AND ECX,0x8000` |
| `1002b6f7` | `89 4d ec` | `MOV dword ptr [EBP + -0x14],ECX` |
| `1002b6fa` | `8b 48 06` | `MOV ECX,dword ptr [EAX + 0x6]` |
| `1002b6fd` | `89 4d e0` | `MOV dword ptr [EBP + -0x20],ECX` |
| `1002b700` | `8b 48 02` | `MOV ECX,dword ptr [EAX + 0x2]` |
| `1002b703` | `0f b7 00` | `MOVZX EAX,word ptr [EAX]` |
| `1002b706` | `81 e3 ff 7f 00 00` | `AND EBX,0x7fff` |
| `1002b70c` | `81 eb ff 3f 00 00` | `SUB EBX,0x3fff` |
| `1002b712` | `c1 e0 10` | `SHL EAX,0x10` |
| `1002b715` | `57` | `PUSH EDI` |
| `1002b716` | `89 4d e4` | `MOV dword ptr [EBP + -0x1c],ECX` |
| `1002b719` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1002b71c` | `81 fb 01 c0 ff ff` | `CMP EBX,0xffffc001` |
| `1002b722` | `75 27` | `JNZ 0x1002b74b` |
| `1002b724` | `33 db` | `XOR EBX,EBX` |
| `1002b726` | `33 c0` | `XOR EAX,EAX` |
| `1002b728` | `39 5c 85 e0` | `CMP dword ptr [EBP + EAX*0x4 + -0x20],EBX` |
| `1002b72c` | `75 0d` | `JNZ 0x1002b73b` |
| `1002b72e` | `40` | `INC EAX` |
| `1002b72f` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b732` | `7c f4` | `JL 0x1002b728` |
| `1002b734` | `33 c0` | `XOR EAX,EAX` |
| `1002b736` | `e9 a5 04 00 00` | `JMP 0x1002bbe0` |
| `1002b73b` | `33 c0` | `XOR EAX,EAX` |
| `1002b73d` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b740` | `ab` | `STOSD ES:EDI` |
| `1002b741` | `ab` | `STOSD ES:EDI` |
| `1002b742` | `6a 02` | `PUSH 0x2` |
| `1002b744` | `ab` | `STOSD ES:EDI` |
| `1002b745` | `58` | `POP EAX` |
| `1002b746` | `e9 95 04 00 00` | `JMP 0x1002bbe0` |
| `1002b74b` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b74f` | `56` | `PUSH ESI` |
| `1002b750` | `8d 75 e0` | `LEA ESI,[EBP + -0x20]` |
| `1002b753` | `8d 7d d4` | `LEA EDI,[EBP + -0x2c]` |
| `1002b756` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b757` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b758` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b759` | `8b 35 30 87 03 10` | `MOV ESI,dword ptr [0x10038730]` |
| `1002b75f` | `4e` | `DEC ESI` |
| `1002b760` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `1002b763` | `8b c1` | `MOV EAX,ECX` |
| `1002b765` | `99` | `CDQ` |
| `1002b766` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b769` | `03 c2` | `ADD EAX,EDX` |
| `1002b76b` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b76e` | `8b d1` | `MOV EDX,ECX` |
| `1002b770` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b776` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `1002b779` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002b77c` | `79 05` | `JNS 0x1002b783` |
| `1002b77e` | `4a` | `DEC EDX` |
| `1002b77f` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b782` | `42` | `INC EDX` |
| `1002b783` | `8d 7c 85 e0` | `LEA EDI,[EBP + EAX*0x4 + -0x20]` |
| `1002b787` | `6a 1f` | `PUSH 0x1f` |
| `1002b789` | `33 c0` | `XOR EAX,EAX` |
| `1002b78b` | `59` | `POP ECX` |
| `1002b78c` | `2b ca` | `SUB ECX,EDX` |
| `1002b78e` | `40` | `INC EAX` |
| `1002b78f` | `d3 e0` | `SHL EAX,CL` |
| `1002b791` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1002b794` | `85 07` | `TEST dword ptr [EDI],EAX` |
| `1002b796` | `0f 84 8d 00 00 00` | `JZ 0x1002b829` |
| `1002b79c` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002b79f` | `83 ca ff` | `OR EDX,0xffffffff` |
| `1002b7a2` | `d3 e2` | `SHL EDX,CL` |
| `1002b7a4` | `f7 d2` | `NOT EDX` |
| `1002b7a6` | `85 54 85 e0` | `TEST dword ptr [EBP + EAX*0x4 + -0x20],EDX` |
| `1002b7aa` | `eb 05` | `JMP 0x1002b7b1` |
| `1002b7ac` | `83 7c 85 e0 00` | `CMP dword ptr [EBP + EAX*0x4 + -0x20],0x0` |
| `1002b7b1` | `75 08` | `JNZ 0x1002b7bb` |
| `1002b7b3` | `40` | `INC EAX` |
| `1002b7b4` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b7b7` | `7c f3` | `JL 0x1002b7ac` |
| `1002b7b9` | `eb 6e` | `JMP 0x1002b829` |
| `1002b7bb` | `8b c6` | `MOV EAX,ESI` |
| `1002b7bd` | `99` | `CDQ` |
| `1002b7be` | `6a 1f` | `PUSH 0x1f` |
| `1002b7c0` | `59` | `POP ECX` |
| `1002b7c1` | `23 d1` | `AND EDX,ECX` |
| `1002b7c3` | `03 c2` | `ADD EAX,EDX` |
| `1002b7c5` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b7c8` | `81 e6 1f 00 00 80` | `AND ESI,0x8000001f` |
| `1002b7ce` | `79 05` | `JNS 0x1002b7d5` |
| `1002b7d0` | `4e` | `DEC ESI` |
| `1002b7d1` | `83 ce e0` | `OR ESI,0xffffffe0` |
| `1002b7d4` | `46` | `INC ESI` |
| `1002b7d5` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1002b7d9` | `2b ce` | `SUB ECX,ESI` |
| `1002b7db` | `33 d2` | `XOR EDX,EDX` |
| `1002b7dd` | `42` | `INC EDX` |
| `1002b7de` | `d3 e2` | `SHL EDX,CL` |
| `1002b7e0` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b7e4` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b7e6` | `03 f2` | `ADD ESI,EDX` |
| `1002b7e8` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `1002b7eb` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b7ed` | `39 75 08` | `CMP dword ptr [EBP + 0x8],ESI` |
| `1002b7f0` | `72 22` | `JC 0x1002b814` |
| `1002b7f2` | `39 55 08` | `CMP dword ptr [EBP + 0x8],EDX` |
| `1002b7f5` | `eb 1b` | `JMP 0x1002b812` |
| `1002b7f7` | `85 c9` | `TEST ECX,ECX` |
| `1002b7f9` | `74 2b` | `JZ 0x1002b826` |
| `1002b7fb` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1002b7ff` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b803` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `1002b805` | `8d 72 01` | `LEA ESI,[EDX + 0x1]` |
| `1002b808` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `1002b80b` | `3b f2` | `CMP ESI,EDX` |
| `1002b80d` | `72 05` | `JC 0x1002b814` |
| `1002b80f` | `83 fe 01` | `CMP ESI,0x1` |
| `1002b812` | `73 07` | `JNC 0x1002b81b` |
| `1002b814` | `c7 45 fc 01 00 00 00` | `MOV dword ptr [EBP + -0x4],0x1` |
| `1002b81b` | `48` | `DEC EAX` |
| `1002b81c` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `1002b81f` | `89 11` | `MOV dword ptr [ECX],EDX` |
| `1002b821` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b824` | `79 d1` | `JNS 0x1002b7f7` |
| `1002b826` | `89 4d 08` | `MOV dword ptr [EBP + 0x8],ECX` |
| `1002b829` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1002b82c` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1002b82f` | `d3 e0` | `SHL EAX,CL` |
| `1002b831` | `21 07` | `AND dword ptr [EDI],EAX` |
| `1002b833` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002b836` | `40` | `INC EAX` |
| `1002b837` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b83a` | `7d 0d` | `JGE 0x1002b849` |
| `1002b83c` | `6a 03` | `PUSH 0x3` |
| `1002b83e` | `59` | `POP ECX` |
| `1002b83f` | `8d 7c 85 e0` | `LEA EDI,[EBP + EAX*0x4 + -0x20]` |
| `1002b843` | `2b c8` | `SUB ECX,EAX` |
| `1002b845` | `33 c0` | `XOR EAX,EAX` |
| `1002b847` | `f3 ab` | `STOSD.REP ES:EDI` |
| `1002b849` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1002b84d` | `74 01` | `JZ 0x1002b850` |
| `1002b84f` | `43` | `INC EBX` |
| `1002b850` | `a1 2c 87 03 10` | `MOV EAX,[0x1003872c]` |
| `1002b855` | `8b c8` | `MOV ECX,EAX` |
| `1002b857` | `2b 0d 30 87 03 10` | `SUB ECX,dword ptr [0x10038730]` |
| `1002b85d` | `3b d9` | `CMP EBX,ECX` |
| `1002b85f` | `7d 0d` | `JGE 0x1002b86e` |
| `1002b861` | `33 c0` | `XOR EAX,EAX` |
| `1002b863` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b866` | `ab` | `STOSD ES:EDI` |
| `1002b867` | `ab` | `STOSD ES:EDI` |
| `1002b868` | `ab` | `STOSD ES:EDI` |
| `1002b869` | `e9 0d 02 00 00` | `JMP 0x1002ba7b` |
| `1002b86e` | `3b d8` | `CMP EBX,EAX` |
| `1002b870` | `0f 8f 0f 02 00 00` | `JG 0x1002ba85` |
| `1002b876` | `2b 45 f0` | `SUB EAX,dword ptr [EBP + -0x10]` |
| `1002b879` | `8d 75 d4` | `LEA ESI,[EBP + -0x2c]` |
| `1002b87c` | `8b c8` | `MOV ECX,EAX` |
| `1002b87e` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b881` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b882` | `99` | `CDQ` |
| `1002b883` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b886` | `03 c2` | `ADD EAX,EDX` |
| `1002b888` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b889` | `8b d1` | `MOV EDX,ECX` |
| `1002b88b` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b88e` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b894` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b895` | `79 05` | `JNS 0x1002b89c` |
| `1002b897` | `4a` | `DEC EDX` |
| `1002b898` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b89b` | `42` | `INC EDX` |
| `1002b89c` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002b8a0` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b8a4` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1002b8a7` | `8b ca` | `MOV ECX,EDX` |
| `1002b8a9` | `d3 e7` | `SHL EDI,CL` |
| `1002b8ab` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002b8b2` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002b8b5` | `f7 d7` | `NOT EDI` |
| `1002b8b7` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1002b8ba` | `8d 5c 9d e0` | `LEA EBX,[EBP + EBX*0x4 + -0x20]` |
| `1002b8be` | `8b 33` | `MOV ESI,dword ptr [EBX]` |
| `1002b8c0` | `8b ce` | `MOV ECX,ESI` |
| `1002b8c2` | `23 cf` | `AND ECX,EDI` |
| `1002b8c4` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b8c7` | `8b ca` | `MOV ECX,EDX` |
| `1002b8c9` | `d3 ee` | `SHR ESI,CL` |
| `1002b8cb` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b8ce` | `0b 75 f4` | `OR ESI,dword ptr [EBP + -0xc]` |
| `1002b8d1` | `89 33` | `MOV dword ptr [EBX],ESI` |
| `1002b8d3` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002b8d6` | `d3 e6` | `SHL ESI,CL` |
| `1002b8d8` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002b8db` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002b8df` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002b8e2` | `7c d3` | `JL 0x1002b8b7` |
| `1002b8e4` | `8b f0` | `MOV ESI,EAX` |
| `1002b8e6` | `6a 02` | `PUSH 0x2` |
| `1002b8e8` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002b8eb` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002b8ee` | `5a` | `POP EDX` |
| `1002b8ef` | `2b ce` | `SUB ECX,ESI` |
| `1002b8f1` | `3b d0` | `CMP EDX,EAX` |
| `1002b8f3` | `7c 08` | `JL 0x1002b8fd` |
| `1002b8f5` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b8f7` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002b8fb` | `eb 05` | `JMP 0x1002b902` |
| `1002b8fd` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002b902` | `4a` | `DEC EDX` |
| `1002b903` | `83 e9 04` | `SUB ECX,0x4` |
| `1002b906` | `85 d2` | `TEST EDX,EDX` |
| `1002b908` | `7d e7` | `JGE 0x1002b8f1` |
| `1002b90a` | `8b 35 30 87 03 10` | `MOV ESI,dword ptr [0x10038730]` |
| `1002b910` | `4e` | `DEC ESI` |
| `1002b911` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `1002b914` | `8b c1` | `MOV EAX,ECX` |
| `1002b916` | `99` | `CDQ` |
| `1002b917` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b91a` | `03 c2` | `ADD EAX,EDX` |
| `1002b91c` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b91f` | `8b d1` | `MOV EDX,ECX` |
| `1002b921` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b927` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002b92a` | `79 05` | `JNS 0x1002b931` |
| `1002b92c` | `4a` | `DEC EDX` |
| `1002b92d` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b930` | `42` | `INC EDX` |
| `1002b931` | `6a 1f` | `PUSH 0x1f` |
| `1002b933` | `59` | `POP ECX` |
| `1002b934` | `2b ca` | `SUB ECX,EDX` |
| `1002b936` | `33 d2` | `XOR EDX,EDX` |
| `1002b938` | `42` | `INC EDX` |
| `1002b939` | `d3 e2` | `SHL EDX,CL` |
| `1002b93b` | `8d 5c 85 e0` | `LEA EBX,[EBP + EAX*0x4 + -0x20]` |
| `1002b93f` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b942` | `85 13` | `TEST dword ptr [EBX],EDX` |
| `1002b944` | `0f 84 82 00 00 00` | `JZ 0x1002b9cc` |
| `1002b94a` | `83 ca ff` | `OR EDX,0xffffffff` |
| `1002b94d` | `d3 e2` | `SHL EDX,CL` |
| `1002b94f` | `f7 d2` | `NOT EDX` |
| `1002b951` | `85 54 85 e0` | `TEST dword ptr [EBP + EAX*0x4 + -0x20],EDX` |
| `1002b955` | `eb 05` | `JMP 0x1002b95c` |
| `1002b957` | `83 7c 85 e0 00` | `CMP dword ptr [EBP + EAX*0x4 + -0x20],0x0` |
| `1002b95c` | `75 08` | `JNZ 0x1002b966` |
| `1002b95e` | `40` | `INC EAX` |
| `1002b95f` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b962` | `7c f3` | `JL 0x1002b957` |
| `1002b964` | `eb 66` | `JMP 0x1002b9cc` |
| `1002b966` | `8b c6` | `MOV EAX,ESI` |
| `1002b968` | `99` | `CDQ` |
| `1002b969` | `6a 1f` | `PUSH 0x1f` |
| `1002b96b` | `59` | `POP ECX` |
| `1002b96c` | `23 d1` | `AND EDX,ECX` |
| `1002b96e` | `03 c2` | `ADD EAX,EDX` |
| `1002b970` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b973` | `81 e6 1f 00 00 80` | `AND ESI,0x8000001f` |
| `1002b979` | `79 05` | `JNS 0x1002b980` |
| `1002b97b` | `4e` | `DEC ESI` |
| `1002b97c` | `83 ce e0` | `OR ESI,0xffffffe0` |
| `1002b97f` | `46` | `INC ESI` |
| `1002b980` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b984` | `33 d2` | `XOR EDX,EDX` |
| `1002b986` | `2b ce` | `SUB ECX,ESI` |
| `1002b988` | `42` | `INC EDX` |
| `1002b989` | `d3 e2` | `SHL EDX,CL` |
| `1002b98b` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b98f` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b991` | `8d 3c 16` | `LEA EDI,[ESI + EDX*0x1]` |
| `1002b994` | `3b fe` | `CMP EDI,ESI` |
| `1002b996` | `72 04` | `JC 0x1002b99c` |
| `1002b998` | `3b fa` | `CMP EDI,EDX` |
| `1002b99a` | `73 07` | `JNC 0x1002b9a3` |
| `1002b99c` | `c7 45 08 01 00 00 00` | `MOV dword ptr [EBP + 0x8],0x1` |
| `1002b9a3` | `89 39` | `MOV dword ptr [ECX],EDI` |
| `1002b9a5` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002b9a8` | `eb 1f` | `JMP 0x1002b9c9` |
| `1002b9aa` | `85 c9` | `TEST ECX,ECX` |
| `1002b9ac` | `74 1e` | `JZ 0x1002b9cc` |
| `1002b9ae` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b9b2` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `1002b9b4` | `8d 72 01` | `LEA ESI,[EDX + 0x1]` |
| `1002b9b7` | `33 ff` | `XOR EDI,EDI` |
| `1002b9b9` | `3b f2` | `CMP ESI,EDX` |
| `1002b9bb` | `72 05` | `JC 0x1002b9c2` |
| `1002b9bd` | `83 fe 01` | `CMP ESI,0x1` |
| `1002b9c0` | `73 03` | `JNC 0x1002b9c5` |
| `1002b9c2` | `33 ff` | `XOR EDI,EDI` |
| `1002b9c4` | `47` | `INC EDI` |
| `1002b9c5` | `89 31` | `MOV dword ptr [ECX],ESI` |
| `1002b9c7` | `8b cf` | `MOV ECX,EDI` |
| `1002b9c9` | `48` | `DEC EAX` |
| `1002b9ca` | `79 de` | `JNS 0x1002b9aa` |
| `1002b9cc` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002b9cf` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1002b9d2` | `d3 e0` | `SHL EAX,CL` |
| `1002b9d4` | `21 03` | `AND dword ptr [EBX],EAX` |
| `1002b9d6` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002b9d9` | `40` | `INC EAX` |
| `1002b9da` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b9dd` | `7d 0d` | `JGE 0x1002b9ec` |
| `1002b9df` | `6a 03` | `PUSH 0x3` |
| `1002b9e1` | `59` | `POP ECX` |
| `1002b9e2` | `8d 7c 85 e0` | `LEA EDI,[EBP + EAX*0x4 + -0x20]` |
| `1002b9e6` | `2b c8` | `SUB ECX,EAX` |
| `1002b9e8` | `33 c0` | `XOR EAX,EAX` |
| `1002b9ea` | `f3 ab` | `STOSD.REP ES:EDI` |
| `1002b9ec` | `8b 0d 34 87 03 10` | `MOV ECX,dword ptr [0x10038734]` |
| `1002b9f2` | `41` | `INC ECX` |
| `1002b9f3` | `8b c1` | `MOV EAX,ECX` |
| `1002b9f5` | `99` | `CDQ` |
| `1002b9f6` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b9f9` | `03 c2` | `ADD EAX,EDX` |
| `1002b9fb` | `8b d1` | `MOV EDX,ECX` |
| `1002b9fd` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002ba00` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002ba06` | `79 05` | `JNS 0x1002ba0d` |
| `1002ba08` | `4a` | `DEC EDX` |
| `1002ba09` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002ba0c` | `42` | `INC EDX` |
| `1002ba0d` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002ba11` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002ba15` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1002ba18` | `8b ca` | `MOV ECX,EDX` |
| `1002ba1a` | `d3 e7` | `SHL EDI,CL` |
| `1002ba1c` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002ba23` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002ba26` | `f7 d7` | `NOT EDI` |
| `1002ba28` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1002ba2b` | `8d 5c 9d e0` | `LEA EBX,[EBP + EBX*0x4 + -0x20]` |
| `1002ba2f` | `8b 33` | `MOV ESI,dword ptr [EBX]` |
| `1002ba31` | `8b ce` | `MOV ECX,ESI` |
| `1002ba33` | `23 cf` | `AND ECX,EDI` |
| `1002ba35` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002ba38` | `8b ca` | `MOV ECX,EDX` |
| `1002ba3a` | `d3 ee` | `SHR ESI,CL` |
| `1002ba3c` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002ba3f` | `0b 75 f4` | `OR ESI,dword ptr [EBP + -0xc]` |
| `1002ba42` | `89 33` | `MOV dword ptr [EBX],ESI` |
| `1002ba44` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002ba47` | `d3 e6` | `SHL ESI,CL` |
| `1002ba49` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002ba4c` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002ba50` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002ba53` | `7c d3` | `JL 0x1002ba28` |
| `1002ba55` | `8b f0` | `MOV ESI,EAX` |
| `1002ba57` | `6a 02` | `PUSH 0x2` |
| `1002ba59` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002ba5c` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002ba5f` | `5a` | `POP EDX` |
| `1002ba60` | `2b ce` | `SUB ECX,ESI` |
| `1002ba62` | `3b d0` | `CMP EDX,EAX` |
| `1002ba64` | `7c 08` | `JL 0x1002ba6e` |
| `1002ba66` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002ba68` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002ba6c` | `eb 05` | `JMP 0x1002ba73` |
| `1002ba6e` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002ba73` | `4a` | `DEC EDX` |
| `1002ba74` | `83 e9 04` | `SUB ECX,0x4` |
| `1002ba77` | `85 d2` | `TEST EDX,EDX` |
| `1002ba79` | `7d e7` | `JGE 0x1002ba62` |
| `1002ba7b` | `6a 02` | `PUSH 0x2` |
| `1002ba7d` | `33 db` | `XOR EBX,EBX` |
| `1002ba7f` | `58` | `POP EAX` |
| `1002ba80` | `e9 5a 01 00 00` | `JMP 0x1002bbdf` |
| `1002ba85` | `3b 1d 28 87 03 10` | `CMP EBX,dword ptr [0x10038728]` |
| `1002ba8b` | `8b 0d 34 87 03 10` | `MOV ECX,dword ptr [0x10038734]` |
| `1002ba91` | `0f 8c ad 00 00 00` | `JL 0x1002bb44` |
| `1002ba97` | `33 c0` | `XOR EAX,EAX` |
| `1002ba99` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002ba9c` | `ab` | `STOSD ES:EDI` |
| `1002ba9d` | `ab` | `STOSD ES:EDI` |
| `1002ba9e` | `ab` | `STOSD ES:EDI` |
| `1002ba9f` | `81 4d e0 00 00 00 80` | `OR dword ptr [EBP + -0x20],0x80000000` |
| `1002baa6` | `8b c1` | `MOV EAX,ECX` |
| `1002baa8` | `99` | `CDQ` |
| `1002baa9` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002baac` | `03 c2` | `ADD EAX,EDX` |
| `1002baae` | `8b d1` | `MOV EDX,ECX` |
| `1002bab0` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002bab3` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002bab9` | `79 05` | `JNS 0x1002bac0` |
| `1002babb` | `4a` | `DEC EDX` |
| `1002babc` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002babf` | `42` | `INC EDX` |
| `1002bac0` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002bac4` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002bac8` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1002bacb` | `8b ca` | `MOV ECX,EDX` |
| `1002bacd` | `d3 e7` | `SHL EDI,CL` |
| `1002bacf` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002bad6` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002bad9` | `f7 d7` | `NOT EDI` |
| `1002badb` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1002bade` | `8d 5c 9d e0` | `LEA EBX,[EBP + EBX*0x4 + -0x20]` |
| `1002bae2` | `8b 33` | `MOV ESI,dword ptr [EBX]` |
| `1002bae4` | `8b ce` | `MOV ECX,ESI` |
| `1002bae6` | `23 cf` | `AND ECX,EDI` |
| `1002bae8` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002baeb` | `8b ca` | `MOV ECX,EDX` |
| `1002baed` | `d3 ee` | `SHR ESI,CL` |
| `1002baef` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002baf2` | `0b 75 f4` | `OR ESI,dword ptr [EBP + -0xc]` |
| `1002baf5` | `89 33` | `MOV dword ptr [EBX],ESI` |
| `1002baf7` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002bafa` | `d3 e6` | `SHL ESI,CL` |
| `1002bafc` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002baff` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002bb03` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002bb06` | `7c d3` | `JL 0x1002badb` |
| `1002bb08` | `8b f0` | `MOV ESI,EAX` |
| `1002bb0a` | `6a 02` | `PUSH 0x2` |
| `1002bb0c` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002bb0f` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002bb12` | `5a` | `POP EDX` |
| `1002bb13` | `2b ce` | `SUB ECX,ESI` |
| `1002bb15` | `3b d0` | `CMP EDX,EAX` |
| `1002bb17` | `7c 08` | `JL 0x1002bb21` |
| `1002bb19` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002bb1b` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002bb1f` | `eb 05` | `JMP 0x1002bb26` |
| `1002bb21` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002bb26` | `4a` | `DEC EDX` |
| `1002bb27` | `83 e9 04` | `SUB ECX,0x4` |
| `1002bb2a` | `85 d2` | `TEST EDX,EDX` |
| `1002bb2c` | `7d e7` | `JGE 0x1002bb15` |
| `1002bb2e` | `a1 28 87 03 10` | `MOV EAX,[0x10038728]` |
| `1002bb33` | `8b 0d 3c 87 03 10` | `MOV ECX,dword ptr [0x1003873c]` |
| `1002bb39` | `8d 1c 01` | `LEA EBX,[ECX + EAX*0x1]` |
| `1002bb3c` | `33 c0` | `XOR EAX,EAX` |
| `1002bb3e` | `40` | `INC EAX` |
| `1002bb3f` | `e9 9b 00 00 00` | `JMP 0x1002bbdf` |
| `1002bb44` | `a1 3c 87 03 10` | `MOV EAX,[0x1003873c]` |
| `1002bb49` | `81 65 e0 ff ff ff 7f` | `AND dword ptr [EBP + -0x20],0x7fffffff` |
| `1002bb50` | `03 d8` | `ADD EBX,EAX` |
| `1002bb52` | `8b c1` | `MOV EAX,ECX` |
| `1002bb54` | `99` | `CDQ` |
| `1002bb55` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002bb58` | `03 c2` | `ADD EAX,EDX` |
| `1002bb5a` | `8b d1` | `MOV EDX,ECX` |
| `1002bb5c` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002bb5f` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002bb65` | `79 05` | `JNS 0x1002bb6c` |
| `1002bb67` | `4a` | `DEC EDX` |
| `1002bb68` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002bb6b` | `42` | `INC EDX` |
| `1002bb6c` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002bb70` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002bb74` | `83 ce ff` | `OR ESI,0xffffffff` |
| `1002bb77` | `8b ca` | `MOV ECX,EDX` |
| `1002bb79` | `d3 e6` | `SHL ESI,CL` |
| `1002bb7b` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002bb82` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002bb85` | `f7 d6` | `NOT ESI` |
| `1002bb87` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002bb8a` | `8b 7c 8d e0` | `MOV EDI,dword ptr [EBP + ECX*0x4 + -0x20]` |
| `1002bb8e` | `8b cf` | `MOV ECX,EDI` |
| `1002bb90` | `23 ce` | `AND ECX,ESI` |
| `1002bb92` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002bb95` | `8b ca` | `MOV ECX,EDX` |
| `1002bb97` | `d3 ef` | `SHR EDI,CL` |
| `1002bb99` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002bb9c` | `0b 7d f4` | `OR EDI,dword ptr [EBP + -0xc]` |
| `1002bb9f` | `89 7c 8d e0` | `MOV dword ptr [EBP + ECX*0x4 + -0x20],EDI` |
| `1002bba3` | `8b 7d f0` | `MOV EDI,dword ptr [EBP + -0x10]` |
| `1002bba6` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002bba9` | `d3 e7` | `SHL EDI,CL` |
| `1002bbab` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002bbae` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002bbb2` | `89 7d f4` | `MOV dword ptr [EBP + -0xc],EDI` |
| `1002bbb5` | `7c d0` | `JL 0x1002bb87` |
| `1002bbb7` | `8b f0` | `MOV ESI,EAX` |
| `1002bbb9` | `6a 02` | `PUSH 0x2` |
| `1002bbbb` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002bbbe` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002bbc1` | `5a` | `POP EDX` |
| `1002bbc2` | `2b ce` | `SUB ECX,ESI` |
| `1002bbc4` | `3b d0` | `CMP EDX,EAX` |
| `1002bbc6` | `7c 08` | `JL 0x1002bbd0` |
| `1002bbc8` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002bbca` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002bbce` | `eb 05` | `JMP 0x1002bbd5` |
| `1002bbd0` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002bbd5` | `4a` | `DEC EDX` |
| `1002bbd6` | `83 e9 04` | `SUB ECX,0x4` |
| `1002bbd9` | `85 d2` | `TEST EDX,EDX` |
| `1002bbdb` | `7d e7` | `JGE 0x1002bbc4` |
| `1002bbdd` | `33 c0` | `XOR EAX,EAX` |
| `1002bbdf` | `5e` | `POP ESI` |
| `1002bbe0` | `6a 1f` | `PUSH 0x1f` |
| `1002bbe2` | `59` | `POP ECX` |
| `1002bbe3` | `2b 0d 34 87 03 10` | `SUB ECX,dword ptr [0x10038734]` |
| `1002bbe9` | `d3 e3` | `SHL EBX,CL` |
| `1002bbeb` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `1002bbee` | `f7 d9` | `NEG ECX` |
| `1002bbf0` | `1b c9` | `SBB ECX,ECX` |
| `1002bbf2` | `81 e1 00 00 00 80` | `AND ECX,0x80000000` |
| `1002bbf8` | `0b d9` | `OR EBX,ECX` |
| `1002bbfa` | `8b 0d 38 87 03 10` | `MOV ECX,dword ptr [0x10038738]` |
| `1002bc00` | `0b 5d e0` | `OR EBX,dword ptr [EBP + -0x20]` |
| `1002bc03` | `83 f9 40` | `CMP ECX,0x40` |
| `1002bc06` | `75 0d` | `JNZ 0x1002bc15` |
| `1002bc08` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1002bc0b` | `8b 55 e4` | `MOV EDX,dword ptr [EBP + -0x1c]` |
| `1002bc0e` | `89 59 04` | `MOV dword ptr [ECX + 0x4],EBX` |
| `1002bc11` | `89 11` | `MOV dword ptr [ECX],EDX` |
| `1002bc13` | `eb 0a` | `JMP 0x1002bc1f` |
| `1002bc15` | `83 f9 20` | `CMP ECX,0x20` |
| `1002bc18` | `75 05` | `JNZ 0x1002bc1f` |
| `1002bc1a` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1002bc1d` | `89 19` | `MOV dword ptr [ECX],EBX` |
| `1002bc1f` | `5f` | `POP EDI` |
| `1002bc20` | `5b` | `POP EBX` |
| `1002bc21` | `c9` | `LEAVE` |
| `1002bc22` | `c3` | `RET` |
