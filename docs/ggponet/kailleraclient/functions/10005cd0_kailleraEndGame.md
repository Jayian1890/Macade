# 10005cd0 `kailleraEndGame`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005cd0 |
| `name` | kailleraEndGame |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraEndGame(void) |
| `size_bytes` | 5 |
| `stack_frame_size` | 4 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_2, _kailleraEndGame@0, kailleraEndGame |

## Decompiled C

```c

/* __stdcall kailleraEndGame,0 */

void kailleraEndGame(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 auStack_40 [13];
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
                    /* 0x5cd0  2  _kailleraEndGame@0 */
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1000ca30;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_1000f1dc = 0;
  DAT_1000f184 = GetTickCount();
  FUN_10001c40(auStack_40);
  uStack_4 = 0;
  auStack_40[0] = 0x14;
  FUN_10001f00(auStack_40);
  uStack_4 = 1;
  FUN_100010d0();
  uStack_4 = 0xffffffff;
  FUN_10001c70((int)auStack_40);
  if (DAT_1000f1d8 != (HWND)0x0) {
    DestroyWindow(DAT_1000f1d8);
  }
  DAT_1000f1d8 = (HWND)0x0;
  SetFocus(DAT_1000f120);
  SetTimer(DAT_1000f120,0xd1ed1e,10,(TIMERPROC)0x0);
  *unaff_FS_OFFSET = uStack_c;
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

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005cd0` | `e9 9b 03 00 00` | `JMP 0x10006070` |
