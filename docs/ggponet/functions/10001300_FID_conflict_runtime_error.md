# 10001300 `FID_conflict:runtime_error`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001300 |
| `name` | FID_conflict:runtime_error |
| `namespace` | Global |
| `signature` | undefined FID_conflict:runtime_error(void) |
| `size_bytes` | 111 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??0logic_error@std@@QAE@ABV01@@Z, ??0runtime_error@std@@QAE@ABV01@@Z, FID_conflict:runtime_error |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::logic_error::logic_error(class std::logic_error const &)
    public: __thiscall std::runtime_error::runtime_error(class std::runtime_error const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

exception * FID_conflict_runtime_error(exception *param_1)

{
  exception *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception(in_ECX,param_1);
  local_8 = 0;
  *(undefined ***)in_ECX = std::logic_error::vftable;
  FUN_10001540(param_1 + 0xc);
  ExceptionList = local_10;
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000132d` | `100111a0` | `UNCONDITIONAL_CALL` | std::exception::exception | `100111a0` |
| `1000134f` | `10001540` | `UNCONDITIONAL_CALL` | FUN_10001540 | `10001540` |

## Callers

| From | Function |
| --- | --- |
| `1000223e` | FID_conflict:invalid_argument |
| `100049de` | FID_conflict:invalid_argument |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10001305` | `1002d808` | `DATA` | LAB_1002d808 |
| `1000130a` | `ffdff000` | `READ` | ExceptionList |
| `10001312` | `10037490` | `READ` | DAT_10037490 |
| `1000131d` | `ffdff000` | `WRITE` | ExceptionList |
| `1000133c` | `1002ef68` | `DATA` | std::logic_error::vftable |
| `10001361` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001300` | `55` | `PUSH EBP` |
| `10001301` | `8b ec` | `MOV EBP,ESP` |
| `10001303` | `6a ff` | `PUSH -0x1` |
| `10001305` | `68 08 d8 02 10` | `PUSH 0x1002d808` |
| `1000130a` | `64 a1 00 00 00 00` | `MOV EAX,FS:[0x0]` |
| `10001310` | `50` | `PUSH EAX` |
| `10001311` | `51` | `PUSH ECX` |
| `10001312` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10001317` | `33 c5` | `XOR EAX,EBP` |
| `10001319` | `50` | `PUSH EAX` |
| `1000131a` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `1000131d` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10001323` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `10001326` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10001329` | `50` | `PUSH EAX` |
| `1000132a` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1000132d` | `e8 6e fe 00 00` | `CALL 0x100111a0` |
| `10001332` | `c7 45 fc 00 00 00 00` | `MOV dword ptr [EBP + -0x4],0x0` |
| `10001339` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1000133c` | `c7 01 68 ef 02 10` | `MOV dword ptr [ECX],0x1002ef68` |
| `10001342` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10001345` | `83 c2 0c` | `ADD EDX,0xc` |
| `10001348` | `52` | `PUSH EDX` |
| `10001349` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1000134c` | `83 c1 0c` | `ADD ECX,0xc` |
| `1000134f` | `e8 ec 01 00 00` | `CALL 0x10001540` |
| `10001354` | `c7 45 fc ff ff ff ff` | `MOV dword ptr [EBP + -0x4],0xffffffff` |
| `1000135b` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1000135e` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10001361` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `10001368` | `59` | `POP ECX` |
| `10001369` | `8b e5` | `MOV ESP,EBP` |
| `1000136b` | `5d` | `POP EBP` |
| `1000136c` | `c2 04 00` | `RET 0x4` |
