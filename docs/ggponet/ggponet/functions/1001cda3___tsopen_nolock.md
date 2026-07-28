# 1001cda3 `__tsopen_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001cda3 |
| `name` | __tsopen_nolock |
| `namespace` | Global |
| `signature` | undefined __tsopen_nolock(void) |
| `size_bytes` | 1820 |
| `stack_frame_size` | 56 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __tsopen_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __tsopen_nolock
   
   Library: Visual Studio 2008 Release */

int __tsopen_nolock(undefined4 *param_1,LPCSTR param_2,uint param_3,int param_4,byte param_5)

{
  byte *pbVar1;
  byte bVar2;
  uint *in_EAX;
  errno_t eVar3;
  uint uVar4;
  ulong *puVar5;
  int *piVar6;
  DWORD DVar7;
  long lVar8;
  int iVar9;
  HANDLE pvVar10;
  byte bVar11;
  int unaff_EDI;
  int iVar12;
  bool bVar13;
  longlong lVar14;
  _SECURITY_ATTRIBUTES local_34;
  uint local_24;
  HANDLE local_20;
  uint local_1c;
  DWORD local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  char local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  
  bVar13 = (param_3 & 0x80) == 0;
  local_24 = 0;
  local_6 = 0;
  local_34.nLength = 0xc;
  local_34.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar13) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_34.bInheritHandle = (BOOL)bVar13;
  eVar3 = __get_fmode((int *)&local_24);
  if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  if (((param_3 & 0x8000) == 0) && (((param_3 & 0x74000) != 0 || (local_24 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar4 = param_3 & 3;
  if (uVar4 == 0) {
    local_c = 0x80000000;
  }
  else {
    if (uVar4 == 1) {
      if (((param_3 & 8) == 0) || ((param_3 & 0x70000) == 0)) {
        local_c = 0x40000000;
        goto LAB_1001ce70;
      }
    }
    else if (uVar4 != 2) goto LAB_1001ce2c;
    local_c = 0xc0000000;
  }
LAB_1001ce70:
  if (param_4 == 0x10) {
    local_14 = 0;
  }
  else if (param_4 == 0x20) {
    local_14 = 1;
  }
  else if (param_4 == 0x30) {
    local_14 = 2;
  }
  else if (param_4 == 0x40) {
    local_14 = 3;
  }
  else {
    if (param_4 != 0x80) goto LAB_1001ce2c;
    local_14 = (uint)(local_c == 0x80000000);
  }
  uVar4 = param_3 & 0x700;
  if (uVar4 < 0x401) {
    if ((uVar4 == 0x400) || (uVar4 == 0)) {
      local_18 = 3;
    }
    else if (uVar4 == 0x100) {
      local_18 = 4;
    }
    else {
      if (uVar4 == 0x200) goto LAB_1001cf75;
      if (uVar4 != 0x300) goto LAB_1001ce2c;
      local_18 = 2;
    }
  }
  else {
    if (uVar4 != 0x500) {
      if (uVar4 == 0x600) {
LAB_1001cf75:
        local_18 = 5;
        goto LAB_1001cf24;
      }
      if (uVar4 != 0x700) {
LAB_1001ce2c:
        puVar5 = ___doserrno();
        *puVar5 = 0;
        *in_EAX = 0xffffffff;
        piVar6 = __errno();
        *piVar6 = 0x16;
        __invalid_parameter(0,0,0,0,0);
        return 0x16;
      }
    }
    local_18 = 1;
  }
LAB_1001cf24:
  local_10 = 0x80;
  if (((param_3 & 0x100) != 0) && (-1 < (char)(~(byte)DAT_10038a3c & param_5))) {
    local_10 = 1;
  }
  if ((param_3 & 0x40) != 0) {
    local_10 = local_10 | 0x4000000;
    local_c = local_c | 0x10000;
    local_14 = local_14 | 4;
  }
  if ((param_3 & 0x1000) != 0) {
    local_10 = local_10 | 0x100;
  }
  if ((param_3 & 0x20) == 0) {
    if ((param_3 & 0x10) != 0) {
      local_10 = local_10 | 0x10000000;
    }
  }
  else {
    local_10 = local_10 | 0x8000000;
  }
  uVar4 = __alloc_osfhnd();
  *in_EAX = uVar4;
  if (uVar4 == 0xffffffff) {
    puVar5 = ___doserrno();
    *puVar5 = 0;
    *in_EAX = 0xffffffff;
    piVar6 = __errno();
    *piVar6 = 0x18;
    goto LAB_1001d03d;
  }
  *param_1 = 1;
  local_20 = CreateFileA(param_2,local_c,local_14,&local_34,local_18,local_10,(HANDLE)0x0);
  if (local_20 == (HANDLE)0xffffffff) {
    if (((local_c & 0xc0000000) == 0xc0000000) && ((param_3 & 1) != 0)) {
      local_c = local_c & 0x7fffffff;
      local_20 = CreateFileA(param_2,local_c,local_14,&local_34,local_18,local_10,(HANDLE)0x0);
      if (local_20 != (HANDLE)0xffffffff) goto LAB_1001d049;
    }
    pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x40);
    *pbVar1 = *pbVar1 & 0xfe;
    DVar7 = GetLastError();
    __dosmaperr(DVar7);
    goto LAB_1001d03d;
  }
LAB_1001d049:
  DVar7 = GetFileType(local_20);
  if (DVar7 == 0) {
    pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x40);
    *pbVar1 = *pbVar1 & 0xfe;
    DVar7 = GetLastError();
    __dosmaperr(DVar7);
    CloseHandle(local_20);
    if (DVar7 == 0) {
      piVar6 = __errno();
      *piVar6 = 0xd;
    }
    goto LAB_1001d03d;
  }
  if (DVar7 == 2) {
    local_5 = local_5 | 0x40;
  }
  else if (DVar7 == 3) {
    local_5 = local_5 | 8;
  }
  __set_osfhnd(*in_EAX,(intptr_t)local_20);
  bVar11 = local_5 | 1;
  *(byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x40) = bVar11;
  pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 0x24 + (*in_EAX & 0x1f) * 0x40);
  *pbVar1 = *pbVar1 & 0x80;
  local_7 = local_5 & 0x48;
  if (local_7 == 0) {
    bVar2 = local_5 & 0x80;
    local_5 = bVar11;
    if (bVar2 == 0) goto LAB_1001d3bd;
    if ((param_3 & 2) == 0) goto LAB_1001d183;
    local_1c = __lseek_nolock(*in_EAX,-1,2);
    if (local_1c == 0xffffffff) {
      puVar5 = ___doserrno();
      bVar11 = local_5;
      if (*puVar5 == 0x83) goto LAB_1001d183;
    }
    else {
      local_8 = '\0';
      iVar12 = __read_nolock(*in_EAX,&local_8,1);
      if ((((iVar12 != 0) || (local_8 != '\x1a')) ||
          (iVar12 = __chsize_nolock(*in_EAX,CONCAT44(unaff_EDI,(int)local_1c >> 0x1f)), iVar12 != -1
          )) && (lVar8 = __lseek_nolock(*in_EAX,0,0), bVar11 = local_5, lVar8 != -1))
      goto LAB_1001d183;
    }
LAB_1001d136:
    __close_nolock(*in_EAX);
    goto LAB_1001d03d;
  }
LAB_1001d183:
  local_5 = bVar11;
  if ((local_5 & 0x80) != 0) {
    if ((param_3 & 0x74000) == 0) {
      if ((local_24 & 0x74000) == 0) {
        param_3 = param_3 | 0x4000;
      }
      else {
        param_3 = param_3 | local_24 & 0x74000;
      }
    }
    uVar4 = param_3 & 0x74000;
    if (uVar4 == 0x4000) {
      local_6 = 0;
    }
    else if ((uVar4 == 0x10000) || (uVar4 == 0x14000)) {
      if ((param_3 & 0x301) == 0x301) goto LAB_1001d1f2;
    }
    else if ((uVar4 == 0x20000) || (uVar4 == 0x24000)) {
LAB_1001d1f2:
      local_6 = 2;
    }
    else if ((uVar4 == 0x40000) || (uVar4 == 0x44000)) {
      local_6 = 1;
    }
    if (((param_3 & 0x70000) != 0) && (local_1c = 0, (local_5 & 0x40) == 0)) {
      uVar4 = local_c & 0xc0000000;
      if (uVar4 == 0x40000000) {
        if (local_18 == 0) goto LAB_1001d3bd;
        if (2 < local_18) {
          if (local_18 < 5) {
            lVar14 = __lseeki64_nolock(*in_EAX,0x200000000,unaff_EDI);
            if (lVar14 == 0) goto LAB_1001d257;
            lVar14 = __lseeki64_nolock(*in_EAX,0,unaff_EDI);
            uVar4 = (uint)lVar14 & (uint)((ulonglong)lVar14 >> 0x20);
            goto LAB_1001d323;
          }
LAB_1001d24e:
          if (local_18 != 5) goto LAB_1001d3bd;
        }
LAB_1001d257:
        iVar12 = 0;
        if (local_6 == 1) {
          local_1c = 0xbfbbef;
          local_18 = 3;
        }
        else {
          if (local_6 != 2) goto LAB_1001d3bd;
          local_1c = 0xfeff;
          local_18 = 2;
        }
        do {
          iVar9 = __write(*in_EAX,(void *)((int)&local_1c + iVar12),local_18 - iVar12);
          if (iVar9 == -1) goto LAB_1001d136;
          iVar12 = iVar12 + iVar9;
        } while (iVar12 < (int)local_18);
      }
      else {
        if (uVar4 != 0x80000000) {
          if ((uVar4 == 0xc0000000) && (local_18 != 0)) {
            if (2 < local_18) {
              if (4 < local_18) goto LAB_1001d24e;
              lVar14 = __lseeki64_nolock(*in_EAX,0x200000000,unaff_EDI);
              if (lVar14 != 0) {
                lVar14 = __lseeki64_nolock(*in_EAX,0,unaff_EDI);
                if (lVar14 == -1) goto LAB_1001d136;
                goto LAB_1001d2a8;
              }
            }
            goto LAB_1001d257;
          }
          goto LAB_1001d3bd;
        }
LAB_1001d2a8:
        iVar12 = __read_nolock(*in_EAX,&local_1c,3);
        if (iVar12 == -1) goto LAB_1001d136;
        if (iVar12 == 2) {
LAB_1001d331:
          if ((local_1c & 0xffff) == 0xfffe) {
            __close_nolock(*in_EAX);
            piVar6 = __errno();
            *piVar6 = 0x16;
            return 0x16;
          }
          if ((local_1c & 0xffff) == 0xfeff) {
            lVar8 = __lseek_nolock(*in_EAX,2,0);
            if (lVar8 == -1) goto LAB_1001d136;
            local_6 = 2;
            goto LAB_1001d3bd;
          }
        }
        else if (iVar12 == 3) {
          if (local_1c == 0xbfbbef) {
            local_6 = 1;
            goto LAB_1001d3bd;
          }
          goto LAB_1001d331;
        }
        uVar4 = __lseek_nolock(*in_EAX,0,0);
LAB_1001d323:
        if (uVar4 == 0xffffffff) goto LAB_1001d136;
      }
    }
  }
LAB_1001d3bd:
  uVar4 = local_c;
  pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 0x24 + (*in_EAX & 0x1f) * 0x40);
  *pbVar1 = *pbVar1 ^ (*pbVar1 ^ local_6) & 0x7f;
  pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 0x24 + (*in_EAX & 0x1f) * 0x40);
  *pbVar1 = (char)(param_3 >> 0x10) << 7 | *pbVar1 & 0x7f;
  if ((local_7 == 0) && ((param_3 & 8) != 0)) {
    pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x40);
    *pbVar1 = *pbVar1 | 0x20;
  }
  if (((local_c & 0xc0000000) == 0xc0000000) && ((param_3 & 1) != 0)) {
    CloseHandle(local_20);
    pvVar10 = CreateFileA(param_2,uVar4 & 0x7fffffff,local_14,&local_34,3,local_10,(HANDLE)0x0);
    if (pvVar10 == (HANDLE)0xffffffff) {
      DVar7 = GetLastError();
      __dosmaperr(DVar7);
      pbVar1 = (byte *)((&DAT_13439540)[(int)*in_EAX >> 5] + 4 + (*in_EAX & 0x1f) * 0x40);
      *pbVar1 = *pbVar1 & 0xfe;
      __free_osfhnd(*in_EAX);
LAB_1001d03d:
      piVar6 = __errno();
      return *piVar6;
    }
    *(HANDLE *)((*in_EAX & 0x1f) * 0x40 + (&DAT_13439540)[(int)*in_EAX >> 5]) = pvVar10;
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cddf` | `1001f633` | `UNCONDITIONAL_CALL` | __get_fmode | `1001f633` |
| `1001cdee` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1001ce2c` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001ce36` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001ce45` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001cf89` | `1001dcf4` | `UNCONDITIONAL_CALL` | __alloc_osfhnd | `1001dcf4` |
| `1001cf95` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001cf9f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001cfd2` | `EXTERNAL:0000002e` | `COMPUTED_CALL` | KERNEL32.DLL::CreateFileA | `` |
| `1001d00b` | `EXTERNAL:0000002e` | `COMPUTED_CALL` | KERNEL32.DLL::CreateFileA | `` |
| `1001d030` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001d037` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |
| `1001d03d` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d04c` | `EXTERNAL:00000051` | `COMPUTED_CALL` | KERNEL32.DLL::GetFileType | `` |
| `1001d071` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001d07a` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |
| `1001d083` | `EXTERNAL:00000028` | `COMPUTED_CALL` | KERNEL32.DLL::CloseHandle | `` |
| `1001d08d` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d0b3` | `1001daaf` | `UNCONDITIONAL_CALL` | __set_osfhnd | `1001daaf` |
| `1001d11a` | `1001f502` | `UNCONDITIONAL_CALL` | __lseek_nolock | `1001f502` |
| `1001d129` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001d138` | `10018c77` | `UNCONDITIONAL_CALL` | __close_nolock | `10018c77` |
| `1001d14d` | `10018586` | `UNCONDITIONAL_CALL` | __read_nolock | `10018586` |
| `1001d167` | `1001f34c` | `UNCONDITIONAL_CALL` | __chsize_nolock | `1001f34c` |
| `1001d177` | `1001f502` | `UNCONDITIONAL_CALL` | __lseek_nolock | `1001f502` |
| `1001d284` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001d295` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001d2b0` | `10018586` | `UNCONDITIONAL_CALL` | __read_nolock | `10018586` |
| `1001d304` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001d319` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001d342` | `10018c77` | `UNCONDITIONAL_CALL` | __close_nolock | `10018c77` |
| `1001d348` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d365` | `1001f502` | `UNCONDITIONAL_CALL` | __lseek_nolock | `1001f502` |
| `1001d380` | `1001f502` | `UNCONDITIONAL_CALL` | __lseek_nolock | `1001f502` |
| `1001d3a5` | `1001a312` | `UNCONDITIONAL_CALL` | __write | `1001a312` |
| `1001d448` | `EXTERNAL:00000028` | `COMPUTED_CALL` | KERNEL32.DLL::CloseHandle | `` |
| `1001d465` | `EXTERNAL:0000002e` | `COMPUTED_CALL` | KERNEL32.DLL::CreateFileA | `` |
| `1001d470` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001d477` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |
| `1001d499` | `1001db30` | `UNCONDITIONAL_CALL` | __free_osfhnd | `1001db30` |

## Callers

| From | Function |
| --- | --- |
| `1001d534` | __sopen_helper |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001cf32` | `10038a3c` | `READ` | DAT_10038a3c |
| `1001cf82` | `10000000` | `DATA` | IMAGE_DOS_HEADER_10000000 |
| `1001cfb2` | `1002e070` | `READ` | PTR_CreateFileA_1002e070 |
| `1001d01c` | `13439540` | `DATA` | DAT_13439540 |
| `1001d030` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001d04c` | `1002e0fc` | `READ` | PTR_GetFileType_1002e0fc |
| `1001d05d` | `13439540` | `DATA` | DAT_13439540 |
| `1001d071` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001d083` | `1002e058` | `READ` | PTR_CloseHandle_1002e058 |
| `1001d0c2` | `13439540` | `DATA` | DAT_13439540 |
| `1001d0e2` | `13439540` | `DATA` | DAT_13439540 |
| `1001d3c4` | `13439540` | `DATA` | DAT_13439540 |
| `1001d3e6` | `13439540` | `DATA` | DAT_13439540 |
| `1001d41e` | `13439540` | `DATA` | DAT_13439540 |
| `1001d448` | `1002e058` | `READ` | PTR_CloseHandle_1002e058 |
| `1001d465` | `1002e070` | `READ` | PTR_CreateFileA_1002e070 |
| `1001d470` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001d486` | `13439540` | `DATA` | DAT_13439540 |
| `1001d4ab` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001cda3` | `8b ff` | `MOV EDI,EDI` |
| `1001cda5` | `55` | `PUSH EBP` |
| `1001cda6` | `8b ec` | `MOV EBP,ESP` |
| `1001cda8` | `83 ec 30` | `SUB ESP,0x30` |
| `1001cdab` | `53` | `PUSH EBX` |
| `1001cdac` | `33 db` | `XOR EBX,EBX` |
| `1001cdae` | `f6 45 10 80` | `TEST byte ptr [EBP + 0x10],0x80` |
| `1001cdb2` | `56` | `PUSH ESI` |
| `1001cdb3` | `57` | `PUSH EDI` |
| `1001cdb4` | `8b f0` | `MOV ESI,EAX` |
| `1001cdb6` | `89 5d e0` | `MOV dword ptr [EBP + -0x20],EBX` |
| `1001cdb9` | `88 5d fe` | `MOV byte ptr [EBP + -0x2],BL` |
| `1001cdbc` | `c7 45 d0 0c 00 00 00` | `MOV dword ptr [EBP + -0x30],0xc` |
| `1001cdc3` | `89 5d d4` | `MOV dword ptr [EBP + -0x2c],EBX` |
| `1001cdc6` | `74 09` | `JZ 0x1001cdd1` |
| `1001cdc8` | `89 5d d8` | `MOV dword ptr [EBP + -0x28],EBX` |
| `1001cdcb` | `c6 45 ff 10` | `MOV byte ptr [EBP + -0x1],0x10` |
| `1001cdcf` | `eb 0a` | `JMP 0x1001cddb` |
| `1001cdd1` | `c7 45 d8 01 00 00 00` | `MOV dword ptr [EBP + -0x28],0x1` |
| `1001cdd8` | `88 5d ff` | `MOV byte ptr [EBP + -0x1],BL` |
| `1001cddb` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `1001cdde` | `50` | `PUSH EAX` |
| `1001cddf` | `e8 4f 28 00 00` | `CALL 0x1001f633` |
| `1001cde4` | `59` | `POP ECX` |
| `1001cde5` | `85 c0` | `TEST EAX,EAX` |
| `1001cde7` | `74 0d` | `JZ 0x1001cdf6` |
| `1001cde9` | `53` | `PUSH EBX` |
| `1001cdea` | `53` | `PUSH EBX` |
| `1001cdeb` | `53` | `PUSH EBX` |
| `1001cdec` | `53` | `PUSH EBX` |
| `1001cded` | `53` | `PUSH EBX` |
| `1001cdee` | `e8 94 47 ff ff` | `CALL 0x10011587` |
| `1001cdf6` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001cdf9` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1001cdfe` | `85 c8` | `TEST EAX,ECX` |
| `1001ce00` | `75 11` | `JNZ 0x1001ce13` |
| `1001ce02` | `f7 c1 00 40 07 00` | `TEST ECX,0x74000` |
| `1001ce08` | `75 05` | `JNZ 0x1001ce0f` |
| `1001ce0a` | `39 45 e0` | `CMP dword ptr [EBP + -0x20],EAX` |
| `1001ce0d` | `74 04` | `JZ 0x1001ce13` |
| `1001ce0f` | `80 4d ff 80` | `OR byte ptr [EBP + -0x1],0x80` |
| `1001ce13` | `8b c1` | `MOV EAX,ECX` |
| `1001ce15` | `83 e0 03` | `AND EAX,0x3` |
| `1001ce18` | `2b c3` | `SUB EAX,EBX` |
| `1001ce1a` | `ba 00 00 00 c0` | `MOV EDX,0xc0000000` |
| `1001ce1f` | `bf 00 00 00 80` | `MOV EDI,0x80000000` |
| `1001ce24` | `74 47` | `JZ 0x1001ce6d` |
| `1001ce26` | `48` | `DEC EAX` |
| `1001ce27` | `74 2e` | `JZ 0x1001ce57` |
| `1001ce29` | `48` | `DEC EAX` |
| `1001ce2a` | `74 26` | `JZ 0x1001ce52` |
| `1001ce2c` | `e8 eb 82 ff ff` | `CALL 0x1001511c` |
| `1001ce31` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001ce33` | `83 0e ff` | `OR dword ptr [ESI],0xffffffff` |
| `1001ce36` | `e8 ce 82 ff ff` | `CALL 0x10015109` |
| `1001ce3b` | `6a 16` | `PUSH 0x16` |
| `1001ce3d` | `5e` | `POP ESI` |
| `1001ce3e` | `53` | `PUSH EBX` |
| `1001ce3f` | `53` | `PUSH EBX` |
| `1001ce40` | `53` | `PUSH EBX` |
| `1001ce41` | `53` | `PUSH EBX` |
| `1001ce42` | `53` | `PUSH EBX` |
| `1001ce43` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001ce45` | `e8 65 48 ff ff` | `CALL 0x100116af` |
| `1001ce4a` | `83 c4 14` | `ADD ESP,0x14` |
| `1001ce4d` | `e9 00 05 00 00` | `JMP 0x1001d352` |
| `1001ce52` | `89 55 f8` | `MOV dword ptr [EBP + -0x8],EDX` |
| `1001ce55` | `eb 19` | `JMP 0x1001ce70` |
| `1001ce57` | `f6 c1 08` | `TEST CL,0x8` |
| `1001ce5a` | `74 08` | `JZ 0x1001ce64` |
| `1001ce5c` | `f7 c1 00 00 07 00` | `TEST ECX,0x70000` |
| `1001ce62` | `75 ee` | `JNZ 0x1001ce52` |
| `1001ce64` | `c7 45 f8 00 00 00 40` | `MOV dword ptr [EBP + -0x8],0x40000000` |
| `1001ce6b` | `eb 03` | `JMP 0x1001ce70` |
| `1001ce6d` | `89 7d f8` | `MOV dword ptr [EBP + -0x8],EDI` |
| `1001ce70` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1001ce73` | `6a 10` | `PUSH 0x10` |
| `1001ce75` | `59` | `POP ECX` |
| `1001ce76` | `2b c1` | `SUB EAX,ECX` |
| `1001ce78` | `74 37` | `JZ 0x1001ceb1` |
| `1001ce7a` | `2b c1` | `SUB EAX,ECX` |
| `1001ce7c` | `74 2a` | `JZ 0x1001cea8` |
| `1001ce7e` | `2b c1` | `SUB EAX,ECX` |
| `1001ce80` | `74 1d` | `JZ 0x1001ce9f` |
| `1001ce82` | `2b c1` | `SUB EAX,ECX` |
| `1001ce84` | `74 10` | `JZ 0x1001ce96` |
| `1001ce86` | `83 e8 40` | `SUB EAX,0x40` |
| `1001ce89` | `75 a1` | `JNZ 0x1001ce2c` |
| `1001ce8b` | `39 7d f8` | `CMP dword ptr [EBP + -0x8],EDI` |
| `1001ce8e` | `0f 94 c0` | `SETZ AL` |
| `1001ce91` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `1001ce94` | `eb 1e` | `JMP 0x1001ceb4` |
| `1001ce96` | `c7 45 f0 03 00 00 00` | `MOV dword ptr [EBP + -0x10],0x3` |
| `1001ce9d` | `eb 15` | `JMP 0x1001ceb4` |
| `1001ce9f` | `c7 45 f0 02 00 00 00` | `MOV dword ptr [EBP + -0x10],0x2` |
| `1001cea6` | `eb 0c` | `JMP 0x1001ceb4` |
| `1001cea8` | `c7 45 f0 01 00 00 00` | `MOV dword ptr [EBP + -0x10],0x1` |
| `1001ceaf` | `eb 03` | `JMP 0x1001ceb4` |
| `1001ceb1` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `1001ceb4` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001ceb7` | `ba 00 07 00 00` | `MOV EDX,0x700` |
| `1001cebc` | `23 c2` | `AND EAX,EDX` |
| `1001cebe` | `b9 00 04 00 00` | `MOV ECX,0x400` |
| `1001cec3` | `3b c1` | `CMP EAX,ECX` |
| `1001cec5` | `bf 00 01 00 00` | `MOV EDI,0x100` |
| `1001ceca` | `7f 3b` | `JG 0x1001cf07` |
| `1001cecc` | `74 30` | `JZ 0x1001cefe` |
| `1001cece` | `3b c3` | `CMP EAX,EBX` |
| `1001ced0` | `74 2c` | `JZ 0x1001cefe` |
| `1001ced2` | `3b c7` | `CMP EAX,EDI` |
| `1001ced4` | `74 1f` | `JZ 0x1001cef5` |
| `1001ced6` | `3d 00 02 00 00` | `CMP EAX,0x200` |
| `1001cedb` | `0f 84 94 00 00 00` | `JZ 0x1001cf75` |
| `1001cee1` | `3d 00 03 00 00` | `CMP EAX,0x300` |
| `1001cee6` | `0f 85 40 ff ff ff` | `JNZ 0x1001ce2c` |
| `1001ceec` | `c7 45 ec 02 00 00 00` | `MOV dword ptr [EBP + -0x14],0x2` |
| `1001cef3` | `eb 2f` | `JMP 0x1001cf24` |
| `1001cef5` | `c7 45 ec 04 00 00 00` | `MOV dword ptr [EBP + -0x14],0x4` |
| `1001cefc` | `eb 26` | `JMP 0x1001cf24` |
| `1001cefe` | `c7 45 ec 03 00 00 00` | `MOV dword ptr [EBP + -0x14],0x3` |
| `1001cf05` | `eb 1d` | `JMP 0x1001cf24` |
| `1001cf07` | `3d 00 05 00 00` | `CMP EAX,0x500` |
| `1001cf0c` | `74 0f` | `JZ 0x1001cf1d` |
| `1001cf0e` | `3d 00 06 00 00` | `CMP EAX,0x600` |
| `1001cf13` | `74 60` | `JZ 0x1001cf75` |
| `1001cf15` | `3b c2` | `CMP EAX,EDX` |
| `1001cf17` | `0f 85 0f ff ff ff` | `JNZ 0x1001ce2c` |
| `1001cf1d` | `c7 45 ec 01 00 00 00` | `MOV dword ptr [EBP + -0x14],0x1` |
| `1001cf24` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001cf27` | `c7 45 f4 80 00 00 00` | `MOV dword ptr [EBP + -0xc],0x80` |
| `1001cf2e` | `85 c7` | `TEST EDI,EAX` |
| `1001cf30` | `74 16` | `JZ 0x1001cf48` |
| `1001cf32` | `8b 0d 3c 8a 03 10` | `MOV ECX,dword ptr [0x10038a3c]` |
| `1001cf38` | `f7 d1` | `NOT ECX` |
| `1001cf3a` | `23 4d 18` | `AND ECX,dword ptr [EBP + 0x18]` |
| `1001cf3d` | `84 c9` | `TEST CL,CL` |
| `1001cf3f` | `78 07` | `JS 0x1001cf48` |
| `1001cf41` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `1001cf48` | `a8 40` | `TEST AL,0x40` |
| `1001cf4a` | `74 12` | `JZ 0x1001cf5e` |
| `1001cf4c` | `81 4d f4 00 00 00 04` | `OR dword ptr [EBP + -0xc],0x4000000` |
| `1001cf53` | `81 4d f8 00 00 01 00` | `OR dword ptr [EBP + -0x8],0x10000` |
| `1001cf5a` | `83 4d f0 04` | `OR dword ptr [EBP + -0x10],0x4` |
| `1001cf5e` | `a9 00 10 00 00` | `TEST EAX,0x1000` |
| `1001cf63` | `74 03` | `JZ 0x1001cf68` |
| `1001cf65` | `09 7d f4` | `OR dword ptr [EBP + -0xc],EDI` |
| `1001cf68` | `a8 20` | `TEST AL,0x20` |
| `1001cf6a` | `74 12` | `JZ 0x1001cf7e` |
| `1001cf6c` | `81 4d f4 00 00 00 08` | `OR dword ptr [EBP + -0xc],0x8000000` |
| `1001cf73` | `eb 14` | `JMP 0x1001cf89` |
| `1001cf75` | `c7 45 ec 05 00 00 00` | `MOV dword ptr [EBP + -0x14],0x5` |
| `1001cf7c` | `eb a6` | `JMP 0x1001cf24` |
| `1001cf7e` | `a8 10` | `TEST AL,0x10` |
| `1001cf80` | `74 07` | `JZ 0x1001cf89` |
| `1001cf82` | `81 4d f4 00 00 00 10` | `OR dword ptr [EBP + -0xc],0x10000000` |
| `1001cf89` | `e8 66 0d 00 00` | `CALL 0x1001dcf4` |
| `1001cf8e` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001cf90` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001cf93` | `75 1a` | `JNZ 0x1001cfaf` |
| `1001cf95` | `e8 82 81 ff ff` | `CALL 0x1001511c` |
| `1001cf9a` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001cf9c` | `83 0e ff` | `OR dword ptr [ESI],0xffffffff` |
| `1001cf9f` | `e8 65 81 ff ff` | `CALL 0x10015109` |
| `1001cfa4` | `c7 00 18 00 00 00` | `MOV dword ptr [EAX],0x18` |
| `1001cfaa` | `e9 8e 00 00 00` | `JMP 0x1001d03d` |
| `1001cfaf` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001cfb2` | `8b 3d 70 e0 02 10` | `MOV EDI,dword ptr [0x1002e070]` |
| `1001cfb8` | `53` | `PUSH EBX` |
| `1001cfb9` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001cfbc` | `c7 00 01 00 00 00` | `MOV dword ptr [EAX],0x1` |
| `1001cfc2` | `ff 75 ec` | `PUSH dword ptr [EBP + -0x14]` |
| `1001cfc5` | `8d 45 d0` | `LEA EAX,[EBP + -0x30]` |
| `1001cfc8` | `50` | `PUSH EAX` |
| `1001cfc9` | `ff 75 f0` | `PUSH dword ptr [EBP + -0x10]` |
| `1001cfcc` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001cfcf` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001cfd2` | `ff d7` | `CALL EDI` |
| `1001cfd4` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001cfd7` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001cfda` | `75 6d` | `JNZ 0x1001d049` |
| `1001cfdc` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001cfdf` | `b8 00 00 00 c0` | `MOV EAX,0xc0000000` |
| `1001cfe4` | `23 c8` | `AND ECX,EAX` |
| `1001cfe6` | `3b c8` | `CMP ECX,EAX` |
| `1001cfe8` | `75 2b` | `JNZ 0x1001d015` |
| `1001cfea` | `f6 45 10 01` | `TEST byte ptr [EBP + 0x10],0x1` |
| `1001cfee` | `74 25` | `JZ 0x1001d015` |
| `1001cff0` | `81 65 f8 ff ff ff 7f` | `AND dword ptr [EBP + -0x8],0x7fffffff` |
| `1001cff7` | `53` | `PUSH EBX` |
| `1001cff8` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001cffb` | `8d 45 d0` | `LEA EAX,[EBP + -0x30]` |
| `1001cffe` | `ff 75 ec` | `PUSH dword ptr [EBP + -0x14]` |
| `1001d001` | `50` | `PUSH EAX` |
| `1001d002` | `ff 75 f0` | `PUSH dword ptr [EBP + -0x10]` |
| `1001d005` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001d008` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d00b` | `ff d7` | `CALL EDI` |
| `1001d00d` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001d010` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d013` | `75 34` | `JNZ 0x1001d049` |
| `1001d015` | `8b 36` | `MOV ESI,dword ptr [ESI]` |
| `1001d017` | `8b c6` | `MOV EAX,ESI` |
| `1001d019` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001d01c` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001d023` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001d026` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001d029` | `8d 44 30 04` | `LEA EAX,[EAX + ESI*0x1 + 0x4]` |
| `1001d02d` | `80 20 fe` | `AND byte ptr [EAX],0xfe` |
| `1001d030` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001d036` | `50` | `PUSH EAX` |
| `1001d037` | `e8 f3 80 ff ff` | `CALL 0x1001512f` |
| `1001d03c` | `59` | `POP ECX` |
| `1001d03d` | `e8 c7 80 ff ff` | `CALL 0x10015109` |
| `1001d042` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001d044` | `e9 74 04 00 00` | `JMP 0x1001d4bd` |
| `1001d049` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001d04c` | `ff 15 fc e0 02 10` | `CALL dword ptr [0x1002e0fc]` |
| `1001d052` | `3b c3` | `CMP EAX,EBX` |
| `1001d054` | `75 44` | `JNZ 0x1001d09a` |
| `1001d056` | `8b 36` | `MOV ESI,dword ptr [ESI]` |
| `1001d058` | `8b c6` | `MOV EAX,ESI` |
| `1001d05a` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001d05d` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001d064` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001d067` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001d06a` | `8d 44 30 04` | `LEA EAX,[EAX + ESI*0x1 + 0x4]` |
| `1001d06e` | `80 20 fe` | `AND byte ptr [EAX],0xfe` |
| `1001d071` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001d077` | `8b f0` | `MOV ESI,EAX` |
| `1001d079` | `56` | `PUSH ESI` |
| `1001d07a` | `e8 b0 80 ff ff` | `CALL 0x1001512f` |
| `1001d07f` | `59` | `POP ECX` |
| `1001d080` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001d083` | `ff 15 58 e0 02 10` | `CALL dword ptr [0x1002e058]` |
| `1001d089` | `3b f3` | `CMP ESI,EBX` |
| `1001d08b` | `75 b0` | `JNZ 0x1001d03d` |
| `1001d08d` | `e8 77 80 ff ff` | `CALL 0x10015109` |
| `1001d092` | `c7 00 0d 00 00 00` | `MOV dword ptr [EAX],0xd` |
| `1001d098` | `eb a3` | `JMP 0x1001d03d` |
| `1001d09a` | `83 f8 02` | `CMP EAX,0x2` |
| `1001d09d` | `75 06` | `JNZ 0x1001d0a5` |
| `1001d09f` | `80 4d ff 40` | `OR byte ptr [EBP + -0x1],0x40` |
| `1001d0a3` | `eb 09` | `JMP 0x1001d0ae` |
| `1001d0a5` | `83 f8 03` | `CMP EAX,0x3` |
| `1001d0a8` | `75 04` | `JNZ 0x1001d0ae` |
| `1001d0aa` | `80 4d ff 08` | `OR byte ptr [EBP + -0x1],0x8` |
| `1001d0ae` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001d0b1` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d0b3` | `e8 f7 09 00 00` | `CALL 0x1001daaf` |
| `1001d0b8` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001d0ba` | `8b d0` | `MOV EDX,EAX` |
| `1001d0bc` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001d0bf` | `c1 fa 05` | `SAR EDX,0x5` |
| `1001d0c2` | `8b 14 95 40 95 43 13` | `MOV EDX,dword ptr [EDX*0x4 + 0x13439540]` |
| `1001d0c9` | `59` | `POP ECX` |
| `1001d0ca` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001d0cd` | `59` | `POP ECX` |
| `1001d0ce` | `8a 4d ff` | `MOV CL,byte ptr [EBP + -0x1]` |
| `1001d0d1` | `80 c9 01` | `OR CL,0x1` |
| `1001d0d4` | `88 4c 02 04` | `MOV byte ptr [EDX + EAX*0x1 + 0x4],CL` |
| `1001d0d8` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001d0da` | `8b d0` | `MOV EDX,EAX` |
| `1001d0dc` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001d0df` | `c1 fa 05` | `SAR EDX,0x5` |
| `1001d0e2` | `8b 14 95 40 95 43 13` | `MOV EDX,dword ptr [EDX*0x4 + 0x13439540]` |
| `1001d0e9` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001d0ec` | `8d 44 02 24` | `LEA EAX,[EDX + EAX*0x1 + 0x24]` |
| `1001d0f0` | `80 20 80` | `AND byte ptr [EAX],0x80` |
| `1001d0f3` | `88 4d fd` | `MOV byte ptr [EBP + -0x3],CL` |
| `1001d0f6` | `80 65 fd 48` | `AND byte ptr [EBP + -0x3],0x48` |
| `1001d0fa` | `88 4d ff` | `MOV byte ptr [EBP + -0x1],CL` |
| `1001d0fd` | `0f 85 80 00 00 00` | `JNZ 0x1001d183` |
| `1001d103` | `f6 c1 80` | `TEST CL,0x80` |
| `1001d106` | `0f 84 b1 02 00 00` | `JZ 0x1001d3bd` |
| `1001d10c` | `f6 45 10 02` | `TEST byte ptr [EBP + 0x10],0x2` |
| `1001d110` | `74 71` | `JZ 0x1001d183` |
| `1001d112` | `6a 02` | `PUSH 0x2` |
| `1001d114` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1001d117` | `57` | `PUSH EDI` |
| `1001d118` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d11a` | `e8 e3 23 00 00` | `CALL 0x1001f502` |
| `1001d11f` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d122` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1001d125` | `3b c7` | `CMP EAX,EDI` |
| `1001d127` | `75 19` | `JNZ 0x1001d142` |
| `1001d129` | `e8 ee 7f ff ff` | `CALL 0x1001511c` |
| `1001d12e` | `81 38 83 00 00 00` | `CMP dword ptr [EAX],0x83` |
| `1001d134` | `74 4d` | `JZ 0x1001d183` |
| `1001d136` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d138` | `e8 3a bb ff ff` | `CALL 0x10018c77` |
| `1001d13d` | `e9 fa fe ff ff` | `JMP 0x1001d03c` |
| `1001d142` | `6a 01` | `PUSH 0x1` |
| `1001d144` | `8d 45 fc` | `LEA EAX,[EBP + -0x4]` |
| `1001d147` | `50` | `PUSH EAX` |
| `1001d148` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d14a` | `88 5d fc` | `MOV byte ptr [EBP + -0x4],BL` |
| `1001d14d` | `e8 34 b4 ff ff` | `CALL 0x10018586` |
| `1001d152` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d155` | `85 c0` | `TEST EAX,EAX` |
| `1001d157` | `75 1a` | `JNZ 0x1001d173` |
| `1001d159` | `80 7d fc 1a` | `CMP byte ptr [EBP + -0x4],0x1a` |
| `1001d15d` | `75 14` | `JNZ 0x1001d173` |
| `1001d15f` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1001d162` | `99` | `CDQ` |
| `1001d163` | `52` | `PUSH EDX` |
| `1001d164` | `50` | `PUSH EAX` |
| `1001d165` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d167` | `e8 e0 21 00 00` | `CALL 0x1001f34c` |
| `1001d16c` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d16f` | `3b c7` | `CMP EAX,EDI` |
| `1001d171` | `74 c3` | `JZ 0x1001d136` |
| `1001d173` | `53` | `PUSH EBX` |
| `1001d174` | `53` | `PUSH EBX` |
| `1001d175` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d177` | `e8 86 23 00 00` | `CALL 0x1001f502` |
| `1001d17c` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d17f` | `3b c7` | `CMP EAX,EDI` |
| `1001d181` | `74 b3` | `JZ 0x1001d136` |
| `1001d183` | `f6 45 ff 80` | `TEST byte ptr [EBP + -0x1],0x80` |
| `1001d187` | `0f 84 30 02 00 00` | `JZ 0x1001d3bd` |
| `1001d18d` | `bf 00 40 07 00` | `MOV EDI,0x74000` |
| `1001d192` | `b9 00 40 00 00` | `MOV ECX,0x4000` |
| `1001d197` | `85 7d 10` | `TEST dword ptr [EBP + 0x10],EDI` |
| `1001d19a` | `75 0f` | `JNZ 0x1001d1ab` |
| `1001d19c` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1001d19f` | `23 c7` | `AND EAX,EDI` |
| `1001d1a1` | `75 05` | `JNZ 0x1001d1a8` |
| `1001d1a3` | `09 4d 10` | `OR dword ptr [EBP + 0x10],ECX` |
| `1001d1a6` | `eb 03` | `JMP 0x1001d1ab` |
| `1001d1a8` | `09 45 10` | `OR dword ptr [EBP + 0x10],EAX` |
| `1001d1ab` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001d1ae` | `23 c7` | `AND EAX,EDI` |
| `1001d1b0` | `3b c1` | `CMP EAX,ECX` |
| `1001d1b2` | `74 44` | `JZ 0x1001d1f8` |
| `1001d1b4` | `3d 00 00 01 00` | `CMP EAX,0x10000` |
| `1001d1b9` | `74 29` | `JZ 0x1001d1e4` |
| `1001d1bb` | `3d 00 40 01 00` | `CMP EAX,0x14000` |
| `1001d1c0` | `74 22` | `JZ 0x1001d1e4` |
| `1001d1c2` | `3d 00 00 02 00` | `CMP EAX,0x20000` |
| `1001d1c7` | `74 29` | `JZ 0x1001d1f2` |
| `1001d1c9` | `3d 00 40 02 00` | `CMP EAX,0x24000` |
| `1001d1ce` | `74 22` | `JZ 0x1001d1f2` |
| `1001d1d0` | `3d 00 00 04 00` | `CMP EAX,0x40000` |
| `1001d1d5` | `74 07` | `JZ 0x1001d1de` |
| `1001d1d7` | `3d 00 40 04 00` | `CMP EAX,0x44000` |
| `1001d1dc` | `75 1d` | `JNZ 0x1001d1fb` |
| `1001d1de` | `c6 45 fe 01` | `MOV byte ptr [EBP + -0x2],0x1` |
| `1001d1e2` | `eb 17` | `JMP 0x1001d1fb` |
| `1001d1e4` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001d1e7` | `b8 01 03 00 00` | `MOV EAX,0x301` |
| `1001d1ec` | `23 c8` | `AND ECX,EAX` |
| `1001d1ee` | `3b c8` | `CMP ECX,EAX` |
| `1001d1f0` | `75 09` | `JNZ 0x1001d1fb` |
| `1001d1f2` | `c6 45 fe 02` | `MOV byte ptr [EBP + -0x2],0x2` |
| `1001d1f6` | `eb 03` | `JMP 0x1001d1fb` |
| `1001d1f8` | `88 5d fe` | `MOV byte ptr [EBP + -0x2],BL` |
| `1001d1fb` | `f7 45 10 00 00 07 00` | `TEST dword ptr [EBP + 0x10],0x70000` |
| `1001d202` | `0f 84 b5 01 00 00` | `JZ 0x1001d3bd` |
| `1001d208` | `f6 45 ff 40` | `TEST byte ptr [EBP + -0x1],0x40` |
| `1001d20c` | `89 5d e8` | `MOV dword ptr [EBP + -0x18],EBX` |
| `1001d20f` | `0f 85 a8 01 00 00` | `JNZ 0x1001d3bd` |
| `1001d215` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001d218` | `b9 00 00 00 c0` | `MOV ECX,0xc0000000` |
| `1001d21d` | `23 c1` | `AND EAX,ECX` |
| `1001d21f` | `3d 00 00 00 40` | `CMP EAX,0x40000000` |
| `1001d224` | `0f 84 b7 00 00 00` | `JZ 0x1001d2e1` |
| `1001d22a` | `3d 00 00 00 80` | `CMP EAX,0x80000000` |
| `1001d22f` | `74 77` | `JZ 0x1001d2a8` |
| `1001d231` | `3b c1` | `CMP EAX,ECX` |
| `1001d233` | `0f 85 84 01 00 00` | `JNZ 0x1001d3bd` |
| `1001d239` | `8b 45 ec` | `MOV EAX,dword ptr [EBP + -0x14]` |
| `1001d23c` | `3b c3` | `CMP EAX,EBX` |
| `1001d23e` | `0f 86 79 01 00 00` | `JBE 0x1001d3bd` |
| `1001d244` | `83 f8 02` | `CMP EAX,0x2` |
| `1001d247` | `76 0e` | `JBE 0x1001d257` |
| `1001d249` | `83 f8 04` | `CMP EAX,0x4` |
| `1001d24c` | `76 30` | `JBE 0x1001d27e` |
| `1001d24e` | `83 f8 05` | `CMP EAX,0x5` |
| `1001d251` | `0f 85 66 01 00 00` | `JNZ 0x1001d3bd` |
| `1001d257` | `0f be 45 fe` | `MOVSX EAX,byte ptr [EBP + -0x2]` |
| `1001d25b` | `33 ff` | `XOR EDI,EDI` |
| `1001d25d` | `48` | `DEC EAX` |
| `1001d25e` | `0f 84 26 01 00 00` | `JZ 0x1001d38a` |
| `1001d264` | `48` | `DEC EAX` |
| `1001d265` | `0f 85 52 01 00 00` | `JNZ 0x1001d3bd` |
| `1001d26b` | `c7 45 e8 ff fe 00 00` | `MOV dword ptr [EBP + -0x18],0xfeff` |
| `1001d272` | `c7 45 ec 02 00 00 00` | `MOV dword ptr [EBP + -0x14],0x2` |
| `1001d279` | `e9 1a 01 00 00` | `JMP 0x1001d398` |
| `1001d27e` | `6a 02` | `PUSH 0x2` |
| `1001d280` | `53` | `PUSH EBX` |
| `1001d281` | `53` | `PUSH EBX` |
| `1001d282` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d284` | `e8 a3 e6 ff ff` | `CALL 0x1001b92c` |
| `1001d289` | `83 c4 10` | `ADD ESP,0x10` |
| `1001d28c` | `0b c2` | `OR EAX,EDX` |
| `1001d28e` | `74 c7` | `JZ 0x1001d257` |
| `1001d290` | `53` | `PUSH EBX` |
| `1001d291` | `53` | `PUSH EBX` |
| `1001d292` | `53` | `PUSH EBX` |
| `1001d293` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d295` | `e8 92 e6 ff ff` | `CALL 0x1001b92c` |
| `1001d29a` | `23 c2` | `AND EAX,EDX` |
| `1001d29c` | `83 c4 10` | `ADD ESP,0x10` |
| `1001d29f` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d2a2` | `0f 84 8e fe ff ff` | `JZ 0x1001d136` |
| `1001d2a8` | `6a 03` | `PUSH 0x3` |
| `1001d2aa` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001d2ad` | `50` | `PUSH EAX` |
| `1001d2ae` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d2b0` | `e8 d1 b2 ff ff` | `CALL 0x10018586` |
| `1001d2b5` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d2b8` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d2bb` | `0f 84 75 fe ff ff` | `JZ 0x1001d136` |
| `1001d2c1` | `83 f8 02` | `CMP EAX,0x2` |
| `1001d2c4` | `74 6b` | `JZ 0x1001d331` |
| `1001d2c6` | `83 f8 03` | `CMP EAX,0x3` |
| `1001d2c9` | `0f 85 ad 00 00 00` | `JNZ 0x1001d37c` |
| `1001d2cf` | `81 7d e8 ef bb bf 00` | `CMP dword ptr [EBP + -0x18],0xbfbbef` |
| `1001d2d6` | `75 59` | `JNZ 0x1001d331` |
| `1001d2d8` | `c6 45 fe 01` | `MOV byte ptr [EBP + -0x2],0x1` |
| `1001d2dc` | `e9 dc 00 00 00` | `JMP 0x1001d3bd` |
| `1001d2e1` | `8b 45 ec` | `MOV EAX,dword ptr [EBP + -0x14]` |
| `1001d2e4` | `3b c3` | `CMP EAX,EBX` |
| `1001d2e6` | `0f 86 d1 00 00 00` | `JBE 0x1001d3bd` |
| `1001d2ec` | `83 f8 02` | `CMP EAX,0x2` |
| `1001d2ef` | `0f 86 62 ff ff ff` | `JBE 0x1001d257` |
| `1001d2f5` | `83 f8 04` | `CMP EAX,0x4` |
| `1001d2f8` | `0f 87 50 ff ff ff` | `JA 0x1001d24e` |
| `1001d2fe` | `6a 02` | `PUSH 0x2` |
| `1001d300` | `53` | `PUSH EBX` |
| `1001d301` | `53` | `PUSH EBX` |
| `1001d302` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d304` | `e8 23 e6 ff ff` | `CALL 0x1001b92c` |
| `1001d309` | `83 c4 10` | `ADD ESP,0x10` |
| `1001d30c` | `0b c2` | `OR EAX,EDX` |
| `1001d30e` | `0f 84 43 ff ff ff` | `JZ 0x1001d257` |
| `1001d314` | `53` | `PUSH EBX` |
| `1001d315` | `53` | `PUSH EBX` |
| `1001d316` | `53` | `PUSH EBX` |
| `1001d317` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d319` | `e8 0e e6 ff ff` | `CALL 0x1001b92c` |
| `1001d31e` | `83 c4 10` | `ADD ESP,0x10` |
| `1001d321` | `23 c2` | `AND EAX,EDX` |
| `1001d323` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d326` | `0f 85 91 00 00 00` | `JNZ 0x1001d3bd` |
| `1001d32c` | `e9 05 fe ff ff` | `JMP 0x1001d136` |
| `1001d331` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1001d334` | `25 ff ff 00 00` | `AND EAX,0xffff` |
| `1001d339` | `3d fe ff 00 00` | `CMP EAX,0xfffe` |
| `1001d33e` | `75 19` | `JNZ 0x1001d359` |
| `1001d340` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d342` | `e8 30 b9 ff ff` | `CALL 0x10018c77` |
| `1001d347` | `59` | `POP ECX` |
| `1001d348` | `e8 bc 7d ff ff` | `CALL 0x10015109` |
| `1001d34d` | `6a 16` | `PUSH 0x16` |
| `1001d34f` | `5e` | `POP ESI` |
| `1001d350` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001d352` | `8b c6` | `MOV EAX,ESI` |
| `1001d354` | `e9 64 01 00 00` | `JMP 0x1001d4bd` |
| `1001d359` | `3d ff fe 00 00` | `CMP EAX,0xfeff` |
| `1001d35e` | `75 1c` | `JNZ 0x1001d37c` |
| `1001d360` | `53` | `PUSH EBX` |
| `1001d361` | `6a 02` | `PUSH 0x2` |
| `1001d363` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d365` | `e8 98 21 00 00` | `CALL 0x1001f502` |
| `1001d36a` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d36d` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d370` | `0f 84 c0 fd ff ff` | `JZ 0x1001d136` |
| `1001d376` | `c6 45 fe 02` | `MOV byte ptr [EBP + -0x2],0x2` |
| `1001d37a` | `eb 41` | `JMP 0x1001d3bd` |
| `1001d37c` | `53` | `PUSH EBX` |
| `1001d37d` | `53` | `PUSH EBX` |
| `1001d37e` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d380` | `e8 7d 21 00 00` | `CALL 0x1001f502` |
| `1001d385` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d388` | `eb 99` | `JMP 0x1001d323` |
| `1001d38a` | `c7 45 e8 ef bb bf 00` | `MOV dword ptr [EBP + -0x18],0xbfbbef` |
| `1001d391` | `c7 45 ec 03 00 00 00` | `MOV dword ptr [EBP + -0x14],0x3` |
| `1001d398` | `8b 45 ec` | `MOV EAX,dword ptr [EBP + -0x14]` |
| `1001d39b` | `2b c7` | `SUB EAX,EDI` |
| `1001d39d` | `50` | `PUSH EAX` |
| `1001d39e` | `8d 44 3d e8` | `LEA EAX,[EBP + EDI*0x1 + -0x18]` |
| `1001d3a2` | `50` | `PUSH EAX` |
| `1001d3a3` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d3a5` | `e8 68 cf ff ff` | `CALL 0x1001a312` |
| `1001d3aa` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d3ad` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d3b0` | `0f 84 80 fd ff ff` | `JZ 0x1001d136` |
| `1001d3b6` | `03 f8` | `ADD EDI,EAX` |
| `1001d3b8` | `39 7d ec` | `CMP dword ptr [EBP + -0x14],EDI` |
| `1001d3bb` | `7f db` | `JG 0x1001d398` |
| `1001d3bd` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001d3bf` | `8b c8` | `MOV ECX,EAX` |
| `1001d3c1` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001d3c4` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001d3cb` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001d3ce` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001d3d1` | `8d 44 01 24` | `LEA EAX,[ECX + EAX*0x1 + 0x24]` |
| `1001d3d5` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1001d3d7` | `32 4d fe` | `XOR CL,byte ptr [EBP + -0x2]` |
| `1001d3da` | `80 e1 7f` | `AND CL,0x7f` |
| `1001d3dd` | `30 08` | `XOR byte ptr [EAX],CL` |
| `1001d3df` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001d3e1` | `8b c8` | `MOV ECX,EAX` |
| `1001d3e3` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001d3e6` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001d3ed` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001d3f0` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001d3f3` | `8d 44 01 24` | `LEA EAX,[ECX + EAX*0x1 + 0x24]` |
| `1001d3f7` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001d3fa` | `8a 10` | `MOV DL,byte ptr [EAX]` |
| `1001d3fc` | `c1 e9 10` | `SHR ECX,0x10` |
| `1001d3ff` | `c0 e1 07` | `SHL CL,0x7` |
| `1001d402` | `80 e2 7f` | `AND DL,0x7f` |
| `1001d405` | `0a ca` | `OR CL,DL` |
| `1001d407` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1001d409` | `38 5d fd` | `CMP byte ptr [EBP + -0x3],BL` |
| `1001d40c` | `75 21` | `JNZ 0x1001d42f` |
| `1001d40e` | `f6 45 10 08` | `TEST byte ptr [EBP + 0x10],0x8` |
| `1001d412` | `74 1b` | `JZ 0x1001d42f` |
| `1001d414` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001d416` | `8b c8` | `MOV ECX,EAX` |
| `1001d418` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001d41b` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001d41e` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001d425` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001d428` | `8d 44 01 04` | `LEA EAX,[ECX + EAX*0x1 + 0x4]` |
| `1001d42c` | `80 08 20` | `OR byte ptr [EAX],0x20` |
| `1001d42f` | `8b 7d f8` | `MOV EDI,dword ptr [EBP + -0x8]` |
| `1001d432` | `b8 00 00 00 c0` | `MOV EAX,0xc0000000` |
| `1001d437` | `8b cf` | `MOV ECX,EDI` |
| `1001d439` | `23 c8` | `AND ECX,EAX` |
| `1001d43b` | `3b c8` | `CMP ECX,EAX` |
| `1001d43d` | `75 7c` | `JNZ 0x1001d4bb` |
| `1001d43f` | `f6 45 10 01` | `TEST byte ptr [EBP + 0x10],0x1` |
| `1001d443` | `74 76` | `JZ 0x1001d4bb` |
| `1001d445` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001d448` | `ff 15 58 e0 02 10` | `CALL dword ptr [0x1002e058]` |
| `1001d44e` | `53` | `PUSH EBX` |
| `1001d44f` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001d452` | `8d 45 d0` | `LEA EAX,[EBP + -0x30]` |
| `1001d455` | `6a 03` | `PUSH 0x3` |
| `1001d457` | `50` | `PUSH EAX` |
| `1001d458` | `ff 75 f0` | `PUSH dword ptr [EBP + -0x10]` |
| `1001d45b` | `81 e7 ff ff ff 7f` | `AND EDI,0x7fffffff` |
| `1001d461` | `57` | `PUSH EDI` |
| `1001d462` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d465` | `ff 15 70 e0 02 10` | `CALL dword ptr [0x1002e070]` |
| `1001d46b` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001d46e` | `75 34` | `JNZ 0x1001d4a4` |
| `1001d470` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001d476` | `50` | `PUSH EAX` |
| `1001d477` | `e8 b3 7c ff ff` | `CALL 0x1001512f` |
| `1001d47c` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001d47e` | `8b c8` | `MOV ECX,EAX` |
| `1001d480` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001d483` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001d486` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001d48d` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001d490` | `8d 44 01 04` | `LEA EAX,[ECX + EAX*0x1 + 0x4]` |
| `1001d494` | `80 20 fe` | `AND byte ptr [EAX],0xfe` |
| `1001d497` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001d499` | `e8 92 06 00 00` | `CALL 0x1001db30` |
| `1001d49e` | `59` | `POP ECX` |
| `1001d49f` | `e9 98 fb ff ff` | `JMP 0x1001d03c` |
| `1001d4a4` | `8b 36` | `MOV ESI,dword ptr [ESI]` |
| `1001d4a6` | `8b ce` | `MOV ECX,ESI` |
| `1001d4a8` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001d4ab` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001d4b2` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001d4b5` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001d4b8` | `89 04 0e` | `MOV dword ptr [ESI + ECX*0x1],EAX` |
| `1001d4bb` | `8b c3` | `MOV EAX,EBX` |
| `1001d4bd` | `5f` | `POP EDI` |
| `1001d4be` | `5e` | `POP ESI` |
| `1001d4bf` | `5b` | `POP EBX` |
| `1001d4c0` | `c9` | `LEAVE` |
| `1001d4c1` | `c3` | `RET` |
