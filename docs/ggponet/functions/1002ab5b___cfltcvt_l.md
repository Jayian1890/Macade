# 1002ab5b `__cfltcvt_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002ab5b |
| `name` | __cfltcvt_l |
| `namespace` | Global |
| `signature` | errno_t __cdecl __cfltcvt_l(double * arg, char * buffer, size_t sizeInBytes, int format, int precision, int caps, _locale_t plocinfo) |
| `size_bytes` | 136 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __cfltcvt_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cfltcvt_l
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl
__cfltcvt_l(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps,
           _locale_t plocinfo)

{
  errno_t eVar1;
  
  if ((format == 0x65) || (format == 0x45)) {
    eVar1 = __cftoe_l(arg,buffer,sizeInBytes,precision,caps,plocinfo);
  }
  else {
    if (format == 0x66) {
      eVar1 = __cftof_l(arg,buffer,sizeInBytes,precision,plocinfo);
      return eVar1;
    }
    if ((format == 0x61) || (format == 0x41)) {
      eVar1 = __cftoa_l(arg,buffer,sizeInBytes,precision,caps,plocinfo);
    }
    else {
      eVar1 = __cftog_l(arg,buffer,sizeInBytes,precision,caps,plocinfo);
    }
  }
  return eVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002ab81` | `1002a9a6` | `UNCONDITIONAL_CALL` | __cftof_l | `1002a9a6` |
| `1002aba7` | `1002aa61` | `UNCONDITIONAL_CALL` | __cftog_l | `1002aa61` |
| `1002abc0` | `1002a53c` | `UNCONDITIONAL_CALL` | __cftoa_l | `1002a53c` |
| `1002abd9` | `1002a44c` | `UNCONDITIONAL_CALL` | __cftoe_l | `1002a44c` |

## Callers

| From | Function |
| --- | --- |
| `1002abfc` | __cfltcvt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002ab5b` | `8b ff` | `MOV EDI,EDI` |
| `1002ab5d` | `55` | `PUSH EBP` |
| `1002ab5e` | `8b ec` | `MOV EBP,ESP` |
| `1002ab60` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1002ab63` | `83 f8 65` | `CMP EAX,0x65` |
| `1002ab66` | `74 5f` | `JZ 0x1002abc7` |
| `1002ab68` | `83 f8 45` | `CMP EAX,0x45` |
| `1002ab6b` | `74 5a` | `JZ 0x1002abc7` |
| `1002ab6d` | `83 f8 66` | `CMP EAX,0x66` |
| `1002ab70` | `75 19` | `JNZ 0x1002ab8b` |
| `1002ab72` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1002ab75` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002ab78` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002ab7b` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002ab7e` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002ab81` | `e8 20 fe ff ff` | `CALL 0x1002a9a6` |
| `1002ab86` | `83 c4 14` | `ADD ESP,0x14` |
| `1002ab89` | `5d` | `POP EBP` |
| `1002ab8a` | `c3` | `RET` |
| `1002ab8b` | `83 f8 61` | `CMP EAX,0x61` |
| `1002ab8e` | `74 1e` | `JZ 0x1002abae` |
| `1002ab90` | `83 f8 41` | `CMP EAX,0x41` |
| `1002ab93` | `74 19` | `JZ 0x1002abae` |
| `1002ab95` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1002ab98` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002ab9b` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002ab9e` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002aba1` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002aba4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002aba7` | `e8 b5 fe ff ff` | `CALL 0x1002aa61` |
| `1002abac` | `eb 30` | `JMP 0x1002abde` |
| `1002abae` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1002abb1` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002abb4` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002abb7` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002abba` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002abbd` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002abc0` | `e8 77 f9 ff ff` | `CALL 0x1002a53c` |
| `1002abc5` | `eb 17` | `JMP 0x1002abde` |
| `1002abc7` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1002abca` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002abcd` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002abd0` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002abd3` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002abd6` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002abd9` | `e8 6e f8 ff ff` | `CALL 0x1002a44c` |
| `1002abde` | `83 c4 18` | `ADD ESP,0x18` |
| `1002abe1` | `5d` | `POP EBP` |
| `1002abe2` | `c3` | `RET` |
