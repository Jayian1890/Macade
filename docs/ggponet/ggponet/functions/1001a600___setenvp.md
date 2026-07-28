# 1001a600 `__setenvp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a600 |
| `name` | __setenvp |
| `namespace` | Global |
| `signature` | int __cdecl __setenvp(void) |
| `size_bytes` | 219 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __setenvp |

## Decompiled C

```c

/* Library Function - Single Match
    __setenvp
   
   Library: Visual Studio 2008 Release */

int __cdecl __setenvp(void)

{
  undefined4 *puVar1;
  size_t sVar2;
  char *_Dst;
  errno_t eVar3;
  char *pcVar4;
  int iVar5;
  
  if (DAT_1343a698 == 0) {
    ___initmbctable();
  }
  iVar5 = 0;
  pcVar4 = DAT_10038a74;
  if (DAT_10038a74 != (char *)0x0) {
    for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + sVar2 + 1) {
      if (*pcVar4 != '=') {
        iVar5 = iVar5 + 1;
      }
      sVar2 = _strlen(pcVar4);
    }
    puVar1 = __calloc_crt(iVar5 + 1,4);
    pcVar4 = DAT_10038a74;
    DAT_10038a4c = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      do {
        if (*pcVar4 == '\0') {
          _free(DAT_10038a74);
          DAT_10038a74 = (char *)0x0;
          *puVar1 = 0;
          DAT_1343a68c = 1;
          return 0;
        }
        sVar2 = _strlen(pcVar4);
        sVar2 = sVar2 + 1;
        if (*pcVar4 != '=') {
          _Dst = __calloc_crt(sVar2,1);
          *puVar1 = _Dst;
          if (_Dst == (char *)0x0) {
            _free(DAT_10038a4c);
            DAT_10038a4c = (undefined4 *)0x0;
            return -1;
          }
          eVar3 = _strcpy_s(_Dst,sVar2,pcVar4);
          if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          puVar1 = puVar1 + 1;
        }
        pcVar4 = pcVar4 + sVar2;
      } while( true );
    }
  }
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a609` | `1001c23c` | `UNCONDITIONAL_CALL` | ___initmbctable | `1001c23c` |
| `1001a62a` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001a63e` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001a65b` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001a66c` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001a67c` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1001a68f` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1001a6a7` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001a6cd` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `100146d3` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a600` | `1343a698` | `READ` | DAT_1343a698 |
| `1001a60f` | `10038a74` | `READ` | DAT_10038a74 |
| `1001a647` | `10038a4c` | `WRITE` | DAT_10038a4c |
| `1001a651` | `10038a74` | `READ` | DAT_10038a74 |
| `1001a6a1` | `10038a74` | `READ` | DAT_10038a74 |
| `1001a6ac` | `10038a74` | `READ_WRITE` | DAT_10038a74 |
| `1001a6b6` | `1343a68c` | `WRITE` | DAT_1343a68c |
| `1001a6c7` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001a6d2` | `10038a4c` | `READ_WRITE` | DAT_10038a4c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a600` | `83 3d 98 a6 43 13 00` | `CMP dword ptr [0x1343a698],0x0` |
| `1001a607` | `75 05` | `JNZ 0x1001a60e` |
| `1001a609` | `e8 2e 1c 00 00` | `CALL 0x1001c23c` |
| `1001a60e` | `56` | `PUSH ESI` |
| `1001a60f` | `8b 35 74 8a 03 10` | `MOV ESI,dword ptr [0x10038a74]` |
| `1001a615` | `57` | `PUSH EDI` |
| `1001a616` | `33 ff` | `XOR EDI,EDI` |
| `1001a618` | `85 f6` | `TEST ESI,ESI` |
| `1001a61a` | `75 18` | `JNZ 0x1001a634` |
| `1001a61c` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a61f` | `e9 a0 00 00 00` | `JMP 0x1001a6c4` |
| `1001a624` | `3c 3d` | `CMP AL,0x3d` |
| `1001a626` | `74 01` | `JZ 0x1001a629` |
| `1001a628` | `47` | `INC EDI` |
| `1001a629` | `56` | `PUSH ESI` |
| `1001a62a` | `e8 c1 6d ff ff` | `CALL 0x100113f0` |
| `1001a62f` | `59` | `POP ECX` |
| `1001a630` | `8d 74 06 01` | `LEA ESI,[ESI + EAX*0x1 + 0x1]` |
| `1001a634` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a636` | `84 c0` | `TEST AL,AL` |
| `1001a638` | `75 ea` | `JNZ 0x1001a624` |
| `1001a63a` | `6a 04` | `PUSH 0x4` |
| `1001a63c` | `47` | `INC EDI` |
| `1001a63d` | `57` | `PUSH EDI` |
| `1001a63e` | `e8 d1 fe ff ff` | `CALL 0x1001a514` |
| `1001a643` | `8b f8` | `MOV EDI,EAX` |
| `1001a645` | `59` | `POP ECX` |
| `1001a646` | `59` | `POP ECX` |
| `1001a647` | `89 3d 4c 8a 03 10` | `MOV dword ptr [0x10038a4c],EDI` |
| `1001a64d` | `85 ff` | `TEST EDI,EDI` |
| `1001a64f` | `74 cb` | `JZ 0x1001a61c` |
| `1001a651` | `8b 35 74 8a 03 10` | `MOV ESI,dword ptr [0x10038a74]` |
| `1001a657` | `53` | `PUSH EBX` |
| `1001a658` | `eb 42` | `JMP 0x1001a69c` |
| `1001a65a` | `56` | `PUSH ESI` |
| `1001a65b` | `e8 90 6d ff ff` | `CALL 0x100113f0` |
| `1001a660` | `8b d8` | `MOV EBX,EAX` |
| `1001a662` | `43` | `INC EBX` |
| `1001a663` | `80 3e 3d` | `CMP byte ptr [ESI],0x3d` |
| `1001a666` | `59` | `POP ECX` |
| `1001a667` | `74 31` | `JZ 0x1001a69a` |
| `1001a669` | `6a 01` | `PUSH 0x1` |
| `1001a66b` | `53` | `PUSH EBX` |
| `1001a66c` | `e8 a3 fe ff ff` | `CALL 0x1001a514` |
| `1001a671` | `59` | `POP ECX` |
| `1001a672` | `59` | `POP ECX` |
| `1001a673` | `89 07` | `MOV dword ptr [EDI],EAX` |
| `1001a675` | `85 c0` | `TEST EAX,EAX` |
| `1001a677` | `74 4e` | `JZ 0x1001a6c7` |
| `1001a679` | `56` | `PUSH ESI` |
| `1001a67a` | `53` | `PUSH EBX` |
| `1001a67b` | `50` | `PUSH EAX` |
| `1001a67c` | `e8 fa b8 ff ff` | `CALL 0x10015f7b` |
| `1001a681` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001a684` | `85 c0` | `TEST EAX,EAX` |
| `1001a686` | `74 0f` | `JZ 0x1001a697` |
| `1001a688` | `33 c0` | `XOR EAX,EAX` |
| `1001a68a` | `50` | `PUSH EAX` |
| `1001a68b` | `50` | `PUSH EAX` |
| `1001a68c` | `50` | `PUSH EAX` |
| `1001a68d` | `50` | `PUSH EAX` |
| `1001a68e` | `50` | `PUSH EAX` |
| `1001a68f` | `e8 f3 6e ff ff` | `CALL 0x10011587` |
| `1001a697` | `83 c7 04` | `ADD EDI,0x4` |
| `1001a69a` | `03 f3` | `ADD ESI,EBX` |
| `1001a69c` | `80 3e 00` | `CMP byte ptr [ESI],0x0` |
| `1001a69f` | `75 b9` | `JNZ 0x1001a65a` |
| `1001a6a1` | `ff 35 74 8a 03 10` | `PUSH dword ptr [0x10038a74]` |
| `1001a6a7` | `e8 95 6b ff ff` | `CALL 0x10011241` |
| `1001a6ac` | `83 25 74 8a 03 10 00` | `AND dword ptr [0x10038a74],0x0` |
| `1001a6b3` | `83 27 00` | `AND dword ptr [EDI],0x0` |
| `1001a6b6` | `c7 05 8c a6 43 13 01 00 00 00` | `MOV dword ptr [0x1343a68c],0x1` |
| `1001a6c0` | `33 c0` | `XOR EAX,EAX` |
| `1001a6c2` | `59` | `POP ECX` |
| `1001a6c3` | `5b` | `POP EBX` |
| `1001a6c4` | `5f` | `POP EDI` |
| `1001a6c5` | `5e` | `POP ESI` |
| `1001a6c6` | `c3` | `RET` |
| `1001a6c7` | `ff 35 4c 8a 03 10` | `PUSH dword ptr [0x10038a4c]` |
| `1001a6cd` | `e8 6f 6b ff ff` | `CALL 0x10011241` |
| `1001a6d2` | `83 25 4c 8a 03 10 00` | `AND dword ptr [0x10038a4c],0x0` |
| `1001a6d9` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a6dc` | `eb e4` | `JMP 0x1001a6c2` |
