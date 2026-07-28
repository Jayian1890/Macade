# 10005ba0 `kailleraShutdown`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005ba0 |
| `name` | kailleraShutdown |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraShutdown(void) |
| `size_bytes` | 57 |
| `stack_frame_size` | 4 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_8, _kailleraShutdown@0, kailleraShutdown |

## Decompiled C

```c

/* __stdcall kailleraShutdown,0 */

void kailleraShutdown(void)

{
  int *piVar1;
  
                    /* 0x5ba0  8  _kailleraShutdown@0 */
  Ordinal_116();
  FUN_10001640(DAT_1000ef90);
  piVar1 = DAT_1000ef90;
  if (DAT_1000ef90 != (int *)0x0) {
    FUN_10001740(DAT_1000ef90);
    operator_delete(piVar1);
  }
  FreeLibrary(DAT_1000ef94);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10005ba1` | `10004170` | `UNCONDITIONAL_CALL` | WS2_32.DLL::Ordinal_116 | `10004170` |
| `10005bac` | `10001640` | `UNCONDITIONAL_CALL` | FUN_10001640 | `10001640` |
| `10005bbd` | `10001740` | `UNCONDITIONAL_CALL` | FUN_10001740 | `10001740` |
| `10005bc3` | `1000c754` | `UNCONDITIONAL_CALL` | MSVCRT.DLL::operator_delete | `1000c754` |
| `10005bd1` | `EXTERNAL:0000000b` | `COMPUTED_CALL` | KERNEL32.DLL::FreeLibrary | `` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10005ba6` | `1000ef90` | `READ` | DAT_1000ef90 |
| `10005bb1` | `1000ef90` | `READ` | DAT_1000ef90 |
| `10005bcb` | `1000ef94` | `READ` | DAT_1000ef94 |
| `10005bd1` | `1000d044` | `READ` | PTR_FreeLibrary_1000d044 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005ba0` | `56` | `PUSH ESI` |
| `10005ba1` | `e8 ca e5 ff ff` | `CALL 0x10004170` |
| `10005ba6` | `8b 0d 90 ef 00 10` | `MOV ECX,dword ptr [0x1000ef90]` |
| `10005bac` | `e8 8f ba ff ff` | `CALL 0x10001640` |
| `10005bb1` | `8b 35 90 ef 00 10` | `MOV ESI,dword ptr [0x1000ef90]` |
| `10005bb7` | `85 f6` | `TEST ESI,ESI` |
| `10005bb9` | `74 10` | `JZ 0x10005bcb` |
| `10005bbb` | `8b ce` | `MOV ECX,ESI` |
| `10005bbd` | `e8 7e bb ff ff` | `CALL 0x10001740` |
| `10005bc2` | `56` | `PUSH ESI` |
| `10005bc3` | `e8 8c 6b 00 00` | `CALL 0x1000c754` |
| `10005bc8` | `83 c4 04` | `ADD ESP,0x4` |
| `10005bcb` | `a1 94 ef 00 10` | `MOV EAX,[0x1000ef94]` |
| `10005bd0` | `50` | `PUSH EAX` |
| `10005bd1` | `ff 15 44 d0 00 10` | `CALL dword ptr [0x1000d044]` |
| `10005bd7` | `5e` | `POP ESI` |
| `10005bd8` | `c3` | `RET` |
