# 1002a51c `__cftoe`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a51c |
| `name` | __cftoe |
| `namespace` | Global |
| `signature` | errno_t __cdecl __cftoe(double * _Value, char * _Buf, size_t _SizeInBytes, int _Dec, int _Caps) |
| `size_bytes` | 32 |
| `stack_frame_size` | 24 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __cftoe |

## Decompiled C

```c

/* Library Function - Single Match
    __cftoe
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl __cftoe(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec,int _Caps)

{
  errno_t eVar1;
  
  eVar1 = __cftoe_l(_Value,_Buf,_SizeInBytes,_Dec,_Caps,0);
  return eVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a532` | `1002a44c` | `UNCONDITIONAL_CALL` | __cftoe_l | `1002a44c` |

## Callers

| From | Function |
| --- | --- |
| `1002a5fb` | __cftoa_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a51c` | `8b ff` | `MOV EDI,EDI` |
| `1002a51e` | `55` | `PUSH EBP` |
| `1002a51f` | `8b ec` | `MOV EBP,ESP` |
| `1002a521` | `6a 00` | `PUSH 0x0` |
| `1002a523` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002a526` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002a529` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002a52c` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002a52f` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002a532` | `e8 15 ff ff ff` | `CALL 0x1002a44c` |
| `1002a537` | `83 c4 18` | `ADD ESP,0x18` |
| `1002a53a` | `5d` | `POP EBP` |
| `1002a53b` | `c3` | `RET` |
