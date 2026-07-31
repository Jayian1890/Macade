# 10016cfc `__SEH_prolog4`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016cfc |
| `name` | __SEH_prolog4 |
| `namespace` | Global |
| `signature` | undefined __SEH_prolog4(void) |
| `size_bytes` | 69 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __SEH_prolog4 |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __SEH_prolog4
   
   Library: Visual Studio */

void __SEH_prolog4(undefined4 param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  param_2 = -param_2;
  *(undefined4 *)((int)auStack_1c + param_2 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + param_2 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + param_2 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + param_2 + 4) = DAT_10037490 ^ (uint)&stack0x00000008;
  *(undefined4 *)((int)auStack_1c + param_2) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10011248` | _free |
| `10016147` | __mtinitlocknum |
| `1001727d` | __initptd |
| `100198fa` | ___crtInitCritSecAndSpinCount |
| `100112d6` | _V6_HeapAlloc |
| `1001ab07` | __calloc_impl |
| `10011a76` | __fsopen |
| `10012d59` | _getenv |
| `100181d4` | __getstream |
| `1001a319` | __write |
| `1001b9b8` | __lseeki64 |
| `1001bda4` | ___updatetmbcinfo |
| `1001c510` | ___updatetlocinfo |
| `1001d4c9` | __sopen_helper |
| `1001dc34` | ___lock_fhandle |
| `1001dcfb` | __alloc_osfhnd |
| `10012ab7` | _realloc |
| `1001cad9` | __msize |
| `1001205e` | _fprintf |
| `1001217a` | vfprintf_helper |
| `1001461a` | _fflush |
| `10014540` | flsall |
| `1001a3f5` | __commit |
| `10017962` | __onexit |
| `100147ab` | ___DllMainCRTStartup |
| `10012587` | doexit |
| `100173f7` | __freefls@4 |
| `10018ee8` | __ioinit |
| `1001c0a9` | __setmbcp |
| `10011d5b` | _fread_s |
| `10011e85` | _fclose |
| `10018b4f` | __read |
| `10018d1a` | __close |
| `10017807` | type_info::_Type_info_dtor |
| `1001ad1d` | ___FrameUnwindToState |
| `10019500` | _inconsistency |
| `100194b4` | terminate |
| `1001972c` | _raise |
| `1001ae43` | ___DestructExceptionObject |
| `1001af85` | CallCatchBlock |
| `1001b2a0` | ___BuildCatchObject |
| `1001b121` | ___BuildCatchObjectHelper |
| `1001500f` | FUN_10015008 |
| `100122b4` | _puts |
| `10011f99` | _printf |
| `1002d251` | ___set_fpsr_sse2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016cfc` | `10016d60` | `DATA` | __except_handler4 |
| `10016d01` | `ffdff000` | `READ` | ExceptionList |
| `10016d19` | `10037490` | `READ` | DAT_10037490 |
| `10016d3a` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016cfc` | `68 60 6d 01 10` | `PUSH 0x10016d60` |
| `10016d01` | `64 ff 35 00 00 00 00` | `PUSH dword ptr FS:[0x0]` |
| `10016d08` | `8b 44 24 10` | `MOV EAX,dword ptr [ESP + 0x10]` |
| `10016d0c` | `89 6c 24 10` | `MOV dword ptr [ESP + 0x10],EBP` |
| `10016d10` | `8d 6c 24 10` | `LEA EBP,[ESP + 0x10]` |
| `10016d14` | `2b e0` | `SUB ESP,EAX` |
| `10016d16` | `53` | `PUSH EBX` |
| `10016d17` | `56` | `PUSH ESI` |
| `10016d18` | `57` | `PUSH EDI` |
| `10016d19` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10016d1e` | `31 45 fc` | `XOR dword ptr [EBP + -0x4],EAX` |
| `10016d21` | `33 c5` | `XOR EAX,EBP` |
| `10016d23` | `50` | `PUSH EAX` |
| `10016d24` | `89 65 e8` | `MOV dword ptr [EBP + -0x18],ESP` |
| `10016d27` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `10016d2a` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10016d2d` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10016d34` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10016d37` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `10016d3a` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10016d40` | `c3` | `RET` |
