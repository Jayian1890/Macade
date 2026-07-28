# 1001dbb6 `__get_osfhandle`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001dbb6 |
| `name` | __get_osfhandle |
| `namespace` | Global |
| `signature` | intptr_t __cdecl __get_osfhandle(int _FileHandle) |
| `size_bytes` | 119 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __get_osfhandle |

## Decompiled C

```c

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 2008 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  ulong *puVar1;
  int *piVar2;
  intptr_t *piVar3;
  intptr_t iVar4;
  
  if (_FileHandle == -2) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    return -1;
  }
  if (((_FileHandle < 0) || (DAT_13439530 <= (uint)_FileHandle)) ||
     (piVar3 = (intptr_t *)((_FileHandle & 0x1fU) * 0x40 + (&DAT_13439540)[_FileHandle >> 5]),
     (*(byte *)(piVar3 + 1) & 1) == 0)) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    __invalid_parameter(0,0,0,0,0);
    iVar4 = -1;
  }
  else {
    iVar4 = *piVar3;
  }
  return iVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001dbc3` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001dbcb` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001dc04` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001dc0b` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001dc1b` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |

## Callers

| From | Function |
| --- | --- |
| `1001b945` | __lseeki64_nolock |
| `10018c82` | __close_nolock |
| `10018cad` | __close_nolock |
| `10018cb6` | __close_nolock |
| `10018cc2` | __close_nolock |
| `1001f493` | __chsize_nolock |
| `1001f50c` | __lseek_nolock |
| `1001a473` | __commit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001dbe2` | `13439530` | `READ` | DAT_13439530 |
| `1001dbf2` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001dbb6` | `8b ff` | `MOV EDI,EDI` |
| `1001dbb8` | `55` | `PUSH EBP` |
| `1001dbb9` | `8b ec` | `MOV EBP,ESP` |
| `1001dbbb` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001dbbe` | `83 f8 fe` | `CMP EAX,-0x2` |
| `1001dbc1` | `75 18` | `JNZ 0x1001dbdb` |
| `1001dbc3` | `e8 54 75 ff ff` | `CALL 0x1001511c` |
| `1001dbc8` | `83 20 00` | `AND dword ptr [EAX],0x0` |
| `1001dbcb` | `e8 39 75 ff ff` | `CALL 0x10015109` |
| `1001dbd0` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001dbd6` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001dbd9` | `5d` | `POP EBP` |
| `1001dbda` | `c3` | `RET` |
| `1001dbdb` | `56` | `PUSH ESI` |
| `1001dbdc` | `33 f6` | `XOR ESI,ESI` |
| `1001dbde` | `3b c6` | `CMP EAX,ESI` |
| `1001dbe0` | `7c 22` | `JL 0x1001dc04` |
| `1001dbe2` | `3b 05 30 95 43 13` | `CMP EAX,dword ptr [0x13439530]` |
| `1001dbe8` | `73 1a` | `JNC 0x1001dc04` |
| `1001dbea` | `8b c8` | `MOV ECX,EAX` |
| `1001dbec` | `83 e0 1f` | `AND EAX,0x1f` |
| `1001dbef` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001dbf2` | `8b 0c 8d 40 95 43 13` | `MOV ECX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001dbf9` | `c1 e0 06` | `SHL EAX,0x6` |
| `1001dbfc` | `03 c1` | `ADD EAX,ECX` |
| `1001dbfe` | `f6 40 04 01` | `TEST byte ptr [EAX + 0x4],0x1` |
| `1001dc02` | `75 24` | `JNZ 0x1001dc28` |
| `1001dc04` | `e8 13 75 ff ff` | `CALL 0x1001511c` |
| `1001dc09` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001dc0b` | `e8 f9 74 ff ff` | `CALL 0x10015109` |
| `1001dc10` | `56` | `PUSH ESI` |
| `1001dc11` | `56` | `PUSH ESI` |
| `1001dc12` | `56` | `PUSH ESI` |
| `1001dc13` | `56` | `PUSH ESI` |
| `1001dc14` | `56` | `PUSH ESI` |
| `1001dc15` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001dc1b` | `e8 8f 3a ff ff` | `CALL 0x100116af` |
| `1001dc20` | `83 c4 14` | `ADD ESP,0x14` |
| `1001dc23` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001dc26` | `eb 02` | `JMP 0x1001dc2a` |
| `1001dc28` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001dc2a` | `5e` | `POP ESI` |
| `1001dc2b` | `5d` | `POP EBP` |
| `1001dc2c` | `c3` | `RET` |
