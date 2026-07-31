# 10012173 `vfprintf_helper`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012173 |
| `name` | vfprintf_helper |
| `namespace` | Global |
| `signature` | undefined __cdecl vfprintf_helper(void) |
| `size_bytes` | 273 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _vfprintf_helper, vfprintf_helper |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _vfprintf_helper
   
   Library: Visual Studio 2008 Release */

int __cdecl
vfprintf_helper(code *param_1,FILE *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  uint uVar2;
  int _Flag;
  undefined *puVar3;
  int local_20;
  
  local_20 = 0;
  if ((param_2 == (FILE *)0x0) || (param_3 == 0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    return -1;
  }
  __lock_file(param_2);
  if ((param_2->_flag & 0x40) == 0) {
    uVar2 = __fileno(param_2);
    if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
      puVar3 = &DAT_10037b80;
    }
    else {
      puVar3 = (undefined *)((uVar2 & 0x1f) * 0x40 + (&DAT_13439540)[(int)uVar2 >> 5]);
    }
    if ((puVar3[0x24] & 0x7f) == 0) {
      if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
        puVar3 = &DAT_10037b80;
      }
      else {
        puVar3 = (undefined *)((uVar2 & 0x1f) * 0x40 + (&DAT_13439540)[(int)uVar2 >> 5]);
      }
      if ((puVar3[0x24] & 0x80) == 0) goto LAB_10012248;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    local_20 = -1;
  }
LAB_10012248:
  if (local_20 == 0) {
    _Flag = __stbuf(param_2);
    local_20 = (*param_1)(param_2,param_3,param_4,param_5);
    __ftbuf(_Flag,param_2);
  }
  FUN_10012284();
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001217a` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `10012192` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100121a2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `100121c2` | `10017e26` | `UNCONDITIONAL_CALL` | __lock_file | `10017e26` |
| `100121d2` | `10018c45` | `UNCONDITIONAL_CALL` | __fileno | `10018c45` |
| `1001222c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001223c` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001224e` | `10018e11` | `UNCONDITIONAL_CALL` | __stbuf | `10018e11` |
| `10012267` | `10018ead` | `UNCONDITIONAL_CALL` | __ftbuf | `10018ead` |
| `10012276` | `10012284` | `UNCONDITIONAL_CALL` | FUN_10012284 | `10012284` |
| `1001227e` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `100122a3` | FID_conflict:_vfprintf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012175` | `10033d18` | `DATA` | DAT_10033d18 |
| `100121ef` | `13439540` | `DATA` | DAT_13439540 |
| `100121f8` | `10037b80` | `DATA` | DAT_10037b80 |
| `100121fd` | `10037ba4` | `READ` | DAT_10037ba4 |
| `10012218` | `13439540` | `DATA` | DAT_13439540 |
| `10012221` | `10037b80` | `DATA` | DAT_10037b80 |
| `10012226` | `10037ba4` | `READ` | DAT_10037ba4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012173` | `6a 0c` | `PUSH 0xc` |
| `10012175` | `68 18 3d 03 10` | `PUSH 0x10033d18` |
| `1001217a` | `e8 7d 4b 00 00` | `CALL 0x10016cfc` |
| `1001217f` | `33 f6` | `XOR ESI,ESI` |
| `10012181` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `10012184` | `33 c0` | `XOR EAX,EAX` |
| `10012186` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `10012189` | `3b fe` | `CMP EDI,ESI` |
| `1001218b` | `0f 95 c0` | `SETNZ AL` |
| `1001218e` | `3b c6` | `CMP EAX,ESI` |
| `10012190` | `75 20` | `JNZ 0x100121b2` |
| `10012192` | `e8 72 2f 00 00` | `CALL 0x10015109` |
| `10012197` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001219d` | `56` | `PUSH ESI` |
| `1001219e` | `56` | `PUSH ESI` |
| `1001219f` | `56` | `PUSH ESI` |
| `100121a0` | `56` | `PUSH ESI` |
| `100121a1` | `56` | `PUSH ESI` |
| `100121a2` | `e8 08 f5 ff ff` | `CALL 0x100116af` |
| `100121a7` | `83 c4 14` | `ADD ESP,0x14` |
| `100121aa` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100121ad` | `e9 cc 00 00 00` | `JMP 0x1001227e` |
| `100121b2` | `33 c0` | `XOR EAX,EAX` |
| `100121b4` | `39 75 10` | `CMP dword ptr [EBP + 0x10],ESI` |
| `100121b7` | `0f 95 c0` | `SETNZ AL` |
| `100121ba` | `3b c6` | `CMP EAX,ESI` |
| `100121bc` | `74 d4` | `JZ 0x10012192` |
| `100121be` | `89 7d 0c` | `MOV dword ptr [EBP + 0xc],EDI` |
| `100121c1` | `57` | `PUSH EDI` |
| `100121c2` | `e8 5f 5c 00 00` | `CALL 0x10017e26` |
| `100121c7` | `59` | `POP ECX` |
| `100121c8` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `100121cb` | `f6 47 0c 40` | `TEST byte ptr [EDI + 0xc],0x40` |
| `100121cf` | `75 77` | `JNZ 0x10012248` |
| `100121d1` | `57` | `PUSH EDI` |
| `100121d2` | `e8 6e 6a 00 00` | `CALL 0x10018c45` |
| `100121d7` | `59` | `POP ECX` |
| `100121d8` | `83 f8 ff` | `CMP EAX,-0x1` |
| `100121db` | `74 1b` | `JZ 0x100121f8` |
| `100121dd` | `83 f8 fe` | `CMP EAX,-0x2` |
| `100121e0` | `74 16` | `JZ 0x100121f8` |
| `100121e2` | `8b d0` | `MOV EDX,EAX` |
| `100121e4` | `c1 fa 05` | `SAR EDX,0x5` |
| `100121e7` | `8b c8` | `MOV ECX,EAX` |
| `100121e9` | `83 e1 1f` | `AND ECX,0x1f` |
| `100121ec` | `c1 e1 06` | `SHL ECX,0x6` |
| `100121ef` | `03 0c 95 40 95 43 13` | `ADD ECX,dword ptr [EDX*0x4 + 0x13439540]` |
| `100121f6` | `eb 05` | `JMP 0x100121fd` |
| `100121f8` | `b9 80 7b 03 10` | `MOV ECX,0x10037b80` |
| `100121fd` | `f6 41 24 7f` | `TEST byte ptr [ECX + 0x24],0x7f` |
| `10012201` | `75 29` | `JNZ 0x1001222c` |
| `10012203` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10012206` | `74 19` | `JZ 0x10012221` |
| `10012208` | `83 f8 fe` | `CMP EAX,-0x2` |
| `1001220b` | `74 14` | `JZ 0x10012221` |
| `1001220d` | `8b c8` | `MOV ECX,EAX` |
| `1001220f` | `c1 f9 05` | `SAR ECX,0x5` |
| `10012212` | `83 e0 1f` | `AND EAX,0x1f` |
| `10012215` | `c1 e0 06` | `SHL EAX,0x6` |
| `10012218` | `03 04 8d 40 95 43 13` | `ADD EAX,dword ptr [ECX*0x4 + 0x13439540]` |
| `1001221f` | `eb 05` | `JMP 0x10012226` |
| `10012221` | `b8 80 7b 03 10` | `MOV EAX,0x10037b80` |
| `10012226` | `f6 40 24 80` | `TEST byte ptr [EAX + 0x24],0x80` |
| `1001222a` | `74 1c` | `JZ 0x10012248` |
| `1001222c` | `e8 d8 2e 00 00` | `CALL 0x10015109` |
| `10012231` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10012237` | `56` | `PUSH ESI` |
| `10012238` | `56` | `PUSH ESI` |
| `10012239` | `56` | `PUSH ESI` |
| `1001223a` | `56` | `PUSH ESI` |
| `1001223b` | `56` | `PUSH ESI` |
| `1001223c` | `e8 6e f4 ff ff` | `CALL 0x100116af` |
| `10012241` | `83 c4 14` | `ADD ESP,0x14` |
| `10012244` | `83 4d e4 ff` | `OR dword ptr [EBP + -0x1c],0xffffffff` |
| `10012248` | `39 75 e4` | `CMP dword ptr [EBP + -0x1c],ESI` |
| `1001224b` | `75 22` | `JNZ 0x1001226f` |
| `1001224d` | `57` | `PUSH EDI` |
| `1001224e` | `e8 be 6b 00 00` | `CALL 0x10018e11` |
| `10012253` | `8b f0` | `MOV ESI,EAX` |
| `10012255` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `10012258` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001225b` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001225e` | `57` | `PUSH EDI` |
| `1001225f` | `ff 55 08` | `CALL dword ptr [EBP + 0x8]` |
| `10012262` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10012265` | `57` | `PUSH EDI` |
| `10012266` | `56` | `PUSH ESI` |
| `10012267` | `e8 41 6c 00 00` | `CALL 0x10018ead` |
| `1001226c` | `83 c4 1c` | `ADD ESP,0x1c` |
| `1001226f` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10012276` | `e8 09 00 00 00` | `CALL 0x10012284` |
| `1001227b` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001227e` | `e8 be 4a 00 00` | `CALL 0x10016d41` |
| `10012283` | `c3` | `RET` |
