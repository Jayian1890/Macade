# 1001533d `write_char`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001533d |
| `name` | write_char |
| `namespace` | Global |
| `signature` | undefined __cdecl write_char(void) |
| `size_bytes` | 51 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _write_char, write_char |

## Decompiled C

```c

/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 2008 Release */

void __cdecl write_char(void)

{
  int *piVar1;
  byte in_AL;
  uint uVar2;
  FILE *in_ECX;
  int *unaff_ESI;
  
  if (((in_ECX->_flag & 0x40) == 0) || (in_ECX->_base != (char *)0x0)) {
    piVar1 = &in_ECX->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = __flsbuf((int)(char)in_AL,in_ECX);
    }
    else {
      *in_ECX->_ptr = in_AL;
      in_ECX->_ptr = in_ECX->_ptr + 1;
      uVar2 = (uint)in_AL;
    }
    if (uVar2 == 0xffffffff) {
      *unaff_ESI = -1;
      return;
    }
  }
  *unaff_ESI = *unaff_ESI + 1;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001535e` | `10015152` | `UNCONDITIONAL_CALL` | __flsbuf | `10015152` |

## Callers

| From | Function |
| --- | --- |
| `10015794` | __output_l |
| `100157b6` | __output_l |
| `10015383` | write_multi_char |
| `100153bb` | write_string |
| `100153d4` | write_string |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001533d` | `f6 41 0c 40` | `TEST byte ptr [ECX + 0xc],0x40` |
| `10015341` | `74 06` | `JZ 0x10015349` |
| `10015343` | `83 79 08 00` | `CMP dword ptr [ECX + 0x8],0x0` |
| `10015347` | `74 24` | `JZ 0x1001536d` |
| `10015349` | `ff 49 04` | `DEC dword ptr [ECX + 0x4]` |
| `1001534c` | `78 0b` | `JS 0x10015359` |
| `1001534e` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `10015350` | `88 02` | `MOV byte ptr [EDX],AL` |
| `10015352` | `ff 01` | `INC dword ptr [ECX]` |
| `10015354` | `0f b6 c0` | `MOVZX EAX,AL` |
| `10015357` | `eb 0c` | `JMP 0x10015365` |
| `10015359` | `0f be c0` | `MOVSX EAX,AL` |
| `1001535c` | `51` | `PUSH ECX` |
| `1001535d` | `50` | `PUSH EAX` |
| `1001535e` | `e8 ef fd ff ff` | `CALL 0x10015152` |
| `10015363` | `59` | `POP ECX` |
| `10015364` | `59` | `POP ECX` |
| `10015365` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10015368` | `75 03` | `JNZ 0x1001536d` |
| `1001536a` | `09 06` | `OR dword ptr [ESI],EAX` |
| `1001536c` | `c3` | `RET` |
| `1001536d` | `ff 06` | `INC dword ptr [ESI]` |
| `1001536f` | `c3` | `RET` |
