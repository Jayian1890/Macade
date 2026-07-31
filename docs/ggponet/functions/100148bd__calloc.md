# 100148bd `_calloc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100148bd |
| `name` | _calloc |
| `namespace` | Global |
| `signature` | void * __cdecl _calloc(size_t _Count, size_t _Size) |
| `size_bytes` | 64 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _calloc |

## Decompiled C

```c

/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 2008 Release */

void * __cdecl _calloc(size_t _Count,size_t _Size)

{
  void *pvVar1;
  int *piVar2;
  int local_8;
  
  local_8 = 0;
  pvVar1 = (void *)__calloc_impl(_Count,_Size,&local_8);
  if ((pvVar1 == (void *)0x0) && (local_8 != 0)) {
    piVar2 = __errno();
    if (piVar2 != (int *)0x0) {
      piVar2 = __errno();
      *piVar2 = local_8;
    }
  }
  return pvVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100148d2` | `1001ab00` | `UNCONDITIONAL_CALL` | __calloc_impl | `1001ab00` |
| `100148e5` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100148ee` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `1000cda6` | FUN_1000cda0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100148bd` | `8b ff` | `MOV EDI,EDI` |
| `100148bf` | `55` | `PUSH EBP` |
| `100148c0` | `8b ec` | `MOV EBP,ESP` |
| `100148c2` | `51` | `PUSH ECX` |
| `100148c3` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `100148c7` | `56` | `PUSH ESI` |
| `100148c8` | `8d 45 fc` | `LEA EAX,[EBP + -0x4]` |
| `100148cb` | `50` | `PUSH EAX` |
| `100148cc` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `100148cf` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100148d2` | `e8 29 62 00 00` | `CALL 0x1001ab00` |
| `100148d7` | `8b f0` | `MOV ESI,EAX` |
| `100148d9` | `83 c4 0c` | `ADD ESP,0xc` |
| `100148dc` | `85 f6` | `TEST ESI,ESI` |
| `100148de` | `75 18` | `JNZ 0x100148f8` |
| `100148e0` | `39 45 fc` | `CMP dword ptr [EBP + -0x4],EAX` |
| `100148e3` | `74 13` | `JZ 0x100148f8` |
| `100148e5` | `e8 1f 08 00 00` | `CALL 0x10015109` |
| `100148ea` | `85 c0` | `TEST EAX,EAX` |
| `100148ec` | `74 0a` | `JZ 0x100148f8` |
| `100148ee` | `e8 16 08 00 00` | `CALL 0x10015109` |
| `100148f3` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100148f6` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `100148f8` | `8b c6` | `MOV EAX,ESI` |
| `100148fa` | `5e` | `POP ESI` |
| `100148fb` | `c9` | `LEAVE` |
| `100148fc` | `c3` | `RET` |
