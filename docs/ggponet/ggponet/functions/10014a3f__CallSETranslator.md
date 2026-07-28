# 10014a3f `_CallSETranslator`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014a3f |
| `name` | _CallSETranslator |
| `namespace` | Global |
| `signature` | int __cdecl _CallSETranslator(EHExceptionRecord * param_1, EHRegistrationNode * param_2, void * param_3, void * param_4, _s_FuncInfo * param_5, int param_6, EHRegistrationNode * param_7) |
| `size_bytes` | 215 |
| `stack_frame_size` | 92 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?_CallSETranslator@@YAHPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAX2PBU_s_FuncInfo@@H1@Z, _CallSETranslator |

## Decompiled C

```c

/* Library Function - Single Match
    int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
   *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl
_CallSETranslator(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7)

{
  _ptiddata p_Var1;
  int local_3c;
  EHExceptionRecord *local_38;
  void *local_34;
  code *local_30;
  undefined4 *local_2c;
  code *local_28;
  uint local_24;
  _s_FuncInfo *local_20;
  EHRegistrationNode *local_1c;
  int local_18;
  EHRegistrationNode *local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffc0;
  if (param_1 == (EHExceptionRecord *)0x123) {
    *(undefined4 *)param_2 = 0x10014aea;
    local_3c = 1;
  }
  else {
    local_28 = TranslatorGuardHandler;
    local_24 = DAT_10037490 ^ (uint)&local_2c;
    local_20 = param_5;
    local_1c = param_2;
    local_18 = param_6;
    local_14 = param_7;
    local_8 = 0;
    local_2c = ExceptionList;
    ExceptionList = &local_2c;
    local_38 = param_1;
    local_34 = param_3;
    p_Var1 = __getptd();
    local_30 = p_Var1->_translator;
    (*local_30)(*(undefined4 *)param_1,&local_38);
    local_3c = 0;
    if (local_8 != 0) {
      *local_2c = *(undefined4 *)ExceptionList;
    }
    ExceptionList = local_2c;
  }
  return local_3c;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014aca` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |

## Callers

| From | Function |
| --- | --- |
| `1001b3ee` | FindHandlerForForeignException |
| `10014b99` | TranslatorGuardHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10014a67` | `10014b16` | `DATA` | ?TranslatorGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUTranslatorGuardRN@@PAX2@Z, TranslatorGuardHandler |
| `10014a6e` | `10037490` | `READ` | DAT_10037490 |
| `10014aa5` | `ffdff000` | `READ` | ExceptionList |
| `10014ab1` | `ffdff000` | `WRITE` | ExceptionList |
| `10014af0` | `ffdff000` | `READ` | ExceptionList |
| `10014afe` | `ffdff000` | `WRITE` | ExceptionList |
| `10014b0a` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014a3f` | `8b ff` | `MOV EDI,EDI` |
| `10014a41` | `55` | `PUSH EBP` |
| `10014a42` | `8b ec` | `MOV EBP,ESP` |
| `10014a44` | `83 ec 38` | `SUB ESP,0x38` |
| `10014a47` | `53` | `PUSH EBX` |
| `10014a48` | `81 7d 08 23 01 00 00` | `CMP dword ptr [EBP + 0x8],0x123` |
| `10014a4f` | `75 12` | `JNZ 0x10014a63` |
| `10014a51` | `b8 ea 4a 01 10` | `MOV EAX,0x10014aea` |
| `10014a56` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10014a59` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `10014a5b` | `33 c0` | `XOR EAX,EAX` |
| `10014a5d` | `40` | `INC EAX` |
| `10014a5e` | `e9 b0 00 00 00` | `JMP 0x10014b13` |
| `10014a63` | `83 65 d8 00` | `AND dword ptr [EBP + -0x28],0x0` |
| `10014a67` | `c7 45 dc 16 4b 01 10` | `MOV dword ptr [EBP + -0x24],0x10014b16` |
| `10014a6e` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10014a73` | `8d 4d d8` | `LEA ECX,[EBP + -0x28]` |
| `10014a76` | `33 c1` | `XOR EAX,ECX` |
| `10014a78` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `10014a7b` | `8b 45 18` | `MOV EAX,dword ptr [EBP + 0x18]` |
| `10014a7e` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10014a81` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014a84` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `10014a87` | `8b 45 1c` | `MOV EAX,dword ptr [EBP + 0x1c]` |
| `10014a8a` | `89 45 ec` | `MOV dword ptr [EBP + -0x14],EAX` |
| `10014a8d` | `8b 45 20` | `MOV EAX,dword ptr [EBP + 0x20]` |
| `10014a90` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `10014a93` | `83 65 f4 00` | `AND dword ptr [EBP + -0xc],0x0` |
| `10014a97` | `83 65 f8 00` | `AND dword ptr [EBP + -0x8],0x0` |
| `10014a9b` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `10014a9f` | `89 65 f4` | `MOV dword ptr [EBP + -0xc],ESP` |
| `10014aa2` | `89 6d f8` | `MOV dword ptr [EBP + -0x8],EBP` |
| `10014aa5` | `64 a1 00 00 00 00` | `MOV EAX,FS:[0x0]` |
| `10014aab` | `89 45 d8` | `MOV dword ptr [EBP + -0x28],EAX` |
| `10014aae` | `8d 45 d8` | `LEA EAX,[EBP + -0x28]` |
| `10014ab1` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014ab7` | `c7 45 c8 01 00 00 00` | `MOV dword ptr [EBP + -0x38],0x1` |
| `10014abe` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014ac1` | `89 45 cc` | `MOV dword ptr [EBP + -0x34],EAX` |
| `10014ac4` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10014ac7` | `89 45 d0` | `MOV dword ptr [EBP + -0x30],EAX` |
| `10014aca` | `e8 07 29 00 00` | `CALL 0x100173d6` |
| `10014acf` | `8b 80 80 00 00 00` | `MOV EAX,dword ptr [EAX + 0x80]` |
| `10014ad5` | `89 45 d4` | `MOV dword ptr [EBP + -0x2c],EAX` |
| `10014ad8` | `8d 45 cc` | `LEA EAX,[EBP + -0x34]` |
| `10014adb` | `50` | `PUSH EAX` |
| `10014adc` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014adf` | `ff 30` | `PUSH dword ptr [EAX]` |
| `10014ae1` | `ff 55 d4` | `CALL dword ptr [EBP + -0x2c]` |
| `10014ae4` | `59` | `POP ECX` |
| `10014ae5` | `59` | `POP ECX` |
| `10014ae6` | `83 65 c8 00` | `AND dword ptr [EBP + -0x38],0x0` |
| `10014aea` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10014aee` | `74 17` | `JZ 0x10014b07` |
| `10014af0` | `64 8b 1d 00 00 00 00` | `MOV EBX,dword ptr FS:[0x0]` |
| `10014af7` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `10014af9` | `8b 5d d8` | `MOV EBX,dword ptr [EBP + -0x28]` |
| `10014afc` | `89 03` | `MOV dword ptr [EBX],EAX` |
| `10014afe` | `64 89 1d 00 00 00 00` | `MOV dword ptr FS:[0x0],EBX` |
| `10014b05` | `eb 09` | `JMP 0x10014b10` |
| `10014b07` | `8b 45 d8` | `MOV EAX,dword ptr [EBP + -0x28]` |
| `10014b0a` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014b10` | `8b 45 c8` | `MOV EAX,dword ptr [EBP + -0x38]` |
| `10014b13` | `5b` | `POP EBX` |
| `10014b14` | `c9` | `LEAVE` |
| `10014b15` | `c3` | `RET` |
