# 10016d60 `__except_handler4`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016d60 |
| `name` | __except_handler4 |
| `namespace` | Global |
| `signature` | undefined __except_handler4(void) |
| `size_bytes` | 396 |
| `stack_frame_size` | 32 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __except_handler4 |

## Decompiled C

```c

/* Library Function - Single Match
    __except_handler4
   
   Library: Visual Studio 2008 Release */

undefined4 __except_handler4(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  int *piVar5;
  int *local_1c;
  undefined4 local_18;
  int *local_14;
  undefined4 local_10;
  int local_c;
  char local_5;
  
  piVar5 = (int *)(*(uint *)(param_2 + 8) ^ DAT_10037490);
  local_5 = '\0';
  local_10 = 1;
  iVar1 = param_2 + 0x10;
  if (*piVar5 != -2) {
    __security_check_cookie(piVar5[1] + iVar1 ^ *(uint *)(*piVar5 + iVar1));
  }
  __security_check_cookie(piVar5[3] + iVar1 ^ *(uint *)(piVar5[2] + iVar1));
  iVar4 = param_2;
  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {
    *(int ***)(param_2 + -4) = &local_1c;
    iVar4 = *(int *)(param_2 + 0xc);
    local_1c = param_1;
    local_18 = param_3;
    if (iVar4 == -2) {
      return local_10;
    }
    do {
      local_14 = piVar5 + iVar4 * 3 + 4;
      local_c = *local_14;
      if (piVar5[iVar4 * 3 + 5] != 0) {
        iVar2 = _EH4_CallFilterFunc(piVar5[iVar4 * 3 + 5],iVar1);
        local_5 = '\x01';
        if (iVar2 < 0) {
          local_10 = 0;
          goto LAB_10016e08;
        }
        if (0 < iVar2) {
          if ((*param_1 == -0x1f928c9d) &&
             (BVar3 = __IsNonwritableInCurrentImage((PBYTE)&PTR____DestructExceptionObject_1002f7c8)
             , BVar3 != 0)) {
            ___DestructExceptionObject(param_1,1);
          }
          _EH4_GlobalUnwind(param_2);
          if (*(int *)(param_2 + 0xc) != iVar4) {
            _EH4_LocalUnwind(param_2,iVar4,iVar1,&DAT_10037490);
          }
          *(int *)(param_2 + 0xc) = local_c;
          if (*piVar5 != -2) {
            __security_check_cookie(piVar5[1] + iVar1 ^ *(uint *)(*piVar5 + iVar1));
          }
          __security_check_cookie(piVar5[3] + iVar1 ^ *(uint *)(piVar5[2] + iVar1));
          _EH4_TransferToHandler(local_14[2],iVar1);
          goto LAB_10016ecc;
        }
      }
      iVar4 = local_c;
    } while (local_c != -2);
    if (local_5 == '\0') {
      return local_10;
    }
  }
  else {
LAB_10016ecc:
    if (*(int *)(iVar4 + 0xc) == -2) {
      return local_10;
    }
    _EH4_LocalUnwind(iVar4,0xfffffffe,iVar1,&DAT_10037490);
  }
LAB_10016e08:
  if (*piVar5 != -2) {
    __security_check_cookie(piVar5[1] + iVar1 ^ *(uint *)(*piVar5 + iVar1));
  }
  __security_check_cookie(piVar5[3] + iVar1 ^ *(uint *)(piVar5[2] + iVar1));
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10016d94` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10016da4` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10016de9` | `100183fa` | `UNCONDITIONAL_CALL` | _EH4_CallFilterFunc | `100183fa` |
| `10016e17` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10016e27` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10016e58` | `100193f0` | `UNCONDITIONAL_CALL` | __IsNonwritableInCurrentImage | `100193f0` |
| `10016e6a` | `1001ae3c` | `COMPUTED_CALL` | ___DestructExceptionObject | `1001ae3c` |
| `10016e76` | `1001842a` | `UNCONDITIONAL_CALL` | _EH4_GlobalUnwind | `1001842a` |
| `10016e8d` | `10018444` | `UNCONDITIONAL_CALL` | _EH4_LocalUnwind | `10018444` |
| `10016eaa` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10016eba` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |
| `10016ec7` | `10018411` | `UNCONDITIONAL_CALL` | _EH4_TransferToHandler | `10018411` |
| `10016ee2` | `10018444` | `UNCONDITIONAL_CALL` | _EH4_LocalUnwind | `10018444` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016d70` | `10037490` | `READ` | DAT_10037490 |
| `10016e4a` | `1002f7c8` | `READ` | PTR____DestructExceptionObject_1002f7c8 |
| `10016e53` | `1002f7c8` | `DATA` | PTR____DestructExceptionObject_1002f7c8 |
| `10016e6a` | `1002f7c8` | `READ` | PTR____DestructExceptionObject_1002f7c8 |
| `10016e83` | `10037490` | `DATA` | DAT_10037490 |
| `10016eda` | `10037490` | `DATA` | DAT_10037490 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016d60` | `8b ff` | `MOV EDI,EDI` |
| `10016d62` | `55` | `PUSH EBP` |
| `10016d63` | `8b ec` | `MOV EBP,ESP` |
| `10016d65` | `83 ec 18` | `SUB ESP,0x18` |
| `10016d68` | `53` | `PUSH EBX` |
| `10016d69` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `10016d6c` | `56` | `PUSH ESI` |
| `10016d6d` | `8b 73 08` | `MOV ESI,dword ptr [EBX + 0x8]` |
| `10016d70` | `33 35 90 74 03 10` | `XOR ESI,dword ptr [0x10037490]` |
| `10016d76` | `57` | `PUSH EDI` |
| `10016d77` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10016d79` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10016d7d` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10016d84` | `8d 7b 10` | `LEA EDI,[EBX + 0x10]` |
| `10016d87` | `83 f8 fe` | `CMP EAX,-0x2` |
| `10016d8a` | `74 0d` | `JZ 0x10016d99` |
| `10016d8c` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `10016d8f` | `03 cf` | `ADD ECX,EDI` |
| `10016d91` | `33 0c 38` | `XOR ECX,dword ptr [EAX + EDI*0x1]` |
| `10016d94` | `e8 32 9f ff ff` | `CALL 0x10010ccb` |
| `10016d99` | `8b 4e 0c` | `MOV ECX,dword ptr [ESI + 0xc]` |
| `10016d9c` | `8b 46 08` | `MOV EAX,dword ptr [ESI + 0x8]` |
| `10016d9f` | `03 cf` | `ADD ECX,EDI` |
| `10016da1` | `33 0c 38` | `XOR ECX,dword ptr [EAX + EDI*0x1]` |
| `10016da4` | `e8 22 9f ff ff` | `CALL 0x10010ccb` |
| `10016da9` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10016dac` | `f6 40 04 66` | `TEST byte ptr [EAX + 0x4],0x66` |
| `10016db0` | `0f 85 16 01 00 00` | `JNZ 0x10016ecc` |
| `10016db6` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10016db9` | `8d 55 e8` | `LEA EDX,[EBP + -0x18]` |
| `10016dbc` | `89 53 fc` | `MOV dword ptr [EBX + -0x4],EDX` |
| `10016dbf` | `8b 5b 0c` | `MOV EBX,dword ptr [EBX + 0xc]` |
| `10016dc2` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `10016dc5` | `89 4d ec` | `MOV dword ptr [EBP + -0x14],ECX` |
| `10016dc8` | `83 fb fe` | `CMP EBX,-0x2` |
| `10016dcb` | `74 5f` | `JZ 0x10016e2c` |
| `10016dcd` | `8d 49 00` | `LEA ECX,[ECX]` |
| `10016dd0` | `8d 04 5b` | `LEA EAX,[EBX + EBX*0x2]` |
| `10016dd3` | `8b 4c 86 14` | `MOV ECX,dword ptr [ESI + EAX*0x4 + 0x14]` |
| `10016dd7` | `8d 44 86 10` | `LEA EAX,[ESI + EAX*0x4 + 0x10]` |
| `10016ddb` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `10016dde` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `10016de0` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10016de3` | `85 c9` | `TEST ECX,ECX` |
| `10016de5` | `74 14` | `JZ 0x10016dfb` |
| `10016de7` | `8b d7` | `MOV EDX,EDI` |
| `10016de9` | `e8 0c 16 00 00` | `CALL 0x100183fa` |
| `10016dee` | `c6 45 ff 01` | `MOV byte ptr [EBP + -0x1],0x1` |
| `10016df2` | `85 c0` | `TEST EAX,EAX` |
| `10016df4` | `7c 40` | `JL 0x10016e36` |
| `10016df6` | `7f 47` | `JG 0x10016e3f` |
| `10016df8` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10016dfb` | `8b d8` | `MOV EBX,EAX` |
| `10016dfd` | `83 f8 fe` | `CMP EAX,-0x2` |
| `10016e00` | `75 ce` | `JNZ 0x10016dd0` |
| `10016e02` | `80 7d ff 00` | `CMP byte ptr [EBP + -0x1],0x0` |
| `10016e06` | `74 24` | `JZ 0x10016e2c` |
| `10016e08` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10016e0a` | `83 f8 fe` | `CMP EAX,-0x2` |
| `10016e0d` | `74 0d` | `JZ 0x10016e1c` |
| `10016e0f` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `10016e12` | `03 cf` | `ADD ECX,EDI` |
| `10016e14` | `33 0c 38` | `XOR ECX,dword ptr [EAX + EDI*0x1]` |
| `10016e17` | `e8 af 9e ff ff` | `CALL 0x10010ccb` |
| `10016e1c` | `8b 4e 0c` | `MOV ECX,dword ptr [ESI + 0xc]` |
| `10016e1f` | `8b 56 08` | `MOV EDX,dword ptr [ESI + 0x8]` |
| `10016e22` | `03 cf` | `ADD ECX,EDI` |
| `10016e24` | `33 0c 3a` | `XOR ECX,dword ptr [EDX + EDI*0x1]` |
| `10016e27` | `e8 9f 9e ff ff` | `CALL 0x10010ccb` |
| `10016e2c` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10016e2f` | `5f` | `POP EDI` |
| `10016e30` | `5e` | `POP ESI` |
| `10016e31` | `5b` | `POP EBX` |
| `10016e32` | `8b e5` | `MOV ESP,EBP` |
| `10016e34` | `5d` | `POP EBP` |
| `10016e35` | `c3` | `RET` |
| `10016e36` | `c7 45 f4 00 00 00 00` | `MOV dword ptr [EBP + -0xc],0x0` |
| `10016e3d` | `eb c9` | `JMP 0x10016e08` |
| `10016e3f` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016e42` | `81 39 63 73 6d e0` | `CMP dword ptr [ECX],0xe06d7363` |
| `10016e48` | `75 29` | `JNZ 0x10016e73` |
| `10016e4a` | `83 3d c8 f7 02 10 00` | `CMP dword ptr [0x1002f7c8],0x0` |
| `10016e51` | `74 20` | `JZ 0x10016e73` |
| `10016e53` | `68 c8 f7 02 10` | `PUSH 0x1002f7c8` |
| `10016e58` | `e8 93 25 00 00` | `CALL 0x100193f0` |
| `10016e5d` | `83 c4 04` | `ADD ESP,0x4` |
| `10016e60` | `85 c0` | `TEST EAX,EAX` |
| `10016e62` | `74 0f` | `JZ 0x10016e73` |
| `10016e64` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10016e67` | `6a 01` | `PUSH 0x1` |
| `10016e69` | `52` | `PUSH EDX` |
| `10016e6a` | `ff 15 c8 f7 02 10` | `CALL dword ptr [0x1002f7c8]` |
| `10016e70` | `83 c4 08` | `ADD ESP,0x8` |
| `10016e73` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10016e76` | `e8 af 15 00 00` | `CALL 0x1001842a` |
| `10016e7b` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10016e7e` | `39 58 0c` | `CMP dword ptr [EAX + 0xc],EBX` |
| `10016e81` | `74 12` | `JZ 0x10016e95` |
| `10016e83` | `68 90 74 03 10` | `PUSH 0x10037490` |
| `10016e88` | `57` | `PUSH EDI` |
| `10016e89` | `8b d3` | `MOV EDX,EBX` |
| `10016e8b` | `8b c8` | `MOV ECX,EAX` |
| `10016e8d` | `e8 b2 15 00 00` | `CALL 0x10018444` |
| `10016e92` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10016e95` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10016e98` | `89 48 0c` | `MOV dword ptr [EAX + 0xc],ECX` |
| `10016e9b` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10016e9d` | `83 f8 fe` | `CMP EAX,-0x2` |
| `10016ea0` | `74 0d` | `JZ 0x10016eaf` |
| `10016ea2` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `10016ea5` | `03 cf` | `ADD ECX,EDI` |
| `10016ea7` | `33 0c 38` | `XOR ECX,dword ptr [EAX + EDI*0x1]` |
| `10016eaa` | `e8 1c 9e ff ff` | `CALL 0x10010ccb` |
| `10016eaf` | `8b 4e 0c` | `MOV ECX,dword ptr [ESI + 0xc]` |
| `10016eb2` | `8b 56 08` | `MOV EDX,dword ptr [ESI + 0x8]` |
| `10016eb5` | `03 cf` | `ADD ECX,EDI` |
| `10016eb7` | `33 0c 3a` | `XOR ECX,dword ptr [EDX + EDI*0x1]` |
| `10016eba` | `e8 0c 9e ff ff` | `CALL 0x10010ccb` |
| `10016ebf` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `10016ec2` | `8b 48 08` | `MOV ECX,dword ptr [EAX + 0x8]` |
| `10016ec5` | `8b d7` | `MOV EDX,EDI` |
| `10016ec7` | `e8 45 15 00 00` | `CALL 0x10018411` |
| `10016ecc` | `ba fe ff ff ff` | `MOV EDX,0xfffffffe` |
| `10016ed1` | `39 53 0c` | `CMP dword ptr [EBX + 0xc],EDX` |
| `10016ed4` | `0f 84 52 ff ff ff` | `JZ 0x10016e2c` |
| `10016eda` | `68 90 74 03 10` | `PUSH 0x10037490` |
| `10016edf` | `57` | `PUSH EDI` |
| `10016ee0` | `8b cb` | `MOV ECX,EBX` |
| `10016ee2` | `e8 5d 15 00 00` | `CALL 0x10018444` |
| `10016ee7` | `e9 1c ff ff ff` | `JMP 0x10016e08` |
