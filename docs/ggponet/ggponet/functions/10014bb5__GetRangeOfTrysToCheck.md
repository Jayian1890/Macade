# 10014bb5 `_GetRangeOfTrysToCheck`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014bb5 |
| `name` | _GetRangeOfTrysToCheck |
| `namespace` | Global |
| `signature` | _s_TryBlockMapEntry * __cdecl _GetRangeOfTrysToCheck(_s_FuncInfo * param_1, int param_2, int param_3, uint * param_4, uint * param_5) |
| `size_bytes` | 117 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?_GetRangeOfTrysToCheck@@YAPBU_s_TryBlockMapEntry@@PBU_s_FuncInfo@@HHPAI1@Z, _GetRangeOfTrysToCheck |

## Decompiled C

```c

/* Library Function - Single Match
    struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *)
   
   Library: Visual Studio 2008 Release */

_s_TryBlockMapEntry * __cdecl
_GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  TryBlockMapEntry *pTVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  pTVar1 = param_1->pTryBlockMap;
  uVar5 = param_1->nTryBlocks;
  uVar2 = uVar5;
  uVar3 = uVar5;
  while (uVar4 = uVar2, -1 < param_2) {
    if (uVar5 == 0xffffffff) {
      _inconsistency();
    }
    uVar5 = uVar5 - 1;
    if (((pTVar1[uVar5].tryHigh < param_3) && (param_3 <= pTVar1[uVar5].catchHigh)) ||
       (uVar2 = uVar4, uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar2 = uVar5;
      uVar3 = uVar4;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((param_1->nTryBlocks < uVar3) || (uVar3 < uVar5)) {
    _inconsistency();
  }
  return pTVar1 + uVar5;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014bd3` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `10014c18` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |

## Callers

| From | Function |
| --- | --- |
| `1001b644` | FindHandler |
| `1001b41c` | FindHandlerForForeignException |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014bb5` | `8b ff` | `MOV EDI,EDI` |
| `10014bb7` | `55` | `PUSH EBP` |
| `10014bb8` | `8b ec` | `MOV EBP,ESP` |
| `10014bba` | `51` | `PUSH ECX` |
| `10014bbb` | `53` | `PUSH EBX` |
| `10014bbc` | `56` | `PUSH ESI` |
| `10014bbd` | `57` | `PUSH EDI` |
| `10014bbe` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10014bc1` | `8b 47 10` | `MOV EAX,dword ptr [EDI + 0x10]` |
| `10014bc4` | `8b 77 0c` | `MOV ESI,dword ptr [EDI + 0xc]` |
| `10014bc7` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10014bca` | `8b de` | `MOV EBX,ESI` |
| `10014bcc` | `eb 2d` | `JMP 0x10014bfb` |
| `10014bce` | `83 fe ff` | `CMP ESI,-0x1` |
| `10014bd1` | `75 05` | `JNZ 0x10014bd8` |
| `10014bd3` | `e8 21 49 00 00` | `CALL 0x100194f9` |
| `10014bd8` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10014bdb` | `4e` | `DEC ESI` |
| `10014bdc` | `8b c6` | `MOV EAX,ESI` |
| `10014bde` | `6b c0 14` | `IMUL EAX,EAX,0x14` |
| `10014be1` | `03 c1` | `ADD EAX,ECX` |
| `10014be3` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10014be6` | `39 48 04` | `CMP dword ptr [EAX + 0x4],ECX` |
| `10014be9` | `7d 05` | `JGE 0x10014bf0` |
| `10014beb` | `3b 48 08` | `CMP ECX,dword ptr [EAX + 0x8]` |
| `10014bee` | `7e 05` | `JLE 0x10014bf5` |
| `10014bf0` | `83 fe ff` | `CMP ESI,-0x1` |
| `10014bf3` | `75 09` | `JNZ 0x10014bfe` |
| `10014bf5` | `ff 4d 0c` | `DEC dword ptr [EBP + 0xc]` |
| `10014bf8` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10014bfb` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `10014bfe` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `10014c02` | `7d ca` | `JGE 0x10014bce` |
| `10014c04` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10014c07` | `46` | `INC ESI` |
| `10014c08` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10014c0a` | `8b 45 18` | `MOV EAX,dword ptr [EBP + 0x18]` |
| `10014c0d` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `10014c0f` | `3b 5f 0c` | `CMP EBX,dword ptr [EDI + 0xc]` |
| `10014c12` | `77 04` | `JA 0x10014c18` |
| `10014c14` | `3b f3` | `CMP ESI,EBX` |
| `10014c16` | `76 05` | `JBE 0x10014c1d` |
| `10014c18` | `e8 dc 48 00 00` | `CALL 0x100194f9` |
| `10014c1d` | `8b c6` | `MOV EAX,ESI` |
| `10014c1f` | `6b c0 14` | `IMUL EAX,EAX,0x14` |
| `10014c22` | `03 45 fc` | `ADD EAX,dword ptr [EBP + -0x4]` |
| `10014c25` | `5f` | `POP EDI` |
| `10014c26` | `5e` | `POP ESI` |
| `10014c27` | `5b` | `POP EBX` |
| `10014c28` | `c9` | `LEAVE` |
| `10014c29` | `c3` | `RET` |
