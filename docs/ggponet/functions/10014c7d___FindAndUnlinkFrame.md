# 10014c7d `__FindAndUnlinkFrame`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014c7d |
| `name` | __FindAndUnlinkFrame |
| `namespace` | Global |
| `signature` | undefined __FindAndUnlinkFrame(void) |
| `size_bytes` | 82 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __FindAndUnlinkFrame |

## Decompiled C

```c

/* Library Function - Single Match
    __FindAndUnlinkFrame
   
   Library: Visual Studio 2008 Release */

void __FindAndUnlinkFrame(void *param_1)

{
  void *pvVar1;
  _ptiddata p_Var2;
  void *pvVar3;
  
  p_Var2 = __getptd();
  if (param_1 == p_Var2->_pFrameInfoChain) {
    p_Var2 = __getptd();
    p_Var2->_pFrameInfoChain = *(void **)((int)param_1 + 4);
  }
  else {
    p_Var2 = __getptd();
    pvVar1 = p_Var2->_pFrameInfoChain;
    do {
      pvVar3 = pvVar1;
      if (*(int *)((int)pvVar3 + 4) == 0) {
        _inconsistency();
        return;
      }
      pvVar1 = *(void **)((int)pvVar3 + 4);
    } while (param_1 != *(void **)((int)pvVar3 + 4));
    *(undefined4 *)((int)pvVar3 + 4) = *(undefined4 *)((int)param_1 + 4);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014c83` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `10014c93` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `10014ca4` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `10014cc2` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |

## Callers

| From | Function |
| --- | --- |
| `1001b0ad` | FUN_1001b0a4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014c7d` | `8b ff` | `MOV EDI,EDI` |
| `10014c7f` | `55` | `PUSH EBP` |
| `10014c80` | `8b ec` | `MOV EBP,ESP` |
| `10014c82` | `56` | `PUSH ESI` |
| `10014c83` | `e8 4e 27 00 00` | `CALL 0x100173d6` |
| `10014c88` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10014c8b` | `3b b0 98 00 00 00` | `CMP ESI,dword ptr [EAX + 0x98]` |
| `10014c91` | `75 11` | `JNZ 0x10014ca4` |
| `10014c93` | `e8 3e 27 00 00` | `CALL 0x100173d6` |
| `10014c98` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `10014c9b` | `89 88 98 00 00 00` | `MOV dword ptr [EAX + 0x98],ECX` |
| `10014ca1` | `5e` | `POP ESI` |
| `10014ca2` | `5d` | `POP EBP` |
| `10014ca3` | `c3` | `RET` |
| `10014ca4` | `e8 2d 27 00 00` | `CALL 0x100173d6` |
| `10014ca9` | `8b 80 98 00 00 00` | `MOV EAX,dword ptr [EAX + 0x98]` |
| `10014caf` | `eb 09` | `JMP 0x10014cba` |
| `10014cb1` | `8b 48 04` | `MOV ECX,dword ptr [EAX + 0x4]` |
| `10014cb4` | `3b f1` | `CMP ESI,ECX` |
| `10014cb6` | `74 0f` | `JZ 0x10014cc7` |
| `10014cb8` | `8b c1` | `MOV EAX,ECX` |
| `10014cba` | `83 78 04 00` | `CMP dword ptr [EAX + 0x4],0x0` |
| `10014cbe` | `75 f1` | `JNZ 0x10014cb1` |
| `10014cc0` | `5e` | `POP ESI` |
| `10014cc1` | `5d` | `POP EBP` |
| `10014cc2` | `e9 32 48 00 00` | `JMP 0x100194f9` |
| `10014cc7` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `10014cca` | `89 48 04` | `MOV dword ptr [EAX + 0x4],ECX` |
| `10014ccd` | `eb d2` | `JMP 0x10014ca1` |
