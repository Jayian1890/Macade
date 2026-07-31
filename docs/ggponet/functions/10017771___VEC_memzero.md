# 10017771 `__VEC_memzero`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017771 |
| `name` | __VEC_memzero |
| `namespace` | Global |
| `signature` | undefined __VEC_memzero(void) |
| `size_bytes` | 143 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __VEC_memzero |

## Decompiled C

```c

/* Library Function - Single Match
    __VEC_memzero
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2005 Release, Visual Studio 2008 Debug, Visual
   Studio 2008 Release */

undefined1 * __VEC_memzero(undefined1 *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  uVar2 = (int)param_1 >> 0x1f;
  iVar3 = (((uint)param_1 ^ uVar2) - uVar2 & 0xf ^ uVar2) - uVar2;
  if (iVar3 == 0) {
    uVar2 = param_3 & 0x7f;
    if (param_3 != uVar2) {
      fastzero_I(param_1,param_3 - uVar2);
    }
    if (uVar2 != 0) {
      puVar4 = param_1 + (param_3 - uVar2);
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
  }
  else {
    iVar3 = 0x10 - iVar3;
    puVar4 = param_1;
    for (iVar1 = iVar3; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    __VEC_memzero(param_1 + iVar3,0,param_3 - iVar3);
  }
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100177a2` | `1001771a` | `UNCONDITIONAL_CALL` | fastzero_I | `1001771a` |
| `100177ee` | `10017771` | `UNCONDITIONAL_CALL` | __VEC_memzero | `10017771` |

## Callers

| From | Function |
| --- | --- |
| `100177ee` | __VEC_memzero |
| `10011717` | _memset |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017771` | `55` | `PUSH EBP` |
| `10017772` | `8b ec` | `MOV EBP,ESP` |
| `10017774` | `83 ec 10` | `SUB ESP,0x10` |
| `10017777` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `1001777a` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001777d` | `99` | `CDQ` |
| `1001777e` | `8b f8` | `MOV EDI,EAX` |
| `10017780` | `33 fa` | `XOR EDI,EDX` |
| `10017782` | `2b fa` | `SUB EDI,EDX` |
| `10017784` | `83 e7 0f` | `AND EDI,0xf` |
| `10017787` | `33 fa` | `XOR EDI,EDX` |
| `10017789` | `2b fa` | `SUB EDI,EDX` |
| `1001778b` | `85 ff` | `TEST EDI,EDI` |
| `1001778d` | `75 3c` | `JNZ 0x100177cb` |
| `1001778f` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10017792` | `8b d1` | `MOV EDX,ECX` |
| `10017794` | `83 e2 7f` | `AND EDX,0x7f` |
| `10017797` | `89 55 f4` | `MOV dword ptr [EBP + -0xc],EDX` |
| `1001779a` | `3b ca` | `CMP ECX,EDX` |
| `1001779c` | `74 12` | `JZ 0x100177b0` |
| `1001779e` | `2b ca` | `SUB ECX,EDX` |
| `100177a0` | `51` | `PUSH ECX` |
| `100177a1` | `50` | `PUSH EAX` |
| `100177a2` | `e8 73 ff ff ff` | `CALL 0x1001771a` |
| `100177a7` | `83 c4 08` | `ADD ESP,0x8` |
| `100177aa` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100177ad` | `8b 55 f4` | `MOV EDX,dword ptr [EBP + -0xc]` |
| `100177b0` | `85 d2` | `TEST EDX,EDX` |
| `100177b2` | `74 45` | `JZ 0x100177f9` |
| `100177b4` | `03 45 10` | `ADD EAX,dword ptr [EBP + 0x10]` |
| `100177b7` | `2b c2` | `SUB EAX,EDX` |
| `100177b9` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `100177bc` | `33 c0` | `XOR EAX,EAX` |
| `100177be` | `8b 7d f8` | `MOV EDI,dword ptr [EBP + -0x8]` |
| `100177c1` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `100177c4` | `f3 aa` | `STOSB.REP ES:EDI` |
| `100177c6` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100177c9` | `eb 2e` | `JMP 0x100177f9` |
| `100177cb` | `f7 df` | `NEG EDI` |
| `100177cd` | `83 c7 10` | `ADD EDI,0x10` |
| `100177d0` | `89 7d f0` | `MOV dword ptr [EBP + -0x10],EDI` |
| `100177d3` | `33 c0` | `XOR EAX,EAX` |
| `100177d5` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `100177d8` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `100177db` | `f3 aa` | `STOSB.REP ES:EDI` |
| `100177dd` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100177e0` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100177e3` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `100177e6` | `03 c8` | `ADD ECX,EAX` |
| `100177e8` | `2b d0` | `SUB EDX,EAX` |
| `100177ea` | `52` | `PUSH EDX` |
| `100177eb` | `6a 00` | `PUSH 0x0` |
| `100177ed` | `51` | `PUSH ECX` |
| `100177ee` | `e8 7e ff ff ff` | `CALL 0x10017771` |
| `100177f3` | `83 c4 0c` | `ADD ESP,0xc` |
| `100177f6` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100177f9` | `8b 7d fc` | `MOV EDI,dword ptr [EBP + -0x4]` |
| `100177fc` | `8b e5` | `MOV ESP,EBP` |
| `100177fe` | `5d` | `POP EBP` |
| `100177ff` | `c3` | `RET` |
