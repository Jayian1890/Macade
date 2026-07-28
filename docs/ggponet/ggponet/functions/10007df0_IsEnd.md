# 10007df0 `IsEnd`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10007df0 |
| `name` | IsEnd |
| `namespace` | Global |
| `signature` | undefined IsEnd(void) |
| `size_bytes` | 25 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | IsEnd |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    public: bool __thiscall CTypedPtrListIterator<class CList<void *,void *>,struct
   COleControlSiteOrWnd *>::IsEnd(void)const 
    public: bool __thiscall CTypedPtrListIterator<class CPtrList,struct COleControlSiteOrWnd
   *>::IsEnd(void)const 
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

bool IsEnd(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x1c) == 0;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10002b3c` | FUN_10002b30 |
| `100057cd` | FUN_100057c0 |
| `10007fcc` | FUN_10007fc0 |
| `1000830d` | FUN_10008300 |
| `1000303c` | FUN_10003030 |
| `100030fd` | FUN_100030f0 |
| `1000413c` | FUN_10004130 |
| `1000422d` | FUN_10004220 |
| `1000ab3c` | FUN_1000ab30 |
| `1000abfd` | FUN_1000abf0 |
| `100037cc` | FUN_100037c0 |
| `1000388d` | FUN_10003880 |
| `10002ebd` | FUN_10002eb0 |
| `10003e8a` | FUN_10003e80 |
| `10007e3d` | FUN_10007e30 |
| `1000a9bd` | FUN_1000a9b0 |
| `1000364d` | FUN_10003640 |
| `10003fbd` | FUN_10003fb0 |
| `10008abd` | FUN_10008ab0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10007df0` | `55` | `PUSH EBP` |
| `10007df1` | `8b ec` | `MOV EBP,ESP` |
| `10007df3` | `51` | `PUSH ECX` |
| `10007df4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10007df7` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10007dfa` | `33 c9` | `XOR ECX,ECX` |
| `10007dfc` | `83 78 1c 00` | `CMP dword ptr [EAX + 0x1c],0x0` |
| `10007e00` | `0f 94 c1` | `SETZ CL` |
| `10007e03` | `8a c1` | `MOV AL,CL` |
| `10007e05` | `8b e5` | `MOV ESP,EBP` |
| `10007e07` | `5d` | `POP EBP` |
| `10007e08` | `c3` | `RET` |
