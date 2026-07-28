# 1001512f `__dosmaperr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001512f |
| `name` | __dosmaperr |
| `namespace` | Global |
| `signature` | void __cdecl __dosmaperr(ulong param_1) |
| `size_bytes` | 35 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __dosmaperr |

## Decompiled C

```c

/* Library Function - Single Match
    __dosmaperr
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __dosmaperr(ulong param_1)

{
  ulong *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = ___doserrno();
  *puVar1 = param_1;
  iVar2 = __get_errno_from_oserr(param_1);
  piVar3 = __errno();
  *piVar3 = iVar2;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10015135` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `10015140` | `100150c7` | `UNCONDITIONAL_CALL` | __get_errno_from_oserr | `100150c7` |
| `10015148` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `1001a2b9` | __write_nolock |
| `1001b986` | __lseeki64_nolock |
| `1001d037` | __tsopen_nolock |
| `1001d07a` | __tsopen_nolock |
| `1001d477` | __tsopen_nolock |
| `10018993` | __read_nolock |
| `10018d02` | __close_nolock |
| `1001f54d` | __lseek_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001512f` | `8b ff` | `MOV EDI,EDI` |
| `10015131` | `55` | `PUSH EBP` |
| `10015132` | `8b ec` | `MOV EBP,ESP` |
| `10015134` | `56` | `PUSH ESI` |
| `10015135` | `e8 e2 ff ff ff` | `CALL 0x1001511c` |
| `1001513a` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001513d` | `51` | `PUSH ECX` |
| `1001513e` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `10015140` | `e8 82 ff ff ff` | `CALL 0x100150c7` |
| `10015145` | `59` | `POP ECX` |
| `10015146` | `8b f0` | `MOV ESI,EAX` |
| `10015148` | `e8 bc ff ff ff` | `CALL 0x10015109` |
| `1001514d` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001514f` | `5e` | `POP ESI` |
| `10015150` | `5d` | `POP EBP` |
| `10015151` | `c3` | `RET` |
