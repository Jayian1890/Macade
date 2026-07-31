# 1001b48d `FindHandler`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b48d |
| `name` | FindHandler |
| `namespace` | Global |
| `signature` | void __cdecl FindHandler(EHExceptionRecord * param_1, EHRegistrationNode * param_2, _CONTEXT * param_3, void * param_4, _s_FuncInfo * param_5, uchar param_6, int param_7, EHRegistrationNode * param_8) |
| `size_bytes` | 839 |
| `stack_frame_size` | 84 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?FindHandler@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@EH1@Z, FindHandler |

## Decompiled C

```c

/* Library Function - Single Match
    void __cdecl FindHandler(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,unsigned char,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2008 Release */

void __cdecl
FindHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
           _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  uchar uVar1;
  bool bVar2;
  _ptiddata p_Var3;
  int iVar4;
  _s_TryBlockMapEntry *p_Var5;
  EHRegistrationNode *unaff_EBX;
  int iVar6;
  int *piVar7;
  int unaff_ESI;
  _s_FuncInfo *p_Var8;
  _s_TryBlockMapEntry *unaff_EDI;
  EHRegistrationNode *pEVar9;
  bad_exception in_stack_ffffffd0;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  HandlerType *local_10;
  int local_c;
  char local_5;
  
  local_5 = '\0';
  if (param_5->maxState < 0x81) {
    local_c = (int)(char)param_2[8];
  }
  else {
    local_c = *(int *)(param_2 + 8);
  }
  if ((local_c < -1) || (param_5->maxState <= local_c)) {
    _inconsistency();
  }
  p_Var8 = (_s_FuncInfo *)param_1;
  if (*(int *)param_1 == -0x1f928c9d) {
    if (((*(int *)(param_1 + 0x10) == 3) &&
        (((iVar4 = *(int *)(param_1 + 0x14), iVar4 == 0x19930520 || (iVar4 == 0x19930521)) ||
         (iVar4 == 0x19930522)))) && (*(int *)(param_1 + 0x1c) == 0)) {
      p_Var3 = __getptd();
      if (p_Var3->_curexception == (void *)0x0) {
        return;
      }
      p_Var3 = __getptd();
      param_1 = p_Var3->_curexception;
      p_Var3 = __getptd();
      param_3 = p_Var3->_curcontext;
      iVar4 = _ValidateRead(param_1,1);
      if (iVar4 == 0) {
        _inconsistency();
      }
      if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
          ((iVar4 = *(int *)(param_1 + 0x14), iVar4 == 0x19930520 ||
           ((iVar4 == 0x19930521 || (iVar4 == 0x19930522)))))) && (*(int *)(param_1 + 0x1c) == 0)) {
        _inconsistency();
      }
      p_Var3 = __getptd();
      if (p_Var3->_curexcspec != (void *)0x0) {
        p_Var3 = __getptd();
        piVar7 = p_Var3->_curexcspec;
        p_Var3 = __getptd();
        iVar4 = 0;
        p_Var3->_curexcspec = (void *)0x0;
        uVar1 = IsInExceptionSpec(param_1,(_s_ESTypeList *)unaff_EDI);
        if (uVar1 == '\0') {
          iVar6 = 0;
          if (0 < *piVar7) {
            do {
              bVar2 = type_info::operator==
                                (*(type_info **)(iVar6 + 4 + piVar7[1]),
                                 (type_info *)&std::bad_exception::RTTI_Type_Descriptor);
              if (bVar2) goto LAB_1001b5ce;
              iVar4 = iVar4 + 1;
              iVar6 = iVar6 + 0x10;
            } while (iVar4 < *piVar7);
          }
          goto LAB_1001b5c9;
        }
      }
    }
    p_Var8 = (_s_FuncInfo *)param_1;
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       ((iVar4 = *(int *)(param_1 + 0x14), iVar4 == 0x19930520 ||
        ((iVar4 == 0x19930521 || (iVar4 == 0x19930522)))))) {
      if (param_5->nTryBlocks != 0) {
        p_Var5 = _GetRangeOfTrysToCheck(param_5,param_7,local_c,&local_14,&local_20);
        for (; local_14 < local_20; local_14 = local_14 + 1) {
          if ((p_Var5->tryLow <= local_c) && (local_c <= p_Var5->tryHigh)) {
            local_10 = p_Var5->pHandlerArray;
            for (local_1c = p_Var5->nCatches; 0 < local_1c; local_1c = local_1c + -1) {
              piVar7 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
              for (local_18 = *piVar7; 0 < local_18; local_18 = local_18 + -1) {
                piVar7 = piVar7 + 1;
                p_Var8 = (_s_FuncInfo *)*piVar7;
                iVar4 = ___TypeMatch(local_10,p_Var8,*(undefined4 *)(param_1 + 0x1c));
                if (iVar4 != 0) {
                  local_5 = '\x01';
                  CatchIt(param_1,(EHRegistrationNode *)param_3,param_4,param_5,p_Var8,
                          (_s_HandlerType *)param_7,(_s_CatchableType *)param_8,unaff_EDI,unaff_ESI,
                          unaff_EBX,(uchar)in_stack_ffffffd0);
                  goto LAB_1001b6e6;
                }
              }
              local_10 = local_10 + 1;
            }
          }
LAB_1001b6e6:
          p_Var5 = p_Var5 + 1;
        }
      }
      if (param_6 != '\0') {
        ___DestructExceptionObject(param_1,1);
      }
      if ((((local_5 != '\0') || ((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930521)) ||
          (param_5->pESTypeList == (ESTypeList *)0x0)) ||
         (uVar1 = IsInExceptionSpec(param_1,(_s_ESTypeList *)unaff_EDI), uVar1 != '\0'))
      goto LAB_1001b7bc;
      __getptd();
      __getptd();
      p_Var3 = __getptd();
      p_Var3->_curexception = param_1;
      p_Var3 = __getptd();
      p_Var3->_curcontext = param_3;
      pEVar9 = param_8;
      if (param_8 == (EHRegistrationNode *)0x0) {
        pEVar9 = param_2;
      }
      _UnwindNestedFrames(pEVar9,param_1);
      ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
      FUN_1001af35(param_5->pESTypeList);
      p_Var8 = param_5;
    }
  }
  if (param_5->nTryBlocks != 0) {
    if (param_6 != '\0') {
LAB_1001b5c9:
      terminate();
LAB_1001b5ce:
      ___DestructExceptionObject(param_1,1);
      std::bad_exception::bad_exception((bad_exception *)&stack0xffffffd0,"bad exception");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&stack0xffffffd0,&DAT_10034174);
    }
    FindHandlerForForeignException
              ((EHExceptionRecord *)p_Var8,param_2,param_3,param_4,param_5,local_c,param_7,param_8);
  }
LAB_1001b7bc:
  p_Var3 = __getptd();
  if (p_Var3->_curexcspec != (void *)0x0) {
    _inconsistency();
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b4c1` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001b508` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b51a` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b528` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b539` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b544` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001b56e` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001b573` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b581` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b58c` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b59c` | `1001aeba` | `UNCONDITIONAL_CALL` | IsInExceptionSpec | `1001aeba` |
| `1001b5b8` | `100118b1` | `UNCONDITIONAL_CALL` | type_info::operator== | `100118b1` |
| `1001b5c9` | `100194ad` | `UNCONDITIONAL_CALL` | terminate | `100194ad` |
| `1001b5d3` | `1001ae3c` | `UNCONDITIONAL_CALL` | ___DestructExceptionObject | `1001ae3c` |
| `1001b5e2` | `1001ac1e` | `UNCONDITIONAL_CALL` | std::bad_exception::bad_exception | `1001ac1e` |
| `1001b5f0` | `100148fd` | `UNCONDITIONAL_CALL` | __CxxThrowException@8 | `100148fd` |
| `1001b644` | `10014bb5` | `UNCONDITIONAL_CALL` | _GetRangeOfTrysToCheck | `10014bb5` |
| `1001b698` | `1001ac6e` | `UNCONDITIONAL_CALL` | ___TypeMatch | `1001ac6e` |
| `1001b6db` | `1001b32b` | `UNCONDITIONAL_CALL` | CatchIt | `1001b32b` |
| `1001b6fd` | `1001ae3c` | `UNCONDITIONAL_CALL` | ___DestructExceptionObject | `1001ae3c` |
| `1001b72c` | `1001aeba` | `UNCONDITIONAL_CALL` | IsInExceptionSpec | `1001aeba` |
| `1001b73a` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b73f` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b744` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b74f` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b76c` | `10014982` | `UNCONDITIONAL_CALL` | _UnwindNestedFrames | `10014982` |
| `1001b77d` | `1001ad16` | `UNCONDITIONAL_CALL` | ___FrameUnwindToState | `1001ad16` |
| `1001b788` | `1001af35` | `UNCONDITIONAL_CALL` | FUN_1001af35 | `1001af35` |
| `1001b7b4` | `1001b399` | `UNCONDITIONAL_CALL` | FindHandlerForForeignException | `1001b399` |
| `1001b7bc` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b7ca` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |

## Callers

| From | Function |
| --- | --- |
| `1001b8c7` | ___InternalCxxFrameHandler |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1001b5da` | `1002f7d8` | `bad exception` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001b5b3` | `10037bfc` | `DATA` | std::bad_exception::RTTI_Type_Descriptor |
| `1001b5e7` | `10034174` | `DATA` | DAT_10034174 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b48d` | `8b ff` | `MOV EDI,EDI` |
| `1001b48f` | `55` | `PUSH EBP` |
| `1001b490` | `8b ec` | `MOV EBP,ESP` |
| `1001b492` | `83 ec 2c` | `SUB ESP,0x2c` |
| `1001b495` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001b498` | `53` | `PUSH EBX` |
| `1001b499` | `8b 5d 18` | `MOV EBX,dword ptr [EBP + 0x18]` |
| `1001b49c` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `1001b49f` | `3d 80 00 00 00` | `CMP EAX,0x80` |
| `1001b4a4` | `56` | `PUSH ESI` |
| `1001b4a5` | `57` | `PUSH EDI` |
| `1001b4a6` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `1001b4aa` | `7f 06` | `JG 0x1001b4b2` |
| `1001b4ac` | `0f be 49 08` | `MOVSX ECX,byte ptr [ECX + 0x8]` |
| `1001b4b0` | `eb 03` | `JMP 0x1001b4b5` |
| `1001b4b2` | `8b 49 08` | `MOV ECX,dword ptr [ECX + 0x8]` |
| `1001b4b5` | `83 f9 ff` | `CMP ECX,-0x1` |
| `1001b4b8` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1001b4bb` | `7c 04` | `JL 0x1001b4c1` |
| `1001b4bd` | `3b c8` | `CMP ECX,EAX` |
| `1001b4bf` | `7c 05` | `JL 0x1001b4c6` |
| `1001b4c1` | `e8 33 e0 ff ff` | `CALL 0x100194f9` |
| `1001b4c6` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001b4c9` | `bf 63 73 6d e0` | `MOV EDI,0xe06d7363` |
| `1001b4ce` | `39 3e` | `CMP dword ptr [ESI],EDI` |
| `1001b4d0` | `0f 85 ba 02 00 00` | `JNZ 0x1001b790` |
| `1001b4d6` | `83 7e 10 03` | `CMP dword ptr [ESI + 0x10],0x3` |
| `1001b4da` | `bb 20 05 93 19` | `MOV EBX,0x19930520` |
| `1001b4df` | `0f 85 18 01 00 00` | `JNZ 0x1001b5fd` |
| `1001b4e5` | `8b 46 14` | `MOV EAX,dword ptr [ESI + 0x14]` |
| `1001b4e8` | `3b c3` | `CMP EAX,EBX` |
| `1001b4ea` | `74 12` | `JZ 0x1001b4fe` |
| `1001b4ec` | `3d 21 05 93 19` | `CMP EAX,0x19930521` |
| `1001b4f1` | `74 0b` | `JZ 0x1001b4fe` |
| `1001b4f3` | `3d 22 05 93 19` | `CMP EAX,0x19930522` |
| `1001b4f8` | `0f 85 ff 00 00 00` | `JNZ 0x1001b5fd` |
| `1001b4fe` | `83 7e 1c 00` | `CMP dword ptr [ESI + 0x1c],0x0` |
| `1001b502` | `0f 85 f5 00 00 00` | `JNZ 0x1001b5fd` |
| `1001b508` | `e8 c9 be ff ff` | `CALL 0x100173d6` |
| `1001b50d` | `83 b8 88 00 00 00 00` | `CMP dword ptr [EAX + 0x88],0x0` |
| `1001b514` | `0f 84 b5 02 00 00` | `JZ 0x1001b7cf` |
| `1001b51a` | `e8 b7 be ff ff` | `CALL 0x100173d6` |
| `1001b51f` | `8b b0 88 00 00 00` | `MOV ESI,dword ptr [EAX + 0x88]` |
| `1001b525` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `1001b528` | `e8 a9 be ff ff` | `CALL 0x100173d6` |
| `1001b52d` | `8b 80 8c 00 00 00` | `MOV EAX,dword ptr [EAX + 0x8c]` |
| `1001b533` | `6a 01` | `PUSH 0x1` |
| `1001b535` | `56` | `PUSH ESI` |
| `1001b536` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `1001b539` | `e8 23 34 00 00` | `CALL 0x1001e961` |
| `1001b53e` | `59` | `POP ECX` |
| `1001b53f` | `59` | `POP ECX` |
| `1001b540` | `85 c0` | `TEST EAX,EAX` |
| `1001b542` | `75 05` | `JNZ 0x1001b549` |
| `1001b544` | `e8 b0 df ff ff` | `CALL 0x100194f9` |
| `1001b549` | `39 3e` | `CMP dword ptr [ESI],EDI` |
| `1001b54b` | `75 26` | `JNZ 0x1001b573` |
| `1001b54d` | `83 7e 10 03` | `CMP dword ptr [ESI + 0x10],0x3` |
| `1001b551` | `75 20` | `JNZ 0x1001b573` |
| `1001b553` | `8b 46 14` | `MOV EAX,dword ptr [ESI + 0x14]` |
| `1001b556` | `3b c3` | `CMP EAX,EBX` |
| `1001b558` | `74 0e` | `JZ 0x1001b568` |
| `1001b55a` | `3d 21 05 93 19` | `CMP EAX,0x19930521` |
| `1001b55f` | `74 07` | `JZ 0x1001b568` |
| `1001b561` | `3d 22 05 93 19` | `CMP EAX,0x19930522` |
| `1001b566` | `75 0b` | `JNZ 0x1001b573` |
| `1001b568` | `83 7e 1c 00` | `CMP dword ptr [ESI + 0x1c],0x0` |
| `1001b56c` | `75 05` | `JNZ 0x1001b573` |
| `1001b56e` | `e8 86 df ff ff` | `CALL 0x100194f9` |
| `1001b573` | `e8 5e be ff ff` | `CALL 0x100173d6` |
| `1001b578` | `83 b8 94 00 00 00 00` | `CMP dword ptr [EAX + 0x94],0x0` |
| `1001b57f` | `74 7c` | `JZ 0x1001b5fd` |
| `1001b581` | `e8 50 be ff ff` | `CALL 0x100173d6` |
| `1001b586` | `8b b8 94 00 00 00` | `MOV EDI,dword ptr [EAX + 0x94]` |
| `1001b58c` | `e8 45 be ff ff` | `CALL 0x100173d6` |
| `1001b591` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001b594` | `33 f6` | `XOR ESI,ESI` |
| `1001b596` | `89 b0 94 00 00 00` | `MOV dword ptr [EAX + 0x94],ESI` |
| `1001b59c` | `e8 19 f9 ff ff` | `CALL 0x1001aeba` |
| `1001b5a1` | `59` | `POP ECX` |
| `1001b5a2` | `84 c0` | `TEST AL,AL` |
| `1001b5a4` | `75 4f` | `JNZ 0x1001b5f5` |
| `1001b5a6` | `33 db` | `XOR EBX,EBX` |
| `1001b5a8` | `39 1f` | `CMP dword ptr [EDI],EBX` |
| `1001b5aa` | `7e 1d` | `JLE 0x1001b5c9` |
| `1001b5ac` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1001b5af` | `8b 4c 03 04` | `MOV ECX,dword ptr [EBX + EAX*0x1 + 0x4]` |
| `1001b5b3` | `68 fc 7b 03 10` | `PUSH 0x10037bfc` |
| `1001b5b8` | `e8 f4 62 ff ff` | `CALL 0x100118b1` |
| `1001b5bd` | `84 c0` | `TEST AL,AL` |
| `1001b5bf` | `75 0d` | `JNZ 0x1001b5ce` |
| `1001b5c1` | `46` | `INC ESI` |
| `1001b5c2` | `83 c3 10` | `ADD EBX,0x10` |
| `1001b5c5` | `3b 37` | `CMP ESI,dword ptr [EDI]` |
| `1001b5c7` | `7c e3` | `JL 0x1001b5ac` |
| `1001b5c9` | `e8 df de ff ff` | `CALL 0x100194ad` |
| `1001b5ce` | `6a 01` | `PUSH 0x1` |
| `1001b5d0` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001b5d3` | `e8 64 f8 ff ff` | `CALL 0x1001ae3c` |
| `1001b5d8` | `59` | `POP ECX` |
| `1001b5d9` | `59` | `POP ECX` |
| `1001b5da` | `68 d8 f7 02 10` | `PUSH 0x1002f7d8` |
| `1001b5df` | `8d 4d d4` | `LEA ECX,[EBP + -0x2c]` |
| `1001b5e2` | `e8 37 f6 ff ff` | `CALL 0x1001ac1e` |
| `1001b5e7` | `68 74 41 03 10` | `PUSH 0x10034174` |
| `1001b5ec` | `8d 45 d4` | `LEA EAX,[EBP + -0x2c]` |
| `1001b5ef` | `50` | `PUSH EAX` |
| `1001b5f0` | `e8 08 93 ff ff` | `CALL 0x100148fd` |
| `1001b5f5` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001b5f8` | `bf 63 73 6d e0` | `MOV EDI,0xe06d7363` |
| `1001b5fd` | `39 3e` | `CMP dword ptr [ESI],EDI` |
| `1001b5ff` | `0f 85 88 01 00 00` | `JNZ 0x1001b78d` |
| `1001b605` | `83 7e 10 03` | `CMP dword ptr [ESI + 0x10],0x3` |
| `1001b609` | `0f 85 7e 01 00 00` | `JNZ 0x1001b78d` |
| `1001b60f` | `8b 46 14` | `MOV EAX,dword ptr [ESI + 0x14]` |
| `1001b612` | `3b c3` | `CMP EAX,EBX` |
| `1001b614` | `74 12` | `JZ 0x1001b628` |
| `1001b616` | `3d 21 05 93 19` | `CMP EAX,0x19930521` |
| `1001b61b` | `74 0b` | `JZ 0x1001b628` |
| `1001b61d` | `3d 22 05 93 19` | `CMP EAX,0x19930522` |
| `1001b622` | `0f 85 65 01 00 00` | `JNZ 0x1001b78d` |
| `1001b628` | `8b 7d 18` | `MOV EDI,dword ptr [EBP + 0x18]` |
| `1001b62b` | `83 7f 0c 00` | `CMP dword ptr [EDI + 0xc],0x0` |
| `1001b62f` | `0f 86 bf 00 00 00` | `JBE 0x1001b6f4` |
| `1001b635` | `8d 45 e4` | `LEA EAX,[EBP + -0x1c]` |
| `1001b638` | `50` | `PUSH EAX` |
| `1001b639` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001b63c` | `50` | `PUSH EAX` |
| `1001b63d` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001b640` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b643` | `57` | `PUSH EDI` |
| `1001b644` | `e8 6c 95 ff ff` | `CALL 0x10014bb5` |
| `1001b649` | `83 c4 14` | `ADD ESP,0x14` |
| `1001b64c` | `8b f8` | `MOV EDI,EAX` |
| `1001b64e` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001b651` | `3b 45 e4` | `CMP EAX,dword ptr [EBP + -0x1c]` |
| `1001b654` | `0f 83 97 00 00 00` | `JNC 0x1001b6f1` |
| `1001b65a` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001b65d` | `39 07` | `CMP dword ptr [EDI],EAX` |
| `1001b65f` | `0f 8f 81 00 00 00` | `JG 0x1001b6e6` |
| `1001b665` | `3b 47 04` | `CMP EAX,dword ptr [EDI + 0x4]` |
| `1001b668` | `7f 7c` | `JG 0x1001b6e6` |
| `1001b66a` | `8b 47 10` | `MOV EAX,dword ptr [EDI + 0x10]` |
| `1001b66d` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1001b670` | `8b 47 0c` | `MOV EAX,dword ptr [EDI + 0xc]` |
| `1001b673` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1001b676` | `85 c0` | `TEST EAX,EAX` |
| `1001b678` | `7e 6c` | `JLE 0x1001b6e6` |
| `1001b67a` | `8b 46 1c` | `MOV EAX,dword ptr [ESI + 0x1c]` |
| `1001b67d` | `8b 40 0c` | `MOV EAX,dword ptr [EAX + 0xc]` |
| `1001b680` | `8d 58 04` | `LEA EBX,[EAX + 0x4]` |
| `1001b683` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001b685` | `89 45 ec` | `MOV dword ptr [EBP + -0x14],EAX` |
| `1001b688` | `85 c0` | `TEST EAX,EAX` |
| `1001b68a` | `7e 23` | `JLE 0x1001b6af` |
| `1001b68c` | `ff 76 1c` | `PUSH dword ptr [ESI + 0x1c]` |
| `1001b68f` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `1001b691` | `50` | `PUSH EAX` |
| `1001b692` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001b695` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001b698` | `e8 d1 f5 ff ff` | `CALL 0x1001ac6e` |
| `1001b69d` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001b6a0` | `85 c0` | `TEST EAX,EAX` |
| `1001b6a2` | `75 1a` | `JNZ 0x1001b6be` |
| `1001b6a4` | `ff 4d ec` | `DEC dword ptr [EBP + -0x14]` |
| `1001b6a7` | `83 c3 04` | `ADD EBX,0x4` |
| `1001b6aa` | `39 45 ec` | `CMP dword ptr [EBP + -0x14],EAX` |
| `1001b6ad` | `7f dd` | `JG 0x1001b68c` |
| `1001b6af` | `ff 4d e8` | `DEC dword ptr [EBP + -0x18]` |
| `1001b6b2` | `83 45 f4 10` | `ADD dword ptr [EBP + -0xc],0x10` |
| `1001b6b6` | `83 7d e8 00` | `CMP dword ptr [EBP + -0x18],0x0` |
| `1001b6ba` | `7f be` | `JG 0x1001b67a` |
| `1001b6bc` | `eb 28` | `JMP 0x1001b6e6` |
| `1001b6be` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001b6c1` | `8b 5d f4` | `MOV EBX,dword ptr [EBP + -0xc]` |
| `1001b6c4` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b6c7` | `c6 45 ff 01` | `MOV byte ptr [EBP + -0x1],0x1` |
| `1001b6cb` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `1001b6ce` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001b6d1` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b6d4` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b6d7` | `56` | `PUSH ESI` |
| `1001b6d8` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001b6db` | `e8 4b fc ff ff` | `CALL 0x1001b32b` |
| `1001b6e0` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001b6e3` | `83 c4 1c` | `ADD ESP,0x1c` |
| `1001b6e6` | `ff 45 f0` | `INC dword ptr [EBP + -0x10]` |
| `1001b6e9` | `83 c7 14` | `ADD EDI,0x14` |
| `1001b6ec` | `e9 5d ff ff ff` | `JMP 0x1001b64e` |
| `1001b6f1` | `8b 7d 18` | `MOV EDI,dword ptr [EBP + 0x18]` |
| `1001b6f4` | `80 7d 1c 00` | `CMP byte ptr [EBP + 0x1c],0x0` |
| `1001b6f8` | `74 0a` | `JZ 0x1001b704` |
| `1001b6fa` | `6a 01` | `PUSH 0x1` |
| `1001b6fc` | `56` | `PUSH ESI` |
| `1001b6fd` | `e8 3a f7 ff ff` | `CALL 0x1001ae3c` |
| `1001b702` | `59` | `POP ECX` |
| `1001b703` | `59` | `POP ECX` |
| `1001b704` | `80 7d ff 00` | `CMP byte ptr [EBP + -0x1],0x0` |
| `1001b708` | `0f 85 ae 00 00 00` | `JNZ 0x1001b7bc` |
| `1001b70e` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001b710` | `25 ff ff ff 1f` | `AND EAX,0x1fffffff` |
| `1001b715` | `3d 21 05 93 19` | `CMP EAX,0x19930521` |
| `1001b71a` | `0f 82 9c 00 00 00` | `JC 0x1001b7bc` |
| `1001b720` | `8b 7f 1c` | `MOV EDI,dword ptr [EDI + 0x1c]` |
| `1001b723` | `85 ff` | `TEST EDI,EDI` |
| `1001b725` | `0f 84 91 00 00 00` | `JZ 0x1001b7bc` |
| `1001b72b` | `56` | `PUSH ESI` |
| `1001b72c` | `e8 89 f7 ff ff` | `CALL 0x1001aeba` |
| `1001b731` | `59` | `POP ECX` |
| `1001b732` | `84 c0` | `TEST AL,AL` |
| `1001b734` | `0f 85 82 00 00 00` | `JNZ 0x1001b7bc` |
| `1001b73a` | `e8 97 bc ff ff` | `CALL 0x100173d6` |
| `1001b73f` | `e8 92 bc ff ff` | `CALL 0x100173d6` |
| `1001b744` | `e8 8d bc ff ff` | `CALL 0x100173d6` |
| `1001b749` | `89 b0 88 00 00 00` | `MOV dword ptr [EAX + 0x88],ESI` |
| `1001b74f` | `e8 82 bc ff ff` | `CALL 0x100173d6` |
| `1001b754` | `83 7d 24 00` | `CMP dword ptr [EBP + 0x24],0x0` |
| `1001b758` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001b75b` | `89 88 8c 00 00 00` | `MOV dword ptr [EAX + 0x8c],ECX` |
| `1001b761` | `56` | `PUSH ESI` |
| `1001b762` | `75 05` | `JNZ 0x1001b769` |
| `1001b764` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b767` | `eb 03` | `JMP 0x1001b76c` |
| `1001b769` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001b76c` | `e8 11 92 ff ff` | `CALL 0x10014982` |
| `1001b771` | `8b 75 18` | `MOV ESI,dword ptr [EBP + 0x18]` |
| `1001b774` | `6a ff` | `PUSH -0x1` |
| `1001b776` | `56` | `PUSH ESI` |
| `1001b777` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b77a` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b77d` | `e8 94 f5 ff ff` | `CALL 0x1001ad16` |
| `1001b782` | `83 c4 10` | `ADD ESP,0x10` |
| `1001b785` | `ff 76 1c` | `PUSH dword ptr [ESI + 0x1c]` |
| `1001b788` | `e8 a8 f7 ff ff` | `CALL 0x1001af35` |
| `1001b78d` | `8b 5d 18` | `MOV EBX,dword ptr [EBP + 0x18]` |
| `1001b790` | `83 7b 0c 00` | `CMP dword ptr [EBX + 0xc],0x0` |
| `1001b794` | `76 26` | `JBE 0x1001b7bc` |
| `1001b796` | `80 7d 1c 00` | `CMP byte ptr [EBP + 0x1c],0x0` |
| `1001b79a` | `0f 85 29 fe ff ff` | `JNZ 0x1001b5c9` |
| `1001b7a0` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001b7a3` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b7a6` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001b7a9` | `53` | `PUSH EBX` |
| `1001b7aa` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b7ad` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b7b0` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b7b3` | `56` | `PUSH ESI` |
| `1001b7b4` | `e8 e0 fb ff ff` | `CALL 0x1001b399` |
| `1001b7b9` | `83 c4 20` | `ADD ESP,0x20` |
| `1001b7bc` | `e8 15 bc ff ff` | `CALL 0x100173d6` |
| `1001b7c1` | `83 b8 94 00 00 00 00` | `CMP dword ptr [EAX + 0x94],0x0` |
| `1001b7c8` | `74 05` | `JZ 0x1001b7cf` |
| `1001b7ca` | `e8 2a dd ff ff` | `CALL 0x100194f9` |
| `1001b7cf` | `5f` | `POP EDI` |
| `1001b7d0` | `5e` | `POP ESI` |
| `1001b7d1` | `5b` | `POP EBX` |
| `1001b7d2` | `c9` | `LEAVE` |
| `1001b7d3` | `c3` | `RET` |
