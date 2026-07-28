# 10012dd5 `_memcmp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012dd5 |
| `name` | _memcmp |
| `namespace` | Global |
| `signature` | int __cdecl _memcmp(void * _Buf1, void * _Buf2, size_t _Size) |
| `size_bytes` | 5632 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _memcmp |

## Decompiled C

```c

/* Library Function - Single Match
    _memcmp
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2019 Release */

int __cdecl _memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (_Size == 0) {
    return 0;
  }
  if (_Size == 1) {
    uVar2 = (uint)*(byte *)_Buf1;
    uVar3 = (uint)*(byte *)_Buf2;
LAB_1001432e:
    if (uVar2 == uVar3) {
      return 0;
    }
    return (uint)(0 < (int)(uVar2 - uVar3)) * 2 + -1;
  }
  if (_Size == 2) {
    uVar2 = (uint)*(byte *)_Buf1;
    uVar3 = (uint)*(byte *)_Buf2;
    if ((uVar2 != uVar3) &&
       (iVar1 = (uint)(uVar2 != uVar3 && -1 < (int)(uVar2 - uVar3)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)_Buf1 + 1);
    uVar3 = (uint)*(byte *)((int)_Buf2 + 1);
    goto LAB_1001432e;
  }
  if (_Size == 3) {
    uVar2 = (uint)*(byte *)_Buf1;
    uVar3 = (uint)*(byte *)_Buf2;
    if ((uVar2 != uVar3) &&
       (iVar1 = (uint)(uVar2 != uVar3 && -1 < (int)(uVar2 - uVar3)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)_Buf1 + 1);
    uVar3 = (uint)*(byte *)((int)_Buf2 + 1);
    if ((uVar2 != uVar3) &&
       (iVar1 = (uint)(uVar2 != uVar3 && -1 < (int)(uVar2 - uVar3)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)_Buf1 + 2);
    uVar3 = (uint)*(byte *)((int)_Buf2 + 2);
    goto LAB_1001432e;
  }
  if (_Size == 4) {
    uVar2 = (uint)*(byte *)_Buf1;
    uVar3 = (uint)*(byte *)_Buf2;
    if ((uVar2 != uVar3) &&
       (iVar1 = (uint)(uVar2 != uVar3 && -1 < (int)(uVar2 - uVar3)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)_Buf1 + 1);
    uVar3 = (uint)*(byte *)((int)_Buf2 + 1);
    if ((uVar2 != uVar3) &&
       (iVar1 = (uint)(uVar2 != uVar3 && -1 < (int)(uVar2 - uVar3)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)_Buf1 + 2);
    uVar3 = (uint)*(byte *)((int)_Buf2 + 2);
    if ((uVar2 != uVar3) &&
       (iVar1 = (uint)(uVar2 != uVar3 && -1 < (int)(uVar2 - uVar3)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    uVar2 = (uint)*(byte *)((int)_Buf1 + 3);
    uVar3 = (uint)*(byte *)((int)_Buf2 + 3);
    goto LAB_1001432e;
  }
  for (; 0x1f < _Size; _Size = _Size - 0x20) {
    if (*(int *)_Buf1 == *(int *)_Buf2) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)_Buf1;
      uVar2 = (uint)*(byte *)_Buf2;
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 1);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 1);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 2);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 2);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 3) != (uint)*(byte *)((int)_Buf2 + 3)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 3) - (uint)*(byte *)((int)_Buf2 + 3)))
                * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 4) == *(int *)((int)_Buf2 + 4)) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)((int)_Buf1 + 4);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 4);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 5);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 5);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 6);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 6);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 7) != (uint)*(byte *)((int)_Buf2 + 7)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 7) - (uint)*(byte *)((int)_Buf2 + 7)))
                * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 8) == *(int *)((int)_Buf2 + 8)) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)((int)_Buf1 + 8);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 8);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 9);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 9);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 10);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 10);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 0xb) != (uint)*(byte *)((int)_Buf2 + 0xb)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 0xb) -
                                (uint)*(byte *)((int)_Buf2 + 0xb))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 0xc) == *(int *)((int)_Buf2 + 0xc)) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0xc);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0xc);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0xd);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0xd);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0xe);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0xe);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 0xf) != (uint)*(byte *)((int)_Buf2 + 0xf)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 0xf) -
                                (uint)*(byte *)((int)_Buf2 + 0xf))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 0x10) == *(int *)((int)_Buf2 + 0x10)) {
      iVar1 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x10);
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x10);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x11);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x11);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x12);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x12);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 0x13) != (uint)*(byte *)((int)_Buf2 + 0x13)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 0x13) -
                                (uint)*(byte *)((int)_Buf2 + 0x13))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 0x14) == *(int *)((int)_Buf2 + 0x14)) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x14);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x14);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x15);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x15);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x16);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x16);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 0x17) != (uint)*(byte *)((int)_Buf2 + 0x17)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 0x17) -
                                (uint)*(byte *)((int)_Buf2 + 0x17))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 0x18) == *(int *)((int)_Buf2 + 0x18)) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x18);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x18);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x19);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x19);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x1a);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x1a);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 0x1b) != (uint)*(byte *)((int)_Buf2 + 0x1b)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 0x1b) -
                                (uint)*(byte *)((int)_Buf2 + 0x1b))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)((int)_Buf1 + 0x1c) == *(int *)((int)_Buf2 + 0x1c)) {
      iVar1 = 0;
    }
    else {
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x1c);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x1c);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x1d);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x1d);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + 0x1e);
      uVar2 = (uint)*(byte *)((int)_Buf2 + 0x1e);
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + 0x1f) != (uint)*(byte *)((int)_Buf2 + 0x1f)) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + 0x1f) -
                                (uint)*(byte *)((int)_Buf2 + 0x1f))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    _Buf1 = (void *)((int)_Buf1 + 0x20);
    _Buf2 = (void *)((int)_Buf2 + 0x20);
  }
  switch(_Size) {
  default:
    goto switchD_1001329c_caseD_0;
  case 1:
    goto switchD_1001329c_caseD_1;
  case 2:
    goto switchD_1001329c_caseD_2;
  case 3:
    goto switchD_1001329c_caseD_3;
  case 4:
    goto switchD_1001329c_caseD_4;
  case 5:
    goto switchD_1001329c_caseD_5;
  case 6:
    goto switchD_1001329c_caseD_6;
  case 7:
    goto switchD_1001329c_caseD_7;
  case 8:
    goto switchD_1001329c_caseD_8;
  case 9:
    goto switchD_1001329c_caseD_9;
  case 10:
    goto switchD_1001329c_caseD_a;
  case 0xb:
    goto switchD_1001329c_caseD_b;
  case 0xc:
    goto switchD_1001329c_caseD_c;
  case 0xd:
    goto switchD_1001329c_caseD_d;
  case 0xe:
    goto switchD_1001329c_caseD_e;
  case 0xf:
    goto switchD_1001329c_caseD_f;
  case 0x10:
    goto switchD_1001329c_caseD_10;
  case 0x11:
    goto switchD_1001329c_caseD_11;
  case 0x12:
    goto switchD_1001329c_caseD_12;
  case 0x13:
    goto switchD_1001329c_caseD_13;
  case 0x14:
    goto switchD_1001329c_caseD_14;
  case 0x15:
    goto switchD_1001329c_caseD_15;
  case 0x16:
    goto switchD_1001329c_caseD_16;
  case 0x17:
    goto switchD_1001329c_caseD_17;
  case 0x18:
    goto switchD_1001329c_caseD_18;
  case 0x1a:
    goto switchD_1001329c_caseD_1a;
  case 0x1b:
    goto switchD_1001329c_caseD_1b;
  case 0x1c:
    if (*(uint *)((int)_Buf1 + (_Size - 0x1c)) == *(uint *)((int)_Buf2 + (_Size - 0x1c))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x1c)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1c));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1b));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1b));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1a));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1a));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x19)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x19))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x19)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x19)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_18:
    if (*(uint *)((int)_Buf1 + (_Size - 0x18)) == *(uint *)((int)_Buf2 + (_Size - 0x18))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x18)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x18));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x17));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x17));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x16));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x16));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x15)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x15))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x15)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x15)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_14:
    if (*(uint *)((int)_Buf1 + (_Size - 0x14)) == *(uint *)((int)_Buf2 + (_Size - 0x14))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x14)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x14));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x13));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x13));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x12));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x12));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x11)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x11))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x11)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x11)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_10:
    if (*(uint *)((int)_Buf1 + (_Size - 0x10)) == *(uint *)((int)_Buf2 + (_Size - 0x10))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x10)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x10));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xf));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xf));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xe));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xe));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0xd)) != (uint)*(byte *)((int)_Buf2 + (_Size - 0xd))
         ) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0xd)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0xd)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_c:
    if (*(int *)((int)_Buf1 + (_Size - 0xc)) == *(int *)((int)_Buf2 + (_Size - 0xc))) {
      iVar1 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xc));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xc));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xb));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xb));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 10));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 10));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 9)) != (uint)*(byte *)((int)_Buf2 + (_Size - 9))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 9)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 9)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_8:
    if (*(uint *)((int)_Buf1 + (_Size - 8)) == *(uint *)((int)_Buf2 + (_Size - 8))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 8)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 8));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 7));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 7));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 6));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 6));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 5)) != (uint)*(byte *)((int)_Buf2 + (_Size - 5))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 5)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 5)))) * 2 + -1;
      }
    }
    if (iVar1 == 0) {
switchD_1001329c_caseD_4:
      if (*(uint *)((int)_Buf1 + (_Size - 4)) == *(uint *)((int)_Buf2 + (_Size - 4))) {
        iVar1 = 0;
      }
      else {
        uVar3 = *(uint *)((int)_Buf1 + (_Size - 4)) & 0xff;
        uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 4));
        if ((uVar3 == uVar2) ||
           (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 == 0)) {
          uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 3));
          uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 3));
          if ((uVar3 == uVar2) ||
             (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 == 0)) {
            uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 2));
            uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 2));
            if ((uVar3 == uVar2) ||
               (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 == 0)) {
              iVar1 = 0;
              if ((uint)*(byte *)((int)_Buf1 + (_Size - 1)) !=
                  (uint)*(byte *)((int)_Buf2 + (_Size - 1))) {
                iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 1)) -
                                        (uint)*(byte *)((int)_Buf2 + (_Size - 1)))) * 2 + -1;
              }
            }
          }
        }
      }
      if (iVar1 == 0) {
switchD_1001329c_caseD_0:
        iVar1 = 0;
      }
    }
    return iVar1;
  case 0x1d:
    if (*(uint *)((int)_Buf1 + (_Size - 0x1d)) == *(uint *)((int)_Buf2 + (_Size - 0x1d))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x1d)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1d));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1c));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1c));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1b));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1b));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x1a)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x1a))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x1a)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x1a)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  case 0x19:
    if (*(uint *)((int)_Buf1 + (_Size - 0x19)) == *(uint *)((int)_Buf2 + (_Size - 0x19))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x19)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x19));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x18));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x18));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x17));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x17));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x16)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x16))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x16)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x16)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_15:
    if (*(uint *)((int)_Buf1 + (_Size - 0x15)) == *(uint *)((int)_Buf2 + (_Size - 0x15))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x15)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x15));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x14));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x14));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x13));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x13));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x12)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x12))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x12)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x12)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_11:
    if (*(uint *)((int)_Buf1 + (_Size - 0x11)) == *(uint *)((int)_Buf2 + (_Size - 0x11))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x11)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x11));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x10));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x10));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xf));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xf));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0xe)) != (uint)*(byte *)((int)_Buf2 + (_Size - 0xe))
         ) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0xe)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0xe)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_d:
    if (*(uint *)((int)_Buf1 + (_Size - 0xd)) == *(uint *)((int)_Buf2 + (_Size - 0xd))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0xd)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xd));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xc));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xc));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xb));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xb));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 10)) != (uint)*(byte *)((int)_Buf2 + (_Size - 10)))
      {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 10)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 10)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_9:
    if (*(int *)((int)_Buf1 + (_Size - 9)) == *(int *)((int)_Buf2 + (_Size - 9))) {
      iVar1 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 9));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 9));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 8));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 8));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 7));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 7));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 6)) != (uint)*(byte *)((int)_Buf2 + (_Size - 6))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 6)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 6)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_5:
    if (*(uint *)((int)_Buf1 + (_Size - 5)) == *(uint *)((int)_Buf2 + (_Size - 5))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 5)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 5));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 4));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 4));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 3));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 3));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 2)) != (uint)*(byte *)((int)_Buf2 + (_Size - 2))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 2)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 2)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_1:
    if ((uint)*(byte *)((int)_Buf1 + (_Size - 1)) == (uint)*(byte *)((int)_Buf2 + (_Size - 1))) {
      return 0;
    }
    return (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 1)) -
                           (uint)*(byte *)((int)_Buf2 + (_Size - 1)))) * 2 + -1;
  case 0x1e:
    if (*(uint *)((int)_Buf1 + (_Size - 0x1e)) == *(uint *)((int)_Buf2 + (_Size - 0x1e))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x1e)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1e));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1d));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1d));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1c));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1c));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x1b)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x1b))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x1b)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x1b)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_1a:
    if (*(uint *)((int)_Buf1 + (_Size - 0x1a)) == *(uint *)((int)_Buf2 + (_Size - 0x1a))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x1a)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1a));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x19));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x19));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x18));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x18));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x17)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x17))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x17)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x17)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_16:
    if (*(uint *)((int)_Buf1 + (_Size - 0x16)) == *(uint *)((int)_Buf2 + (_Size - 0x16))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x16)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x16));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x15));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x15));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x14));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x14));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x13)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x13))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x13)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x13)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_12:
    if (*(uint *)((int)_Buf1 + (_Size - 0x12)) == *(uint *)((int)_Buf2 + (_Size - 0x12))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x12)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x12));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x11));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x11));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x10));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x10));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0xf)) != (uint)*(byte *)((int)_Buf2 + (_Size - 0xf))
         ) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0xf)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0xf)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_e:
    if (*(uint *)((int)_Buf1 + (_Size - 0xe)) == *(uint *)((int)_Buf2 + (_Size - 0xe))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0xe)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xe));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xd));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xd));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xc));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xc));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0xb)) != (uint)*(byte *)((int)_Buf2 + (_Size - 0xb))
         ) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0xb)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0xb)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_a:
    if (*(int *)((int)_Buf1 + (_Size - 10)) == *(int *)((int)_Buf2 + (_Size - 10))) {
      iVar1 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 10));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 10));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 9));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 9));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 8));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 8));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 7)) != (uint)*(byte *)((int)_Buf2 + (_Size - 7))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 7)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 7)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_6:
    if (*(uint *)((int)_Buf1 + (_Size - 6)) == *(uint *)((int)_Buf2 + (_Size - 6))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 6)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 6));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 5));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 5));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 4));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 4));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 3)) != (uint)*(byte *)((int)_Buf2 + (_Size - 3))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 3)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 3)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_2:
    if (*(short *)((int)_Buf1 + (_Size - 2)) != *(short *)((int)_Buf2 + (_Size - 2))) {
LAB_10013e82:
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 2));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 2));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      goto switchD_1001329c_caseD_1;
    }
    goto switchD_1001329c_caseD_0;
  case 0x1f:
    if (*(int *)((int)_Buf1 + (_Size - 0x1f)) == *(int *)((int)_Buf2 + (_Size - 0x1f))) {
      iVar1 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1f));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1f));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1e));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1e));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1d));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1d));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x1c)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x1c))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x1c)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x1c)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_1b:
    if (*(uint *)((int)_Buf1 + (_Size - 0x1b)) == *(uint *)((int)_Buf2 + (_Size - 0x1b))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x1b)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1b));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x1a));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x1a));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x19));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x19));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x18)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x18))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x18)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x18)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_17:
    if (*(uint *)((int)_Buf1 + (_Size - 0x17)) == *(uint *)((int)_Buf2 + (_Size - 0x17))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x17)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x17));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x16));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x16));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x15));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x15));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x14)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x14))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x14)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x14)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_13:
    if (*(uint *)((int)_Buf1 + (_Size - 0x13)) == *(uint *)((int)_Buf2 + (_Size - 0x13))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0x13)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x13));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x12));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x12));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0x11));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0x11));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0x10)) !=
          (uint)*(byte *)((int)_Buf2 + (_Size - 0x10))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0x10)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0x10)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_f:
    if (*(int *)((int)_Buf1 + (_Size - 0xf)) == *(int *)((int)_Buf2 + (_Size - 0xf))) {
      iVar1 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xf));
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xf));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xe));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xe));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 0xd));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xd));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 0xc)) != (uint)*(byte *)((int)_Buf2 + (_Size - 0xc))
         ) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 0xc)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 0xc)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_b:
    if (*(uint *)((int)_Buf1 + (_Size - 0xb)) == *(uint *)((int)_Buf2 + (_Size - 0xb))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 0xb)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 0xb));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 10));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 10));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 9));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 9));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 8)) != (uint)*(byte *)((int)_Buf2 + (_Size - 8))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 8)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 8)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_7:
    if (*(uint *)((int)_Buf1 + (_Size - 7)) == *(uint *)((int)_Buf2 + (_Size - 7))) {
      iVar1 = 0;
    }
    else {
      uVar3 = *(uint *)((int)_Buf1 + (_Size - 7)) & 0xff;
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 7));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 6));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 6));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 5));
      uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 5));
      if ((uVar3 != uVar2) &&
         (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = 0;
      if ((uint)*(byte *)((int)_Buf1 + (_Size - 4)) != (uint)*(byte *)((int)_Buf2 + (_Size - 4))) {
        iVar1 = (uint)(0 < (int)((uint)*(byte *)((int)_Buf1 + (_Size - 4)) -
                                (uint)*(byte *)((int)_Buf2 + (_Size - 4)))) * 2 + -1;
      }
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_1001329c_caseD_3:
    uVar3 = (uint)*(byte *)((int)_Buf1 + (_Size - 3));
    uVar2 = (uint)*(byte *)((int)_Buf2 + (_Size - 3));
    if ((uVar3 != uVar2) &&
       (iVar1 = (uint)(uVar3 != uVar2 && -1 < (int)(uVar3 - uVar2)) * 2 + -1, iVar1 != 0)) {
      return iVar1;
    }
    goto LAB_10013e82;
  }
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100220b6` | FUN_10022020 |
| `100221aa` | FUN_10022020 |
| `10023c0d` | FUN_100239f0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001329c` | `100143d5` | `DATA` | switchD_1001329c::switchdataD_100143d5 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012dd5` | `8b ff` | `MOV EDI,EDI` |
| `10012dd7` | `55` | `PUSH EBP` |
| `10012dd8` | `8b ec` | `MOV EBP,ESP` |
| `10012dda` | `56` | `PUSH ESI` |
| `10012ddb` | `57` | `PUSH EDI` |
| `10012ddc` | `8b 7d 10` | `MOV EDI,dword ptr [EBP + 0x10]` |
| `10012ddf` | `8b c7` | `MOV EAX,EDI` |
| `10012de1` | `83 e8 00` | `SUB EAX,0x0` |
| `10012de4` | `0f 84 e5 15 00 00` | `JZ 0x100143cf` |
| `10012dea` | `48` | `DEC EAX` |
| `10012deb` | `0f 84 cd 15 00 00` | `JZ 0x100143be` |
| `10012df1` | `48` | `DEC EAX` |
| `10012df2` | `0f 84 98 15 00 00` | `JZ 0x10014390` |
| `10012df8` | `48` | `DEC EAX` |
| `10012df9` | `0f 84 49 15 00 00` | `JZ 0x10014348` |
| `10012dff` | `48` | `DEC EAX` |
| `10012e00` | `0f 84 b9 14 00 00` | `JZ 0x100142bf` |
| `10012e06` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10012e09` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10012e0c` | `53` | `PUSH EBX` |
| `10012e0d` | `6a 20` | `PUSH 0x20` |
| `10012e0f` | `5a` | `POP EDX` |
| `10012e10` | `e9 72 04 00 00` | `JMP 0x10013287` |
| `10012e15` | `8b 30` | `MOV ESI,dword ptr [EAX]` |
| `10012e17` | `3b 31` | `CMP ESI,dword ptr [ECX]` |
| `10012e19` | `74 7c` | `JZ 0x10012e97` |
| `10012e1b` | `0f b6 30` | `MOVZX ESI,byte ptr [EAX]` |
| `10012e1e` | `0f b6 19` | `MOVZX EBX,byte ptr [ECX]` |
| `10012e21` | `2b f3` | `SUB ESI,EBX` |
| `10012e23` | `74 15` | `JZ 0x10012e3a` |
| `10012e25` | `33 db` | `XOR EBX,EBX` |
| `10012e27` | `85 f6` | `TEST ESI,ESI` |
| `10012e29` | `0f 9f c3` | `SETG BL` |
| `10012e2c` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012e30` | `8b f3` | `MOV ESI,EBX` |
| `10012e32` | `85 f6` | `TEST ESI,ESI` |
| `10012e34` | `0f 85 69 04 00 00` | `JNZ 0x100132a3` |
| `10012e3a` | `0f b6 70 01` | `MOVZX ESI,byte ptr [EAX + 0x1]` |
| `10012e3e` | `0f b6 59 01` | `MOVZX EBX,byte ptr [ECX + 0x1]` |
| `10012e42` | `2b f3` | `SUB ESI,EBX` |
| `10012e44` | `74 15` | `JZ 0x10012e5b` |
| `10012e46` | `33 db` | `XOR EBX,EBX` |
| `10012e48` | `85 f6` | `TEST ESI,ESI` |
| `10012e4a` | `0f 9f c3` | `SETG BL` |
| `10012e4d` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012e51` | `8b f3` | `MOV ESI,EBX` |
| `10012e53` | `85 f6` | `TEST ESI,ESI` |
| `10012e55` | `0f 85 48 04 00 00` | `JNZ 0x100132a3` |
| `10012e5b` | `0f b6 70 02` | `MOVZX ESI,byte ptr [EAX + 0x2]` |
| `10012e5f` | `0f b6 59 02` | `MOVZX EBX,byte ptr [ECX + 0x2]` |
| `10012e63` | `2b f3` | `SUB ESI,EBX` |
| `10012e65` | `74 15` | `JZ 0x10012e7c` |
| `10012e67` | `33 db` | `XOR EBX,EBX` |
| `10012e69` | `85 f6` | `TEST ESI,ESI` |
| `10012e6b` | `0f 9f c3` | `SETG BL` |
| `10012e6e` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012e72` | `8b f3` | `MOV ESI,EBX` |
| `10012e74` | `85 f6` | `TEST ESI,ESI` |
| `10012e76` | `0f 85 27 04 00 00` | `JNZ 0x100132a3` |
| `10012e7c` | `0f b6 70 03` | `MOVZX ESI,byte ptr [EAX + 0x3]` |
| `10012e80` | `0f b6 59 03` | `MOVZX EBX,byte ptr [ECX + 0x3]` |
| `10012e84` | `2b f3` | `SUB ESI,EBX` |
| `10012e86` | `74 11` | `JZ 0x10012e99` |
| `10012e88` | `33 db` | `XOR EBX,EBX` |
| `10012e8a` | `85 f6` | `TEST ESI,ESI` |
| `10012e8c` | `0f 9f c3` | `SETG BL` |
| `10012e8f` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012e93` | `8b f3` | `MOV ESI,EBX` |
| `10012e95` | `eb 02` | `JMP 0x10012e99` |
| `10012e97` | `33 f6` | `XOR ESI,ESI` |
| `10012e99` | `85 f6` | `TEST ESI,ESI` |
| `10012e9b` | `0f 85 02 04 00 00` | `JNZ 0x100132a3` |
| `10012ea1` | `8b 70 04` | `MOV ESI,dword ptr [EAX + 0x4]` |
| `10012ea4` | `3b 71 04` | `CMP ESI,dword ptr [ECX + 0x4]` |
| `10012ea7` | `74 7e` | `JZ 0x10012f27` |
| `10012ea9` | `0f b6 70 04` | `MOVZX ESI,byte ptr [EAX + 0x4]` |
| `10012ead` | `0f b6 59 04` | `MOVZX EBX,byte ptr [ECX + 0x4]` |
| `10012eb1` | `2b f3` | `SUB ESI,EBX` |
| `10012eb3` | `74 15` | `JZ 0x10012eca` |
| `10012eb5` | `33 db` | `XOR EBX,EBX` |
| `10012eb7` | `85 f6` | `TEST ESI,ESI` |
| `10012eb9` | `0f 9f c3` | `SETG BL` |
| `10012ebc` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012ec0` | `8b f3` | `MOV ESI,EBX` |
| `10012ec2` | `85 f6` | `TEST ESI,ESI` |
| `10012ec4` | `0f 85 d9 03 00 00` | `JNZ 0x100132a3` |
| `10012eca` | `0f b6 70 05` | `MOVZX ESI,byte ptr [EAX + 0x5]` |
| `10012ece` | `0f b6 59 05` | `MOVZX EBX,byte ptr [ECX + 0x5]` |
| `10012ed2` | `2b f3` | `SUB ESI,EBX` |
| `10012ed4` | `74 15` | `JZ 0x10012eeb` |
| `10012ed6` | `33 db` | `XOR EBX,EBX` |
| `10012ed8` | `85 f6` | `TEST ESI,ESI` |
| `10012eda` | `0f 9f c3` | `SETG BL` |
| `10012edd` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012ee1` | `8b f3` | `MOV ESI,EBX` |
| `10012ee3` | `85 f6` | `TEST ESI,ESI` |
| `10012ee5` | `0f 85 b8 03 00 00` | `JNZ 0x100132a3` |
| `10012eeb` | `0f b6 70 06` | `MOVZX ESI,byte ptr [EAX + 0x6]` |
| `10012eef` | `0f b6 59 06` | `MOVZX EBX,byte ptr [ECX + 0x6]` |
| `10012ef3` | `2b f3` | `SUB ESI,EBX` |
| `10012ef5` | `74 15` | `JZ 0x10012f0c` |
| `10012ef7` | `33 db` | `XOR EBX,EBX` |
| `10012ef9` | `85 f6` | `TEST ESI,ESI` |
| `10012efb` | `0f 9f c3` | `SETG BL` |
| `10012efe` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012f02` | `8b f3` | `MOV ESI,EBX` |
| `10012f04` | `85 f6` | `TEST ESI,ESI` |
| `10012f06` | `0f 85 97 03 00 00` | `JNZ 0x100132a3` |
| `10012f0c` | `0f b6 70 07` | `MOVZX ESI,byte ptr [EAX + 0x7]` |
| `10012f10` | `0f b6 59 07` | `MOVZX EBX,byte ptr [ECX + 0x7]` |
| `10012f14` | `2b f3` | `SUB ESI,EBX` |
| `10012f16` | `74 11` | `JZ 0x10012f29` |
| `10012f18` | `33 db` | `XOR EBX,EBX` |
| `10012f1a` | `85 f6` | `TEST ESI,ESI` |
| `10012f1c` | `0f 9f c3` | `SETG BL` |
| `10012f1f` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012f23` | `8b f3` | `MOV ESI,EBX` |
| `10012f25` | `eb 02` | `JMP 0x10012f29` |
| `10012f27` | `33 f6` | `XOR ESI,ESI` |
| `10012f29` | `85 f6` | `TEST ESI,ESI` |
| `10012f2b` | `0f 85 72 03 00 00` | `JNZ 0x100132a3` |
| `10012f31` | `8b 70 08` | `MOV ESI,dword ptr [EAX + 0x8]` |
| `10012f34` | `3b 71 08` | `CMP ESI,dword ptr [ECX + 0x8]` |
| `10012f37` | `74 7e` | `JZ 0x10012fb7` |
| `10012f39` | `0f b6 70 08` | `MOVZX ESI,byte ptr [EAX + 0x8]` |
| `10012f3d` | `0f b6 59 08` | `MOVZX EBX,byte ptr [ECX + 0x8]` |
| `10012f41` | `2b f3` | `SUB ESI,EBX` |
| `10012f43` | `74 15` | `JZ 0x10012f5a` |
| `10012f45` | `33 db` | `XOR EBX,EBX` |
| `10012f47` | `85 f6` | `TEST ESI,ESI` |
| `10012f49` | `0f 9f c3` | `SETG BL` |
| `10012f4c` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012f50` | `8b f3` | `MOV ESI,EBX` |
| `10012f52` | `85 f6` | `TEST ESI,ESI` |
| `10012f54` | `0f 85 49 03 00 00` | `JNZ 0x100132a3` |
| `10012f5a` | `0f b6 70 09` | `MOVZX ESI,byte ptr [EAX + 0x9]` |
| `10012f5e` | `0f b6 59 09` | `MOVZX EBX,byte ptr [ECX + 0x9]` |
| `10012f62` | `2b f3` | `SUB ESI,EBX` |
| `10012f64` | `74 15` | `JZ 0x10012f7b` |
| `10012f66` | `33 db` | `XOR EBX,EBX` |
| `10012f68` | `85 f6` | `TEST ESI,ESI` |
| `10012f6a` | `0f 9f c3` | `SETG BL` |
| `10012f6d` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012f71` | `8b f3` | `MOV ESI,EBX` |
| `10012f73` | `85 f6` | `TEST ESI,ESI` |
| `10012f75` | `0f 85 28 03 00 00` | `JNZ 0x100132a3` |
| `10012f7b` | `0f b6 70 0a` | `MOVZX ESI,byte ptr [EAX + 0xa]` |
| `10012f7f` | `0f b6 59 0a` | `MOVZX EBX,byte ptr [ECX + 0xa]` |
| `10012f83` | `2b f3` | `SUB ESI,EBX` |
| `10012f85` | `74 15` | `JZ 0x10012f9c` |
| `10012f87` | `33 db` | `XOR EBX,EBX` |
| `10012f89` | `85 f6` | `TEST ESI,ESI` |
| `10012f8b` | `0f 9f c3` | `SETG BL` |
| `10012f8e` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012f92` | `8b f3` | `MOV ESI,EBX` |
| `10012f94` | `85 f6` | `TEST ESI,ESI` |
| `10012f96` | `0f 85 07 03 00 00` | `JNZ 0x100132a3` |
| `10012f9c` | `0f b6 70 0b` | `MOVZX ESI,byte ptr [EAX + 0xb]` |
| `10012fa0` | `0f b6 59 0b` | `MOVZX EBX,byte ptr [ECX + 0xb]` |
| `10012fa4` | `2b f3` | `SUB ESI,EBX` |
| `10012fa6` | `74 11` | `JZ 0x10012fb9` |
| `10012fa8` | `33 db` | `XOR EBX,EBX` |
| `10012faa` | `85 f6` | `TEST ESI,ESI` |
| `10012fac` | `0f 9f c3` | `SETG BL` |
| `10012faf` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012fb3` | `8b f3` | `MOV ESI,EBX` |
| `10012fb5` | `eb 02` | `JMP 0x10012fb9` |
| `10012fb7` | `33 f6` | `XOR ESI,ESI` |
| `10012fb9` | `85 f6` | `TEST ESI,ESI` |
| `10012fbb` | `0f 85 e2 02 00 00` | `JNZ 0x100132a3` |
| `10012fc1` | `8b 70 0c` | `MOV ESI,dword ptr [EAX + 0xc]` |
| `10012fc4` | `3b 71 0c` | `CMP ESI,dword ptr [ECX + 0xc]` |
| `10012fc7` | `74 7e` | `JZ 0x10013047` |
| `10012fc9` | `0f b6 70 0c` | `MOVZX ESI,byte ptr [EAX + 0xc]` |
| `10012fcd` | `0f b6 59 0c` | `MOVZX EBX,byte ptr [ECX + 0xc]` |
| `10012fd1` | `2b f3` | `SUB ESI,EBX` |
| `10012fd3` | `74 15` | `JZ 0x10012fea` |
| `10012fd5` | `33 db` | `XOR EBX,EBX` |
| `10012fd7` | `85 f6` | `TEST ESI,ESI` |
| `10012fd9` | `0f 9f c3` | `SETG BL` |
| `10012fdc` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10012fe0` | `8b f3` | `MOV ESI,EBX` |
| `10012fe2` | `85 f6` | `TEST ESI,ESI` |
| `10012fe4` | `0f 85 b9 02 00 00` | `JNZ 0x100132a3` |
| `10012fea` | `0f b6 70 0d` | `MOVZX ESI,byte ptr [EAX + 0xd]` |
| `10012fee` | `0f b6 59 0d` | `MOVZX EBX,byte ptr [ECX + 0xd]` |
| `10012ff2` | `2b f3` | `SUB ESI,EBX` |
| `10012ff4` | `74 15` | `JZ 0x1001300b` |
| `10012ff6` | `33 db` | `XOR EBX,EBX` |
| `10012ff8` | `85 f6` | `TEST ESI,ESI` |
| `10012ffa` | `0f 9f c3` | `SETG BL` |
| `10012ffd` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013001` | `8b f3` | `MOV ESI,EBX` |
| `10013003` | `85 f6` | `TEST ESI,ESI` |
| `10013005` | `0f 85 98 02 00 00` | `JNZ 0x100132a3` |
| `1001300b` | `0f b6 70 0e` | `MOVZX ESI,byte ptr [EAX + 0xe]` |
| `1001300f` | `0f b6 59 0e` | `MOVZX EBX,byte ptr [ECX + 0xe]` |
| `10013013` | `2b f3` | `SUB ESI,EBX` |
| `10013015` | `74 15` | `JZ 0x1001302c` |
| `10013017` | `33 db` | `XOR EBX,EBX` |
| `10013019` | `85 f6` | `TEST ESI,ESI` |
| `1001301b` | `0f 9f c3` | `SETG BL` |
| `1001301e` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013022` | `8b f3` | `MOV ESI,EBX` |
| `10013024` | `85 f6` | `TEST ESI,ESI` |
| `10013026` | `0f 85 77 02 00 00` | `JNZ 0x100132a3` |
| `1001302c` | `0f b6 70 0f` | `MOVZX ESI,byte ptr [EAX + 0xf]` |
| `10013030` | `0f b6 59 0f` | `MOVZX EBX,byte ptr [ECX + 0xf]` |
| `10013034` | `2b f3` | `SUB ESI,EBX` |
| `10013036` | `74 11` | `JZ 0x10013049` |
| `10013038` | `33 db` | `XOR EBX,EBX` |
| `1001303a` | `85 f6` | `TEST ESI,ESI` |
| `1001303c` | `0f 9f c3` | `SETG BL` |
| `1001303f` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013043` | `8b f3` | `MOV ESI,EBX` |
| `10013045` | `eb 02` | `JMP 0x10013049` |
| `10013047` | `33 f6` | `XOR ESI,ESI` |
| `10013049` | `85 f6` | `TEST ESI,ESI` |
| `1001304b` | `0f 85 52 02 00 00` | `JNZ 0x100132a3` |
| `10013051` | `8b 70 10` | `MOV ESI,dword ptr [EAX + 0x10]` |
| `10013054` | `3b 71 10` | `CMP ESI,dword ptr [ECX + 0x10]` |
| `10013057` | `74 7e` | `JZ 0x100130d7` |
| `10013059` | `0f b6 59 10` | `MOVZX EBX,byte ptr [ECX + 0x10]` |
| `1001305d` | `0f b6 70 10` | `MOVZX ESI,byte ptr [EAX + 0x10]` |
| `10013061` | `2b f3` | `SUB ESI,EBX` |
| `10013063` | `74 15` | `JZ 0x1001307a` |
| `10013065` | `33 db` | `XOR EBX,EBX` |
| `10013067` | `85 f6` | `TEST ESI,ESI` |
| `10013069` | `0f 9f c3` | `SETG BL` |
| `1001306c` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013070` | `8b f3` | `MOV ESI,EBX` |
| `10013072` | `85 f6` | `TEST ESI,ESI` |
| `10013074` | `0f 85 29 02 00 00` | `JNZ 0x100132a3` |
| `1001307a` | `0f b6 70 11` | `MOVZX ESI,byte ptr [EAX + 0x11]` |
| `1001307e` | `0f b6 59 11` | `MOVZX EBX,byte ptr [ECX + 0x11]` |
| `10013082` | `2b f3` | `SUB ESI,EBX` |
| `10013084` | `74 15` | `JZ 0x1001309b` |
| `10013086` | `33 db` | `XOR EBX,EBX` |
| `10013088` | `85 f6` | `TEST ESI,ESI` |
| `1001308a` | `0f 9f c3` | `SETG BL` |
| `1001308d` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013091` | `8b f3` | `MOV ESI,EBX` |
| `10013093` | `85 f6` | `TEST ESI,ESI` |
| `10013095` | `0f 85 08 02 00 00` | `JNZ 0x100132a3` |
| `1001309b` | `0f b6 70 12` | `MOVZX ESI,byte ptr [EAX + 0x12]` |
| `1001309f` | `0f b6 59 12` | `MOVZX EBX,byte ptr [ECX + 0x12]` |
| `100130a3` | `2b f3` | `SUB ESI,EBX` |
| `100130a5` | `74 15` | `JZ 0x100130bc` |
| `100130a7` | `33 db` | `XOR EBX,EBX` |
| `100130a9` | `85 f6` | `TEST ESI,ESI` |
| `100130ab` | `0f 9f c3` | `SETG BL` |
| `100130ae` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `100130b2` | `8b f3` | `MOV ESI,EBX` |
| `100130b4` | `85 f6` | `TEST ESI,ESI` |
| `100130b6` | `0f 85 e7 01 00 00` | `JNZ 0x100132a3` |
| `100130bc` | `0f b6 70 13` | `MOVZX ESI,byte ptr [EAX + 0x13]` |
| `100130c0` | `0f b6 59 13` | `MOVZX EBX,byte ptr [ECX + 0x13]` |
| `100130c4` | `2b f3` | `SUB ESI,EBX` |
| `100130c6` | `74 11` | `JZ 0x100130d9` |
| `100130c8` | `33 db` | `XOR EBX,EBX` |
| `100130ca` | `85 f6` | `TEST ESI,ESI` |
| `100130cc` | `0f 9f c3` | `SETG BL` |
| `100130cf` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `100130d3` | `8b f3` | `MOV ESI,EBX` |
| `100130d5` | `eb 02` | `JMP 0x100130d9` |
| `100130d7` | `33 f6` | `XOR ESI,ESI` |
| `100130d9` | `85 f6` | `TEST ESI,ESI` |
| `100130db` | `0f 85 c2 01 00 00` | `JNZ 0x100132a3` |
| `100130e1` | `8b 70 14` | `MOV ESI,dword ptr [EAX + 0x14]` |
| `100130e4` | `3b 71 14` | `CMP ESI,dword ptr [ECX + 0x14]` |
| `100130e7` | `74 7e` | `JZ 0x10013167` |
| `100130e9` | `0f b6 70 14` | `MOVZX ESI,byte ptr [EAX + 0x14]` |
| `100130ed` | `0f b6 59 14` | `MOVZX EBX,byte ptr [ECX + 0x14]` |
| `100130f1` | `2b f3` | `SUB ESI,EBX` |
| `100130f3` | `74 15` | `JZ 0x1001310a` |
| `100130f5` | `33 db` | `XOR EBX,EBX` |
| `100130f7` | `85 f6` | `TEST ESI,ESI` |
| `100130f9` | `0f 9f c3` | `SETG BL` |
| `100130fc` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013100` | `8b f3` | `MOV ESI,EBX` |
| `10013102` | `85 f6` | `TEST ESI,ESI` |
| `10013104` | `0f 85 99 01 00 00` | `JNZ 0x100132a3` |
| `1001310a` | `0f b6 70 15` | `MOVZX ESI,byte ptr [EAX + 0x15]` |
| `1001310e` | `0f b6 59 15` | `MOVZX EBX,byte ptr [ECX + 0x15]` |
| `10013112` | `2b f3` | `SUB ESI,EBX` |
| `10013114` | `74 15` | `JZ 0x1001312b` |
| `10013116` | `33 db` | `XOR EBX,EBX` |
| `10013118` | `85 f6` | `TEST ESI,ESI` |
| `1001311a` | `0f 9f c3` | `SETG BL` |
| `1001311d` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013121` | `8b f3` | `MOV ESI,EBX` |
| `10013123` | `85 f6` | `TEST ESI,ESI` |
| `10013125` | `0f 85 78 01 00 00` | `JNZ 0x100132a3` |
| `1001312b` | `0f b6 70 16` | `MOVZX ESI,byte ptr [EAX + 0x16]` |
| `1001312f` | `0f b6 59 16` | `MOVZX EBX,byte ptr [ECX + 0x16]` |
| `10013133` | `2b f3` | `SUB ESI,EBX` |
| `10013135` | `74 15` | `JZ 0x1001314c` |
| `10013137` | `33 db` | `XOR EBX,EBX` |
| `10013139` | `85 f6` | `TEST ESI,ESI` |
| `1001313b` | `0f 9f c3` | `SETG BL` |
| `1001313e` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013142` | `8b f3` | `MOV ESI,EBX` |
| `10013144` | `85 f6` | `TEST ESI,ESI` |
| `10013146` | `0f 85 57 01 00 00` | `JNZ 0x100132a3` |
| `1001314c` | `0f b6 70 17` | `MOVZX ESI,byte ptr [EAX + 0x17]` |
| `10013150` | `0f b6 59 17` | `MOVZX EBX,byte ptr [ECX + 0x17]` |
| `10013154` | `2b f3` | `SUB ESI,EBX` |
| `10013156` | `74 11` | `JZ 0x10013169` |
| `10013158` | `33 db` | `XOR EBX,EBX` |
| `1001315a` | `85 f6` | `TEST ESI,ESI` |
| `1001315c` | `0f 9f c3` | `SETG BL` |
| `1001315f` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013163` | `8b f3` | `MOV ESI,EBX` |
| `10013165` | `eb 02` | `JMP 0x10013169` |
| `10013167` | `33 f6` | `XOR ESI,ESI` |
| `10013169` | `85 f6` | `TEST ESI,ESI` |
| `1001316b` | `0f 85 32 01 00 00` | `JNZ 0x100132a3` |
| `10013171` | `8b 70 18` | `MOV ESI,dword ptr [EAX + 0x18]` |
| `10013174` | `3b 71 18` | `CMP ESI,dword ptr [ECX + 0x18]` |
| `10013177` | `74 7e` | `JZ 0x100131f7` |
| `10013179` | `0f b6 70 18` | `MOVZX ESI,byte ptr [EAX + 0x18]` |
| `1001317d` | `0f b6 59 18` | `MOVZX EBX,byte ptr [ECX + 0x18]` |
| `10013181` | `2b f3` | `SUB ESI,EBX` |
| `10013183` | `74 15` | `JZ 0x1001319a` |
| `10013185` | `33 db` | `XOR EBX,EBX` |
| `10013187` | `85 f6` | `TEST ESI,ESI` |
| `10013189` | `0f 9f c3` | `SETG BL` |
| `1001318c` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013190` | `8b f3` | `MOV ESI,EBX` |
| `10013192` | `85 f6` | `TEST ESI,ESI` |
| `10013194` | `0f 85 09 01 00 00` | `JNZ 0x100132a3` |
| `1001319a` | `0f b6 70 19` | `MOVZX ESI,byte ptr [EAX + 0x19]` |
| `1001319e` | `0f b6 59 19` | `MOVZX EBX,byte ptr [ECX + 0x19]` |
| `100131a2` | `2b f3` | `SUB ESI,EBX` |
| `100131a4` | `74 15` | `JZ 0x100131bb` |
| `100131a6` | `33 db` | `XOR EBX,EBX` |
| `100131a8` | `85 f6` | `TEST ESI,ESI` |
| `100131aa` | `0f 9f c3` | `SETG BL` |
| `100131ad` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `100131b1` | `8b f3` | `MOV ESI,EBX` |
| `100131b3` | `85 f6` | `TEST ESI,ESI` |
| `100131b5` | `0f 85 e8 00 00 00` | `JNZ 0x100132a3` |
| `100131bb` | `0f b6 70 1a` | `MOVZX ESI,byte ptr [EAX + 0x1a]` |
| `100131bf` | `0f b6 59 1a` | `MOVZX EBX,byte ptr [ECX + 0x1a]` |
| `100131c3` | `2b f3` | `SUB ESI,EBX` |
| `100131c5` | `74 15` | `JZ 0x100131dc` |
| `100131c7` | `33 db` | `XOR EBX,EBX` |
| `100131c9` | `85 f6` | `TEST ESI,ESI` |
| `100131cb` | `0f 9f c3` | `SETG BL` |
| `100131ce` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `100131d2` | `8b f3` | `MOV ESI,EBX` |
| `100131d4` | `85 f6` | `TEST ESI,ESI` |
| `100131d6` | `0f 85 c7 00 00 00` | `JNZ 0x100132a3` |
| `100131dc` | `0f b6 70 1b` | `MOVZX ESI,byte ptr [EAX + 0x1b]` |
| `100131e0` | `0f b6 59 1b` | `MOVZX EBX,byte ptr [ECX + 0x1b]` |
| `100131e4` | `2b f3` | `SUB ESI,EBX` |
| `100131e6` | `74 11` | `JZ 0x100131f9` |
| `100131e8` | `33 db` | `XOR EBX,EBX` |
| `100131ea` | `85 f6` | `TEST ESI,ESI` |
| `100131ec` | `0f 9f c3` | `SETG BL` |
| `100131ef` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `100131f3` | `8b f3` | `MOV ESI,EBX` |
| `100131f5` | `eb 02` | `JMP 0x100131f9` |
| `100131f7` | `33 f6` | `XOR ESI,ESI` |
| `100131f9` | `85 f6` | `TEST ESI,ESI` |
| `100131fb` | `0f 85 a2 00 00 00` | `JNZ 0x100132a3` |
| `10013201` | `8b 70 1c` | `MOV ESI,dword ptr [EAX + 0x1c]` |
| `10013204` | `3b 71 1c` | `CMP ESI,dword ptr [ECX + 0x1c]` |
| `10013207` | `74 72` | `JZ 0x1001327b` |
| `10013209` | `0f b6 70 1c` | `MOVZX ESI,byte ptr [EAX + 0x1c]` |
| `1001320d` | `0f b6 59 1c` | `MOVZX EBX,byte ptr [ECX + 0x1c]` |
| `10013211` | `2b f3` | `SUB ESI,EBX` |
| `10013213` | `74 11` | `JZ 0x10013226` |
| `10013215` | `33 db` | `XOR EBX,EBX` |
| `10013217` | `85 f6` | `TEST ESI,ESI` |
| `10013219` | `0f 9f c3` | `SETG BL` |
| `1001321c` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013220` | `8b f3` | `MOV ESI,EBX` |
| `10013222` | `85 f6` | `TEST ESI,ESI` |
| `10013224` | `75 7d` | `JNZ 0x100132a3` |
| `10013226` | `0f b6 70 1d` | `MOVZX ESI,byte ptr [EAX + 0x1d]` |
| `1001322a` | `0f b6 59 1d` | `MOVZX EBX,byte ptr [ECX + 0x1d]` |
| `1001322e` | `2b f3` | `SUB ESI,EBX` |
| `10013230` | `74 11` | `JZ 0x10013243` |
| `10013232` | `33 db` | `XOR EBX,EBX` |
| `10013234` | `85 f6` | `TEST ESI,ESI` |
| `10013236` | `0f 9f c3` | `SETG BL` |
| `10013239` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `1001323d` | `8b f3` | `MOV ESI,EBX` |
| `1001323f` | `85 f6` | `TEST ESI,ESI` |
| `10013241` | `75 60` | `JNZ 0x100132a3` |
| `10013243` | `0f b6 70 1e` | `MOVZX ESI,byte ptr [EAX + 0x1e]` |
| `10013247` | `0f b6 59 1e` | `MOVZX EBX,byte ptr [ECX + 0x1e]` |
| `1001324b` | `2b f3` | `SUB ESI,EBX` |
| `1001324d` | `74 11` | `JZ 0x10013260` |
| `1001324f` | `33 db` | `XOR EBX,EBX` |
| `10013251` | `85 f6` | `TEST ESI,ESI` |
| `10013253` | `0f 9f c3` | `SETG BL` |
| `10013256` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `1001325a` | `8b f3` | `MOV ESI,EBX` |
| `1001325c` | `85 f6` | `TEST ESI,ESI` |
| `1001325e` | `75 43` | `JNZ 0x100132a3` |
| `10013260` | `0f b6 70 1f` | `MOVZX ESI,byte ptr [EAX + 0x1f]` |
| `10013264` | `0f b6 59 1f` | `MOVZX EBX,byte ptr [ECX + 0x1f]` |
| `10013268` | `2b f3` | `SUB ESI,EBX` |
| `1001326a` | `74 11` | `JZ 0x1001327d` |
| `1001326c` | `33 db` | `XOR EBX,EBX` |
| `1001326e` | `85 f6` | `TEST ESI,ESI` |
| `10013270` | `0f 9f c3` | `SETG BL` |
| `10013273` | `8d 5c 1b ff` | `LEA EBX,[EBX + EBX*0x1 + -0x1]` |
| `10013277` | `8b f3` | `MOV ESI,EBX` |
| `10013279` | `eb 02` | `JMP 0x1001327d` |
| `1001327b` | `33 f6` | `XOR ESI,ESI` |
| `1001327d` | `85 f6` | `TEST ESI,ESI` |
| `1001327f` | `75 22` | `JNZ 0x100132a3` |
| `10013281` | `03 c2` | `ADD EAX,EDX` |
| `10013283` | `03 ca` | `ADD ECX,EDX` |
| `10013285` | `2b fa` | `SUB EDI,EDX` |
| `10013287` | `3b fa` | `CMP EDI,EDX` |
| `10013289` | `0f 83 86 fb ff ff` | `JNC 0x10012e15` |
| `1001328f` | `03 c7` | `ADD EAX,EDI` |
| `10013291` | `03 cf` | `ADD ECX,EDI` |
| `10013293` | `83 ff 1f` | `CMP EDI,0x1f` |
| `10013296` | `0f 87 da 03 00 00` | `JA 0x10013676` |
| `1001329c` | `ff 24 bd d5 43 01 10` | `JMP dword ptr [EDI*0x4 + 0x100143d5]` |
| `100132a3` | `8b c6` | `MOV EAX,ESI` |
| `100132a5` | `e9 ce 03 00 00` | `JMP 0x10013678` |
| `100132aa` | `8b 50 e4` | `MOV EDX,dword ptr [EAX + -0x1c]` |
| `100132ad` | `3b 51 e4` | `CMP EDX,dword ptr [ECX + -0x1c]` |
| `100132b0` | `74 71` | `JZ 0x10013323` |
| `100132b2` | `0f b6 f2` | `MOVZX ESI,DL` |
| `100132b5` | `0f b6 51 e4` | `MOVZX EDX,byte ptr [ECX + -0x1c]` |
| `100132b9` | `2b f2` | `SUB ESI,EDX` |
| `100132bb` | `74 11` | `JZ 0x100132ce` |
| `100132bd` | `33 d2` | `XOR EDX,EDX` |
| `100132bf` | `85 f6` | `TEST ESI,ESI` |
| `100132c1` | `0f 9f c2` | `SETG DL` |
| `100132c4` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100132c8` | `8b f2` | `MOV ESI,EDX` |
| `100132ca` | `85 f6` | `TEST ESI,ESI` |
| `100132cc` | `75 d5` | `JNZ 0x100132a3` |
| `100132ce` | `0f b6 70 e5` | `MOVZX ESI,byte ptr [EAX + -0x1b]` |
| `100132d2` | `0f b6 51 e5` | `MOVZX EDX,byte ptr [ECX + -0x1b]` |
| `100132d6` | `2b f2` | `SUB ESI,EDX` |
| `100132d8` | `74 11` | `JZ 0x100132eb` |
| `100132da` | `33 d2` | `XOR EDX,EDX` |
| `100132dc` | `85 f6` | `TEST ESI,ESI` |
| `100132de` | `0f 9f c2` | `SETG DL` |
| `100132e1` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100132e5` | `8b f2` | `MOV ESI,EDX` |
| `100132e7` | `85 f6` | `TEST ESI,ESI` |
| `100132e9` | `75 b8` | `JNZ 0x100132a3` |
| `100132eb` | `0f b6 70 e6` | `MOVZX ESI,byte ptr [EAX + -0x1a]` |
| `100132ef` | `0f b6 51 e6` | `MOVZX EDX,byte ptr [ECX + -0x1a]` |
| `100132f3` | `2b f2` | `SUB ESI,EDX` |
| `100132f5` | `74 11` | `JZ 0x10013308` |
| `100132f7` | `33 d2` | `XOR EDX,EDX` |
| `100132f9` | `85 f6` | `TEST ESI,ESI` |
| `100132fb` | `0f 9f c2` | `SETG DL` |
| `100132fe` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013302` | `8b f2` | `MOV ESI,EDX` |
| `10013304` | `85 f6` | `TEST ESI,ESI` |
| `10013306` | `75 9b` | `JNZ 0x100132a3` |
| `10013308` | `0f b6 70 e7` | `MOVZX ESI,byte ptr [EAX + -0x19]` |
| `1001330c` | `0f b6 51 e7` | `MOVZX EDX,byte ptr [ECX + -0x19]` |
| `10013310` | `2b f2` | `SUB ESI,EDX` |
| `10013312` | `74 11` | `JZ 0x10013325` |
| `10013314` | `33 d2` | `XOR EDX,EDX` |
| `10013316` | `85 f6` | `TEST ESI,ESI` |
| `10013318` | `0f 9f c2` | `SETG DL` |
| `1001331b` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001331f` | `8b f2` | `MOV ESI,EDX` |
| `10013321` | `eb 02` | `JMP 0x10013325` |
| `10013323` | `33 f6` | `XOR ESI,ESI` |
| `10013325` | `85 f6` | `TEST ESI,ESI` |
| `10013327` | `0f 85 76 ff ff ff` | `JNZ 0x100132a3` |
| `1001332d` | `8b 50 e8` | `MOV EDX,dword ptr [EAX + -0x18]` |
| `10013330` | `3b 51 e8` | `CMP EDX,dword ptr [ECX + -0x18]` |
| `10013333` | `74 7d` | `JZ 0x100133b2` |
| `10013335` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013338` | `0f b6 51 e8` | `MOVZX EDX,byte ptr [ECX + -0x18]` |
| `1001333c` | `2b f2` | `SUB ESI,EDX` |
| `1001333e` | `74 15` | `JZ 0x10013355` |
| `10013340` | `33 d2` | `XOR EDX,EDX` |
| `10013342` | `85 f6` | `TEST ESI,ESI` |
| `10013344` | `0f 9f c2` | `SETG DL` |
| `10013347` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001334b` | `8b f2` | `MOV ESI,EDX` |
| `1001334d` | `85 f6` | `TEST ESI,ESI` |
| `1001334f` | `0f 85 4e ff ff ff` | `JNZ 0x100132a3` |
| `10013355` | `0f b6 70 e9` | `MOVZX ESI,byte ptr [EAX + -0x17]` |
| `10013359` | `0f b6 51 e9` | `MOVZX EDX,byte ptr [ECX + -0x17]` |
| `1001335d` | `2b f2` | `SUB ESI,EDX` |
| `1001335f` | `74 15` | `JZ 0x10013376` |
| `10013361` | `33 d2` | `XOR EDX,EDX` |
| `10013363` | `85 f6` | `TEST ESI,ESI` |
| `10013365` | `0f 9f c2` | `SETG DL` |
| `10013368` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001336c` | `8b f2` | `MOV ESI,EDX` |
| `1001336e` | `85 f6` | `TEST ESI,ESI` |
| `10013370` | `0f 85 2d ff ff ff` | `JNZ 0x100132a3` |
| `10013376` | `0f b6 70 ea` | `MOVZX ESI,byte ptr [EAX + -0x16]` |
| `1001337a` | `0f b6 51 ea` | `MOVZX EDX,byte ptr [ECX + -0x16]` |
| `1001337e` | `2b f2` | `SUB ESI,EDX` |
| `10013380` | `74 15` | `JZ 0x10013397` |
| `10013382` | `33 d2` | `XOR EDX,EDX` |
| `10013384` | `85 f6` | `TEST ESI,ESI` |
| `10013386` | `0f 9f c2` | `SETG DL` |
| `10013389` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001338d` | `8b f2` | `MOV ESI,EDX` |
| `1001338f` | `85 f6` | `TEST ESI,ESI` |
| `10013391` | `0f 85 0c ff ff ff` | `JNZ 0x100132a3` |
| `10013397` | `0f b6 70 eb` | `MOVZX ESI,byte ptr [EAX + -0x15]` |
| `1001339b` | `0f b6 51 eb` | `MOVZX EDX,byte ptr [ECX + -0x15]` |
| `1001339f` | `2b f2` | `SUB ESI,EDX` |
| `100133a1` | `74 11` | `JZ 0x100133b4` |
| `100133a3` | `33 d2` | `XOR EDX,EDX` |
| `100133a5` | `85 f6` | `TEST ESI,ESI` |
| `100133a7` | `0f 9f c2` | `SETG DL` |
| `100133aa` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100133ae` | `8b f2` | `MOV ESI,EDX` |
| `100133b0` | `eb 02` | `JMP 0x100133b4` |
| `100133b2` | `33 f6` | `XOR ESI,ESI` |
| `100133b4` | `85 f6` | `TEST ESI,ESI` |
| `100133b6` | `0f 85 e7 fe ff ff` | `JNZ 0x100132a3` |
| `100133bc` | `8b 50 ec` | `MOV EDX,dword ptr [EAX + -0x14]` |
| `100133bf` | `3b 51 ec` | `CMP EDX,dword ptr [ECX + -0x14]` |
| `100133c2` | `74 7d` | `JZ 0x10013441` |
| `100133c4` | `0f b6 f2` | `MOVZX ESI,DL` |
| `100133c7` | `0f b6 51 ec` | `MOVZX EDX,byte ptr [ECX + -0x14]` |
| `100133cb` | `2b f2` | `SUB ESI,EDX` |
| `100133cd` | `74 15` | `JZ 0x100133e4` |
| `100133cf` | `33 d2` | `XOR EDX,EDX` |
| `100133d1` | `85 f6` | `TEST ESI,ESI` |
| `100133d3` | `0f 9f c2` | `SETG DL` |
| `100133d6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100133da` | `8b f2` | `MOV ESI,EDX` |
| `100133dc` | `85 f6` | `TEST ESI,ESI` |
| `100133de` | `0f 85 bf fe ff ff` | `JNZ 0x100132a3` |
| `100133e4` | `0f b6 70 ed` | `MOVZX ESI,byte ptr [EAX + -0x13]` |
| `100133e8` | `0f b6 51 ed` | `MOVZX EDX,byte ptr [ECX + -0x13]` |
| `100133ec` | `2b f2` | `SUB ESI,EDX` |
| `100133ee` | `74 15` | `JZ 0x10013405` |
| `100133f0` | `33 d2` | `XOR EDX,EDX` |
| `100133f2` | `85 f6` | `TEST ESI,ESI` |
| `100133f4` | `0f 9f c2` | `SETG DL` |
| `100133f7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100133fb` | `8b f2` | `MOV ESI,EDX` |
| `100133fd` | `85 f6` | `TEST ESI,ESI` |
| `100133ff` | `0f 85 9e fe ff ff` | `JNZ 0x100132a3` |
| `10013405` | `0f b6 70 ee` | `MOVZX ESI,byte ptr [EAX + -0x12]` |
| `10013409` | `0f b6 51 ee` | `MOVZX EDX,byte ptr [ECX + -0x12]` |
| `1001340d` | `2b f2` | `SUB ESI,EDX` |
| `1001340f` | `74 15` | `JZ 0x10013426` |
| `10013411` | `33 d2` | `XOR EDX,EDX` |
| `10013413` | `85 f6` | `TEST ESI,ESI` |
| `10013415` | `0f 9f c2` | `SETG DL` |
| `10013418` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001341c` | `8b f2` | `MOV ESI,EDX` |
| `1001341e` | `85 f6` | `TEST ESI,ESI` |
| `10013420` | `0f 85 7d fe ff ff` | `JNZ 0x100132a3` |
| `10013426` | `0f b6 70 ef` | `MOVZX ESI,byte ptr [EAX + -0x11]` |
| `1001342a` | `0f b6 51 ef` | `MOVZX EDX,byte ptr [ECX + -0x11]` |
| `1001342e` | `2b f2` | `SUB ESI,EDX` |
| `10013430` | `74 11` | `JZ 0x10013443` |
| `10013432` | `33 d2` | `XOR EDX,EDX` |
| `10013434` | `85 f6` | `TEST ESI,ESI` |
| `10013436` | `0f 9f c2` | `SETG DL` |
| `10013439` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001343d` | `8b f2` | `MOV ESI,EDX` |
| `1001343f` | `eb 02` | `JMP 0x10013443` |
| `10013441` | `33 f6` | `XOR ESI,ESI` |
| `10013443` | `85 f6` | `TEST ESI,ESI` |
| `10013445` | `0f 85 58 fe ff ff` | `JNZ 0x100132a3` |
| `1001344b` | `8b 50 f0` | `MOV EDX,dword ptr [EAX + -0x10]` |
| `1001344e` | `3b 51 f0` | `CMP EDX,dword ptr [ECX + -0x10]` |
| `10013451` | `74 7d` | `JZ 0x100134d0` |
| `10013453` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013456` | `0f b6 51 f0` | `MOVZX EDX,byte ptr [ECX + -0x10]` |
| `1001345a` | `2b f2` | `SUB ESI,EDX` |
| `1001345c` | `74 15` | `JZ 0x10013473` |
| `1001345e` | `33 d2` | `XOR EDX,EDX` |
| `10013460` | `85 f6` | `TEST ESI,ESI` |
| `10013462` | `0f 9f c2` | `SETG DL` |
| `10013465` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013469` | `8b f2` | `MOV ESI,EDX` |
| `1001346b` | `85 f6` | `TEST ESI,ESI` |
| `1001346d` | `0f 85 30 fe ff ff` | `JNZ 0x100132a3` |
| `10013473` | `0f b6 70 f1` | `MOVZX ESI,byte ptr [EAX + -0xf]` |
| `10013477` | `0f b6 51 f1` | `MOVZX EDX,byte ptr [ECX + -0xf]` |
| `1001347b` | `2b f2` | `SUB ESI,EDX` |
| `1001347d` | `74 15` | `JZ 0x10013494` |
| `1001347f` | `33 d2` | `XOR EDX,EDX` |
| `10013481` | `85 f6` | `TEST ESI,ESI` |
| `10013483` | `0f 9f c2` | `SETG DL` |
| `10013486` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001348a` | `8b f2` | `MOV ESI,EDX` |
| `1001348c` | `85 f6` | `TEST ESI,ESI` |
| `1001348e` | `0f 85 0f fe ff ff` | `JNZ 0x100132a3` |
| `10013494` | `0f b6 70 f2` | `MOVZX ESI,byte ptr [EAX + -0xe]` |
| `10013498` | `0f b6 51 f2` | `MOVZX EDX,byte ptr [ECX + -0xe]` |
| `1001349c` | `2b f2` | `SUB ESI,EDX` |
| `1001349e` | `74 15` | `JZ 0x100134b5` |
| `100134a0` | `33 d2` | `XOR EDX,EDX` |
| `100134a2` | `85 f6` | `TEST ESI,ESI` |
| `100134a4` | `0f 9f c2` | `SETG DL` |
| `100134a7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100134ab` | `8b f2` | `MOV ESI,EDX` |
| `100134ad` | `85 f6` | `TEST ESI,ESI` |
| `100134af` | `0f 85 ee fd ff ff` | `JNZ 0x100132a3` |
| `100134b5` | `0f b6 70 f3` | `MOVZX ESI,byte ptr [EAX + -0xd]` |
| `100134b9` | `0f b6 51 f3` | `MOVZX EDX,byte ptr [ECX + -0xd]` |
| `100134bd` | `2b f2` | `SUB ESI,EDX` |
| `100134bf` | `74 11` | `JZ 0x100134d2` |
| `100134c1` | `33 d2` | `XOR EDX,EDX` |
| `100134c3` | `85 f6` | `TEST ESI,ESI` |
| `100134c5` | `0f 9f c2` | `SETG DL` |
| `100134c8` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100134cc` | `8b f2` | `MOV ESI,EDX` |
| `100134ce` | `eb 02` | `JMP 0x100134d2` |
| `100134d0` | `33 f6` | `XOR ESI,ESI` |
| `100134d2` | `85 f6` | `TEST ESI,ESI` |
| `100134d4` | `0f 85 c9 fd ff ff` | `JNZ 0x100132a3` |
| `100134da` | `8b 50 f4` | `MOV EDX,dword ptr [EAX + -0xc]` |
| `100134dd` | `3b 51 f4` | `CMP EDX,dword ptr [ECX + -0xc]` |
| `100134e0` | `74 7e` | `JZ 0x10013560` |
| `100134e2` | `0f b6 51 f4` | `MOVZX EDX,byte ptr [ECX + -0xc]` |
| `100134e6` | `0f b6 70 f4` | `MOVZX ESI,byte ptr [EAX + -0xc]` |
| `100134ea` | `2b f2` | `SUB ESI,EDX` |
| `100134ec` | `74 15` | `JZ 0x10013503` |
| `100134ee` | `33 d2` | `XOR EDX,EDX` |
| `100134f0` | `85 f6` | `TEST ESI,ESI` |
| `100134f2` | `0f 9f c2` | `SETG DL` |
| `100134f5` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100134f9` | `8b f2` | `MOV ESI,EDX` |
| `100134fb` | `85 f6` | `TEST ESI,ESI` |
| `100134fd` | `0f 85 a0 fd ff ff` | `JNZ 0x100132a3` |
| `10013503` | `0f b6 70 f5` | `MOVZX ESI,byte ptr [EAX + -0xb]` |
| `10013507` | `0f b6 51 f5` | `MOVZX EDX,byte ptr [ECX + -0xb]` |
| `1001350b` | `2b f2` | `SUB ESI,EDX` |
| `1001350d` | `74 15` | `JZ 0x10013524` |
| `1001350f` | `33 d2` | `XOR EDX,EDX` |
| `10013511` | `85 f6` | `TEST ESI,ESI` |
| `10013513` | `0f 9f c2` | `SETG DL` |
| `10013516` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001351a` | `8b f2` | `MOV ESI,EDX` |
| `1001351c` | `85 f6` | `TEST ESI,ESI` |
| `1001351e` | `0f 85 7f fd ff ff` | `JNZ 0x100132a3` |
| `10013524` | `0f b6 70 f6` | `MOVZX ESI,byte ptr [EAX + -0xa]` |
| `10013528` | `0f b6 51 f6` | `MOVZX EDX,byte ptr [ECX + -0xa]` |
| `1001352c` | `2b f2` | `SUB ESI,EDX` |
| `1001352e` | `74 15` | `JZ 0x10013545` |
| `10013530` | `33 d2` | `XOR EDX,EDX` |
| `10013532` | `85 f6` | `TEST ESI,ESI` |
| `10013534` | `0f 9f c2` | `SETG DL` |
| `10013537` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001353b` | `8b f2` | `MOV ESI,EDX` |
| `1001353d` | `85 f6` | `TEST ESI,ESI` |
| `1001353f` | `0f 85 5e fd ff ff` | `JNZ 0x100132a3` |
| `10013545` | `0f b6 70 f7` | `MOVZX ESI,byte ptr [EAX + -0x9]` |
| `10013549` | `0f b6 51 f7` | `MOVZX EDX,byte ptr [ECX + -0x9]` |
| `1001354d` | `2b f2` | `SUB ESI,EDX` |
| `1001354f` | `74 11` | `JZ 0x10013562` |
| `10013551` | `33 d2` | `XOR EDX,EDX` |
| `10013553` | `85 f6` | `TEST ESI,ESI` |
| `10013555` | `0f 9f c2` | `SETG DL` |
| `10013558` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001355c` | `8b f2` | `MOV ESI,EDX` |
| `1001355e` | `eb 02` | `JMP 0x10013562` |
| `10013560` | `33 f6` | `XOR ESI,ESI` |
| `10013562` | `85 f6` | `TEST ESI,ESI` |
| `10013564` | `0f 85 39 fd ff ff` | `JNZ 0x100132a3` |
| `1001356a` | `8b 50 f8` | `MOV EDX,dword ptr [EAX + -0x8]` |
| `1001356d` | `3b 51 f8` | `CMP EDX,dword ptr [ECX + -0x8]` |
| `10013570` | `74 7d` | `JZ 0x100135ef` |
| `10013572` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013575` | `0f b6 51 f8` | `MOVZX EDX,byte ptr [ECX + -0x8]` |
| `10013579` | `2b f2` | `SUB ESI,EDX` |
| `1001357b` | `74 15` | `JZ 0x10013592` |
| `1001357d` | `33 d2` | `XOR EDX,EDX` |
| `1001357f` | `85 f6` | `TEST ESI,ESI` |
| `10013581` | `0f 9f c2` | `SETG DL` |
| `10013584` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013588` | `8b f2` | `MOV ESI,EDX` |
| `1001358a` | `85 f6` | `TEST ESI,ESI` |
| `1001358c` | `0f 85 11 fd ff ff` | `JNZ 0x100132a3` |
| `10013592` | `0f b6 70 f9` | `MOVZX ESI,byte ptr [EAX + -0x7]` |
| `10013596` | `0f b6 51 f9` | `MOVZX EDX,byte ptr [ECX + -0x7]` |
| `1001359a` | `2b f2` | `SUB ESI,EDX` |
| `1001359c` | `74 15` | `JZ 0x100135b3` |
| `1001359e` | `33 d2` | `XOR EDX,EDX` |
| `100135a0` | `85 f6` | `TEST ESI,ESI` |
| `100135a2` | `0f 9f c2` | `SETG DL` |
| `100135a5` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100135a9` | `8b f2` | `MOV ESI,EDX` |
| `100135ab` | `85 f6` | `TEST ESI,ESI` |
| `100135ad` | `0f 85 f0 fc ff ff` | `JNZ 0x100132a3` |
| `100135b3` | `0f b6 70 fa` | `MOVZX ESI,byte ptr [EAX + -0x6]` |
| `100135b7` | `0f b6 51 fa` | `MOVZX EDX,byte ptr [ECX + -0x6]` |
| `100135bb` | `2b f2` | `SUB ESI,EDX` |
| `100135bd` | `74 15` | `JZ 0x100135d4` |
| `100135bf` | `33 d2` | `XOR EDX,EDX` |
| `100135c1` | `85 f6` | `TEST ESI,ESI` |
| `100135c3` | `0f 9f c2` | `SETG DL` |
| `100135c6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100135ca` | `8b f2` | `MOV ESI,EDX` |
| `100135cc` | `85 f6` | `TEST ESI,ESI` |
| `100135ce` | `0f 85 cf fc ff ff` | `JNZ 0x100132a3` |
| `100135d4` | `0f b6 70 fb` | `MOVZX ESI,byte ptr [EAX + -0x5]` |
| `100135d8` | `0f b6 51 fb` | `MOVZX EDX,byte ptr [ECX + -0x5]` |
| `100135dc` | `2b f2` | `SUB ESI,EDX` |
| `100135de` | `74 11` | `JZ 0x100135f1` |
| `100135e0` | `33 d2` | `XOR EDX,EDX` |
| `100135e2` | `85 f6` | `TEST ESI,ESI` |
| `100135e4` | `0f 9f c2` | `SETG DL` |
| `100135e7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100135eb` | `8b f2` | `MOV ESI,EDX` |
| `100135ed` | `eb 02` | `JMP 0x100135f1` |
| `100135ef` | `33 f6` | `XOR ESI,ESI` |
| `100135f1` | `85 f6` | `TEST ESI,ESI` |
| `100135f3` | `0f 85 aa fc ff ff` | `JNZ 0x100132a3` |
| `100135f9` | `8b 50 fc` | `MOV EDX,dword ptr [EAX + -0x4]` |
| `100135fc` | `3b 51 fc` | `CMP EDX,dword ptr [ECX + -0x4]` |
| `100135ff` | `74 6f` | `JZ 0x10013670` |
| `10013601` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013604` | `0f b6 51 fc` | `MOVZX EDX,byte ptr [ECX + -0x4]` |
| `10013608` | `2b f2` | `SUB ESI,EDX` |
| `1001360a` | `74 0f` | `JZ 0x1001361b` |
| `1001360c` | `33 d2` | `XOR EDX,EDX` |
| `1001360e` | `85 f6` | `TEST ESI,ESI` |
| `10013610` | `0f 9f c2` | `SETG DL` |
| `10013613` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013617` | `85 d2` | `TEST EDX,EDX` |
| `10013619` | `75 36` | `JNZ 0x10013651` |
| `1001361b` | `0f b6 70 fd` | `MOVZX ESI,byte ptr [EAX + -0x3]` |
| `1001361f` | `0f b6 51 fd` | `MOVZX EDX,byte ptr [ECX + -0x3]` |
| `10013623` | `2b f2` | `SUB ESI,EDX` |
| `10013625` | `74 0f` | `JZ 0x10013636` |
| `10013627` | `33 d2` | `XOR EDX,EDX` |
| `10013629` | `85 f6` | `TEST ESI,ESI` |
| `1001362b` | `0f 9f c2` | `SETG DL` |
| `1001362e` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013632` | `85 d2` | `TEST EDX,EDX` |
| `10013634` | `75 1b` | `JNZ 0x10013651` |
| `10013636` | `0f b6 70 fe` | `MOVZX ESI,byte ptr [EAX + -0x2]` |
| `1001363a` | `0f b6 51 fe` | `MOVZX EDX,byte ptr [ECX + -0x2]` |
| `1001363e` | `2b f2` | `SUB ESI,EDX` |
| `10013640` | `74 13` | `JZ 0x10013655` |
| `10013642` | `33 d2` | `XOR EDX,EDX` |
| `10013644` | `85 f6` | `TEST ESI,ESI` |
| `10013646` | `0f 9f c2` | `SETG DL` |
| `10013649` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001364d` | `85 d2` | `TEST EDX,EDX` |
| `1001364f` | `74 04` | `JZ 0x10013655` |
| `10013651` | `8b c2` | `MOV EAX,EDX` |
| `10013653` | `eb 1d` | `JMP 0x10013672` |
| `10013655` | `0f b6 40 ff` | `MOVZX EAX,byte ptr [EAX + -0x1]` |
| `10013659` | `0f b6 49 ff` | `MOVZX ECX,byte ptr [ECX + -0x1]` |
| `1001365d` | `2b c1` | `SUB EAX,ECX` |
| `1001365f` | `74 11` | `JZ 0x10013672` |
| `10013661` | `33 c9` | `XOR ECX,ECX` |
| `10013663` | `85 c0` | `TEST EAX,EAX` |
| `10013665` | `0f 9f c1` | `SETG CL` |
| `10013668` | `8d 4c 09 ff` | `LEA ECX,[ECX + ECX*0x1 + -0x1]` |
| `1001366c` | `8b c1` | `MOV EAX,ECX` |
| `1001366e` | `eb 02` | `JMP 0x10013672` |
| `10013670` | `33 c0` | `XOR EAX,EAX` |
| `10013672` | `85 c0` | `TEST EAX,EAX` |
| `10013674` | `75 02` | `JNZ 0x10013678` |
| `10013676` | `33 c0` | `XOR EAX,EAX` |
| `10013678` | `5b` | `POP EBX` |
| `10013679` | `e9 53 0d 00 00` | `JMP 0x100143d1` |
| `1001367e` | `8b 50 e3` | `MOV EDX,dword ptr [EAX + -0x1d]` |
| `10013681` | `3b 51 e3` | `CMP EDX,dword ptr [ECX + -0x1d]` |
| `10013684` | `74 7d` | `JZ 0x10013703` |
| `10013686` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013689` | `0f b6 51 e3` | `MOVZX EDX,byte ptr [ECX + -0x1d]` |
| `1001368d` | `2b f2` | `SUB ESI,EDX` |
| `1001368f` | `74 15` | `JZ 0x100136a6` |
| `10013691` | `33 d2` | `XOR EDX,EDX` |
| `10013693` | `85 f6` | `TEST ESI,ESI` |
| `10013695` | `0f 9f c2` | `SETG DL` |
| `10013698` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001369c` | `8b f2` | `MOV ESI,EDX` |
| `1001369e` | `85 f6` | `TEST ESI,ESI` |
| `100136a0` | `0f 85 fd fb ff ff` | `JNZ 0x100132a3` |
| `100136a6` | `0f b6 70 e4` | `MOVZX ESI,byte ptr [EAX + -0x1c]` |
| `100136aa` | `0f b6 51 e4` | `MOVZX EDX,byte ptr [ECX + -0x1c]` |
| `100136ae` | `2b f2` | `SUB ESI,EDX` |
| `100136b0` | `74 15` | `JZ 0x100136c7` |
| `100136b2` | `33 d2` | `XOR EDX,EDX` |
| `100136b4` | `85 f6` | `TEST ESI,ESI` |
| `100136b6` | `0f 9f c2` | `SETG DL` |
| `100136b9` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100136bd` | `8b f2` | `MOV ESI,EDX` |
| `100136bf` | `85 f6` | `TEST ESI,ESI` |
| `100136c1` | `0f 85 dc fb ff ff` | `JNZ 0x100132a3` |
| `100136c7` | `0f b6 70 e5` | `MOVZX ESI,byte ptr [EAX + -0x1b]` |
| `100136cb` | `0f b6 51 e5` | `MOVZX EDX,byte ptr [ECX + -0x1b]` |
| `100136cf` | `2b f2` | `SUB ESI,EDX` |
| `100136d1` | `74 15` | `JZ 0x100136e8` |
| `100136d3` | `33 d2` | `XOR EDX,EDX` |
| `100136d5` | `85 f6` | `TEST ESI,ESI` |
| `100136d7` | `0f 9f c2` | `SETG DL` |
| `100136da` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100136de` | `8b f2` | `MOV ESI,EDX` |
| `100136e0` | `85 f6` | `TEST ESI,ESI` |
| `100136e2` | `0f 85 bb fb ff ff` | `JNZ 0x100132a3` |
| `100136e8` | `0f b6 70 e6` | `MOVZX ESI,byte ptr [EAX + -0x1a]` |
| `100136ec` | `0f b6 51 e6` | `MOVZX EDX,byte ptr [ECX + -0x1a]` |
| `100136f0` | `2b f2` | `SUB ESI,EDX` |
| `100136f2` | `74 11` | `JZ 0x10013705` |
| `100136f4` | `33 d2` | `XOR EDX,EDX` |
| `100136f6` | `85 f6` | `TEST ESI,ESI` |
| `100136f8` | `0f 9f c2` | `SETG DL` |
| `100136fb` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100136ff` | `8b f2` | `MOV ESI,EDX` |
| `10013701` | `eb 02` | `JMP 0x10013705` |
| `10013703` | `33 f6` | `XOR ESI,ESI` |
| `10013705` | `85 f6` | `TEST ESI,ESI` |
| `10013707` | `0f 85 96 fb ff ff` | `JNZ 0x100132a3` |
| `1001370d` | `8b 50 e7` | `MOV EDX,dword ptr [EAX + -0x19]` |
| `10013710` | `3b 51 e7` | `CMP EDX,dword ptr [ECX + -0x19]` |
| `10013713` | `74 7d` | `JZ 0x10013792` |
| `10013715` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013718` | `0f b6 51 e7` | `MOVZX EDX,byte ptr [ECX + -0x19]` |
| `1001371c` | `2b f2` | `SUB ESI,EDX` |
| `1001371e` | `74 15` | `JZ 0x10013735` |
| `10013720` | `33 d2` | `XOR EDX,EDX` |
| `10013722` | `85 f6` | `TEST ESI,ESI` |
| `10013724` | `0f 9f c2` | `SETG DL` |
| `10013727` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001372b` | `8b f2` | `MOV ESI,EDX` |
| `1001372d` | `85 f6` | `TEST ESI,ESI` |
| `1001372f` | `0f 85 6e fb ff ff` | `JNZ 0x100132a3` |
| `10013735` | `0f b6 70 e8` | `MOVZX ESI,byte ptr [EAX + -0x18]` |
| `10013739` | `0f b6 51 e8` | `MOVZX EDX,byte ptr [ECX + -0x18]` |
| `1001373d` | `2b f2` | `SUB ESI,EDX` |
| `1001373f` | `74 15` | `JZ 0x10013756` |
| `10013741` | `33 d2` | `XOR EDX,EDX` |
| `10013743` | `85 f6` | `TEST ESI,ESI` |
| `10013745` | `0f 9f c2` | `SETG DL` |
| `10013748` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001374c` | `8b f2` | `MOV ESI,EDX` |
| `1001374e` | `85 f6` | `TEST ESI,ESI` |
| `10013750` | `0f 85 4d fb ff ff` | `JNZ 0x100132a3` |
| `10013756` | `0f b6 70 e9` | `MOVZX ESI,byte ptr [EAX + -0x17]` |
| `1001375a` | `0f b6 51 e9` | `MOVZX EDX,byte ptr [ECX + -0x17]` |
| `1001375e` | `2b f2` | `SUB ESI,EDX` |
| `10013760` | `74 15` | `JZ 0x10013777` |
| `10013762` | `33 d2` | `XOR EDX,EDX` |
| `10013764` | `85 f6` | `TEST ESI,ESI` |
| `10013766` | `0f 9f c2` | `SETG DL` |
| `10013769` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001376d` | `8b f2` | `MOV ESI,EDX` |
| `1001376f` | `85 f6` | `TEST ESI,ESI` |
| `10013771` | `0f 85 2c fb ff ff` | `JNZ 0x100132a3` |
| `10013777` | `0f b6 70 ea` | `MOVZX ESI,byte ptr [EAX + -0x16]` |
| `1001377b` | `0f b6 51 ea` | `MOVZX EDX,byte ptr [ECX + -0x16]` |
| `1001377f` | `2b f2` | `SUB ESI,EDX` |
| `10013781` | `74 11` | `JZ 0x10013794` |
| `10013783` | `33 d2` | `XOR EDX,EDX` |
| `10013785` | `85 f6` | `TEST ESI,ESI` |
| `10013787` | `0f 9f c2` | `SETG DL` |
| `1001378a` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001378e` | `8b f2` | `MOV ESI,EDX` |
| `10013790` | `eb 02` | `JMP 0x10013794` |
| `10013792` | `33 f6` | `XOR ESI,ESI` |
| `10013794` | `85 f6` | `TEST ESI,ESI` |
| `10013796` | `0f 85 07 fb ff ff` | `JNZ 0x100132a3` |
| `1001379c` | `8b 50 eb` | `MOV EDX,dword ptr [EAX + -0x15]` |
| `1001379f` | `3b 51 eb` | `CMP EDX,dword ptr [ECX + -0x15]` |
| `100137a2` | `74 7d` | `JZ 0x10013821` |
| `100137a4` | `0f b6 f2` | `MOVZX ESI,DL` |
| `100137a7` | `0f b6 51 eb` | `MOVZX EDX,byte ptr [ECX + -0x15]` |
| `100137ab` | `2b f2` | `SUB ESI,EDX` |
| `100137ad` | `74 15` | `JZ 0x100137c4` |
| `100137af` | `33 d2` | `XOR EDX,EDX` |
| `100137b1` | `85 f6` | `TEST ESI,ESI` |
| `100137b3` | `0f 9f c2` | `SETG DL` |
| `100137b6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100137ba` | `8b f2` | `MOV ESI,EDX` |
| `100137bc` | `85 f6` | `TEST ESI,ESI` |
| `100137be` | `0f 85 df fa ff ff` | `JNZ 0x100132a3` |
| `100137c4` | `0f b6 70 ec` | `MOVZX ESI,byte ptr [EAX + -0x14]` |
| `100137c8` | `0f b6 51 ec` | `MOVZX EDX,byte ptr [ECX + -0x14]` |
| `100137cc` | `2b f2` | `SUB ESI,EDX` |
| `100137ce` | `74 15` | `JZ 0x100137e5` |
| `100137d0` | `33 d2` | `XOR EDX,EDX` |
| `100137d2` | `85 f6` | `TEST ESI,ESI` |
| `100137d4` | `0f 9f c2` | `SETG DL` |
| `100137d7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100137db` | `8b f2` | `MOV ESI,EDX` |
| `100137dd` | `85 f6` | `TEST ESI,ESI` |
| `100137df` | `0f 85 be fa ff ff` | `JNZ 0x100132a3` |
| `100137e5` | `0f b6 70 ed` | `MOVZX ESI,byte ptr [EAX + -0x13]` |
| `100137e9` | `0f b6 51 ed` | `MOVZX EDX,byte ptr [ECX + -0x13]` |
| `100137ed` | `2b f2` | `SUB ESI,EDX` |
| `100137ef` | `74 15` | `JZ 0x10013806` |
| `100137f1` | `33 d2` | `XOR EDX,EDX` |
| `100137f3` | `85 f6` | `TEST ESI,ESI` |
| `100137f5` | `0f 9f c2` | `SETG DL` |
| `100137f8` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100137fc` | `8b f2` | `MOV ESI,EDX` |
| `100137fe` | `85 f6` | `TEST ESI,ESI` |
| `10013800` | `0f 85 9d fa ff ff` | `JNZ 0x100132a3` |
| `10013806` | `0f b6 70 ee` | `MOVZX ESI,byte ptr [EAX + -0x12]` |
| `1001380a` | `0f b6 51 ee` | `MOVZX EDX,byte ptr [ECX + -0x12]` |
| `1001380e` | `2b f2` | `SUB ESI,EDX` |
| `10013810` | `74 11` | `JZ 0x10013823` |
| `10013812` | `33 d2` | `XOR EDX,EDX` |
| `10013814` | `85 f6` | `TEST ESI,ESI` |
| `10013816` | `0f 9f c2` | `SETG DL` |
| `10013819` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001381d` | `8b f2` | `MOV ESI,EDX` |
| `1001381f` | `eb 02` | `JMP 0x10013823` |
| `10013821` | `33 f6` | `XOR ESI,ESI` |
| `10013823` | `85 f6` | `TEST ESI,ESI` |
| `10013825` | `0f 85 78 fa ff ff` | `JNZ 0x100132a3` |
| `1001382b` | `8b 50 ef` | `MOV EDX,dword ptr [EAX + -0x11]` |
| `1001382e` | `3b 51 ef` | `CMP EDX,dword ptr [ECX + -0x11]` |
| `10013831` | `74 7d` | `JZ 0x100138b0` |
| `10013833` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013836` | `0f b6 51 ef` | `MOVZX EDX,byte ptr [ECX + -0x11]` |
| `1001383a` | `2b f2` | `SUB ESI,EDX` |
| `1001383c` | `74 15` | `JZ 0x10013853` |
| `1001383e` | `33 d2` | `XOR EDX,EDX` |
| `10013840` | `85 f6` | `TEST ESI,ESI` |
| `10013842` | `0f 9f c2` | `SETG DL` |
| `10013845` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013849` | `8b f2` | `MOV ESI,EDX` |
| `1001384b` | `85 f6` | `TEST ESI,ESI` |
| `1001384d` | `0f 85 50 fa ff ff` | `JNZ 0x100132a3` |
| `10013853` | `0f b6 70 f0` | `MOVZX ESI,byte ptr [EAX + -0x10]` |
| `10013857` | `0f b6 51 f0` | `MOVZX EDX,byte ptr [ECX + -0x10]` |
| `1001385b` | `2b f2` | `SUB ESI,EDX` |
| `1001385d` | `74 15` | `JZ 0x10013874` |
| `1001385f` | `33 d2` | `XOR EDX,EDX` |
| `10013861` | `85 f6` | `TEST ESI,ESI` |
| `10013863` | `0f 9f c2` | `SETG DL` |
| `10013866` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001386a` | `8b f2` | `MOV ESI,EDX` |
| `1001386c` | `85 f6` | `TEST ESI,ESI` |
| `1001386e` | `0f 85 2f fa ff ff` | `JNZ 0x100132a3` |
| `10013874` | `0f b6 70 f1` | `MOVZX ESI,byte ptr [EAX + -0xf]` |
| `10013878` | `0f b6 51 f1` | `MOVZX EDX,byte ptr [ECX + -0xf]` |
| `1001387c` | `2b f2` | `SUB ESI,EDX` |
| `1001387e` | `74 15` | `JZ 0x10013895` |
| `10013880` | `33 d2` | `XOR EDX,EDX` |
| `10013882` | `85 f6` | `TEST ESI,ESI` |
| `10013884` | `0f 9f c2` | `SETG DL` |
| `10013887` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001388b` | `8b f2` | `MOV ESI,EDX` |
| `1001388d` | `85 f6` | `TEST ESI,ESI` |
| `1001388f` | `0f 85 0e fa ff ff` | `JNZ 0x100132a3` |
| `10013895` | `0f b6 70 f2` | `MOVZX ESI,byte ptr [EAX + -0xe]` |
| `10013899` | `0f b6 51 f2` | `MOVZX EDX,byte ptr [ECX + -0xe]` |
| `1001389d` | `2b f2` | `SUB ESI,EDX` |
| `1001389f` | `74 11` | `JZ 0x100138b2` |
| `100138a1` | `33 d2` | `XOR EDX,EDX` |
| `100138a3` | `85 f6` | `TEST ESI,ESI` |
| `100138a5` | `0f 9f c2` | `SETG DL` |
| `100138a8` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100138ac` | `8b f2` | `MOV ESI,EDX` |
| `100138ae` | `eb 02` | `JMP 0x100138b2` |
| `100138b0` | `33 f6` | `XOR ESI,ESI` |
| `100138b2` | `85 f6` | `TEST ESI,ESI` |
| `100138b4` | `0f 85 e9 f9 ff ff` | `JNZ 0x100132a3` |
| `100138ba` | `8b 50 f3` | `MOV EDX,dword ptr [EAX + -0xd]` |
| `100138bd` | `3b 51 f3` | `CMP EDX,dword ptr [ECX + -0xd]` |
| `100138c0` | `74 7d` | `JZ 0x1001393f` |
| `100138c2` | `0f b6 f2` | `MOVZX ESI,DL` |
| `100138c5` | `0f b6 51 f3` | `MOVZX EDX,byte ptr [ECX + -0xd]` |
| `100138c9` | `2b f2` | `SUB ESI,EDX` |
| `100138cb` | `74 15` | `JZ 0x100138e2` |
| `100138cd` | `33 d2` | `XOR EDX,EDX` |
| `100138cf` | `85 f6` | `TEST ESI,ESI` |
| `100138d1` | `0f 9f c2` | `SETG DL` |
| `100138d4` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100138d8` | `8b f2` | `MOV ESI,EDX` |
| `100138da` | `85 f6` | `TEST ESI,ESI` |
| `100138dc` | `0f 85 c1 f9 ff ff` | `JNZ 0x100132a3` |
| `100138e2` | `0f b6 70 f4` | `MOVZX ESI,byte ptr [EAX + -0xc]` |
| `100138e6` | `0f b6 51 f4` | `MOVZX EDX,byte ptr [ECX + -0xc]` |
| `100138ea` | `2b f2` | `SUB ESI,EDX` |
| `100138ec` | `74 15` | `JZ 0x10013903` |
| `100138ee` | `33 d2` | `XOR EDX,EDX` |
| `100138f0` | `85 f6` | `TEST ESI,ESI` |
| `100138f2` | `0f 9f c2` | `SETG DL` |
| `100138f5` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100138f9` | `8b f2` | `MOV ESI,EDX` |
| `100138fb` | `85 f6` | `TEST ESI,ESI` |
| `100138fd` | `0f 85 a0 f9 ff ff` | `JNZ 0x100132a3` |
| `10013903` | `0f b6 70 f5` | `MOVZX ESI,byte ptr [EAX + -0xb]` |
| `10013907` | `0f b6 51 f5` | `MOVZX EDX,byte ptr [ECX + -0xb]` |
| `1001390b` | `2b f2` | `SUB ESI,EDX` |
| `1001390d` | `74 15` | `JZ 0x10013924` |
| `1001390f` | `33 d2` | `XOR EDX,EDX` |
| `10013911` | `85 f6` | `TEST ESI,ESI` |
| `10013913` | `0f 9f c2` | `SETG DL` |
| `10013916` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001391a` | `8b f2` | `MOV ESI,EDX` |
| `1001391c` | `85 f6` | `TEST ESI,ESI` |
| `1001391e` | `0f 85 7f f9 ff ff` | `JNZ 0x100132a3` |
| `10013924` | `0f b6 70 f6` | `MOVZX ESI,byte ptr [EAX + -0xa]` |
| `10013928` | `0f b6 51 f6` | `MOVZX EDX,byte ptr [ECX + -0xa]` |
| `1001392c` | `2b f2` | `SUB ESI,EDX` |
| `1001392e` | `74 11` | `JZ 0x10013941` |
| `10013930` | `33 d2` | `XOR EDX,EDX` |
| `10013932` | `85 f6` | `TEST ESI,ESI` |
| `10013934` | `0f 9f c2` | `SETG DL` |
| `10013937` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001393b` | `8b f2` | `MOV ESI,EDX` |
| `1001393d` | `eb 02` | `JMP 0x10013941` |
| `1001393f` | `33 f6` | `XOR ESI,ESI` |
| `10013941` | `85 f6` | `TEST ESI,ESI` |
| `10013943` | `0f 85 5a f9 ff ff` | `JNZ 0x100132a3` |
| `10013949` | `8b 50 f7` | `MOV EDX,dword ptr [EAX + -0x9]` |
| `1001394c` | `3b 51 f7` | `CMP EDX,dword ptr [ECX + -0x9]` |
| `1001394f` | `74 7e` | `JZ 0x100139cf` |
| `10013951` | `0f b6 51 f7` | `MOVZX EDX,byte ptr [ECX + -0x9]` |
| `10013955` | `0f b6 70 f7` | `MOVZX ESI,byte ptr [EAX + -0x9]` |
| `10013959` | `2b f2` | `SUB ESI,EDX` |
| `1001395b` | `74 15` | `JZ 0x10013972` |
| `1001395d` | `33 d2` | `XOR EDX,EDX` |
| `1001395f` | `85 f6` | `TEST ESI,ESI` |
| `10013961` | `0f 9f c2` | `SETG DL` |
| `10013964` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013968` | `8b f2` | `MOV ESI,EDX` |
| `1001396a` | `85 f6` | `TEST ESI,ESI` |
| `1001396c` | `0f 85 31 f9 ff ff` | `JNZ 0x100132a3` |
| `10013972` | `0f b6 70 f8` | `MOVZX ESI,byte ptr [EAX + -0x8]` |
| `10013976` | `0f b6 51 f8` | `MOVZX EDX,byte ptr [ECX + -0x8]` |
| `1001397a` | `2b f2` | `SUB ESI,EDX` |
| `1001397c` | `74 15` | `JZ 0x10013993` |
| `1001397e` | `33 d2` | `XOR EDX,EDX` |
| `10013980` | `85 f6` | `TEST ESI,ESI` |
| `10013982` | `0f 9f c2` | `SETG DL` |
| `10013985` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013989` | `8b f2` | `MOV ESI,EDX` |
| `1001398b` | `85 f6` | `TEST ESI,ESI` |
| `1001398d` | `0f 85 10 f9 ff ff` | `JNZ 0x100132a3` |
| `10013993` | `0f b6 70 f9` | `MOVZX ESI,byte ptr [EAX + -0x7]` |
| `10013997` | `0f b6 51 f9` | `MOVZX EDX,byte ptr [ECX + -0x7]` |
| `1001399b` | `2b f2` | `SUB ESI,EDX` |
| `1001399d` | `74 15` | `JZ 0x100139b4` |
| `1001399f` | `33 d2` | `XOR EDX,EDX` |
| `100139a1` | `85 f6` | `TEST ESI,ESI` |
| `100139a3` | `0f 9f c2` | `SETG DL` |
| `100139a6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100139aa` | `8b f2` | `MOV ESI,EDX` |
| `100139ac` | `85 f6` | `TEST ESI,ESI` |
| `100139ae` | `0f 85 ef f8 ff ff` | `JNZ 0x100132a3` |
| `100139b4` | `0f b6 70 fa` | `MOVZX ESI,byte ptr [EAX + -0x6]` |
| `100139b8` | `0f b6 51 fa` | `MOVZX EDX,byte ptr [ECX + -0x6]` |
| `100139bc` | `2b f2` | `SUB ESI,EDX` |
| `100139be` | `74 11` | `JZ 0x100139d1` |
| `100139c0` | `33 d2` | `XOR EDX,EDX` |
| `100139c2` | `85 f6` | `TEST ESI,ESI` |
| `100139c4` | `0f 9f c2` | `SETG DL` |
| `100139c7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100139cb` | `8b f2` | `MOV ESI,EDX` |
| `100139cd` | `eb 02` | `JMP 0x100139d1` |
| `100139cf` | `33 f6` | `XOR ESI,ESI` |
| `100139d1` | `85 f6` | `TEST ESI,ESI` |
| `100139d3` | `0f 85 ca f8 ff ff` | `JNZ 0x100132a3` |
| `100139d9` | `8b 50 fb` | `MOV EDX,dword ptr [EAX + -0x5]` |
| `100139dc` | `3b 51 fb` | `CMP EDX,dword ptr [ECX + -0x5]` |
| `100139df` | `74 7d` | `JZ 0x10013a5e` |
| `100139e1` | `0f b6 f2` | `MOVZX ESI,DL` |
| `100139e4` | `0f b6 51 fb` | `MOVZX EDX,byte ptr [ECX + -0x5]` |
| `100139e8` | `2b f2` | `SUB ESI,EDX` |
| `100139ea` | `74 15` | `JZ 0x10013a01` |
| `100139ec` | `33 d2` | `XOR EDX,EDX` |
| `100139ee` | `85 f6` | `TEST ESI,ESI` |
| `100139f0` | `0f 9f c2` | `SETG DL` |
| `100139f3` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100139f7` | `8b f2` | `MOV ESI,EDX` |
| `100139f9` | `85 f6` | `TEST ESI,ESI` |
| `100139fb` | `0f 85 a2 f8 ff ff` | `JNZ 0x100132a3` |
| `10013a01` | `0f b6 70 fc` | `MOVZX ESI,byte ptr [EAX + -0x4]` |
| `10013a05` | `0f b6 51 fc` | `MOVZX EDX,byte ptr [ECX + -0x4]` |
| `10013a09` | `2b f2` | `SUB ESI,EDX` |
| `10013a0b` | `74 15` | `JZ 0x10013a22` |
| `10013a0d` | `33 d2` | `XOR EDX,EDX` |
| `10013a0f` | `85 f6` | `TEST ESI,ESI` |
| `10013a11` | `0f 9f c2` | `SETG DL` |
| `10013a14` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013a18` | `8b f2` | `MOV ESI,EDX` |
| `10013a1a` | `85 f6` | `TEST ESI,ESI` |
| `10013a1c` | `0f 85 81 f8 ff ff` | `JNZ 0x100132a3` |
| `10013a22` | `0f b6 70 fd` | `MOVZX ESI,byte ptr [EAX + -0x3]` |
| `10013a26` | `0f b6 51 fd` | `MOVZX EDX,byte ptr [ECX + -0x3]` |
| `10013a2a` | `2b f2` | `SUB ESI,EDX` |
| `10013a2c` | `74 15` | `JZ 0x10013a43` |
| `10013a2e` | `33 d2` | `XOR EDX,EDX` |
| `10013a30` | `85 f6` | `TEST ESI,ESI` |
| `10013a32` | `0f 9f c2` | `SETG DL` |
| `10013a35` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013a39` | `8b f2` | `MOV ESI,EDX` |
| `10013a3b` | `85 f6` | `TEST ESI,ESI` |
| `10013a3d` | `0f 85 60 f8 ff ff` | `JNZ 0x100132a3` |
| `10013a43` | `0f b6 70 fe` | `MOVZX ESI,byte ptr [EAX + -0x2]` |
| `10013a47` | `0f b6 51 fe` | `MOVZX EDX,byte ptr [ECX + -0x2]` |
| `10013a4b` | `2b f2` | `SUB ESI,EDX` |
| `10013a4d` | `74 11` | `JZ 0x10013a60` |
| `10013a4f` | `33 d2` | `XOR EDX,EDX` |
| `10013a51` | `85 f6` | `TEST ESI,ESI` |
| `10013a53` | `0f 9f c2` | `SETG DL` |
| `10013a56` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013a5a` | `8b f2` | `MOV ESI,EDX` |
| `10013a5c` | `eb 02` | `JMP 0x10013a60` |
| `10013a5e` | `33 f6` | `XOR ESI,ESI` |
| `10013a60` | `85 f6` | `TEST ESI,ESI` |
| `10013a62` | `0f 85 3b f8 ff ff` | `JNZ 0x100132a3` |
| `10013a68` | `0f b6 49 ff` | `MOVZX ECX,byte ptr [ECX + -0x1]` |
| `10013a6c` | `0f b6 40 ff` | `MOVZX EAX,byte ptr [EAX + -0x1]` |
| `10013a70` | `2b c1` | `SUB EAX,ECX` |
| `10013a72` | `0f 84 00 fc ff ff` | `JZ 0x10013678` |
| `10013a78` | `33 c9` | `XOR ECX,ECX` |
| `10013a7a` | `85 c0` | `TEST EAX,EAX` |
| `10013a7c` | `0f 9f c1` | `SETG CL` |
| `10013a7f` | `8d 4c 09 ff` | `LEA ECX,[ECX + ECX*0x1 + -0x1]` |
| `10013a83` | `8b c1` | `MOV EAX,ECX` |
| `10013a85` | `e9 ee fb ff ff` | `JMP 0x10013678` |
| `10013a8a` | `8b 50 e2` | `MOV EDX,dword ptr [EAX + -0x1e]` |
| `10013a8d` | `3b 51 e2` | `CMP EDX,dword ptr [ECX + -0x1e]` |
| `10013a90` | `74 7d` | `JZ 0x10013b0f` |
| `10013a92` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013a95` | `0f b6 51 e2` | `MOVZX EDX,byte ptr [ECX + -0x1e]` |
| `10013a99` | `2b f2` | `SUB ESI,EDX` |
| `10013a9b` | `74 15` | `JZ 0x10013ab2` |
| `10013a9d` | `33 d2` | `XOR EDX,EDX` |
| `10013a9f` | `85 f6` | `TEST ESI,ESI` |
| `10013aa1` | `0f 9f c2` | `SETG DL` |
| `10013aa4` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013aa8` | `8b f2` | `MOV ESI,EDX` |
| `10013aaa` | `85 f6` | `TEST ESI,ESI` |
| `10013aac` | `0f 85 f1 f7 ff ff` | `JNZ 0x100132a3` |
| `10013ab2` | `0f b6 70 e3` | `MOVZX ESI,byte ptr [EAX + -0x1d]` |
| `10013ab6` | `0f b6 51 e3` | `MOVZX EDX,byte ptr [ECX + -0x1d]` |
| `10013aba` | `2b f2` | `SUB ESI,EDX` |
| `10013abc` | `74 15` | `JZ 0x10013ad3` |
| `10013abe` | `33 d2` | `XOR EDX,EDX` |
| `10013ac0` | `85 f6` | `TEST ESI,ESI` |
| `10013ac2` | `0f 9f c2` | `SETG DL` |
| `10013ac5` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013ac9` | `8b f2` | `MOV ESI,EDX` |
| `10013acb` | `85 f6` | `TEST ESI,ESI` |
| `10013acd` | `0f 85 d0 f7 ff ff` | `JNZ 0x100132a3` |
| `10013ad3` | `0f b6 70 e4` | `MOVZX ESI,byte ptr [EAX + -0x1c]` |
| `10013ad7` | `0f b6 51 e4` | `MOVZX EDX,byte ptr [ECX + -0x1c]` |
| `10013adb` | `2b f2` | `SUB ESI,EDX` |
| `10013add` | `74 15` | `JZ 0x10013af4` |
| `10013adf` | `33 d2` | `XOR EDX,EDX` |
| `10013ae1` | `85 f6` | `TEST ESI,ESI` |
| `10013ae3` | `0f 9f c2` | `SETG DL` |
| `10013ae6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013aea` | `8b f2` | `MOV ESI,EDX` |
| `10013aec` | `85 f6` | `TEST ESI,ESI` |
| `10013aee` | `0f 85 af f7 ff ff` | `JNZ 0x100132a3` |
| `10013af4` | `0f b6 70 e5` | `MOVZX ESI,byte ptr [EAX + -0x1b]` |
| `10013af8` | `0f b6 51 e5` | `MOVZX EDX,byte ptr [ECX + -0x1b]` |
| `10013afc` | `2b f2` | `SUB ESI,EDX` |
| `10013afe` | `74 11` | `JZ 0x10013b11` |
| `10013b00` | `33 d2` | `XOR EDX,EDX` |
| `10013b02` | `85 f6` | `TEST ESI,ESI` |
| `10013b04` | `0f 9f c2` | `SETG DL` |
| `10013b07` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013b0b` | `8b f2` | `MOV ESI,EDX` |
| `10013b0d` | `eb 02` | `JMP 0x10013b11` |
| `10013b0f` | `33 f6` | `XOR ESI,ESI` |
| `10013b11` | `85 f6` | `TEST ESI,ESI` |
| `10013b13` | `0f 85 8a f7 ff ff` | `JNZ 0x100132a3` |
| `10013b19` | `8b 50 e6` | `MOV EDX,dword ptr [EAX + -0x1a]` |
| `10013b1c` | `3b 51 e6` | `CMP EDX,dword ptr [ECX + -0x1a]` |
| `10013b1f` | `74 7d` | `JZ 0x10013b9e` |
| `10013b21` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013b24` | `0f b6 51 e6` | `MOVZX EDX,byte ptr [ECX + -0x1a]` |
| `10013b28` | `2b f2` | `SUB ESI,EDX` |
| `10013b2a` | `74 15` | `JZ 0x10013b41` |
| `10013b2c` | `33 d2` | `XOR EDX,EDX` |
| `10013b2e` | `85 f6` | `TEST ESI,ESI` |
| `10013b30` | `0f 9f c2` | `SETG DL` |
| `10013b33` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013b37` | `8b f2` | `MOV ESI,EDX` |
| `10013b39` | `85 f6` | `TEST ESI,ESI` |
| `10013b3b` | `0f 85 62 f7 ff ff` | `JNZ 0x100132a3` |
| `10013b41` | `0f b6 70 e7` | `MOVZX ESI,byte ptr [EAX + -0x19]` |
| `10013b45` | `0f b6 51 e7` | `MOVZX EDX,byte ptr [ECX + -0x19]` |
| `10013b49` | `2b f2` | `SUB ESI,EDX` |
| `10013b4b` | `74 15` | `JZ 0x10013b62` |
| `10013b4d` | `33 d2` | `XOR EDX,EDX` |
| `10013b4f` | `85 f6` | `TEST ESI,ESI` |
| `10013b51` | `0f 9f c2` | `SETG DL` |
| `10013b54` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013b58` | `8b f2` | `MOV ESI,EDX` |
| `10013b5a` | `85 f6` | `TEST ESI,ESI` |
| `10013b5c` | `0f 85 41 f7 ff ff` | `JNZ 0x100132a3` |
| `10013b62` | `0f b6 70 e8` | `MOVZX ESI,byte ptr [EAX + -0x18]` |
| `10013b66` | `0f b6 51 e8` | `MOVZX EDX,byte ptr [ECX + -0x18]` |
| `10013b6a` | `2b f2` | `SUB ESI,EDX` |
| `10013b6c` | `74 15` | `JZ 0x10013b83` |
| `10013b6e` | `33 d2` | `XOR EDX,EDX` |
| `10013b70` | `85 f6` | `TEST ESI,ESI` |
| `10013b72` | `0f 9f c2` | `SETG DL` |
| `10013b75` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013b79` | `8b f2` | `MOV ESI,EDX` |
| `10013b7b` | `85 f6` | `TEST ESI,ESI` |
| `10013b7d` | `0f 85 20 f7 ff ff` | `JNZ 0x100132a3` |
| `10013b83` | `0f b6 70 e9` | `MOVZX ESI,byte ptr [EAX + -0x17]` |
| `10013b87` | `0f b6 51 e9` | `MOVZX EDX,byte ptr [ECX + -0x17]` |
| `10013b8b` | `2b f2` | `SUB ESI,EDX` |
| `10013b8d` | `74 11` | `JZ 0x10013ba0` |
| `10013b8f` | `33 d2` | `XOR EDX,EDX` |
| `10013b91` | `85 f6` | `TEST ESI,ESI` |
| `10013b93` | `0f 9f c2` | `SETG DL` |
| `10013b96` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013b9a` | `8b f2` | `MOV ESI,EDX` |
| `10013b9c` | `eb 02` | `JMP 0x10013ba0` |
| `10013b9e` | `33 f6` | `XOR ESI,ESI` |
| `10013ba0` | `85 f6` | `TEST ESI,ESI` |
| `10013ba2` | `0f 85 fb f6 ff ff` | `JNZ 0x100132a3` |
| `10013ba8` | `8b 50 ea` | `MOV EDX,dword ptr [EAX + -0x16]` |
| `10013bab` | `3b 51 ea` | `CMP EDX,dword ptr [ECX + -0x16]` |
| `10013bae` | `74 7d` | `JZ 0x10013c2d` |
| `10013bb0` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013bb3` | `0f b6 51 ea` | `MOVZX EDX,byte ptr [ECX + -0x16]` |
| `10013bb7` | `2b f2` | `SUB ESI,EDX` |
| `10013bb9` | `74 15` | `JZ 0x10013bd0` |
| `10013bbb` | `33 d2` | `XOR EDX,EDX` |
| `10013bbd` | `85 f6` | `TEST ESI,ESI` |
| `10013bbf` | `0f 9f c2` | `SETG DL` |
| `10013bc2` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013bc6` | `8b f2` | `MOV ESI,EDX` |
| `10013bc8` | `85 f6` | `TEST ESI,ESI` |
| `10013bca` | `0f 85 d3 f6 ff ff` | `JNZ 0x100132a3` |
| `10013bd0` | `0f b6 70 eb` | `MOVZX ESI,byte ptr [EAX + -0x15]` |
| `10013bd4` | `0f b6 51 eb` | `MOVZX EDX,byte ptr [ECX + -0x15]` |
| `10013bd8` | `2b f2` | `SUB ESI,EDX` |
| `10013bda` | `74 15` | `JZ 0x10013bf1` |
| `10013bdc` | `33 d2` | `XOR EDX,EDX` |
| `10013bde` | `85 f6` | `TEST ESI,ESI` |
| `10013be0` | `0f 9f c2` | `SETG DL` |
| `10013be3` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013be7` | `8b f2` | `MOV ESI,EDX` |
| `10013be9` | `85 f6` | `TEST ESI,ESI` |
| `10013beb` | `0f 85 b2 f6 ff ff` | `JNZ 0x100132a3` |
| `10013bf1` | `0f b6 70 ec` | `MOVZX ESI,byte ptr [EAX + -0x14]` |
| `10013bf5` | `0f b6 51 ec` | `MOVZX EDX,byte ptr [ECX + -0x14]` |
| `10013bf9` | `2b f2` | `SUB ESI,EDX` |
| `10013bfb` | `74 15` | `JZ 0x10013c12` |
| `10013bfd` | `33 d2` | `XOR EDX,EDX` |
| `10013bff` | `85 f6` | `TEST ESI,ESI` |
| `10013c01` | `0f 9f c2` | `SETG DL` |
| `10013c04` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013c08` | `8b f2` | `MOV ESI,EDX` |
| `10013c0a` | `85 f6` | `TEST ESI,ESI` |
| `10013c0c` | `0f 85 91 f6 ff ff` | `JNZ 0x100132a3` |
| `10013c12` | `0f b6 70 ed` | `MOVZX ESI,byte ptr [EAX + -0x13]` |
| `10013c16` | `0f b6 51 ed` | `MOVZX EDX,byte ptr [ECX + -0x13]` |
| `10013c1a` | `2b f2` | `SUB ESI,EDX` |
| `10013c1c` | `74 11` | `JZ 0x10013c2f` |
| `10013c1e` | `33 d2` | `XOR EDX,EDX` |
| `10013c20` | `85 f6` | `TEST ESI,ESI` |
| `10013c22` | `0f 9f c2` | `SETG DL` |
| `10013c25` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013c29` | `8b f2` | `MOV ESI,EDX` |
| `10013c2b` | `eb 02` | `JMP 0x10013c2f` |
| `10013c2d` | `33 f6` | `XOR ESI,ESI` |
| `10013c2f` | `85 f6` | `TEST ESI,ESI` |
| `10013c31` | `0f 85 6c f6 ff ff` | `JNZ 0x100132a3` |
| `10013c37` | `8b 50 ee` | `MOV EDX,dword ptr [EAX + -0x12]` |
| `10013c3a` | `3b 51 ee` | `CMP EDX,dword ptr [ECX + -0x12]` |
| `10013c3d` | `74 7d` | `JZ 0x10013cbc` |
| `10013c3f` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013c42` | `0f b6 51 ee` | `MOVZX EDX,byte ptr [ECX + -0x12]` |
| `10013c46` | `2b f2` | `SUB ESI,EDX` |
| `10013c48` | `74 15` | `JZ 0x10013c5f` |
| `10013c4a` | `33 d2` | `XOR EDX,EDX` |
| `10013c4c` | `85 f6` | `TEST ESI,ESI` |
| `10013c4e` | `0f 9f c2` | `SETG DL` |
| `10013c51` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013c55` | `8b f2` | `MOV ESI,EDX` |
| `10013c57` | `85 f6` | `TEST ESI,ESI` |
| `10013c59` | `0f 85 44 f6 ff ff` | `JNZ 0x100132a3` |
| `10013c5f` | `0f b6 70 ef` | `MOVZX ESI,byte ptr [EAX + -0x11]` |
| `10013c63` | `0f b6 51 ef` | `MOVZX EDX,byte ptr [ECX + -0x11]` |
| `10013c67` | `2b f2` | `SUB ESI,EDX` |
| `10013c69` | `74 15` | `JZ 0x10013c80` |
| `10013c6b` | `33 d2` | `XOR EDX,EDX` |
| `10013c6d` | `85 f6` | `TEST ESI,ESI` |
| `10013c6f` | `0f 9f c2` | `SETG DL` |
| `10013c72` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013c76` | `8b f2` | `MOV ESI,EDX` |
| `10013c78` | `85 f6` | `TEST ESI,ESI` |
| `10013c7a` | `0f 85 23 f6 ff ff` | `JNZ 0x100132a3` |
| `10013c80` | `0f b6 70 f0` | `MOVZX ESI,byte ptr [EAX + -0x10]` |
| `10013c84` | `0f b6 51 f0` | `MOVZX EDX,byte ptr [ECX + -0x10]` |
| `10013c88` | `2b f2` | `SUB ESI,EDX` |
| `10013c8a` | `74 15` | `JZ 0x10013ca1` |
| `10013c8c` | `33 d2` | `XOR EDX,EDX` |
| `10013c8e` | `85 f6` | `TEST ESI,ESI` |
| `10013c90` | `0f 9f c2` | `SETG DL` |
| `10013c93` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013c97` | `8b f2` | `MOV ESI,EDX` |
| `10013c99` | `85 f6` | `TEST ESI,ESI` |
| `10013c9b` | `0f 85 02 f6 ff ff` | `JNZ 0x100132a3` |
| `10013ca1` | `0f b6 70 f1` | `MOVZX ESI,byte ptr [EAX + -0xf]` |
| `10013ca5` | `0f b6 51 f1` | `MOVZX EDX,byte ptr [ECX + -0xf]` |
| `10013ca9` | `2b f2` | `SUB ESI,EDX` |
| `10013cab` | `74 11` | `JZ 0x10013cbe` |
| `10013cad` | `33 d2` | `XOR EDX,EDX` |
| `10013caf` | `85 f6` | `TEST ESI,ESI` |
| `10013cb1` | `0f 9f c2` | `SETG DL` |
| `10013cb4` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013cb8` | `8b f2` | `MOV ESI,EDX` |
| `10013cba` | `eb 02` | `JMP 0x10013cbe` |
| `10013cbc` | `33 f6` | `XOR ESI,ESI` |
| `10013cbe` | `85 f6` | `TEST ESI,ESI` |
| `10013cc0` | `0f 85 dd f5 ff ff` | `JNZ 0x100132a3` |
| `10013cc6` | `8b 50 f2` | `MOV EDX,dword ptr [EAX + -0xe]` |
| `10013cc9` | `3b 51 f2` | `CMP EDX,dword ptr [ECX + -0xe]` |
| `10013ccc` | `74 7d` | `JZ 0x10013d4b` |
| `10013cce` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013cd1` | `0f b6 51 f2` | `MOVZX EDX,byte ptr [ECX + -0xe]` |
| `10013cd5` | `2b f2` | `SUB ESI,EDX` |
| `10013cd7` | `74 15` | `JZ 0x10013cee` |
| `10013cd9` | `33 d2` | `XOR EDX,EDX` |
| `10013cdb` | `85 f6` | `TEST ESI,ESI` |
| `10013cdd` | `0f 9f c2` | `SETG DL` |
| `10013ce0` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013ce4` | `8b f2` | `MOV ESI,EDX` |
| `10013ce6` | `85 f6` | `TEST ESI,ESI` |
| `10013ce8` | `0f 85 b5 f5 ff ff` | `JNZ 0x100132a3` |
| `10013cee` | `0f b6 70 f3` | `MOVZX ESI,byte ptr [EAX + -0xd]` |
| `10013cf2` | `0f b6 51 f3` | `MOVZX EDX,byte ptr [ECX + -0xd]` |
| `10013cf6` | `2b f2` | `SUB ESI,EDX` |
| `10013cf8` | `74 15` | `JZ 0x10013d0f` |
| `10013cfa` | `33 d2` | `XOR EDX,EDX` |
| `10013cfc` | `85 f6` | `TEST ESI,ESI` |
| `10013cfe` | `0f 9f c2` | `SETG DL` |
| `10013d01` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013d05` | `8b f2` | `MOV ESI,EDX` |
| `10013d07` | `85 f6` | `TEST ESI,ESI` |
| `10013d09` | `0f 85 94 f5 ff ff` | `JNZ 0x100132a3` |
| `10013d0f` | `0f b6 70 f4` | `MOVZX ESI,byte ptr [EAX + -0xc]` |
| `10013d13` | `0f b6 51 f4` | `MOVZX EDX,byte ptr [ECX + -0xc]` |
| `10013d17` | `2b f2` | `SUB ESI,EDX` |
| `10013d19` | `74 15` | `JZ 0x10013d30` |
| `10013d1b` | `33 d2` | `XOR EDX,EDX` |
| `10013d1d` | `85 f6` | `TEST ESI,ESI` |
| `10013d1f` | `0f 9f c2` | `SETG DL` |
| `10013d22` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013d26` | `8b f2` | `MOV ESI,EDX` |
| `10013d28` | `85 f6` | `TEST ESI,ESI` |
| `10013d2a` | `0f 85 73 f5 ff ff` | `JNZ 0x100132a3` |
| `10013d30` | `0f b6 70 f5` | `MOVZX ESI,byte ptr [EAX + -0xb]` |
| `10013d34` | `0f b6 51 f5` | `MOVZX EDX,byte ptr [ECX + -0xb]` |
| `10013d38` | `2b f2` | `SUB ESI,EDX` |
| `10013d3a` | `74 11` | `JZ 0x10013d4d` |
| `10013d3c` | `33 d2` | `XOR EDX,EDX` |
| `10013d3e` | `85 f6` | `TEST ESI,ESI` |
| `10013d40` | `0f 9f c2` | `SETG DL` |
| `10013d43` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013d47` | `8b f2` | `MOV ESI,EDX` |
| `10013d49` | `eb 02` | `JMP 0x10013d4d` |
| `10013d4b` | `33 f6` | `XOR ESI,ESI` |
| `10013d4d` | `85 f6` | `TEST ESI,ESI` |
| `10013d4f` | `0f 85 4e f5 ff ff` | `JNZ 0x100132a3` |
| `10013d55` | `8b 50 f6` | `MOV EDX,dword ptr [EAX + -0xa]` |
| `10013d58` | `3b 51 f6` | `CMP EDX,dword ptr [ECX + -0xa]` |
| `10013d5b` | `74 7e` | `JZ 0x10013ddb` |
| `10013d5d` | `0f b6 51 f6` | `MOVZX EDX,byte ptr [ECX + -0xa]` |
| `10013d61` | `0f b6 70 f6` | `MOVZX ESI,byte ptr [EAX + -0xa]` |
| `10013d65` | `2b f2` | `SUB ESI,EDX` |
| `10013d67` | `74 15` | `JZ 0x10013d7e` |
| `10013d69` | `33 d2` | `XOR EDX,EDX` |
| `10013d6b` | `85 f6` | `TEST ESI,ESI` |
| `10013d6d` | `0f 9f c2` | `SETG DL` |
| `10013d70` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013d74` | `8b f2` | `MOV ESI,EDX` |
| `10013d76` | `85 f6` | `TEST ESI,ESI` |
| `10013d78` | `0f 85 25 f5 ff ff` | `JNZ 0x100132a3` |
| `10013d7e` | `0f b6 51 f7` | `MOVZX EDX,byte ptr [ECX + -0x9]` |
| `10013d82` | `0f b6 70 f7` | `MOVZX ESI,byte ptr [EAX + -0x9]` |
| `10013d86` | `2b f2` | `SUB ESI,EDX` |
| `10013d88` | `74 15` | `JZ 0x10013d9f` |
| `10013d8a` | `33 d2` | `XOR EDX,EDX` |
| `10013d8c` | `85 f6` | `TEST ESI,ESI` |
| `10013d8e` | `0f 9f c2` | `SETG DL` |
| `10013d91` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013d95` | `8b f2` | `MOV ESI,EDX` |
| `10013d97` | `85 f6` | `TEST ESI,ESI` |
| `10013d99` | `0f 85 04 f5 ff ff` | `JNZ 0x100132a3` |
| `10013d9f` | `0f b6 51 f8` | `MOVZX EDX,byte ptr [ECX + -0x8]` |
| `10013da3` | `0f b6 70 f8` | `MOVZX ESI,byte ptr [EAX + -0x8]` |
| `10013da7` | `2b f2` | `SUB ESI,EDX` |
| `10013da9` | `74 15` | `JZ 0x10013dc0` |
| `10013dab` | `33 d2` | `XOR EDX,EDX` |
| `10013dad` | `85 f6` | `TEST ESI,ESI` |
| `10013daf` | `0f 9f c2` | `SETG DL` |
| `10013db2` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013db6` | `8b f2` | `MOV ESI,EDX` |
| `10013db8` | `85 f6` | `TEST ESI,ESI` |
| `10013dba` | `0f 85 e3 f4 ff ff` | `JNZ 0x100132a3` |
| `10013dc0` | `0f b6 51 f9` | `MOVZX EDX,byte ptr [ECX + -0x7]` |
| `10013dc4` | `0f b6 70 f9` | `MOVZX ESI,byte ptr [EAX + -0x7]` |
| `10013dc8` | `2b f2` | `SUB ESI,EDX` |
| `10013dca` | `74 11` | `JZ 0x10013ddd` |
| `10013dcc` | `33 d2` | `XOR EDX,EDX` |
| `10013dce` | `85 f6` | `TEST ESI,ESI` |
| `10013dd0` | `0f 9f c2` | `SETG DL` |
| `10013dd3` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013dd7` | `8b f2` | `MOV ESI,EDX` |
| `10013dd9` | `eb 02` | `JMP 0x10013ddd` |
| `10013ddb` | `33 f6` | `XOR ESI,ESI` |
| `10013ddd` | `85 f6` | `TEST ESI,ESI` |
| `10013ddf` | `0f 85 be f4 ff ff` | `JNZ 0x100132a3` |
| `10013de5` | `8b 50 fa` | `MOV EDX,dword ptr [EAX + -0x6]` |
| `10013de8` | `3b 51 fa` | `CMP EDX,dword ptr [ECX + -0x6]` |
| `10013deb` | `74 7d` | `JZ 0x10013e6a` |
| `10013ded` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013df0` | `0f b6 51 fa` | `MOVZX EDX,byte ptr [ECX + -0x6]` |
| `10013df4` | `2b f2` | `SUB ESI,EDX` |
| `10013df6` | `74 15` | `JZ 0x10013e0d` |
| `10013df8` | `33 d2` | `XOR EDX,EDX` |
| `10013dfa` | `85 f6` | `TEST ESI,ESI` |
| `10013dfc` | `0f 9f c2` | `SETG DL` |
| `10013dff` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013e03` | `8b f2` | `MOV ESI,EDX` |
| `10013e05` | `85 f6` | `TEST ESI,ESI` |
| `10013e07` | `0f 85 96 f4 ff ff` | `JNZ 0x100132a3` |
| `10013e0d` | `0f b6 70 fb` | `MOVZX ESI,byte ptr [EAX + -0x5]` |
| `10013e11` | `0f b6 51 fb` | `MOVZX EDX,byte ptr [ECX + -0x5]` |
| `10013e15` | `2b f2` | `SUB ESI,EDX` |
| `10013e17` | `74 15` | `JZ 0x10013e2e` |
| `10013e19` | `33 d2` | `XOR EDX,EDX` |
| `10013e1b` | `85 f6` | `TEST ESI,ESI` |
| `10013e1d` | `0f 9f c2` | `SETG DL` |
| `10013e20` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013e24` | `8b f2` | `MOV ESI,EDX` |
| `10013e26` | `85 f6` | `TEST ESI,ESI` |
| `10013e28` | `0f 85 75 f4 ff ff` | `JNZ 0x100132a3` |
| `10013e2e` | `0f b6 70 fc` | `MOVZX ESI,byte ptr [EAX + -0x4]` |
| `10013e32` | `0f b6 51 fc` | `MOVZX EDX,byte ptr [ECX + -0x4]` |
| `10013e36` | `2b f2` | `SUB ESI,EDX` |
| `10013e38` | `74 15` | `JZ 0x10013e4f` |
| `10013e3a` | `33 d2` | `XOR EDX,EDX` |
| `10013e3c` | `85 f6` | `TEST ESI,ESI` |
| `10013e3e` | `0f 9f c2` | `SETG DL` |
| `10013e41` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013e45` | `8b f2` | `MOV ESI,EDX` |
| `10013e47` | `85 f6` | `TEST ESI,ESI` |
| `10013e49` | `0f 85 54 f4 ff ff` | `JNZ 0x100132a3` |
| `10013e4f` | `0f b6 70 fd` | `MOVZX ESI,byte ptr [EAX + -0x3]` |
| `10013e53` | `0f b6 51 fd` | `MOVZX EDX,byte ptr [ECX + -0x3]` |
| `10013e57` | `2b f2` | `SUB ESI,EDX` |
| `10013e59` | `74 11` | `JZ 0x10013e6c` |
| `10013e5b` | `33 d2` | `XOR EDX,EDX` |
| `10013e5d` | `85 f6` | `TEST ESI,ESI` |
| `10013e5f` | `0f 9f c2` | `SETG DL` |
| `10013e62` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013e66` | `8b f2` | `MOV ESI,EDX` |
| `10013e68` | `eb 02` | `JMP 0x10013e6c` |
| `10013e6a` | `33 f6` | `XOR ESI,ESI` |
| `10013e6c` | `85 f6` | `TEST ESI,ESI` |
| `10013e6e` | `0f 85 2f f4 ff ff` | `JNZ 0x100132a3` |
| `10013e74` | `66 8b 50 fe` | `MOV DX,word ptr [EAX + -0x2]` |
| `10013e78` | `66 3b 51 fe` | `CMP DX,word ptr [ECX + -0x2]` |
| `10013e7c` | `0f 84 f4 f7 ff ff` | `JZ 0x10013676` |
| `10013e82` | `0f b6 51 fe` | `MOVZX EDX,byte ptr [ECX + -0x2]` |
| `10013e86` | `0f b6 70 fe` | `MOVZX ESI,byte ptr [EAX + -0x2]` |
| `10013e8a` | `2b f2` | `SUB ESI,EDX` |
| `10013e8c` | `0f 84 d6 fb ff ff` | `JZ 0x10013a68` |
| `10013e92` | `33 d2` | `XOR EDX,EDX` |
| `10013e94` | `85 f6` | `TEST ESI,ESI` |
| `10013e96` | `0f 9f c2` | `SETG DL` |
| `10013e99` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013e9d` | `85 d2` | `TEST EDX,EDX` |
| `10013e9f` | `0f 85 13 04 00 00` | `JNZ 0x100142b8` |
| `10013ea5` | `e9 be fb ff ff` | `JMP 0x10013a68` |
| `10013eaa` | `8b 50 e1` | `MOV EDX,dword ptr [EAX + -0x1f]` |
| `10013ead` | `3b 51 e1` | `CMP EDX,dword ptr [ECX + -0x1f]` |
| `10013eb0` | `74 7e` | `JZ 0x10013f30` |
| `10013eb2` | `0f b6 51 e1` | `MOVZX EDX,byte ptr [ECX + -0x1f]` |
| `10013eb6` | `0f b6 70 e1` | `MOVZX ESI,byte ptr [EAX + -0x1f]` |
| `10013eba` | `2b f2` | `SUB ESI,EDX` |
| `10013ebc` | `74 15` | `JZ 0x10013ed3` |
| `10013ebe` | `33 d2` | `XOR EDX,EDX` |
| `10013ec0` | `85 f6` | `TEST ESI,ESI` |
| `10013ec2` | `0f 9f c2` | `SETG DL` |
| `10013ec5` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013ec9` | `8b f2` | `MOV ESI,EDX` |
| `10013ecb` | `85 f6` | `TEST ESI,ESI` |
| `10013ecd` | `0f 85 d0 f3 ff ff` | `JNZ 0x100132a3` |
| `10013ed3` | `0f b6 70 e2` | `MOVZX ESI,byte ptr [EAX + -0x1e]` |
| `10013ed7` | `0f b6 51 e2` | `MOVZX EDX,byte ptr [ECX + -0x1e]` |
| `10013edb` | `2b f2` | `SUB ESI,EDX` |
| `10013edd` | `74 15` | `JZ 0x10013ef4` |
| `10013edf` | `33 d2` | `XOR EDX,EDX` |
| `10013ee1` | `85 f6` | `TEST ESI,ESI` |
| `10013ee3` | `0f 9f c2` | `SETG DL` |
| `10013ee6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013eea` | `8b f2` | `MOV ESI,EDX` |
| `10013eec` | `85 f6` | `TEST ESI,ESI` |
| `10013eee` | `0f 85 af f3 ff ff` | `JNZ 0x100132a3` |
| `10013ef4` | `0f b6 70 e3` | `MOVZX ESI,byte ptr [EAX + -0x1d]` |
| `10013ef8` | `0f b6 51 e3` | `MOVZX EDX,byte ptr [ECX + -0x1d]` |
| `10013efc` | `2b f2` | `SUB ESI,EDX` |
| `10013efe` | `74 15` | `JZ 0x10013f15` |
| `10013f00` | `33 d2` | `XOR EDX,EDX` |
| `10013f02` | `85 f6` | `TEST ESI,ESI` |
| `10013f04` | `0f 9f c2` | `SETG DL` |
| `10013f07` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013f0b` | `8b f2` | `MOV ESI,EDX` |
| `10013f0d` | `85 f6` | `TEST ESI,ESI` |
| `10013f0f` | `0f 85 8e f3 ff ff` | `JNZ 0x100132a3` |
| `10013f15` | `0f b6 70 e4` | `MOVZX ESI,byte ptr [EAX + -0x1c]` |
| `10013f19` | `0f b6 51 e4` | `MOVZX EDX,byte ptr [ECX + -0x1c]` |
| `10013f1d` | `2b f2` | `SUB ESI,EDX` |
| `10013f1f` | `74 11` | `JZ 0x10013f32` |
| `10013f21` | `33 d2` | `XOR EDX,EDX` |
| `10013f23` | `85 f6` | `TEST ESI,ESI` |
| `10013f25` | `0f 9f c2` | `SETG DL` |
| `10013f28` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013f2c` | `8b f2` | `MOV ESI,EDX` |
| `10013f2e` | `eb 02` | `JMP 0x10013f32` |
| `10013f30` | `33 f6` | `XOR ESI,ESI` |
| `10013f32` | `85 f6` | `TEST ESI,ESI` |
| `10013f34` | `0f 85 69 f3 ff ff` | `JNZ 0x100132a3` |
| `10013f3a` | `8b 50 e5` | `MOV EDX,dword ptr [EAX + -0x1b]` |
| `10013f3d` | `3b 51 e5` | `CMP EDX,dword ptr [ECX + -0x1b]` |
| `10013f40` | `74 7d` | `JZ 0x10013fbf` |
| `10013f42` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013f45` | `0f b6 51 e5` | `MOVZX EDX,byte ptr [ECX + -0x1b]` |
| `10013f49` | `2b f2` | `SUB ESI,EDX` |
| `10013f4b` | `74 15` | `JZ 0x10013f62` |
| `10013f4d` | `33 d2` | `XOR EDX,EDX` |
| `10013f4f` | `85 f6` | `TEST ESI,ESI` |
| `10013f51` | `0f 9f c2` | `SETG DL` |
| `10013f54` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013f58` | `8b f2` | `MOV ESI,EDX` |
| `10013f5a` | `85 f6` | `TEST ESI,ESI` |
| `10013f5c` | `0f 85 41 f3 ff ff` | `JNZ 0x100132a3` |
| `10013f62` | `0f b6 70 e6` | `MOVZX ESI,byte ptr [EAX + -0x1a]` |
| `10013f66` | `0f b6 51 e6` | `MOVZX EDX,byte ptr [ECX + -0x1a]` |
| `10013f6a` | `2b f2` | `SUB ESI,EDX` |
| `10013f6c` | `74 15` | `JZ 0x10013f83` |
| `10013f6e` | `33 d2` | `XOR EDX,EDX` |
| `10013f70` | `85 f6` | `TEST ESI,ESI` |
| `10013f72` | `0f 9f c2` | `SETG DL` |
| `10013f75` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013f79` | `8b f2` | `MOV ESI,EDX` |
| `10013f7b` | `85 f6` | `TEST ESI,ESI` |
| `10013f7d` | `0f 85 20 f3 ff ff` | `JNZ 0x100132a3` |
| `10013f83` | `0f b6 70 e7` | `MOVZX ESI,byte ptr [EAX + -0x19]` |
| `10013f87` | `0f b6 51 e7` | `MOVZX EDX,byte ptr [ECX + -0x19]` |
| `10013f8b` | `2b f2` | `SUB ESI,EDX` |
| `10013f8d` | `74 15` | `JZ 0x10013fa4` |
| `10013f8f` | `33 d2` | `XOR EDX,EDX` |
| `10013f91` | `85 f6` | `TEST ESI,ESI` |
| `10013f93` | `0f 9f c2` | `SETG DL` |
| `10013f96` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013f9a` | `8b f2` | `MOV ESI,EDX` |
| `10013f9c` | `85 f6` | `TEST ESI,ESI` |
| `10013f9e` | `0f 85 ff f2 ff ff` | `JNZ 0x100132a3` |
| `10013fa4` | `0f b6 70 e8` | `MOVZX ESI,byte ptr [EAX + -0x18]` |
| `10013fa8` | `0f b6 51 e8` | `MOVZX EDX,byte ptr [ECX + -0x18]` |
| `10013fac` | `2b f2` | `SUB ESI,EDX` |
| `10013fae` | `74 11` | `JZ 0x10013fc1` |
| `10013fb0` | `33 d2` | `XOR EDX,EDX` |
| `10013fb2` | `85 f6` | `TEST ESI,ESI` |
| `10013fb4` | `0f 9f c2` | `SETG DL` |
| `10013fb7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013fbb` | `8b f2` | `MOV ESI,EDX` |
| `10013fbd` | `eb 02` | `JMP 0x10013fc1` |
| `10013fbf` | `33 f6` | `XOR ESI,ESI` |
| `10013fc1` | `85 f6` | `TEST ESI,ESI` |
| `10013fc3` | `0f 85 da f2 ff ff` | `JNZ 0x100132a3` |
| `10013fc9` | `8b 50 e9` | `MOV EDX,dword ptr [EAX + -0x17]` |
| `10013fcc` | `3b 51 e9` | `CMP EDX,dword ptr [ECX + -0x17]` |
| `10013fcf` | `74 7d` | `JZ 0x1001404e` |
| `10013fd1` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10013fd4` | `0f b6 51 e9` | `MOVZX EDX,byte ptr [ECX + -0x17]` |
| `10013fd8` | `2b f2` | `SUB ESI,EDX` |
| `10013fda` | `74 15` | `JZ 0x10013ff1` |
| `10013fdc` | `33 d2` | `XOR EDX,EDX` |
| `10013fde` | `85 f6` | `TEST ESI,ESI` |
| `10013fe0` | `0f 9f c2` | `SETG DL` |
| `10013fe3` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10013fe7` | `8b f2` | `MOV ESI,EDX` |
| `10013fe9` | `85 f6` | `TEST ESI,ESI` |
| `10013feb` | `0f 85 b2 f2 ff ff` | `JNZ 0x100132a3` |
| `10013ff1` | `0f b6 70 ea` | `MOVZX ESI,byte ptr [EAX + -0x16]` |
| `10013ff5` | `0f b6 51 ea` | `MOVZX EDX,byte ptr [ECX + -0x16]` |
| `10013ff9` | `2b f2` | `SUB ESI,EDX` |
| `10013ffb` | `74 15` | `JZ 0x10014012` |
| `10013ffd` | `33 d2` | `XOR EDX,EDX` |
| `10013fff` | `85 f6` | `TEST ESI,ESI` |
| `10014001` | `0f 9f c2` | `SETG DL` |
| `10014004` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014008` | `8b f2` | `MOV ESI,EDX` |
| `1001400a` | `85 f6` | `TEST ESI,ESI` |
| `1001400c` | `0f 85 91 f2 ff ff` | `JNZ 0x100132a3` |
| `10014012` | `0f b6 70 eb` | `MOVZX ESI,byte ptr [EAX + -0x15]` |
| `10014016` | `0f b6 51 eb` | `MOVZX EDX,byte ptr [ECX + -0x15]` |
| `1001401a` | `2b f2` | `SUB ESI,EDX` |
| `1001401c` | `74 15` | `JZ 0x10014033` |
| `1001401e` | `33 d2` | `XOR EDX,EDX` |
| `10014020` | `85 f6` | `TEST ESI,ESI` |
| `10014022` | `0f 9f c2` | `SETG DL` |
| `10014025` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014029` | `8b f2` | `MOV ESI,EDX` |
| `1001402b` | `85 f6` | `TEST ESI,ESI` |
| `1001402d` | `0f 85 70 f2 ff ff` | `JNZ 0x100132a3` |
| `10014033` | `0f b6 70 ec` | `MOVZX ESI,byte ptr [EAX + -0x14]` |
| `10014037` | `0f b6 51 ec` | `MOVZX EDX,byte ptr [ECX + -0x14]` |
| `1001403b` | `2b f2` | `SUB ESI,EDX` |
| `1001403d` | `74 11` | `JZ 0x10014050` |
| `1001403f` | `33 d2` | `XOR EDX,EDX` |
| `10014041` | `85 f6` | `TEST ESI,ESI` |
| `10014043` | `0f 9f c2` | `SETG DL` |
| `10014046` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001404a` | `8b f2` | `MOV ESI,EDX` |
| `1001404c` | `eb 02` | `JMP 0x10014050` |
| `1001404e` | `33 f6` | `XOR ESI,ESI` |
| `10014050` | `85 f6` | `TEST ESI,ESI` |
| `10014052` | `0f 85 4b f2 ff ff` | `JNZ 0x100132a3` |
| `10014058` | `8b 50 ed` | `MOV EDX,dword ptr [EAX + -0x13]` |
| `1001405b` | `3b 51 ed` | `CMP EDX,dword ptr [ECX + -0x13]` |
| `1001405e` | `74 7d` | `JZ 0x100140dd` |
| `10014060` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10014063` | `0f b6 51 ed` | `MOVZX EDX,byte ptr [ECX + -0x13]` |
| `10014067` | `2b f2` | `SUB ESI,EDX` |
| `10014069` | `74 15` | `JZ 0x10014080` |
| `1001406b` | `33 d2` | `XOR EDX,EDX` |
| `1001406d` | `85 f6` | `TEST ESI,ESI` |
| `1001406f` | `0f 9f c2` | `SETG DL` |
| `10014072` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014076` | `8b f2` | `MOV ESI,EDX` |
| `10014078` | `85 f6` | `TEST ESI,ESI` |
| `1001407a` | `0f 85 23 f2 ff ff` | `JNZ 0x100132a3` |
| `10014080` | `0f b6 70 ee` | `MOVZX ESI,byte ptr [EAX + -0x12]` |
| `10014084` | `0f b6 51 ee` | `MOVZX EDX,byte ptr [ECX + -0x12]` |
| `10014088` | `2b f2` | `SUB ESI,EDX` |
| `1001408a` | `74 15` | `JZ 0x100140a1` |
| `1001408c` | `33 d2` | `XOR EDX,EDX` |
| `1001408e` | `85 f6` | `TEST ESI,ESI` |
| `10014090` | `0f 9f c2` | `SETG DL` |
| `10014093` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014097` | `8b f2` | `MOV ESI,EDX` |
| `10014099` | `85 f6` | `TEST ESI,ESI` |
| `1001409b` | `0f 85 02 f2 ff ff` | `JNZ 0x100132a3` |
| `100140a1` | `0f b6 70 ef` | `MOVZX ESI,byte ptr [EAX + -0x11]` |
| `100140a5` | `0f b6 51 ef` | `MOVZX EDX,byte ptr [ECX + -0x11]` |
| `100140a9` | `2b f2` | `SUB ESI,EDX` |
| `100140ab` | `74 15` | `JZ 0x100140c2` |
| `100140ad` | `33 d2` | `XOR EDX,EDX` |
| `100140af` | `85 f6` | `TEST ESI,ESI` |
| `100140b1` | `0f 9f c2` | `SETG DL` |
| `100140b4` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100140b8` | `8b f2` | `MOV ESI,EDX` |
| `100140ba` | `85 f6` | `TEST ESI,ESI` |
| `100140bc` | `0f 85 e1 f1 ff ff` | `JNZ 0x100132a3` |
| `100140c2` | `0f b6 70 f0` | `MOVZX ESI,byte ptr [EAX + -0x10]` |
| `100140c6` | `0f b6 51 f0` | `MOVZX EDX,byte ptr [ECX + -0x10]` |
| `100140ca` | `2b f2` | `SUB ESI,EDX` |
| `100140cc` | `74 11` | `JZ 0x100140df` |
| `100140ce` | `33 d2` | `XOR EDX,EDX` |
| `100140d0` | `85 f6` | `TEST ESI,ESI` |
| `100140d2` | `0f 9f c2` | `SETG DL` |
| `100140d5` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100140d9` | `8b f2` | `MOV ESI,EDX` |
| `100140db` | `eb 02` | `JMP 0x100140df` |
| `100140dd` | `33 f6` | `XOR ESI,ESI` |
| `100140df` | `85 f6` | `TEST ESI,ESI` |
| `100140e1` | `0f 85 bc f1 ff ff` | `JNZ 0x100132a3` |
| `100140e7` | `8b 50 f1` | `MOV EDX,dword ptr [EAX + -0xf]` |
| `100140ea` | `3b 51 f1` | `CMP EDX,dword ptr [ECX + -0xf]` |
| `100140ed` | `74 7e` | `JZ 0x1001416d` |
| `100140ef` | `0f b6 51 f1` | `MOVZX EDX,byte ptr [ECX + -0xf]` |
| `100140f3` | `0f b6 70 f1` | `MOVZX ESI,byte ptr [EAX + -0xf]` |
| `100140f7` | `2b f2` | `SUB ESI,EDX` |
| `100140f9` | `74 15` | `JZ 0x10014110` |
| `100140fb` | `33 d2` | `XOR EDX,EDX` |
| `100140fd` | `85 f6` | `TEST ESI,ESI` |
| `100140ff` | `0f 9f c2` | `SETG DL` |
| `10014102` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014106` | `8b f2` | `MOV ESI,EDX` |
| `10014108` | `85 f6` | `TEST ESI,ESI` |
| `1001410a` | `0f 85 93 f1 ff ff` | `JNZ 0x100132a3` |
| `10014110` | `0f b6 70 f2` | `MOVZX ESI,byte ptr [EAX + -0xe]` |
| `10014114` | `0f b6 51 f2` | `MOVZX EDX,byte ptr [ECX + -0xe]` |
| `10014118` | `2b f2` | `SUB ESI,EDX` |
| `1001411a` | `74 15` | `JZ 0x10014131` |
| `1001411c` | `33 d2` | `XOR EDX,EDX` |
| `1001411e` | `85 f6` | `TEST ESI,ESI` |
| `10014120` | `0f 9f c2` | `SETG DL` |
| `10014123` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014127` | `8b f2` | `MOV ESI,EDX` |
| `10014129` | `85 f6` | `TEST ESI,ESI` |
| `1001412b` | `0f 85 72 f1 ff ff` | `JNZ 0x100132a3` |
| `10014131` | `0f b6 70 f3` | `MOVZX ESI,byte ptr [EAX + -0xd]` |
| `10014135` | `0f b6 51 f3` | `MOVZX EDX,byte ptr [ECX + -0xd]` |
| `10014139` | `2b f2` | `SUB ESI,EDX` |
| `1001413b` | `74 15` | `JZ 0x10014152` |
| `1001413d` | `33 d2` | `XOR EDX,EDX` |
| `1001413f` | `85 f6` | `TEST ESI,ESI` |
| `10014141` | `0f 9f c2` | `SETG DL` |
| `10014144` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014148` | `8b f2` | `MOV ESI,EDX` |
| `1001414a` | `85 f6` | `TEST ESI,ESI` |
| `1001414c` | `0f 85 51 f1 ff ff` | `JNZ 0x100132a3` |
| `10014152` | `0f b6 70 f4` | `MOVZX ESI,byte ptr [EAX + -0xc]` |
| `10014156` | `0f b6 51 f4` | `MOVZX EDX,byte ptr [ECX + -0xc]` |
| `1001415a` | `2b f2` | `SUB ESI,EDX` |
| `1001415c` | `74 11` | `JZ 0x1001416f` |
| `1001415e` | `33 d2` | `XOR EDX,EDX` |
| `10014160` | `85 f6` | `TEST ESI,ESI` |
| `10014162` | `0f 9f c2` | `SETG DL` |
| `10014165` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014169` | `8b f2` | `MOV ESI,EDX` |
| `1001416b` | `eb 02` | `JMP 0x1001416f` |
| `1001416d` | `33 f6` | `XOR ESI,ESI` |
| `1001416f` | `85 f6` | `TEST ESI,ESI` |
| `10014171` | `0f 85 2c f1 ff ff` | `JNZ 0x100132a3` |
| `10014177` | `8b 50 f5` | `MOV EDX,dword ptr [EAX + -0xb]` |
| `1001417a` | `3b 51 f5` | `CMP EDX,dword ptr [ECX + -0xb]` |
| `1001417d` | `74 7d` | `JZ 0x100141fc` |
| `1001417f` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10014182` | `0f b6 51 f5` | `MOVZX EDX,byte ptr [ECX + -0xb]` |
| `10014186` | `2b f2` | `SUB ESI,EDX` |
| `10014188` | `74 15` | `JZ 0x1001419f` |
| `1001418a` | `33 d2` | `XOR EDX,EDX` |
| `1001418c` | `85 f6` | `TEST ESI,ESI` |
| `1001418e` | `0f 9f c2` | `SETG DL` |
| `10014191` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014195` | `8b f2` | `MOV ESI,EDX` |
| `10014197` | `85 f6` | `TEST ESI,ESI` |
| `10014199` | `0f 85 04 f1 ff ff` | `JNZ 0x100132a3` |
| `1001419f` | `0f b6 70 f6` | `MOVZX ESI,byte ptr [EAX + -0xa]` |
| `100141a3` | `0f b6 51 f6` | `MOVZX EDX,byte ptr [ECX + -0xa]` |
| `100141a7` | `2b f2` | `SUB ESI,EDX` |
| `100141a9` | `74 15` | `JZ 0x100141c0` |
| `100141ab` | `33 d2` | `XOR EDX,EDX` |
| `100141ad` | `85 f6` | `TEST ESI,ESI` |
| `100141af` | `0f 9f c2` | `SETG DL` |
| `100141b2` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100141b6` | `8b f2` | `MOV ESI,EDX` |
| `100141b8` | `85 f6` | `TEST ESI,ESI` |
| `100141ba` | `0f 85 e3 f0 ff ff` | `JNZ 0x100132a3` |
| `100141c0` | `0f b6 70 f7` | `MOVZX ESI,byte ptr [EAX + -0x9]` |
| `100141c4` | `0f b6 51 f7` | `MOVZX EDX,byte ptr [ECX + -0x9]` |
| `100141c8` | `2b f2` | `SUB ESI,EDX` |
| `100141ca` | `74 15` | `JZ 0x100141e1` |
| `100141cc` | `33 d2` | `XOR EDX,EDX` |
| `100141ce` | `85 f6` | `TEST ESI,ESI` |
| `100141d0` | `0f 9f c2` | `SETG DL` |
| `100141d3` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100141d7` | `8b f2` | `MOV ESI,EDX` |
| `100141d9` | `85 f6` | `TEST ESI,ESI` |
| `100141db` | `0f 85 c2 f0 ff ff` | `JNZ 0x100132a3` |
| `100141e1` | `0f b6 70 f8` | `MOVZX ESI,byte ptr [EAX + -0x8]` |
| `100141e5` | `0f b6 51 f8` | `MOVZX EDX,byte ptr [ECX + -0x8]` |
| `100141e9` | `2b f2` | `SUB ESI,EDX` |
| `100141eb` | `74 11` | `JZ 0x100141fe` |
| `100141ed` | `33 d2` | `XOR EDX,EDX` |
| `100141ef` | `85 f6` | `TEST ESI,ESI` |
| `100141f1` | `0f 9f c2` | `SETG DL` |
| `100141f4` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100141f8` | `8b f2` | `MOV ESI,EDX` |
| `100141fa` | `eb 02` | `JMP 0x100141fe` |
| `100141fc` | `33 f6` | `XOR ESI,ESI` |
| `100141fe` | `85 f6` | `TEST ESI,ESI` |
| `10014200` | `0f 85 9d f0 ff ff` | `JNZ 0x100132a3` |
| `10014206` | `8b 50 f9` | `MOV EDX,dword ptr [EAX + -0x7]` |
| `10014209` | `3b 51 f9` | `CMP EDX,dword ptr [ECX + -0x7]` |
| `1001420c` | `74 7d` | `JZ 0x1001428b` |
| `1001420e` | `0f b6 f2` | `MOVZX ESI,DL` |
| `10014211` | `0f b6 51 f9` | `MOVZX EDX,byte ptr [ECX + -0x7]` |
| `10014215` | `2b f2` | `SUB ESI,EDX` |
| `10014217` | `74 15` | `JZ 0x1001422e` |
| `10014219` | `33 d2` | `XOR EDX,EDX` |
| `1001421b` | `85 f6` | `TEST ESI,ESI` |
| `1001421d` | `0f 9f c2` | `SETG DL` |
| `10014220` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014224` | `8b f2` | `MOV ESI,EDX` |
| `10014226` | `85 f6` | `TEST ESI,ESI` |
| `10014228` | `0f 85 75 f0 ff ff` | `JNZ 0x100132a3` |
| `1001422e` | `0f b6 70 fa` | `MOVZX ESI,byte ptr [EAX + -0x6]` |
| `10014232` | `0f b6 51 fa` | `MOVZX EDX,byte ptr [ECX + -0x6]` |
| `10014236` | `2b f2` | `SUB ESI,EDX` |
| `10014238` | `74 15` | `JZ 0x1001424f` |
| `1001423a` | `33 d2` | `XOR EDX,EDX` |
| `1001423c` | `85 f6` | `TEST ESI,ESI` |
| `1001423e` | `0f 9f c2` | `SETG DL` |
| `10014241` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014245` | `8b f2` | `MOV ESI,EDX` |
| `10014247` | `85 f6` | `TEST ESI,ESI` |
| `10014249` | `0f 85 54 f0 ff ff` | `JNZ 0x100132a3` |
| `1001424f` | `0f b6 70 fb` | `MOVZX ESI,byte ptr [EAX + -0x5]` |
| `10014253` | `0f b6 51 fb` | `MOVZX EDX,byte ptr [ECX + -0x5]` |
| `10014257` | `2b f2` | `SUB ESI,EDX` |
| `10014259` | `74 15` | `JZ 0x10014270` |
| `1001425b` | `33 d2` | `XOR EDX,EDX` |
| `1001425d` | `85 f6` | `TEST ESI,ESI` |
| `1001425f` | `0f 9f c2` | `SETG DL` |
| `10014262` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014266` | `8b f2` | `MOV ESI,EDX` |
| `10014268` | `85 f6` | `TEST ESI,ESI` |
| `1001426a` | `0f 85 33 f0 ff ff` | `JNZ 0x100132a3` |
| `10014270` | `0f b6 70 fc` | `MOVZX ESI,byte ptr [EAX + -0x4]` |
| `10014274` | `0f b6 51 fc` | `MOVZX EDX,byte ptr [ECX + -0x4]` |
| `10014278` | `2b f2` | `SUB ESI,EDX` |
| `1001427a` | `74 11` | `JZ 0x1001428d` |
| `1001427c` | `33 d2` | `XOR EDX,EDX` |
| `1001427e` | `85 f6` | `TEST ESI,ESI` |
| `10014280` | `0f 9f c2` | `SETG DL` |
| `10014283` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014287` | `8b f2` | `MOV ESI,EDX` |
| `10014289` | `eb 02` | `JMP 0x1001428d` |
| `1001428b` | `33 f6` | `XOR ESI,ESI` |
| `1001428d` | `85 f6` | `TEST ESI,ESI` |
| `1001428f` | `0f 85 0e f0 ff ff` | `JNZ 0x100132a3` |
| `10014295` | `0f b6 70 fd` | `MOVZX ESI,byte ptr [EAX + -0x3]` |
| `10014299` | `0f b6 51 fd` | `MOVZX EDX,byte ptr [ECX + -0x3]` |
| `1001429d` | `2b f2` | `SUB ESI,EDX` |
| `1001429f` | `0f 84 dd fb ff ff` | `JZ 0x10013e82` |
| `100142a5` | `33 d2` | `XOR EDX,EDX` |
| `100142a7` | `85 f6` | `TEST ESI,ESI` |
| `100142a9` | `0f 9f c2` | `SETG DL` |
| `100142ac` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100142b0` | `85 d2` | `TEST EDX,EDX` |
| `100142b2` | `0f 84 ca fb ff ff` | `JZ 0x10013e82` |
| `100142b8` | `8b c2` | `MOV EAX,EDX` |
| `100142ba` | `e9 b9 f3 ff ff` | `JMP 0x10013678` |
| `100142bf` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100142c2` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `100142c5` | `0f b6 01` | `MOVZX EAX,byte ptr [ECX]` |
| `100142c8` | `0f b6 16` | `MOVZX EDX,byte ptr [ESI]` |
| `100142cb` | `2b c2` | `SUB EAX,EDX` |
| `100142cd` | `74 15` | `JZ 0x100142e4` |
| `100142cf` | `33 d2` | `XOR EDX,EDX` |
| `100142d1` | `85 c0` | `TEST EAX,EAX` |
| `100142d3` | `0f 9f c2` | `SETG DL` |
| `100142d6` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100142da` | `8b c2` | `MOV EAX,EDX` |
| `100142dc` | `85 c0` | `TEST EAX,EAX` |
| `100142de` | `0f 85 ed 00 00 00` | `JNZ 0x100143d1` |
| `100142e4` | `0f b6 41 01` | `MOVZX EAX,byte ptr [ECX + 0x1]` |
| `100142e8` | `0f b6 56 01` | `MOVZX EDX,byte ptr [ESI + 0x1]` |
| `100142ec` | `2b c2` | `SUB EAX,EDX` |
| `100142ee` | `74 15` | `JZ 0x10014305` |
| `100142f0` | `33 d2` | `XOR EDX,EDX` |
| `100142f2` | `85 c0` | `TEST EAX,EAX` |
| `100142f4` | `0f 9f c2` | `SETG DL` |
| `100142f7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100142fb` | `8b c2` | `MOV EAX,EDX` |
| `100142fd` | `85 c0` | `TEST EAX,EAX` |
| `100142ff` | `0f 85 cc 00 00 00` | `JNZ 0x100143d1` |
| `10014305` | `0f b6 41 02` | `MOVZX EAX,byte ptr [ECX + 0x2]` |
| `10014309` | `0f b6 56 02` | `MOVZX EDX,byte ptr [ESI + 0x2]` |
| `1001430d` | `2b c2` | `SUB EAX,EDX` |
| `1001430f` | `74 15` | `JZ 0x10014326` |
| `10014311` | `33 d2` | `XOR EDX,EDX` |
| `10014313` | `85 c0` | `TEST EAX,EAX` |
| `10014315` | `0f 9f c2` | `SETG DL` |
| `10014318` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `1001431c` | `8b c2` | `MOV EAX,EDX` |
| `1001431e` | `85 c0` | `TEST EAX,EAX` |
| `10014320` | `0f 85 ab 00 00 00` | `JNZ 0x100143d1` |
| `10014326` | `0f b6 41 03` | `MOVZX EAX,byte ptr [ECX + 0x3]` |
| `1001432a` | `0f b6 4e 03` | `MOVZX ECX,byte ptr [ESI + 0x3]` |
| `1001432e` | `2b c1` | `SUB EAX,ECX` |
| `10014330` | `0f 84 9b 00 00 00` | `JZ 0x100143d1` |
| `10014336` | `33 c9` | `XOR ECX,ECX` |
| `10014338` | `85 c0` | `TEST EAX,EAX` |
| `1001433a` | `0f 9f c1` | `SETG CL` |
| `1001433d` | `8d 4c 09 ff` | `LEA ECX,[ECX + ECX*0x1 + -0x1]` |
| `10014341` | `8b c1` | `MOV EAX,ECX` |
| `10014343` | `e9 89 00 00 00` | `JMP 0x100143d1` |
| `10014348` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001434b` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001434e` | `0f b6 01` | `MOVZX EAX,byte ptr [ECX]` |
| `10014351` | `0f b6 16` | `MOVZX EDX,byte ptr [ESI]` |
| `10014354` | `2b c2` | `SUB EAX,EDX` |
| `10014356` | `74 11` | `JZ 0x10014369` |
| `10014358` | `33 d2` | `XOR EDX,EDX` |
| `1001435a` | `85 c0` | `TEST EAX,EAX` |
| `1001435c` | `0f 9f c2` | `SETG DL` |
| `1001435f` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014363` | `8b c2` | `MOV EAX,EDX` |
| `10014365` | `85 c0` | `TEST EAX,EAX` |
| `10014367` | `75 68` | `JNZ 0x100143d1` |
| `10014369` | `0f b6 41 01` | `MOVZX EAX,byte ptr [ECX + 0x1]` |
| `1001436d` | `0f b6 56 01` | `MOVZX EDX,byte ptr [ESI + 0x1]` |
| `10014371` | `2b c2` | `SUB EAX,EDX` |
| `10014373` | `74 11` | `JZ 0x10014386` |
| `10014375` | `33 d2` | `XOR EDX,EDX` |
| `10014377` | `85 c0` | `TEST EAX,EAX` |
| `10014379` | `0f 9f c2` | `SETG DL` |
| `1001437c` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `10014380` | `8b c2` | `MOV EAX,EDX` |
| `10014382` | `85 c0` | `TEST EAX,EAX` |
| `10014384` | `75 4b` | `JNZ 0x100143d1` |
| `10014386` | `0f b6 41 02` | `MOVZX EAX,byte ptr [ECX + 0x2]` |
| `1001438a` | `0f b6 4e 02` | `MOVZX ECX,byte ptr [ESI + 0x2]` |
| `1001438e` | `eb 9e` | `JMP 0x1001432e` |
| `10014390` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10014393` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10014396` | `0f b6 01` | `MOVZX EAX,byte ptr [ECX]` |
| `10014399` | `0f b6 16` | `MOVZX EDX,byte ptr [ESI]` |
| `1001439c` | `2b c2` | `SUB EAX,EDX` |
| `1001439e` | `74 11` | `JZ 0x100143b1` |
| `100143a0` | `33 d2` | `XOR EDX,EDX` |
| `100143a2` | `85 c0` | `TEST EAX,EAX` |
| `100143a4` | `0f 9f c2` | `SETG DL` |
| `100143a7` | `8d 54 12 ff` | `LEA EDX,[EDX + EDX*0x1 + -0x1]` |
| `100143ab` | `8b c2` | `MOV EAX,EDX` |
| `100143ad` | `85 c0` | `TEST EAX,EAX` |
| `100143af` | `75 20` | `JNZ 0x100143d1` |
| `100143b1` | `0f b6 41 01` | `MOVZX EAX,byte ptr [ECX + 0x1]` |
| `100143b5` | `0f b6 4e 01` | `MOVZX ECX,byte ptr [ESI + 0x1]` |
| `100143b9` | `e9 70 ff ff ff` | `JMP 0x1001432e` |
| `100143be` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100143c1` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `100143c4` | `0f b6 00` | `MOVZX EAX,byte ptr [EAX]` |
| `100143c7` | `0f b6 09` | `MOVZX ECX,byte ptr [ECX]` |
| `100143ca` | `e9 5f ff ff ff` | `JMP 0x1001432e` |
| `100143cf` | `33 c0` | `XOR EAX,EAX` |
| `100143d1` | `5f` | `POP EDI` |
| `100143d2` | `5e` | `POP ESI` |
| `100143d3` | `5d` | `POP EBP` |
| `100143d4` | `c3` | `RET` |
