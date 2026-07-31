# 1001aeba `IsInExceptionSpec`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001aeba |
| `name` | IsInExceptionSpec |
| `namespace` | Global |
| `signature` | uchar __cdecl IsInExceptionSpec(EHExceptionRecord * param_1, _s_ESTypeList * param_2) |
| `size_bytes` | 123 |
| `stack_frame_size` | 28 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?IsInExceptionSpec@@YAEPAUEHExceptionRecord@@PBU_s_ESTypeList@@@Z, IsInExceptionSpec |

## Decompiled C

```c

/* Library Function - Single Match
    unsigned char __cdecl IsInExceptionSpec(struct EHExceptionRecord *,struct _s_ESTypeList const *)
   
   Library: Visual Studio 2008 Release */

uchar __cdecl IsInExceptionSpec(EHExceptionRecord *param_1,_s_ESTypeList *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  int local_c;
  uchar local_5;
  
  if (unaff_EDI == (int *)0x0) {
    _inconsistency();
    terminate();
  }
  local_c = 0;
  local_5 = '\0';
  if (0 < *unaff_EDI) {
    do {
      piVar3 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
      iVar2 = *piVar3;
      if (0 < iVar2) {
        do {
          piVar3 = piVar3 + 1;
          iVar1 = ___TypeMatch(unaff_EDI[1] + local_c * 0x10,*piVar3,*(undefined4 *)(param_1 + 0x1c)
                              );
          if (iVar1 != 0) {
            local_5 = '\x01';
            break;
          }
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
      }
      local_c = local_c + 1;
    } while (local_c < *unaff_EDI);
  }
  return local_5;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001aec6` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001aecb` | `100194ad` | `UNCONDITIONAL_CALL` | terminate | `100194ad` |
| `1001af0a` | `1001ac6e` | `UNCONDITIONAL_CALL` | ___TypeMatch | `1001ac6e` |

## Callers

| From | Function |
| --- | --- |
| `1001b59c` | FindHandler |
| `1001b72c` | FindHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001aeba` | `8b ff` | `MOV EDI,EDI` |
| `1001aebc` | `55` | `PUSH EBP` |
| `1001aebd` | `8b ec` | `MOV EBP,ESP` |
| `1001aebf` | `83 ec 0c` | `SUB ESP,0xc` |
| `1001aec2` | `85 ff` | `TEST EDI,EDI` |
| `1001aec4` | `75 0a` | `JNZ 0x1001aed0` |
| `1001aec6` | `e8 2e e6 ff ff` | `CALL 0x100194f9` |
| `1001aecb` | `e8 dd e5 ff ff` | `CALL 0x100194ad` |
| `1001aed0` | `83 65 f8 00` | `AND dword ptr [EBP + -0x8],0x0` |
| `1001aed4` | `83 3f 00` | `CMP dword ptr [EDI],0x0` |
| `1001aed7` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `1001aedb` | `7e 53` | `JLE 0x1001af30` |
| `1001aedd` | `53` | `PUSH EBX` |
| `1001aede` | `56` | `PUSH ESI` |
| `1001aedf` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001aee2` | `8b 40 1c` | `MOV EAX,dword ptr [EAX + 0x1c]` |
| `1001aee5` | `8b 40 0c` | `MOV EAX,dword ptr [EAX + 0xc]` |
| `1001aee8` | `8b 18` | `MOV EBX,dword ptr [EAX]` |
| `1001aeea` | `8d 70 04` | `LEA ESI,[EAX + 0x4]` |
| `1001aeed` | `85 db` | `TEST EBX,EBX` |
| `1001aeef` | `7e 33` | `JLE 0x1001af24` |
| `1001aef1` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001aef4` | `c1 e0 04` | `SHL EAX,0x4` |
| `1001aef7` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1001aefa` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001aefd` | `ff 71 1c` | `PUSH dword ptr [ECX + 0x1c]` |
| `1001af00` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001af02` | `50` | `PUSH EAX` |
| `1001af03` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1001af06` | `03 45 f4` | `ADD EAX,dword ptr [EBP + -0xc]` |
| `1001af09` | `50` | `PUSH EAX` |
| `1001af0a` | `e8 5f fd ff ff` | `CALL 0x1001ac6e` |
| `1001af0f` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001af12` | `85 c0` | `TEST EAX,EAX` |
| `1001af14` | `75 0a` | `JNZ 0x1001af20` |
| `1001af16` | `4b` | `DEC EBX` |
| `1001af17` | `83 c6 04` | `ADD ESI,0x4` |
| `1001af1a` | `85 db` | `TEST EBX,EBX` |
| `1001af1c` | `7f dc` | `JG 0x1001aefa` |
| `1001af1e` | `eb 04` | `JMP 0x1001af24` |
| `1001af20` | `c6 45 ff 01` | `MOV byte ptr [EBP + -0x1],0x1` |
| `1001af24` | `ff 45 f8` | `INC dword ptr [EBP + -0x8]` |
| `1001af27` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001af2a` | `3b 07` | `CMP EAX,dword ptr [EDI]` |
| `1001af2c` | `7c b1` | `JL 0x1001aedf` |
| `1001af2e` | `5e` | `POP ESI` |
| `1001af2f` | `5b` | `POP EBX` |
| `1001af30` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `1001af33` | `c9` | `LEAVE` |
| `1001af34` | `c3` | `RET` |
