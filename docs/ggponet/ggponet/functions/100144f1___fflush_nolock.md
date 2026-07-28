# 100144f1 `__fflush_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100144f1 |
| `name` | __fflush_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __fflush_nolock(FILE * _File) |
| `size_bytes` | 72 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fflush_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __fflush_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __fflush_nolock(FILE *_File)

{
  int iVar1;
  
  if (_File == (FILE *)0x0) {
    iVar1 = flsall(0);
  }
  else {
    iVar1 = __flush(_File);
    if (iVar1 == 0) {
      if ((_File->_flag & 0x4000U) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = __fileno(_File);
        iVar1 = __commit(iVar1);
        iVar1 = -(uint)(iVar1 != 0);
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100144ff` | `10014539` | `UNCONDITIONAL_CALL` | flsall | `10014539` |
| `10014508` | `10014489` | `UNCONDITIONAL_CALL` | __flush | `10014489` |
| `10014521` | `10018c45` | `UNCONDITIONAL_CALL` | __fileno | `10018c45` |
| `10014527` | `1001a3ee` | `UNCONDITIONAL_CALL` | __commit | `1001a3ee` |

## Callers

| From | Function |
| --- | --- |
| `1001463e` | _fflush |
| `100145a2` | flsall |
| `100145bd` | flsall |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100144f1` | `8b ff` | `MOV EDI,EDI` |
| `100144f3` | `55` | `PUSH EBP` |
| `100144f4` | `8b ec` | `MOV EBP,ESP` |
| `100144f6` | `56` | `PUSH ESI` |
| `100144f7` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `100144fa` | `85 f6` | `TEST ESI,ESI` |
| `100144fc` | `75 09` | `JNZ 0x10014507` |
| `100144fe` | `56` | `PUSH ESI` |
| `100144ff` | `e8 35 00 00 00` | `CALL 0x10014539` |
| `10014504` | `59` | `POP ECX` |
| `10014505` | `eb 2f` | `JMP 0x10014536` |
| `10014507` | `56` | `PUSH ESI` |
| `10014508` | `e8 7c ff ff ff` | `CALL 0x10014489` |
| `1001450d` | `59` | `POP ECX` |
| `1001450e` | `85 c0` | `TEST EAX,EAX` |
| `10014510` | `74 05` | `JZ 0x10014517` |
| `10014512` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10014515` | `eb 1f` | `JMP 0x10014536` |
| `10014517` | `f7 46 0c 00 40 00 00` | `TEST dword ptr [ESI + 0xc],0x4000` |
| `1001451e` | `74 14` | `JZ 0x10014534` |
| `10014520` | `56` | `PUSH ESI` |
| `10014521` | `e8 1f 47 00 00` | `CALL 0x10018c45` |
| `10014526` | `50` | `PUSH EAX` |
| `10014527` | `e8 c2 5e 00 00` | `CALL 0x1001a3ee` |
| `1001452c` | `59` | `POP ECX` |
| `1001452d` | `f7 d8` | `NEG EAX` |
| `1001452f` | `59` | `POP ECX` |
| `10014530` | `1b c0` | `SBB EAX,EAX` |
| `10014532` | `eb 02` | `JMP 0x10014536` |
| `10014534` | `33 c0` | `XOR EAX,EAX` |
| `10014536` | `5e` | `POP ESI` |
| `10014537` | `5d` | `POP EBP` |
| `10014538` | `c3` | `RET` |
