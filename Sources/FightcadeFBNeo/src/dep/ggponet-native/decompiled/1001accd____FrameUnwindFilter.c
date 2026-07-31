
/* Library Function - Single Match
    ___FrameUnwindFilter
   
   Library: Visual Studio 2008 Release */

undefined4 ___FrameUnwindFilter(undefined4 *param_1)

{
  _ptiddata p_Var1;
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 == -0x1fbcb0b3) {
    p_Var1 = __getptd();
    if (0 < p_Var1->_ProcessingThrow) {
      p_Var1 = __getptd();
      p_Var1->_ProcessingThrow = p_Var1->_ProcessingThrow + -1;
    }
  }
  else if (*(int *)*param_1 == -0x1f928c9d) {
    p_Var1 = __getptd();
    p_Var1->_ProcessingThrow = 0;
    terminate();
    return extraout_EAX;
  }
  return 0;
}
