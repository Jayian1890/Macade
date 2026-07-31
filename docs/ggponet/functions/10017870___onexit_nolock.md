# 10017870 `__onexit_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017870 |
| `name` | __onexit_nolock |
| `namespace` | Global |
| `signature` | undefined __onexit_nolock(void) |
| `size_bytes` | 186 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __onexit_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __onexit_nolock
   
   Library: Visual Studio 2008 Release */

undefined4 __onexit_nolock(undefined4 param_1)

{
  undefined4 *_Memory;
  undefined4 *puVar1;
  size_t sVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  
  _Memory = (undefined4 *)__decode_pointer(DAT_1343a694);
  puVar1 = (undefined4 *)__decode_pointer(DAT_1343a690);
  if ((puVar1 < _Memory) || (iVar6 = (int)puVar1 - (int)_Memory, iVar6 + 4U < 4)) {
    return 0;
  }
  sVar2 = __msize(_Memory);
  if (sVar2 < iVar6 + 4U) {
    sVar3 = 0x800;
    if (sVar2 < 0x800) {
      sVar3 = sVar2;
    }
    if ((sVar3 + sVar2 < sVar2) ||
       (pvVar4 = __realloc_crt(_Memory,sVar3 + sVar2), pvVar4 == (void *)0x0)) {
      if (sVar2 + 0x10 < sVar2) {
        return 0;
      }
      pvVar4 = __realloc_crt(_Memory,sVar2 + 0x10);
      if (pvVar4 == (void *)0x0) {
        return 0;
      }
    }
    puVar1 = (undefined4 *)((int)pvVar4 + (iVar6 >> 2) * 4);
    DAT_1343a694 = __encode_pointer(pvVar4);
  }
  uVar5 = __encode_pointer(param_1);
  *puVar1 = uVar5;
  DAT_1343a690 = __encode_pointer(puVar1 + 1);
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001787f` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001788f` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `100178ad` | `1001cad2` | `UNCONDITIONAL_CALL` | __msize | `1001cad2` |
| `100178d1` | `1001a560` | `UNCONDITIONAL_CALL` | __realloc_crt | `1001a560` |
| `100178e7` | `1001a560` | `UNCONDITIONAL_CALL` | __realloc_crt | `1001a560` |
| `100178f9` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `10017907` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `10017912` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |

## Callers

| From | Function |
| --- | --- |
| `10017973` | __onexit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017879` | `1343a694` | `READ` | DAT_1343a694 |
| `10017884` | `1343a690` | `READ` | DAT_1343a690 |
| `100178ff` | `1343a694` | `WRITE` | DAT_1343a694 |
| `10017918` | `1343a690` | `WRITE` | DAT_1343a690 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017870` | `8b ff` | `MOV EDI,EDI` |
| `10017872` | `55` | `PUSH EBP` |
| `10017873` | `8b ec` | `MOV EBP,ESP` |
| `10017875` | `51` | `PUSH ECX` |
| `10017876` | `53` | `PUSH EBX` |
| `10017877` | `56` | `PUSH ESI` |
| `10017878` | `57` | `PUSH EDI` |
| `10017879` | `ff 35 94 a6 43 13` | `PUSH dword ptr [0x1343a694]` |
| `1001787f` | `e8 06 f9 ff ff` | `CALL 0x1001718a` |
| `10017884` | `ff 35 90 a6 43 13` | `PUSH dword ptr [0x1343a690]` |
| `1001788a` | `8b f8` | `MOV EDI,EAX` |
| `1001788c` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `1001788f` | `e8 f6 f8 ff ff` | `CALL 0x1001718a` |
| `10017894` | `8b f0` | `MOV ESI,EAX` |
| `10017896` | `59` | `POP ECX` |
| `10017897` | `59` | `POP ECX` |
| `10017898` | `3b f7` | `CMP ESI,EDI` |
| `1001789a` | `0f 82 83 00 00 00` | `JC 0x10017923` |
| `100178a0` | `8b de` | `MOV EBX,ESI` |
| `100178a2` | `2b df` | `SUB EBX,EDI` |
| `100178a4` | `8d 43 04` | `LEA EAX,[EBX + 0x4]` |
| `100178a7` | `83 f8 04` | `CMP EAX,0x4` |
| `100178aa` | `72 77` | `JC 0x10017923` |
| `100178ac` | `57` | `PUSH EDI` |
| `100178ad` | `e8 20 52 00 00` | `CALL 0x1001cad2` |
| `100178b2` | `8b f8` | `MOV EDI,EAX` |
| `100178b4` | `8d 43 04` | `LEA EAX,[EBX + 0x4]` |
| `100178b7` | `59` | `POP ECX` |
| `100178b8` | `3b f8` | `CMP EDI,EAX` |
| `100178ba` | `73 48` | `JNC 0x10017904` |
| `100178bc` | `b8 00 08 00 00` | `MOV EAX,0x800` |
| `100178c1` | `3b f8` | `CMP EDI,EAX` |
| `100178c3` | `73 02` | `JNC 0x100178c7` |
| `100178c5` | `8b c7` | `MOV EAX,EDI` |
| `100178c7` | `03 c7` | `ADD EAX,EDI` |
| `100178c9` | `3b c7` | `CMP EAX,EDI` |
| `100178cb` | `72 0f` | `JC 0x100178dc` |
| `100178cd` | `50` | `PUSH EAX` |
| `100178ce` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `100178d1` | `e8 8a 2c 00 00` | `CALL 0x1001a560` |
| `100178d6` | `59` | `POP ECX` |
| `100178d7` | `59` | `POP ECX` |
| `100178d8` | `85 c0` | `TEST EAX,EAX` |
| `100178da` | `75 16` | `JNZ 0x100178f2` |
| `100178dc` | `8d 47 10` | `LEA EAX,[EDI + 0x10]` |
| `100178df` | `3b c7` | `CMP EAX,EDI` |
| `100178e1` | `72 40` | `JC 0x10017923` |
| `100178e3` | `50` | `PUSH EAX` |
| `100178e4` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `100178e7` | `e8 74 2c 00 00` | `CALL 0x1001a560` |
| `100178ec` | `59` | `POP ECX` |
| `100178ed` | `59` | `POP ECX` |
| `100178ee` | `85 c0` | `TEST EAX,EAX` |
| `100178f0` | `74 31` | `JZ 0x10017923` |
| `100178f2` | `c1 fb 02` | `SAR EBX,0x2` |
| `100178f5` | `50` | `PUSH EAX` |
| `100178f6` | `8d 34 98` | `LEA ESI,[EAX + EBX*0x4]` |
| `100178f9` | `e8 11 f8 ff ff` | `CALL 0x1001710f` |
| `100178fe` | `59` | `POP ECX` |
| `100178ff` | `a3 94 a6 43 13` | `MOV [0x1343a694],EAX` |
| `10017904` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10017907` | `e8 03 f8 ff ff` | `CALL 0x1001710f` |
| `1001790c` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001790e` | `83 c6 04` | `ADD ESI,0x4` |
| `10017911` | `56` | `PUSH ESI` |
| `10017912` | `e8 f8 f7 ff ff` | `CALL 0x1001710f` |
| `10017917` | `59` | `POP ECX` |
| `10017918` | `a3 90 a6 43 13` | `MOV [0x1343a690],EAX` |
| `1001791d` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10017920` | `59` | `POP ECX` |
| `10017921` | `eb 02` | `JMP 0x10017925` |
| `10017923` | `33 c0` | `XOR EAX,EAX` |
| `10017925` | `5f` | `POP EDI` |
| `10017926` | `5e` | `POP ESI` |
| `10017927` | `5b` | `POP EBX` |
| `10017928` | `c9` | `LEAVE` |
| `10017929` | `c3` | `RET` |
