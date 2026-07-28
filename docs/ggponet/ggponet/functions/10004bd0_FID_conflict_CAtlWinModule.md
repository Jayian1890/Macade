# 10004bd0 `FID_conflict:~CAtlWinModule`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10004bd0 |
| `name` | FID_conflict:~CAtlWinModule |
| `namespace` | Global |
| `signature` | undefined FID_conflict:~CAtlWinModule(void) |
| `size_bytes` | 83 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??1CAtlWinModule@ATL@@QAE@XZ, ??1CPaneContainerGC@@QAE@XZ, FID_conflict:~CAtlWinModule |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlWinModule::~CAtlWinModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2010 Debug */

void FID_conflict__CAtlWinModule(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d908;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10005580(DAT_10037490 ^ (uint)&stack0xfffffffc);
  local_8 = 0xffffffff;
  FUN_10004d80();
  ExceptionList = local_10;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10004c00` | `10005580` | `UNCONDITIONAL_CALL` | FUN_10005580 | `10005580` |
| `10004c0f` | `10004d80` | `UNCONDITIONAL_CALL` | FUN_10004d80 | `10004d80` |

## Callers

| From | Function |
| --- | --- |
| `10004a8a` | FUN_10004a80 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10004bd5` | `1002d908` | `DATA` | LAB_1002d908 |
| `10004bda` | `ffdff000` | `READ` | ExceptionList |
| `10004be2` | `10037490` | `READ` | DAT_10037490 |
| `10004bed` | `ffdff000` | `WRITE` | ExceptionList |
| `10004c17` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10004bd0` | `55` | `PUSH EBP` |
| `10004bd1` | `8b ec` | `MOV EBP,ESP` |
| `10004bd3` | `6a ff` | `PUSH -0x1` |
| `10004bd5` | `68 08 d9 02 10` | `PUSH 0x1002d908` |
| `10004bda` | `64 a1 00 00 00 00` | `MOV EAX,FS:[0x0]` |
| `10004be0` | `50` | `PUSH EAX` |
| `10004be1` | `51` | `PUSH ECX` |
| `10004be2` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10004be7` | `33 c5` | `XOR EAX,EBP` |
| `10004be9` | `50` | `PUSH EAX` |
| `10004bea` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10004bed` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10004bf3` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `10004bf6` | `c7 45 fc 00 00 00 00` | `MOV dword ptr [EBP + -0x4],0x0` |
| `10004bfd` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `10004c00` | `e8 7b 09 00 00` | `CALL 0x10005580` |
| `10004c05` | `c7 45 fc ff ff ff ff` | `MOV dword ptr [EBP + -0x4],0xffffffff` |
| `10004c0c` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `10004c0f` | `e8 6c 01 00 00` | `CALL 0x10004d80` |
| `10004c14` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10004c17` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `10004c1e` | `59` | `POP ECX` |
| `10004c1f` | `8b e5` | `MOV ESP,EBP` |
| `10004c21` | `5d` | `POP EBP` |
| `10004c22` | `c3` | `RET` |
