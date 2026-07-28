# 1002aca0 `_strrchr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002aca0 |
| `name` | _strrchr |
| `namespace` | Global |
| `signature` | char * __cdecl _strrchr(char * _Str, int _Ch) |
| `size_bytes` | 45 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strrchr |

## Decompiled C

```c

/* Library Function - Single Match
    _strrchr
   
   Library: Visual Studio 2008 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002a640` | __cftoa_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002aca0` | `55` | `PUSH EBP` |
| `1002aca1` | `8b ec` | `MOV EBP,ESP` |
| `1002aca3` | `57` | `PUSH EDI` |
| `1002aca4` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1002aca7` | `33 c0` | `XOR EAX,EAX` |
| `1002aca9` | `83 c9 ff` | `OR ECX,0xffffffff` |
| `1002acac` | `f2 ae` | `SCASB.REPNE ES:EDI` |
| `1002acae` | `83 c1 01` | `ADD ECX,0x1` |
| `1002acb1` | `f7 d9` | `NEG ECX` |
| `1002acb3` | `83 ef 01` | `SUB EDI,0x1` |
| `1002acb6` | `8a 45 0c` | `MOV AL,byte ptr [EBP + 0xc]` |
| `1002acb9` | `fd` | `STD` |
| `1002acba` | `f2 ae` | `SCASB.REPNE ES:EDI` |
| `1002acbc` | `83 c7 01` | `ADD EDI,0x1` |
| `1002acbf` | `38 07` | `CMP byte ptr [EDI],AL` |
| `1002acc1` | `74 04` | `JZ 0x1002acc7` |
| `1002acc3` | `33 c0` | `XOR EAX,EAX` |
| `1002acc5` | `eb 02` | `JMP 0x1002acc9` |
| `1002acc7` | `8b c7` | `MOV EAX,EDI` |
| `1002acc9` | `fc` | `CLD` |
| `1002acca` | `5f` | `POP EDI` |
| `1002accb` | `c9` | `LEAVE` |
| `1002accc` | `c3` | `RET` |
