# 10011a6f `__fsopen`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011a6f |
| `name` | __fsopen |
| `namespace` | Global |
| `signature` | FILE * __cdecl __fsopen(char * _Filename, char * _Mode, int _ShFlag) |
| `size_bytes` | 186 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fsopen |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 2008 Release */

FILE * __cdecl __fsopen(char *_Filename,char *_Mode,int _ShFlag)

{
  int *piVar1;
  FILE *pFVar2;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_10033c78;
  uStack_c = 0x10011a7b;
  if (((_Filename == (char *)0x0) || (_Mode == (char *)0x0)) || (*_Mode == '\0')) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
  }
  else {
    pFVar2 = __getstream();
    if (pFVar2 == (FILE *)0x0) {
      piVar1 = __errno();
      *piVar1 = 0x18;
    }
    else {
      local_8 = (undefined *)0x0;
      if (*_Filename != '\0') {
        pFVar2 = __openfile(_Filename,_Mode,_ShFlag,pFVar2);
        local_8 = (undefined *)0xfffffffe;
        FUN_10011b29();
        return pFVar2;
      }
      piVar1 = __errno();
      *piVar1 = 0x16;
      __local_unwind4(&DAT_10037490,local_14,0xfffffffe);
    }
  }
  return (FILE *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011a76` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `10011a8e` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011a9e` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10011ac3` | `100181cd` | `UNCONDITIONAL_CALL` | __getstream | `100181cd` |
| `10011acf` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011ae3` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011af9` | `10018308` | `UNCONDITIONAL_CALL` | __local_unwind4 | `10018308` |
| `10011b09` | `10017f04` | `UNCONDITIONAL_CALL` | __openfile | `10017f04` |
| `10011b1b` | `10011b29` | `UNCONDITIONAL_CALL` | FUN_10011b29 | `10011b29` |
| `10011b23` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `10011b40` | _fopen |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10011a71` | `10033c78` | `DATA` | DAT_10033c78 |
| `10011af4` | `10037490` | `DATA` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011a6f` | `6a 0c` | `PUSH 0xc` |
| `10011a71` | `68 78 3c 03 10` | `PUSH 0x10033c78` |
| `10011a76` | `e8 81 52 00 00` | `CALL 0x10016cfc` |
| `10011a7b` | `33 db` | `XOR EBX,EBX` |
| `10011a7d` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `10011a80` | `33 c0` | `XOR EAX,EAX` |
| `10011a82` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10011a85` | `3b fb` | `CMP EDI,EBX` |
| `10011a87` | `0f 95 c0` | `SETNZ AL` |
| `10011a8a` | `3b c3` | `CMP EAX,EBX` |
| `10011a8c` | `75 1c` | `JNZ 0x10011aaa` |
| `10011a8e` | `e8 76 36 00 00` | `CALL 0x10015109` |
| `10011a93` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10011a99` | `53` | `PUSH EBX` |
| `10011a9a` | `53` | `PUSH EBX` |
| `10011a9b` | `53` | `PUSH EBX` |
| `10011a9c` | `53` | `PUSH EBX` |
| `10011a9d` | `53` | `PUSH EBX` |
| `10011a9e` | `e8 0c fc ff ff` | `CALL 0x100116af` |
| `10011aa3` | `83 c4 14` | `ADD ESP,0x14` |
| `10011aa6` | `33 c0` | `XOR EAX,EAX` |
| `10011aa8` | `eb 79` | `JMP 0x10011b23` |
| `10011aaa` | `33 c0` | `XOR EAX,EAX` |
| `10011aac` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10011aaf` | `3b f3` | `CMP ESI,EBX` |
| `10011ab1` | `0f 95 c0` | `SETNZ AL` |
| `10011ab4` | `3b c3` | `CMP EAX,EBX` |
| `10011ab6` | `74 d6` | `JZ 0x10011a8e` |
| `10011ab8` | `33 c0` | `XOR EAX,EAX` |
| `10011aba` | `38 1e` | `CMP byte ptr [ESI],BL` |
| `10011abc` | `0f 95 c0` | `SETNZ AL` |
| `10011abf` | `3b c3` | `CMP EAX,EBX` |
| `10011ac1` | `74 cb` | `JZ 0x10011a8e` |
| `10011ac3` | `e8 05 67 00 00` | `CALL 0x100181cd` |
| `10011ac8` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `10011acb` | `3b c3` | `CMP EAX,EBX` |
| `10011acd` | `75 0d` | `JNZ 0x10011adc` |
| `10011acf` | `e8 35 36 00 00` | `CALL 0x10015109` |
| `10011ad4` | `c7 00 18 00 00 00` | `MOV dword ptr [EAX],0x18` |
| `10011ada` | `eb ca` | `JMP 0x10011aa6` |
| `10011adc` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `10011adf` | `38 1f` | `CMP byte ptr [EDI],BL` |
| `10011ae1` | `75 20` | `JNZ 0x10011b03` |
| `10011ae3` | `e8 21 36 00 00` | `CALL 0x10015109` |
| `10011ae8` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10011aee` | `6a fe` | `PUSH -0x2` |
| `10011af0` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `10011af3` | `50` | `PUSH EAX` |
| `10011af4` | `68 90 74 03 10` | `PUSH 0x10037490` |
| `10011af9` | `e8 0a 68 00 00` | `CALL 0x10018308` |
| `10011afe` | `83 c4 0c` | `ADD ESP,0xc` |
| `10011b01` | `eb a3` | `JMP 0x10011aa6` |
| `10011b03` | `50` | `PUSH EAX` |
| `10011b04` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10011b07` | `56` | `PUSH ESI` |
| `10011b08` | `57` | `PUSH EDI` |
| `10011b09` | `e8 f6 63 00 00` | `CALL 0x10017f04` |
| `10011b0e` | `83 c4 10` | `ADD ESP,0x10` |
| `10011b11` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10011b14` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10011b1b` | `e8 09 00 00 00` | `CALL 0x10011b29` |
| `10011b20` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `10011b23` | `e8 19 52 00 00` | `CALL 0x10016d41` |
| `10011b28` | `c3` | `RET` |
