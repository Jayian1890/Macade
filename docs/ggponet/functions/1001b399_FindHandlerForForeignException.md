# 1001b399 `FindHandlerForForeignException`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b399 |
| `name` | FindHandlerForForeignException |
| `namespace` | Global |
| `signature` | void __cdecl FindHandlerForForeignException(EHExceptionRecord * param_1, EHRegistrationNode * param_2, _CONTEXT * param_3, void * param_4, _s_FuncInfo * param_5, int param_6, int param_7, EHRegistrationNode * param_8) |
| `size_bytes` | 244 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?FindHandlerForForeignException@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@HH1@Z, FindHandlerForForeignException |

## Decompiled C

```c

/* Library Function - Single Match
    void __cdecl FindHandlerForForeignException(struct EHExceptionRecord *,struct EHRegistrationNode
   *,struct _CONTEXT *,void *,struct _s_FuncInfo const *,int,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2008 Release */

void __cdecl
FindHandlerForForeignException
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  TypeDescriptor *pTVar1;
  _ptiddata p_Var2;
  void *pvVar3;
  int iVar4;
  _s_TryBlockMapEntry *p_Var5;
  _s_TryBlockMapEntry *unaff_EBX;
  EHRegistrationNode *unaff_ESI;
  int unaff_EDI;
  uint extraout_var;
  uint uVar6;
  uint local_8;
  
  if (*(int *)param_1 != -0x7ffffffd) {
    p_Var2 = __getptd();
    uVar6 = extraout_var;
    if (p_Var2->_translator != (void *)0x0) {
      p_Var2 = __getptd();
      pvVar3 = (void *)__encoded_null();
      if (((p_Var2->_translator != pvVar3) && (*(int *)param_1 != -0x1fbcb0b3)) &&
         (iVar4 = _CallSETranslator(param_1,param_2,param_3,param_4,param_5,param_7,param_8),
         iVar4 != 0)) {
        return;
      }
    }
    if (param_5->nTryBlocks == 0) {
      _inconsistency();
    }
    p_Var5 = _GetRangeOfTrysToCheck(param_5,param_7,param_6,&local_8,(uint *)&stack0xfffffff4);
    if (local_8 < uVar6) {
      do {
        if ((p_Var5->tryLow <= param_6) && (param_6 <= p_Var5->tryHigh)) {
          pTVar1 = p_Var5->pHandlerArray[p_Var5->nCatches + -1].pType;
          if (((pTVar1 == (TypeDescriptor *)0x0) || (*(char *)&pTVar1[1].pVFTable == '\0')) &&
             ((p_Var5->pHandlerArray[p_Var5->nCatches + -1].adjectives & 0x40) == 0)) {
            CatchIt(param_1,(EHRegistrationNode *)param_3,param_4,param_5,(_s_FuncInfo *)0x0,
                    (_s_HandlerType *)param_7,(_s_CatchableType *)param_8,unaff_EBX,unaff_EDI,
                    unaff_ESI,(uchar)uVar6);
          }
        }
        local_8 = local_8 + 1;
        p_Var5 = p_Var5 + 1;
      } while (local_8 < uVar6);
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b3b1` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b3bf` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b3ca` | `10017181` | `UNCONDITIONAL_CALL` | __encoded_null | `10017181` |
| `1001b3ee` | `10014a3f` | `UNCONDITIONAL_CALL` | _CallSETranslator | `10014a3f` |
| `1001b407` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001b41c` | `10014bb5` | `UNCONDITIONAL_CALL` | _GetRangeOfTrysToCheck | `10014bb5` |
| `1001b46f` | `1001b32b` | `UNCONDITIONAL_CALL` | CatchIt | `1001b32b` |

## Callers

| From | Function |
| --- | --- |
| `1001b7b4` | FindHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b399` | `8b ff` | `MOV EDI,EDI` |
| `1001b39b` | `55` | `PUSH EBP` |
| `1001b39c` | `8b ec` | `MOV EBP,ESP` |
| `1001b39e` | `51` | `PUSH ECX` |
| `1001b39f` | `51` | `PUSH ECX` |
| `1001b3a0` | `56` | `PUSH ESI` |
| `1001b3a1` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001b3a4` | `81 3e 03 00 00 80` | `CMP dword ptr [ESI],0x80000003` |
| `1001b3aa` | `0f 84 da 00 00 00` | `JZ 0x1001b48a` |
| `1001b3b0` | `57` | `PUSH EDI` |
| `1001b3b1` | `e8 20 c0 ff ff` | `CALL 0x100173d6` |
| `1001b3b6` | `83 b8 80 00 00 00 00` | `CMP dword ptr [EAX + 0x80],0x0` |
| `1001b3bd` | `74 3f` | `JZ 0x1001b3fe` |
| `1001b3bf` | `e8 12 c0 ff ff` | `CALL 0x100173d6` |
| `1001b3c4` | `8d b8 80 00 00 00` | `LEA EDI,[EAX + 0x80]` |
| `1001b3ca` | `e8 b2 bd ff ff` | `CALL 0x10017181` |
| `1001b3cf` | `39 07` | `CMP dword ptr [EDI],EAX` |
| `1001b3d1` | `74 2b` | `JZ 0x1001b3fe` |
| `1001b3d3` | `81 3e 4d 4f 43 e0` | `CMP dword ptr [ESI],0xe0434f4d` |
| `1001b3d9` | `74 23` | `JZ 0x1001b3fe` |
| `1001b3db` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001b3de` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b3e1` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001b3e4` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b3e7` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b3ea` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b3ed` | `56` | `PUSH ESI` |
| `1001b3ee` | `e8 4c 96 ff ff` | `CALL 0x10014a3f` |
| `1001b3f3` | `83 c4 1c` | `ADD ESP,0x1c` |
| `1001b3f6` | `85 c0` | `TEST EAX,EAX` |
| `1001b3f8` | `0f 85 8b 00 00 00` | `JNZ 0x1001b489` |
| `1001b3fe` | `8b 7d 18` | `MOV EDI,dword ptr [EBP + 0x18]` |
| `1001b401` | `83 7f 0c 00` | `CMP dword ptr [EDI + 0xc],0x0` |
| `1001b405` | `75 05` | `JNZ 0x1001b40c` |
| `1001b407` | `e8 ed e0 ff ff` | `CALL 0x100194f9` |
| `1001b40c` | `8b 75 1c` | `MOV ESI,dword ptr [EBP + 0x1c]` |
| `1001b40f` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001b412` | `50` | `PUSH EAX` |
| `1001b413` | `8d 45 fc` | `LEA EAX,[EBP + -0x4]` |
| `1001b416` | `50` | `PUSH EAX` |
| `1001b417` | `56` | `PUSH ESI` |
| `1001b418` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b41b` | `57` | `PUSH EDI` |
| `1001b41c` | `e8 94 97 ff ff` | `CALL 0x10014bb5` |
| `1001b421` | `8b f8` | `MOV EDI,EAX` |
| `1001b423` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1001b426` | `83 c4 14` | `ADD ESP,0x14` |
| `1001b429` | `3b 45 f8` | `CMP EAX,dword ptr [EBP + -0x8]` |
| `1001b42c` | `73 5b` | `JNC 0x1001b489` |
| `1001b42e` | `53` | `PUSH EBX` |
| `1001b42f` | `3b 37` | `CMP ESI,dword ptr [EDI]` |
| `1001b431` | `7c 47` | `JL 0x1001b47a` |
| `1001b433` | `3b 77 04` | `CMP ESI,dword ptr [EDI + 0x4]` |
| `1001b436` | `7f 42` | `JG 0x1001b47a` |
| `1001b438` | `8b 47 0c` | `MOV EAX,dword ptr [EDI + 0xc]` |
| `1001b43b` | `8b 4f 10` | `MOV ECX,dword ptr [EDI + 0x10]` |
| `1001b43e` | `c1 e0 04` | `SHL EAX,0x4` |
| `1001b441` | `03 c1` | `ADD EAX,ECX` |
| `1001b443` | `8b 48 f4` | `MOV ECX,dword ptr [EAX + -0xc]` |
| `1001b446` | `85 c9` | `TEST ECX,ECX` |
| `1001b448` | `74 06` | `JZ 0x1001b450` |
| `1001b44a` | `80 79 08 00` | `CMP byte ptr [ECX + 0x8],0x0` |
| `1001b44e` | `75 2a` | `JNZ 0x1001b47a` |
| `1001b450` | `8d 58 f0` | `LEA EBX,[EAX + -0x10]` |
| `1001b453` | `f6 03 40` | `TEST byte ptr [EBX],0x40` |
| `1001b456` | `75 22` | `JNZ 0x1001b47a` |
| `1001b458` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001b45b` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001b45e` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b461` | `6a 00` | `PUSH 0x0` |
| `1001b463` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001b466` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b469` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b46c` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001b46f` | `e8 b7 fe ff ff` | `CALL 0x1001b32b` |
| `1001b474` | `8b 75 1c` | `MOV ESI,dword ptr [EBP + 0x1c]` |
| `1001b477` | `83 c4 1c` | `ADD ESP,0x1c` |
| `1001b47a` | `ff 45 fc` | `INC dword ptr [EBP + -0x4]` |
| `1001b47d` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1001b480` | `83 c7 14` | `ADD EDI,0x14` |
| `1001b483` | `3b 45 f8` | `CMP EAX,dword ptr [EBP + -0x8]` |
| `1001b486` | `72 a7` | `JC 0x1001b42f` |
| `1001b488` | `5b` | `POP EBX` |
| `1001b489` | `5f` | `POP EDI` |
| `1001b48a` | `5e` | `POP ESI` |
| `1001b48b` | `c9` | `LEAVE` |
| `1001b48c` | `c3` | `RET` |
