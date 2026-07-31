# 100124d7 `__initterm_e`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100124d7 |
| `name` | __initterm_e |
| `namespace` | Global |
| `signature` | undefined __initterm_e(void) |
| `size_bytes` | 36 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __initterm_e |

## Decompiled C

```c

/* Library Function - Single Match
    __initterm_e
   
   Library: Visual Studio 2008 Release */

void __initterm_e(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while ((param_1 < param_2 && (iVar1 == 0))) {
    if ((code *)*param_1 != (code *)0x0) {
      iVar1 = (*(code *)*param_1)();
    }
    param_1 = param_1 + 1;
  }
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10012531` | __cinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100124d7` | `8b ff` | `MOV EDI,EDI` |
| `100124d9` | `55` | `PUSH EBP` |
| `100124da` | `8b ec` | `MOV EBP,ESP` |
| `100124dc` | `56` | `PUSH ESI` |
| `100124dd` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `100124e0` | `33 c0` | `XOR EAX,EAX` |
| `100124e2` | `eb 0f` | `JMP 0x100124f3` |
| `100124e4` | `85 c0` | `TEST EAX,EAX` |
| `100124e6` | `75 10` | `JNZ 0x100124f8` |
| `100124e8` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `100124ea` | `85 c9` | `TEST ECX,ECX` |
| `100124ec` | `74 02` | `JZ 0x100124f0` |
| `100124ee` | `ff d1` | `CALL ECX` |
| `100124f0` | `83 c6 04` | `ADD ESI,0x4` |
| `100124f3` | `3b 75 0c` | `CMP ESI,dword ptr [EBP + 0xc]` |
| `100124f6` | `72 ec` | `JC 0x100124e4` |
| `100124f8` | `5e` | `POP ESI` |
| `100124f9` | `5d` | `POP EBP` |
| `100124fa` | `c3` | `RET` |
