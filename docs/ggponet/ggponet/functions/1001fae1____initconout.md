# 1001fae1 `___initconout`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001fae1 |
| `name` | ___initconout |
| `namespace` | Global |
| `signature` | void __cdecl ___initconout(void) |
| `size_bytes` | 31 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___initconout |

## Decompiled C

```c

/* Library Function - Single Match
    ___initconout
   
   Library: Visual Studio 2008 Release */

void __cdecl ___initconout(void)

{
  DAT_10038374 = CreateFileA("CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001faf4` | `EXTERNAL:0000002e` | `COMPUTED_CALL` | KERNEL32.DLL::CreateFileA | `` |

## Callers

| From | Function |
| --- | --- |
| `1001e67e` | __putwch_nolock |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1001faef` | `10030934` | `CONOUT$` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001faf4` | `1002e070` | `READ` | PTR_CreateFileA_1002e070 |
| `1001fafa` | `10038374` | `WRITE` | DAT_10038374 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001fae1` | `33 c0` | `XOR EAX,EAX` |
| `1001fae3` | `50` | `PUSH EAX` |
| `1001fae4` | `50` | `PUSH EAX` |
| `1001fae5` | `6a 03` | `PUSH 0x3` |
| `1001fae7` | `50` | `PUSH EAX` |
| `1001fae8` | `6a 03` | `PUSH 0x3` |
| `1001faea` | `68 00 00 00 40` | `PUSH 0x40000000` |
| `1001faef` | `68 34 09 03 10` | `PUSH 0x10030934` |
| `1001faf4` | `ff 15 70 e0 02 10` | `CALL dword ptr [0x1002e070]` |
| `1001fafa` | `a3 74 83 03 10` | `MOV [0x10038374],EAX` |
| `1001faff` | `c3` | `RET` |
