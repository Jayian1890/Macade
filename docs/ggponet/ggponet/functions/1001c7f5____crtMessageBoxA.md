# 1001c7f5 `___crtMessageBoxA`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c7f5 |
| `name` | ___crtMessageBoxA |
| `namespace` | Global |
| `signature` | int __cdecl ___crtMessageBoxA(LPCSTR _LpText, LPCSTR _LpCaption, UINT _UType) |
| `size_bytes` | 361 |
| `stack_frame_size` | 56 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtMessageBoxA |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 2008 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  undefined1 local_18 [8];
  byte local_10;
  undefined1 local_c [4];
  int local_8;
  
  iVar1 = __encoded_null();
  local_8 = 0;
  if (DAT_100393c4 == 0) {
    hModule = LoadLibraryA("USER32.DLL");
    if (hModule == (HMODULE)0x0) {
      return 0;
    }
    pFVar2 = GetProcAddress(hModule,"MessageBoxA");
    if (pFVar2 == (FARPROC)0x0) {
      return 0;
    }
    DAT_100393c4 = __encode_pointer(pFVar2);
    pFVar2 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_100393c8 = __encode_pointer(pFVar2);
    pFVar2 = GetProcAddress(hModule,"GetLastActivePopup");
    DAT_100393cc = __encode_pointer(pFVar2);
    pFVar2 = GetProcAddress(hModule,"GetUserObjectInformationA");
    DAT_100393d4 = __encode_pointer(pFVar2);
    if (DAT_100393d4 != 0) {
      pFVar2 = GetProcAddress(hModule,"GetProcessWindowStation");
      DAT_100393d0 = __encode_pointer(pFVar2);
    }
  }
  if ((DAT_100393d0 != iVar1) && (DAT_100393d4 != iVar1)) {
    pcVar3 = (code *)__decode_pointer(DAT_100393d0);
    pcVar4 = (code *)__decode_pointer(DAT_100393d4);
    if (((pcVar3 != (code *)0x0) && (pcVar4 != (code *)0x0)) &&
       (((iVar5 = (*pcVar3)(), iVar5 == 0 ||
         (iVar5 = (*pcVar4)(iVar5,1,local_18,0xc,local_c), iVar5 == 0)) || ((local_10 & 1) == 0))))
    {
      _UType = _UType | 0x200000;
      goto LAB_1001c937;
    }
  }
  if ((((DAT_100393c8 != iVar1) &&
       (pcVar3 = (code *)__decode_pointer(DAT_100393c8), pcVar3 != (code *)0x0)) &&
      (local_8 = (*pcVar3)(), local_8 != 0)) &&
     ((DAT_100393cc != iVar1 &&
      (pcVar3 = (code *)__decode_pointer(DAT_100393cc), pcVar3 != (code *)0x0)))) {
    local_8 = (*pcVar3)(local_8);
  }
LAB_1001c937:
  pcVar3 = (code *)__decode_pointer(DAT_100393c4);
  if (pcVar3 == (code *)0x0) {
    return 0;
  }
  iVar1 = (*pcVar3)(local_8,_LpText,_LpCaption,_UType);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c800` | `10017181` | `UNCONDITIONAL_CALL` | __encoded_null | `10017181` |
| `1001c81d` | `EXTERNAL:00000053` | `COMPUTED_CALL` | KERNEL32.DLL::LoadLibraryA | `` |
| `1001c839` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `1001c844` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `1001c856` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `1001c859` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `1001c86b` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `1001c86e` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `1001c880` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `1001c883` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `1001c898` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `1001c89b` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |
| `1001c8b8` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001c8c5` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001c908` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001c925` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001c93d` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |

## Callers

| From | Function |
| --- | --- |
| `10017056` | __NMSG_WRITE |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1001c818` | `1002f8d0` | `USER32.DLL` |
| `1001c833` | `1002f8c4` | `MessageBoxA` |
| `1001c849` | `1002f8b4` | `GetActiveWindow` |
| `1001c85e` | `1002f8a0` | `GetLastActivePopup` |
| `1001c873` | `1002f884` | `GetUserObjectInformationA` |
| `1001c892` | `1002f86c` | `GetProcessWindowStation` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c809` | `100393c4` | `READ` | DAT_100393c4 |
| `1001c81d` | `1002e104` | `READ` | PTR_LoadLibraryA_1002e104 |
| `1001c82d` | `1002e094` | `READ` | PTR_GetProcAddress_1002e094 |
| `1001c851` | `100393c4` | `WRITE` | DAT_100393c4 |
| `1001c866` | `100393c8` | `WRITE` | DAT_100393c8 |
| `1001c87b` | `100393cc` | `WRITE` | DAT_100393cc |
| `1001c889` | `100393d4` | `WRITE` | DAT_100393d4 |
| `1001c8a1` | `100393d0` | `WRITE` | DAT_100393d0 |
| `1001c8a6` | `100393d0` | `READ` | DAT_100393d0 |
| `1001c8af` | `100393d4` | `READ` | DAT_100393d4 |
| `1001c8bd` | `100393d4` | `READ` | DAT_100393d4 |
| `1001c8fe` | `100393c8` | `READ` | DAT_100393c8 |
| `1001c91b` | `100393cc` | `READ` | DAT_100393cc |
| `1001c937` | `100393c4` | `READ` | DAT_100393c4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c7f5` | `8b ff` | `MOV EDI,EDI` |
| `1001c7f7` | `55` | `PUSH EBP` |
| `1001c7f8` | `8b ec` | `MOV EBP,ESP` |
| `1001c7fa` | `83 ec 14` | `SUB ESP,0x14` |
| `1001c7fd` | `53` | `PUSH EBX` |
| `1001c7fe` | `56` | `PUSH ESI` |
| `1001c7ff` | `57` | `PUSH EDI` |
| `1001c800` | `e8 7c a9 ff ff` | `CALL 0x10017181` |
| `1001c805` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001c809` | `83 3d c4 93 03 10 00` | `CMP dword ptr [0x100393c4],0x0` |
| `1001c810` | `8b d8` | `MOV EBX,EAX` |
| `1001c812` | `0f 85 8e 00 00 00` | `JNZ 0x1001c8a6` |
| `1001c818` | `68 d0 f8 02 10` | `PUSH 0x1002f8d0` |
| `1001c81d` | `ff 15 04 e1 02 10` | `CALL dword ptr [0x1002e104]` |
| `1001c823` | `8b f8` | `MOV EDI,EAX` |
| `1001c825` | `85 ff` | `TEST EDI,EDI` |
| `1001c827` | `0f 84 2a 01 00 00` | `JZ 0x1001c957` |
| `1001c82d` | `8b 35 94 e0 02 10` | `MOV ESI,dword ptr [0x1002e094]` |
| `1001c833` | `68 c4 f8 02 10` | `PUSH 0x1002f8c4` |
| `1001c838` | `57` | `PUSH EDI` |
| `1001c839` | `ff d6` | `CALL ESI` |
| `1001c83b` | `85 c0` | `TEST EAX,EAX` |
| `1001c83d` | `0f 84 14 01 00 00` | `JZ 0x1001c957` |
| `1001c843` | `50` | `PUSH EAX` |
| `1001c844` | `e8 c6 a8 ff ff` | `CALL 0x1001710f` |
| `1001c849` | `c7 04 24 b4 f8 02 10` | `MOV dword ptr [ESP],0x1002f8b4` |
| `1001c850` | `57` | `PUSH EDI` |
| `1001c851` | `a3 c4 93 03 10` | `MOV [0x100393c4],EAX` |
| `1001c856` | `ff d6` | `CALL ESI` |
| `1001c858` | `50` | `PUSH EAX` |
| `1001c859` | `e8 b1 a8 ff ff` | `CALL 0x1001710f` |
| `1001c85e` | `c7 04 24 a0 f8 02 10` | `MOV dword ptr [ESP],0x1002f8a0` |
| `1001c865` | `57` | `PUSH EDI` |
| `1001c866` | `a3 c8 93 03 10` | `MOV [0x100393c8],EAX` |
| `1001c86b` | `ff d6` | `CALL ESI` |
| `1001c86d` | `50` | `PUSH EAX` |
| `1001c86e` | `e8 9c a8 ff ff` | `CALL 0x1001710f` |
| `1001c873` | `c7 04 24 84 f8 02 10` | `MOV dword ptr [ESP],0x1002f884` |
| `1001c87a` | `57` | `PUSH EDI` |
| `1001c87b` | `a3 cc 93 03 10` | `MOV [0x100393cc],EAX` |
| `1001c880` | `ff d6` | `CALL ESI` |
| `1001c882` | `50` | `PUSH EAX` |
| `1001c883` | `e8 87 a8 ff ff` | `CALL 0x1001710f` |
| `1001c888` | `59` | `POP ECX` |
| `1001c889` | `a3 d4 93 03 10` | `MOV [0x100393d4],EAX` |
| `1001c88e` | `85 c0` | `TEST EAX,EAX` |
| `1001c890` | `74 14` | `JZ 0x1001c8a6` |
| `1001c892` | `68 6c f8 02 10` | `PUSH 0x1002f86c` |
| `1001c897` | `57` | `PUSH EDI` |
| `1001c898` | `ff d6` | `CALL ESI` |
| `1001c89a` | `50` | `PUSH EAX` |
| `1001c89b` | `e8 6f a8 ff ff` | `CALL 0x1001710f` |
| `1001c8a0` | `59` | `POP ECX` |
| `1001c8a1` | `a3 d0 93 03 10` | `MOV [0x100393d0],EAX` |
| `1001c8a6` | `a1 d0 93 03 10` | `MOV EAX,[0x100393d0]` |
| `1001c8ab` | `3b c3` | `CMP EAX,EBX` |
| `1001c8ad` | `74 4f` | `JZ 0x1001c8fe` |
| `1001c8af` | `39 1d d4 93 03 10` | `CMP dword ptr [0x100393d4],EBX` |
| `1001c8b5` | `74 47` | `JZ 0x1001c8fe` |
| `1001c8b7` | `50` | `PUSH EAX` |
| `1001c8b8` | `e8 cd a8 ff ff` | `CALL 0x1001718a` |
| `1001c8bd` | `ff 35 d4 93 03 10` | `PUSH dword ptr [0x100393d4]` |
| `1001c8c3` | `8b f0` | `MOV ESI,EAX` |
| `1001c8c5` | `e8 c0 a8 ff ff` | `CALL 0x1001718a` |
| `1001c8ca` | `59` | `POP ECX` |
| `1001c8cb` | `59` | `POP ECX` |
| `1001c8cc` | `8b f8` | `MOV EDI,EAX` |
| `1001c8ce` | `85 f6` | `TEST ESI,ESI` |
| `1001c8d0` | `74 2c` | `JZ 0x1001c8fe` |
| `1001c8d2` | `85 ff` | `TEST EDI,EDI` |
| `1001c8d4` | `74 28` | `JZ 0x1001c8fe` |
| `1001c8d6` | `ff d6` | `CALL ESI` |
| `1001c8d8` | `85 c0` | `TEST EAX,EAX` |
| `1001c8da` | `74 19` | `JZ 0x1001c8f5` |
| `1001c8dc` | `8d 4d f8` | `LEA ECX,[EBP + -0x8]` |
| `1001c8df` | `51` | `PUSH ECX` |
| `1001c8e0` | `6a 0c` | `PUSH 0xc` |
| `1001c8e2` | `8d 4d ec` | `LEA ECX,[EBP + -0x14]` |
| `1001c8e5` | `51` | `PUSH ECX` |
| `1001c8e6` | `6a 01` | `PUSH 0x1` |
| `1001c8e8` | `50` | `PUSH EAX` |
| `1001c8e9` | `ff d7` | `CALL EDI` |
| `1001c8eb` | `85 c0` | `TEST EAX,EAX` |
| `1001c8ed` | `74 06` | `JZ 0x1001c8f5` |
| `1001c8ef` | `f6 45 f4 01` | `TEST byte ptr [EBP + -0xc],0x1` |
| `1001c8f3` | `75 09` | `JNZ 0x1001c8fe` |
| `1001c8f5` | `81 4d 10 00 00 20 00` | `OR dword ptr [EBP + 0x10],0x200000` |
| `1001c8fc` | `eb 39` | `JMP 0x1001c937` |
| `1001c8fe` | `a1 c8 93 03 10` | `MOV EAX,[0x100393c8]` |
| `1001c903` | `3b c3` | `CMP EAX,EBX` |
| `1001c905` | `74 30` | `JZ 0x1001c937` |
| `1001c907` | `50` | `PUSH EAX` |
| `1001c908` | `e8 7d a8 ff ff` | `CALL 0x1001718a` |
| `1001c90d` | `59` | `POP ECX` |
| `1001c90e` | `85 c0` | `TEST EAX,EAX` |
| `1001c910` | `74 25` | `JZ 0x1001c937` |
| `1001c912` | `ff d0` | `CALL EAX` |
| `1001c914` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001c917` | `85 c0` | `TEST EAX,EAX` |
| `1001c919` | `74 1c` | `JZ 0x1001c937` |
| `1001c91b` | `a1 cc 93 03 10` | `MOV EAX,[0x100393cc]` |
| `1001c920` | `3b c3` | `CMP EAX,EBX` |
| `1001c922` | `74 13` | `JZ 0x1001c937` |
| `1001c924` | `50` | `PUSH EAX` |
| `1001c925` | `e8 60 a8 ff ff` | `CALL 0x1001718a` |
| `1001c92a` | `59` | `POP ECX` |
| `1001c92b` | `85 c0` | `TEST EAX,EAX` |
| `1001c92d` | `74 08` | `JZ 0x1001c937` |
| `1001c92f` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001c932` | `ff d0` | `CALL EAX` |
| `1001c934` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001c937` | `ff 35 c4 93 03 10` | `PUSH dword ptr [0x100393c4]` |
| `1001c93d` | `e8 48 a8 ff ff` | `CALL 0x1001718a` |
| `1001c942` | `59` | `POP ECX` |
| `1001c943` | `85 c0` | `TEST EAX,EAX` |
| `1001c945` | `74 10` | `JZ 0x1001c957` |
| `1001c947` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001c94a` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001c94d` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001c950` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001c953` | `ff d0` | `CALL EAX` |
| `1001c955` | `eb 02` | `JMP 0x1001c959` |
| `1001c957` | `33 c0` | `XOR EAX,EAX` |
| `1001c959` | `5f` | `POP EDI` |
| `1001c95a` | `5e` | `POP ESI` |
| `1001c95b` | `5b` | `POP EBX` |
| `1001c95c` | `c9` | `LEAVE` |
| `1001c95d` | `c3` | `RET` |
