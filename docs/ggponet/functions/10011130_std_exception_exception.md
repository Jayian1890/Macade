# 10011130 `std::exception::exception`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011130 |
| `name` | std::exception::exception |
| `namespace` | std::exception (GhidraClass) |
| `signature` | undefined __thiscall exception(exception * this, char * * param_1) |
| `size_bytes` | 83 |
| `stack_frame_size` | 8 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0exception@std@@QAE@ABQBD@Z, std::exception::exception |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::exception::exception(char const * const &)
   
   Library: Visual Studio 2008 Release */

exception * __thiscall std::exception::exception(exception *this,char **param_1)

{
  size_t sVar1;
  char *_Dst;
  
  *(undefined ***)this = vftable;
  if (*param_1 == (char *)0x0) {
    *(undefined4 *)(this + 4) = 0;
  }
  else {
    sVar1 = _strlen(*param_1);
    _Dst = _malloc(sVar1 + 1);
    *(char **)(this + 4) = _Dst;
    if (_Dst != (char *)0x0) {
      _strcpy_s(_Dst,sVar1 + 1,*param_1);
    }
  }
  *(undefined4 *)(this + 8) = 1;
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001114a` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `10011153` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `10011165` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |

## Callers

| From | Function |
| --- | --- |
| `1000100e` | std::bad_alloc::bad_alloc |
| `1001ac2a` | std::bad_exception::bad_exception |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001113d` | `1002efb4` | `DATA` | std::exception::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011130` | `8b ff` | `MOV EDI,EDI` |
| `10011132` | `55` | `PUSH EBP` |
| `10011133` | `8b ec` | `MOV EBP,ESP` |
| `10011135` | `53` | `PUSH EBX` |
| `10011136` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10011139` | `56` | `PUSH ESI` |
| `1001113a` | `57` | `PUSH EDI` |
| `1001113b` | `8b f9` | `MOV EDI,ECX` |
| `1001113d` | `c7 07 b4 ef 02 10` | `MOV dword ptr [EDI],0x1002efb4` |
| `10011143` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `10011145` | `85 c0` | `TEST EAX,EAX` |
| `10011147` | `74 26` | `JZ 0x1001116f` |
| `10011149` | `50` | `PUSH EAX` |
| `1001114a` | `e8 a1 02 00 00` | `CALL 0x100113f0` |
| `1001114f` | `8b f0` | `MOV ESI,EAX` |
| `10011151` | `46` | `INC ESI` |
| `10011152` | `56` | `PUSH ESI` |
| `10011153` | `e8 c6 01 00 00` | `CALL 0x1001131e` |
| `10011158` | `59` | `POP ECX` |
| `10011159` | `59` | `POP ECX` |
| `1001115a` | `89 47 04` | `MOV dword ptr [EDI + 0x4],EAX` |
| `1001115d` | `85 c0` | `TEST EAX,EAX` |
| `1001115f` | `74 12` | `JZ 0x10011173` |
| `10011161` | `ff 33` | `PUSH dword ptr [EBX]` |
| `10011163` | `56` | `PUSH ESI` |
| `10011164` | `50` | `PUSH EAX` |
| `10011165` | `e8 11 4e 00 00` | `CALL 0x10015f7b` |
| `1001116a` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001116d` | `eb 04` | `JMP 0x10011173` |
| `1001116f` | `83 67 04 00` | `AND dword ptr [EDI + 0x4],0x0` |
| `10011173` | `c7 47 08 01 00 00 00` | `MOV dword ptr [EDI + 0x8],0x1` |
| `1001117a` | `8b c7` | `MOV EAX,EDI` |
| `1001117c` | `5f` | `POP EDI` |
| `1001117d` | `5e` | `POP ESI` |
| `1001117e` | `5b` | `POP EBX` |
| `1001117f` | `5d` | `POP EBP` |
| `10011180` | `c2 04 00` | `RET 0x4` |
