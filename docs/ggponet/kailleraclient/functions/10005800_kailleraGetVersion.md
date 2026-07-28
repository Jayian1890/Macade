# 10005800 `kailleraGetVersion`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005800 |
| `name` | kailleraGetVersion |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraGetVersion(char * param_1) |
| `size_bytes` | 43 |
| `stack_frame_size` | 8 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_3, _kailleraGetVersion@4, kailleraGetVersion |

## Decompiled C

```c

/* __stdcall kailleraGetVersion,4 */

void kailleraGetVersion(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
                    /* 0x5800  3  _kailleraGetVersion@4 */
  uVar2 = 0xffffffff;
  pcVar4 = &DAT_1000e454;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10005802` | `1000e454` | `DATA` | DAT_1000e454 |
| `1000580c` | `1000e454` | `READ` | DAT_1000e454 |
| `1000580c` | `1000e455` | `READ` | DAT_1000e455 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005800` | `56` | `PUSH ESI` |
| `10005801` | `57` | `PUSH EDI` |
| `10005802` | `bf 54 e4 00 10` | `MOV EDI,0x1000e454` |
| `10005807` | `83 c9 ff` | `OR ECX,0xffffffff` |
| `1000580a` | `33 c0` | `XOR EAX,EAX` |
| `1000580c` | `f2 ae` | `SCASB.REPNE ES:EDI` |
| `1000580e` | `f7 d1` | `NOT ECX` |
| `10005810` | `2b f9` | `SUB EDI,ECX` |
| `10005812` | `8b c1` | `MOV EAX,ECX` |
| `10005814` | `8b f7` | `MOV ESI,EDI` |
| `10005816` | `8b 7c 24 0c` | `MOV EDI,dword ptr [ESP + 0xc]` |
| `1000581a` | `c1 e9 02` | `SHR ECX,0x2` |
| `1000581d` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `1000581f` | `8b c8` | `MOV ECX,EAX` |
| `10005821` | `83 e1 03` | `AND ECX,0x3` |
| `10005824` | `f3 a4` | `MOVSB.REP ES:EDI,ESI` |
| `10005826` | `5f` | `POP EDI` |
| `10005827` | `5e` | `POP ESI` |
| `10005828` | `c2 04 00` | `RET 0x4` |
