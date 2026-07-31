# 10015396 `write_string`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10015396 |
| `name` | write_string |
| `namespace` | Global |
| `signature` | undefined __cdecl write_string(void) |
| `size_bytes` | 77 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _write_string, write_string |

## Decompiled C

```c

/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 2008 Release */

void __cdecl write_string(int param_1)

{
  int *in_EAX;
  int *piVar1;
  int unaff_EDI;
  
  if (((*(byte *)(unaff_EDI + 0xc) & 0x40) == 0) || (*(int *)(unaff_EDI + 8) != 0)) {
    while (0 < param_1) {
      param_1 = param_1 + -1;
      write_char();
      if (*in_EAX == -1) {
        piVar1 = __errno();
        if (*piVar1 != 0x2a) {
          return;
        }
        write_char();
      }
    }
  }
  else {
    *in_EAX = *in_EAX + param_1;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100153bb` | `1001533d` | `UNCONDITIONAL_CALL` | write_char | `1001533d` |
| `100153c6` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100153d4` | `1001533d` | `UNCONDITIONAL_CALL` | write_char | `1001533d` |

## Callers

| From | Function |
| --- | --- |
| `10015e1b` | __output_l |
| `10015ea0` | __output_l |
| `10015ec7` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10015396` | `8b ff` | `MOV EDI,EDI` |
| `10015398` | `55` | `PUSH EBP` |
| `10015399` | `8b ec` | `MOV EBP,ESP` |
| `1001539b` | `f6 47 0c 40` | `TEST byte ptr [EDI + 0xc],0x40` |
| `1001539f` | `53` | `PUSH EBX` |
| `100153a0` | `56` | `PUSH ESI` |
| `100153a1` | `8b f0` | `MOV ESI,EAX` |
| `100153a3` | `8b d9` | `MOV EBX,ECX` |
| `100153a5` | `74 32` | `JZ 0x100153d9` |
| `100153a7` | `83 7f 08 00` | `CMP dword ptr [EDI + 0x8],0x0` |
| `100153ab` | `75 2c` | `JNZ 0x100153d9` |
| `100153ad` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100153b0` | `01 06` | `ADD dword ptr [ESI],EAX` |
| `100153b2` | `eb 2b` | `JMP 0x100153df` |
| `100153b4` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `100153b6` | `ff 4d 08` | `DEC dword ptr [EBP + 0x8]` |
| `100153b9` | `8b cf` | `MOV ECX,EDI` |
| `100153bb` | `e8 7d ff ff ff` | `CALL 0x1001533d` |
| `100153c0` | `43` | `INC EBX` |
| `100153c1` | `83 3e ff` | `CMP dword ptr [ESI],-0x1` |
| `100153c4` | `75 13` | `JNZ 0x100153d9` |
| `100153c6` | `e8 3e fd ff ff` | `CALL 0x10015109` |
| `100153cb` | `83 38 2a` | `CMP dword ptr [EAX],0x2a` |
| `100153ce` | `75 0f` | `JNZ 0x100153df` |
| `100153d0` | `8b cf` | `MOV ECX,EDI` |
| `100153d2` | `b0 3f` | `MOV AL,0x3f` |
| `100153d4` | `e8 64 ff ff ff` | `CALL 0x1001533d` |
| `100153d9` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `100153dd` | `7f d5` | `JG 0x100153b4` |
| `100153df` | `5e` | `POP ESI` |
| `100153e0` | `5b` | `POP EBX` |
| `100153e1` | `5d` | `POP EBP` |
| `100153e2` | `c3` | `RET` |
