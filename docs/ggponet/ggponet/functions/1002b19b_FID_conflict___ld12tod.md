# 1002b19b `FID_conflict:__ld12tod`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002b19b |
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
        goto LAB_1002b69c;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    IVar3 = INTRNCVT_OK;
  }
  else {
    _Ifp = (_LDBL12 *)0x0;
    iVar13 = DAT_10038718 - 1;
    iVar4 = (int)(DAT_10038718 + ((int)DAT_10038718 >> 0x1f & 0x1fU)) >> 5;
    uVar8 = DAT_10038718 & 0x8000001f;
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
          if (_Ifp < (_LDBL12 *)*puVar6) goto LAB_1002b2d0;
          bVar14 = _Ifp < p_Var9;
          do {
            local_8 = (_LDBL12 *)0x0;
            if (!bVar14) goto LAB_1002b2d7;
LAB_1002b2d0:
            do {
              local_8 = (_LDBL12 *)0x1;
LAB_1002b2d7:
              iVar4 = iVar4 + -1;
              *puVar6 = (uint)_Ifp;
              if ((iVar4 < 0) || (local_8 == (_LDBL12 *)0x0)) {
                _Ifp = local_8;
                goto LAB_1002b2e5;
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
LAB_1002b2e5:
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
    if (iVar12 < (int)(DAT_10038714 - DAT_10038718)) {
      local_24[0] = 0;
      local_24[1] = 0;
    }
    else {
      if (DAT_10038714 < iVar12) {
        if (iVar12 < DAT_10038710) {
          local_24[0] = local_24[0] & 0x7fffffff;
          iVar12 = iVar12 + DAT_10038724;
          iVar2 = (int)(DAT_1003871c + ((int)DAT_1003871c >> 0x1f & 0x1fU)) >> 5;
          uVar10 = DAT_1003871c & 0x8000001f;
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
          iVar12 = (int)(DAT_1003871c + ((int)DAT_1003871c >> 0x1f & 0x1fU)) >> 5;
          uVar10 = DAT_1003871c & 0x8000001f;
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
          iVar12 = DAT_10038724 + DAT_10038710;
          IVar3 = INTRNCVT_OVERFLOW;
        }
        goto LAB_1002b69c;
      }
      local_14 = DAT_10038714 - local_14;
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
      iVar2 = DAT_10038718 - 1;
      iVar12 = (int)(DAT_10038718 + ((int)DAT_10038718 >> 0x1f & 0x1fU)) >> 5;
      uVar10 = DAT_10038718 & 0x8000001f;
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
          if (2 < iVar12) goto LAB_1002b488;
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
LAB_1002b488:
      *puVar7 = *puVar7 & -1 << ((byte)local_14 & 0x1f);
      iVar12 = local_10 + 1;
      if (iVar12 < 3) {
        puVar7 = local_24 + iVar12;
        for (iVar2 = 3 - iVar12; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
      }
      uVar10 = DAT_1003871c + 1;
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
LAB_1002b69c:
  local_24[0] = iVar12 << (0x1fU - (char)DAT_1003871c & 0x1f) |
                -(uint)(local_24[3] != 0) & 0x80000000 | local_24[0];
  if (DAT_10038720 == 0x40) {
    *(uint *)((int)&_D->x + 4) = local_24[0];
    *(uint *)&_D->x = local_24[1];
  }
  else if (DAT_10038720 == 0x20) {
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
| `1002ad13` | FID_conflict:__atoflt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002b215` | `10038718` | `READ` | DAT_10038718 |
| `1002b30c` | `10038714` | `READ` | DAT_10038714 |
| `1002b313` | `10038718` | `READ` | DAT_10038718 |
| `1002b3c6` | `10038718` | `READ` | DAT_10038718 |
| `1002b4a8` | `1003871c` | `READ` | DAT_1003871c |
| `1002b541` | `10038710` | `READ` | DAT_10038710 |
| `1002b547` | `1003871c` | `READ` | DAT_1003871c |
| `1002b5ea` | `10038710` | `READ` | DAT_10038710 |
| `1002b5ef` | `10038724` | `READ` | DAT_10038724 |
| `1002b600` | `10038724` | `READ` | DAT_10038724 |
| `1002b69f` | `1003871c` | `READ` | DAT_1003871c |
| `1002b6b6` | `10038720` | `READ` | DAT_10038720 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002b19b` | `8b ff` | `MOV EDI,EDI` |
| `1002b19d` | `55` | `PUSH EBP` |
| `1002b19e` | `8b ec` | `MOV EBP,ESP` |
| `1002b1a0` | `83 ec 2c` | `SUB ESP,0x2c` |
| `1002b1a3` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002b1a6` | `0f b7 48 0a` | `MOVZX ECX,word ptr [EAX + 0xa]` |
| `1002b1aa` | `53` | `PUSH EBX` |
| `1002b1ab` | `8b d9` | `MOV EBX,ECX` |
| `1002b1ad` | `81 e1 00 80 00 00` | `AND ECX,0x8000` |
| `1002b1b3` | `89 4d ec` | `MOV dword ptr [EBP + -0x14],ECX` |
| `1002b1b6` | `8b 48 06` | `MOV ECX,dword ptr [EAX + 0x6]` |
| `1002b1b9` | `89 4d e0` | `MOV dword ptr [EBP + -0x20],ECX` |
| `1002b1bc` | `8b 48 02` | `MOV ECX,dword ptr [EAX + 0x2]` |
| `1002b1bf` | `0f b7 00` | `MOVZX EAX,word ptr [EAX]` |
| `1002b1c2` | `81 e3 ff 7f 00 00` | `AND EBX,0x7fff` |
| `1002b1c8` | `81 eb ff 3f 00 00` | `SUB EBX,0x3fff` |
| `1002b1ce` | `c1 e0 10` | `SHL EAX,0x10` |
| `1002b1d1` | `57` | `PUSH EDI` |
| `1002b1d2` | `89 4d e4` | `MOV dword ptr [EBP + -0x1c],ECX` |
| `1002b1d5` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1002b1d8` | `81 fb 01 c0 ff ff` | `CMP EBX,0xffffc001` |
| `1002b1de` | `75 27` | `JNZ 0x1002b207` |
| `1002b1e0` | `33 db` | `XOR EBX,EBX` |
| `1002b1e2` | `33 c0` | `XOR EAX,EAX` |
| `1002b1e4` | `39 5c 85 e0` | `CMP dword ptr [EBP + EAX*0x4 + -0x20],EBX` |
| `1002b1e8` | `75 0d` | `JNZ 0x1002b1f7` |
| `1002b1ea` | `40` | `INC EAX` |
| `1002b1eb` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b1ee` | `7c f4` | `JL 0x1002b1e4` |
| `1002b1f0` | `33 c0` | `XOR EAX,EAX` |
| `1002b1f2` | `e9 a5 04 00 00` | `JMP 0x1002b69c` |
| `1002b1f7` | `33 c0` | `XOR EAX,EAX` |
| `1002b1f9` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b1fc` | `ab` | `STOSD ES:EDI` |
| `1002b1fd` | `ab` | `STOSD ES:EDI` |
| `1002b1fe` | `6a 02` | `PUSH 0x2` |
| `1002b200` | `ab` | `STOSD ES:EDI` |
| `1002b201` | `58` | `POP EAX` |
| `1002b202` | `e9 95 04 00 00` | `JMP 0x1002b69c` |
| `1002b207` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b20b` | `56` | `PUSH ESI` |
| `1002b20c` | `8d 75 e0` | `LEA ESI,[EBP + -0x20]` |
| `1002b20f` | `8d 7d d4` | `LEA EDI,[EBP + -0x2c]` |
| `1002b212` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b213` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b214` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b215` | `8b 35 18 87 03 10` | `MOV ESI,dword ptr [0x10038718]` |
| `1002b21b` | `4e` | `DEC ESI` |
| `1002b21c` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `1002b21f` | `8b c1` | `MOV EAX,ECX` |
| `1002b221` | `99` | `CDQ` |
| `1002b222` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b225` | `03 c2` | `ADD EAX,EDX` |
| `1002b227` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b22a` | `8b d1` | `MOV EDX,ECX` |
| `1002b22c` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b232` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `1002b235` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002b238` | `79 05` | `JNS 0x1002b23f` |
| `1002b23a` | `4a` | `DEC EDX` |
| `1002b23b` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b23e` | `42` | `INC EDX` |
| `1002b23f` | `8d 7c 85 e0` | `LEA EDI,[EBP + EAX*0x4 + -0x20]` |
| `1002b243` | `6a 1f` | `PUSH 0x1f` |
| `1002b245` | `33 c0` | `XOR EAX,EAX` |
| `1002b247` | `59` | `POP ECX` |
| `1002b248` | `2b ca` | `SUB ECX,EDX` |
| `1002b24a` | `40` | `INC EAX` |
| `1002b24b` | `d3 e0` | `SHL EAX,CL` |
| `1002b24d` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1002b250` | `85 07` | `TEST dword ptr [EDI],EAX` |
| `1002b252` | `0f 84 8d 00 00 00` | `JZ 0x1002b2e5` |
| `1002b258` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002b25b` | `83 ca ff` | `OR EDX,0xffffffff` |
| `1002b25e` | `d3 e2` | `SHL EDX,CL` |
| `1002b260` | `f7 d2` | `NOT EDX` |
| `1002b262` | `85 54 85 e0` | `TEST dword ptr [EBP + EAX*0x4 + -0x20],EDX` |
| `1002b266` | `eb 05` | `JMP 0x1002b26d` |
| `1002b268` | `83 7c 85 e0 00` | `CMP dword ptr [EBP + EAX*0x4 + -0x20],0x0` |
| `1002b26d` | `75 08` | `JNZ 0x1002b277` |
| `1002b26f` | `40` | `INC EAX` |
| `1002b270` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b273` | `7c f3` | `JL 0x1002b268` |
| `1002b275` | `eb 6e` | `JMP 0x1002b2e5` |
| `1002b277` | `8b c6` | `MOV EAX,ESI` |
| `1002b279` | `99` | `CDQ` |
| `1002b27a` | `6a 1f` | `PUSH 0x1f` |
| `1002b27c` | `59` | `POP ECX` |
| `1002b27d` | `23 d1` | `AND EDX,ECX` |
| `1002b27f` | `03 c2` | `ADD EAX,EDX` |
| `1002b281` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b284` | `81 e6 1f 00 00 80` | `AND ESI,0x8000001f` |
| `1002b28a` | `79 05` | `JNS 0x1002b291` |
| `1002b28c` | `4e` | `DEC ESI` |
| `1002b28d` | `83 ce e0` | `OR ESI,0xffffffe0` |
| `1002b290` | `46` | `INC ESI` |
| `1002b291` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1002b295` | `2b ce` | `SUB ECX,ESI` |
| `1002b297` | `33 d2` | `XOR EDX,EDX` |
| `1002b299` | `42` | `INC EDX` |
| `1002b29a` | `d3 e2` | `SHL EDX,CL` |
| `1002b29c` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b2a0` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b2a2` | `03 f2` | `ADD ESI,EDX` |
| `1002b2a4` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `1002b2a7` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b2a9` | `39 75 08` | `CMP dword ptr [EBP + 0x8],ESI` |
| `1002b2ac` | `72 22` | `JC 0x1002b2d0` |
| `1002b2ae` | `39 55 08` | `CMP dword ptr [EBP + 0x8],EDX` |
| `1002b2b1` | `eb 1b` | `JMP 0x1002b2ce` |
| `1002b2b3` | `85 c9` | `TEST ECX,ECX` |
| `1002b2b5` | `74 2b` | `JZ 0x1002b2e2` |
| `1002b2b7` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1002b2bb` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b2bf` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `1002b2c1` | `8d 72 01` | `LEA ESI,[EDX + 0x1]` |
| `1002b2c4` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `1002b2c7` | `3b f2` | `CMP ESI,EDX` |
| `1002b2c9` | `72 05` | `JC 0x1002b2d0` |
| `1002b2cb` | `83 fe 01` | `CMP ESI,0x1` |
| `1002b2ce` | `73 07` | `JNC 0x1002b2d7` |
| `1002b2d0` | `c7 45 fc 01 00 00 00` | `MOV dword ptr [EBP + -0x4],0x1` |
| `1002b2d7` | `48` | `DEC EAX` |
| `1002b2d8` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `1002b2db` | `89 11` | `MOV dword ptr [ECX],EDX` |
| `1002b2dd` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b2e0` | `79 d1` | `JNS 0x1002b2b3` |
| `1002b2e2` | `89 4d 08` | `MOV dword ptr [EBP + 0x8],ECX` |
| `1002b2e5` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1002b2e8` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1002b2eb` | `d3 e0` | `SHL EAX,CL` |
| `1002b2ed` | `21 07` | `AND dword ptr [EDI],EAX` |
| `1002b2ef` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002b2f2` | `40` | `INC EAX` |
| `1002b2f3` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b2f6` | `7d 0d` | `JGE 0x1002b305` |
| `1002b2f8` | `6a 03` | `PUSH 0x3` |
| `1002b2fa` | `59` | `POP ECX` |
| `1002b2fb` | `8d 7c 85 e0` | `LEA EDI,[EBP + EAX*0x4 + -0x20]` |
| `1002b2ff` | `2b c8` | `SUB ECX,EAX` |
| `1002b301` | `33 c0` | `XOR EAX,EAX` |
| `1002b303` | `f3 ab` | `STOSD.REP ES:EDI` |
| `1002b305` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1002b309` | `74 01` | `JZ 0x1002b30c` |
| `1002b30b` | `43` | `INC EBX` |
| `1002b30c` | `a1 14 87 03 10` | `MOV EAX,[0x10038714]` |
| `1002b311` | `8b c8` | `MOV ECX,EAX` |
| `1002b313` | `2b 0d 18 87 03 10` | `SUB ECX,dword ptr [0x10038718]` |
| `1002b319` | `3b d9` | `CMP EBX,ECX` |
| `1002b31b` | `7d 0d` | `JGE 0x1002b32a` |
| `1002b31d` | `33 c0` | `XOR EAX,EAX` |
| `1002b31f` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b322` | `ab` | `STOSD ES:EDI` |
| `1002b323` | `ab` | `STOSD ES:EDI` |
| `1002b324` | `ab` | `STOSD ES:EDI` |
| `1002b325` | `e9 0d 02 00 00` | `JMP 0x1002b537` |
| `1002b32a` | `3b d8` | `CMP EBX,EAX` |
| `1002b32c` | `0f 8f 0f 02 00 00` | `JG 0x1002b541` |
| `1002b332` | `2b 45 f0` | `SUB EAX,dword ptr [EBP + -0x10]` |
| `1002b335` | `8d 75 d4` | `LEA ESI,[EBP + -0x2c]` |
| `1002b338` | `8b c8` | `MOV ECX,EAX` |
| `1002b33a` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b33d` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b33e` | `99` | `CDQ` |
| `1002b33f` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b342` | `03 c2` | `ADD EAX,EDX` |
| `1002b344` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b345` | `8b d1` | `MOV EDX,ECX` |
| `1002b347` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b34a` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b350` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002b351` | `79 05` | `JNS 0x1002b358` |
| `1002b353` | `4a` | `DEC EDX` |
| `1002b354` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b357` | `42` | `INC EDX` |
| `1002b358` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002b35c` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b360` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1002b363` | `8b ca` | `MOV ECX,EDX` |
| `1002b365` | `d3 e7` | `SHL EDI,CL` |
| `1002b367` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002b36e` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002b371` | `f7 d7` | `NOT EDI` |
| `1002b373` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1002b376` | `8d 5c 9d e0` | `LEA EBX,[EBP + EBX*0x4 + -0x20]` |
| `1002b37a` | `8b 33` | `MOV ESI,dword ptr [EBX]` |
| `1002b37c` | `8b ce` | `MOV ECX,ESI` |
| `1002b37e` | `23 cf` | `AND ECX,EDI` |
| `1002b380` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b383` | `8b ca` | `MOV ECX,EDX` |
| `1002b385` | `d3 ee` | `SHR ESI,CL` |
| `1002b387` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b38a` | `0b 75 f4` | `OR ESI,dword ptr [EBP + -0xc]` |
| `1002b38d` | `89 33` | `MOV dword ptr [EBX],ESI` |
| `1002b38f` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002b392` | `d3 e6` | `SHL ESI,CL` |
| `1002b394` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002b397` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002b39b` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002b39e` | `7c d3` | `JL 0x1002b373` |
| `1002b3a0` | `8b f0` | `MOV ESI,EAX` |
| `1002b3a2` | `6a 02` | `PUSH 0x2` |
| `1002b3a4` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002b3a7` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002b3aa` | `5a` | `POP EDX` |
| `1002b3ab` | `2b ce` | `SUB ECX,ESI` |
| `1002b3ad` | `3b d0` | `CMP EDX,EAX` |
| `1002b3af` | `7c 08` | `JL 0x1002b3b9` |
| `1002b3b1` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b3b3` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002b3b7` | `eb 05` | `JMP 0x1002b3be` |
| `1002b3b9` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002b3be` | `4a` | `DEC EDX` |
| `1002b3bf` | `83 e9 04` | `SUB ECX,0x4` |
| `1002b3c2` | `85 d2` | `TEST EDX,EDX` |
| `1002b3c4` | `7d e7` | `JGE 0x1002b3ad` |
| `1002b3c6` | `8b 35 18 87 03 10` | `MOV ESI,dword ptr [0x10038718]` |
| `1002b3cc` | `4e` | `DEC ESI` |
| `1002b3cd` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `1002b3d0` | `8b c1` | `MOV EAX,ECX` |
| `1002b3d2` | `99` | `CDQ` |
| `1002b3d3` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b3d6` | `03 c2` | `ADD EAX,EDX` |
| `1002b3d8` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b3db` | `8b d1` | `MOV EDX,ECX` |
| `1002b3dd` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b3e3` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002b3e6` | `79 05` | `JNS 0x1002b3ed` |
| `1002b3e8` | `4a` | `DEC EDX` |
| `1002b3e9` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b3ec` | `42` | `INC EDX` |
| `1002b3ed` | `6a 1f` | `PUSH 0x1f` |
| `1002b3ef` | `59` | `POP ECX` |
| `1002b3f0` | `2b ca` | `SUB ECX,EDX` |
| `1002b3f2` | `33 d2` | `XOR EDX,EDX` |
| `1002b3f4` | `42` | `INC EDX` |
| `1002b3f5` | `d3 e2` | `SHL EDX,CL` |
| `1002b3f7` | `8d 5c 85 e0` | `LEA EBX,[EBP + EAX*0x4 + -0x20]` |
| `1002b3fb` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b3fe` | `85 13` | `TEST dword ptr [EBX],EDX` |
| `1002b400` | `0f 84 82 00 00 00` | `JZ 0x1002b488` |
| `1002b406` | `83 ca ff` | `OR EDX,0xffffffff` |
| `1002b409` | `d3 e2` | `SHL EDX,CL` |
| `1002b40b` | `f7 d2` | `NOT EDX` |
| `1002b40d` | `85 54 85 e0` | `TEST dword ptr [EBP + EAX*0x4 + -0x20],EDX` |
| `1002b411` | `eb 05` | `JMP 0x1002b418` |
| `1002b413` | `83 7c 85 e0 00` | `CMP dword ptr [EBP + EAX*0x4 + -0x20],0x0` |
| `1002b418` | `75 08` | `JNZ 0x1002b422` |
| `1002b41a` | `40` | `INC EAX` |
| `1002b41b` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b41e` | `7c f3` | `JL 0x1002b413` |
| `1002b420` | `eb 66` | `JMP 0x1002b488` |
| `1002b422` | `8b c6` | `MOV EAX,ESI` |
| `1002b424` | `99` | `CDQ` |
| `1002b425` | `6a 1f` | `PUSH 0x1f` |
| `1002b427` | `59` | `POP ECX` |
| `1002b428` | `23 d1` | `AND EDX,ECX` |
| `1002b42a` | `03 c2` | `ADD EAX,EDX` |
| `1002b42c` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b42f` | `81 e6 1f 00 00 80` | `AND ESI,0x8000001f` |
| `1002b435` | `79 05` | `JNS 0x1002b43c` |
| `1002b437` | `4e` | `DEC ESI` |
| `1002b438` | `83 ce e0` | `OR ESI,0xffffffe0` |
| `1002b43b` | `46` | `INC ESI` |
| `1002b43c` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b440` | `33 d2` | `XOR EDX,EDX` |
| `1002b442` | `2b ce` | `SUB ECX,ESI` |
| `1002b444` | `42` | `INC EDX` |
| `1002b445` | `d3 e2` | `SHL EDX,CL` |
| `1002b447` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b44b` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b44d` | `8d 3c 16` | `LEA EDI,[ESI + EDX*0x1]` |
| `1002b450` | `3b fe` | `CMP EDI,ESI` |
| `1002b452` | `72 04` | `JC 0x1002b458` |
| `1002b454` | `3b fa` | `CMP EDI,EDX` |
| `1002b456` | `73 07` | `JNC 0x1002b45f` |
| `1002b458` | `c7 45 08 01 00 00 00` | `MOV dword ptr [EBP + 0x8],0x1` |
| `1002b45f` | `89 39` | `MOV dword ptr [ECX],EDI` |
| `1002b461` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002b464` | `eb 1f` | `JMP 0x1002b485` |
| `1002b466` | `85 c9` | `TEST ECX,ECX` |
| `1002b468` | `74 1e` | `JZ 0x1002b488` |
| `1002b46a` | `8d 4c 85 e0` | `LEA ECX,[EBP + EAX*0x4 + -0x20]` |
| `1002b46e` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `1002b470` | `8d 72 01` | `LEA ESI,[EDX + 0x1]` |
| `1002b473` | `33 ff` | `XOR EDI,EDI` |
| `1002b475` | `3b f2` | `CMP ESI,EDX` |
| `1002b477` | `72 05` | `JC 0x1002b47e` |
| `1002b479` | `83 fe 01` | `CMP ESI,0x1` |
| `1002b47c` | `73 03` | `JNC 0x1002b481` |
| `1002b47e` | `33 ff` | `XOR EDI,EDI` |
| `1002b480` | `47` | `INC EDI` |
| `1002b481` | `89 31` | `MOV dword ptr [ECX],ESI` |
| `1002b483` | `8b cf` | `MOV ECX,EDI` |
| `1002b485` | `48` | `DEC EAX` |
| `1002b486` | `79 de` | `JNS 0x1002b466` |
| `1002b488` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002b48b` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1002b48e` | `d3 e0` | `SHL EAX,CL` |
| `1002b490` | `21 03` | `AND dword ptr [EBX],EAX` |
| `1002b492` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002b495` | `40` | `INC EAX` |
| `1002b496` | `83 f8 03` | `CMP EAX,0x3` |
| `1002b499` | `7d 0d` | `JGE 0x1002b4a8` |
| `1002b49b` | `6a 03` | `PUSH 0x3` |
| `1002b49d` | `59` | `POP ECX` |
| `1002b49e` | `8d 7c 85 e0` | `LEA EDI,[EBP + EAX*0x4 + -0x20]` |
| `1002b4a2` | `2b c8` | `SUB ECX,EAX` |
| `1002b4a4` | `33 c0` | `XOR EAX,EAX` |
| `1002b4a6` | `f3 ab` | `STOSD.REP ES:EDI` |
| `1002b4a8` | `8b 0d 1c 87 03 10` | `MOV ECX,dword ptr [0x1003871c]` |
| `1002b4ae` | `41` | `INC ECX` |
| `1002b4af` | `8b c1` | `MOV EAX,ECX` |
| `1002b4b1` | `99` | `CDQ` |
| `1002b4b2` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b4b5` | `03 c2` | `ADD EAX,EDX` |
| `1002b4b7` | `8b d1` | `MOV EDX,ECX` |
| `1002b4b9` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b4bc` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b4c2` | `79 05` | `JNS 0x1002b4c9` |
| `1002b4c4` | `4a` | `DEC EDX` |
| `1002b4c5` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b4c8` | `42` | `INC EDX` |
| `1002b4c9` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002b4cd` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b4d1` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1002b4d4` | `8b ca` | `MOV ECX,EDX` |
| `1002b4d6` | `d3 e7` | `SHL EDI,CL` |
| `1002b4d8` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002b4df` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002b4e2` | `f7 d7` | `NOT EDI` |
| `1002b4e4` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1002b4e7` | `8d 5c 9d e0` | `LEA EBX,[EBP + EBX*0x4 + -0x20]` |
| `1002b4eb` | `8b 33` | `MOV ESI,dword ptr [EBX]` |
| `1002b4ed` | `8b ce` | `MOV ECX,ESI` |
| `1002b4ef` | `23 cf` | `AND ECX,EDI` |
| `1002b4f1` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b4f4` | `8b ca` | `MOV ECX,EDX` |
| `1002b4f6` | `d3 ee` | `SHR ESI,CL` |
| `1002b4f8` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b4fb` | `0b 75 f4` | `OR ESI,dword ptr [EBP + -0xc]` |
| `1002b4fe` | `89 33` | `MOV dword ptr [EBX],ESI` |
| `1002b500` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002b503` | `d3 e6` | `SHL ESI,CL` |
| `1002b505` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002b508` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002b50c` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002b50f` | `7c d3` | `JL 0x1002b4e4` |
| `1002b511` | `8b f0` | `MOV ESI,EAX` |
| `1002b513` | `6a 02` | `PUSH 0x2` |
| `1002b515` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002b518` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002b51b` | `5a` | `POP EDX` |
| `1002b51c` | `2b ce` | `SUB ECX,ESI` |
| `1002b51e` | `3b d0` | `CMP EDX,EAX` |
| `1002b520` | `7c 08` | `JL 0x1002b52a` |
| `1002b522` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b524` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002b528` | `eb 05` | `JMP 0x1002b52f` |
| `1002b52a` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002b52f` | `4a` | `DEC EDX` |
| `1002b530` | `83 e9 04` | `SUB ECX,0x4` |
| `1002b533` | `85 d2` | `TEST EDX,EDX` |
| `1002b535` | `7d e7` | `JGE 0x1002b51e` |
| `1002b537` | `6a 02` | `PUSH 0x2` |
| `1002b539` | `33 db` | `XOR EBX,EBX` |
| `1002b53b` | `58` | `POP EAX` |
| `1002b53c` | `e9 5a 01 00 00` | `JMP 0x1002b69b` |
| `1002b541` | `3b 1d 10 87 03 10` | `CMP EBX,dword ptr [0x10038710]` |
| `1002b547` | `8b 0d 1c 87 03 10` | `MOV ECX,dword ptr [0x1003871c]` |
| `1002b54d` | `0f 8c ad 00 00 00` | `JL 0x1002b600` |
| `1002b553` | `33 c0` | `XOR EAX,EAX` |
| `1002b555` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002b558` | `ab` | `STOSD ES:EDI` |
| `1002b559` | `ab` | `STOSD ES:EDI` |
| `1002b55a` | `ab` | `STOSD ES:EDI` |
| `1002b55b` | `81 4d e0 00 00 00 80` | `OR dword ptr [EBP + -0x20],0x80000000` |
| `1002b562` | `8b c1` | `MOV EAX,ECX` |
| `1002b564` | `99` | `CDQ` |
| `1002b565` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b568` | `03 c2` | `ADD EAX,EDX` |
| `1002b56a` | `8b d1` | `MOV EDX,ECX` |
| `1002b56c` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b56f` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b575` | `79 05` | `JNS 0x1002b57c` |
| `1002b577` | `4a` | `DEC EDX` |
| `1002b578` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b57b` | `42` | `INC EDX` |
| `1002b57c` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002b580` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b584` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1002b587` | `8b ca` | `MOV ECX,EDX` |
| `1002b589` | `d3 e7` | `SHL EDI,CL` |
| `1002b58b` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002b592` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002b595` | `f7 d7` | `NOT EDI` |
| `1002b597` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1002b59a` | `8d 5c 9d e0` | `LEA EBX,[EBP + EBX*0x4 + -0x20]` |
| `1002b59e` | `8b 33` | `MOV ESI,dword ptr [EBX]` |
| `1002b5a0` | `8b ce` | `MOV ECX,ESI` |
| `1002b5a2` | `23 cf` | `AND ECX,EDI` |
| `1002b5a4` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b5a7` | `8b ca` | `MOV ECX,EDX` |
| `1002b5a9` | `d3 ee` | `SHR ESI,CL` |
| `1002b5ab` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b5ae` | `0b 75 f4` | `OR ESI,dword ptr [EBP + -0xc]` |
| `1002b5b1` | `89 33` | `MOV dword ptr [EBX],ESI` |
| `1002b5b3` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002b5b6` | `d3 e6` | `SHL ESI,CL` |
| `1002b5b8` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002b5bb` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002b5bf` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002b5c2` | `7c d3` | `JL 0x1002b597` |
| `1002b5c4` | `8b f0` | `MOV ESI,EAX` |
| `1002b5c6` | `6a 02` | `PUSH 0x2` |
| `1002b5c8` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002b5cb` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002b5ce` | `5a` | `POP EDX` |
| `1002b5cf` | `2b ce` | `SUB ECX,ESI` |
| `1002b5d1` | `3b d0` | `CMP EDX,EAX` |
| `1002b5d3` | `7c 08` | `JL 0x1002b5dd` |
| `1002b5d5` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b5d7` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002b5db` | `eb 05` | `JMP 0x1002b5e2` |
| `1002b5dd` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002b5e2` | `4a` | `DEC EDX` |
| `1002b5e3` | `83 e9 04` | `SUB ECX,0x4` |
| `1002b5e6` | `85 d2` | `TEST EDX,EDX` |
| `1002b5e8` | `7d e7` | `JGE 0x1002b5d1` |
| `1002b5ea` | `a1 10 87 03 10` | `MOV EAX,[0x10038710]` |
| `1002b5ef` | `8b 0d 24 87 03 10` | `MOV ECX,dword ptr [0x10038724]` |
| `1002b5f5` | `8d 1c 01` | `LEA EBX,[ECX + EAX*0x1]` |
| `1002b5f8` | `33 c0` | `XOR EAX,EAX` |
| `1002b5fa` | `40` | `INC EAX` |
| `1002b5fb` | `e9 9b 00 00 00` | `JMP 0x1002b69b` |
| `1002b600` | `a1 24 87 03 10` | `MOV EAX,[0x10038724]` |
| `1002b605` | `81 65 e0 ff ff ff 7f` | `AND dword ptr [EBP + -0x20],0x7fffffff` |
| `1002b60c` | `03 d8` | `ADD EBX,EAX` |
| `1002b60e` | `8b c1` | `MOV EAX,ECX` |
| `1002b610` | `99` | `CDQ` |
| `1002b611` | `83 e2 1f` | `AND EDX,0x1f` |
| `1002b614` | `03 c2` | `ADD EAX,EDX` |
| `1002b616` | `8b d1` | `MOV EDX,ECX` |
| `1002b618` | `c1 f8 05` | `SAR EAX,0x5` |
| `1002b61b` | `81 e2 1f 00 00 80` | `AND EDX,0x8000001f` |
| `1002b621` | `79 05` | `JNS 0x1002b628` |
| `1002b623` | `4a` | `DEC EDX` |
| `1002b624` | `83 ca e0` | `OR EDX,0xffffffe0` |
| `1002b627` | `42` | `INC EDX` |
| `1002b628` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `1002b62c` | `83 65 08 00` | `AND dword ptr [EBP + 0x8],0x0` |
| `1002b630` | `83 ce ff` | `OR ESI,0xffffffff` |
| `1002b633` | `8b ca` | `MOV ECX,EDX` |
| `1002b635` | `d3 e6` | `SHL ESI,CL` |
| `1002b637` | `c7 45 fc 20 00 00 00` | `MOV dword ptr [EBP + -0x4],0x20` |
| `1002b63e` | `29 55 fc` | `SUB dword ptr [EBP + -0x4],EDX` |
| `1002b641` | `f7 d6` | `NOT ESI` |
| `1002b643` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002b646` | `8b 7c 8d e0` | `MOV EDI,dword ptr [EBP + ECX*0x4 + -0x20]` |
| `1002b64a` | `8b cf` | `MOV ECX,EDI` |
| `1002b64c` | `23 ce` | `AND ECX,ESI` |
| `1002b64e` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002b651` | `8b ca` | `MOV ECX,EDX` |
| `1002b653` | `d3 ef` | `SHR EDI,CL` |
| `1002b655` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002b658` | `0b 7d f4` | `OR EDI,dword ptr [EBP + -0xc]` |
| `1002b65b` | `89 7c 8d e0` | `MOV dword ptr [EBP + ECX*0x4 + -0x20],EDI` |
| `1002b65f` | `8b 7d f0` | `MOV EDI,dword ptr [EBP + -0x10]` |
| `1002b662` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002b665` | `d3 e7` | `SHL EDI,CL` |
| `1002b667` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1002b66a` | `83 7d 08 03` | `CMP dword ptr [EBP + 0x8],0x3` |
| `1002b66e` | `89 7d f4` | `MOV dword ptr [EBP + -0xc],EDI` |
| `1002b671` | `7c d0` | `JL 0x1002b643` |
| `1002b673` | `8b f0` | `MOV ESI,EAX` |
| `1002b675` | `6a 02` | `PUSH 0x2` |
| `1002b677` | `c1 e6 02` | `SHL ESI,0x2` |
| `1002b67a` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1002b67d` | `5a` | `POP EDX` |
| `1002b67e` | `2b ce` | `SUB ECX,ESI` |
| `1002b680` | `3b d0` | `CMP EDX,EAX` |
| `1002b682` | `7c 08` | `JL 0x1002b68c` |
| `1002b684` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1002b686` | `89 74 95 e0` | `MOV dword ptr [EBP + EDX*0x4 + -0x20],ESI` |
| `1002b68a` | `eb 05` | `JMP 0x1002b691` |
| `1002b68c` | `83 64 95 e0 00` | `AND dword ptr [EBP + EDX*0x4 + -0x20],0x0` |
| `1002b691` | `4a` | `DEC EDX` |
| `1002b692` | `83 e9 04` | `SUB ECX,0x4` |
| `1002b695` | `85 d2` | `TEST EDX,EDX` |
| `1002b697` | `7d e7` | `JGE 0x1002b680` |
| `1002b699` | `33 c0` | `XOR EAX,EAX` |
| `1002b69b` | `5e` | `POP ESI` |
| `1002b69c` | `6a 1f` | `PUSH 0x1f` |
| `1002b69e` | `59` | `POP ECX` |
| `1002b69f` | `2b 0d 1c 87 03 10` | `SUB ECX,dword ptr [0x1003871c]` |
| `1002b6a5` | `d3 e3` | `SHL EBX,CL` |
| `1002b6a7` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `1002b6aa` | `f7 d9` | `NEG ECX` |
| `1002b6ac` | `1b c9` | `SBB ECX,ECX` |
| `1002b6ae` | `81 e1 00 00 00 80` | `AND ECX,0x80000000` |
| `1002b6b4` | `0b d9` | `OR EBX,ECX` |
| `1002b6b6` | `8b 0d 20 87 03 10` | `MOV ECX,dword ptr [0x10038720]` |
| `1002b6bc` | `0b 5d e0` | `OR EBX,dword ptr [EBP + -0x20]` |
| `1002b6bf` | `83 f9 40` | `CMP ECX,0x40` |
| `1002b6c2` | `75 0d` | `JNZ 0x1002b6d1` |
| `1002b6c4` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1002b6c7` | `8b 55 e4` | `MOV EDX,dword ptr [EBP + -0x1c]` |
| `1002b6ca` | `89 59 04` | `MOV dword ptr [ECX + 0x4],EBX` |
| `1002b6cd` | `89 11` | `MOV dword ptr [ECX],EDX` |
| `1002b6cf` | `eb 0a` | `JMP 0x1002b6db` |
| `1002b6d1` | `83 f9 20` | `CMP ECX,0x20` |
| `1002b6d4` | `75 05` | `JNZ 0x1002b6db` |
| `1002b6d6` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1002b6d9` | `89 19` | `MOV dword ptr [ECX],EBX` |
| `1002b6db` | `5f` | `POP EDI` |
| `1002b6dc` | `5b` | `POP EBX` |
| `1002b6dd` | `c9` | `LEAVE` |
| `1002b6de` | `c3` | `RET` |
