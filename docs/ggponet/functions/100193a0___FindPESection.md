# 100193a0 `__FindPESection`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100193a0 |
| `name` | __FindPESection |
| `namespace` | Global |
| `signature` | PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase, DWORD_PTR rva) |
| `size_bytes` | 68 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __FindPESection |

## Decompiled C

```c

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2008 Release */

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14) + 0x18 + iVar1);
  if (*(ushort *)(pImageBase + iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001944b` | __IsNonwritableInCurrentImage |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100193a0` | `8b ff` | `MOV EDI,EDI` |
| `100193a2` | `55` | `PUSH EBP` |
| `100193a3` | `8b ec` | `MOV EBP,ESP` |
| `100193a5` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100193a8` | `8b 48 3c` | `MOV ECX,dword ptr [EAX + 0x3c]` |
| `100193ab` | `03 c8` | `ADD ECX,EAX` |
| `100193ad` | `0f b7 41 14` | `MOVZX EAX,word ptr [ECX + 0x14]` |
| `100193b1` | `53` | `PUSH EBX` |
| `100193b2` | `56` | `PUSH ESI` |
| `100193b3` | `0f b7 71 06` | `MOVZX ESI,word ptr [ECX + 0x6]` |
| `100193b7` | `33 d2` | `XOR EDX,EDX` |
| `100193b9` | `57` | `PUSH EDI` |
| `100193ba` | `8d 44 08 18` | `LEA EAX,[EAX + ECX*0x1 + 0x18]` |
| `100193be` | `85 f6` | `TEST ESI,ESI` |
| `100193c0` | `76 1b` | `JBE 0x100193dd` |
| `100193c2` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `100193c5` | `8b 48 0c` | `MOV ECX,dword ptr [EAX + 0xc]` |
| `100193c8` | `3b f9` | `CMP EDI,ECX` |
| `100193ca` | `72 09` | `JC 0x100193d5` |
| `100193cc` | `8b 58 08` | `MOV EBX,dword ptr [EAX + 0x8]` |
| `100193cf` | `03 d9` | `ADD EBX,ECX` |
| `100193d1` | `3b fb` | `CMP EDI,EBX` |
| `100193d3` | `72 0a` | `JC 0x100193df` |
| `100193d5` | `42` | `INC EDX` |
| `100193d6` | `83 c0 28` | `ADD EAX,0x28` |
| `100193d9` | `3b d6` | `CMP EDX,ESI` |
| `100193db` | `72 e8` | `JC 0x100193c5` |
| `100193dd` | `33 c0` | `XOR EAX,EAX` |
| `100193df` | `5f` | `POP EDI` |
| `100193e0` | `5e` | `POP ESI` |
| `100193e1` | `5b` | `POP EBX` |
| `100193e2` | `5d` | `POP EBP` |
| `100193e3` | `c3` | `RET` |
