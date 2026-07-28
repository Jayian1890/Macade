# 10003600 `std::function<void___cdecl(void)>::~function<void___cdecl(void)>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10003600 |
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
  FUN_100037c0(this);
  FUN_10007c40();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000360a` | `100037c0` | `UNCONDITIONAL_CALL` | FUN_100037c0 | `100037c0` |
| `10003612` | `10007c40` | `UNCONDITIONAL_CALL` | FUN_10007c40 | `10007c40` |

## Callers

| From | Function |
| --- | --- |
| `1000358a` | FUN_10003580 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10003600` | `55` | `PUSH EBP` |
| `10003601` | `8b ec` | `MOV EBP,ESP` |
| `10003603` | `51` | `PUSH ECX` |
| `10003604` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10003607` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000360a` | `e8 b1 01 00 00` | `CALL 0x100037c0` |
| `1000360f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10003612` | `e8 29 46 00 00` | `CALL 0x10007c40` |
| `10003617` | `8b e5` | `MOV ESP,EBP` |
| `10003619` | `5d` | `POP EBP` |
| `1000361a` | `c3` | `RET` |
