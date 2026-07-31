
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___report_gsfailure(void)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 unaff_retaddr;
  UINT uExitCode;
  undefined4 local_32c;
  undefined4 local_328;
  
  _DAT_10038ba0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10038ba4 = &stack0x00000004;
  _DAT_10038ae0 = 0x10001;
  _DAT_10038a88 = 0xc0000409;
  _DAT_10038a8c = 1;
  local_32c = DAT_10037490;
  local_328 = DAT_10037494;
  _DAT_10038a94 = unaff_retaddr;
  _DAT_10038b6c = in_GS;
  _DAT_10038b70 = in_FS;
  _DAT_10038b74 = in_ES;
  _DAT_10038b78 = in_DS;
  _DAT_10038b7c = unaff_EDI;
  _DAT_10038b80 = unaff_ESI;
  _DAT_10038b84 = unaff_EBX;
  _DAT_10038b88 = in_EDX;
  _DAT_10038b8c = in_ECX;
  _DAT_10038b90 = in_EAX;
  _DAT_10038b94 = unaff_EBP;
  DAT_10038b98 = unaff_retaddr;
  _DAT_10038b9c = in_CS;
  _DAT_10038ba8 = in_SS;
  DAT_10038ad8 = IsDebuggerPresent();
  FUN_10017107(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1002f024);
  if (DAT_10038ad8 == 0) {
    FUN_10017107(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}
