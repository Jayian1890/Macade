# 10018586 `__read_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018586 |
| `name` | __read_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __read_nolock(int _FileHandle, void * _DstBuf, uint _MaxCharCount) |
| `size_bytes` | 1474 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __read_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __read_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __read_nolock(int _FileHandle,void *_DstBuf,uint _MaxCharCount)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  ulong *puVar4;
  int *piVar5;
  uint uVar6;
  byte *pbVar7;
  BOOL BVar8;
  DWORD DVar9;
  ulong uVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  int unaff_EDI;
  bool bVar14;
  longlong lVar15;
  undefined2 uVar16;
  uint local_1c;
  int local_18;
  byte *local_14;
  byte *local_10;
  undefined2 local_c;
  char local_6;
  char local_5;
  
  uVar1 = _MaxCharCount;
  local_18 = -2;
  if (_FileHandle == -2) {
    puVar4 = ___doserrno();
    *puVar4 = 0;
    piVar5 = __errno();
    *piVar5 = 9;
    return -1;
  }
  if ((_FileHandle < 0) || (DAT_13439530 <= (uint)_FileHandle)) {
    puVar4 = ___doserrno();
    *puVar4 = 0;
    piVar5 = __errno();
    *piVar5 = 9;
    __invalid_parameter(0,0,0,0,0);
    return -1;
  }
  piVar5 = &DAT_13439540 + (_FileHandle >> 5);
  iVar13 = (_FileHandle & 0x1fU) * 0x40;
  bVar2 = *(byte *)(*piVar5 + iVar13 + 4);
  if ((bVar2 & 1) == 0) {
    puVar4 = ___doserrno();
    *puVar4 = 0;
    piVar5 = __errno();
    *piVar5 = 9;
    goto LAB_10018690;
  }
  if (_MaxCharCount < 0x80000000) {
    local_14 = (byte *)0x0;
    if ((_MaxCharCount == 0) || ((bVar2 & 2) != 0)) {
      return 0;
    }
    if (_DstBuf != (void *)0x0) {
      local_6 = (char)(*(char *)(*piVar5 + iVar13 + 0x24) * '\x02') >> 1;
      if (local_6 == '\x01') {
        if ((~_MaxCharCount & 1) == 0) goto LAB_1001867e;
        uVar6 = _MaxCharCount >> 1;
        _MaxCharCount = 4;
        if (3 < uVar6) {
          _MaxCharCount = uVar6;
        }
        local_10 = __malloc_crt(_MaxCharCount);
        if (local_10 == (byte *)0x0) {
          piVar5 = __errno();
          *piVar5 = 0xc;
          puVar4 = ___doserrno();
          *puVar4 = 8;
          return -1;
        }
        lVar15 = __lseeki64_nolock(_FileHandle,0x100000000,unaff_EDI);
        iVar12 = *piVar5;
        *(int *)(iVar13 + 0x28 + iVar12) = (int)lVar15;
        *(int *)(iVar13 + 0x2c + iVar12) = (int)((ulonglong)lVar15 >> 0x20);
      }
      else {
        if (local_6 == '\x02') {
          if ((~_MaxCharCount & 1) == 0) goto LAB_1001867e;
          _MaxCharCount = _MaxCharCount & 0xfffffffe;
        }
        local_10 = _DstBuf;
      }
      pbVar7 = local_10;
      uVar6 = _MaxCharCount;
      if ((((*(byte *)(*piVar5 + iVar13 + 4) & 0x48) != 0) &&
          (bVar2 = *(byte *)(*piVar5 + iVar13 + 5), bVar2 != 10)) && (_MaxCharCount != 0)) {
        *local_10 = bVar2;
        pbVar7 = local_10 + 1;
        uVar6 = _MaxCharCount - 1;
        local_14 = (byte *)0x1;
        *(undefined1 *)(iVar13 + 5 + *piVar5) = 10;
        if (((local_6 != '\0') && (bVar2 = *(byte *)(iVar13 + 0x25 + *piVar5), bVar2 != 10)) &&
           (uVar6 != 0)) {
          *pbVar7 = bVar2;
          pbVar7 = local_10 + 2;
          uVar6 = _MaxCharCount - 2;
          local_14 = (byte *)0x2;
          *(undefined1 *)(iVar13 + 0x25 + *piVar5) = 10;
          if (((local_6 == '\x01') && (bVar2 = *(byte *)(iVar13 + 0x26 + *piVar5), bVar2 != 10)) &&
             (uVar6 != 0)) {
            *pbVar7 = bVar2;
            pbVar7 = local_10 + 3;
            local_14 = (byte *)0x3;
            *(undefined1 *)(iVar13 + 0x26 + *piVar5) = 10;
            uVar6 = _MaxCharCount - 3;
          }
        }
      }
      _MaxCharCount = uVar6;
      BVar8 = ReadFile(*(HANDLE *)(iVar13 + *piVar5),pbVar7,_MaxCharCount,&local_1c,
                       (LPOVERLAPPED)0x0);
      if (((BVar8 == 0) || ((int)local_1c < 0)) || (_MaxCharCount < local_1c)) {
        uVar10 = GetLastError();
        if (uVar10 != 5) {
          if (uVar10 == 0x6d) {
            local_18 = 0;
            goto LAB_1001899d;
          }
          goto LAB_10018992;
        }
        piVar5 = __errno();
        *piVar5 = 9;
        puVar4 = ___doserrno();
        *puVar4 = 5;
      }
      else {
        local_14 = (byte *)((int)local_14 + local_1c);
        pbVar7 = (byte *)(iVar13 + 4 + *piVar5);
        if ((*pbVar7 & 0x80) == 0) goto LAB_1001899d;
        if (local_6 == '\x02') {
          if ((local_1c == 0) || (*(short *)local_10 != 10)) {
            *pbVar7 = *pbVar7 & 0xfb;
          }
          else {
            *pbVar7 = *pbVar7 | 4;
          }
          local_14 = local_10 + (int)local_14;
          _MaxCharCount = (uint)local_10;
          pbVar7 = local_10;
          if (local_10 < local_14) {
            do {
              sVar3 = *(short *)_MaxCharCount;
              if (sVar3 == 0x1a) {
                pbVar11 = (byte *)(iVar13 + 4 + *piVar5);
                if ((*pbVar11 & 0x40) == 0) {
                  *pbVar11 = *pbVar11 | 2;
                }
                else {
                  *(undefined2 *)pbVar7 = *(undefined2 *)_MaxCharCount;
                  pbVar7 = pbVar7 + 2;
                }
                break;
              }
              if (sVar3 == 0xd) {
                if (_MaxCharCount < local_14 + -2) {
                  if (*(short *)(_MaxCharCount + 2) == 10) {
                    uVar1 = _MaxCharCount + 4;
                    goto LAB_10018a40;
                  }
LAB_10018ad3:
                  _MaxCharCount = _MaxCharCount + 2;
                  uVar16 = 0xd;
LAB_10018ad5:
                  *(undefined2 *)pbVar7 = uVar16;
                }
                else {
                  uVar1 = _MaxCharCount + 2;
                  BVar8 = ReadFile(*(HANDLE *)(iVar13 + *piVar5),&local_c,2,&local_1c,
                                   (LPOVERLAPPED)0x0);
                  if (((BVar8 == 0) && (DVar9 = GetLastError(), DVar9 != 0)) || (local_1c == 0))
                  goto LAB_10018ad3;
                  if ((*(byte *)(iVar13 + 4 + *piVar5) & 0x48) == 0) {
                    if ((pbVar7 == local_10) && (local_c == 10)) goto LAB_10018a40;
                    __lseeki64_nolock(_FileHandle,0x1ffffffff,unaff_EDI);
                    if (local_c == 10) goto LAB_10018adb;
                    goto LAB_10018ad3;
                  }
                  if (local_c == 10) {
LAB_10018a40:
                    _MaxCharCount = uVar1;
                    uVar16 = 10;
                    goto LAB_10018ad5;
                  }
                  pbVar7[0] = 0xd;
                  pbVar7[1] = 0;
                  *(undefined1 *)(iVar13 + 5 + *piVar5) = (undefined1)local_c;
                  *(undefined1 *)(iVar13 + 0x25 + *piVar5) = local_c._1_1_;
                  *(undefined1 *)(iVar13 + 0x26 + *piVar5) = 10;
                  _MaxCharCount = uVar1;
                }
                pbVar7 = pbVar7 + 2;
                uVar1 = _MaxCharCount;
              }
              else {
                *(short *)pbVar7 = sVar3;
                pbVar7 = pbVar7 + 2;
                uVar1 = _MaxCharCount + 2;
              }
LAB_10018adb:
              _MaxCharCount = uVar1;
            } while (_MaxCharCount < local_14);
          }
          local_14 = (byte *)((int)pbVar7 - (int)local_10);
          goto LAB_1001899d;
        }
        if ((local_1c == 0) || (*local_10 != 10)) {
          *pbVar7 = *pbVar7 & 0xfb;
        }
        else {
          *pbVar7 = *pbVar7 | 4;
        }
        local_14 = local_10 + (int)local_14;
        _MaxCharCount = (uint)local_10;
        pbVar7 = local_10;
        if (local_10 < local_14) {
          do {
            bVar2 = *(byte *)_MaxCharCount;
            if (bVar2 == 0x1a) {
              pbVar11 = (byte *)(iVar13 + 4 + *piVar5);
              if ((*pbVar11 & 0x40) == 0) {
                *pbVar11 = *pbVar11 | 2;
              }
              else {
                *pbVar7 = *(byte *)_MaxCharCount;
                pbVar7 = pbVar7 + 1;
              }
              break;
            }
            if (bVar2 == 0xd) {
              if (_MaxCharCount < local_14 + -1) {
                if (*(char *)(_MaxCharCount + 1) == '\n') {
                  uVar6 = _MaxCharCount + 2;
                  goto LAB_1001881d;
                }
LAB_10018894:
                _MaxCharCount = _MaxCharCount + 1;
                *pbVar7 = 0xd;
              }
              else {
                uVar6 = _MaxCharCount + 1;
                BVar8 = ReadFile(*(HANDLE *)(iVar13 + *piVar5),&local_5,1,&local_1c,
                                 (LPOVERLAPPED)0x0);
                if (((BVar8 == 0) && (DVar9 = GetLastError(), DVar9 != 0)) || (local_1c == 0))
                goto LAB_10018894;
                if ((*(byte *)(iVar13 + 4 + *piVar5) & 0x48) == 0) {
                  if ((pbVar7 == local_10) && (local_5 == '\n')) goto LAB_1001881d;
                  __lseeki64_nolock(_FileHandle,0x1ffffffff,unaff_EDI);
                  if (local_5 == '\n') goto LAB_10018898;
                  goto LAB_10018894;
                }
                if (local_5 == '\n') {
LAB_1001881d:
                  _MaxCharCount = uVar6;
                  *pbVar7 = 10;
                }
                else {
                  *pbVar7 = 0xd;
                  *(char *)(iVar13 + 5 + *piVar5) = local_5;
                  _MaxCharCount = uVar6;
                }
              }
              pbVar7 = pbVar7 + 1;
              uVar6 = _MaxCharCount;
            }
            else {
              *pbVar7 = bVar2;
              pbVar7 = pbVar7 + 1;
              uVar6 = _MaxCharCount + 1;
            }
LAB_10018898:
            _MaxCharCount = uVar6;
          } while (_MaxCharCount < local_14);
        }
        local_14 = (byte *)((int)pbVar7 - (int)local_10);
        if ((local_6 != '\x01') || (local_14 == (byte *)0x0)) goto LAB_1001899d;
        bVar2 = pbVar7[-1];
        if ((char)bVar2 < '\0') {
          iVar12 = 1;
          pbVar7 = pbVar7 + -1;
          while ((((&DAT_10037a80)[bVar2] == '\0' && (iVar12 < 5)) && (local_10 <= pbVar7))) {
            pbVar7 = pbVar7 + -1;
            bVar2 = *pbVar7;
            iVar12 = iVar12 + 1;
          }
          if ((char)(&DAT_10037a80)[*pbVar7] == 0) {
            piVar5 = __errno();
            *piVar5 = 0x2a;
            goto LAB_10018999;
          }
          if ((char)(&DAT_10037a80)[*pbVar7] + 1 == iVar12) {
            pbVar7 = pbVar7 + iVar12;
          }
          else if ((*(byte *)(*piVar5 + iVar13 + 4) & 0x48) == 0) {
            __lseeki64_nolock(_FileHandle,CONCAT44(1,-iVar12 >> 0x1f),unaff_EDI);
          }
          else {
            pbVar11 = pbVar7 + 1;
            *(byte *)(*piVar5 + iVar13 + 5) = *pbVar7;
            if (1 < iVar12) {
              *(byte *)(iVar13 + 0x25 + *piVar5) = *pbVar11;
              pbVar11 = pbVar7 + 2;
            }
            if (iVar12 == 3) {
              *(byte *)(iVar13 + 0x26 + *piVar5) = *pbVar11;
              pbVar11 = pbVar11 + 1;
            }
            pbVar7 = pbVar11 + -iVar12;
          }
        }
        iVar12 = (int)pbVar7 - (int)local_10;
        local_14 = (byte *)MultiByteToWideChar(0xfde9,0,(LPCSTR)local_10,iVar12,_DstBuf,uVar1 >> 1);
        if (local_14 != (byte *)0x0) {
          bVar14 = local_14 != (byte *)iVar12;
          local_14 = (byte *)((int)local_14 * 2);
          *(uint *)(iVar13 + 0x30 + *piVar5) = (uint)bVar14;
          goto LAB_1001899d;
        }
        uVar10 = GetLastError();
LAB_10018992:
        __dosmaperr(uVar10);
      }
LAB_10018999:
      local_18 = -1;
LAB_1001899d:
      if (local_10 != _DstBuf) {
        _free(local_10);
      }
      if (local_18 == -2) {
        return (int)local_14;
      }
      return local_18;
    }
  }
LAB_1001867e:
  puVar4 = ___doserrno();
  *puVar4 = 0;
  piVar5 = __errno();
  *piVar5 = 0x16;
LAB_10018690:
  __invalid_parameter(0,0,0,0,0);
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100185a2` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `100185aa` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100185cc` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `100185d3` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100185e3` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10018612` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `10018619` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001867e` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `10018685` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10018695` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `100186b0` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `100186bd` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100186c8` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `100186e2` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `10018783` | `EXTERNAL:0000004f` | `COMPUTED_CALL` | KERNEL32.DLL::ReadFile | `` |
| `1001883b` | `EXTERNAL:0000004f` | `COMPUTED_CALL` | KERNEL32.DLL::ReadFile | `` |
| `10018845` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10018886` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `10018912` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10018960` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001897f` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001898c` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10018993` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |
| `100189a6` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10018a64` | `EXTERNAL:0000004f` | `COMPUTED_CALL` | KERNEL32.DLL::ReadFile | `` |
| `10018a6e` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10018ac4` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `10018b0c` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10018b19` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10018b24` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |

## Callers

| From | Function |
| --- | --- |
| `1001d14d` | __tsopen_nolock |
| `1001d2b0` | __tsopen_nolock |
| `10018c03` | __read |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100185c4` | `13439530` | `READ` | DAT_13439530 |
| `100185f9` | `13439540` | `DATA` | DAT_13439540 |
| `10018600` | `13439540` | `DATA` | DAT_13439540 |
| `100186e7` | `13439540` | `DATA` | DAT_13439540 |
| `100186f7` | `13439540` | `DATA` | DAT_13439540 |
| `10018710` | `13439540` | `DATA` | DAT_13439540 |
| `10018727` | `13439540` | `DATA` | DAT_13439540 |
| `10018739` | `13439540` | `DATA` | DAT_13439540 |
| `10018751` | `13439540` | `DATA` | DAT_13439540 |
| `10018763` | `13439540` | `DATA` | DAT_13439540 |
| `1001877e` | `13439540` | `DATA` | DAT_13439540 |
| `10018783` | `1002e0f4` | `READ` | PTR_ReadFile_1002e0f4 |
| `100187a5` | `13439540` | `DATA` | DAT_13439540 |
| `10018836` | `13439540` | `DATA` | DAT_13439540 |
| `1001883b` | `1002e0f4` | `READ` | PTR_ReadFile_1002e0f4 |
| `10018845` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `10018855` | `13439540` | `DATA` | DAT_13439540 |
| `10018867` | `13439540` | `DATA` | DAT_13439540 |
| `100188a6` | `13439540` | `DATA` | DAT_13439540 |
| `100188f9` | `10037a80` | `DATA` | DAT_10037a80 |
| `10018907` | `10037a80` | `DATA` | DAT_10037a80 |
| `10018928` | `13439540` | `DATA` | DAT_13439540 |
| `1001893d` | `13439540` | `DATA` | DAT_13439540 |
| `1001894b` | `13439540` | `DATA` | DAT_13439540 |
| `1001897f` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |
| `1001898c` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `100189c3` | `13439540` | `DATA` | DAT_13439540 |
| `10018a5f` | `13439540` | `DATA` | DAT_13439540 |
| `10018a64` | `1002e0f4` | `READ` | PTR_ReadFile_1002e0f4 |
| `10018a6e` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `10018a7e` | `13439540` | `DATA` | DAT_13439540 |
| `10018a94` | `13439540` | `DATA` | DAT_13439540 |
| `10018a9d` | `13439540` | `DATA` | DAT_13439540 |
| `10018aa6` | `13439540` | `DATA` | DAT_13439540 |
| `10018ae9` | `13439540` | `DATA` | DAT_13439540 |
| `10018b0c` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018586` | `8b ff` | `MOV EDI,EDI` |
| `10018588` | `55` | `PUSH EBP` |
| `10018589` | `8b ec` | `MOV EBP,ESP` |
| `1001858b` | `83 ec 1c` | `SUB ESP,0x1c` |
| `1001858e` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `10018591` | `56` | `PUSH ESI` |
| `10018592` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10018595` | `6a fe` | `PUSH -0x2` |
| `10018597` | `58` | `POP EAX` |
| `10018598` | `89 45 ec` | `MOV dword ptr [EBP + -0x14],EAX` |
| `1001859b` | `89 55 e4` | `MOV dword ptr [EBP + -0x1c],EDX` |
| `1001859e` | `3b f0` | `CMP ESI,EAX` |
| `100185a0` | `75 1b` | `JNZ 0x100185bd` |
| `100185a2` | `e8 75 cb ff ff` | `CALL 0x1001511c` |
| `100185a7` | `83 20 00` | `AND dword ptr [EAX],0x0` |
| `100185aa` | `e8 5a cb ff ff` | `CALL 0x10015109` |
| `100185af` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `100185b5` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100185b8` | `e9 88 05 00 00` | `JMP 0x10018b45` |
| `100185bd` | `53` | `PUSH EBX` |
| `100185be` | `33 db` | `XOR EBX,EBX` |
| `100185c0` | `3b f3` | `CMP ESI,EBX` |
| `100185c2` | `7c 08` | `JL 0x100185cc` |
| `100185c4` | `3b 35 30 95 43 13` | `CMP ESI,dword ptr [0x13439530]` |
| `100185ca` | `72 27` | `JC 0x100185f3` |
| `100185cc` | `e8 4b cb ff ff` | `CALL 0x1001511c` |
| `100185d1` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `100185d3` | `e8 31 cb ff ff` | `CALL 0x10015109` |
| `100185d8` | `53` | `PUSH EBX` |
| `100185d9` | `53` | `PUSH EBX` |
| `100185da` | `53` | `PUSH EBX` |
| `100185db` | `53` | `PUSH EBX` |
| `100185dc` | `53` | `PUSH EBX` |
| `100185dd` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `100185e3` | `e8 c7 90 ff ff` | `CALL 0x100116af` |
| `100185e8` | `83 c4 14` | `ADD ESP,0x14` |
| `100185eb` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100185ee` | `e9 51 05 00 00` | `JMP 0x10018b44` |
| `100185f3` | `8b c6` | `MOV EAX,ESI` |
| `100185f5` | `c1 f8 05` | `SAR EAX,0x5` |
| `100185f8` | `57` | `PUSH EDI` |
| `100185f9` | `8d 3c 85 40 95 43 13` | `LEA EDI,[EAX*0x4 + 0x13439540]` |
| `10018600` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018602` | `83 e6 1f` | `AND ESI,0x1f` |
| `10018605` | `c1 e6 06` | `SHL ESI,0x6` |
| `10018608` | `03 c6` | `ADD EAX,ESI` |
| `1001860a` | `8a 48 04` | `MOV CL,byte ptr [EAX + 0x4]` |
| `1001860d` | `f6 c1 01` | `TEST CL,0x1` |
| `10018610` | `75 14` | `JNZ 0x10018626` |
| `10018612` | `e8 05 cb ff ff` | `CALL 0x1001511c` |
| `10018617` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `10018619` | `e8 eb ca ff ff` | `CALL 0x10015109` |
| `1001861e` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `10018624` | `eb 6a` | `JMP 0x10018690` |
| `10018626` | `81 fa ff ff ff 7f` | `CMP EDX,0x7fffffff` |
| `1001862c` | `77 50` | `JA 0x1001867e` |
| `1001862e` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `10018631` | `3b d3` | `CMP EDX,EBX` |
| `10018633` | `0f 84 08 05 00 00` | `JZ 0x10018b41` |
| `10018639` | `f6 c1 02` | `TEST CL,0x2` |
| `1001863c` | `0f 85 ff 04 00 00` | `JNZ 0x10018b41` |
| `10018642` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `10018645` | `74 37` | `JZ 0x1001867e` |
| `10018647` | `8a 40 24` | `MOV AL,byte ptr [EAX + 0x24]` |
| `1001864a` | `02 c0` | `ADD AL,AL` |
| `1001864c` | `d0 f8` | `SAR AL,0x1` |
| `1001864e` | `88 45 fe` | `MOV byte ptr [EBP + -0x2],AL` |
| `10018651` | `0f be c0` | `MOVSX EAX,AL` |
| `10018654` | `48` | `DEC EAX` |
| `10018655` | `6a 04` | `PUSH 0x4` |
| `10018657` | `59` | `POP ECX` |
| `10018658` | `74 1c` | `JZ 0x10018676` |
| `1001865a` | `48` | `DEC EAX` |
| `1001865b` | `75 0e` | `JNZ 0x1001866b` |
| `1001865d` | `8b c2` | `MOV EAX,EDX` |
| `1001865f` | `f7 d0` | `NOT EAX` |
| `10018661` | `a8 01` | `TEST AL,0x1` |
| `10018663` | `74 19` | `JZ 0x1001867e` |
| `10018665` | `83 e2 fe` | `AND EDX,0xfffffffe` |
| `10018668` | `89 55 10` | `MOV dword ptr [EBP + 0x10],EDX` |
| `1001866b` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1001866e` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10018671` | `e9 81 00 00 00` | `JMP 0x100186f7` |
| `10018676` | `8b c2` | `MOV EAX,EDX` |
| `10018678` | `f7 d0` | `NOT EAX` |
| `1001867a` | `a8 01` | `TEST AL,0x1` |
| `1001867c` | `75 21` | `JNZ 0x1001869f` |
| `1001867e` | `e8 99 ca ff ff` | `CALL 0x1001511c` |
| `10018683` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `10018685` | `e8 7f ca ff ff` | `CALL 0x10015109` |
| `1001868a` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10018690` | `53` | `PUSH EBX` |
| `10018691` | `53` | `PUSH EBX` |
| `10018692` | `53` | `PUSH EBX` |
| `10018693` | `53` | `PUSH EBX` |
| `10018694` | `53` | `PUSH EBX` |
| `10018695` | `e8 15 90 ff ff` | `CALL 0x100116af` |
| `1001869a` | `83 c4 14` | `ADD ESP,0x14` |
| `1001869d` | `eb 34` | `JMP 0x100186d3` |
| `1001869f` | `8b c2` | `MOV EAX,EDX` |
| `100186a1` | `d1 e8` | `SHR EAX,0x1` |
| `100186a3` | `89 4d 10` | `MOV dword ptr [EBP + 0x10],ECX` |
| `100186a6` | `3b c1` | `CMP EAX,ECX` |
| `100186a8` | `72 03` | `JC 0x100186ad` |
| `100186aa` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `100186ad` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `100186b0` | `e8 1a 1e 00 00` | `CALL 0x1001a4cf` |
| `100186b5` | `59` | `POP ECX` |
| `100186b6` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `100186b9` | `3b c3` | `CMP EAX,EBX` |
| `100186bb` | `75 1e` | `JNZ 0x100186db` |
| `100186bd` | `e8 47 ca ff ff` | `CALL 0x10015109` |
| `100186c2` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `100186c8` | `e8 4f ca ff ff` | `CALL 0x1001511c` |
| `100186cd` | `c7 00 08 00 00 00` | `MOV dword ptr [EAX],0x8` |
| `100186d3` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100186d6` | `e9 68 04 00 00` | `JMP 0x10018b43` |
| `100186db` | `6a 01` | `PUSH 0x1` |
| `100186dd` | `53` | `PUSH EBX` |
| `100186de` | `53` | `PUSH EBX` |
| `100186df` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100186e2` | `e8 45 32 00 00` | `CALL 0x1001b92c` |
| `100186e7` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `100186e9` | `89 44 0e 28` | `MOV dword ptr [ESI + ECX*0x1 + 0x28],EAX` |
| `100186ed` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `100186f0` | `83 c4 10` | `ADD ESP,0x10` |
| `100186f3` | `89 54 0e 2c` | `MOV dword ptr [ESI + ECX*0x1 + 0x2c],EDX` |
| `100186f7` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `100186f9` | `03 ce` | `ADD ECX,ESI` |
| `100186fb` | `f6 41 04 48` | `TEST byte ptr [ECX + 0x4],0x48` |
| `100186ff` | `74 74` | `JZ 0x10018775` |
| `10018701` | `8a 49 05` | `MOV CL,byte ptr [ECX + 0x5]` |
| `10018704` | `80 f9 0a` | `CMP CL,0xa` |
| `10018707` | `74 6c` | `JZ 0x10018775` |
| `10018709` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001870c` | `74 67` | `JZ 0x10018775` |
| `1001870e` | `88 08` | `MOV byte ptr [EAX],CL` |
| `10018710` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `10018712` | `40` | `INC EAX` |
| `10018713` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `10018716` | `c7 45 f0 01 00 00 00` | `MOV dword ptr [EBP + -0x10],0x1` |
| `1001871d` | `c6 44 0e 05 0a` | `MOV byte ptr [ESI + ECX*0x1 + 0x5],0xa` |
| `10018722` | `38 5d fe` | `CMP byte ptr [EBP + -0x2],BL` |
| `10018725` | `74 4e` | `JZ 0x10018775` |
| `10018727` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `10018729` | `8a 4c 0e 25` | `MOV CL,byte ptr [ESI + ECX*0x1 + 0x25]` |
| `1001872d` | `80 f9 0a` | `CMP CL,0xa` |
| `10018730` | `74 43` | `JZ 0x10018775` |
| `10018732` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `10018735` | `74 3e` | `JZ 0x10018775` |
| `10018737` | `88 08` | `MOV byte ptr [EAX],CL` |
| `10018739` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `1001873b` | `40` | `INC EAX` |
| `1001873c` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `1001873f` | `80 7d fe 01` | `CMP byte ptr [EBP + -0x2],0x1` |
| `10018743` | `c7 45 f0 02 00 00 00` | `MOV dword ptr [EBP + -0x10],0x2` |
| `1001874a` | `c6 44 0e 25 0a` | `MOV byte ptr [ESI + ECX*0x1 + 0x25],0xa` |
| `1001874f` | `75 24` | `JNZ 0x10018775` |
| `10018751` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `10018753` | `8a 4c 0e 26` | `MOV CL,byte ptr [ESI + ECX*0x1 + 0x26]` |
| `10018757` | `80 f9 0a` | `CMP CL,0xa` |
| `1001875a` | `74 19` | `JZ 0x10018775` |
| `1001875c` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001875f` | `74 14` | `JZ 0x10018775` |
| `10018761` | `88 08` | `MOV byte ptr [EAX],CL` |
| `10018763` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `10018765` | `40` | `INC EAX` |
| `10018766` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `10018769` | `c7 45 f0 03 00 00 00` | `MOV dword ptr [EBP + -0x10],0x3` |
| `10018770` | `c6 44 0e 26 0a` | `MOV byte ptr [ESI + ECX*0x1 + 0x26],0xa` |
| `10018775` | `53` | `PUSH EBX` |
| `10018776` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `10018779` | `51` | `PUSH ECX` |
| `1001877a` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001877d` | `50` | `PUSH EAX` |
| `1001877e` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018780` | `ff 34 06` | `PUSH dword ptr [ESI + EAX*0x1]` |
| `10018783` | `ff 15 f4 e0 02 10` | `CALL dword ptr [0x1002e0f4]` |
| `10018789` | `85 c0` | `TEST EAX,EAX` |
| `1001878b` | `0f 84 7b 03 00 00` | `JZ 0x10018b0c` |
| `10018791` | `8b 4d e8` | `MOV ECX,dword ptr [EBP + -0x18]` |
| `10018794` | `3b cb` | `CMP ECX,EBX` |
| `10018796` | `0f 8c 70 03 00 00` | `JL 0x10018b0c` |
| `1001879c` | `3b 4d 10` | `CMP ECX,dword ptr [EBP + 0x10]` |
| `1001879f` | `0f 87 67 03 00 00` | `JA 0x10018b0c` |
| `100187a5` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `100187a7` | `01 4d f0` | `ADD dword ptr [EBP + -0x10],ECX` |
| `100187aa` | `8d 44 06 04` | `LEA EAX,[ESI + EAX*0x1 + 0x4]` |
| `100187ae` | `f6 00 80` | `TEST byte ptr [EAX],0x80` |
| `100187b1` | `0f 84 e6 01 00 00` | `JZ 0x1001899d` |
| `100187b7` | `80 7d fe 02` | `CMP byte ptr [EBP + -0x2],0x2` |
| `100187bb` | `0f 84 16 02 00 00` | `JZ 0x100189d7` |
| `100187c1` | `3b cb` | `CMP ECX,EBX` |
| `100187c3` | `74 0d` | `JZ 0x100187d2` |
| `100187c5` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `100187c8` | `80 39 0a` | `CMP byte ptr [ECX],0xa` |
| `100187cb` | `75 05` | `JNZ 0x100187d2` |
| `100187cd` | `80 08 04` | `OR byte ptr [EAX],0x4` |
| `100187d0` | `eb 03` | `JMP 0x100187d5` |
| `100187d2` | `80 20 fb` | `AND byte ptr [EAX],0xfb` |
| `100187d5` | `8b 5d f4` | `MOV EBX,dword ptr [EBP + -0xc]` |
| `100187d8` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100187db` | `03 c3` | `ADD EAX,EBX` |
| `100187dd` | `89 5d 10` | `MOV dword ptr [EBP + 0x10],EBX` |
| `100187e0` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `100187e3` | `3b d8` | `CMP EBX,EAX` |
| `100187e5` | `0f 83 d0 00 00 00` | `JNC 0x100188bb` |
| `100187eb` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `100187ee` | `8a 01` | `MOV AL,byte ptr [ECX]` |
| `100187f0` | `3c 1a` | `CMP AL,0x1a` |
| `100187f2` | `0f 84 ae 00 00 00` | `JZ 0x100188a6` |
| `100187f8` | `3c 0d` | `CMP AL,0xd` |
| `100187fa` | `74 0c` | `JZ 0x10018808` |
| `100187fc` | `88 03` | `MOV byte ptr [EBX],AL` |
| `100187fe` | `43` | `INC EBX` |
| `100187ff` | `41` | `INC ECX` |
| `10018800` | `89 4d 10` | `MOV dword ptr [EBP + 0x10],ECX` |
| `10018803` | `e9 90 00 00 00` | `JMP 0x10018898` |
| `10018808` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001880b` | `48` | `DEC EAX` |
| `1001880c` | `3b c8` | `CMP ECX,EAX` |
| `1001880e` | `73 17` | `JNC 0x10018827` |
| `10018810` | `8d 41 01` | `LEA EAX,[ECX + 0x1]` |
| `10018813` | `80 38 0a` | `CMP byte ptr [EAX],0xa` |
| `10018816` | `75 0a` | `JNZ 0x10018822` |
| `10018818` | `41` | `INC ECX` |
| `10018819` | `41` | `INC ECX` |
| `1001881a` | `89 4d 10` | `MOV dword ptr [EBP + 0x10],ECX` |
| `1001881d` | `c6 03 0a` | `MOV byte ptr [EBX],0xa` |
| `10018820` | `eb 75` | `JMP 0x10018897` |
| `10018822` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `10018825` | `eb 6d` | `JMP 0x10018894` |
| `10018827` | `ff 45 10` | `INC dword ptr [EBP + 0x10]` |
| `1001882a` | `6a 00` | `PUSH 0x0` |
| `1001882c` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001882f` | `50` | `PUSH EAX` |
| `10018830` | `6a 01` | `PUSH 0x1` |
| `10018832` | `8d 45 ff` | `LEA EAX,[EBP + -0x1]` |
| `10018835` | `50` | `PUSH EAX` |
| `10018836` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018838` | `ff 34 06` | `PUSH dword ptr [ESI + EAX*0x1]` |
| `1001883b` | `ff 15 f4 e0 02 10` | `CALL dword ptr [0x1002e0f4]` |
| `10018841` | `85 c0` | `TEST EAX,EAX` |
| `10018843` | `75 0a` | `JNZ 0x1001884f` |
| `10018845` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001884b` | `85 c0` | `TEST EAX,EAX` |
| `1001884d` | `75 45` | `JNZ 0x10018894` |
| `1001884f` | `83 7d e8 00` | `CMP dword ptr [EBP + -0x18],0x0` |
| `10018853` | `74 3f` | `JZ 0x10018894` |
| `10018855` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018857` | `f6 44 06 04 48` | `TEST byte ptr [ESI + EAX*0x1 + 0x4],0x48` |
| `1001885c` | `74 14` | `JZ 0x10018872` |
| `1001885e` | `80 7d ff 0a` | `CMP byte ptr [EBP + -0x1],0xa` |
| `10018862` | `74 b9` | `JZ 0x1001881d` |
| `10018864` | `c6 03 0d` | `MOV byte ptr [EBX],0xd` |
| `10018867` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018869` | `8a 4d ff` | `MOV CL,byte ptr [EBP + -0x1]` |
| `1001886c` | `88 4c 06 05` | `MOV byte ptr [ESI + EAX*0x1 + 0x5],CL` |
| `10018870` | `eb 25` | `JMP 0x10018897` |
| `10018872` | `3b 5d f4` | `CMP EBX,dword ptr [EBP + -0xc]` |
| `10018875` | `75 06` | `JNZ 0x1001887d` |
| `10018877` | `80 7d ff 0a` | `CMP byte ptr [EBP + -0x1],0xa` |
| `1001887b` | `74 a0` | `JZ 0x1001881d` |
| `1001887d` | `6a 01` | `PUSH 0x1` |
| `1001887f` | `6a ff` | `PUSH -0x1` |
| `10018881` | `6a ff` | `PUSH -0x1` |
| `10018883` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10018886` | `e8 a1 30 00 00` | `CALL 0x1001b92c` |
| `1001888b` | `83 c4 10` | `ADD ESP,0x10` |
| `1001888e` | `80 7d ff 0a` | `CMP byte ptr [EBP + -0x1],0xa` |
| `10018892` | `74 04` | `JZ 0x10018898` |
| `10018894` | `c6 03 0d` | `MOV byte ptr [EBX],0xd` |
| `10018897` | `43` | `INC EBX` |
| `10018898` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001889b` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `1001889e` | `0f 82 47 ff ff ff` | `JC 0x100187eb` |
| `100188a4` | `eb 15` | `JMP 0x100188bb` |
| `100188a6` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `100188a8` | `8d 44 06 04` | `LEA EAX,[ESI + EAX*0x1 + 0x4]` |
| `100188ac` | `f6 00 40` | `TEST byte ptr [EAX],0x40` |
| `100188af` | `75 05` | `JNZ 0x100188b6` |
| `100188b1` | `80 08 02` | `OR byte ptr [EAX],0x2` |
| `100188b4` | `eb 05` | `JMP 0x100188bb` |
| `100188b6` | `8a 01` | `MOV AL,byte ptr [ECX]` |
| `100188b8` | `88 03` | `MOV byte ptr [EBX],AL` |
| `100188ba` | `43` | `INC EBX` |
| `100188bb` | `8b c3` | `MOV EAX,EBX` |
| `100188bd` | `2b 45 f4` | `SUB EAX,dword ptr [EBP + -0xc]` |
| `100188c0` | `80 7d fe 01` | `CMP byte ptr [EBP + -0x2],0x1` |
| `100188c4` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `100188c7` | `0f 85 d0 00 00 00` | `JNZ 0x1001899d` |
| `100188cd` | `85 c0` | `TEST EAX,EAX` |
| `100188cf` | `0f 84 c8 00 00 00` | `JZ 0x1001899d` |
| `100188d5` | `4b` | `DEC EBX` |
| `100188d6` | `8a 0b` | `MOV CL,byte ptr [EBX]` |
| `100188d8` | `84 c9` | `TEST CL,CL` |
| `100188da` | `78 06` | `JS 0x100188e2` |
| `100188dc` | `43` | `INC EBX` |
| `100188dd` | `e9 86 00 00 00` | `JMP 0x10018968` |
| `100188e2` | `33 c0` | `XOR EAX,EAX` |
| `100188e4` | `40` | `INC EAX` |
| `100188e5` | `0f b6 c9` | `MOVZX ECX,CL` |
| `100188e8` | `eb 0f` | `JMP 0x100188f9` |
| `100188ea` | `83 f8 04` | `CMP EAX,0x4` |
| `100188ed` | `7f 13` | `JG 0x10018902` |
| `100188ef` | `3b 5d f4` | `CMP EBX,dword ptr [EBP + -0xc]` |
| `100188f2` | `72 0e` | `JC 0x10018902` |
| `100188f4` | `4b` | `DEC EBX` |
| `100188f5` | `0f b6 0b` | `MOVZX ECX,byte ptr [EBX]` |
| `100188f8` | `40` | `INC EAX` |
| `100188f9` | `80 b9 80 7a 03 10 00` | `CMP byte ptr [ECX + 0x10037a80],0x0` |
| `10018900` | `74 e8` | `JZ 0x100188ea` |
| `10018902` | `8a 13` | `MOV DL,byte ptr [EBX]` |
| `10018904` | `0f b6 ca` | `MOVZX ECX,DL` |
| `10018907` | `0f be 89 80 7a 03 10` | `MOVSX ECX,byte ptr [ECX + 0x10037a80]` |
| `1001890e` | `85 c9` | `TEST ECX,ECX` |
| `10018910` | `75 0d` | `JNZ 0x1001891f` |
| `10018912` | `e8 f2 c7 ff ff` | `CALL 0x10015109` |
| `10018917` | `c7 00 2a 00 00 00` | `MOV dword ptr [EAX],0x2a` |
| `1001891d` | `eb 7a` | `JMP 0x10018999` |
| `1001891f` | `41` | `INC ECX` |
| `10018920` | `3b c8` | `CMP ECX,EAX` |
| `10018922` | `75 04` | `JNZ 0x10018928` |
| `10018924` | `03 d8` | `ADD EBX,EAX` |
| `10018926` | `eb 40` | `JMP 0x10018968` |
| `10018928` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `1001892a` | `03 ce` | `ADD ECX,ESI` |
| `1001892c` | `f6 41 04 48` | `TEST byte ptr [ECX + 0x4],0x48` |
| `10018930` | `74 24` | `JZ 0x10018956` |
| `10018932` | `43` | `INC EBX` |
| `10018933` | `83 f8 02` | `CMP EAX,0x2` |
| `10018936` | `88 51 05` | `MOV byte ptr [ECX + 0x5],DL` |
| `10018939` | `7c 09` | `JL 0x10018944` |
| `1001893b` | `8a 13` | `MOV DL,byte ptr [EBX]` |
| `1001893d` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `1001893f` | `88 54 0e 25` | `MOV byte ptr [ESI + ECX*0x1 + 0x25],DL` |
| `10018943` | `43` | `INC EBX` |
| `10018944` | `83 f8 03` | `CMP EAX,0x3` |
| `10018947` | `75 09` | `JNZ 0x10018952` |
| `10018949` | `8a 13` | `MOV DL,byte ptr [EBX]` |
| `1001894b` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `1001894d` | `88 54 0e 26` | `MOV byte ptr [ESI + ECX*0x1 + 0x26],DL` |
| `10018951` | `43` | `INC EBX` |
| `10018952` | `2b d8` | `SUB EBX,EAX` |
| `10018954` | `eb 12` | `JMP 0x10018968` |
| `10018956` | `f7 d8` | `NEG EAX` |
| `10018958` | `99` | `CDQ` |
| `10018959` | `6a 01` | `PUSH 0x1` |
| `1001895b` | `52` | `PUSH EDX` |
| `1001895c` | `50` | `PUSH EAX` |
| `1001895d` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10018960` | `e8 c7 2f 00 00` | `CALL 0x1001b92c` |
| `10018965` | `83 c4 10` | `ADD ESP,0x10` |
| `10018968` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001896b` | `2b 5d f4` | `SUB EBX,dword ptr [EBP + -0xc]` |
| `1001896e` | `d1 e8` | `SHR EAX,0x1` |
| `10018970` | `50` | `PUSH EAX` |
| `10018971` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10018974` | `53` | `PUSH EBX` |
| `10018975` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `10018978` | `6a 00` | `PUSH 0x0` |
| `1001897a` | `68 e9 fd 00 00` | `PUSH 0xfde9` |
| `1001897f` | `ff 15 60 e0 02 10` | `CALL dword ptr [0x1002e060]` |
| `10018985` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `10018988` | `85 c0` | `TEST EAX,EAX` |
| `1001898a` | `75 34` | `JNZ 0x100189c0` |
| `1001898c` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10018992` | `50` | `PUSH EAX` |
| `10018993` | `e8 97 c7 ff ff` | `CALL 0x1001512f` |
| `10018998` | `59` | `POP ECX` |
| `10018999` | `83 4d ec ff` | `OR dword ptr [EBP + -0x14],0xffffffff` |
| `1001899d` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `100189a0` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `100189a3` | `74 07` | `JZ 0x100189ac` |
| `100189a5` | `50` | `PUSH EAX` |
| `100189a6` | `e8 96 88 ff ff` | `CALL 0x10011241` |
| `100189ab` | `59` | `POP ECX` |
| `100189ac` | `8b 45 ec` | `MOV EAX,dword ptr [EBP + -0x14]` |
| `100189af` | `83 f8 fe` | `CMP EAX,-0x2` |
| `100189b2` | `0f 85 8b 01 00 00` | `JNZ 0x10018b43` |
| `100189b8` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100189bb` | `e9 83 01 00 00` | `JMP 0x10018b43` |
| `100189c0` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100189c3` | `8b 17` | `MOV EDX,dword ptr [EDI]` |
| `100189c5` | `33 c9` | `XOR ECX,ECX` |
| `100189c7` | `3b c3` | `CMP EAX,EBX` |
| `100189c9` | `0f 95 c1` | `SETNZ CL` |
| `100189cc` | `03 c0` | `ADD EAX,EAX` |
| `100189ce` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `100189d1` | `89 4c 16 30` | `MOV dword ptr [ESI + EDX*0x1 + 0x30],ECX` |
| `100189d5` | `eb c6` | `JMP 0x1001899d` |
| `100189d7` | `3b cb` | `CMP ECX,EBX` |
| `100189d9` | `74 0e` | `JZ 0x100189e9` |
| `100189db` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `100189de` | `66 83 39 0a` | `CMP word ptr [ECX],0xa` |
| `100189e2` | `75 05` | `JNZ 0x100189e9` |
| `100189e4` | `80 08 04` | `OR byte ptr [EAX],0x4` |
| `100189e7` | `eb 03` | `JMP 0x100189ec` |
| `100189e9` | `80 20 fb` | `AND byte ptr [EAX],0xfb` |
| `100189ec` | `8b 5d f4` | `MOV EBX,dword ptr [EBP + -0xc]` |
| `100189ef` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100189f2` | `03 c3` | `ADD EAX,EBX` |
| `100189f4` | `89 5d 10` | `MOV dword ptr [EBP + 0x10],EBX` |
| `100189f7` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `100189fa` | `3b d8` | `CMP EBX,EAX` |
| `100189fc` | `0f 83 ff 00 00 00` | `JNC 0x10018b01` |
| `10018a02` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10018a05` | `0f b7 08` | `MOVZX ECX,word ptr [EAX]` |
| `10018a08` | `66 83 f9 1a` | `CMP CX,0x1a` |
| `10018a0c` | `0f 84 d7 00 00 00` | `JZ 0x10018ae9` |
| `10018a12` | `66 83 f9 0d` | `CMP CX,0xd` |
| `10018a16` | `74 0f` | `JZ 0x10018a27` |
| `10018a18` | `66 89 0b` | `MOV word ptr [EBX],CX` |
| `10018a1b` | `43` | `INC EBX` |
| `10018a1c` | `43` | `INC EBX` |
| `10018a1d` | `40` | `INC EAX` |
| `10018a1e` | `40` | `INC EAX` |
| `10018a1f` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `10018a22` | `e9 b4 00 00 00` | `JMP 0x10018adb` |
| `10018a27` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `10018a2a` | `83 c1 fe` | `ADD ECX,-0x2` |
| `10018a2d` | `3b c1` | `CMP EAX,ECX` |
| `10018a2f` | `73 1e` | `JNC 0x10018a4f` |
| `10018a31` | `8d 48 02` | `LEA ECX,[EAX + 0x2]` |
| `10018a34` | `66 83 39 0a` | `CMP word ptr [ECX],0xa` |
| `10018a38` | `75 0d` | `JNZ 0x10018a47` |
| `10018a3a` | `83 c0 04` | `ADD EAX,0x4` |
| `10018a3d` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `10018a40` | `6a 0a` | `PUSH 0xa` |
| `10018a42` | `e9 8e 00 00 00` | `JMP 0x10018ad5` |
| `10018a47` | `89 4d 10` | `MOV dword ptr [EBP + 0x10],ECX` |
| `10018a4a` | `e9 84 00 00 00` | `JMP 0x10018ad3` |
| `10018a4f` | `83 45 10 02` | `ADD dword ptr [EBP + 0x10],0x2` |
| `10018a53` | `6a 00` | `PUSH 0x0` |
| `10018a55` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `10018a58` | `50` | `PUSH EAX` |
| `10018a59` | `6a 02` | `PUSH 0x2` |
| `10018a5b` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `10018a5e` | `50` | `PUSH EAX` |
| `10018a5f` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018a61` | `ff 34 06` | `PUSH dword ptr [ESI + EAX*0x1]` |
| `10018a64` | `ff 15 f4 e0 02 10` | `CALL dword ptr [0x1002e0f4]` |
| `10018a6a` | `85 c0` | `TEST EAX,EAX` |
| `10018a6c` | `75 0a` | `JNZ 0x10018a78` |
| `10018a6e` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10018a74` | `85 c0` | `TEST EAX,EAX` |
| `10018a76` | `75 5b` | `JNZ 0x10018ad3` |
| `10018a78` | `83 7d e8 00` | `CMP dword ptr [EBP + -0x18],0x0` |
| `10018a7c` | `74 55` | `JZ 0x10018ad3` |
| `10018a7e` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018a80` | `f6 44 06 04 48` | `TEST byte ptr [ESI + EAX*0x1 + 0x4],0x48` |
| `10018a85` | `74 28` | `JZ 0x10018aaf` |
| `10018a87` | `66 83 7d f8 0a` | `CMP word ptr [EBP + -0x8],0xa` |
| `10018a8c` | `74 b2` | `JZ 0x10018a40` |
| `10018a8e` | `6a 0d` | `PUSH 0xd` |
| `10018a90` | `58` | `POP EAX` |
| `10018a91` | `66 89 03` | `MOV word ptr [EBX],AX` |
| `10018a94` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018a96` | `8a 4d f8` | `MOV CL,byte ptr [EBP + -0x8]` |
| `10018a99` | `88 4c 06 05` | `MOV byte ptr [ESI + EAX*0x1 + 0x5],CL` |
| `10018a9d` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018a9f` | `8a 4d f9` | `MOV CL,byte ptr [EBP + -0x7]` |
| `10018aa2` | `88 4c 06 25` | `MOV byte ptr [ESI + EAX*0x1 + 0x25],CL` |
| `10018aa6` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10018aa8` | `c6 44 06 26 0a` | `MOV byte ptr [ESI + EAX*0x1 + 0x26],0xa` |
| `10018aad` | `eb 2a` | `JMP 0x10018ad9` |
| `10018aaf` | `3b 5d f4` | `CMP EBX,dword ptr [EBP + -0xc]` |
| `10018ab2` | `75 07` | `JNZ 0x10018abb` |
| `10018ab4` | `66 83 7d f8 0a` | `CMP word ptr [EBP + -0x8],0xa` |
| `10018ab9` | `74 85` | `JZ 0x10018a40` |
| `10018abb` | `6a 01` | `PUSH 0x1` |
| `10018abd` | `6a ff` | `PUSH -0x1` |
| `10018abf` | `6a fe` | `PUSH -0x2` |
| `10018ac1` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10018ac4` | `e8 63 2e 00 00` | `CALL 0x1001b92c` |
| `10018ac9` | `83 c4 10` | `ADD ESP,0x10` |
| `10018acc` | `66 83 7d f8 0a` | `CMP word ptr [EBP + -0x8],0xa` |
| `10018ad1` | `74 08` | `JZ 0x10018adb` |
| `10018ad3` | `6a 0d` | `PUSH 0xd` |
| `10018ad5` | `58` | `POP EAX` |
| `10018ad6` | `66 89 03` | `MOV word ptr [EBX],AX` |
| `10018ad9` | `43` | `INC EBX` |
| `10018ada` | `43` | `INC EBX` |
| `10018adb` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `10018ade` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `10018ae1` | `0f 82 1b ff ff ff` | `JC 0x10018a02` |
| `10018ae7` | `eb 18` | `JMP 0x10018b01` |
| `10018ae9` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `10018aeb` | `8d 74 0e 04` | `LEA ESI,[ESI + ECX*0x1 + 0x4]` |
| `10018aef` | `f6 06 40` | `TEST byte ptr [ESI],0x40` |
| `10018af2` | `75 05` | `JNZ 0x10018af9` |
| `10018af4` | `80 0e 02` | `OR byte ptr [ESI],0x2` |
| `10018af7` | `eb 08` | `JMP 0x10018b01` |
| `10018af9` | `66 8b 00` | `MOV AX,word ptr [EAX]` |
| `10018afc` | `66 89 03` | `MOV word ptr [EBX],AX` |
| `10018aff` | `43` | `INC EBX` |
| `10018b00` | `43` | `INC EBX` |
| `10018b01` | `2b 5d f4` | `SUB EBX,dword ptr [EBP + -0xc]` |
| `10018b04` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `10018b07` | `e9 91 fe ff ff` | `JMP 0x1001899d` |
| `10018b0c` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10018b12` | `6a 05` | `PUSH 0x5` |
| `10018b14` | `5e` | `POP ESI` |
| `10018b15` | `3b c6` | `CMP EAX,ESI` |
| `10018b17` | `75 17` | `JNZ 0x10018b30` |
| `10018b19` | `e8 eb c5 ff ff` | `CALL 0x10015109` |
| `10018b1e` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `10018b24` | `e8 f3 c5 ff ff` | `CALL 0x1001511c` |
| `10018b29` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10018b2b` | `e9 69 fe ff ff` | `JMP 0x10018999` |
| `10018b30` | `83 f8 6d` | `CMP EAX,0x6d` |
| `10018b33` | `0f 85 59 fe ff ff` | `JNZ 0x10018992` |
| `10018b39` | `89 5d ec` | `MOV dword ptr [EBP + -0x14],EBX` |
| `10018b3c` | `e9 5c fe ff ff` | `JMP 0x1001899d` |
| `10018b41` | `33 c0` | `XOR EAX,EAX` |
| `10018b43` | `5f` | `POP EDI` |
| `10018b44` | `5b` | `POP EBX` |
| `10018b45` | `5e` | `POP ESI` |
| `10018b46` | `c9` | `LEAVE` |
| `10018b47` | `c3` | `RET` |
