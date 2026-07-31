# 1001f0ee `___free_lconv_num`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f0ee |
| `name` | ___free_lconv_num |
| `namespace` | Global |
| `signature` | undefined ___free_lconv_num(void) |
| `size_bytes` | 69 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___free_lconv_num |

## Decompiled C

```c

/* Library Function - Single Match
    ___free_lconv_num
   
   Library: Visual Studio 2008 Release */

void ___free_lconv_num(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((undefined *)*param_1 != PTR_DAT_10038328) {
      _free((undefined *)*param_1);
    }
    if ((undefined *)param_1[1] != PTR_DAT_1003832c) {
      _free((undefined *)param_1[1]);
    }
    if ((undefined *)param_1[2] != PTR_DAT_10038330) {
      _free((undefined *)param_1[2]);
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f106` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f118` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f12a` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `1001c2c1` | ___freetlocinfo |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f0fd` | `10038328` | `READ` | PTR_DAT_10038328 |
| `1001f10f` | `1003832c` | `READ` | PTR_DAT_1003832c |
| `1001f121` | `10038330` | `READ` | PTR_DAT_10038330 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f0ee` | `8b ff` | `MOV EDI,EDI` |
| `1001f0f0` | `55` | `PUSH EBP` |
| `1001f0f1` | `8b ec` | `MOV EBP,ESP` |
| `1001f0f3` | `56` | `PUSH ESI` |
| `1001f0f4` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001f0f7` | `85 f6` | `TEST ESI,ESI` |
| `1001f0f9` | `74 35` | `JZ 0x1001f130` |
| `1001f0fb` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001f0fd` | `3b 05 28 83 03 10` | `CMP EAX,dword ptr [0x10038328]` |
| `1001f103` | `74 07` | `JZ 0x1001f10c` |
| `1001f105` | `50` | `PUSH EAX` |
| `1001f106` | `e8 36 21 ff ff` | `CALL 0x10011241` |
| `1001f10b` | `59` | `POP ECX` |
| `1001f10c` | `8b 46 04` | `MOV EAX,dword ptr [ESI + 0x4]` |
| `1001f10f` | `3b 05 2c 83 03 10` | `CMP EAX,dword ptr [0x1003832c]` |
| `1001f115` | `74 07` | `JZ 0x1001f11e` |
| `1001f117` | `50` | `PUSH EAX` |
| `1001f118` | `e8 24 21 ff ff` | `CALL 0x10011241` |
| `1001f11d` | `59` | `POP ECX` |
| `1001f11e` | `8b 76 08` | `MOV ESI,dword ptr [ESI + 0x8]` |
| `1001f121` | `3b 35 30 83 03 10` | `CMP ESI,dword ptr [0x10038330]` |
| `1001f127` | `74 07` | `JZ 0x1001f130` |
| `1001f129` | `56` | `PUSH ESI` |
| `1001f12a` | `e8 12 21 ff ff` | `CALL 0x10011241` |
| `1001f12f` | `59` | `POP ECX` |
| `1001f130` | `5e` | `POP ESI` |
| `1001f131` | `5d` | `POP EBP` |
| `1001f132` | `c3` | `RET` |
