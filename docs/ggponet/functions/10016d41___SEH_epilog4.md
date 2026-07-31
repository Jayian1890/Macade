# 10016d41 `__SEH_epilog4`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016d41 |
| `name` | __SEH_epilog4 |
| `namespace` | Global |
| `signature` | undefined __SEH_epilog4(void) |
| `size_bytes` | 20 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __SEH_epilog4 |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __SEH_epilog4
   
   Library: Visual Studio */

void __SEH_epilog4(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100112c9` | _free |
| `100161f4` | __mtinitlocknum |
| `1001733f` | __initptd |
| `1001994d` | ___crtInitCritSecAndSpinCount |
| `1001130f` | _V6_HeapAlloc |
| `1001ac18` | __calloc_impl |
| `10011b23` | __fsopen |
| `10012dc6` | _getenv |
| `100182f3` | __getstream |
| `1001a3de` | __write |
| `1001baba` | __lseeki64 |
| `1001bdd1` | ___updatetmbcinfo |
| `1001c542` | ___updatetlocinfo |
| `1001d555` | __sopen_helper |
| `1001dcb9` | ___lock_fhandle |
| `1001de7f` | __alloc_osfhnd |
| `10012c9d` | _realloc |
| `1001cb5e` | __msize |
| `10012163` | _fprintf |
| `1001227e` | vfprintf_helper |
| `10014656` | _fflush |
| `10014604` | flsall |
| `1001a4bf` | __commit |
| `1001798b` | __onexit |
| `10014894` | ___DllMainCRTStartup |
| `100126a6` | doexit |
| `100174ff` | __freefls@4 |
| `1001912f` | __ioinit |
| `1001c236` | __setmbcp |
| `10011da3` | _fread_s |
| `10011ec7` | _fclose |
| `10018c35` | __read |
| `10018dd0` | __close |
| `1001785d` | type_info::_Type_info_dtor |
| `1001add0` | ___FrameUnwindToState |
| `100198cf` | _raise |
| `1001ae79` | ___DestructExceptionObject |
| `1001b093` | CallCatchBlock |
| `1001b318` | ___BuildCatchObject |
| `1001b293` | ___BuildCatchObjectHelper |
| `10015052` | FUN_10015008 |
| `100123f3` | _puts |
| `10012028` | _printf |
| `1002d2b6` | ___set_fpsr_sse2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016d44` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016d41` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `10016d44` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `10016d4b` | `59` | `POP ECX` |
| `10016d4c` | `5f` | `POP EDI` |
| `10016d4d` | `5f` | `POP EDI` |
| `10016d4e` | `5e` | `POP ESI` |
| `10016d4f` | `5b` | `POP EBX` |
| `10016d50` | `8b e5` | `MOV ESP,EBP` |
| `10016d52` | `5d` | `POP EBP` |
| `10016d53` | `51` | `PUSH ECX` |
| `10016d54` | `c3` | `RET` |
