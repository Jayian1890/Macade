# 1001af7e `CallCatchBlock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001af7e |
| `name` | CallCatchBlock |
| `namespace` | Global |
| `signature` | void * __cdecl CallCatchBlock(EHExceptionRecord * param_1, EHRegistrationNode * param_2, _CONTEXT * param_3, _s_FuncInfo * param_4, void * param_5, int param_6, ulong param_7) |
| `size_bytes` | 172 |
| `stack_frame_size` | 96 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?CallCatchBlock@@YAPAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PBU_s_FuncInfo@@PAXHK@Z, CallCatchBlock |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void * __cdecl CallCatchBlock(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _CONTEXT *,struct _s_FuncInfo const *,void *,int,unsigned long)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void * __cdecl
CallCatchBlock(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
              _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  _ptiddata p_Var1;
  void *in_ECX;
  undefined1 local_40 [8];
  undefined4 local_38;
  void *local_34;
  void *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  void *local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_10034110;
  uStack_c = 0x1001af8a;
  local_38 = 0;
  local_28 = *(undefined4 *)(param_2 + -4);
  local_2c = __CreateFrameInfo(local_40,*(undefined4 *)(param_1 + 0x18));
  p_Var1 = __getptd();
  local_30 = p_Var1->_curexception;
  p_Var1 = __getptd();
  local_34 = p_Var1->_curcontext;
  p_Var1 = __getptd();
  p_Var1->_curexception = param_1;
  p_Var1 = __getptd();
  p_Var1->_curcontext = param_3;
  local_8 = (undefined *)0x1;
  local_20 = _CallCatchBlock2(param_2,param_4,in_ECX,(int)param_5,param_6);
  local_8 = (undefined *)0xfffffffe;
  FUN_1001b0a4();
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001af85` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001afa6` | `10014c2a` | `UNCONDITIONAL_CALL` | __CreateFrameInfo | `10014c2a` |
| `1001afb0` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001afbe` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001afcc` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001afd7` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001affd` | `10014ccf` | `UNCONDITIONAL_CALL` | _CallCatchBlock2 | `10014ccf` |
| `1001b08b` | `1001b0a4` | `UNCONDITIONAL_CALL` | FUN_1001b0a4 | `1001b0a4` |
| `1001b093` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001b384` | CatchIt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001af80` | `10034110` | `DATA` | DAT_10034110 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001af7e` | `6a 2c` | `PUSH 0x2c` |
| `1001af80` | `68 10 41 03 10` | `PUSH 0x10034110` |
| `1001af85` | `e8 72 bd ff ff` | `CALL 0x10016cfc` |
| `1001af8a` | `8b d9` | `MOV EBX,ECX` |
| `1001af8c` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001af8f` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001af92` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `1001af95` | `83 65 cc 00` | `AND dword ptr [EBP + -0x34],0x0` |
| `1001af99` | `8b 47 fc` | `MOV EAX,dword ptr [EDI + -0x4]` |
| `1001af9c` | `89 45 dc` | `MOV dword ptr [EBP + -0x24],EAX` |
| `1001af9f` | `ff 76 18` | `PUSH dword ptr [ESI + 0x18]` |
| `1001afa2` | `8d 45 c4` | `LEA EAX,[EBP + -0x3c]` |
| `1001afa5` | `50` | `PUSH EAX` |
| `1001afa6` | `e8 7f 9c ff ff` | `CALL 0x10014c2a` |
| `1001afab` | `59` | `POP ECX` |
| `1001afac` | `59` | `POP ECX` |
| `1001afad` | `89 45 d8` | `MOV dword ptr [EBP + -0x28],EAX` |
| `1001afb0` | `e8 21 c4 ff ff` | `CALL 0x100173d6` |
| `1001afb5` | `8b 80 88 00 00 00` | `MOV EAX,dword ptr [EAX + 0x88]` |
| `1001afbb` | `89 45 d4` | `MOV dword ptr [EBP + -0x2c],EAX` |
| `1001afbe` | `e8 13 c4 ff ff` | `CALL 0x100173d6` |
| `1001afc3` | `8b 80 8c 00 00 00` | `MOV EAX,dword ptr [EAX + 0x8c]` |
| `1001afc9` | `89 45 d0` | `MOV dword ptr [EBP + -0x30],EAX` |
| `1001afcc` | `e8 05 c4 ff ff` | `CALL 0x100173d6` |
| `1001afd1` | `89 b0 88 00 00 00` | `MOV dword ptr [EAX + 0x88],ESI` |
| `1001afd7` | `e8 fa c3 ff ff` | `CALL 0x100173d6` |
| `1001afdc` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001afdf` | `89 88 8c 00 00 00` | `MOV dword ptr [EAX + 0x8c],ECX` |
| `1001afe5` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001afe9` | `33 c0` | `XOR EAX,EAX` |
| `1001afeb` | `40` | `INC EAX` |
| `1001afec` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `1001afef` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001aff2` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001aff5` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001aff8` | `53` | `PUSH EBX` |
| `1001aff9` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001affc` | `57` | `PUSH EDI` |
| `1001affd` | `e8 cd 9c ff ff` | `CALL 0x10014ccf` |
| `1001b002` | `83 c4 14` | `ADD ESP,0x14` |
| `1001b005` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001b008` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001b00c` | `eb 6f` | `JMP 0x1001b07d` |
| `1001b07d` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001b084` | `c7 45 10 00 00 00 00` | `MOV dword ptr [EBP + 0x10],0x0` |
| `1001b08b` | `e8 14 00 00 00` | `CALL 0x1001b0a4` |
| `1001b090` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001b093` | `e8 a9 bc ff ff` | `CALL 0x10016d41` |
| `1001b098` | `c3` | `RET` |
