# 10014f25 `__VEC_memcpy`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014f25 |
| `name` | __VEC_memcpy |
| `namespace` | Global |
| `signature` | undefined __VEC_memcpy(void) |
| `size_bytes` | 227 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __VEC_memcpy |

## Decompiled C

```c

/* Library Function - Single Match
    __VEC_memcpy
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2005 Release, Visual Studio 2008 Debug, Visual
   Studio 2008 Release */

undefined4 * __VEC_memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  
  uVar3 = (int)param_2 >> 0x1f;
  iVar1 = (((uint)param_2 ^ uVar3) - uVar3 & 0xf ^ uVar3) - uVar3;
  uVar3 = (int)param_1 >> 0x1f;
  uVar6 = ((uint)param_1 ^ uVar3) - uVar3 & 0xf ^ uVar3;
  if (iVar1 == 0 && uVar6 == uVar3) {
    uVar3 = param_3 & 0x7f;
    if (param_3 != uVar3) {
      FUN_10014e9e(param_1,param_2,param_3 - uVar3);
    }
    if (uVar3 != 0) {
      puVar4 = (undefined1 *)((int)param_2 + (param_3 - uVar3));
      puVar7 = (undefined1 *)((int)param_1 + (param_3 - uVar3));
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
    }
  }
  else if (iVar1 == uVar6 - uVar3) {
    iVar1 = 0x10 - iVar1;
    puVar5 = param_2;
    puVar8 = param_1;
    for (iVar2 = iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    __VEC_memcpy((undefined1 *)((int)param_1 + iVar1),(undefined1 *)((int)param_2 + iVar1),
                 param_3 - iVar1);
  }
  else {
    puVar5 = param_1;
    for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *param_2;
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
    }
    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014f72` | `10014e9e` | `UNCONDITIONAL_CALL` | FUN_10014e9e | `10014e9e` |
| `10014fd4` | `10014f25` | `UNCONDITIONAL_CALL` | __VEC_memcpy | `10014f25` |

## Callers

| From | Function |
| --- | --- |
| `10014fd4` | __VEC_memcpy |
| `10010d22` | _memcpy |
| `10012782` | _memmove |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014f25` | `55` | `PUSH EBP` |
| `10014f26` | `8b ec` | `MOV EBP,ESP` |
| `10014f28` | `83 ec 1c` | `SUB ESP,0x1c` |
| `10014f2b` | `89 7d f4` | `MOV dword ptr [EBP + -0xc],EDI` |
| `10014f2e` | `89 75 f8` | `MOV dword ptr [EBP + -0x8],ESI` |
| `10014f31` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `10014f34` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `10014f37` | `8b c3` | `MOV EAX,EBX` |
| `10014f39` | `99` | `CDQ` |
| `10014f3a` | `8b c8` | `MOV ECX,EAX` |
| `10014f3c` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014f3f` | `33 ca` | `XOR ECX,EDX` |
| `10014f41` | `2b ca` | `SUB ECX,EDX` |
| `10014f43` | `83 e1 0f` | `AND ECX,0xf` |
| `10014f46` | `33 ca` | `XOR ECX,EDX` |
| `10014f48` | `2b ca` | `SUB ECX,EDX` |
| `10014f4a` | `99` | `CDQ` |
| `10014f4b` | `8b f8` | `MOV EDI,EAX` |
| `10014f4d` | `33 fa` | `XOR EDI,EDX` |
| `10014f4f` | `2b fa` | `SUB EDI,EDX` |
| `10014f51` | `83 e7 0f` | `AND EDI,0xf` |
| `10014f54` | `33 fa` | `XOR EDI,EDX` |
| `10014f56` | `2b fa` | `SUB EDI,EDX` |
| `10014f58` | `8b d1` | `MOV EDX,ECX` |
| `10014f5a` | `0b d7` | `OR EDX,EDI` |
| `10014f5c` | `75 4a` | `JNZ 0x10014fa8` |
| `10014f5e` | `8b 75 10` | `MOV ESI,dword ptr [EBP + 0x10]` |
| `10014f61` | `8b ce` | `MOV ECX,ESI` |
| `10014f63` | `83 e1 7f` | `AND ECX,0x7f` |
| `10014f66` | `89 4d e8` | `MOV dword ptr [EBP + -0x18],ECX` |
| `10014f69` | `3b f1` | `CMP ESI,ECX` |
| `10014f6b` | `74 13` | `JZ 0x10014f80` |
| `10014f6d` | `2b f1` | `SUB ESI,ECX` |
| `10014f6f` | `56` | `PUSH ESI` |
| `10014f70` | `53` | `PUSH EBX` |
| `10014f71` | `50` | `PUSH EAX` |
| `10014f72` | `e8 27 ff ff ff` | `CALL 0x10014e9e` |
| `10014f77` | `83 c4 0c` | `ADD ESP,0xc` |
| `10014f7a` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014f7d` | `8b 4d e8` | `MOV ECX,dword ptr [EBP + -0x18]` |
| `10014f80` | `85 c9` | `TEST ECX,ECX` |
| `10014f82` | `74 77` | `JZ 0x10014ffb` |
| `10014f84` | `8b 5d 10` | `MOV EBX,dword ptr [EBP + 0x10]` |
| `10014f87` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10014f8a` | `03 d3` | `ADD EDX,EBX` |
| `10014f8c` | `2b d1` | `SUB EDX,ECX` |
| `10014f8e` | `89 55 ec` | `MOV dword ptr [EBP + -0x14],EDX` |
| `10014f91` | `03 d8` | `ADD EBX,EAX` |
| `10014f93` | `2b d9` | `SUB EBX,ECX` |
| `10014f95` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `10014f98` | `8b 75 ec` | `MOV ESI,dword ptr [EBP + -0x14]` |
| `10014f9b` | `8b 7d f0` | `MOV EDI,dword ptr [EBP + -0x10]` |
| `10014f9e` | `8b 4d e8` | `MOV ECX,dword ptr [EBP + -0x18]` |
| `10014fa1` | `f3 a4` | `MOVSB.REP ES:EDI,ESI` |
| `10014fa3` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014fa6` | `eb 53` | `JMP 0x10014ffb` |
| `10014fa8` | `3b cf` | `CMP ECX,EDI` |
| `10014faa` | `75 35` | `JNZ 0x10014fe1` |
| `10014fac` | `f7 d9` | `NEG ECX` |
| `10014fae` | `83 c1 10` | `ADD ECX,0x10` |
| `10014fb1` | `89 4d e4` | `MOV dword ptr [EBP + -0x1c],ECX` |
| `10014fb4` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10014fb7` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10014fba` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `10014fbd` | `f3 a4` | `MOVSB.REP ES:EDI,ESI` |
| `10014fbf` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10014fc2` | `03 4d e4` | `ADD ECX,dword ptr [EBP + -0x1c]` |
| `10014fc5` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10014fc8` | `03 55 e4` | `ADD EDX,dword ptr [EBP + -0x1c]` |
| `10014fcb` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10014fce` | `2b 45 e4` | `SUB EAX,dword ptr [EBP + -0x1c]` |
| `10014fd1` | `50` | `PUSH EAX` |
| `10014fd2` | `52` | `PUSH EDX` |
| `10014fd3` | `51` | `PUSH ECX` |
| `10014fd4` | `e8 4c ff ff ff` | `CALL 0x10014f25` |
| `10014fd9` | `83 c4 0c` | `ADD ESP,0xc` |
| `10014fdc` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014fdf` | `eb 1a` | `JMP 0x10014ffb` |
| `10014fe1` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10014fe4` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10014fe7` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10014fea` | `8b d1` | `MOV EDX,ECX` |
| `10014fec` | `c1 e9 02` | `SHR ECX,0x2` |
| `10014fef` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10014ff1` | `8b ca` | `MOV ECX,EDX` |
| `10014ff3` | `83 e1 03` | `AND ECX,0x3` |
| `10014ff6` | `f3 a4` | `MOVSB.REP ES:EDI,ESI` |
| `10014ff8` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014ffb` | `8b 5d fc` | `MOV EBX,dword ptr [EBP + -0x4]` |
| `10014ffe` | `8b 75 f8` | `MOV ESI,dword ptr [EBP + -0x8]` |
| `10015001` | `8b 7d f4` | `MOV EDI,dword ptr [EBP + -0xc]` |
| `10015004` | `8b e5` | `MOV ESP,EBP` |
| `10015006` | `5d` | `POP EBP` |
| `10015007` | `c3` | `RET` |
