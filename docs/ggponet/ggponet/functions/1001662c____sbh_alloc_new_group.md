# 1001662c `___sbh_alloc_new_group`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001662c |
| `name` | ___sbh_alloc_new_group |
| `namespace` | Global |
| `signature` | undefined ___sbh_alloc_new_group(void) |
| `size_bytes` | 264 |
| `stack_frame_size` | 16 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___sbh_alloc_new_group |

## Decompiled C

```c

/* Library Function - Single Match
    ___sbh_alloc_new_group
   
   Library: Visual Studio 2008 Release */

int ___sbh_alloc_new_group(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPVOID pvVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  LPVOID lpAddress;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar8 = 0;
  for (iVar3 = *(int *)(param_1 + 8); -1 < iVar3; iVar3 = iVar3 * 2) {
    iVar8 = iVar8 + 1;
  }
  iVar3 = iVar8 * 0x204 + 0x144 + iVar2;
  iVar7 = 0x3f;
  iVar4 = iVar3;
  do {
    *(int *)(iVar4 + 8) = iVar4;
    *(int *)(iVar4 + 4) = iVar4;
    iVar4 = iVar4 + 8;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  lpAddress = (LPVOID)(iVar8 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar5 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar5 == (LPVOID)0x0) {
    iVar8 = -1;
  }
  else {
    if (lpAddress <= (LPVOID)((int)lpAddress + 0x7000U)) {
      piVar6 = (int *)((int)lpAddress + 0x10);
      iVar7 = ((uint)((int)((int)lpAddress + 0x7000U) - (int)lpAddress) >> 0xc) + 1;
      do {
        piVar6[-2] = -1;
        piVar6[0x3fb] = -1;
        *piVar6 = (int)(piVar6 + 0x3ff);
        piVar6[-1] = 0xff0;
        piVar6[1] = (int)(piVar6 + -0x401);
        piVar6[0x3fa] = 0xff0;
        piVar6 = piVar6 + 0x400;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(int *)(iVar3 + 0x1fc) = (int)lpAddress + 0xc;
    *(int *)((int)lpAddress + 0x14) = iVar3 + 0x1f8;
    *(int *)(iVar3 + 0x200) = (int)lpAddress + 0x700c;
    *(int *)((int)lpAddress + 0x7010) = iVar3 + 0x1f8;
    *(undefined4 *)(iVar2 + 0x44 + iVar8 * 4) = 0;
    *(undefined4 *)(iVar2 + 0xc4 + iVar8 * 4) = 1;
    cVar1 = *(char *)(iVar2 + 0x43);
    *(char *)(iVar2 + 0x43) = cVar1 + '\x01';
    if (cVar1 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar8 & 0x1f));
  }
  return iVar8;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10016680` | `EXTERNAL:00000044` | `COMPUTED_CALL` | KERNEL32.DLL::VirtualAlloc | `` |

## Callers

| From | Function |
| --- | --- |
| `10016aed` | ___sbh_alloc_block |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016680` | `1002e0c8` | `READ` | PTR_VirtualAlloc_1002e0c8 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001662c` | `8b ff` | `MOV EDI,EDI` |
| `1001662e` | `55` | `PUSH EBP` |
| `1001662f` | `8b ec` | `MOV EBP,ESP` |
| `10016631` | `51` | `PUSH ECX` |
| `10016632` | `51` | `PUSH ECX` |
| `10016633` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016636` | `8b 41 08` | `MOV EAX,dword ptr [ECX + 0x8]` |
| `10016639` | `53` | `PUSH EBX` |
| `1001663a` | `56` | `PUSH ESI` |
| `1001663b` | `8b 71 10` | `MOV ESI,dword ptr [ECX + 0x10]` |
| `1001663e` | `57` | `PUSH EDI` |
| `1001663f` | `33 db` | `XOR EBX,EBX` |
| `10016641` | `eb 03` | `JMP 0x10016646` |
| `10016643` | `03 c0` | `ADD EAX,EAX` |
| `10016645` | `43` | `INC EBX` |
| `10016646` | `85 c0` | `TEST EAX,EAX` |
| `10016648` | `7d f9` | `JGE 0x10016643` |
| `1001664a` | `8b c3` | `MOV EAX,EBX` |
| `1001664c` | `69 c0 04 02 00 00` | `IMUL EAX,EAX,0x204` |
| `10016652` | `8d 84 30 44 01 00 00` | `LEA EAX,[EAX + ESI*0x1 + 0x144]` |
| `10016659` | `6a 3f` | `PUSH 0x3f` |
| `1001665b` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001665e` | `5a` | `POP EDX` |
| `1001665f` | `89 40 08` | `MOV dword ptr [EAX + 0x8],EAX` |
| `10016662` | `89 40 04` | `MOV dword ptr [EAX + 0x4],EAX` |
| `10016665` | `83 c0 08` | `ADD EAX,0x8` |
| `10016668` | `4a` | `DEC EDX` |
| `10016669` | `75 f4` | `JNZ 0x1001665f` |
| `1001666b` | `6a 04` | `PUSH 0x4` |
| `1001666d` | `8b fb` | `MOV EDI,EBX` |
| `1001666f` | `68 00 10 00 00` | `PUSH 0x1000` |
| `10016674` | `c1 e7 0f` | `SHL EDI,0xf` |
| `10016677` | `03 79 0c` | `ADD EDI,dword ptr [ECX + 0xc]` |
| `1001667a` | `68 00 80 00 00` | `PUSH 0x8000` |
| `1001667f` | `57` | `PUSH EDI` |
| `10016680` | `ff 15 c8 e0 02 10` | `CALL dword ptr [0x1002e0c8]` |
| `10016686` | `85 c0` | `TEST EAX,EAX` |
| `10016688` | `75 08` | `JNZ 0x10016692` |
| `1001668a` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001668d` | `e9 9d 00 00 00` | `JMP 0x1001672f` |
| `10016692` | `8d 97 00 70 00 00` | `LEA EDX,[EDI + 0x7000]` |
| `10016698` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `1001669b` | `3b fa` | `CMP EDI,EDX` |
| `1001669d` | `77 43` | `JA 0x100166e2` |
| `1001669f` | `8b ca` | `MOV ECX,EDX` |
| `100166a1` | `2b cf` | `SUB ECX,EDI` |
| `100166a3` | `c1 e9 0c` | `SHR ECX,0xc` |
| `100166a6` | `8d 47 10` | `LEA EAX,[EDI + 0x10]` |
| `100166a9` | `41` | `INC ECX` |
| `100166aa` | `83 48 f8 ff` | `OR dword ptr [EAX + -0x8],0xffffffff` |
| `100166ae` | `83 88 ec 0f 00 00 ff` | `OR dword ptr [EAX + 0xfec],0xffffffff` |
| `100166b5` | `8d 90 fc 0f 00 00` | `LEA EDX,[EAX + 0xffc]` |
| `100166bb` | `89 10` | `MOV dword ptr [EAX],EDX` |
| `100166bd` | `8d 90 fc ef ff ff` | `LEA EDX,[EAX + 0xffffeffc]` |
| `100166c3` | `c7 40 fc f0 0f 00 00` | `MOV dword ptr [EAX + -0x4],0xff0` |
| `100166ca` | `89 50 04` | `MOV dword ptr [EAX + 0x4],EDX` |
| `100166cd` | `c7 80 e8 0f 00 00 f0 0f 00 00` | `MOV dword ptr [EAX + 0xfe8],0xff0` |
| `100166d7` | `05 00 10 00 00` | `ADD EAX,0x1000` |
| `100166dc` | `49` | `DEC ECX` |
| `100166dd` | `75 cb` | `JNZ 0x100166aa` |
| `100166df` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `100166e2` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `100166e5` | `05 f8 01 00 00` | `ADD EAX,0x1f8` |
| `100166ea` | `8d 4f 0c` | `LEA ECX,[EDI + 0xc]` |
| `100166ed` | `89 48 04` | `MOV dword ptr [EAX + 0x4],ECX` |
| `100166f0` | `89 41 08` | `MOV dword ptr [ECX + 0x8],EAX` |
| `100166f3` | `8d 4a 0c` | `LEA ECX,[EDX + 0xc]` |
| `100166f6` | `89 48 08` | `MOV dword ptr [EAX + 0x8],ECX` |
| `100166f9` | `89 41 04` | `MOV dword ptr [ECX + 0x4],EAX` |
| `100166fc` | `83 64 9e 44 00` | `AND dword ptr [ESI + EBX*0x4 + 0x44],0x0` |
| `10016701` | `33 ff` | `XOR EDI,EDI` |
| `10016703` | `47` | `INC EDI` |
| `10016704` | `89 bc 9e c4 00 00 00` | `MOV dword ptr [ESI + EBX*0x4 + 0xc4],EDI` |
| `1001670b` | `8a 46 43` | `MOV AL,byte ptr [ESI + 0x43]` |
| `1001670e` | `8a c8` | `MOV CL,AL` |
| `10016710` | `fe c1` | `INC CL` |
| `10016712` | `84 c0` | `TEST AL,AL` |
| `10016714` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10016717` | `88 4e 43` | `MOV byte ptr [ESI + 0x43],CL` |
| `1001671a` | `75 03` | `JNZ 0x1001671f` |
| `1001671c` | `09 78 04` | `OR dword ptr [EAX + 0x4],EDI` |
| `1001671f` | `ba 00 00 00 80` | `MOV EDX,0x80000000` |
| `10016724` | `8b cb` | `MOV ECX,EBX` |
| `10016726` | `d3 ea` | `SHR EDX,CL` |
| `10016728` | `f7 d2` | `NOT EDX` |
| `1001672a` | `21 50 08` | `AND dword ptr [EAX + 0x8],EDX` |
| `1001672d` | `8b c3` | `MOV EAX,EBX` |
| `1001672f` | `5f` | `POP EDI` |
| `10016730` | `5e` | `POP ESI` |
| `10016731` | `5b` | `POP EBX` |
| `10016732` | `c9` | `LEAVE` |
| `10016733` | `c3` | `RET` |
