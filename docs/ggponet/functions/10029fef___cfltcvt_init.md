# 10029fef `__cfltcvt_init`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10029fef |
| `name` | __cfltcvt_init |
| `namespace` | Global |
| `signature` | undefined __cfltcvt_init(void) |
| `size_bytes` | 96 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cfltcvt_init |

## Decompiled C

```c

/* Library Function - Single Match
    __cfltcvt_init
   
   Library: Visual Studio 2008 Release */

void __cfltcvt_init(void)

{
  PTR_LAB_10037bc0 = __cfltcvt;
  PTR_LAB_10037bc4 = __cropzeros;
  PTR_LAB_10037bc8 = __fassign;
  PTR_LAB_10037bcc = __forcdecpt;
  PTR_LAB_10037bd0 = __positive;
  PTR_LAB_10037bd4 = __cfltcvt;
  PTR_LAB_10037bd8 = __cfltcvt_l;
  PTR_LAB_10037bdc = __fassign_l;
  PTR_LAB_10037be0 = __cropzeros_l;
  PTR_LAB_10037be4 = __forcdecpt_l;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002a054` | __fpmath |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10029fef` | `1002abe3` | `DATA` | __cfltcvt |
| `10029ff4` | `10037bc0` | `WRITE` | PTR_LAB_10037bc0 |
| `10029ff9` | `10037bc4` | `WRITE` | PTR_LAB_10037bc4 |
| `10029ff9` | `1002a2ca` | `DATA` | __cropzeros |
| `1002a003` | `10037bc8` | `WRITE` | PTR_LAB_10037bc8 |
| `1002a003` | `1002a27e` | `DATA` | __fassign |
| `1002a00d` | `10037bcc` | `WRITE` | PTR_LAB_10037bcc |
| `1002a00d` | `1002a2b7` | `DATA` | __forcdecpt |
| `1002a017` | `10037bd0` | `WRITE` | PTR_LAB_10037bd0 |
| `1002a017` | `1002a220` | `DATA` | __positive |
| `1002a021` | `10037bd4` | `WRITE` | PTR_LAB_10037bd4 |
| `1002a026` | `10037bd8` | `WRITE` | PTR_LAB_10037bd8 |
| `1002a026` | `1002ab5b` | `DATA` | __cfltcvt_l |
| `1002a030` | `10037bdc` | `WRITE` | PTR_LAB_10037bdc |
| `1002a030` | `1002a23c` | `DATA` | __fassign_l |
| `1002a03a` | `10037be0` | `WRITE` | PTR_LAB_10037be0 |
| `1002a03a` | `1002a19e` | `DATA` | __cropzeros_l |
| `1002a044` | `10037be4` | `WRITE` | PTR_LAB_10037be4 |
| `1002a044` | `1002a12b` | `DATA` | __forcdecpt_l |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10029fef` | `b8 e3 ab 02 10` | `MOV EAX,0x1002abe3` |
| `10029ff4` | `a3 c0 7b 03 10` | `MOV [0x10037bc0],EAX` |
| `10029ff9` | `c7 05 c4 7b 03 10 ca a2 02 10` | `MOV dword ptr [0x10037bc4],0x1002a2ca` |
| `1002a003` | `c7 05 c8 7b 03 10 7e a2 02 10` | `MOV dword ptr [0x10037bc8],0x1002a27e` |
| `1002a00d` | `c7 05 cc 7b 03 10 b7 a2 02 10` | `MOV dword ptr [0x10037bcc],0x1002a2b7` |
| `1002a017` | `c7 05 d0 7b 03 10 20 a2 02 10` | `MOV dword ptr [0x10037bd0],0x1002a220` |
| `1002a021` | `a3 d4 7b 03 10` | `MOV [0x10037bd4],EAX` |
| `1002a026` | `c7 05 d8 7b 03 10 5b ab 02 10` | `MOV dword ptr [0x10037bd8],0x1002ab5b` |
| `1002a030` | `c7 05 dc 7b 03 10 3c a2 02 10` | `MOV dword ptr [0x10037bdc],0x1002a23c` |
| `1002a03a` | `c7 05 e0 7b 03 10 9e a1 02 10` | `MOV dword ptr [0x10037be0],0x1002a19e` |
| `1002a044` | `c7 05 e4 7b 03 10 2b a1 02 10` | `MOV dword ptr [0x10037be4],0x1002a12b` |
| `1002a04e` | `c3` | `RET` |
