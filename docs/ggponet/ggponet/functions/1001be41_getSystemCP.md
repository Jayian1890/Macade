# 1001be41 `getSystemCP`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001be41 |
| `name` | getSystemCP |
| `namespace` | Global |
| `signature` | int __cdecl getSystemCP(int param_1) |
| `size_bytes` | 124 |
| `stack_frame_size` | 28 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?getSystemCP@@YAHH@Z, getSystemCP |

## Decompiled C

```c

/* Library Function - Single Match
    int __cdecl getSystemCP(int)
   
   Library: Visual Studio 2008 Release */

int __cdecl getSystemCP(int param_1)

{
  UINT UVar1;
  int unaff_ESI;
  int local_14 [2];
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,(localeinfo_struct *)0x0);
  DAT_10039384 = 0;
  if (unaff_ESI == -2) {
    DAT_10039384 = 1;
    UVar1 = GetOEMCP();
  }
  else if (unaff_ESI == -3) {
    DAT_10039384 = 1;
    UVar1 = GetACP();
  }
  else {
    if (unaff_ESI != -4) {
      if (local_8 == '\0') {
        DAT_10039384 = 0;
        return unaff_ESI;
      }
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      return unaff_ESI;
    }
    UVar1 = *(UINT *)(local_14[0] + 4);
    DAT_10039384 = 1;
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return UVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001be50` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001be6a` | `EXTERNAL:00000062` | `COMPUTED_CALL` | KERNEL32.DLL::GetOEMCP | `` |
| `1001be8d` | `EXTERNAL:00000061` | `COMPUTED_CALL` | KERNEL32.DLL::GetACP | `` |

## Callers

| From | Function |
| --- | --- |
| `1001c0c7` | __setmbcp |
| `1001bed8` | __setmbcp_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001be55` | `10039384` | `WRITE` | DAT_10039384 |
| `1001be60` | `10039384` | `WRITE` | DAT_10039384 |
| `1001be6a` | `1002e140` | `READ` | PTR_GetOEMCP_1002e140 |
| `1001be83` | `10039384` | `WRITE` | DAT_10039384 |
| `1001be8d` | `1002e13c` | `READ` | PTR_GetACP_1002e13c |
| `1001bea0` | `10039384` | `WRITE` | DAT_10039384 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001be41` | `8b ff` | `MOV EDI,EDI` |
| `1001be43` | `55` | `PUSH EBP` |
| `1001be44` | `8b ec` | `MOV EBP,ESP` |
| `1001be46` | `83 ec 10` | `SUB ESP,0x10` |
| `1001be49` | `53` | `PUSH EBX` |
| `1001be4a` | `33 db` | `XOR EBX,EBX` |
| `1001be4c` | `53` | `PUSH EBX` |
| `1001be4d` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001be50` | `e8 61 94 ff ff` | `CALL 0x100152b6` |
| `1001be55` | `89 1d 84 93 03 10` | `MOV dword ptr [0x10039384],EBX` |
| `1001be5b` | `83 fe fe` | `CMP ESI,-0x2` |
| `1001be5e` | `75 1e` | `JNZ 0x1001be7e` |
| `1001be60` | `c7 05 84 93 03 10 01 00 00 00` | `MOV dword ptr [0x10039384],0x1` |
| `1001be6a` | `ff 15 40 e1 02 10` | `CALL dword ptr [0x1002e140]` |
| `1001be70` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001be73` | `74 45` | `JZ 0x1001beba` |
| `1001be75` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001be78` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001be7c` | `eb 3c` | `JMP 0x1001beba` |
| `1001be7e` | `83 fe fd` | `CMP ESI,-0x3` |
| `1001be81` | `75 12` | `JNZ 0x1001be95` |
| `1001be83` | `c7 05 84 93 03 10 01 00 00 00` | `MOV dword ptr [0x10039384],0x1` |
| `1001be8d` | `ff 15 3c e1 02 10` | `CALL dword ptr [0x1002e13c]` |
| `1001be93` | `eb db` | `JMP 0x1001be70` |
| `1001be95` | `83 fe fc` | `CMP ESI,-0x4` |
| `1001be98` | `75 12` | `JNZ 0x1001beac` |
| `1001be9a` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001be9d` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001bea0` | `c7 05 84 93 03 10 01 00 00 00` | `MOV dword ptr [0x10039384],0x1` |
| `1001beaa` | `eb c4` | `JMP 0x1001be70` |
| `1001beac` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001beaf` | `74 07` | `JZ 0x1001beb8` |
| `1001beb1` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001beb4` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001beb8` | `8b c6` | `MOV EAX,ESI` |
| `1001beba` | `5b` | `POP EBX` |
| `1001bebb` | `c9` | `LEAVE` |
| `1001bebc` | `c3` | `RET` |
