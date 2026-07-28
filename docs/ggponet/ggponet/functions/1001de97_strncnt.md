# 1001de97 `strncnt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001de97 |
| `name` | strncnt |
| `namespace` | Global |
| `signature` | int __cdecl strncnt(char * param_1, int param_2) |
| `size_bytes` | 30 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?strncnt@@YAHPBDH@Z, strncnt |

## Decompiled C

```c

/* Library Function - Single Match
    int __cdecl strncnt(char const *,int)
   
   Library: Visual Studio 2008 Release */

int __cdecl strncnt(char *param_1,int param_2)

{
  char *in_EAX;
  char *pcVar1;
  
  pcVar1 = param_1;
  for (; (pcVar1 != (char *)0x0 && (*in_EAX != '\0')); in_EAX = in_EAX + 1) {
    pcVar1 = pcVar1 + -1;
  }
  return (int)(param_1 + (-1 - (int)(pcVar1 + -1)));
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001df23` | __crtCompareStringA_stat |
| `1001df37` | __crtCompareStringA_stat |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001de97` | `8b ff` | `MOV EDI,EDI` |
| `1001de99` | `55` | `PUSH EBP` |
| `1001de9a` | `8b ec` | `MOV EBP,ESP` |
| `1001de9c` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001de9f` | `eb 07` | `JMP 0x1001dea8` |
| `1001dea1` | `49` | `DEC ECX` |
| `1001dea2` | `80 38 00` | `CMP byte ptr [EAX],0x0` |
| `1001dea5` | `74 06` | `JZ 0x1001dead` |
| `1001dea7` | `40` | `INC EAX` |
| `1001dea8` | `85 c9` | `TEST ECX,ECX` |
| `1001deaa` | `75 f5` | `JNZ 0x1001dea1` |
| `1001deac` | `49` | `DEC ECX` |
| `1001dead` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001deb0` | `2b c1` | `SUB EAX,ECX` |
| `1001deb2` | `48` | `DEC EAX` |
| `1001deb3` | `5d` | `POP EBP` |
| `1001deb4` | `c3` | `RET` |
