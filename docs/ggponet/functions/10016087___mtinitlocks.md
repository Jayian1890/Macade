# 10016087 `__mtinitlocks`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016087 |
| `name` | __mtinitlocks |
| `namespace` | Global |
| `signature` | int __cdecl __mtinitlocks(void) |
| `size_bytes` | 75 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mtinitlocks |

## Decompiled C

```c

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 2008 Release */

int __cdecl __mtinitlocks(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_10038db0;
  do {
    if ((&DAT_1003761c)[iVar2 * 2] == 1) {
      (&DAT_10037618)[iVar2 * 2] = puVar3;
      puVar3 = puVar3 + 0x18;
      iVar1 = ___crtInitCritSecAndSpinCount((&DAT_10037618)[iVar2 * 2],4000);
      if (iVar1 == 0) {
        (&DAT_10037618)[iVar2 * 2] = 0;
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x24);
  return 1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100160af` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |

## Callers

| From | Function |
| --- | --- |
| `100176a2` | __mtinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001608d` | `10038db0` | `DATA` | DAT_10038db0 |
| `10016092` | `1003761c` | `READ` | DAT_1003761c |
| `10016092` | `10037624` | `READ` | DAT_10037624 |
| `1001609c` | `10037618` | `DATA` | DAT_10037618 |
| `100160a3` | `10037618` | `WRITE` | DAT_10037618 |
| `100160a3` | `10038db0` | `DATA` | DAT_10038db0 |
| `100160a3` | `10037620` | `WRITE` | DAT_10037620 |
| `100160a3` | `10038dc8` | `DATA` | DAT_10038dc8 |
| `100160aa` | `10037618` | `READ` | DAT_10037618 |
| `100160aa` | `10038db0` | `DATA` | DAT_10038db0 |
| `100160aa` | `10037620` | `READ` | DAT_10037620 |
| `100160aa` | `10038dc8` | `DATA` | DAT_10038dc8 |
| `100160c6` | `10037618` | `READ_WRITE` | DAT_10037618 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016087` | `8b ff` | `MOV EDI,EDI` |
| `10016089` | `56` | `PUSH ESI` |
| `1001608a` | `57` | `PUSH EDI` |
| `1001608b` | `33 f6` | `XOR ESI,ESI` |
| `1001608d` | `bf b0 8d 03 10` | `MOV EDI,0x10038db0` |
| `10016092` | `83 3c f5 1c 76 03 10 01` | `CMP dword ptr [ESI*0x8 + 0x1003761c],0x1` |
| `1001609a` | `75 1e` | `JNZ 0x100160ba` |
| `1001609c` | `8d 04 f5 18 76 03 10` | `LEA EAX,[ESI*0x8 + 0x10037618]` |
| `100160a3` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `100160a5` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `100160aa` | `ff 30` | `PUSH dword ptr [EAX]` |
| `100160ac` | `83 c7 18` | `ADD EDI,0x18` |
| `100160af` | `e8 3f 38 00 00` | `CALL 0x100198f3` |
| `100160b4` | `59` | `POP ECX` |
| `100160b5` | `59` | `POP ECX` |
| `100160b6` | `85 c0` | `TEST EAX,EAX` |
| `100160b8` | `74 0c` | `JZ 0x100160c6` |
| `100160ba` | `46` | `INC ESI` |
| `100160bb` | `83 fe 24` | `CMP ESI,0x24` |
| `100160be` | `7c d2` | `JL 0x10016092` |
| `100160c0` | `33 c0` | `XOR EAX,EAX` |
| `100160c2` | `40` | `INC EAX` |
| `100160c3` | `5f` | `POP EDI` |
| `100160c4` | `5e` | `POP ESI` |
| `100160c5` | `c3` | `RET` |
| `100160c6` | `83 24 f5 18 76 03 10 00` | `AND dword ptr [ESI*0x8 + 0x10037618],0x0` |
| `100160ce` | `33 c0` | `XOR EAX,EAX` |
| `100160d0` | `eb f1` | `JMP 0x100160c3` |
