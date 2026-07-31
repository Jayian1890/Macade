# 10008cd0 ``vector_constructor_iterator'`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10008cd0 |
| `name` | `vector_constructor_iterator' |
| `namespace` | Global |
| `signature` | void __stdcall `vector_constructor_iterator'(void * param_1, uint param_2, int param_3, _func_void_ptr_void_ptr * param_4) |
| `size_bytes` | 35 |
| `stack_frame_size` | 20 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | ??_H@YGXPAXIHP6EPAX0@Z@Z, `vector_constructor_iterator' |

## Decompiled C

```c

/* Library Function - Single Match
    void __stdcall `vector constructor iterator'(void *,unsigned int,int,void * (__thiscall*)(void
   *))
   
   Library: Visual Studio */

void _vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_ptr_void_ptr *param_4)

{
  void *unaff_EBP;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EBP);
  }
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002850c` | FUN_100284c0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10008cd0` | `55` | `PUSH EBP` |
| `10008cd1` | `8b ec` | `MOV EBP,ESP` |
| `10008cd3` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10008cd6` | `83 e8 01` | `SUB EAX,0x1` |
| `10008cd9` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `10008cdc` | `78 11` | `JS 0x10008cef` |
| `10008cde` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10008ce1` | `ff 55 14` | `CALL dword ptr [EBP + 0x14]` |
| `10008ce4` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10008ce7` | `03 4d 0c` | `ADD ECX,dword ptr [EBP + 0xc]` |
| `10008cea` | `89 4d 08` | `MOV dword ptr [EBP + 0x8],ECX` |
| `10008ced` | `eb e4` | `JMP 0x10008cd3` |
| `10008cef` | `5d` | `POP EBP` |
| `10008cf0` | `c2 10 00` | `RET 0x10` |
