# 10007be0 `std::function<void___cdecl(void)>::~function<void___cdecl(void)>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10007be0 |
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
  FUN_10007fc0(this);
  FUN_10007c40();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10007bea` | `10007fc0` | `UNCONDITIONAL_CALL` | FUN_10007fc0 | `10007fc0` |
| `10007bf2` | `10007c40` | `UNCONDITIONAL_CALL` | FUN_10007c40 | `10007c40` |

## Callers

| From | Function |
| --- | --- |
| `10007a2a` | FUN_10007a20 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10007be0` | `55` | `PUSH EBP` |
| `10007be1` | `8b ec` | `MOV EBP,ESP` |
| `10007be3` | `51` | `PUSH ECX` |
| `10007be4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10007be7` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10007bea` | `e8 d1 03 00 00` | `CALL 0x10007fc0` |
| `10007bef` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10007bf2` | `e8 49 00 00 00` | `CALL 0x10007c40` |
| `10007bf7` | `8b e5` | `MOV ESP,EBP` |
| `10007bf9` | `5d` | `POP EBP` |
| `10007bfa` | `c3` | `RET` |
