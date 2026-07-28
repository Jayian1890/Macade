# 100116af `__invalid_parameter`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100116af |
| `name` | __invalid_parameter |
| `namespace` | Global |
| `signature` | undefined __invalid_parameter(void) |
| `size_bytes` | 38 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __invalid_parameter |

## Decompiled C

```c

/* Library Function - Single Match
    __invalid_parameter
   
   Library: Visual Studio 2008 Release */

void __invalid_parameter(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                        uintptr_t param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)__decode_pointer(DAT_10038a24);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x100116c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  FUN_10017107(2);
                    /* WARNING: Subroutine does not return */
  __invoke_watson(param_1,param_2,param_3,param_4,param_5);
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100116ba` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `100116c9` | `10017107` | `UNCONDITIONAL_CALL` | FUN_10017107 | `10017107` |
| `100116d0` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |

## Callers

| From | Function |
| --- | --- |
| `1001182b` | _memcpy_s |
| `10015fa2` | _strcpy_s |
| `1001ab34` | __calloc_impl |
| `1001c985` | _strcat_s |
| `1001ca0e` | _strncpy_s |
| `1001cac4` | __set_error_mode |
| `100110c2` | _sprintf |
| `10011a9e` | __fsopen |
| `10012d7c` | _getenv |
| `10015460` | __output_l |
| `10017f4a` | __openfile |
| `1001817c` | __openfile |
| `10018c64` | __fileno |
| `10019a68` | __mbsnbicoll_l |
| `10019aa5` | __mbsnbicoll_l |
| `1001a366` | __write |
| `10019c37` | __write_nolock |
| `10019ca2` | __write_nolock |
| `1001ba0f` | __lseeki64 |
| `1001ba50` | __lseeki64 |
| `1001bb4e` | __isatty |
| `1001d4f0` | __sopen_helper |
| `1001ce45` | __tsopen_nolock |
| `100185e3` | __read_nolock |
| `10018695` | __read_nolock |
| `1001d61f` | __mbsnbicmp_l |
| `1001d655` | __mbsnbicmp_l |
| `1001d859` | __mbsnbcmp_l |
| `1001d88c` | __mbsnbcmp_l |
| `1001dc1b` | __get_osfhandle |
| `1001e2ac` | __strnicoll_l |
| `1001e2e9` | __strnicoll_l |
| `1001e432` | ___crtsetenv |
| `1001e8a6` | __recalloc |
| `1001cafe` | __msize |
| `1001f652` | __get_fmode |
| `1001f6a2` | __strnicmp_l |
| `1001f6e1` | __strnicmp_l |
| `1001f783` | __strnicmp |
| `10017b2c` | strtoxl |
| `1001fa3b` | __mbschr_l |
| `10011f1a` | __vsprintf_l |
| `10012086` | _fprintf |
| `10012120` | _fprintf |
| `100121a2` | vfprintf_helper |
| `1001223c` | vfprintf_helper |
| `1001a433` | __commit |
| `10011069` | _memmove_s |
| `100116dc` | FUN_100116d5 |
| `10011d99` | _fread_s |
| `10011b81` | __fread_nolock_s |
| `10011eae` | _fclose |
| `10011e2b` | __fclose_nolock |
| `1001847b` | __filbuf |
| `10018b9c` | __read |
| `10018d67` | __close |
| `10019973` | __vsnprintf_l |
| `100199a2` | __vsnprintf_l |
| `1001c5cb` | __wctomb_s_l |
| `1001c649` | __wctomb_s_l |
| `100197ae` | _raise |
| `100191b1` | __fwrite_nolock |
| `100122dd` | _puts |
| `10011fbc` | _printf |
| `1002b16e` | __controlfp_s |
| `1002bc7e` | ___strgtold12_l |
| `1002a30a` | __cftoe2_l |
| `1002a492` | __cftoe_l |
| `1002ae43` | __fptostr |
| `1002a57f` | __cftoa_l |
| `1002a8e2` | __cftof2_l |
| `1002a9ec` | __cftof_l |
| `1002aaa7` | __cftog_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100116b4` | `10038a24` | `READ` | DAT_10038a24 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100116af` | `8b ff` | `MOV EDI,EDI` |
| `100116b1` | `55` | `PUSH EBP` |
| `100116b2` | `8b ec` | `MOV EBP,ESP` |
| `100116b4` | `ff 35 24 8a 03 10` | `PUSH dword ptr [0x10038a24]` |
| `100116ba` | `e8 cb 5a 00 00` | `CALL 0x1001718a` |
| `100116bf` | `59` | `POP ECX` |
| `100116c0` | `85 c0` | `TEST EAX,EAX` |
| `100116c2` | `74 03` | `JZ 0x100116c7` |
| `100116c4` | `5d` | `POP EBP` |
| `100116c5` | `ff e0` | `JMP EAX` |
| `100116c7` | `6a 02` | `PUSH 0x2` |
| `100116c9` | `e8 39 5a 00 00` | `CALL 0x10017107` |
| `100116ce` | `59` | `POP ECX` |
| `100116cf` | `5d` | `POP EBP` |
| `100116d0` | `e9 b2 fe ff ff` | `JMP 0x10011587` |
