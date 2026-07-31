# 100124ba `__initterm`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100124ba |
| `name` | __initterm |
| `namespace` | Global |
| `signature` | undefined __initterm(void) |
| `size_bytes` | 29 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __initterm |

## Decompiled C

```c

/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 2008 Release */

void __initterm(undefined4 *param_1)

{
  undefined4 *in_EAX;
  
  for (; in_EAX < param_1; in_EAX = in_EAX + 1) {
    if ((code *)*in_EAX != (code *)0x0) {
      (*(code *)*in_EAX)();
    }
  }
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10012552` | __cinit |
| `10012656` | doexit |
| `10012666` | doexit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100124ba` | `8b ff` | `MOV EDI,EDI` |
| `100124bc` | `55` | `PUSH EBP` |
| `100124bd` | `8b ec` | `MOV EBP,ESP` |
| `100124bf` | `56` | `PUSH ESI` |
| `100124c0` | `8b f0` | `MOV ESI,EAX` |
| `100124c2` | `eb 0b` | `JMP 0x100124cf` |
| `100124c4` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `100124c6` | `85 c0` | `TEST EAX,EAX` |
| `100124c8` | `74 02` | `JZ 0x100124cc` |
| `100124ca` | `ff d0` | `CALL EAX` |
| `100124cc` | `83 c6 04` | `ADD ESI,0x4` |
| `100124cf` | `3b 75 08` | `CMP ESI,dword ptr [EBP + 0x8]` |
| `100124d2` | `72 f0` | `JC 0x100124c4` |
| `100124d4` | `5e` | `POP ESI` |
| `100124d5` | `5d` | `POP EBP` |
| `100124d6` | `c3` | `RET` |
