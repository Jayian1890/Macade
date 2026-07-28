# 1001f133 `___free_lconv_mon`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f133 |
| `name` | ___free_lconv_mon |
| `namespace` | Global |
| `signature` | undefined ___free_lconv_mon(void) |
| `size_bytes` | 142 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___free_lconv_mon |

## Decompiled C

```c

/* Library Function - Single Match
    ___free_lconv_mon
   
   Library: Visual Studio 2008 Release */

void ___free_lconv_mon(int param_1)

{
  if (param_1 != 0) {
    if (*(undefined **)(param_1 + 0xc) != PTR_DAT_10038334) {
      _free(*(undefined **)(param_1 + 0xc));
    }
    if (*(undefined **)(param_1 + 0x10) != PTR_DAT_10038338) {
      _free(*(undefined **)(param_1 + 0x10));
    }
    if (*(undefined **)(param_1 + 0x14) != PTR_DAT_1003833c) {
      _free(*(undefined **)(param_1 + 0x14));
    }
    if (*(undefined **)(param_1 + 0x18) != PTR_DAT_10038340) {
      _free(*(undefined **)(param_1 + 0x18));
    }
    if (*(undefined **)(param_1 + 0x1c) != PTR_DAT_10038344) {
      _free(*(undefined **)(param_1 + 0x1c));
    }
    if (*(undefined **)(param_1 + 0x20) != PTR_DAT_10038348) {
      _free(*(undefined **)(param_1 + 0x20));
    }
    if (*(undefined **)(param_1 + 0x24) != PTR_DAT_1003834c) {
      _free(*(undefined **)(param_1 + 0x24));
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f14c` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f15e` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f170` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f182` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f194` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f1a6` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f1b8` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `1001c2a0` | ___freetlocinfo |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f143` | `10038334` | `READ` | PTR_DAT_10038334 |
| `1001f155` | `10038338` | `READ` | PTR_DAT_10038338 |
| `1001f167` | `1003833c` | `READ` | PTR_DAT_1003833c |
| `1001f179` | `10038340` | `READ` | PTR_DAT_10038340 |
| `1001f18b` | `10038344` | `READ` | PTR_DAT_10038344 |
| `1001f19d` | `10038348` | `READ` | PTR_DAT_10038348 |
| `1001f1af` | `1003834c` | `READ` | PTR_DAT_1003834c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f133` | `8b ff` | `MOV EDI,EDI` |
| `1001f135` | `55` | `PUSH EBP` |
| `1001f136` | `8b ec` | `MOV EBP,ESP` |
| `1001f138` | `56` | `PUSH ESI` |
| `1001f139` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001f13c` | `85 f6` | `TEST ESI,ESI` |
| `1001f13e` | `74 7e` | `JZ 0x1001f1be` |
| `1001f140` | `8b 46 0c` | `MOV EAX,dword ptr [ESI + 0xc]` |
| `1001f143` | `3b 05 34 83 03 10` | `CMP EAX,dword ptr [0x10038334]` |
| `1001f149` | `74 07` | `JZ 0x1001f152` |
| `1001f14b` | `50` | `PUSH EAX` |
| `1001f14c` | `e8 f0 20 ff ff` | `CALL 0x10011241` |
| `1001f151` | `59` | `POP ECX` |
| `1001f152` | `8b 46 10` | `MOV EAX,dword ptr [ESI + 0x10]` |
| `1001f155` | `3b 05 38 83 03 10` | `CMP EAX,dword ptr [0x10038338]` |
| `1001f15b` | `74 07` | `JZ 0x1001f164` |
| `1001f15d` | `50` | `PUSH EAX` |
| `1001f15e` | `e8 de 20 ff ff` | `CALL 0x10011241` |
| `1001f163` | `59` | `POP ECX` |
| `1001f164` | `8b 46 14` | `MOV EAX,dword ptr [ESI + 0x14]` |
| `1001f167` | `3b 05 3c 83 03 10` | `CMP EAX,dword ptr [0x1003833c]` |
| `1001f16d` | `74 07` | `JZ 0x1001f176` |
| `1001f16f` | `50` | `PUSH EAX` |
| `1001f170` | `e8 cc 20 ff ff` | `CALL 0x10011241` |
| `1001f175` | `59` | `POP ECX` |
| `1001f176` | `8b 46 18` | `MOV EAX,dword ptr [ESI + 0x18]` |
| `1001f179` | `3b 05 40 83 03 10` | `CMP EAX,dword ptr [0x10038340]` |
| `1001f17f` | `74 07` | `JZ 0x1001f188` |
| `1001f181` | `50` | `PUSH EAX` |
| `1001f182` | `e8 ba 20 ff ff` | `CALL 0x10011241` |
| `1001f187` | `59` | `POP ECX` |
| `1001f188` | `8b 46 1c` | `MOV EAX,dword ptr [ESI + 0x1c]` |
| `1001f18b` | `3b 05 44 83 03 10` | `CMP EAX,dword ptr [0x10038344]` |
| `1001f191` | `74 07` | `JZ 0x1001f19a` |
| `1001f193` | `50` | `PUSH EAX` |
| `1001f194` | `e8 a8 20 ff ff` | `CALL 0x10011241` |
| `1001f199` | `59` | `POP ECX` |
| `1001f19a` | `8b 46 20` | `MOV EAX,dword ptr [ESI + 0x20]` |
| `1001f19d` | `3b 05 48 83 03 10` | `CMP EAX,dword ptr [0x10038348]` |
| `1001f1a3` | `74 07` | `JZ 0x1001f1ac` |
| `1001f1a5` | `50` | `PUSH EAX` |
| `1001f1a6` | `e8 96 20 ff ff` | `CALL 0x10011241` |
| `1001f1ab` | `59` | `POP ECX` |
| `1001f1ac` | `8b 76 24` | `MOV ESI,dword ptr [ESI + 0x24]` |
| `1001f1af` | `3b 35 4c 83 03 10` | `CMP ESI,dword ptr [0x1003834c]` |
| `1001f1b5` | `74 07` | `JZ 0x1001f1be` |
| `1001f1b7` | `56` | `PUSH ESI` |
| `1001f1b8` | `e8 84 20 ff ff` | `CALL 0x10011241` |
| `1001f1bd` | `59` | `POP ECX` |
| `1001f1be` | `5e` | `POP ESI` |
| `1001f1bf` | `5d` | `POP EBP` |
| `1001f1c0` | `c3` | `RET` |
