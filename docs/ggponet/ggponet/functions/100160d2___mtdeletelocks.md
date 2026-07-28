# 100160d2 `__mtdeletelocks`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100160d2 |
| `name` | __mtdeletelocks |
| `namespace` | Global |
| `signature` | void __cdecl __mtdeletelocks(void) |
| `size_bytes` | 87 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mtdeletelocks |

## Decompiled C

```c

/* Library Function - Single Match
    __mtdeletelocks
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  
  puVar1 = &DAT_10037618;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)*puVar1;
    if ((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (puVar1[1] != 1)) {
      DeleteCriticalSection(lpCriticalSection);
      _free(lpCriticalSection);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x10037738);
  puVar1 = &DAT_10037618;
  do {
    if (((LPCRITICAL_SECTION)*puVar1 != (LPCRITICAL_SECTION)0x0) && (puVar1[1] == 1)) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*puVar1);
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x10037738);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100160ef` | `EXTERNAL:00000041` | `COMPUTED_CALL` | KERNEL32.DLL::DeleteCriticalSection | `` |
| `100160f2` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10016119` | `EXTERNAL:00000041` | `COMPUTED_CALL` | KERNEL32.DLL::DeleteCriticalSection | `` |

## Callers

| From | Function |
| --- | --- |
| `10017271` | __mtterm |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100160d5` | `1002e0bc` | `READ` | PTR_DeleteCriticalSection_1002e0bc |
| `100160dc` | `10037618` | `DATA` | DAT_10037618 |
| `100160e2` | `10037618` | `READ` | DAT_10037618 |
| `100160e2` | `10037620` | `READ` | DAT_10037620 |
| `100160e8` | `1003761c` | `READ` | DAT_1003761c |
| `100160e8` | `10037624` | `READ` | DAT_10037624 |
| `100160f7` | `10037620` | `READ_WRITE` | DAT_10037620 |
| `100160fe` | `10037738` | `DATA` | DAT_10037738 |
| `10016106` | `10037618` | `DATA` | DAT_10037618 |
| `1001610c` | `10037618` | `READ` | DAT_10037618 |
| `1001610c` | `10037620` | `READ` | DAT_10037620 |
| `10016112` | `1003761c` | `READ` | DAT_1003761c |
| `10016112` | `10037624` | `READ` | DAT_10037624 |
| `1001611e` | `10037738` | `DATA` | DAT_10037738 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100160d2` | `8b ff` | `MOV EDI,EDI` |
| `100160d4` | `53` | `PUSH EBX` |
| `100160d5` | `8b 1d bc e0 02 10` | `MOV EBX,dword ptr [0x1002e0bc]` |
| `100160db` | `56` | `PUSH ESI` |
| `100160dc` | `be 18 76 03 10` | `MOV ESI,0x10037618` |
| `100160e1` | `57` | `PUSH EDI` |
| `100160e2` | `8b 3e` | `MOV EDI,dword ptr [ESI]` |
| `100160e4` | `85 ff` | `TEST EDI,EDI` |
| `100160e6` | `74 13` | `JZ 0x100160fb` |
| `100160e8` | `83 7e 04 01` | `CMP dword ptr [ESI + 0x4],0x1` |
| `100160ec` | `74 0d` | `JZ 0x100160fb` |
| `100160ee` | `57` | `PUSH EDI` |
| `100160ef` | `ff d3` | `CALL EBX` |
| `100160f1` | `57` | `PUSH EDI` |
| `100160f2` | `e8 4a b1 ff ff` | `CALL 0x10011241` |
| `100160f7` | `83 26 00` | `AND dword ptr [ESI],0x0` |
| `100160fa` | `59` | `POP ECX` |
| `100160fb` | `83 c6 08` | `ADD ESI,0x8` |
| `100160fe` | `81 fe 38 77 03 10` | `CMP ESI,0x10037738` |
| `10016104` | `7c dc` | `JL 0x100160e2` |
| `10016106` | `be 18 76 03 10` | `MOV ESI,0x10037618` |
| `1001610b` | `5f` | `POP EDI` |
| `1001610c` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001610e` | `85 c0` | `TEST EAX,EAX` |
| `10016110` | `74 09` | `JZ 0x1001611b` |
| `10016112` | `83 7e 04 01` | `CMP dword ptr [ESI + 0x4],0x1` |
| `10016116` | `75 03` | `JNZ 0x1001611b` |
| `10016118` | `50` | `PUSH EAX` |
| `10016119` | `ff d3` | `CALL EBX` |
| `1001611b` | `83 c6 08` | `ADD ESI,0x8` |
| `1001611e` | `81 fe 38 77 03 10` | `CMP ESI,0x10037738` |
| `10016124` | `7c e6` | `JL 0x1001610c` |
| `10016126` | `5e` | `POP ESI` |
| `10016127` | `5b` | `POP EBX` |
| `10016128` | `c3` | `RET` |
