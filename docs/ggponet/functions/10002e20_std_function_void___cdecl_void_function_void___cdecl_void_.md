# 10002e20 `std::function<void___cdecl(void)>::~function<void___cdecl(void)>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002e20 |
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
  FUN_10003030(this);
  FUN_10007c40();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10002e2a` | `10003030` | `UNCONDITIONAL_CALL` | FUN_10003030 | `10003030` |
| `10002e32` | `10007c40` | `UNCONDITIONAL_CALL` | FUN_10007c40 | `10007c40` |

## Callers

| From | Function |
| --- | --- |
| `10002d8a` | FUN_10002d80 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002e20` | `55` | `PUSH EBP` |
| `10002e21` | `8b ec` | `MOV EBP,ESP` |
| `10002e23` | `51` | `PUSH ECX` |
| `10002e24` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10002e27` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10002e2a` | `e8 01 02 00 00` | `CALL 0x10003030` |
| `10002e2f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10002e32` | `e8 09 4e 00 00` | `CALL 0x10007c40` |
| `10002e37` | `8b e5` | `MOV ESP,EBP` |
| `10002e39` | `5d` | `POP EBP` |
| `10002e3a` | `c3` | `RET` |
