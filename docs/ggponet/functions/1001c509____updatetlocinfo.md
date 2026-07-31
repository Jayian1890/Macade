# 1001c509 `___updatetlocinfo`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c509 |
| `name` | ___updatetlocinfo |
| `namespace` | Global |
| `signature` | pthreadlocinfo __cdecl ___updatetlocinfo(void) |
| `size_bytes` | 106 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___updatetlocinfo |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetlocinfo
   
   Library: Visual Studio 2008 Release */

pthreadlocinfo __cdecl ___updatetlocinfo(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (((p_Var1->_ownlocale & DAT_10038144) == 0) || (p_Var1->ptlocinfo == (pthreadlocinfo)0x0)) {
    __lock(0xc);
    __updatetlocinfoEx_nolock();
    FUN_1001c573();
  }
  else {
    p_Var1 = __getptd();
    p_Var1 = (_ptiddata)p_Var1->ptlocinfo;
  }
  if (p_Var1 == (_ptiddata)0x0) {
    __amsg_exit(0x20);
  }
  return (pthreadlocinfo)p_Var1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c510` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001c515` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001c52c` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001c53a` | `1001243c` | `UNCONDITIONAL_CALL` | __amsg_exit | `1001243c` |
| `1001c542` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |
| `1001c54a` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001c55d` | `1001c4cb` | `UNCONDITIONAL_CALL` | __updatetlocinfoEx_nolock | `1001c4cb` |
| `1001c56c` | `1001c573` | `UNCONDITIONAL_CALL` | FUN_1001c573 | `1001c573` |

## Callers

| From | Function |
| --- | --- |
| `100152f1` | _LocaleUpdate::_LocaleUpdate |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c50b` | `10034210` | `DATA` | DAT_10034210 |
| `1001c51c` | `10038144` | `READ` | DAT_10038144 |
| `1001c557` | `10038228` | `READ` | PTR_DAT_10038228 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c509` | `6a 0c` | `PUSH 0xc` |
| `1001c50b` | `68 10 42 03 10` | `PUSH 0x10034210` |
| `1001c510` | `e8 e7 a7 ff ff` | `CALL 0x10016cfc` |
| `1001c515` | `e8 bc ae ff ff` | `CALL 0x100173d6` |
| `1001c51a` | `8b f0` | `MOV ESI,EAX` |
| `1001c51c` | `a1 44 81 03 10` | `MOV EAX,[0x10038144]` |
| `1001c521` | `85 46 70` | `TEST dword ptr [ESI + 0x70],EAX` |
| `1001c524` | `74 22` | `JZ 0x1001c548` |
| `1001c526` | `83 7e 6c 00` | `CMP dword ptr [ESI + 0x6c],0x0` |
| `1001c52a` | `74 1c` | `JZ 0x1001c548` |
| `1001c52c` | `e8 a5 ae ff ff` | `CALL 0x100173d6` |
| `1001c531` | `8b 70 6c` | `MOV ESI,dword ptr [EAX + 0x6c]` |
| `1001c534` | `85 f6` | `TEST ESI,ESI` |
| `1001c536` | `75 08` | `JNZ 0x1001c540` |
| `1001c538` | `6a 20` | `PUSH 0x20` |
| `1001c53a` | `e8 fd 5e ff ff` | `CALL 0x1001243c` |
| `1001c53f` | `59` | `POP ECX` |
| `1001c540` | `8b c6` | `MOV EAX,ESI` |
| `1001c542` | `e8 fa a7 ff ff` | `CALL 0x10016d41` |
| `1001c547` | `c3` | `RET` |
| `1001c548` | `6a 0c` | `PUSH 0xc` |
| `1001c54a` | `e8 b4 9c ff ff` | `CALL 0x10016203` |
| `1001c54f` | `59` | `POP ECX` |
| `1001c550` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001c554` | `8d 46 6c` | `LEA EAX,[ESI + 0x6c]` |
| `1001c557` | `8b 3d 28 82 03 10` | `MOV EDI,dword ptr [0x10038228]` |
| `1001c55d` | `e8 69 ff ff ff` | `CALL 0x1001c4cb` |
| `1001c562` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001c565` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001c56c` | `e8 02 00 00 00` | `CALL 0x1001c573` |
| `1001c571` | `eb c1` | `JMP 0x1001c534` |
