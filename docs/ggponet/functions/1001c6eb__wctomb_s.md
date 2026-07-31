# 1001c6eb `_wctomb_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c6eb |
| `name` | _wctomb_s |
| `namespace` | Global |
| `signature` | errno_t __cdecl _wctomb_s(int * _SizeConverted, char * _MbCh, rsize_t _SizeInBytes, wchar_t _WCh) |
| `size_bytes` | 29 |
| `stack_frame_size` | 18 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _wctomb_s |

## Decompiled C

```c

/* Library Function - Single Match
    _wctomb_s
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl _wctomb_s(int *_SizeConverted,char *_MbCh,rsize_t _SizeInBytes,wchar_t _WCh)

{
  errno_t eVar1;
  
  eVar1 = __wctomb_s_l(_SizeConverted,_MbCh,_SizeInBytes,_WCh,(_locale_t)0x0);
  return eVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c6fe` | `1001c57f` | `UNCONDITIONAL_CALL` | __wctomb_s_l | `1001c57f` |

## Callers

| From | Function |
| --- | --- |
| `10015917` | __output_l |
| `10015e7d` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c6eb` | `8b ff` | `MOV EDI,EDI` |
| `1001c6ed` | `55` | `PUSH EBP` |
| `1001c6ee` | `8b ec` | `MOV EBP,ESP` |
| `1001c6f0` | `6a 00` | `PUSH 0x0` |
| `1001c6f2` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001c6f5` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001c6f8` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001c6fb` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001c6fe` | `e8 7c fe ff ff` | `CALL 0x1001c57f` |
| `1001c703` | `83 c4 14` | `ADD ESP,0x14` |
| `1001c706` | `5d` | `POP EBP` |
| `1001c707` | `c3` | `RET` |
