# 10015058 `__get_sse2_info`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10015058 |
| `name` | __get_sse2_info |
| `namespace` | Global |
| `signature` | undefined __get_sse2_info(void) |
| `size_bytes` | 98 |
| `stack_frame_size` | 32 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __get_sse2_info |

## Decompiled C

```c

/* WARNING: Removing unreachable block (ram,0x10015095) */
/* WARNING: Removing unreachable block (ram,0x10015082) */
/* Library Function - Single Match
    __get_sse2_info
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

undefined4 __get_sse2_info(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar4;
  undefined4 local_8;
  
  local_8 = 0;
  uVar4 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | 0x40
          | (uint)(in_AF & 1) * 0x10 | 4 | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar1 = uVar4 ^ 0x200000;
  if (((uint)((uVar1 & 0x4000) != 0) * 0x4000 | (uint)((uVar1 & 0x200) != 0) * 0x200 |
       (uint)((uVar1 & 0x100) != 0) * 0x100 | (uint)((uVar1 & 0x40) != 0) * 0x40 |
       (uint)((uVar1 & 0x10) != 0) * 0x10 | (uint)((uVar1 & 4) != 0) * 4 |
       (uint)((uVar1 & 0x200000) != 0) * 0x200000 | (uint)((uVar1 & 0x40000) != 0) * 0x40000) !=
      uVar4) {
    cpuid_basic_info(0);
    iVar2 = cpuid_Version_info(1);
    local_8 = *(uint *)(iVar2 + 8);
  }
  if (((local_8 & 0x4000000) == 0) || (iVar2 = FUN_10015008(), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100150a7` | `10015008` | `UNCONDITIONAL_CALL` | FUN_10015008 | `10015008` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10015058` | `8b ff` | `MOV EDI,EDI` |
| `1001505a` | `55` | `PUSH EBP` |
| `1001505b` | `8b ec` | `MOV EBP,ESP` |
| `1001505d` | `83 ec 18` | `SUB ESP,0x18` |
| `10015060` | `33 c0` | `XOR EAX,EAX` |
| `10015062` | `53` | `PUSH EBX` |
| `10015063` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10015066` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10015069` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001506c` | `53` | `PUSH EBX` |
| `1001506d` | `9c` | `PUSHFD` |
| `1001506e` | `58` | `POP EAX` |
| `1001506f` | `8b c8` | `MOV ECX,EAX` |
| `10015071` | `35 00 00 20 00` | `XOR EAX,0x200000` |
| `10015076` | `50` | `PUSH EAX` |
| `10015077` | `9d` | `POPFD` |
| `10015078` | `9c` | `PUSHFD` |
| `10015079` | `5a` | `POP EDX` |
| `1001507a` | `2b d1` | `SUB EDX,ECX` |
| `1001507c` | `74 1f` | `JZ 0x1001509d` |
| `1001507e` | `51` | `PUSH ECX` |
| `1001507f` | `9d` | `POPFD` |
| `10015080` | `33 c0` | `XOR EAX,EAX` |
| `10015082` | `0f a2` | `CPUID` |
| `10015084` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10015087` | `89 5d e8` | `MOV dword ptr [EBP + -0x18],EBX` |
| `1001508a` | `89 55 ec` | `MOV dword ptr [EBP + -0x14],EDX` |
| `1001508d` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `10015090` | `b8 01 00 00 00` | `MOV EAX,0x1` |
| `10015095` | `0f a2` | `CPUID` |
| `10015097` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `1001509a` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001509d` | `5b` | `POP EBX` |
| `1001509e` | `f7 45 fc 00 00 00 04` | `TEST dword ptr [EBP + -0x4],0x4000000` |
| `100150a5` | `74 0e` | `JZ 0x100150b5` |
| `100150a7` | `e8 5c ff ff ff` | `CALL 0x10015008` |
| `100150ac` | `85 c0` | `TEST EAX,EAX` |
| `100150ae` | `74 05` | `JZ 0x100150b5` |
| `100150b0` | `33 c0` | `XOR EAX,EAX` |
| `100150b2` | `40` | `INC EAX` |
| `100150b3` | `eb 02` | `JMP 0x100150b7` |
| `100150b5` | `33 c0` | `XOR EAX,EAX` |
| `100150b7` | `5b` | `POP EBX` |
| `100150b8` | `c9` | `LEAVE` |
| `100150b9` | `c3` | `RET` |
