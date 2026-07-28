
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
