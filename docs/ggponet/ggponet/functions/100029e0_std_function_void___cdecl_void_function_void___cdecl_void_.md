# 100029e0 `std::function<void___cdecl(void)>::~function<void___cdecl(void)>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100029e0 |
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
  FUN_10002b30(this);
  FUN_10007c40();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100029ea` | `10002b30` | `UNCONDITIONAL_CALL` | FUN_10002b30 | `10002b30` |
| `100029f2` | `10007c40` | `UNCONDITIONAL_CALL` | FUN_10007c40 | `10007c40` |

## Callers

| From | Function |
| --- | --- |
| `1000298a` | FUN_10002980 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100029e0` | `55` | `PUSH EBP` |
| `100029e1` | `8b ec` | `MOV EBP,ESP` |
| `100029e3` | `51` | `PUSH ECX` |
| `100029e4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `100029e7` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100029ea` | `e8 41 01 00 00` | `CALL 0x10002b30` |
| `100029ef` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100029f2` | `e8 49 52 00 00` | `CALL 0x10007c40` |
| `100029f7` | `8b e5` | `MOV ESP,EBP` |
| `100029f9` | `5d` | `POP EBP` |
| `100029fa` | `c3` | `RET` |
