# 1001c4cb `__updatetlocinfoEx_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c4cb |
| `name` | __updatetlocinfoEx_nolock |
| `namespace` | Global |
| `signature` | undefined __updatetlocinfoEx_nolock(void) |
| `size_bytes` | 62 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __updatetlocinfoEx_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __updatetlocinfoEx_nolock
   
   Library: Visual Studio 2008 Release */

int * __updatetlocinfoEx_nolock(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  int *unaff_EDI;
  
  if ((unaff_EDI != (int *)0x0) && (in_EAX != (undefined4 *)0x0)) {
    piVar1 = (int *)*in_EAX;
    if (piVar1 != unaff_EDI) {
      *in_EAX = unaff_EDI;
      ___addlocaleref();
      if (piVar1 != (int *)0x0) {
        ___removelocaleref(piVar1);
        if ((*piVar1 == 0) && (piVar1 != (int *)&DAT_10038150)) {
          ___freetlocinfo(piVar1);
        }
      }
    }
    return unaff_EDI;
  }
  return (int *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c4dd` | `1001c3a3` | `UNCONDITIONAL_CALL` | ___addlocaleref | `1001c3a3` |
| `1001c4e8` | `1001c432` | `UNCONDITIONAL_CALL` | ___removelocaleref | `1001c432` |
| `1001c4fc` | `1001c25a` | `UNCONDITIONAL_CALL` | ___freetlocinfo | `1001c25a` |

## Callers

| From | Function |
| --- | --- |
| `1001c55d` | ___updatetlocinfo |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c4f3` | `10038150` | `DATA` | DAT_10038150 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c4cb` | `85 ff` | `TEST EDI,EDI` |
| `1001c4cd` | `74 37` | `JZ 0x1001c506` |
| `1001c4cf` | `85 c0` | `TEST EAX,EAX` |
| `1001c4d1` | `74 33` | `JZ 0x1001c506` |
| `1001c4d3` | `56` | `PUSH ESI` |
| `1001c4d4` | `8b 30` | `MOV ESI,dword ptr [EAX]` |
| `1001c4d6` | `3b f7` | `CMP ESI,EDI` |
| `1001c4d8` | `74 28` | `JZ 0x1001c502` |
| `1001c4da` | `57` | `PUSH EDI` |
| `1001c4db` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `1001c4dd` | `e8 c1 fe ff ff` | `CALL 0x1001c3a3` |
| `1001c4e2` | `59` | `POP ECX` |
| `1001c4e3` | `85 f6` | `TEST ESI,ESI` |
| `1001c4e5` | `74 1b` | `JZ 0x1001c502` |
| `1001c4e7` | `56` | `PUSH ESI` |
| `1001c4e8` | `e8 45 ff ff ff` | `CALL 0x1001c432` |
| `1001c4ed` | `83 3e 00` | `CMP dword ptr [ESI],0x0` |
| `1001c4f0` | `59` | `POP ECX` |
| `1001c4f1` | `75 0f` | `JNZ 0x1001c502` |
| `1001c4f3` | `81 fe 50 81 03 10` | `CMP ESI,0x10038150` |
| `1001c4f9` | `74 07` | `JZ 0x1001c502` |
| `1001c4fb` | `56` | `PUSH ESI` |
| `1001c4fc` | `e8 59 fd ff ff` | `CALL 0x1001c25a` |
| `1001c501` | `59` | `POP ECX` |
| `1001c502` | `8b c7` | `MOV EAX,EDI` |
| `1001c504` | `5e` | `POP ESI` |
| `1001c505` | `c3` | `RET` |
| `1001c506` | `33 c0` | `XOR EAX,EAX` |
| `1001c508` | `c3` | `RET` |
