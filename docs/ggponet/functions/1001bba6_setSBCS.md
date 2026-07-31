# 1001bba6 `setSBCS`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001bba6 |
| `name` | setSBCS |
| `namespace` | Global |
| `signature` | void __cdecl setSBCS(threadmbcinfostruct * param_1) |
| `size_bytes` | 100 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?setSBCS@@YAXPAUthreadmbcinfostruct@@@Z, setSBCS |

## Decompiled C

```c

/* Library Function - Single Match
    void __cdecl setSBCS(struct threadmbcinfostruct *)
   
   Library: Visual Studio 2008 Release */

void __cdecl setSBCS(threadmbcinfostruct *param_1)

{
  int in_EAX;
  undefined1 *puVar1;
  int iVar2;
  
  _memset((void *)(in_EAX + 0x1c),0,0x101);
  *(undefined4 *)(in_EAX + 4) = 0;
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  puVar1 = (undefined1 *)(in_EAX + 0x1c);
  iVar2 = 0x101;
  do {
    *puVar1 = puVar1[(int)&DAT_10037c20 - in_EAX];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined1 *)(in_EAX + 0x11d);
  iVar2 = 0x100;
  do {
    *puVar1 = puVar1[(int)&DAT_10037c20 - in_EAX];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001bbb8` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |

## Callers

| From | Function |
| --- | --- |
| `1001beea` | __setmbcp_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001bbd8` | `10037c20` | `DATA` | DAT_10037c20 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001bba6` | `8b ff` | `MOV EDI,EDI` |
| `1001bba8` | `56` | `PUSH ESI` |
| `1001bba9` | `57` | `PUSH EDI` |
| `1001bbaa` | `8b f0` | `MOV ESI,EAX` |
| `1001bbac` | `68 01 01 00 00` | `PUSH 0x101` |
| `1001bbb1` | `33 ff` | `XOR EDI,EDI` |
| `1001bbb3` | `8d 46 1c` | `LEA EAX,[ESI + 0x1c]` |
| `1001bbb6` | `57` | `PUSH EDI` |
| `1001bbb7` | `50` | `PUSH EAX` |
| `1001bbb8` | `e8 33 5b ff ff` | `CALL 0x100116f0` |
| `1001bbbd` | `33 c0` | `XOR EAX,EAX` |
| `1001bbbf` | `0f b7 c8` | `MOVZX ECX,AX` |
| `1001bbc2` | `8b c1` | `MOV EAX,ECX` |
| `1001bbc4` | `89 7e 04` | `MOV dword ptr [ESI + 0x4],EDI` |
| `1001bbc7` | `89 7e 08` | `MOV dword ptr [ESI + 0x8],EDI` |
| `1001bbca` | `89 7e 0c` | `MOV dword ptr [ESI + 0xc],EDI` |
| `1001bbcd` | `c1 e1 10` | `SHL ECX,0x10` |
| `1001bbd0` | `0b c1` | `OR EAX,ECX` |
| `1001bbd2` | `8d 7e 10` | `LEA EDI,[ESI + 0x10]` |
| `1001bbd5` | `ab` | `STOSD ES:EDI` |
| `1001bbd6` | `ab` | `STOSD ES:EDI` |
| `1001bbd7` | `ab` | `STOSD ES:EDI` |
| `1001bbd8` | `b9 20 7c 03 10` | `MOV ECX,0x10037c20` |
| `1001bbdd` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001bbe0` | `8d 46 1c` | `LEA EAX,[ESI + 0x1c]` |
| `1001bbe3` | `2b ce` | `SUB ECX,ESI` |
| `1001bbe5` | `bf 01 01 00 00` | `MOV EDI,0x101` |
| `1001bbea` | `8a 14 01` | `MOV DL,byte ptr [ECX + EAX*0x1]` |
| `1001bbed` | `88 10` | `MOV byte ptr [EAX],DL` |
| `1001bbef` | `40` | `INC EAX` |
| `1001bbf0` | `4f` | `DEC EDI` |
| `1001bbf1` | `75 f7` | `JNZ 0x1001bbea` |
| `1001bbf3` | `8d 86 1d 01 00 00` | `LEA EAX,[ESI + 0x11d]` |
| `1001bbf9` | `be 00 01 00 00` | `MOV ESI,0x100` |
| `1001bbfe` | `8a 14 08` | `MOV DL,byte ptr [EAX + ECX*0x1]` |
| `1001bc01` | `88 10` | `MOV byte ptr [EAX],DL` |
| `1001bc03` | `40` | `INC EAX` |
| `1001bc04` | `4e` | `DEC ESI` |
| `1001bc05` | `75 f7` | `JNZ 0x1001bbfe` |
| `1001bc07` | `5f` | `POP EDI` |
| `1001bc08` | `5e` | `POP ESI` |
| `1001bc09` | `c3` | `RET` |
