# 1001b7f1 `___InternalCxxFrameHandler`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b7f1 |
| `name` | ___InternalCxxFrameHandler |
| `namespace` | Global |
| `signature` | undefined ___InternalCxxFrameHandler(void) |
| `size_bytes` | 230 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___InternalCxxFrameHandler |

## Decompiled C

```c

/* Library Function - Single Match
    ___InternalCxxFrameHandler
   
   Library: Visual Studio 2008 Release */

undefined4
___InternalCxxFrameHandler
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,uchar param_8)

{
  _ptiddata p_Var1;
  undefined4 uVar2;
  
  p_Var1 = __getptd();
  if ((((*(int *)((p_Var1->_setloc_data)._cacheout + 0x27) != 0) || (*(int *)param_1 == -0x1f928c9d)
       ) || (*(int *)param_1 == -0x7fffffda)) ||
     (((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930522 ||
      ((param_5->EHFlags & 1) == 0)))) {
    if (((byte)param_1[4] & 0x66) == 0) {
      if ((param_5->nTryBlocks != 0) ||
         ((0x19930520 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff) &&
          (param_5->pESTypeList != (ESTypeList *)0x0)))) {
        if ((*(int *)param_1 == -0x1f928c9d) &&
           (((2 < *(uint *)(param_1 + 0x10) && (0x19930522 < *(uint *)(param_1 + 0x14))) &&
            (*(code **)(*(int *)(param_1 + 0x1c) + 8) != (code *)0x0)))) {
          uVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 8))
                            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
          return uVar2;
        }
        FindHandler(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
      }
    }
    else if ((param_5->maxState != 0) && (param_6 == 0)) {
      ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
    }
  }
  return 1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b7f9` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001b85b` | `1001ad16` | `UNCONDITIONAL_CALL` | ___FrameUnwindToState | `1001ad16` |
| `1001b8c7` | `1001b48d` | `UNCONDITIONAL_CALL` | FindHandler | `1001b48d` |

## Callers

| From | Function |
| --- | --- |
| `100149f7` | FID_conflict:___CxxFrameHandler3 |
| `10014a34` | CatchGuardHandler |
| `10014b6a` | TranslatorGuardHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b7f1` | `8b ff` | `MOV EDI,EDI` |
| `1001b7f3` | `55` | `PUSH EBP` |
| `1001b7f4` | `8b ec` | `MOV EBP,ESP` |
| `1001b7f6` | `53` | `PUSH EBX` |
| `1001b7f7` | `56` | `PUSH ESI` |
| `1001b7f8` | `57` | `PUSH EDI` |
| `1001b7f9` | `e8 d8 bb ff ff` | `CALL 0x100173d6` |
| `1001b7fe` | `83 b8 0c 02 00 00 00` | `CMP dword ptr [EAX + 0x20c],0x0` |
| `1001b805` | `8b 45 18` | `MOV EAX,dword ptr [EBP + 0x18]` |
| `1001b808` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001b80b` | `bf 63 73 6d e0` | `MOV EDI,0xe06d7363` |
| `1001b810` | `be ff ff ff 1f` | `MOV ESI,0x1fffffff` |
| `1001b815` | `bb 22 05 93 19` | `MOV EBX,0x19930522` |
| `1001b81a` | `75 20` | `JNZ 0x1001b83c` |
| `1001b81c` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `1001b81e` | `3b d7` | `CMP EDX,EDI` |
| `1001b820` | `74 1a` | `JZ 0x1001b83c` |
| `1001b822` | `81 fa 26 00 00 80` | `CMP EDX,0x80000026` |
| `1001b828` | `74 12` | `JZ 0x1001b83c` |
| `1001b82a` | `8b 10` | `MOV EDX,dword ptr [EAX]` |
| `1001b82c` | `23 d6` | `AND EDX,ESI` |
| `1001b82e` | `3b d3` | `CMP EDX,EBX` |
| `1001b830` | `72 0a` | `JC 0x1001b83c` |
| `1001b832` | `f6 40 20 01` | `TEST byte ptr [EAX + 0x20],0x1` |
| `1001b836` | `0f 85 93 00 00 00` | `JNZ 0x1001b8cf` |
| `1001b83c` | `f6 41 04 66` | `TEST byte ptr [ECX + 0x4],0x66` |
| `1001b840` | `74 23` | `JZ 0x1001b865` |
| `1001b842` | `83 78 04 00` | `CMP dword ptr [EAX + 0x4],0x0` |
| `1001b846` | `0f 84 83 00 00 00` | `JZ 0x1001b8cf` |
| `1001b84c` | `83 7d 1c 00` | `CMP dword ptr [EBP + 0x1c],0x0` |
| `1001b850` | `75 7d` | `JNZ 0x1001b8cf` |
| `1001b852` | `6a ff` | `PUSH -0x1` |
| `1001b854` | `50` | `PUSH EAX` |
| `1001b855` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b858` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b85b` | `e8 b6 f4 ff ff` | `CALL 0x1001ad16` |
| `1001b860` | `83 c4 10` | `ADD ESP,0x10` |
| `1001b863` | `eb 6a` | `JMP 0x1001b8cf` |
| `1001b865` | `83 78 0c 00` | `CMP dword ptr [EAX + 0xc],0x0` |
| `1001b869` | `75 12` | `JNZ 0x1001b87d` |
| `1001b86b` | `8b 10` | `MOV EDX,dword ptr [EAX]` |
| `1001b86d` | `23 d6` | `AND EDX,ESI` |
| `1001b86f` | `81 fa 21 05 93 19` | `CMP EDX,0x19930521` |
| `1001b875` | `72 58` | `JC 0x1001b8cf` |
| `1001b877` | `83 78 1c 00` | `CMP dword ptr [EAX + 0x1c],0x0` |
| `1001b87b` | `74 52` | `JZ 0x1001b8cf` |
| `1001b87d` | `39 39` | `CMP dword ptr [ECX],EDI` |
| `1001b87f` | `75 32` | `JNZ 0x1001b8b3` |
| `1001b881` | `83 79 10 03` | `CMP dword ptr [ECX + 0x10],0x3` |
| `1001b885` | `72 2c` | `JC 0x1001b8b3` |
| `1001b887` | `39 59 14` | `CMP dword ptr [ECX + 0x14],EBX` |
| `1001b88a` | `76 27` | `JBE 0x1001b8b3` |
| `1001b88c` | `8b 51 1c` | `MOV EDX,dword ptr [ECX + 0x1c]` |
| `1001b88f` | `8b 52 08` | `MOV EDX,dword ptr [EDX + 0x8]` |
| `1001b892` | `85 d2` | `TEST EDX,EDX` |
| `1001b894` | `74 1d` | `JZ 0x1001b8b3` |
| `1001b896` | `0f b6 75 24` | `MOVZX ESI,byte ptr [EBP + 0x24]` |
| `1001b89a` | `56` | `PUSH ESI` |
| `1001b89b` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b89e` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001b8a1` | `50` | `PUSH EAX` |
| `1001b8a2` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b8a5` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b8a8` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b8ab` | `51` | `PUSH ECX` |
| `1001b8ac` | `ff d2` | `CALL EDX` |
| `1001b8ae` | `83 c4 20` | `ADD ESP,0x20` |
| `1001b8b1` | `eb 1f` | `JMP 0x1001b8d2` |
| `1001b8b3` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001b8b6` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001b8b9` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001b8bc` | `50` | `PUSH EAX` |
| `1001b8bd` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b8c0` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b8c3` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b8c6` | `51` | `PUSH ECX` |
| `1001b8c7` | `e8 c1 fb ff ff` | `CALL 0x1001b48d` |
| `1001b8cc` | `83 c4 20` | `ADD ESP,0x20` |
| `1001b8cf` | `33 c0` | `XOR EAX,EAX` |
| `1001b8d1` | `40` | `INC EAX` |
| `1001b8d2` | `5f` | `POP EDI` |
| `1001b8d3` | `5e` | `POP ESI` |
| `1001b8d4` | `5b` | `POP EBX` |
| `1001b8d5` | `5d` | `POP EBP` |
| `1001b8d6` | `c3` | `RET` |
