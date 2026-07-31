# 100110a2 `_sprintf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100110a2 |
| `name` | _sprintf |
| `namespace` | Global |
| `signature` | int __cdecl _sprintf(char * _Dest, char * _Format, ...) |
| `size_bytes` | 125 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _sprintf |

## Decompiled C

```c

/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 2008 Release */

int __cdecl _sprintf(char *_Dest,char *_Format,...)

{
  int *piVar1;
  int iVar2;
  FILE local_24;
  
  if ((_Format == (char *)0x0) || (_Dest == (char *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    local_24._base = _Dest;
    local_24._ptr = _Dest;
    local_24._cnt = 0x7fffffff;
    local_24._flag = 0x42;
    iVar2 = __output_l(&local_24,_Format,(_locale_t)0x0,&stack0x0000000c);
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100110b2` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100110c2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `100110f7` | `100153e3` | `UNCONDITIONAL_CALL` | __output_l | `100153e3` |
| `10011112` | `10015152` | `UNCONDITIONAL_CALL` | __flsbuf | `10015152` |

## Callers

| From | Function |
| --- | --- |
| `10021fb1` | FUN_10021f70 |
| `10022347` | FUN_10022310 |
| `100223d0` | FUN_10022310 |
| `10026564` | FUN_100264e0 |
| `100266d8` | FUN_100264e0 |
| `1002836e` | FUN_10028330 |
| `10022ff5` | FUN_10022e60 |
| `10024808` | FUN_10024750 |
| `10024905` | FUN_10024750 |
| `10007901` | FUN_10007830 |
| `1001fda6` | FUN_1001fd20 |
| `1001ffb1` | FUN_1001fef0 |
| `100200d9` | FUN_10020080 |
| `1002018c` | FUN_10020080 |
| `10020258` | FUN_10020080 |
| `100216ad` | FUN_10021660 |
| `100217eb` | FUN_10021660 |
| `100209aa` | FUN_10020940 |
| `10020a48` | FUN_10020940 |
| `10020c11` | FUN_10020940 |
| `100220fc` | FUN_10022020 |
| `1002222d` | FUN_100221f0 |
| `100226fd` | FUN_100226c0 |
| `10022793` | FUN_100226c0 |
| `100227b0` | FUN_100226c0 |
| `10022813` | FUN_100226c0 |
| `10021385` | FUN_10021340 |
| `10021420` | FUN_10021340 |
| `100215a9` | FUN_10021340 |
| `10021928` | FUN_10021870 |
| `100219cc` | FUN_10021870 |
| `10021a84` | FUN_10021870 |
| `10020fe1` | FUN_10020eb0 |
| `10021078` | FUN_10020eb0 |
| `10021123` | FUN_10020eb0 |
| `100224d7` | FUN_100224a0 |
| `10022560` | FUN_100224a0 |
| `100225e9` | FUN_100224a0 |
| `10022a94` | FUN_10022a60 |
| `10022d81` | FUN_10022d40 |
| `100234e2` | FUN_100233f0 |
| `10023632` | FUN_100233f0 |
| `100236f8` | FUN_100233f0 |
| `10023b3a` | FUN_100239f0 |
| `10023c3d` | FUN_100239f0 |
| `10023d0a` | FUN_100239f0 |
| `10024f5e` | FUN_10024da0 |
| `10025955` | FUN_100258f0 |
| `100274e4` | FUN_100274b0 |
| `1002752a` | FUN_100274b0 |
| `1002761d` | FUN_10027580 |
| `100292e8` | FUN_10029160 |
| `10029306` | FUN_10029160 |
| `10029330` | FUN_10029160 |
| `1002936c` | FUN_10029160 |
| `100293a8` | FUN_10029160 |
| `10029422` | FUN_10029160 |
| `1002945e` | FUN_10029160 |
| `1002948e` | FUN_10029160 |
| `100294b9` | FUN_10029160 |
| `100294db` | FUN_10029160 |
| `100294fd` | FUN_10029160 |
| `10029528` | FUN_10029160 |
| `1002954a` | FUN_10029160 |
| `1002956c` | FUN_10029160 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100110a2` | `8b ff` | `MOV EDI,EDI` |
| `100110a4` | `55` | `PUSH EBP` |
| `100110a5` | `8b ec` | `MOV EBP,ESP` |
| `100110a7` | `83 ec 20` | `SUB ESP,0x20` |
| `100110aa` | `53` | `PUSH EBX` |
| `100110ab` | `33 db` | `XOR EBX,EBX` |
| `100110ad` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `100110b0` | `75 1d` | `JNZ 0x100110cf` |
| `100110b2` | `e8 52 40 00 00` | `CALL 0x10015109` |
| `100110b7` | `53` | `PUSH EBX` |
| `100110b8` | `53` | `PUSH EBX` |
| `100110b9` | `53` | `PUSH EBX` |
| `100110ba` | `53` | `PUSH EBX` |
| `100110bb` | `53` | `PUSH EBX` |
| `100110bc` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `100110c2` | `e8 e8 05 00 00` | `CALL 0x100116af` |
| `100110c7` | `83 c4 14` | `ADD ESP,0x14` |
| `100110ca` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100110cd` | `eb 4d` | `JMP 0x1001111c` |
| `100110cf` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100110d2` | `3b c3` | `CMP EAX,EBX` |
| `100110d4` | `74 dc` | `JZ 0x100110b2` |
| `100110d6` | `56` | `PUSH ESI` |
| `100110d7` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `100110da` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `100110dd` | `8d 45 10` | `LEA EAX,[EBP + 0x10]` |
| `100110e0` | `50` | `PUSH EAX` |
| `100110e1` | `53` | `PUSH EBX` |
| `100110e2` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `100110e5` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `100110e8` | `50` | `PUSH EAX` |
| `100110e9` | `c7 45 e4 ff ff ff 7f` | `MOV dword ptr [EBP + -0x1c],0x7fffffff` |
| `100110f0` | `c7 45 ec 42 00 00 00` | `MOV dword ptr [EBP + -0x14],0x42` |
| `100110f7` | `e8 e7 42 00 00` | `CALL 0x100153e3` |
| `100110fc` | `83 c4 10` | `ADD ESP,0x10` |
| `100110ff` | `ff 4d e4` | `DEC dword ptr [EBP + -0x1c]` |
| `10011102` | `8b f0` | `MOV ESI,EAX` |
| `10011104` | `78 07` | `JS 0x1001110d` |
| `10011106` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `10011109` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1001110b` | `eb 0c` | `JMP 0x10011119` |
| `1001110d` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `10011110` | `50` | `PUSH EAX` |
| `10011111` | `53` | `PUSH EBX` |
| `10011112` | `e8 3b 40 00 00` | `CALL 0x10015152` |
| `10011117` | `59` | `POP ECX` |
| `10011118` | `59` | `POP ECX` |
| `10011119` | `8b c6` | `MOV EAX,ESI` |
| `1001111b` | `5e` | `POP ESI` |
| `1001111c` | `5b` | `POP EBX` |
| `1001111d` | `c9` | `LEAVE` |
| `1001111e` | `c3` | `RET` |
