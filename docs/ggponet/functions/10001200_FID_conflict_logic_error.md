# 10001200 `FID_conflict:~logic_error`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001200 |
| `name` | FID_conflict:~logic_error |
| `namespace` | Global |
| `signature` | undefined FID_conflict:~logic_error(void) |
| `size_bytes` | 39 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??1logic_error@std@@UAE@XZ, ??1runtime_error@std@@UAE@XZ, FID_conflict:~logic_error |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall std::logic_error::~logic_error(void)
    public: virtual __thiscall std::runtime_error::~runtime_error(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

void FID_conflict__logic_error(void)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = std::logic_error::vftable;
  FUN_10001580();
  exception::~exception(in_ECX);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10001216` | `10001580` | `UNCONDITIONAL_CALL` | FUN_10001580 | `10001580` |
| `1000121e` | `100111fd` | `UNCONDITIONAL_CALL` | exception::~exception | `100111fd` |

## Callers

| From | Function |
| --- | --- |
| `1000125a` | FUN_10001250 |
| `100012c3` | FUN_100012b0 |
| `10004993` | FUN_10004980 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1000120a` | `1002ef68` | `DATA` | std::logic_error::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001200` | `55` | `PUSH EBP` |
| `10001201` | `8b ec` | `MOV EBP,ESP` |
| `10001203` | `51` | `PUSH ECX` |
| `10001204` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001207` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000120a` | `c7 00 68 ef 02 10` | `MOV dword ptr [EAX],0x1002ef68` |
| `10001210` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001213` | `83 c1 0c` | `ADD ECX,0xc` |
| `10001216` | `e8 65 03 00 00` | `CALL 0x10001580` |
| `1000121b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000121e` | `e8 da ff 00 00` | `CALL 0x100111fd` |
| `10001223` | `8b e5` | `MOV ESP,EBP` |
| `10001225` | `5d` | `POP EBP` |
| `10001226` | `c3` | `RET` |
