# 100192e5 `__RTC_Initialize`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100192e5 |
| `name` | __RTC_Initialize |
| `namespace` | Global |
| `signature` | undefined __RTC_Initialize(void) |
| `size_bytes` | 38 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __RTC_Initialize |

## Decompiled C

```c

/* WARNING: Removing unreachable block (ram,0x100192f9) */
/* WARNING: Removing unreachable block (ram,0x100192ff) */
/* WARNING: Removing unreachable block (ram,0x10019301) */
/* Library Function - Single Match
    __RTC_Initialize
   
   Library: Visual Studio 2008 Release */

void __RTC_Initialize(void)

{
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100146a0` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100192e8` | `10033bf8` | `DATA` | DAT_10033bf8 |
| `100192ed` | `10033bf8` | `DATA` | DAT_10033bf8 |
| `100192f9` | `10033bf8` | `READ` | DAT_10033bf8 |
| `100192f9` | `10033bfc` | `READ` | DAT_10033bfc |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100192e5` | `8b ff` | `MOV EDI,EDI` |
| `100192e7` | `56` | `PUSH ESI` |
| `100192e8` | `b8 f8 3b 03 10` | `MOV EAX,0x10033bf8` |
| `100192ed` | `be f8 3b 03 10` | `MOV ESI,0x10033bf8` |
| `100192f2` | `57` | `PUSH EDI` |
| `100192f3` | `8b f8` | `MOV EDI,EAX` |
| `100192f5` | `3b c6` | `CMP EAX,ESI` |
| `100192f7` | `73 0f` | `JNC 0x10019308` |
| `100192f9` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `100192fb` | `85 c0` | `TEST EAX,EAX` |
| `100192fd` | `74 02` | `JZ 0x10019301` |
| `100192ff` | `ff d0` | `CALL EAX` |
| `10019301` | `83 c7 04` | `ADD EDI,0x4` |
| `10019304` | `3b fe` | `CMP EDI,ESI` |
| `10019306` | `72 f1` | `JC 0x100192f9` |
| `10019308` | `5f` | `POP EDI` |
| `10019309` | `5e` | `POP ESI` |
| `1001930a` | `c3` | `RET` |
