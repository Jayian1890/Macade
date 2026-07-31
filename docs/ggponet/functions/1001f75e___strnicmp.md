# 1001f75e `__strnicmp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f75e |
| `name` | __strnicmp |
| `namespace` | Global |
| `signature` | int __cdecl __strnicmp(char * _Str1, char * _Str2, size_t _MaxCount) |
| `size_bytes` | 94 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __strnicmp |

## Decompiled C

```c

/* Library Function - Single Match
    __strnicmp
   
   Library: Visual Studio 2008 Release */

int __cdecl __strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_100393a0 == 0) {
    if (((_Str1 != (char *)0x0) && (_Str2 != (char *)0x0)) && (_MaxCount < 0x80000000)) {
      iVar2 = ___ascii_strnicmp(_Str1,_Str2,_MaxCount);
      return iVar2;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = 0x7fffffff;
  }
  else {
    iVar2 = __strnicmp_l(_Str1,_Str2,_MaxCount,(_locale_t)0x0);
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f773` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f783` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001f7a2` | `1001fc70` | `UNCONDITIONAL_CALL` | ___ascii_strnicmp | `1001fc70` |
| `1001f7b1` | `1001f66c` | `UNCONDITIONAL_CALL` | __strnicmp_l | `1001f66c` |

## Callers

| From | Function |
| --- | --- |
| `1001d5ed` | __mbsnbicmp_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f766` | `100393a0` | `READ` | DAT_100393a0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f75e` | `8b ff` | `MOV EDI,EDI` |
| `1001f760` | `55` | `PUSH EBP` |
| `1001f761` | `8b ec` | `MOV EBP,ESP` |
| `1001f763` | `56` | `PUSH ESI` |
| `1001f764` | `33 f6` | `XOR ESI,ESI` |
| `1001f766` | `39 35 a0 93 03 10` | `CMP dword ptr [0x100393a0],ESI` |
| `1001f76c` | `75 39` | `JNZ 0x1001f7a7` |
| `1001f76e` | `39 75 08` | `CMP dword ptr [EBP + 0x8],ESI` |
| `1001f771` | `75 1f` | `JNZ 0x1001f792` |
| `1001f773` | `e8 91 59 ff ff` | `CALL 0x10015109` |
| `1001f778` | `56` | `PUSH ESI` |
| `1001f779` | `56` | `PUSH ESI` |
| `1001f77a` | `56` | `PUSH ESI` |
| `1001f77b` | `56` | `PUSH ESI` |
| `1001f77c` | `56` | `PUSH ESI` |
| `1001f77d` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001f783` | `e8 27 1f ff ff` | `CALL 0x100116af` |
| `1001f788` | `83 c4 14` | `ADD ESP,0x14` |
| `1001f78b` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001f790` | `eb 27` | `JMP 0x1001f7b9` |
| `1001f792` | `39 75 0c` | `CMP dword ptr [EBP + 0xc],ESI` |
| `1001f795` | `74 dc` | `JZ 0x1001f773` |
| `1001f797` | `81 7d 10 ff ff ff 7f` | `CMP dword ptr [EBP + 0x10],0x7fffffff` |
| `1001f79e` | `77 d3` | `JA 0x1001f773` |
| `1001f7a0` | `5e` | `POP ESI` |
| `1001f7a1` | `5d` | `POP EBP` |
| `1001f7a2` | `e9 c9 04 00 00` | `JMP 0x1001fc70` |
| `1001f7a7` | `56` | `PUSH ESI` |
| `1001f7a8` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001f7ab` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f7ae` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f7b1` | `e8 b6 fe ff ff` | `CALL 0x1001f66c` |
| `1001f7b6` | `83 c4 10` | `ADD ESP,0x10` |
| `1001f7b9` | `5e` | `POP ESI` |
| `1001f7ba` | `5d` | `POP EBP` |
| `1001f7bb` | `c3` | `RET` |
