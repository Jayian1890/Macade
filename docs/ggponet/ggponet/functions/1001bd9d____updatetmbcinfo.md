# 1001bd9d `___updatetmbcinfo`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001bd9d |
| `name` | ___updatetmbcinfo |
| `namespace` | Global |
| `signature` | pthreadmbcinfo __cdecl ___updatetmbcinfo(void) |
| `size_bytes` | 152 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___updatetmbcinfo |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetmbcinfo
   
   Library: Visual Studio 2008 Release */

pthreadmbcinfo __cdecl ___updatetmbcinfo(void)

{
  _ptiddata p_Var1;
  LONG LVar2;
  pthreadmbcinfo lpAddend;
  
  p_Var1 = __getptd();
  if (((p_Var1->_ownlocale & DAT_10038144) == 0) || (p_Var1->ptlocinfo == (pthreadlocinfo)0x0)) {
    __lock(0xd);
    lpAddend = p_Var1->ptmbcinfo;
    if (lpAddend != (pthreadmbcinfo)PTR_DAT_10038048) {
      if (lpAddend != (pthreadmbcinfo)0x0) {
        LVar2 = InterlockedDecrement(&lpAddend->refcount);
        if ((LVar2 == 0) && (lpAddend != (pthreadmbcinfo)&DAT_10037c20)) {
          _free(lpAddend);
        }
      }
      p_Var1->ptmbcinfo = (pthreadmbcinfo)PTR_DAT_10038048;
      lpAddend = (pthreadmbcinfo)PTR_DAT_10038048;
      InterlockedIncrement((LONG *)PTR_DAT_10038048);
    }
    FUN_1001be38();
  }
  else {
    lpAddend = p_Var1->ptmbcinfo;
  }
  if (lpAddend == (pthreadmbcinfo)0x0) {
    __amsg_exit(0x20);
  }
  return lpAddend;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001bda4` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001bda9` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001bdc9` | `1001243c` | `UNCONDITIONAL_CALL` | __amsg_exit | `1001243c` |
| `1001bdd1` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |
| `1001bdd9` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001bdf6` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001be09` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001be21` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001be2e` | `1001be38` | `UNCONDITIONAL_CALL` | FUN_1001be38 | `1001be38` |

## Callers

| From | Function |
| --- | --- |
| `10015311` | _LocaleUpdate::_LocaleUpdate |
| `1001c0bc` | __setmbcp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001bd9f` | `100341d0` | `DATA` | DAT_100341d0 |
| `1001bdb0` | `10038144` | `READ` | DAT_10038144 |
| `1001bde9` | `10038048` | `READ` | PTR_DAT_10038048 |
| `1001bdf6` | `1002e0f0` | `READ` | PTR_InterlockedDecrement_1002e0f0 |
| `1001be00` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001be0f` | `10038048` | `READ` | PTR_DAT_10038048 |
| `1001be14` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001be17` | `10038048` | `READ` | PTR_DAT_10038048 |
| `1001be1d` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001be20` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001be21` | `1002e0e8` | `READ` | PTR_InterlockedIncrement_1002e0e8 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001bd9d` | `6a 0c` | `PUSH 0xc` |
| `1001bd9f` | `68 d0 41 03 10` | `PUSH 0x100341d0` |
| `1001bda4` | `e8 53 af ff ff` | `CALL 0x10016cfc` |
| `1001bda9` | `e8 28 b6 ff ff` | `CALL 0x100173d6` |
| `1001bdae` | `8b f8` | `MOV EDI,EAX` |
| `1001bdb0` | `a1 44 81 03 10` | `MOV EAX,[0x10038144]` |
| `1001bdb5` | `85 47 70` | `TEST dword ptr [EDI + 0x70],EAX` |
| `1001bdb8` | `74 1d` | `JZ 0x1001bdd7` |
| `1001bdba` | `83 7f 6c 00` | `CMP dword ptr [EDI + 0x6c],0x0` |
| `1001bdbe` | `74 17` | `JZ 0x1001bdd7` |
| `1001bdc0` | `8b 77 68` | `MOV ESI,dword ptr [EDI + 0x68]` |
| `1001bdc3` | `85 f6` | `TEST ESI,ESI` |
| `1001bdc5` | `75 08` | `JNZ 0x1001bdcf` |
| `1001bdc7` | `6a 20` | `PUSH 0x20` |
| `1001bdc9` | `e8 6e 66 ff ff` | `CALL 0x1001243c` |
| `1001bdce` | `59` | `POP ECX` |
| `1001bdcf` | `8b c6` | `MOV EAX,ESI` |
| `1001bdd1` | `e8 6b af ff ff` | `CALL 0x10016d41` |
| `1001bdd6` | `c3` | `RET` |
| `1001bdd7` | `6a 0d` | `PUSH 0xd` |
| `1001bdd9` | `e8 25 a4 ff ff` | `CALL 0x10016203` |
| `1001bdde` | `59` | `POP ECX` |
| `1001bddf` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001bde3` | `8b 77 68` | `MOV ESI,dword ptr [EDI + 0x68]` |
| `1001bde6` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001bde9` | `3b 35 48 80 03 10` | `CMP ESI,dword ptr [0x10038048]` |
| `1001bdef` | `74 36` | `JZ 0x1001be27` |
| `1001bdf1` | `85 f6` | `TEST ESI,ESI` |
| `1001bdf3` | `74 1a` | `JZ 0x1001be0f` |
| `1001bdf5` | `56` | `PUSH ESI` |
| `1001bdf6` | `ff 15 f0 e0 02 10` | `CALL dword ptr [0x1002e0f0]` |
| `1001bdfc` | `85 c0` | `TEST EAX,EAX` |
| `1001bdfe` | `75 0f` | `JNZ 0x1001be0f` |
| `1001be00` | `81 fe 20 7c 03 10` | `CMP ESI,0x10037c20` |
| `1001be06` | `74 07` | `JZ 0x1001be0f` |
| `1001be08` | `56` | `PUSH ESI` |
| `1001be09` | `e8 33 54 ff ff` | `CALL 0x10011241` |
| `1001be0e` | `59` | `POP ECX` |
| `1001be0f` | `a1 48 80 03 10` | `MOV EAX,[0x10038048]` |
| `1001be14` | `89 47 68` | `MOV dword ptr [EDI + 0x68],EAX` |
| `1001be17` | `8b 35 48 80 03 10` | `MOV ESI,dword ptr [0x10038048]` |
| `1001be1d` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001be20` | `56` | `PUSH ESI` |
| `1001be21` | `ff 15 e8 e0 02 10` | `CALL dword ptr [0x1002e0e8]` |
| `1001be27` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001be2e` | `e8 05 00 00 00` | `CALL 0x1001be38` |
| `1001be33` | `eb 8e` | `JMP 0x1001bdc3` |
