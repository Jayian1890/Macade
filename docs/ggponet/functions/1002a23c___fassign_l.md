# 1002a23c `__fassign_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a23c |
| `name` | __fassign_l |
| `namespace` | Global |
| `signature` | void __cdecl __fassign_l(int flag, char * argument, char * number, _locale_t param_4) |
| `size_bytes` | 66 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fassign_l |

## Decompiled C

```c

/* Library Function - Single Match
    __fassign_l
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __fassign_l(int flag,char *argument,char *number,_locale_t param_4)

{
  _CRT_FLOAT local_c;
  undefined4 local_8;
  
  if (flag == 0) {
    FID_conflict___atoflt_l((_CRT_FLOAT *)&flag,number,param_4);
    *(int *)argument = flag;
  }
  else {
    FID_conflict___atoflt_l(&local_c,number,param_4);
    *(float *)argument = local_c.f;
    *(undefined4 *)(argument + 4) = local_8;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a253` | `1002accd` | `UNCONDITIONAL_CALL` | FID_conflict:__atoflt_l | `1002accd` |
| `1002a26c` | `1002ad75` | `UNCONDITIONAL_CALL` | FID_conflict:__atoflt_l | `1002ad75` |

## Callers

| From | Function |
| --- | --- |
| `1002a28e` | __fassign |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a23c` | `8b ff` | `MOV EDI,EDI` |
| `1002a23e` | `55` | `PUSH EBP` |
| `1002a23f` | `8b ec` | `MOV EBP,ESP` |
| `1002a241` | `51` | `PUSH ECX` |
| `1002a242` | `51` | `PUSH ECX` |
| `1002a243` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1002a247` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002a24a` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002a24d` | `74 19` | `JZ 0x1002a268` |
| `1002a24f` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1002a252` | `50` | `PUSH EAX` |
| `1002a253` | `e8 75 0a 00 00` | `CALL 0x1002accd` |
| `1002a258` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1002a25b` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1002a25e` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1002a260` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002a263` | `89 48 04` | `MOV dword ptr [EAX + 0x4],ECX` |
| `1002a266` | `eb 11` | `JMP 0x1002a279` |
| `1002a268` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `1002a26b` | `50` | `PUSH EAX` |
| `1002a26c` | `e8 04 0b 00 00` | `CALL 0x1002ad75` |
| `1002a271` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1002a274` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002a277` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1002a279` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002a27c` | `c9` | `LEAVE` |
| `1002a27d` | `c3` | `RET` |
