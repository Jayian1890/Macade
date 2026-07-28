# 10011e7e `_fclose`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011e7e |
| `name` | _fclose |
| `namespace` | Global |
| `signature` | int __cdecl _fclose(FILE * _File) |
| `size_bytes` | 113 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _fclose |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 2008 Release */

int __cdecl _fclose(FILE *_File)

{
  int *piVar1;
  int local_20;
  
  local_20 = -1;
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    local_20 = -1;
  }
  else if ((_File->_flag & 0x40) == 0) {
    __lock_file(_File);
    local_20 = __fclose_nolock(_File);
    FUN_10011ef2();
  }
  else {
    _File->_flag = 0;
  }
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011e85` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `10011e9e` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011eae` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10011ec7` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |
| `10011ece` | `10017e26` | `UNCONDITIONAL_CALL` | __lock_file | `10017e26` |
| `10011ed8` | `10011e07` | `UNCONDITIONAL_CALL` | __fclose_nolock | `10011e07` |
| `10011ee8` | `10011ef2` | `UNCONDITIONAL_CALL` | FUN_10011ef2 | `10011ef2` |

## Callers

| From | Function |
| --- | --- |
| `10027e4a` | FUN_10027b70 |
| `100273e4` | FUN_100273b0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10011e80` | `10033cb8` | `DATA` | DAT_10033cb8 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011e7e` | `6a 0c` | `PUSH 0xc` |
| `10011e80` | `68 b8 3c 03 10` | `PUSH 0x10033cb8` |
| `10011e85` | `e8 72 4e 00 00` | `CALL 0x10016cfc` |
| `10011e8a` | `83 4d e4 ff` | `OR dword ptr [EBP + -0x1c],0xffffffff` |
| `10011e8e` | `33 c0` | `XOR EAX,EAX` |
| `10011e90` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10011e93` | `33 ff` | `XOR EDI,EDI` |
| `10011e95` | `3b f7` | `CMP ESI,EDI` |
| `10011e97` | `0f 95 c0` | `SETNZ AL` |
| `10011e9a` | `3b c7` | `CMP EAX,EDI` |
| `10011e9c` | `75 1d` | `JNZ 0x10011ebb` |
| `10011e9e` | `e8 66 32 00 00` | `CALL 0x10015109` |
| `10011ea3` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10011ea9` | `57` | `PUSH EDI` |
| `10011eaa` | `57` | `PUSH EDI` |
| `10011eab` | `57` | `PUSH EDI` |
| `10011eac` | `57` | `PUSH EDI` |
| `10011ead` | `57` | `PUSH EDI` |
| `10011eae` | `e8 fc f7 ff ff` | `CALL 0x100116af` |
| `10011eb3` | `83 c4 14` | `ADD ESP,0x14` |
| `10011eb6` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10011eb9` | `eb 0c` | `JMP 0x10011ec7` |
| `10011ebb` | `f6 46 0c 40` | `TEST byte ptr [ESI + 0xc],0x40` |
| `10011ebf` | `74 0c` | `JZ 0x10011ecd` |
| `10011ec1` | `89 7e 0c` | `MOV dword ptr [ESI + 0xc],EDI` |
| `10011ec4` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `10011ec7` | `e8 75 4e 00 00` | `CALL 0x10016d41` |
| `10011ecc` | `c3` | `RET` |
| `10011ecd` | `56` | `PUSH ESI` |
| `10011ece` | `e8 53 5f 00 00` | `CALL 0x10017e26` |
| `10011ed3` | `59` | `POP ECX` |
| `10011ed4` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10011ed7` | `56` | `PUSH ESI` |
| `10011ed8` | `e8 2a ff ff ff` | `CALL 0x10011e07` |
| `10011edd` | `59` | `POP ECX` |
| `10011ede` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10011ee1` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10011ee8` | `e8 05 00 00 00` | `CALL 0x10011ef2` |
| `10011eed` | `eb d5` | `JMP 0x10011ec4` |
