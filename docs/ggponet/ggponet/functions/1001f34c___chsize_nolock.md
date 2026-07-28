# 1001f34c `__chsize_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f34c |
| `name` | __chsize_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __chsize_nolock(int _FileHandle, longlong _Size) |
| `size_bytes` | 438 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __chsize_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __chsize_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __chsize_nolock(int _FileHandle,longlong _Size)

{
  int iVar1;
  HANDLE pvVar2;
  LPVOID _Buf;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ulong *puVar6;
  BOOL BVar7;
  uint uVar8;
  int unaff_EDI;
  int iVar9;
  bool bVar10;
  bool bVar11;
  ulonglong uVar12;
  longlong lVar13;
  uint in_stack_00000008;
  DWORD DVar14;
  SIZE_T dwBytes;
  uint local_14;
  uint local_10;
  
  local_14 = 0;
  local_10 = 0;
  uVar12 = __lseeki64_nolock(_FileHandle,0x100000000,unaff_EDI);
  if (uVar12 == 0xffffffffffffffff) goto LAB_1001f3d4;
  lVar13 = __lseeki64_nolock(_FileHandle,0x200000000,unaff_EDI);
  iVar4 = (int)((ulonglong)lVar13 >> 0x20);
  if (lVar13 == -1) goto LAB_1001f3d4;
  uVar8 = in_stack_00000008 - (uint)lVar13;
  uVar5 = (uint)(in_stack_00000008 < (uint)lVar13);
  iVar1 = (int)_Size - iVar4;
  iVar9 = iVar1 - uVar5;
  if ((iVar9 < 0) ||
     ((iVar9 == 0 || SBORROW4((int)_Size,iVar4) != SBORROW4(iVar1,uVar5) && (uVar8 == 0)))) {
    if ((iVar9 < 1) && (iVar9 < 0)) {
      lVar13 = __lseeki64_nolock(_FileHandle,_Size & 0xffffffff,unaff_EDI);
      if (lVar13 == -1) goto LAB_1001f3d4;
      pvVar2 = (HANDLE)__get_osfhandle(_FileHandle);
      BVar7 = SetEndOfFile(pvVar2);
      local_14 = (BVar7 != 0) - 1;
      local_10 = (int)local_14 >> 0x1f;
      if ((local_14 & local_10) == 0xffffffff) {
        piVar3 = __errno();
        *piVar3 = 0xd;
        puVar6 = ___doserrno();
        DVar14 = GetLastError();
        *puVar6 = DVar14;
        goto LAB_1001f4d2;
      }
    }
  }
  else {
    dwBytes = 0x1000;
    DVar14 = 8;
    pvVar2 = GetProcessHeap();
    _Buf = HeapAlloc(pvVar2,DVar14,dwBytes);
    if (_Buf == (LPVOID)0x0) {
      piVar3 = __errno();
      *piVar3 = 0xc;
      goto LAB_1001f3d4;
    }
    iVar4 = __setmode_nolock(_FileHandle,0x8000);
    while( true ) {
      uVar5 = uVar8;
      if ((-1 < iVar9) && ((0 < iVar9 || (0xfff < uVar8)))) {
        uVar5 = 0x1000;
      }
      uVar5 = __write_nolock(_FileHandle,_Buf,uVar5);
      if (uVar5 == 0xffffffff) break;
      bVar10 = uVar8 < uVar5;
      uVar8 = uVar8 - uVar5;
      bVar11 = SBORROW4(iVar9,(int)uVar5 >> 0x1f);
      iVar1 = iVar9 - ((int)uVar5 >> 0x1f);
      iVar9 = iVar1 - (uint)bVar10;
      if ((iVar9 < 0) || ((iVar9 == 0 || bVar11 != SBORROW4(iVar1,(uint)bVar10) && (uVar8 == 0))))
      goto LAB_1001f426;
    }
    puVar6 = ___doserrno();
    if (*puVar6 == 5) {
      piVar3 = __errno();
      *piVar3 = 0xd;
    }
    local_14 = 0xffffffff;
    local_10 = 0xffffffff;
LAB_1001f426:
    __setmode_nolock(_FileHandle,iVar4);
    DVar14 = 0;
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,DVar14,_Buf);
LAB_1001f4d2:
    if ((local_14 & local_10) == 0xffffffff) goto LAB_1001f3d4;
  }
  lVar13 = __lseeki64_nolock(_FileHandle,uVar12 >> 0x20,unaff_EDI);
  if (lVar13 != -1) {
    return 0;
  }
LAB_1001f3d4:
  piVar3 = __errno();
  return *piVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f366` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001f382` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001f3b5` | `EXTERNAL:00000013` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcessHeap | `` |
| `1001f3bc` | `EXTERNAL:00000030` | `COMPUTED_CALL` | KERNEL32.DLL::HeapAlloc | `` |
| `1001f3c9` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f3d4` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f3e8` | `1001f577` | `UNCONDITIONAL_CALL` | __setmode_nolock | `1001f577` |
| `1001f409` | `10019bdf` | `UNCONDITIONAL_CALL` | __write_nolock | `10019bdf` |
| `1001f42c` | `1001f577` | `UNCONDITIONAL_CALL` | __setmode_nolock | `1001f577` |
| `1001f438` | `EXTERNAL:00000013` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcessHeap | `` |
| `1001f43f` | `EXTERNAL:0000002f` | `COMPUTED_CALL` | KERNEL32.DLL::HeapFree | `` |
| `1001f44c` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001f456` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f47d` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `1001f493` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `1001f49a` | `EXTERNAL:00000014` | `COMPUTED_CALL` | KERNEL32.DLL::SetEndOfFile | `` |
| `1001f4b5` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f4c0` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001f4c7` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001f4e8` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |

## Callers

| From | Function |
| --- | --- |
| `1001d167` | __tsopen_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f3b5` | `1002e004` | `READ` | PTR_GetProcessHeap_1002e004 |
| `1001f3bc` | `1002e078` | `READ` | PTR_HeapAlloc_1002e078 |
| `1001f438` | `1002e004` | `READ` | PTR_GetProcessHeap_1002e004 |
| `1001f43f` | `1002e074` | `READ` | PTR_HeapFree_1002e074 |
| `1001f49a` | `1002e008` | `READ` | PTR_SetEndOfFile_1002e008 |
| `1001f4c7` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f34c` | `8b ff` | `MOV EDI,EDI` |
| `1001f34e` | `55` | `PUSH EBP` |
| `1001f34f` | `8b ec` | `MOV EBP,ESP` |
| `1001f351` | `83 ec 18` | `SUB ESP,0x18` |
| `1001f354` | `53` | `PUSH EBX` |
| `1001f355` | `56` | `PUSH ESI` |
| `1001f356` | `57` | `PUSH EDI` |
| `1001f357` | `33 db` | `XOR EBX,EBX` |
| `1001f359` | `6a 01` | `PUSH 0x1` |
| `1001f35b` | `53` | `PUSH EBX` |
| `1001f35c` | `53` | `PUSH EBX` |
| `1001f35d` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f360` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `1001f363` | `89 5d f4` | `MOV dword ptr [EBP + -0xc],EBX` |
| `1001f366` | `e8 c1 c5 ff ff` | `CALL 0x1001b92c` |
| `1001f36b` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1001f36e` | `23 c2` | `AND EAX,EDX` |
| `1001f370` | `83 c4 10` | `ADD ESP,0x10` |
| `1001f373` | `89 55 ec` | `MOV dword ptr [EBP + -0x14],EDX` |
| `1001f376` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001f379` | `74 59` | `JZ 0x1001f3d4` |
| `1001f37b` | `6a 02` | `PUSH 0x2` |
| `1001f37d` | `53` | `PUSH EBX` |
| `1001f37e` | `53` | `PUSH EBX` |
| `1001f37f` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f382` | `e8 a5 c5 ff ff` | `CALL 0x1001b92c` |
| `1001f387` | `8b c8` | `MOV ECX,EAX` |
| `1001f389` | `23 ca` | `AND ECX,EDX` |
| `1001f38b` | `83 c4 10` | `ADD ESP,0x10` |
| `1001f38e` | `83 f9 ff` | `CMP ECX,-0x1` |
| `1001f391` | `74 41` | `JZ 0x1001f3d4` |
| `1001f393` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001f396` | `8b 7d 10` | `MOV EDI,dword ptr [EBP + 0x10]` |
| `1001f399` | `2b f0` | `SUB ESI,EAX` |
| `1001f39b` | `1b fa` | `SBB EDI,EDX` |
| `1001f39d` | `0f 88 c6 00 00 00` | `JS 0x1001f469` |
| `1001f3a3` | `7f 08` | `JG 0x1001f3ad` |
| `1001f3a5` | `3b f3` | `CMP ESI,EBX` |
| `1001f3a7` | `0f 86 bc 00 00 00` | `JBE 0x1001f469` |
| `1001f3ad` | `bb 00 10 00 00` | `MOV EBX,0x1000` |
| `1001f3b2` | `53` | `PUSH EBX` |
| `1001f3b3` | `6a 08` | `PUSH 0x8` |
| `1001f3b5` | `ff 15 04 e0 02 10` | `CALL dword ptr [0x1002e004]` |
| `1001f3bb` | `50` | `PUSH EAX` |
| `1001f3bc` | `ff 15 78 e0 02 10` | `CALL dword ptr [0x1002e078]` |
| `1001f3c2` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001f3c5` | `85 c0` | `TEST EAX,EAX` |
| `1001f3c7` | `75 17` | `JNZ 0x1001f3e0` |
| `1001f3c9` | `e8 3b 5d ff ff` | `CALL 0x10015109` |
| `1001f3ce` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `1001f3d4` | `e8 30 5d ff ff` | `CALL 0x10015109` |
| `1001f3d9` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001f3db` | `5f` | `POP EDI` |
| `1001f3dc` | `5e` | `POP ESI` |
| `1001f3dd` | `5b` | `POP EBX` |
| `1001f3de` | `c9` | `LEAVE` |
| `1001f3df` | `c3` | `RET` |
| `1001f3e0` | `68 00 80 00 00` | `PUSH 0x8000` |
| `1001f3e5` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f3e8` | `e8 8a 01 00 00` | `CALL 0x1001f577` |
| `1001f3ed` | `59` | `POP ECX` |
| `1001f3ee` | `59` | `POP ECX` |
| `1001f3ef` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001f3f2` | `85 ff` | `TEST EDI,EDI` |
| `1001f3f4` | `7c 0a` | `JL 0x1001f400` |
| `1001f3f6` | `7f 04` | `JG 0x1001f3fc` |
| `1001f3f8` | `3b f3` | `CMP ESI,EBX` |
| `1001f3fa` | `72 04` | `JC 0x1001f400` |
| `1001f3fc` | `8b c3` | `MOV EAX,EBX` |
| `1001f3fe` | `eb 02` | `JMP 0x1001f402` |
| `1001f400` | `8b c6` | `MOV EAX,ESI` |
| `1001f402` | `50` | `PUSH EAX` |
| `1001f403` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001f406` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f409` | `e8 d1 a7 ff ff` | `CALL 0x10019bdf` |
| `1001f40e` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001f411` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001f414` | `74 36` | `JZ 0x1001f44c` |
| `1001f416` | `99` | `CDQ` |
| `1001f417` | `2b f0` | `SUB ESI,EAX` |
| `1001f419` | `1b fa` | `SBB EDI,EDX` |
| `1001f41b` | `78 06` | `JS 0x1001f423` |
| `1001f41d` | `7f d3` | `JG 0x1001f3f2` |
| `1001f41f` | `85 f6` | `TEST ESI,ESI` |
| `1001f421` | `77 cf` | `JA 0x1001f3f2` |
| `1001f423` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1001f426` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001f429` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f42c` | `e8 46 01 00 00` | `CALL 0x1001f577` |
| `1001f431` | `59` | `POP ECX` |
| `1001f432` | `59` | `POP ECX` |
| `1001f433` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001f436` | `6a 00` | `PUSH 0x0` |
| `1001f438` | `ff 15 04 e0 02 10` | `CALL dword ptr [0x1002e004]` |
| `1001f43e` | `50` | `PUSH EAX` |
| `1001f43f` | `ff 15 74 e0 02 10` | `CALL dword ptr [0x1002e074]` |
| `1001f445` | `33 db` | `XOR EBX,EBX` |
| `1001f447` | `e9 86 00 00 00` | `JMP 0x1001f4d2` |
| `1001f44c` | `e8 cb 5c ff ff` | `CALL 0x1001511c` |
| `1001f451` | `83 38 05` | `CMP dword ptr [EAX],0x5` |
| `1001f454` | `75 0b` | `JNZ 0x1001f461` |
| `1001f456` | `e8 ae 5c ff ff` | `CALL 0x10015109` |
| `1001f45b` | `c7 00 0d 00 00 00` | `MOV dword ptr [EAX],0xd` |
| `1001f461` | `83 ce ff` | `OR ESI,0xffffffff` |
| `1001f464` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1001f467` | `eb bd` | `JMP 0x1001f426` |
| `1001f469` | `3b fb` | `CMP EDI,EBX` |
| `1001f46b` | `7f 71` | `JG 0x1001f4de` |
| `1001f46d` | `7c 04` | `JL 0x1001f473` |
| `1001f46f` | `3b f3` | `CMP ESI,EBX` |
| `1001f471` | `73 6b` | `JNC 0x1001f4de` |
| `1001f473` | `53` | `PUSH EBX` |
| `1001f474` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001f477` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f47a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f47d` | `e8 aa c4 ff ff` | `CALL 0x1001b92c` |
| `1001f482` | `23 c2` | `AND EAX,EDX` |
| `1001f484` | `83 c4 10` | `ADD ESP,0x10` |
| `1001f487` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001f48a` | `0f 84 44 ff ff ff` | `JZ 0x1001f3d4` |
| `1001f490` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f493` | `e8 1e e7 ff ff` | `CALL 0x1001dbb6` |
| `1001f498` | `59` | `POP ECX` |
| `1001f499` | `50` | `PUSH EAX` |
| `1001f49a` | `ff 15 08 e0 02 10` | `CALL dword ptr [0x1002e008]` |
| `1001f4a0` | `f7 d8` | `NEG EAX` |
| `1001f4a2` | `1b c0` | `SBB EAX,EAX` |
| `1001f4a4` | `f7 d8` | `NEG EAX` |
| `1001f4a6` | `48` | `DEC EAX` |
| `1001f4a7` | `99` | `CDQ` |
| `1001f4a8` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `1001f4ab` | `23 c2` | `AND EAX,EDX` |
| `1001f4ad` | `89 55 f4` | `MOV dword ptr [EBP + -0xc],EDX` |
| `1001f4b0` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001f4b3` | `75 29` | `JNZ 0x1001f4de` |
| `1001f4b5` | `e8 4f 5c ff ff` | `CALL 0x10015109` |
| `1001f4ba` | `c7 00 0d 00 00 00` | `MOV dword ptr [EAX],0xd` |
| `1001f4c0` | `e8 57 5c ff ff` | `CALL 0x1001511c` |
| `1001f4c5` | `8b f0` | `MOV ESI,EAX` |
| `1001f4c7` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001f4cd` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001f4cf` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1001f4d2` | `23 75 f4` | `AND ESI,dword ptr [EBP + -0xc]` |
| `1001f4d5` | `83 fe ff` | `CMP ESI,-0x1` |
| `1001f4d8` | `0f 84 f6 fe ff ff` | `JZ 0x1001f3d4` |
| `1001f4de` | `53` | `PUSH EBX` |
| `1001f4df` | `ff 75 ec` | `PUSH dword ptr [EBP + -0x14]` |
| `1001f4e2` | `ff 75 e8` | `PUSH dword ptr [EBP + -0x18]` |
| `1001f4e5` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f4e8` | `e8 3f c4 ff ff` | `CALL 0x1001b92c` |
| `1001f4ed` | `23 c2` | `AND EAX,EDX` |
| `1001f4ef` | `83 c4 10` | `ADD ESP,0x10` |
| `1001f4f2` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001f4f5` | `0f 84 d9 fe ff ff` | `JZ 0x1001f3d4` |
| `1001f4fb` | `33 c0` | `XOR EAX,EAX` |
| `1001f4fd` | `e9 d9 fe ff ff` | `JMP 0x1001f3db` |
