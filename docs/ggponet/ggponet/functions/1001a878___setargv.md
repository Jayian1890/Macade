# 1001a878 `__setargv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a878 |
| `name` | __setargv |
| `namespace` | Global |
| `signature` | int __cdecl __setargv(void) |
| `size_bytes` | 187 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __setargv |

## Decompiled C

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 2008 Release */

int __cdecl __setargv(void)

{
  uint _Size;
  void *pvVar1;
  int iVar2;
  uint local_10;
  uint local_c;
  char *local_8;
  
  if (DAT_1343a698 == 0) {
    ___initmbctable();
  }
  DAT_1003937c = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_10039278,0x104);
  _DAT_10038a5c = &DAT_10039278;
  if ((DAT_1343a688 == (char *)0x0) || (local_8 = DAT_1343a688, *DAT_1343a688 == '\0')) {
    local_8 = &DAT_10039278;
  }
  parse_cmdline(0,0,&local_c);
  if ((local_c < 0x3fffffff) && (local_10 != 0xffffffff)) {
    iVar2 = local_c * 4;
    _Size = iVar2 + local_10;
    if ((local_10 <= _Size) && (pvVar1 = __malloc_crt(_Size), pvVar1 != (void *)0x0)) {
      parse_cmdline(pvVar1,(void *)(iVar2 + (int)pvVar1),&local_c);
      _DAT_10038a40 = local_c - 1;
      _DAT_10038a44 = pvVar1;
      return 0;
    }
  }
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a88d` | `1001c23c` | `UNCONDITIONAL_CALL` | ___initmbctable | `1001c23c` |
| `1001a8a4` | `EXTERNAL:00000047` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleFileNameA | `` |
| `1001a8cf` | `1001a6de` | `UNCONDITIONAL_CALL` | parse_cmdline | `1001a6de` |
| `1001a8f6` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001a910` | `1001a6de` | `UNCONDITIONAL_CALL` | parse_cmdline | `1001a6de` |

## Callers

| From | Function |
| --- | --- |
| `100146ca` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a885` | `1343a698` | `READ` | DAT_1343a698 |
| `1001a897` | `10039278` | `DATA` | DAT_10039278 |
| `1001a89c` | `10039278` | `DATA` | DAT_10039278 |
| `1001a89e` | `1003937c` | `WRITE` | DAT_1003937c |
| `1001a8a4` | `1002e0d4` | `READ` | PTR_GetModuleFileNameA_1002e0d4 |
| `1001a8aa` | `1343a688` | `READ` | DAT_1343a688 |
| `1001a8af` | `10038a5c` | `WRITE` | DAT_10038a5c |
| `1001a8c0` | `10039278` | `DATA` | DAT_10039278 |
| `1001a91c` | `10038a40` | `WRITE` | DAT_10038a40 |
| `1001a921` | `10038a44` | `WRITE` | DAT_10038a44 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a878` | `8b ff` | `MOV EDI,EDI` |
| `1001a87a` | `55` | `PUSH EBP` |
| `1001a87b` | `8b ec` | `MOV EBP,ESP` |
| `1001a87d` | `83 ec 0c` | `SUB ESP,0xc` |
| `1001a880` | `53` | `PUSH EBX` |
| `1001a881` | `33 db` | `XOR EBX,EBX` |
| `1001a883` | `56` | `PUSH ESI` |
| `1001a884` | `57` | `PUSH EDI` |
| `1001a885` | `39 1d 98 a6 43 13` | `CMP dword ptr [0x1343a698],EBX` |
| `1001a88b` | `75 05` | `JNZ 0x1001a892` |
| `1001a88d` | `e8 aa 19 00 00` | `CALL 0x1001c23c` |
| `1001a892` | `68 04 01 00 00` | `PUSH 0x104` |
| `1001a897` | `be 78 92 03 10` | `MOV ESI,0x10039278` |
| `1001a89c` | `56` | `PUSH ESI` |
| `1001a89d` | `53` | `PUSH EBX` |
| `1001a89e` | `88 1d 7c 93 03 10` | `MOV byte ptr [0x1003937c],BL` |
| `1001a8a4` | `ff 15 d4 e0 02 10` | `CALL dword ptr [0x1002e0d4]` |
| `1001a8aa` | `a1 88 a6 43 13` | `MOV EAX,[0x1343a688]` |
| `1001a8af` | `89 35 5c 8a 03 10` | `MOV dword ptr [0x10038a5c],ESI` |
| `1001a8b5` | `3b c3` | `CMP EAX,EBX` |
| `1001a8b7` | `74 07` | `JZ 0x1001a8c0` |
| `1001a8b9` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001a8bc` | `38 18` | `CMP byte ptr [EAX],BL` |
| `1001a8be` | `75 03` | `JNZ 0x1001a8c3` |
| `1001a8c0` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `1001a8c3` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `1001a8c6` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001a8c9` | `50` | `PUSH EAX` |
| `1001a8ca` | `53` | `PUSH EBX` |
| `1001a8cb` | `53` | `PUSH EBX` |
| `1001a8cc` | `8d 7d f4` | `LEA EDI,[EBP + -0xc]` |
| `1001a8cf` | `e8 0a fe ff ff` | `CALL 0x1001a6de` |
| `1001a8d4` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001a8d7` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001a8da` | `3d ff ff ff 3f` | `CMP EAX,0x3fffffff` |
| `1001a8df` | `73 4a` | `JNC 0x1001a92b` |
| `1001a8e1` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `1001a8e4` | `83 f9 ff` | `CMP ECX,-0x1` |
| `1001a8e7` | `73 42` | `JNC 0x1001a92b` |
| `1001a8e9` | `8b f8` | `MOV EDI,EAX` |
| `1001a8eb` | `c1 e7 02` | `SHL EDI,0x2` |
| `1001a8ee` | `8d 04 0f` | `LEA EAX,[EDI + ECX*0x1]` |
| `1001a8f1` | `3b c1` | `CMP EAX,ECX` |
| `1001a8f3` | `72 36` | `JC 0x1001a92b` |
| `1001a8f5` | `50` | `PUSH EAX` |
| `1001a8f6` | `e8 d4 fb ff ff` | `CALL 0x1001a4cf` |
| `1001a8fb` | `8b f0` | `MOV ESI,EAX` |
| `1001a8fd` | `59` | `POP ECX` |
| `1001a8fe` | `3b f3` | `CMP ESI,EBX` |
| `1001a900` | `74 29` | `JZ 0x1001a92b` |
| `1001a902` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `1001a905` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001a908` | `50` | `PUSH EAX` |
| `1001a909` | `03 fe` | `ADD EDI,ESI` |
| `1001a90b` | `57` | `PUSH EDI` |
| `1001a90c` | `56` | `PUSH ESI` |
| `1001a90d` | `8d 7d f4` | `LEA EDI,[EBP + -0xc]` |
| `1001a910` | `e8 c9 fd ff ff` | `CALL 0x1001a6de` |
| `1001a915` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001a918` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001a91b` | `48` | `DEC EAX` |
| `1001a91c` | `a3 40 8a 03 10` | `MOV [0x10038a40],EAX` |
| `1001a921` | `89 35 44 8a 03 10` | `MOV dword ptr [0x10038a44],ESI` |
| `1001a927` | `33 c0` | `XOR EAX,EAX` |
| `1001a929` | `eb 03` | `JMP 0x1001a92e` |
| `1001a92b` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a92e` | `5f` | `POP EDI` |
| `1001a92f` | `5e` | `POP ESI` |
| `1001a930` | `5b` | `POP EBX` |
| `1001a931` | `c9` | `LEAVE` |
| `1001a932` | `c3` | `RET` |
