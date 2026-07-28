# 10005830 `kailleraInit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005830 |
| `name` | kailleraInit |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraInit(void) |
| `size_bytes` | 239 |
| `stack_frame_size` | 4 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_4, _kailleraInit@0, kailleraInit |

## Decompiled C

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall kailleraInit,0 */

void kailleraInit(void)

{
  char cVar1;
  void *this;
  char *pcVar2;
  HMODULE hModule;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
                    /* 0x5830  4  _kailleraInit@0 */
  DAT_1000ef88 = 0;
  this = operator_new(0x13c);
  if (this == (void *)0x0) {
    DAT_1000ef90 = (undefined4 *)0x0;
  }
  else {
    DAT_1000ef90 = FUN_100017a0(this,s_kaillera_ini_1000e49c,s_KailleraClient_1000e4ac);
  }
  DAT_1000ef98 = 0;
  pcVar2 = (char *)FUN_10001ba0(DAT_1000ef90,s_username_1000e490,&DAT_1000ec9c);
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = &DAT_1000edc8;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  DAT_1000edc0 = 0;
  _DAT_1000edbc = 0x6cee;
  DAT_1000eefc = FUN_100019d0(DAT_1000ef90,s_conntype_1000e484,3);
  FUN_10004140();
  Ordinal_17();
  hModule = LoadLibraryA(s_USER32_DLL_1000e478);
  DAT_1000eef0 = GetProcAddress(hModule,s_FlashWindowEx_1000e468);
  FreeLibrary(hModule);
  DAT_1000ef94 = LoadLibraryA(s_RICHED32_DLL_1000e458);
  FUN_10005920();
  FUN_10005a60();
  FUN_10005690();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000583f` | `1000c7ce` | `UNCONDITIONAL_CALL` | MSVCRT.DLL::operator_new | `1000c7ce` |
| `10005857` | `100017a0` | `UNCONDITIONAL_CALL` | FUN_100017a0 | `100017a0` |
| `1000587d` | `10001ba0` | `UNCONDITIONAL_CALL` | FUN_10001ba0 | `10001ba0` |
| `100058c5` | `100019d0` | `UNCONDITIONAL_CALL` | FUN_100019d0 | `100019d0` |
| `100058cf` | `10004140` | `UNCONDITIONAL_CALL` | FUN_10004140 | `10004140` |
| `100058d4` | `EXTERNAL:0000000e` | `COMPUTED_CALL` | COMCTL32.DLL::Ordinal_17 | `` |
| `100058e5` | `EXTERNAL:00000005` | `COMPUTED_CALL` | KERNEL32.DLL::LoadLibraryA | `` |
| `100058ef` | `EXTERNAL:0000000d` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `100058fb` | `EXTERNAL:0000000b` | `COMPUTED_CALL` | KERNEL32.DLL::FreeLibrary | `` |
| `10005906` | `EXTERNAL:00000005` | `COMPUTED_CALL` | KERNEL32.DLL::LoadLibraryA | `` |
| `1000590d` | `10005920` | `UNCONDITIONAL_CALL` | FUN_10005920 | `10005920` |
| `10005912` | `10005a60` | `UNCONDITIONAL_CALL` | FUN_10005a60 | `10005a60` |
| `10005917` | `10005690` | `UNCONDITIONAL_CALL` | FUN_10005690 | `10005690` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1000584b` | `1000e4ac` | `KailleraClient` |
| `10005850` | `1000e49c` | `kaillera.ini` |
| `10005867` | `1000e490` | `username` |
| `10005891` | `1000e484` | `conntype` |
| `100058e0` | `1000e478` | `USER32.DLL` |
| `100058e9` | `1000e468` | `FlashWindowEx` |
| `10005901` | `1000e458` | `RICHED32.DLL` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10005835` | `1000ef88` | `WRITE` | DAT_1000ef88 |
| `10005862` | `1000ec9c` | `DATA` | DAT_1000ec9c |
| `1000586e` | `1000ef90` | `WRITE` | DAT_1000ef90 |
| `10005873` | `1000ef98` | `WRITE` | DAT_1000ef98 |
| `1000589a` | `1000edc8` | `DATA` | DAT_1000edc8 |
| `100058a2` | `1000edc8` | `WRITE` | DAT_1000edc8 |
| `100058a2` | `1000edcc` | `WRITE` | DAT_1000edcc |
| `100058a9` | `1000edcc` | `WRITE` | DAT_1000edcc |
| `100058a9` | `1000edcd` | `WRITE` | DAT_1000edcd |
| `100058ab` | `1000ef90` | `READ` | DAT_1000ef90 |
| `100058b1` | `1000edc0` | `WRITE` | DAT_1000edc0 |
| `100058bb` | `1000edbc` | `WRITE` | DAT_1000edbc |
| `100058ca` | `1000eefc` | `WRITE` | DAT_1000eefc |
| `100058d4` | `1000d000` | `READ` | PTR_Ordinal_17_1000d000 |
| `100058da` | `1000d02c` | `READ` | PTR_LoadLibraryA_1000d02c |
| `100058ef` | `1000d04c` | `READ` | PTR_GetProcAddress_1000d04c |
| `100058f6` | `1000eef0` | `WRITE` | DAT_1000eef0 |
| `100058fb` | `1000d044` | `READ` | PTR_FreeLibrary_1000d044 |
| `10005908` | `1000ef94` | `WRITE` | DAT_1000ef94 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005830` | `68 3c 01 00 00` | `PUSH 0x13c` |
| `10005835` | `c7 05 88 ef 00 10 00 00 00 00` | `MOV dword ptr [0x1000ef88],0x0` |
| `1000583f` | `e8 8a 6f 00 00` | `CALL 0x1000c7ce` |
| `10005844` | `83 c4 04` | `ADD ESP,0x4` |
| `10005847` | `85 c0` | `TEST EAX,EAX` |
| `10005849` | `74 13` | `JZ 0x1000585e` |
| `1000584b` | `68 ac e4 00 10` | `PUSH 0x1000e4ac` |
| `10005850` | `68 9c e4 00 10` | `PUSH 0x1000e49c` |
| `10005855` | `8b c8` | `MOV ECX,EAX` |
| `10005857` | `e8 44 bf ff ff` | `CALL 0x100017a0` |
| `1000585c` | `eb 02` | `JMP 0x10005860` |
| `1000585e` | `33 c0` | `XOR EAX,EAX` |
| `10005860` | `56` | `PUSH ESI` |
| `10005861` | `57` | `PUSH EDI` |
| `10005862` | `68 9c ec 00 10` | `PUSH 0x1000ec9c` |
| `10005867` | `68 90 e4 00 10` | `PUSH 0x1000e490` |
| `1000586c` | `8b c8` | `MOV ECX,EAX` |
| `1000586e` | `a3 90 ef 00 10` | `MOV [0x1000ef90],EAX` |
| `10005873` | `c7 05 98 ef 00 10 00 00 00 00` | `MOV dword ptr [0x1000ef98],0x0` |
| `1000587d` | `e8 1e c3 ff ff` | `CALL 0x10001ba0` |
| `10005882` | `8b f8` | `MOV EDI,EAX` |
| `10005884` | `83 c9 ff` | `OR ECX,0xffffffff` |
| `10005887` | `33 c0` | `XOR EAX,EAX` |
| `10005889` | `6a 03` | `PUSH 0x3` |
| `1000588b` | `f2 ae` | `SCASB.REPNE ES:EDI` |
| `1000588d` | `f7 d1` | `NOT ECX` |
| `1000588f` | `2b f9` | `SUB EDI,ECX` |
| `10005891` | `68 84 e4 00 10` | `PUSH 0x1000e484` |
| `10005896` | `8b c1` | `MOV EAX,ECX` |
| `10005898` | `8b f7` | `MOV ESI,EDI` |
| `1000589a` | `bf c8 ed 00 10` | `MOV EDI,0x1000edc8` |
| `1000589f` | `c1 e9 02` | `SHR ECX,0x2` |
| `100058a2` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `100058a4` | `8b c8` | `MOV ECX,EAX` |
| `100058a6` | `83 e1 03` | `AND ECX,0x3` |
| `100058a9` | `f3 a4` | `MOVSB.REP ES:EDI,ESI` |
| `100058ab` | `8b 0d 90 ef 00 10` | `MOV ECX,dword ptr [0x1000ef90]` |
| `100058b1` | `c7 05 c0 ed 00 10 00 00 00 00` | `MOV dword ptr [0x1000edc0],0x0` |
| `100058bb` | `c7 05 bc ed 00 10 ee 6c 00 00` | `MOV dword ptr [0x1000edbc],0x6cee` |
| `100058c5` | `e8 06 c1 ff ff` | `CALL 0x100019d0` |
| `100058ca` | `a3 fc ee 00 10` | `MOV [0x1000eefc],EAX` |
| `100058cf` | `e8 6c e8 ff ff` | `CALL 0x10004140` |
| `100058d4` | `ff 15 00 d0 00 10` | `CALL dword ptr [0x1000d000]` |
| `100058da` | `8b 3d 2c d0 00 10` | `MOV EDI,dword ptr [0x1000d02c]` |
| `100058e0` | `68 78 e4 00 10` | `PUSH 0x1000e478` |
| `100058e5` | `ff d7` | `CALL EDI` |
| `100058e7` | `8b f0` | `MOV ESI,EAX` |
| `100058e9` | `68 68 e4 00 10` | `PUSH 0x1000e468` |
| `100058ee` | `56` | `PUSH ESI` |
| `100058ef` | `ff 15 4c d0 00 10` | `CALL dword ptr [0x1000d04c]` |
| `100058f5` | `56` | `PUSH ESI` |
| `100058f6` | `a3 f0 ee 00 10` | `MOV [0x1000eef0],EAX` |
| `100058fb` | `ff 15 44 d0 00 10` | `CALL dword ptr [0x1000d044]` |
| `10005901` | `68 58 e4 00 10` | `PUSH 0x1000e458` |
| `10005906` | `ff d7` | `CALL EDI` |
| `10005908` | `a3 94 ef 00 10` | `MOV [0x1000ef94],EAX` |
| `1000590d` | `e8 0e 00 00 00` | `CALL 0x10005920` |
| `10005912` | `e8 49 01 00 00` | `CALL 0x10005a60` |
| `10005917` | `e8 74 fd ff ff` | `CALL 0x10005690` |
| `1000591c` | `5f` | `POP EDI` |
| `1000591d` | `5e` | `POP ESI` |
| `1000591e` | `c3` | `RET` |
