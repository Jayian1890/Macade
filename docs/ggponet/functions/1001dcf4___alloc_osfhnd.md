# 1001dcf4 `__alloc_osfhnd`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001dcf4 |
| `name` | __alloc_osfhnd |
| `namespace` | Global |
| `signature` | int __cdecl __alloc_osfhnd(void) |
| `size_bytes` | 386 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __alloc_osfhnd |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __alloc_osfhnd
   
   Library: Visual Studio 2008 Release */

int __cdecl __alloc_osfhnd(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_20;
  
  local_20 = -1;
  iVar4 = 0;
  bVar1 = false;
  iVar2 = __mtinitlocknum(0xb);
  if (iVar2 == 0) {
    local_20 = -1;
  }
  else {
    __lock(0xb);
    for (; iVar4 < 0x40; iVar4 = iVar4 + 1) {
      puVar3 = (undefined4 *)(&DAT_13439540)[iVar4];
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = __calloc_crt(0x20,0x40);
        if (puVar3 != (undefined4 *)0x0) {
          (&DAT_13439540)[iVar4] = puVar3;
          DAT_13439530 = DAT_13439530 + 0x20;
          for (; puVar3 < (undefined4 *)((&DAT_13439540)[iVar4] + 0x800); puVar3 = puVar3 + 0x10) {
            *(undefined1 *)(puVar3 + 1) = 0;
            *puVar3 = 0xffffffff;
            *(undefined1 *)((int)puVar3 + 5) = 10;
            puVar3[2] = 0;
          }
          local_20 = iVar4 << 5;
          *(undefined1 *)((&DAT_13439540)[local_20 >> 5] + 4) = 1;
          iVar2 = ___lock_fhandle(local_20);
          if (iVar2 == 0) {
            local_20 = -1;
          }
        }
        break;
      }
      for (; puVar3 < (undefined4 *)((&DAT_13439540)[iVar4] + 0x800); puVar3 = puVar3 + 0x10) {
        if ((*(byte *)(puVar3 + 1) & 1) == 0) {
          if (puVar3[2] == 0) {
            __lock(10);
            if (puVar3[2] == 0) {
              iVar2 = ___crtInitCritSecAndSpinCount(puVar3 + 3,4000);
              if (iVar2 == 0) {
                bVar1 = true;
              }
              else {
                puVar3[2] = puVar3[2] + 1;
              }
            }
            FUN_1001ddc7();
          }
          if (!bVar1) {
            EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
            if ((*(byte *)(puVar3 + 1) & 1) == 0) {
              *(undefined1 *)(puVar3 + 1) = 1;
              *puVar3 = 0xffffffff;
              local_20 = ((int)puVar3 - (&DAT_13439540)[iVar4] >> 6) + iVar4 * 0x20;
              break;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
          }
        }
      }
      if (local_20 != -1) break;
    }
    FUN_1001de85();
  }
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001dcfb` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001dd0b` | `10016140` | `UNCONDITIONAL_CALL` | __mtinitlocknum | `10016140` |
| `1001dd1f` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001dd68` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001dd83` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |
| `1001dd9a` | `1001ddc7` | `UNCONDITIONAL_CALL` | FUN_1001ddc7 | `1001ddc7` |
| `1001dda9` | `EXTERNAL:00000043` | `COMPUTED_CALL` | KERNEL32.DLL::EnterCriticalSection | `` |
| `1001ddb6` | `EXTERNAL:00000042` | `COMPUTED_CALL` | KERNEL32.DLL::LeaveCriticalSection | `` |
| `1001de01` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001de62` | `1001dc2d` | `UNCONDITIONAL_CALL` | ___lock_fhandle | `1001dc2d` |
| `1001de77` | `1001de85` | `UNCONDITIONAL_CALL` | FUN_1001de85 | `1001de85` |
| `1001de7f` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001cf89` | __tsopen_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001dcf6` | `100342b0` | `DATA` | DAT_100342b0 |
| `1001dd34` | `13439540` | `READ` | DAT_13439540 |
| `1001dd34` | `13439544` | `READ` | DAT_13439544 |
| `1001dd46` | `13439540` | `READ` | DAT_13439540 |
| `1001dd46` | `13439544` | `READ` | DAT_13439544 |
| `1001dda9` | `1002e0c4` | `READ` | PTR_EnterCriticalSection_1002e0c4 |
| `1001ddb6` | `1002e0c0` | `READ` | PTR_LeaveCriticalSection_1002e0c0 |
| `1001dddd` | `13439540` | `READ` | DAT_13439540 |
| `1001de0f` | `13439544` | `DATA` | DAT_13439544 |
| `1001de16` | `13439544` | `WRITE` | DAT_13439544 |
| `1001de18` | `13439530` | `READ_WRITE` | DAT_13439530 |
| `1001de1f` | `13439544` | `READ` | DAT_13439544 |
| `1001de55` | `13439544` | `READ` | DAT_13439544 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001dcf4` | `6a 18` | `PUSH 0x18` |
| `1001dcf6` | `68 b0 42 03 10` | `PUSH 0x100342b0` |
| `1001dcfb` | `e8 fc 8f ff ff` | `CALL 0x10016cfc` |
| `1001dd00` | `83 4d e4 ff` | `OR dword ptr [EBP + -0x1c],0xffffffff` |
| `1001dd04` | `33 ff` | `XOR EDI,EDI` |
| `1001dd06` | `89 7d dc` | `MOV dword ptr [EBP + -0x24],EDI` |
| `1001dd09` | `6a 0b` | `PUSH 0xb` |
| `1001dd0b` | `e8 30 84 ff ff` | `CALL 0x10016140` |
| `1001dd10` | `59` | `POP ECX` |
| `1001dd11` | `85 c0` | `TEST EAX,EAX` |
| `1001dd13` | `75 08` | `JNZ 0x1001dd1d` |
| `1001dd15` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001dd18` | `e9 62 01 00 00` | `JMP 0x1001de7f` |
| `1001dd1d` | `6a 0b` | `PUSH 0xb` |
| `1001dd1f` | `e8 df 84 ff ff` | `CALL 0x10016203` |
| `1001dd24` | `59` | `POP ECX` |
| `1001dd25` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `1001dd28` | `89 7d d8` | `MOV dword ptr [EBP + -0x28],EDI` |
| `1001dd2b` | `83 ff 40` | `CMP EDI,0x40` |
| `1001dd2e` | `0f 8d 3c 01 00 00` | `JGE 0x1001de70` |
| `1001dd34` | `8b 34 bd 40 95 43 13` | `MOV ESI,dword ptr [EDI*0x4 + 0x13439540]` |
| `1001dd3b` | `85 f6` | `TEST ESI,ESI` |
| `1001dd3d` | `0f 84 ba 00 00 00` | `JZ 0x1001ddfd` |
| `1001dd43` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `1001dd46` | `8b 04 bd 40 95 43 13` | `MOV EAX,dword ptr [EDI*0x4 + 0x13439540]` |
| `1001dd4d` | `05 00 08 00 00` | `ADD EAX,0x800` |
| `1001dd52` | `3b f0` | `CMP ESI,EAX` |
| `1001dd54` | `0f 83 97 00 00 00` | `JNC 0x1001ddf1` |
| `1001dd5a` | `f6 46 04 01` | `TEST byte ptr [ESI + 0x4],0x1` |
| `1001dd5e` | `75 5c` | `JNZ 0x1001ddbc` |
| `1001dd60` | `83 7e 08 00` | `CMP dword ptr [ESI + 0x8],0x0` |
| `1001dd64` | `75 39` | `JNZ 0x1001dd9f` |
| `1001dd66` | `6a 0a` | `PUSH 0xa` |
| `1001dd68` | `e8 96 84 ff ff` | `CALL 0x10016203` |
| `1001dd6d` | `59` | `POP ECX` |
| `1001dd6e` | `33 db` | `XOR EBX,EBX` |
| `1001dd70` | `43` | `INC EBX` |
| `1001dd71` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1001dd74` | `83 7e 08 00` | `CMP dword ptr [ESI + 0x8],0x0` |
| `1001dd78` | `75 1c` | `JNZ 0x1001dd96` |
| `1001dd7a` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `1001dd7f` | `8d 46 0c` | `LEA EAX,[ESI + 0xc]` |
| `1001dd82` | `50` | `PUSH EAX` |
| `1001dd83` | `e8 6b bb ff ff` | `CALL 0x100198f3` |
| `1001dd88` | `59` | `POP ECX` |
| `1001dd89` | `59` | `POP ECX` |
| `1001dd8a` | `85 c0` | `TEST EAX,EAX` |
| `1001dd8c` | `75 05` | `JNZ 0x1001dd93` |
| `1001dd8e` | `89 5d dc` | `MOV dword ptr [EBP + -0x24],EBX` |
| `1001dd91` | `eb 03` | `JMP 0x1001dd96` |
| `1001dd93` | `ff 46 08` | `INC dword ptr [ESI + 0x8]` |
| `1001dd96` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001dd9a` | `e8 28 00 00 00` | `CALL 0x1001ddc7` |
| `1001dd9f` | `83 7d dc 00` | `CMP dword ptr [EBP + -0x24],0x0` |
| `1001dda3` | `75 17` | `JNZ 0x1001ddbc` |
| `1001dda5` | `8d 5e 0c` | `LEA EBX,[ESI + 0xc]` |
| `1001dda8` | `53` | `PUSH EBX` |
| `1001dda9` | `ff 15 c4 e0 02 10` | `CALL dword ptr [0x1002e0c4]` |
| `1001ddaf` | `f6 46 04 01` | `TEST byte ptr [ESI + 0x4],0x1` |
| `1001ddb3` | `74 1b` | `JZ 0x1001ddd0` |
| `1001ddb5` | `53` | `PUSH EBX` |
| `1001ddb6` | `ff 15 c0 e0 02 10` | `CALL dword ptr [0x1002e0c0]` |
| `1001ddbc` | `83 c6 40` | `ADD ESI,0x40` |
| `1001ddbf` | `eb 82` | `JMP 0x1001dd43` |
| `1001ddd0` | `83 7d dc 00` | `CMP dword ptr [EBP + -0x24],0x0` |
| `1001ddd4` | `75 e6` | `JNZ 0x1001ddbc` |
| `1001ddd6` | `c6 46 04 01` | `MOV byte ptr [ESI + 0x4],0x1` |
| `1001ddda` | `83 0e ff` | `OR dword ptr [ESI],0xffffffff` |
| `1001dddd` | `2b 34 bd 40 95 43 13` | `SUB ESI,dword ptr [EDI*0x4 + 0x13439540]` |
| `1001dde4` | `c1 fe 06` | `SAR ESI,0x6` |
| `1001dde7` | `8b c7` | `MOV EAX,EDI` |
| `1001dde9` | `c1 e0 05` | `SHL EAX,0x5` |
| `1001ddec` | `03 f0` | `ADD ESI,EAX` |
| `1001ddee` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001ddf1` | `83 7d e4 ff` | `CMP dword ptr [EBP + -0x1c],-0x1` |
| `1001ddf5` | `75 79` | `JNZ 0x1001de70` |
| `1001ddf7` | `47` | `INC EDI` |
| `1001ddf8` | `e9 2b ff ff ff` | `JMP 0x1001dd28` |
| `1001ddfd` | `6a 40` | `PUSH 0x40` |
| `1001ddff` | `6a 20` | `PUSH 0x20` |
| `1001de01` | `e8 0e c7 ff ff` | `CALL 0x1001a514` |
| `1001de06` | `59` | `POP ECX` |
| `1001de07` | `59` | `POP ECX` |
| `1001de08` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001de0b` | `85 c0` | `TEST EAX,EAX` |
| `1001de0d` | `74 61` | `JZ 0x1001de70` |
| `1001de0f` | `8d 0c bd 40 95 43 13` | `LEA ECX,[EDI*0x4 + 0x13439540]` |
| `1001de16` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `1001de18` | `83 05 30 95 43 13 20` | `ADD dword ptr [0x13439530],0x20` |
| `1001de1f` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `1001de21` | `81 c2 00 08 00 00` | `ADD EDX,0x800` |
| `1001de27` | `3b c2` | `CMP EAX,EDX` |
| `1001de29` | `73 17` | `JNC 0x1001de42` |
| `1001de2b` | `c6 40 04 00` | `MOV byte ptr [EAX + 0x4],0x0` |
| `1001de2f` | `83 08 ff` | `OR dword ptr [EAX],0xffffffff` |
| `1001de32` | `c6 40 05 0a` | `MOV byte ptr [EAX + 0x5],0xa` |
| `1001de36` | `83 60 08 00` | `AND dword ptr [EAX + 0x8],0x0` |
| `1001de3a` | `83 c0 40` | `ADD EAX,0x40` |
| `1001de3d` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001de40` | `eb dd` | `JMP 0x1001de1f` |
| `1001de42` | `c1 e7 05` | `SHL EDI,0x5` |
| `1001de45` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `1001de48` | `8b c7` | `MOV EAX,EDI` |
| `1001de4a` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001de4d` | `8b cf` | `MOV ECX,EDI` |
| `1001de4f` | `83 e1 1f` | `AND ECX,0x1f` |
| `1001de52` | `c1 e1 06` | `SHL ECX,0x6` |
| `1001de55` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001de5c` | `c6 44 08 04 01` | `MOV byte ptr [EAX + ECX*0x1 + 0x4],0x1` |
| `1001de61` | `57` | `PUSH EDI` |
| `1001de62` | `e8 c6 fd ff ff` | `CALL 0x1001dc2d` |
| `1001de67` | `59` | `POP ECX` |
| `1001de68` | `85 c0` | `TEST EAX,EAX` |
| `1001de6a` | `75 04` | `JNZ 0x1001de70` |
| `1001de6c` | `83 4d e4 ff` | `OR dword ptr [EBP + -0x1c],0xffffffff` |
| `1001de70` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001de77` | `e8 09 00 00 00` | `CALL 0x1001de85` |
| `1001de7c` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001de7f` | `e8 bd 8e ff ff` | `CALL 0x10016d41` |
| `1001de84` | `c3` | `RET` |
