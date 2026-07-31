# 10003f20 `std::function<void___cdecl(void)>::~function<void___cdecl(void)>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10003f20 |
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
  FUN_10004130(this);
  FUN_10007c40();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10003f2a` | `10004130` | `UNCONDITIONAL_CALL` | FUN_10004130 | `10004130` |
| `10003f32` | `10007c40` | `UNCONDITIONAL_CALL` | FUN_10007c40 | `10007c40` |

## Callers

| From | Function |
| --- | --- |
| `10003e6a` | FUN_10003e60 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10003f20` | `55` | `PUSH EBP` |
| `10003f21` | `8b ec` | `MOV EBP,ESP` |
| `10003f23` | `51` | `PUSH ECX` |
| `10003f24` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10003f27` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10003f2a` | `e8 01 02 00 00` | `CALL 0x10004130` |
| `10003f2f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10003f32` | `e8 09 3d 00 00` | `CALL 0x10007c40` |
| `10003f37` | `8b e5` | `MOV ESP,EBP` |
| `10003f39` | `5d` | `POP EBP` |
| `10003f3a` | `c3` | `RET` |
