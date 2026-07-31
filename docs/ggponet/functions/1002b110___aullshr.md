# 1002b110 `__aullshr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002b110 |
| `name` | __aullshr |
| `namespace` | Global |
| `signature` | undefined __aullshr(void) |
| `size_bytes` | 31 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __aullshr |

## Decompiled C

```c

/* Library Function - Single Match
    __aullshr
   
   Library: Visual Studio 2008 Release */

ulonglong __aullshr(void)

{
  uint in_EAX;
  byte in_CL;
  uint in_EDX;
  
  if (0x3f < in_CL) {
    return 0;
  }
  if (in_CL < 0x20) {
    return CONCAT44(in_EDX >> (in_CL & 0x1f),
                    in_EAX >> (in_CL & 0x1f) | in_EDX << 0x20 - (in_CL & 0x1f));
  }
  return (ulonglong)(in_EDX >> (in_CL & 0x1f));
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002a728` | __cftoa_l |
| `1002a77c` | __cftoa_l |
| `1002a7f0` | __cftoa_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002b110` | `80 f9 40` | `CMP CL,0x40` |
| `1002b113` | `73 15` | `JNC 0x1002b12a` |
| `1002b115` | `80 f9 20` | `CMP CL,0x20` |
| `1002b118` | `73 06` | `JNC 0x1002b120` |
| `1002b11a` | `0f ad d0` | `SHRD EAX,EDX,CL` |
| `1002b11d` | `d3 ea` | `SHR EDX,CL` |
| `1002b11f` | `c3` | `RET` |
| `1002b120` | `8b c2` | `MOV EAX,EDX` |
| `1002b122` | `33 d2` | `XOR EDX,EDX` |
| `1002b124` | `80 e1 1f` | `AND CL,0x1f` |
| `1002b127` | `d3 e8` | `SHR EAX,CL` |
| `1002b129` | `c3` | `RET` |
| `1002b12a` | `33 c0` | `XOR EAX,EAX` |
| `1002b12c` | `33 d2` | `XOR EDX,EDX` |
| `1002b12e` | `c3` | `RET` |
