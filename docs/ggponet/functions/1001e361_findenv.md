# 1001e361 `findenv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e361 |
| `name` | findenv |
| `namespace` | Global |
| `signature` | undefined __cdecl findenv(void) |
| `size_bytes` | 82 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _findenv, findenv |

## Decompiled C

```c

/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 2008 Release */

int __cdecl findenv(uchar *param_1)

{
  int iVar1;
  int *piVar2;
  size_t unaff_EDI;
  
  piVar2 = DAT_10038a4c;
  while( true ) {
    if ((uchar *)*piVar2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_10038a4c >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*piVar2,unaff_EDI);
    if ((iVar1 == 0) &&
       ((*(char *)(unaff_EDI + *piVar2) == '=' || (*(char *)(unaff_EDI + *piVar2) == '\0')))) break;
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_10038a4c >> 2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e374` | `10019b11` | `UNCONDITIONAL_CALL` | __mbsnbicoll | `10019b11` |

## Callers

| From | Function |
| --- | --- |
| `1001e4fa` | ___crtsetenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001e367` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001e398` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001e3a8` | `10038a4c` | `READ` | DAT_10038a4c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e361` | `8b ff` | `MOV EDI,EDI` |
| `1001e363` | `55` | `PUSH EBP` |
| `1001e364` | `8b ec` | `MOV EBP,ESP` |
| `1001e366` | `56` | `PUSH ESI` |
| `1001e367` | `8b 35 4c 8a 03 10` | `MOV ESI,dword ptr [0x10038a4c]` |
| `1001e36d` | `eb 21` | `JMP 0x1001e390` |
| `1001e36f` | `57` | `PUSH EDI` |
| `1001e370` | `50` | `PUSH EAX` |
| `1001e371` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e374` | `e8 98 b7 ff ff` | `CALL 0x10019b11` |
| `1001e379` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001e37c` | `85 c0` | `TEST EAX,EAX` |
| `1001e37e` | `75 0d` | `JNZ 0x1001e38d` |
| `1001e380` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001e382` | `8a 04 07` | `MOV AL,byte ptr [EDI + EAX*0x1]` |
| `1001e385` | `3c 3d` | `CMP AL,0x3d` |
| `1001e387` | `74 1d` | `JZ 0x1001e3a6` |
| `1001e389` | `84 c0` | `TEST AL,AL` |
| `1001e38b` | `74 19` | `JZ 0x1001e3a6` |
| `1001e38d` | `83 c6 04` | `ADD ESI,0x4` |
| `1001e390` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001e392` | `85 c0` | `TEST EAX,EAX` |
| `1001e394` | `75 d9` | `JNZ 0x1001e36f` |
| `1001e396` | `8b c6` | `MOV EAX,ESI` |
| `1001e398` | `2b 05 4c 8a 03 10` | `SUB EAX,dword ptr [0x10038a4c]` |
| `1001e39e` | `c1 f8 02` | `SAR EAX,0x2` |
| `1001e3a1` | `f7 d8` | `NEG EAX` |
| `1001e3a3` | `5e` | `POP ESI` |
| `1001e3a4` | `5d` | `POP EBP` |
| `1001e3a5` | `c3` | `RET` |
| `1001e3a6` | `8b c6` | `MOV EAX,ESI` |
| `1001e3a8` | `2b 05 4c 8a 03 10` | `SUB EAX,dword ptr [0x10038a4c]` |
| `1001e3ae` | `c1 f8 02` | `SAR EAX,0x2` |
| `1001e3b1` | `eb f0` | `JMP 0x1001e3a3` |
