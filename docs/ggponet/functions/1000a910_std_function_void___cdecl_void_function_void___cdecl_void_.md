# 1000a910 `std::function<void___cdecl(void)>::~function<void___cdecl(void)>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1000a910 |
| `name` | std::function<void___cdecl(void)>::~function<void___cdecl(void)> |
| `namespace` | std::function<void___cdecl(void)> (GhidraClass) |
| `signature` | void __thiscall ~function<void___cdecl(void)>(function<void___cdecl(void)> * this) |
| `size_bytes` | 27 |
| `stack_frame_size` | 12 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??1?$function@$$A6AXXZ@std@@QAE@XZ, std::function<void___cdecl(void)>::~function<void___cdecl(void)> |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::function<void __cdecl(void)>::~function<void __cdecl(void)>(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __thiscall
std::function<void___cdecl(void)>::~function<void___cdecl(void)>(function<void___cdecl(void)> *this)

{
  FUN_1000ab30(this);
  FUN_10007c40();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000a91a` | `1000ab30` | `UNCONDITIONAL_CALL` | FUN_1000ab30 | `1000ab30` |
| `1000a922` | `10007c40` | `UNCONDITIONAL_CALL` | FUN_10007c40 | `10007c40` |

## Callers

| From | Function |
| --- | --- |
| `1000a82a` | FUN_1000a820 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1000a910` | `55` | `PUSH EBP` |
| `1000a911` | `8b ec` | `MOV EBP,ESP` |
| `1000a913` | `51` | `PUSH ECX` |
| `1000a914` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `1000a917` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000a91a` | `e8 11 02 00 00` | `CALL 0x1000ab30` |
| `1000a91f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000a922` | `e8 19 d3 ff ff` | `CALL 0x10007c40` |
| `1000a927` | `8b e5` | `MOV ESP,EBP` |
| `1000a929` | `5d` | `POP EBP` |
| `1000a92a` | `c3` | `RET` |
