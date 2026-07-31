# 100196a3 `___CppXcptFilter`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100196a3 |
| `name` | ___CppXcptFilter |
| `namespace` | Global |
| `signature` | int __cdecl ___CppXcptFilter(ulong _ExceptionNum, _EXCEPTION_POINTERS * _ExceptionPtr) |
| `size_bytes` | 32 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___CppXcptFilter |

## Decompiled C

```c

/* Library Function - Single Match
    ___CppXcptFilter
   
   Library: Visual Studio 2008 Release */

int __cdecl ___CppXcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
  if (_ExceptionNum == 0xe06d7363) {
    iVar1 = __XcptFilter(0xe06d7363,_ExceptionPtr);
    return iVar1;
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100196b6` | `10019543` | `UNCONDITIONAL_CALL` | __XcptFilter | `10019543` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100196a3` | `8b ff` | `MOV EDI,EDI` |
| `100196a5` | `55` | `PUSH EBP` |
| `100196a6` | `8b ec` | `MOV EBP,ESP` |
| `100196a8` | `b8 63 73 6d e0` | `MOV EAX,0xe06d7363` |
| `100196ad` | `39 45 08` | `CMP dword ptr [EBP + 0x8],EAX` |
| `100196b0` | `75 0d` | `JNZ 0x100196bf` |
| `100196b2` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `100196b5` | `50` | `PUSH EAX` |
| `100196b6` | `e8 88 fe ff ff` | `CALL 0x10019543` |
| `100196bb` | `59` | `POP ECX` |
| `100196bc` | `59` | `POP ECX` |
| `100196bd` | `5d` | `POP EBP` |
| `100196be` | `c3` | `RET` |
| `100196bf` | `33 c0` | `XOR EAX,EAX` |
| `100196c1` | `5d` | `POP EBP` |
| `100196c2` | `c3` | `RET` |
