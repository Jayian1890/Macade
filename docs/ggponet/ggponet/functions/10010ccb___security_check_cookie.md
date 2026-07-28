# 10010ccb `__security_check_cookie`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10010ccb |
| `name` | __security_check_cookie |
| `namespace` | Global |
| `signature` | undefined __fastcall __security_check_cookie(void) |
| `size_bytes` | 15 |
| `stack_frame_size` | 4 |
| `calling_convention` | __fastcall |
| `source_type` | ANALYSIS |
| `export_names` | @__security_check_cookie@4, __security_check_cookie |

## Decompiled C

```c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10037490) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10010cd5` | `10014d98` | `UNCONDITIONAL_CALL` | ___report_gsfailure | `10014d98` |

## Callers

| From | Function |
| --- | --- |
| `100116a8` | __invoke_watson |
| `10015f53` | __output_l |
| `1001a30b` | __write_nolock |
| `1001e21e` | __crtCompareStringA_stat |
| `1001e70a` | __putwch_nolock |
| `1001f7fe` | ___ansicp |
| `1001ef10` | __crtGetStringTypeA_stat |
| `1001f9b2` | ___convertcp |
| `1001ed11` | __crtLCMapStringA_stat |
| `1001c09b` | __setmbcp_nolock |
| `1001bd96` | setSBUpLow |
| `10027f53` | FUN_10027b70 |
| `1002248d` | FUN_10022310 |
| `10026748` | FUN_100264e0 |
| `1002843f` | FUN_10028330 |
| `100246d5` | FUN_100245b0 |
| `100245a5` | FUN_10024520 |
| `10023081` | FUN_10022e60 |
| `10022cd5` | FUN_10022c50 |
| `100249fa` | FUN_10024750 |
| `10007973` | FUN_10007830 |
| `10014a1b` | CatchGuardHandler |
| `10014b27` | TranslatorGuardHandler |
| `10016d94` | __except_handler4 |
| `10016da4` | __except_handler4 |
| `10016e17` | __except_handler4 |
| `10016e27` | __except_handler4 |
| `10016eaa` | __except_handler4 |
| `10016eba` | __except_handler4 |
| `1001fe19` | FUN_1001fd20 |
| `10020075` | FUN_1001fef0 |
| `100202d5` | FUN_10020080 |
| `1002185e` | FUN_10021660 |
| `1002088a` | FUN_10020700 |
| `100206f2` | FUN_100206b0 |
| `10020e98` | FUN_10020940 |
| `100221d7` | FUN_10022020 |
| `100222f9` | FUN_100221f0 |
| `10022846` | FUN_100226c0 |
| `100228d8` | FUN_10022860 |
| `10021333` | FUN_10021290 |
| `10021651` | FUN_10021340 |
| `10021b22` | FUN_10021870 |
| `10021285` | FUN_10020eb0 |
| `100226b2` | FUN_100224a0 |
| `10022b5e` | FUN_10022a60 |
| `10022e0d` | FUN_10022d40 |
| `1002391e` | FUN_100233f0 |
| `10023ea4` | FUN_100239f0 |
| `10025082` | FUN_10024da0 |
| `10026051` | FUN_10025e90 |
| `100274a6` | FUN_10027440 |
| `1002756f` | FUN_100274b0 |
| `1002764a` | FUN_10027580 |
| `10027947` | FUN_10027730 |
| `10028704` | FUN_100286c0 |
| `10028c85` | FUN_10028b30 |
| `100295cf` | FUN_10029160 |
| `1002ad6e` | FID_conflict:__atoflt_l |
| `1002ae16` | FID_conflict:__atoflt_l |
| `1002c2e3` | ___strgtold12_l |
| `1002d243` | ___mtold12 |
| `1002a515` | __cftoe_l |
| `1002b022` | __fltout2 |
| `1002cbfb` | $I10_OUTPUT |
| `1002aa5a` | __cftof_l |
| `1002ab54` | __cftog_l |
| `100183b3` |  |
| `1001d9b3` |  |
| `1002d2d4` |  |
| `1002d2ef` |  |
| `1002d30c` |  |
| `1002d32c` |  |
| `1002d34c` |  |
| `1002d36c` |  |
| `1002d38c` |  |
| `1002d3ac` |  |
| `1002d3d4` |  |
| `1002d3fc` |  |
| `1002d41c` |  |
| `1002d43c` |  |
| `1002d45c` |  |
| `1002d484` |  |
| `1002d4ba` |  |
| `1002d4e0` |  |
| `1002d514` |  |
| `1002d569` |  |
| `1002d5a0` |  |
| `1002d5d4` |  |
| `1002d5fa` |  |
| `1002d623` |  |
| `1002d62d` |  |
| `1002d661` |  |
| `1002d695` |  |
| `1002d6d7` |  |
| `1002d727` |  |
| `1002d74a` |  |
| `1002d797` |  |
| `1002d7c4` |  |
| `1002d7ec` |  |
| `1002d814` |  |
| `1002d83c` |  |
| `1002d85c` |  |
| `1002d884` |  |
| `1002d8b4` |  |
| `1002d8e4` |  |
| `1002d914` |  |
| `1002d944` |  |
| `1002d974` |  |
| `1002d99c` |  |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10010ccb` | `10037490` | `READ` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10010ccb` | `3b 0d 90 74 03 10` | `CMP ECX,dword ptr [0x10037490]` |
| `10010cd1` | `75 02` | `JNZ 0x10010cd5` |
| `10010cd3` | `f3 c3` | `RET` |
| `10010cd5` | `e9 be 40 00 00` | `JMP 0x10014d98` |
