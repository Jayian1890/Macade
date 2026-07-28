# 10016eec `__NMSG_WRITE`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016eec |
| `name` | __NMSG_WRITE |
| `namespace` | Global |
| `signature` | void __cdecl __NMSG_WRITE(int param_1) |
| `size_bytes` | 410 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __NMSG_WRITE |

## Decompiled C

```c

/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 2008 Release */

void __cdecl __NMSG_WRITE(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  errno_t eVar4;
  DWORD DVar5;
  size_t sVar6;
  HANDLE hFile;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  DWORD local_c;
  uint local_8;
  
  local_8 = 0;
  do {
    if (param_1 == (&DAT_10037738)[local_8 * 2]) break;
    local_8 = local_8 + 1;
  } while (local_8 < 0x17);
  uVar2 = local_8;
  if (local_8 < 0x17) {
    iVar3 = __set_error_mode(3);
    if ((iVar3 != 1) && ((iVar3 = __set_error_mode(3), iVar3 != 0 || (DAT_10038a80 != 1)))) {
      if (param_1 == 0xfc) {
        return;
      }
      eVar4 = _strcpy_s(&DAT_10038f08,0x314,"Runtime Error!\n\nProgram: ");
      if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      DAT_10039025 = 0;
      DVar5 = GetModuleFileNameA((HMODULE)0x0,&DAT_10038f21,0x104);
      if ((DVar5 == 0) &&
         (eVar4 = _strcpy_s(&DAT_10038f21,0x2fb,"<program name unknown>"), eVar4 != 0)) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar6 = _strlen(&DAT_10038f21);
      if (0x3c < sVar6 + 1) {
        sVar6 = _strlen(&DAT_10038f21);
        eVar4 = _strncpy_s((char *)(sVar6 + 0x10038ee6),
                           (int)&DAT_1003921c - (int)(sVar6 + 0x10038ee6),"...",3);
        if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
      }
      eVar4 = _strcat_s(&DAT_10038f08,0x314,"\n\n");
      if (eVar4 == 0) {
        eVar4 = _strcat_s(&DAT_10038f08,0x314,*(char **)(local_8 * 8 + 0x1003773c));
        if (eVar4 == 0) {
          ___crtMessageBoxA(&DAT_10038f08,"Microsoft Visual C++ Runtime Library",0x12010);
          return;
        }
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    hFile = GetStdHandle(0xfffffff4);
    if ((hFile != (HANDLE)0x0) && (hFile != (HANDLE)0xffffffff)) {
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &local_c;
      puVar1 = (undefined4 *)(uVar2 * 8 + 0x1003773c);
      sVar6 = _strlen((char *)*puVar1);
      WriteFile(hFile,(LPCVOID)*puVar1,sVar6,lpNumberOfBytesWritten,lpOverlapped);
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10016f1d` | `1001ca87` | `UNCONDITIONAL_CALL` | __set_error_mode | `1001ca87` |
| `10016f2e` | `1001ca87` | `UNCONDITIONAL_CALL` | __set_error_mode | `1001ca87` |
| `10016f62` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `10016f73` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `10016f8f` | `EXTERNAL:00000047` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleFileNameA | `` |
| `10016fa4` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `10016fb7` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `10016fc0` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `10016fcd` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `10016fe7` | `1001c9d2` | `UNCONDITIONAL_CALL` | _strncpy_s | `1001c9d2` |
| `10016ffa` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1001700d` | `1001c95e` | `UNCONDITIONAL_CALL` | _strcat_s | `1001c95e` |
| `1001701e` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `10017032` | `1001c95e` | `UNCONDITIONAL_CALL` | _strcat_s | `1001c95e` |
| `10017043` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `10017056` | `1001c7f5` | `UNCONDITIONAL_CALL` | ___crtMessageBoxA | `1001c7f5` |
| `10017062` | `EXTERNAL:00000046` | `COMPUTED_CALL` | KERNEL32.DLL::GetStdHandle | `` |
| `10017082` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001708c` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |

## Callers

| From | Function |
| --- | --- |
| `10012449` | __amsg_exit |
| `10016163` | __mtinitlocknum |
| `100170be` | __FF_MSGBANNER |
| `100170c8` | __FF_MSGBANNER |
| `10011348` | _malloc |
| `100179cf` | _abort |
| `10011965` | __purecall |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `10016f51` | `1002f648` | `Runtime Error!\n\nProgram: ` |
| `10016f99` | `1002f630` | `<program name unknown>` |
| `10017029` | `1002f578` | `R6009\n- not enough space for environment\n` |
| `10017050` | `1002f600` | `Microsoft Visual C++ Runtime Library` |
| `10017080` | `1002f578` | `R6009\n- not enough space for environment\n` |
| `10017089` | `1002f578` | `R6009\n- not enough space for environment\n` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016f00` | `10037738` | `READ` | DAT_10037738 |
| `10016f00` | `10037740` | `READ` | DAT_10037740 |
| `10016f38` | `10038a80` | `READ` | DAT_10038a80 |
| `10016f5c` | `10038f08` | `DATA` | DAT_10038f08 |
| `10016f61` | `10038f08` | `DATA` | DAT_10038f08 |
| `10016f80` | `10038f21` | `DATA` | DAT_10038f21 |
| `10016f85` | `10038f21` | `DATA` | DAT_10038f21 |
| `10016f88` | `10039025` | `WRITE` | DAT_10039025 |
| `10016f8f` | `1002e0d4` | `READ` | PTR_GetModuleFileNameA_1002e0d4 |
| `10016fa3` | `10038f21` | `DATA` | DAT_10038f21 |
| `10016fbf` | `10038f21` | `DATA` | DAT_10038f21 |
| `10016fcc` | `10038f21` | `DATA` | DAT_10038f21 |
| `10016fd9` | `1003921c` | `DATA` | DAT_1003921c |
| `10016fde` | `1002f62c` | `DATA` | DAT_1002f62c |
| `10017006` | `1002f628` | `DATA` | DAT_1002f628 |
| `1001700c` | `10038f08` | `DATA` | DAT_10038f08 |
| `10017029` | `1003774c` | `READ` | PTR_s_R6009_-_not_enough_space_for_env_1003774c |
| `10017031` | `10038f08` | `DATA` | DAT_10038f08 |
| `10017055` | `10038f08` | `DATA` | DAT_10038f08 |
| `10017062` | `1002e0d0` | `READ` | PTR_GetStdHandle_1002e0d0 |
| `10017079` | `1003774c` | `DATA` | PTR_s_R6009_-_not_enough_space_for_env_1003774c |
| `10017080` | `1003774c` | `READ` | PTR_s_R6009_-_not_enough_space_for_env_1003774c |
| `10017089` | `1003774c` | `READ` | PTR_s_R6009_-_not_enough_space_for_env_1003774c |
| `1001708c` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016eec` | `8b ff` | `MOV EDI,EDI` |
| `10016eee` | `55` | `PUSH EBP` |
| `10016eef` | `8b ec` | `MOV EBP,ESP` |
| `10016ef1` | `51` | `PUSH ECX` |
| `10016ef2` | `51` | `PUSH ECX` |
| `10016ef3` | `53` | `PUSH EBX` |
| `10016ef4` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10016ef7` | `56` | `PUSH ESI` |
| `10016ef8` | `57` | `PUSH EDI` |
| `10016ef9` | `33 f6` | `XOR ESI,ESI` |
| `10016efb` | `33 ff` | `XOR EDI,EDI` |
| `10016efd` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10016f00` | `3b 1c fd 38 77 03 10` | `CMP EBX,dword ptr [EDI*0x8 + 0x10037738]` |
| `10016f07` | `74 09` | `JZ 0x10016f12` |
| `10016f09` | `47` | `INC EDI` |
| `10016f0a` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10016f0d` | `83 ff 17` | `CMP EDI,0x17` |
| `10016f10` | `72 ee` | `JC 0x10016f00` |
| `10016f12` | `83 ff 17` | `CMP EDI,0x17` |
| `10016f15` | `0f 83 77 01 00 00` | `JNC 0x10017092` |
| `10016f1b` | `6a 03` | `PUSH 0x3` |
| `10016f1d` | `e8 65 5b 00 00` | `CALL 0x1001ca87` |
| `10016f22` | `59` | `POP ECX` |
| `10016f23` | `83 f8 01` | `CMP EAX,0x1` |
| `10016f26` | `0f 84 34 01 00 00` | `JZ 0x10017060` |
| `10016f2c` | `6a 03` | `PUSH 0x3` |
| `10016f2e` | `e8 54 5b 00 00` | `CALL 0x1001ca87` |
| `10016f33` | `59` | `POP ECX` |
| `10016f34` | `85 c0` | `TEST EAX,EAX` |
| `10016f36` | `75 0d` | `JNZ 0x10016f45` |
| `10016f38` | `83 3d 80 8a 03 10 01` | `CMP dword ptr [0x10038a80],0x1` |
| `10016f3f` | `0f 84 1b 01 00 00` | `JZ 0x10017060` |
| `10016f45` | `81 fb fc 00 00 00` | `CMP EBX,0xfc` |
| `10016f4b` | `0f 84 41 01 00 00` | `JZ 0x10017092` |
| `10016f51` | `68 48 f6 02 10` | `PUSH 0x1002f648` |
| `10016f56` | `bb 14 03 00 00` | `MOV EBX,0x314` |
| `10016f5b` | `53` | `PUSH EBX` |
| `10016f5c` | `bf 08 8f 03 10` | `MOV EDI,0x10038f08` |
| `10016f61` | `57` | `PUSH EDI` |
| `10016f62` | `e8 14 f0 ff ff` | `CALL 0x10015f7b` |
| `10016f67` | `83 c4 0c` | `ADD ESP,0xc` |
| `10016f6a` | `85 c0` | `TEST EAX,EAX` |
| `10016f6c` | `74 0d` | `JZ 0x10016f7b` |
| `10016f6e` | `56` | `PUSH ESI` |
| `10016f6f` | `56` | `PUSH ESI` |
| `10016f70` | `56` | `PUSH ESI` |
| `10016f71` | `56` | `PUSH ESI` |
| `10016f72` | `56` | `PUSH ESI` |
| `10016f73` | `e8 0f a6 ff ff` | `CALL 0x10011587` |
| `10016f7b` | `68 04 01 00 00` | `PUSH 0x104` |
| `10016f80` | `be 21 8f 03 10` | `MOV ESI,0x10038f21` |
| `10016f85` | `56` | `PUSH ESI` |
| `10016f86` | `6a 00` | `PUSH 0x0` |
| `10016f88` | `c6 05 25 90 03 10 00` | `MOV byte ptr [0x10039025],0x0` |
| `10016f8f` | `ff 15 d4 e0 02 10` | `CALL dword ptr [0x1002e0d4]` |
| `10016f95` | `85 c0` | `TEST EAX,EAX` |
| `10016f97` | `75 26` | `JNZ 0x10016fbf` |
| `10016f99` | `68 30 f6 02 10` | `PUSH 0x1002f630` |
| `10016f9e` | `68 fb 02 00 00` | `PUSH 0x2fb` |
| `10016fa3` | `56` | `PUSH ESI` |
| `10016fa4` | `e8 d2 ef ff ff` | `CALL 0x10015f7b` |
| `10016fa9` | `83 c4 0c` | `ADD ESP,0xc` |
| `10016fac` | `85 c0` | `TEST EAX,EAX` |
| `10016fae` | `74 0f` | `JZ 0x10016fbf` |
| `10016fb0` | `33 c0` | `XOR EAX,EAX` |
| `10016fb2` | `50` | `PUSH EAX` |
| `10016fb3` | `50` | `PUSH EAX` |
| `10016fb4` | `50` | `PUSH EAX` |
| `10016fb5` | `50` | `PUSH EAX` |
| `10016fb6` | `50` | `PUSH EAX` |
| `10016fb7` | `e8 cb a5 ff ff` | `CALL 0x10011587` |
| `10016fbf` | `56` | `PUSH ESI` |
| `10016fc0` | `e8 2b a4 ff ff` | `CALL 0x100113f0` |
| `10016fc5` | `40` | `INC EAX` |
| `10016fc6` | `59` | `POP ECX` |
| `10016fc7` | `83 f8 3c` | `CMP EAX,0x3c` |
| `10016fca` | `76 38` | `JBE 0x10017004` |
| `10016fcc` | `56` | `PUSH ESI` |
| `10016fcd` | `e8 1e a4 ff ff` | `CALL 0x100113f0` |
| `10016fd2` | `83 ee 3b` | `SUB ESI,0x3b` |
| `10016fd5` | `03 c6` | `ADD EAX,ESI` |
| `10016fd7` | `6a 03` | `PUSH 0x3` |
| `10016fd9` | `b9 1c 92 03 10` | `MOV ECX,0x1003921c` |
| `10016fde` | `68 2c f6 02 10` | `PUSH 0x1002f62c` |
| `10016fe3` | `2b c8` | `SUB ECX,EAX` |
| `10016fe5` | `51` | `PUSH ECX` |
| `10016fe6` | `50` | `PUSH EAX` |
| `10016fe7` | `e8 e6 59 00 00` | `CALL 0x1001c9d2` |
| `10016fec` | `83 c4 14` | `ADD ESP,0x14` |
| `10016fef` | `85 c0` | `TEST EAX,EAX` |
| `10016ff1` | `74 11` | `JZ 0x10017004` |
| `10016ff3` | `33 f6` | `XOR ESI,ESI` |
| `10016ff5` | `56` | `PUSH ESI` |
| `10016ff6` | `56` | `PUSH ESI` |
| `10016ff7` | `56` | `PUSH ESI` |
| `10016ff8` | `56` | `PUSH ESI` |
| `10016ff9` | `56` | `PUSH ESI` |
| `10016ffa` | `e8 88 a5 ff ff` | `CALL 0x10011587` |
| `10017004` | `33 f6` | `XOR ESI,ESI` |
| `10017006` | `68 28 f6 02 10` | `PUSH 0x1002f628` |
| `1001700b` | `53` | `PUSH EBX` |
| `1001700c` | `57` | `PUSH EDI` |
| `1001700d` | `e8 4c 59 00 00` | `CALL 0x1001c95e` |
| `10017012` | `83 c4 0c` | `ADD ESP,0xc` |
| `10017015` | `85 c0` | `TEST EAX,EAX` |
| `10017017` | `74 0d` | `JZ 0x10017026` |
| `10017019` | `56` | `PUSH ESI` |
| `1001701a` | `56` | `PUSH ESI` |
| `1001701b` | `56` | `PUSH ESI` |
| `1001701c` | `56` | `PUSH ESI` |
| `1001701d` | `56` | `PUSH ESI` |
| `1001701e` | `e8 64 a5 ff ff` | `CALL 0x10011587` |
| `10017026` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10017029` | `ff 34 c5 3c 77 03 10` | `PUSH dword ptr [EAX*0x8 + 0x1003773c]` |
| `10017030` | `53` | `PUSH EBX` |
| `10017031` | `57` | `PUSH EDI` |
| `10017032` | `e8 27 59 00 00` | `CALL 0x1001c95e` |
| `10017037` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001703a` | `85 c0` | `TEST EAX,EAX` |
| `1001703c` | `74 0d` | `JZ 0x1001704b` |
| `1001703e` | `56` | `PUSH ESI` |
| `1001703f` | `56` | `PUSH ESI` |
| `10017040` | `56` | `PUSH ESI` |
| `10017041` | `56` | `PUSH ESI` |
| `10017042` | `56` | `PUSH ESI` |
| `10017043` | `e8 3f a5 ff ff` | `CALL 0x10011587` |
| `1001704b` | `68 10 20 01 00` | `PUSH 0x12010` |
| `10017050` | `68 00 f6 02 10` | `PUSH 0x1002f600` |
| `10017055` | `57` | `PUSH EDI` |
| `10017056` | `e8 9a 57 00 00` | `CALL 0x1001c7f5` |
| `1001705b` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001705e` | `eb 32` | `JMP 0x10017092` |
| `10017060` | `6a f4` | `PUSH -0xc` |
| `10017062` | `ff 15 d0 e0 02 10` | `CALL dword ptr [0x1002e0d0]` |
| `10017068` | `8b d8` | `MOV EBX,EAX` |
| `1001706a` | `3b de` | `CMP EBX,ESI` |
| `1001706c` | `74 24` | `JZ 0x10017092` |
| `1001706e` | `83 fb ff` | `CMP EBX,-0x1` |
| `10017071` | `74 1f` | `JZ 0x10017092` |
| `10017073` | `6a 00` | `PUSH 0x0` |
| `10017075` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `10017078` | `50` | `PUSH EAX` |
| `10017079` | `8d 34 fd 3c 77 03 10` | `LEA ESI,[EDI*0x8 + 0x1003773c]` |
| `10017080` | `ff 36` | `PUSH dword ptr [ESI]` |
| `10017082` | `e8 69 a3 ff ff` | `CALL 0x100113f0` |
| `10017087` | `59` | `POP ECX` |
| `10017088` | `50` | `PUSH EAX` |
| `10017089` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001708b` | `53` | `PUSH EBX` |
| `1001708c` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `10017092` | `5f` | `POP EDI` |
| `10017093` | `5e` | `POP ESI` |
| `10017094` | `5b` | `POP EBX` |
| `10017095` | `c9` | `LEAVE` |
| `10017096` | `c3` | `RET` |
