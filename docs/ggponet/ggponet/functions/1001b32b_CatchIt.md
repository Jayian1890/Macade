# 1001b32b `CatchIt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b32b |
| `name` | CatchIt |
| `namespace` | Global |
| `signature` | void __cdecl CatchIt(EHExceptionRecord * param_1, EHRegistrationNode * param_2, _CONTEXT * param_3, void * param_4, _s_FuncInfo * param_5, _s_HandlerType * param_6, _s_CatchableType * param_7, _s_TryBlockMapEntry * param_8, int param_9, EHRegistrationNode * param_10, uchar param_11) |
| `size_bytes` | 110 |
| `stack_frame_size` | 45 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?CatchIt@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@PBU_s_HandlerType@@PBU_s_CatchableType@@PBU_s_TryBlockMapEntry@@H1E@Z, CatchIt |

## Decompiled C

```c

/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *,unsigned char)
   
   Library: Visual Studio 2008 Release */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10,uchar param_11)

{
  void *pvVar1;
  EHRegistrationNode *unaff_ESI;
  int unaff_EDI;
  EHRegistrationNode *pEVar2;
  
  if (param_5 != (_s_FuncInfo *)0x0) {
    ___BuildCatchObject(param_1);
  }
  if (param_7 == (_s_CatchableType *)0x0) {
    param_7 = (_s_CatchableType *)unaff_ESI;
  }
  _UnwindNestedFrames((EHRegistrationNode *)param_7,param_1);
  pEVar2 = unaff_ESI;
  ___FrameUnwindToState();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_EDI + 4) + 1;
  pvVar1 = CallCatchBlock(param_1,unaff_ESI,(_CONTEXT *)param_2,param_4,param_6,0x100,(ulong)pEVar2)
  ;
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,unaff_ESI);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b33e` | `1001b299` | `UNCONDITIONAL_CALL` | ___BuildCatchObject | `1001b299` |
| `1001b355` | `10014982` | `UNCONDITIONAL_CALL` | _UnwindNestedFrames | `10014982` |
| `1001b363` | `1001ad16` | `UNCONDITIONAL_CALL` | ___FrameUnwindToState | `1001ad16` |
| `1001b384` | `1001af7e` | `UNCONDITIONAL_CALL` | CallCatchBlock | `1001af7e` |
| `1001b392` | `10014949` | `UNCONDITIONAL_CALL` | _JumpToContinuation | `10014949` |

## Callers

| From | Function |
| --- | --- |
| `1001b6db` | FindHandler |
| `1001b46f` | FindHandlerForForeignException |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b32b` | `8b ff` | `MOV EDI,EDI` |
| `1001b32d` | `55` | `PUSH EBP` |
| `1001b32e` | `8b ec` | `MOV EBP,ESP` |
| `1001b330` | `83 7d 18 00` | `CMP dword ptr [EBP + 0x18],0x0` |
| `1001b334` | `74 10` | `JZ 0x1001b346` |
| `1001b336` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001b339` | `53` | `PUSH EBX` |
| `1001b33a` | `56` | `PUSH ESI` |
| `1001b33b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001b33e` | `e8 56 ff ff ff` | `CALL 0x1001b299` |
| `1001b343` | `83 c4 10` | `ADD ESP,0x10` |
| `1001b346` | `83 7d 20 00` | `CMP dword ptr [EBP + 0x20],0x0` |
| `1001b34a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001b34d` | `75 03` | `JNZ 0x1001b352` |
| `1001b34f` | `56` | `PUSH ESI` |
| `1001b350` | `eb 03` | `JMP 0x1001b355` |
| `1001b352` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b355` | `e8 28 96 ff ff` | `CALL 0x10014982` |
| `1001b35a` | `ff 37` | `PUSH dword ptr [EDI]` |
| `1001b35c` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b35f` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b362` | `56` | `PUSH ESI` |
| `1001b363` | `e8 ae f9 ff ff` | `CALL 0x1001ad16` |
| `1001b368` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1001b36b` | `68 00 01 00 00` | `PUSH 0x100` |
| `1001b370` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001b373` | `40` | `INC EAX` |
| `1001b374` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b377` | `89 46 08` | `MOV dword ptr [ESI + 0x8],EAX` |
| `1001b37a` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b37d` | `8b 4b 0c` | `MOV ECX,dword ptr [EBX + 0xc]` |
| `1001b380` | `56` | `PUSH ESI` |
| `1001b381` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001b384` | `e8 f5 fb ff ff` | `CALL 0x1001af7e` |
| `1001b389` | `83 c4 28` | `ADD ESP,0x28` |
| `1001b38c` | `85 c0` | `TEST EAX,EAX` |
| `1001b38e` | `74 07` | `JZ 0x1001b397` |
| `1001b390` | `56` | `PUSH ESI` |
| `1001b391` | `50` | `PUSH EAX` |
| `1001b392` | `e8 b2 95 ff ff` | `CALL 0x10014949` |
| `1001b397` | `5d` | `POP EBP` |
| `1001b398` | `c3` | `RET` |
