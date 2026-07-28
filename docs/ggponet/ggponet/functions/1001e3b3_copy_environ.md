# 1001e3b3 `copy_environ`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e3b3 |
| `name` | copy_environ |
| `namespace` | Global |
| `signature` | undefined __cdecl copy_environ(void) |
| `size_bytes` | 90 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _copy_environ, copy_environ |

## Decompiled C

```c

/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 2008 Release */

undefined4 * __cdecl copy_environ(void)

{
  int iVar1;
  int *in_EAX;
  undefined4 *puVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  puVar2 = (undefined4 *)0x0;
  if (in_EAX != (int *)0x0) {
    iVar1 = *in_EAX;
    piVar4 = in_EAX;
    while (iVar1 != 0) {
      piVar4 = piVar4 + 1;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      iVar1 = *piVar4;
    }
    puVar2 = __calloc_crt((int)puVar2 + 1,4);
    puVar5 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    for (; (char *)*in_EAX != (char *)0x0; in_EAX = in_EAX + 1) {
      pcVar3 = __strdup((char *)*in_EAX);
      *puVar5 = pcVar3;
      puVar5 = puVar5 + 1;
    }
    *puVar5 = 0;
  }
  return puVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e3d6` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001e3e8` | `1001243c` | `UNCONDITIONAL_CALL` | __amsg_exit | `1001243c` |
| `1001e3f0` | `1001f9b9` | `UNCONDITIONAL_CALL` | __strdup | `1001f9b9` |

## Callers

| From | Function |
| --- | --- |
| `1001e479` | ___crtsetenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e3b3` | `8b ff` | `MOV EDI,EDI` |
| `1001e3b5` | `55` | `PUSH EBP` |
| `1001e3b6` | `8b ec` | `MOV EBP,ESP` |
| `1001e3b8` | `51` | `PUSH ECX` |
| `1001e3b9` | `57` | `PUSH EDI` |
| `1001e3ba` | `8b f8` | `MOV EDI,EAX` |
| `1001e3bc` | `33 c0` | `XOR EAX,EAX` |
| `1001e3be` | `8b cf` | `MOV ECX,EDI` |
| `1001e3c0` | `85 ff` | `TEST EDI,EDI` |
| `1001e3c2` | `74 46` | `JZ 0x1001e40a` |
| `1001e3c4` | `39 07` | `CMP dword ptr [EDI],EAX` |
| `1001e3c6` | `74 09` | `JZ 0x1001e3d1` |
| `1001e3c8` | `83 c1 04` | `ADD ECX,0x4` |
| `1001e3cb` | `40` | `INC EAX` |
| `1001e3cc` | `83 39 00` | `CMP dword ptr [ECX],0x0` |
| `1001e3cf` | `75 f7` | `JNZ 0x1001e3c8` |
| `1001e3d1` | `56` | `PUSH ESI` |
| `1001e3d2` | `40` | `INC EAX` |
| `1001e3d3` | `6a 04` | `PUSH 0x4` |
| `1001e3d5` | `50` | `PUSH EAX` |
| `1001e3d6` | `e8 39 c1 ff ff` | `CALL 0x1001a514` |
| `1001e3db` | `8b f0` | `MOV ESI,EAX` |
| `1001e3dd` | `59` | `POP ECX` |
| `1001e3de` | `59` | `POP ECX` |
| `1001e3df` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `1001e3e2` | `85 f6` | `TEST ESI,ESI` |
| `1001e3e4` | `75 18` | `JNZ 0x1001e3fe` |
| `1001e3e6` | `6a 09` | `PUSH 0x9` |
| `1001e3e8` | `e8 4f 40 ff ff` | `CALL 0x1001243c` |
| `1001e3ed` | `eb 0e` | `JMP 0x1001e3fd` |
| `1001e3ef` | `50` | `PUSH EAX` |
| `1001e3f0` | `e8 c4 15 00 00` | `CALL 0x1001f9b9` |
| `1001e3f5` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001e3f7` | `83 c6 04` | `ADD ESI,0x4` |
| `1001e3fa` | `83 c7 04` | `ADD EDI,0x4` |
| `1001e3fd` | `59` | `POP ECX` |
| `1001e3fe` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001e400` | `85 c0` | `TEST EAX,EAX` |
| `1001e402` | `75 eb` | `JNZ 0x1001e3ef` |
| `1001e404` | `21 06` | `AND dword ptr [ESI],EAX` |
| `1001e406` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1001e409` | `5e` | `POP ESI` |
| `1001e40a` | `5f` | `POP EDI` |
| `1001e40b` | `c9` | `LEAVE` |
| `1001e40c` | `c3` | `RET` |
