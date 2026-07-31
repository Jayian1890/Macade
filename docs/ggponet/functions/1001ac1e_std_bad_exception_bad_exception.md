# 1001ac1e `std::bad_exception::bad_exception`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ac1e |
| `name` | std::bad_exception::bad_exception |
| `namespace` | std::bad_exception (GhidraClass) |
| `signature` | undefined __thiscall bad_exception(bad_exception * this, char * param_1) |
| `size_bytes` | 30 |
| `stack_frame_size` | 8 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0bad_exception@std@@QAE@PBD@Z, std::bad_exception::bad_exception |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::bad_exception::bad_exception(char const *)
   
   Library: Visual Studio 2008 Release */

bad_exception * __thiscall std::bad_exception::bad_exception(bad_exception *this,char *param_1)

{
  exception::exception((exception *)this,&param_1);
  *(undefined ***)this = vftable;
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ac2a` | `10011130` | `UNCONDITIONAL_CALL` | std::exception::exception | `10011130` |

## Callers

| From | Function |
| --- | --- |
| `1001b5e2` | FindHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001ac2f` | `1002f7d0` | `DATA` | std::bad_exception::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ac1e` | `8b ff` | `MOV EDI,EDI` |
| `1001ac20` | `55` | `PUSH EBP` |
| `1001ac21` | `8b ec` | `MOV EBP,ESP` |
| `1001ac23` | `56` | `PUSH ESI` |
| `1001ac24` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `1001ac27` | `50` | `PUSH EAX` |
| `1001ac28` | `8b f1` | `MOV ESI,ECX` |
| `1001ac2a` | `e8 01 65 ff ff` | `CALL 0x10011130` |
| `1001ac2f` | `c7 06 d0 f7 02 10` | `MOV dword ptr [ESI],0x1002f7d0` |
| `1001ac35` | `8b c6` | `MOV EAX,ESI` |
| `1001ac37` | `5e` | `POP ESI` |
| `1001ac38` | `5d` | `POP EBP` |
| `1001ac39` | `c2 04 00` | `RET 0x4` |
