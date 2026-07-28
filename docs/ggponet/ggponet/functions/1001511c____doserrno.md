# 1001511c `___doserrno`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001511c |
| `name` | ___doserrno |
| `namespace` | Global |
| `signature` | ulong * __cdecl ___doserrno(void) |
| `size_bytes` | 19 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___doserrno |

## Decompiled C

```c

/* Library Function - Single Match
    ___doserrno
   
   Library: Visual Studio 2008 Release */

ulong * __cdecl ___doserrno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (ulong *)&DAT_10037604;
  }
  return &p_Var1->_tdoserrno;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001511c` | `1001735d` | `UNCONDITIONAL_CALL` | __getptd_noexit | `1001735d` |

## Callers

| From | Function |
| --- | --- |
| `1001a326` | __write |
| `1001a34f` | __write |
| `1001a3c4` | __write |
| `10019c20` | __write_nolock |
| `10019c89` | __write_nolock |
| `1001a2aa` | __write_nolock |
| `1001a2ea` | __write_nolock |
| `10015135` | __dosmaperr |
| `1001b9ce` | __lseeki64 |
| `1001b9f8` | __lseeki64 |
| `1001ba39` | __lseeki64 |
| `1001ba99` | __lseeki64 |
| `1001ce2c` | __tsopen_nolock |
| `1001cf95` | __tsopen_nolock |
| `1001d129` | __tsopen_nolock |
| `100185a2` | __read_nolock |
| `100185cc` | __read_nolock |
| `10018612` | __read_nolock |
| `1001867e` | __read_nolock |
| `100186c8` | __read_nolock |
| `10018b24` | __read_nolock |
| `1001db21` | __set_osfhnd |
| `1001dba7` | __free_osfhnd |
| `1001dbc3` | __get_osfhandle |
| `1001dc04` | __get_osfhandle |
| `1001f44c` | __chsize_nolock |
| `1001f4c0` | __chsize_nolock |
| `1001a497` | __commit |
| `10018b5c` | __read |
| `10018b85` | __read |
| `10018bd3` | __read |
| `10018c1b` | __read |
| `10018d27` | __close |
| `10018d50` | __close |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10015125` | `10037604` | `DATA` | DAT_10037604 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001511c` | `e8 3c 22 00 00` | `CALL 0x1001735d` |
| `10015121` | `85 c0` | `TEST EAX,EAX` |
| `10015123` | `75 06` | `JNZ 0x1001512b` |
| `10015125` | `b8 04 76 03 10` | `MOV EAX,0x10037604` |
| `1001512a` | `c3` | `RET` |
| `1001512b` | `83 c0 0c` | `ADD EAX,0xc` |
| `1001512e` | `c3` | `RET` |
