# 10012ccb `__getenv_helper_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012ccb |
| `name` | __getenv_helper_nolock |
| `namespace` | Global |
| `signature` | char * __cdecl __getenv_helper_nolock(char * param_1) |
| `size_bytes` | 135 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __getenv_helper_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __getenv_helper_nolock
   
   Library: Visual Studio 2008 Release */

char * __cdecl __getenv_helper_nolock(char *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_1343a68c != 0) &&
      ((DAT_10038a4c != (int *)0x0 ||
       (((DAT_10038a54 != 0 && (iVar1 = ___wtomb_environ(), iVar1 == 0)) &&
        (DAT_10038a4c != (int *)0x0)))))) && (piVar3 = DAT_10038a4c, param_1 != (char *)0x0)) {
    _MaxCount = _strlen(param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,(uchar *)param_1,_MaxCount), iVar1 == 0)) {
        return (char *)(*piVar3 + 1 + _MaxCount);
      }
    }
  }
  return (char *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10012cf1` | `10019b2b` | `UNCONDITIONAL_CALL` | ___wtomb_environ | `10019b2b` |
| `10012d0d` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `10012d18` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `10012d2f` | `10019b11` | `UNCONDITIONAL_CALL` | __mbsnbicoll | `10019b11` |

## Callers

| From | Function |
| --- | --- |
| `10012dae` | _getenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012cd0` | `1343a68c` | `READ` | DAT_1343a68c |
| `10012cd8` | `10038a4c` | `READ` | DAT_10038a4c |
| `10012ce9` | `10038a54` | `READ` | DAT_10038a54 |
| `10012cfa` | `10038a4c` | `READ` | DAT_10038a4c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012ccb` | `8b ff` | `MOV EDI,EDI` |
| `10012ccd` | `55` | `PUSH EBP` |
| `10012cce` | `8b ec` | `MOV EBP,ESP` |
| `10012cd0` | `83 3d 8c a6 43 13 00` | `CMP dword ptr [0x1343a68c],0x0` |
| `10012cd7` | `56` | `PUSH ESI` |
| `10012cd8` | `8b 35 4c 8a 03 10` | `MOV ESI,dword ptr [0x10038a4c]` |
| `10012cde` | `75 04` | `JNZ 0x10012ce4` |
| `10012ce0` | `33 c0` | `XOR EAX,EAX` |
| `10012ce2` | `eb 63` | `JMP 0x10012d47` |
| `10012ce4` | `57` | `PUSH EDI` |
| `10012ce5` | `85 f6` | `TEST ESI,ESI` |
| `10012ce7` | `75 1b` | `JNZ 0x10012d04` |
| `10012ce9` | `39 35 54 8a 03 10` | `CMP dword ptr [0x10038a54],ESI` |
| `10012cef` | `74 53` | `JZ 0x10012d44` |
| `10012cf1` | `e8 35 6e 00 00` | `CALL 0x10019b2b` |
| `10012cf6` | `85 c0` | `TEST EAX,EAX` |
| `10012cf8` | `75 4a` | `JNZ 0x10012d44` |
| `10012cfa` | `8b 35 4c 8a 03 10` | `MOV ESI,dword ptr [0x10038a4c]` |
| `10012d00` | `85 f6` | `TEST ESI,ESI` |
| `10012d02` | `74 40` | `JZ 0x10012d44` |
| `10012d04` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10012d08` | `74 3a` | `JZ 0x10012d44` |
| `10012d0a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10012d0d` | `e8 de e6 ff ff` | `CALL 0x100113f0` |
| `10012d12` | `59` | `POP ECX` |
| `10012d13` | `8b f8` | `MOV EDI,EAX` |
| `10012d15` | `eb 27` | `JMP 0x10012d3e` |
| `10012d17` | `50` | `PUSH EAX` |
| `10012d18` | `e8 d3 e6 ff ff` | `CALL 0x100113f0` |
| `10012d1d` | `59` | `POP ECX` |
| `10012d1e` | `3b c7` | `CMP EAX,EDI` |
| `10012d20` | `76 19` | `JBE 0x10012d3b` |
| `10012d22` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10012d24` | `80 3c 38 3d` | `CMP byte ptr [EAX + EDI*0x1],0x3d` |
| `10012d28` | `75 11` | `JNZ 0x10012d3b` |
| `10012d2a` | `57` | `PUSH EDI` |
| `10012d2b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10012d2e` | `50` | `PUSH EAX` |
| `10012d2f` | `e8 dd 6d 00 00` | `CALL 0x10019b11` |
| `10012d34` | `83 c4 0c` | `ADD ESP,0xc` |
| `10012d37` | `85 c0` | `TEST EAX,EAX` |
| `10012d39` | `74 0f` | `JZ 0x10012d4a` |
| `10012d3b` | `83 c6 04` | `ADD ESI,0x4` |
| `10012d3e` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10012d40` | `85 c0` | `TEST EAX,EAX` |
| `10012d42` | `75 d3` | `JNZ 0x10012d17` |
| `10012d44` | `33 c0` | `XOR EAX,EAX` |
| `10012d46` | `5f` | `POP EDI` |
| `10012d47` | `5e` | `POP ESI` |
| `10012d48` | `5d` | `POP EBP` |
| `10012d49` | `c3` | `RET` |
| `10012d4a` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10012d4c` | `8d 44 38 01` | `LEA EAX,[EAX + EDI*0x1 + 0x1]` |
| `10012d50` | `eb f4` | `JMP 0x10012d46` |
