# 100111a0 `std::exception::exception`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100111a0 |
| `name` | std::exception::exception |
| `namespace` | std::exception (GhidraClass) |
| `signature` | undefined __thiscall exception(exception * this, exception * param_1) |
| `size_bytes` | 93 |
| `stack_frame_size` | 8 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0exception@std@@QAE@ABV01@@Z, std::exception::exception |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::exception::exception(class std::exception const &)
   
   Library: Visual Studio 2008 Release */

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  
  *(undefined ***)this = vftable;
  iVar1 = *(int *)(param_1 + 8);
  *(int *)(this + 8) = iVar1;
  pcVar3 = *(char **)(param_1 + 4);
  if (iVar1 == 0) {
    *(char **)(this + 4) = pcVar3;
  }
  else if (pcVar3 == (char *)0x0) {
    *(undefined4 *)(this + 4) = 0;
  }
  else {
    sVar2 = _strlen(pcVar3);
    pcVar3 = _malloc(sVar2 + 1);
    *(char **)(this + 4) = pcVar3;
    if (pcVar3 != (char *)0x0) {
      _strcpy_s(pcVar3,sVar2 + 1,*(char **)(param_1 + 4));
    }
  }
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100111c5` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `100111ce` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `100111e1` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |

## Callers

| From | Function |
| --- | --- |
| `1000277e` | FUN_10002770 |
| `1000132d` | FID_conflict:runtime_error |
| `1001b7df` | FUN_1001b7d4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100111ac` | `1002efb4` | `DATA` | std::exception::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100111a0` | `8b ff` | `MOV EDI,EDI` |
| `100111a2` | `55` | `PUSH EBP` |
| `100111a3` | `8b ec` | `MOV EBP,ESP` |
| `100111a5` | `53` | `PUSH EBX` |
| `100111a6` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `100111a9` | `56` | `PUSH ESI` |
| `100111aa` | `8b f1` | `MOV ESI,ECX` |
| `100111ac` | `c7 06 b4 ef 02 10` | `MOV dword ptr [ESI],0x1002efb4` |
| `100111b2` | `8b 43 08` | `MOV EAX,dword ptr [EBX + 0x8]` |
| `100111b5` | `89 46 08` | `MOV dword ptr [ESI + 0x8],EAX` |
| `100111b8` | `85 c0` | `TEST EAX,EAX` |
| `100111ba` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `100111bd` | `57` | `PUSH EDI` |
| `100111be` | `74 31` | `JZ 0x100111f1` |
| `100111c0` | `85 c0` | `TEST EAX,EAX` |
| `100111c2` | `74 27` | `JZ 0x100111eb` |
| `100111c4` | `50` | `PUSH EAX` |
| `100111c5` | `e8 26 02 00 00` | `CALL 0x100113f0` |
| `100111ca` | `8b f8` | `MOV EDI,EAX` |
| `100111cc` | `47` | `INC EDI` |
| `100111cd` | `57` | `PUSH EDI` |
| `100111ce` | `e8 4b 01 00 00` | `CALL 0x1001131e` |
| `100111d3` | `59` | `POP ECX` |
| `100111d4` | `59` | `POP ECX` |
| `100111d5` | `89 46 04` | `MOV dword ptr [ESI + 0x4],EAX` |
| `100111d8` | `85 c0` | `TEST EAX,EAX` |
| `100111da` | `74 18` | `JZ 0x100111f4` |
| `100111dc` | `ff 73 04` | `PUSH dword ptr [EBX + 0x4]` |
| `100111df` | `57` | `PUSH EDI` |
| `100111e0` | `50` | `PUSH EAX` |
| `100111e1` | `e8 95 4d 00 00` | `CALL 0x10015f7b` |
| `100111e6` | `83 c4 0c` | `ADD ESP,0xc` |
| `100111e9` | `eb 09` | `JMP 0x100111f4` |
| `100111eb` | `83 66 04 00` | `AND dword ptr [ESI + 0x4],0x0` |
| `100111ef` | `eb 03` | `JMP 0x100111f4` |
| `100111f1` | `89 46 04` | `MOV dword ptr [ESI + 0x4],EAX` |
| `100111f4` | `5f` | `POP EDI` |
| `100111f5` | `8b c6` | `MOV EAX,ESI` |
| `100111f7` | `5e` | `POP ESI` |
| `100111f8` | `5b` | `POP EBX` |
| `100111f9` | `5d` | `POP EBP` |
| `100111fa` | `c2 04 00` | `RET 0x4` |
