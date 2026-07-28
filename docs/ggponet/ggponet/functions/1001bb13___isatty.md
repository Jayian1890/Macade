# 1001bb13 `__isatty`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001bb13 |
| `name` | __isatty |
| `namespace` | Global |
| `signature` | int __cdecl __isatty(int _FileHandle) |
| `size_bytes` | 100 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __isatty |

## Decompiled C

```c

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2008 Release */

int __cdecl __isatty(int _FileHandle)

{
  int *piVar1;
  uint uVar2;
  
  if (_FileHandle == -2) {
    piVar1 = __errno();
    *piVar1 = 9;
    return 0;
  }
  if ((_FileHandle < 0) || (DAT_13439530 <= (uint)_FileHandle)) {
    piVar1 = __errno();
    *piVar1 = 9;
    __invalid_parameter(0,0,0,0,0);
    uVar2 = 0;
  }
  else {
    uVar2 = (int)*(char *)((&DAT_13439540)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x40) &
            0x40;
  }
  return uVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001bb20` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001bb3e` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001bb4e` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |

## Callers

| From | Function |
| --- | --- |
| `100151e6` | __flsbuf |
| `10019cc9` | __write_nolock |
| `10018e21` | __stbuf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001bb36` | `13439530` | `READ` | DAT_13439530 |
| `1001bb62` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001bb13` | `8b ff` | `MOV EDI,EDI` |
| `1001bb15` | `55` | `PUSH EBP` |
| `1001bb16` | `8b ec` | `MOV EBP,ESP` |
| `1001bb18` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001bb1b` | `83 f8 fe` | `CMP EAX,-0x2` |
| `1001bb1e` | `75 0f` | `JNZ 0x1001bb2f` |
| `1001bb20` | `e8 e4 95 ff ff` | `CALL 0x10015109` |
| `1001bb25` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001bb2b` | `33 c0` | `XOR EAX,EAX` |
| `1001bb2d` | `5d` | `POP EBP` |
| `1001bb2e` | `c3` | `RET` |
| `1001bb2f` | `56` | `PUSH ESI` |
| `1001bb30` | `33 f6` | `XOR ESI,ESI` |
| `1001bb32` | `3b c6` | `CMP EAX,ESI` |
| `1001bb34` | `7c 08` | `JL 0x1001bb3e` |
| `1001bb36` | `3b 05 30 95 43 13` | `CMP EAX,dword ptr [0x13439530]` |
| `1001bb3c` | `72 1c` | `JC 0x1001bb5a` |
| `1001bb3e` | `e8 c6 95 ff ff` | `CALL 0x10015109` |
| `1001bb43` | `56` | `PUSH ESI` |
| `1001bb44` | `56` | `PUSH ESI` |
| `1001bb45` | `56` | `PUSH ESI` |
| `1001bb46` | `56` | `PUSH ESI` |
| `1001bb47` | `56` | `PUSH ESI` |
| `1001bb48` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001bb4e` | `e8 5c 5b ff ff` | `CALL 0x100116af` |
| `1001bb53` | `83 c4 14` | `ADD ESP,0x14` |
| `1001bb56` | `33 c0` | `XOR EAX,EAX` |
| `1001bb58` | `eb 1a` | `JMP 0x1001bb74` |
| `1001bb5a` | `8b c8` | `MOV ECX,EAX` |
| `1001bb5c` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001bb5f` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001bb62` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001bb69` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001bb6c` | `0f be 44 01 04` | `MOVSX EAX,byte ptr [ECX + EAX*0x1 + 0x4]` |
| `1001bb71` | `83 e0 40` | `AND EAX,0x40` |
| `1001bb74` | `5e` | `POP ESI` |
| `1001bb75` | `5d` | `POP EBP` |
| `1001bb76` | `c3` | `RET` |
