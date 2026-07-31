# 10015370 `write_multi_char`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10015370 |
| `name` | write_multi_char |
| `namespace` | Global |
| `signature` | undefined __cdecl write_multi_char(void) |
| `size_bytes` | 38 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _write_multi_char, write_multi_char |

## Decompiled C

```c

/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 2008 Release */

void __cdecl write_multi_char(undefined4 param_1,int param_2)

{
  int *in_EAX;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    write_char();
  } while (*in_EAX != -1);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10015383` | `1001533d` | `UNCONDITIONAL_CALL` | write_char | `1001533d` |

## Callers

| From | Function |
| --- | --- |
| `10015dfb` | __output_l |
| `10015e3d` | __output_l |
| `10015ee9` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10015370` | `8b ff` | `MOV EDI,EDI` |
| `10015372` | `55` | `PUSH EBP` |
| `10015373` | `8b ec` | `MOV EBP,ESP` |
| `10015375` | `56` | `PUSH ESI` |
| `10015376` | `8b f0` | `MOV ESI,EAX` |
| `10015378` | `eb 13` | `JMP 0x1001538d` |
| `1001537a` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001537d` | `8a 45 08` | `MOV AL,byte ptr [EBP + 0x8]` |
| `10015380` | `ff 4d 0c` | `DEC dword ptr [EBP + 0xc]` |
| `10015383` | `e8 b5 ff ff ff` | `CALL 0x1001533d` |
| `10015388` | `83 3e ff` | `CMP dword ptr [ESI],-0x1` |
| `1001538b` | `74 06` | `JZ 0x10015393` |
| `1001538d` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `10015391` | `7f e7` | `JG 0x1001537a` |
| `10015393` | `5e` | `POP ESI` |
| `10015394` | `5d` | `POP EBP` |
| `10015395` | `c3` | `RET` |
