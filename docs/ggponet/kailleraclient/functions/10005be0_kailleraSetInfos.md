# 10005be0 `kailleraSetInfos`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005be0 |
| `name` | kailleraSetInfos |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraSetInfos(undefined4 * param_1) |
| `size_bytes` | 160 |
| `stack_frame_size` | 8 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_7, _kailleraSetInfos@4, kailleraSetInfos |

## Decompiled C

```c

/* __stdcall kailleraSetInfos,4 */

void kailleraSetInfos(undefined4 *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
                    /* 0x5be0  7  _kailleraSetInfos@4 */
  if (DAT_1000ef98 != 0) {
    free((void *)DAT_1000ef98);
  }
  DAT_1000ef98 = (int)_strdup((char *)*param_1);
  if (DAT_1000edc0 != (undefined4 *)0x0) {
    free(DAT_1000edc0);
  }
  iVar3 = 0;
  for (pcVar1 = (char *)param_1[1]; (*pcVar1 != '\0' || (pcVar1[1] != '\0')); pcVar1 = pcVar1 + 1) {
    iVar3 = iVar3 + 1;
  }
  uVar4 = iVar3 + 2;
  DAT_1000edc0 = malloc(uVar4);
  puVar5 = (undefined4 *)param_1[1];
  puVar6 = DAT_1000edc0;
  for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  DAT_1000edb8 = param_1[2];
  DAT_1000edb0 = param_1[3];
  DAT_1000edc4 = param_1[4];
  DAT_1000eeec = param_1[5];
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10005bf3` | `EXTERNAL:00000014` | `COMPUTED_CALL` | MSVCRT.DLL::free | `` |
| `10005bff` | `EXTERNAL:00000023` | `COMPUTED_CALL` | MSVCRT.DLL::_strdup | `` |
| `10005c17` | `EXTERNAL:00000014` | `COMPUTED_CALL` | MSVCRT.DLL::free | `` |
| `10005c35` | `EXTERNAL:00000015` | `COMPUTED_CALL` | MSVCRT.DLL::malloc | `` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10005be0` | `1000ef98` | `READ` | DAT_1000ef98 |
| `10005be7` | `1000d058` | `READ` | PTR_free_1000d058 |
| `10005bff` | `1000d094` | `READ` | PTR__strdup_1000d094 |
| `10005c05` | `1000ef98` | `WRITE` | DAT_1000ef98 |
| `10005c0a` | `1000edc0` | `READ` | DAT_1000edc0 |
| `10005c35` | `1000d05c` | `READ` | PTR_malloc_1000d05c |
| `10005c3d` | `1000edc0` | `WRITE` | DAT_1000edc0 |
| `10005c5c` | `1000edb8` | `WRITE` | DAT_1000edb8 |
| `10005c64` | `1000edb0` | `WRITE` | DAT_1000edb0 |
| `10005c6d` | `1000edc4` | `WRITE` | DAT_1000edc4 |
| `10005c77` | `1000eeec` | `WRITE` | DAT_1000eeec |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005be0` | `a1 98 ef 00 10` | `MOV EAX,[0x1000ef98]` |
| `10005be5` | `53` | `PUSH EBX` |
| `10005be6` | `56` | `PUSH ESI` |
| `10005be7` | `8b 35 58 d0 00 10` | `MOV ESI,dword ptr [0x1000d058]` |
| `10005bed` | `85 c0` | `TEST EAX,EAX` |
| `10005bef` | `57` | `PUSH EDI` |
| `10005bf0` | `74 06` | `JZ 0x10005bf8` |
| `10005bf2` | `50` | `PUSH EAX` |
| `10005bf3` | `ff d6` | `CALL ESI` |
| `10005bf5` | `83 c4 04` | `ADD ESP,0x4` |
| `10005bf8` | `8b 5c 24 10` | `MOV EBX,dword ptr [ESP + 0x10]` |
| `10005bfc` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `10005bfe` | `50` | `PUSH EAX` |
| `10005bff` | `ff 15 94 d0 00 10` | `CALL dword ptr [0x1000d094]` |
| `10005c05` | `a3 98 ef 00 10` | `MOV [0x1000ef98],EAX` |
| `10005c0a` | `a1 c0 ed 00 10` | `MOV EAX,[0x1000edc0]` |
| `10005c0f` | `83 c4 04` | `ADD ESP,0x4` |
| `10005c12` | `85 c0` | `TEST EAX,EAX` |
| `10005c14` | `74 06` | `JZ 0x10005c1c` |
| `10005c16` | `50` | `PUSH EAX` |
| `10005c17` | `ff d6` | `CALL ESI` |
| `10005c19` | `83 c4 04` | `ADD ESP,0x4` |
| `10005c1c` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `10005c1f` | `33 f6` | `XOR ESI,ESI` |
| `10005c21` | `80 38 00` | `CMP byte ptr [EAX],0x0` |
| `10005c24` | `75 07` | `JNZ 0x10005c2d` |
| `10005c26` | `8a 48 01` | `MOV CL,byte ptr [EAX + 0x1]` |
| `10005c29` | `84 c9` | `TEST CL,CL` |
| `10005c2b` | `74 04` | `JZ 0x10005c31` |
| `10005c2d` | `40` | `INC EAX` |
| `10005c2e` | `46` | `INC ESI` |
| `10005c2f` | `eb f0` | `JMP 0x10005c21` |
| `10005c31` | `83 c6 02` | `ADD ESI,0x2` |
| `10005c34` | `56` | `PUSH ESI` |
| `10005c35` | `ff 15 5c d0 00 10` | `CALL dword ptr [0x1000d05c]` |
| `10005c3b` | `8b ce` | `MOV ECX,ESI` |
| `10005c3d` | `a3 c0 ed 00 10` | `MOV [0x1000edc0],EAX` |
| `10005c42` | `8b 73 04` | `MOV ESI,dword ptr [EBX + 0x4]` |
| `10005c45` | `8b d1` | `MOV EDX,ECX` |
| `10005c47` | `8b f8` | `MOV EDI,EAX` |
| `10005c49` | `83 c4 04` | `ADD ESP,0x4` |
| `10005c4c` | `c1 e9 02` | `SHR ECX,0x2` |
| `10005c4f` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10005c51` | `8b ca` | `MOV ECX,EDX` |
| `10005c53` | `83 e1 03` | `AND ECX,0x3` |
| `10005c56` | `f3 a4` | `MOVSB.REP ES:EDI,ESI` |
| `10005c58` | `8b 43 08` | `MOV EAX,dword ptr [EBX + 0x8]` |
| `10005c5b` | `5f` | `POP EDI` |
| `10005c5c` | `a3 b8 ed 00 10` | `MOV [0x1000edb8],EAX` |
| `10005c61` | `8b 4b 0c` | `MOV ECX,dword ptr [EBX + 0xc]` |
| `10005c64` | `89 0d b0 ed 00 10` | `MOV dword ptr [0x1000edb0],ECX` |
| `10005c6a` | `8b 53 10` | `MOV EDX,dword ptr [EBX + 0x10]` |
| `10005c6d` | `89 15 c4 ed 00 10` | `MOV dword ptr [0x1000edc4],EDX` |
| `10005c73` | `8b 43 14` | `MOV EAX,dword ptr [EBX + 0x14]` |
| `10005c76` | `5e` | `POP ESI` |
| `10005c77` | `a3 ec ee 00 10` | `MOV [0x1000eeec],EAX` |
| `10005c7c` | `5b` | `POP EBX` |
| `10005c7d` | `c2 04 00` | `RET 0x4` |
