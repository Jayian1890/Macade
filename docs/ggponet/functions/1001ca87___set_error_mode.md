# 1001ca87 `__set_error_mode`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ca87 |
| `name` | __set_error_mode |
| `namespace` | Global |
| `signature` | int __cdecl __set_error_mode(int _Mode) |
| `size_bytes` | 75 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __set_error_mode |

## Decompiled C

```c

/* Library Function - Single Match
    __set_error_mode
   
   Library: Visual Studio 2008 Release */

int __cdecl __set_error_mode(int _Mode)

{
  int *piVar1;
  int iVar2;
  
  if (-1 < _Mode) {
    if (_Mode < 3) {
      iVar2 = DAT_10038a7c;
      DAT_10038a7c = _Mode;
      return iVar2;
    }
    if (_Mode == 3) {
      return DAT_10038a7c;
    }
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  __invalid_parameter(0,0,0,0,0);
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cab4` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001cac4` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |

## Callers

| From | Function |
| --- | --- |
| `10016f1d` | __NMSG_WRITE |
| `10016f2e` | __NMSG_WRITE |
| `10017099` | __FF_MSGBANNER |
| `100170a6` | __FF_MSGBANNER |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001caa0` | `10038a7c` | `READ` | DAT_10038a7c |
| `1001caa7` | `10038a7c` | `READ` | DAT_10038a7c |
| `1001caac` | `10038a7c` | `WRITE` | DAT_10038a7c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ca87` | `8b ff` | `MOV EDI,EDI` |
| `1001ca89` | `55` | `PUSH EBP` |
| `1001ca8a` | `8b ec` | `MOV EBP,ESP` |
| `1001ca8c` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001ca8f` | `56` | `PUSH ESI` |
| `1001ca90` | `33 f6` | `XOR ESI,ESI` |
| `1001ca92` | `3b ce` | `CMP ECX,ESI` |
| `1001ca94` | `7c 1e` | `JL 0x1001cab4` |
| `1001ca96` | `83 f9 02` | `CMP ECX,0x2` |
| `1001ca99` | `7e 0c` | `JLE 0x1001caa7` |
| `1001ca9b` | `83 f9 03` | `CMP ECX,0x3` |
| `1001ca9e` | `75 14` | `JNZ 0x1001cab4` |
| `1001caa0` | `a1 7c 8a 03 10` | `MOV EAX,[0x10038a7c]` |
| `1001caa5` | `eb 28` | `JMP 0x1001cacf` |
| `1001caa7` | `a1 7c 8a 03 10` | `MOV EAX,[0x10038a7c]` |
| `1001caac` | `89 0d 7c 8a 03 10` | `MOV dword ptr [0x10038a7c],ECX` |
| `1001cab2` | `eb 1b` | `JMP 0x1001cacf` |
| `1001cab4` | `e8 50 86 ff ff` | `CALL 0x10015109` |
| `1001cab9` | `56` | `PUSH ESI` |
| `1001caba` | `56` | `PUSH ESI` |
| `1001cabb` | `56` | `PUSH ESI` |
| `1001cabc` | `56` | `PUSH ESI` |
| `1001cabd` | `56` | `PUSH ESI` |
| `1001cabe` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001cac4` | `e8 e6 4b ff ff` | `CALL 0x100116af` |
| `1001cac9` | `83 c4 14` | `ADD ESP,0x14` |
| `1001cacc` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001cacf` | `5e` | `POP ESI` |
| `1001cad0` | `5d` | `POP EBP` |
| `1001cad1` | `c3` | `RET` |
