# 10002720 `std::_Allocate<char>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002720 |
| `name` | std::_Allocate<char> |
| `namespace` | std |
| `signature` | char * __cdecl _Allocate<char>(uint param_1, char * param_2) |
| `size_bytes` | 74 |
| `stack_frame_size` | 28 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ??$_Allocate@D@std@@YAPADIPAD@Z, std::_Allocate<char> |

## Decompiled C

```c

/* Library Function - Single Match
    char * __cdecl std::_Allocate<char>(unsigned int,char *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

char * __cdecl std::_Allocate<char>(uint param_1,char *param_2)

{
  char *pcVar1;
  bad_alloc local_10 [12];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if ((int)(0xffffffff / (ulonglong)param_1) == 0) {
    bad_alloc::bad_alloc(local_10,(char *)0x0);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_10034374);
  }
  pcVar1 = (char *)FUN_100118ec(param_1);
  return pcVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10002747` | `10001000` | `UNCONDITIONAL_CALL` | std::bad_alloc::bad_alloc | `10001000` |
| `10002755` | `100148fd` | `UNCONDITIONAL_CALL` | __CxxThrowException@8 | `100148fd` |
| `1000275e` | `100118ec` | `UNCONDITIONAL_CALL` | FUN_100118ec | `100118ec` |

## Callers

| From | Function |
| --- | --- |
| `100024ed` | std::allocator<char>::allocate |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1000274c` | `10034374` | `DATA` | DAT_10034374 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002720` | `55` | `PUSH EBP` |
| `10002721` | `8b ec` | `MOV EBP,ESP` |
| `10002723` | `83 ec 0c` | `SUB ESP,0xc` |
| `10002726` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1000272a` | `77 09` | `JA 0x10002735` |
| `1000272c` | `c7 45 08 00 00 00 00` | `MOV dword ptr [EBP + 0x8],0x0` |
| `10002733` | `eb 25` | `JMP 0x1000275a` |
| `10002735` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10002738` | `33 d2` | `XOR EDX,EDX` |
| `1000273a` | `f7 75 08` | `DIV dword ptr [EBP + 0x8]` |
| `1000273d` | `83 f8 01` | `CMP EAX,0x1` |
| `10002740` | `73 18` | `JNC 0x1000275a` |
| `10002742` | `6a 00` | `PUSH 0x0` |
| `10002744` | `8d 4d f4` | `LEA ECX,[EBP + -0xc]` |
| `10002747` | `e8 b4 e8 ff ff` | `CALL 0x10001000` |
| `1000274c` | `68 74 43 03 10` | `PUSH 0x10034374` |
| `10002751` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10002754` | `50` | `PUSH EAX` |
| `10002755` | `e8 a3 21 01 00` | `CALL 0x100148fd` |
| `1000275a` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1000275d` | `51` | `PUSH ECX` |
| `1000275e` | `e8 89 f1 00 00` | `CALL 0x100118ec` |
| `10002763` | `83 c4 04` | `ADD ESP,0x4` |
| `10002766` | `8b e5` | `MOV ESP,EBP` |
| `10002768` | `5d` | `POP EBP` |
| `10002769` | `c3` | `RET` |
