# 10012ab0 `_realloc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012ab0 |
| `name` | _realloc |
| `namespace` | Global |
| `signature` | void * __cdecl _realloc(void * _Memory, size_t _NewSize) |
| `size_bytes` | 524 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _realloc |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _realloc
   
   Library: Visual Studio 2008 Release */

void * __cdecl _realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  DWORD DVar5;
  LPVOID pvVar6;
  int local_24;
  void *local_20;
  
  if (_Memory == (void *)0x0) {
    pvVar1 = _malloc(_NewSize);
    return pvVar1;
  }
  if (_NewSize == 0) {
    _free(_Memory);
    return (void *)0x0;
  }
  if (DAT_1343a680 == 3) {
    do {
      local_20 = (void *)0x0;
      if (0xffffffe0 < _NewSize) goto LAB_10012c89;
      __lock(4);
      local_24 = ___sbh_find_block(_Memory);
      if (local_24 != 0) {
        if (_NewSize <= DAT_1343a670) {
          iVar2 = ___sbh_resize_block(local_24,_Memory,_NewSize);
          if (iVar2 == 0) {
            local_20 = (void *)___sbh_alloc_block(_NewSize);
            if (local_20 != (void *)0x0) {
              uVar3 = *(int *)((int)_Memory + -4) - 1;
              if (_NewSize <= uVar3) {
                uVar3 = _NewSize;
              }
              _memcpy(local_20,_Memory,uVar3);
              local_24 = ___sbh_find_block(_Memory);
              ___sbh_free_block(local_24,_Memory);
            }
          }
          else {
            local_20 = _Memory;
          }
        }
        if (local_20 == (void *)0x0) {
          if (_NewSize == 0) {
            _NewSize = 1;
          }
          _NewSize = _NewSize + 0xf & 0xfffffff0;
          local_20 = HeapAlloc(DAT_10038dac,0,_NewSize);
          if (local_20 != (LPVOID)0x0) {
            uVar3 = *(int *)((int)_Memory + -4) - 1;
            if (_NewSize <= uVar3) {
              uVar3 = _NewSize;
            }
            _memcpy(local_20,_Memory,uVar3);
            ___sbh_free_block(local_24,_Memory);
          }
        }
      }
      FUN_10012bf4();
      if (local_24 == 0) {
        if (_NewSize == 0) {
          _NewSize = 1;
        }
        _NewSize = _NewSize + 0xf & 0xfffffff0;
        local_20 = HeapReAlloc(DAT_10038dac,0,_Memory,_NewSize);
      }
      if (local_20 != (void *)0x0) {
        return local_20;
      }
      if (DAT_10039220 == 0) {
        piVar4 = __errno();
        if (local_24 != 0) {
          *piVar4 = 0xc;
          return (void *)0x0;
        }
        goto LAB_10012cb6;
      }
      iVar2 = __callnewh(_NewSize);
    } while (iVar2 != 0);
    piVar4 = __errno();
    if (local_24 != 0) goto LAB_10012c95;
  }
  else {
    do {
      if (0xffffffe0 < _NewSize) goto LAB_10012c89;
      if (_NewSize == 0) {
        _NewSize = 1;
      }
      pvVar6 = HeapReAlloc(DAT_10038dac,0,_Memory,_NewSize);
      if (pvVar6 != (LPVOID)0x0) {
        return pvVar6;
      }
      if (DAT_10039220 == 0) {
        piVar4 = __errno();
LAB_10012cb6:
        DVar5 = GetLastError();
        iVar2 = __get_errno_from_oserr(DVar5);
        *piVar4 = iVar2;
        return (void *)0x0;
      }
      iVar2 = __callnewh(_NewSize);
    } while (iVar2 != 0);
    piVar4 = __errno();
  }
  DVar5 = GetLastError();
  iVar2 = __get_errno_from_oserr(DVar5);
  *piVar4 = iVar2;
  return (void *)0x0;
LAB_10012c89:
  __callnewh(_NewSize);
  piVar4 = __errno();
LAB_10012c95:
  *piVar4 = 0xc;
  return (void *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10012ab7` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `10012ac6` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `10012ad9` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10012b01` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `10012b0b` | `10016236` | `UNCONDITIONAL_CALL` | ___sbh_find_block | `10016236` |
| `10012b27` | `10016734` | `UNCONDITIONAL_CALL` | ___sbh_resize_block | `10016734` |
| `10012b39` | `10016a15` | `UNCONDITIONAL_CALL` | ___sbh_alloc_block | `10016a15` |
| `10012b55` | `10010ce0` | `UNCONDITIONAL_CALL` | _memcpy | `10010ce0` |
| `10012b5b` | `10016236` | `UNCONDITIONAL_CALL` | ___sbh_find_block | `10016236` |
| `10012b65` | `10016266` | `UNCONDITIONAL_CALL` | ___sbh_free_block | `10016266` |
| `10012b8d` | `EXTERNAL:00000030` | `COMPUTED_CALL` | KERNEL32.DLL::HeapAlloc | `` |
| `10012ba9` | `10010ce0` | `UNCONDITIONAL_CALL` | _memcpy | `10010ce0` |
| `10012bb2` | `10016266` | `UNCONDITIONAL_CALL` | ___sbh_free_block | `10016266` |
| `10012bc1` | `10012bf4` | `UNCONDITIONAL_CALL` | FUN_10012bf4 | `10012bf4` |
| `10012be4` | `EXTERNAL:00000039` | `COMPUTED_CALL` | KERNEL32.DLL::HeapReAlloc | `` |
| `10012c11` | `100170df` | `UNCONDITIONAL_CALL` | __callnewh | `100170df` |
| `10012c1f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10012c2b` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10012c32` | `100150c7` | `UNCONDITIONAL_CALL` | __get_errno_from_oserr | `100150c7` |
| `10012c44` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10012c65` | `EXTERNAL:00000039` | `COMPUTED_CALL` | KERNEL32.DLL::HeapReAlloc | `` |
| `10012c7a` | `100170df` | `UNCONDITIONAL_CALL` | __callnewh | `100170df` |
| `10012c8a` | `100170df` | `UNCONDITIONAL_CALL` | __callnewh | `100170df` |
| `10012c90` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10012c9d` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |
| `10012ca3` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10012cb1` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10012cb8` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10012cbf` | `100150c7` | `UNCONDITIONAL_CALL` | __get_errno_from_oserr | `100150c7` |

## Callers

| From | Function |
| --- | --- |
| `1001e8ce` | __recalloc |
| `1001a56f` | __realloc_crt |
| `100259de` | FUN_10025980 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012ab2` | `10033d78` | `DATA` | DAT_10033d78 |
| `10012ae4` | `1343a680` | `READ` | DAT_1343a680 |
| `10012b1c` | `1343a670` | `READ` | DAT_1343a670 |
| `10012b87` | `10038dac` | `READ` | DAT_10038dac |
| `10012b8d` | `1002e078` | `READ` | PTR_HeapAlloc_1002e078 |
| `10012bde` | `10038dac` | `READ` | DAT_10038dac |
| `10012be4` | `1002e09c` | `READ` | PTR_HeapReAlloc_1002e09c |
| `10012c08` | `10039220` | `READ` | DAT_10039220 |
| `10012c2b` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `10012c5f` | `10038dac` | `READ` | DAT_10038dac |
| `10012c65` | `1002e09c` | `READ` | PTR_HeapReAlloc_1002e09c |
| `10012c71` | `10039220` | `READ` | DAT_10039220 |
| `10012cb8` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012ab0` | `6a 10` | `PUSH 0x10` |
| `10012ab2` | `68 78 3d 03 10` | `PUSH 0x10033d78` |
| `10012ab7` | `e8 40 42 00 00` | `CALL 0x10016cfc` |
| `10012abc` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10012abf` | `85 db` | `TEST EBX,EBX` |
| `10012ac1` | `75 0e` | `JNZ 0x10012ad1` |
| `10012ac3` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10012ac6` | `e8 53 e8 ff ff` | `CALL 0x1001131e` |
| `10012acb` | `59` | `POP ECX` |
| `10012acc` | `e9 cc 01 00 00` | `JMP 0x10012c9d` |
| `10012ad1` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10012ad4` | `85 f6` | `TEST ESI,ESI` |
| `10012ad6` | `75 0c` | `JNZ 0x10012ae4` |
| `10012ad8` | `53` | `PUSH EBX` |
| `10012ad9` | `e8 63 e7 ff ff` | `CALL 0x10011241` |
| `10012ade` | `59` | `POP ECX` |
| `10012adf` | `e9 b7 01 00 00` | `JMP 0x10012c9b` |
| `10012ae4` | `83 3d 80 a6 43 13 03` | `CMP dword ptr [0x1343a680],0x3` |
| `10012aeb` | `0f 85 93 01 00 00` | `JNZ 0x10012c84` |
| `10012af1` | `33 ff` | `XOR EDI,EDI` |
| `10012af3` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `10012af6` | `83 fe e0` | `CMP ESI,-0x20` |
| `10012af9` | `0f 87 8a 01 00 00` | `JA 0x10012c89` |
| `10012aff` | `6a 04` | `PUSH 0x4` |
| `10012b01` | `e8 fd 36 00 00` | `CALL 0x10016203` |
| `10012b06` | `59` | `POP ECX` |
| `10012b07` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10012b0a` | `53` | `PUSH EBX` |
| `10012b0b` | `e8 26 37 00 00` | `CALL 0x10016236` |
| `10012b10` | `59` | `POP ECX` |
| `10012b11` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `10012b14` | `3b c7` | `CMP EAX,EDI` |
| `10012b16` | `0f 84 9e 00 00 00` | `JZ 0x10012bba` |
| `10012b1c` | `3b 35 70 a6 43 13` | `CMP ESI,dword ptr [0x1343a670]` |
| `10012b22` | `77 49` | `JA 0x10012b6d` |
| `10012b24` | `56` | `PUSH ESI` |
| `10012b25` | `53` | `PUSH EBX` |
| `10012b26` | `50` | `PUSH EAX` |
| `10012b27` | `e8 08 3c 00 00` | `CALL 0x10016734` |
| `10012b2c` | `83 c4 0c` | `ADD ESP,0xc` |
| `10012b2f` | `85 c0` | `TEST EAX,EAX` |
| `10012b31` | `74 05` | `JZ 0x10012b38` |
| `10012b33` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `10012b36` | `eb 35` | `JMP 0x10012b6d` |
| `10012b38` | `56` | `PUSH ESI` |
| `10012b39` | `e8 d7 3e 00 00` | `CALL 0x10016a15` |
| `10012b3e` | `59` | `POP ECX` |
| `10012b3f` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10012b42` | `3b c7` | `CMP EAX,EDI` |
| `10012b44` | `74 27` | `JZ 0x10012b6d` |
| `10012b46` | `8b 43 fc` | `MOV EAX,dword ptr [EBX + -0x4]` |
| `10012b49` | `48` | `DEC EAX` |
| `10012b4a` | `3b c6` | `CMP EAX,ESI` |
| `10012b4c` | `72 02` | `JC 0x10012b50` |
| `10012b4e` | `8b c6` | `MOV EAX,ESI` |
| `10012b50` | `50` | `PUSH EAX` |
| `10012b51` | `53` | `PUSH EBX` |
| `10012b52` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `10012b55` | `e8 86 e1 ff ff` | `CALL 0x10010ce0` |
| `10012b5a` | `53` | `PUSH EBX` |
| `10012b5b` | `e8 d6 36 00 00` | `CALL 0x10016236` |
| `10012b60` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `10012b63` | `53` | `PUSH EBX` |
| `10012b64` | `50` | `PUSH EAX` |
| `10012b65` | `e8 fc 36 00 00` | `CALL 0x10016266` |
| `10012b6a` | `83 c4 18` | `ADD ESP,0x18` |
| `10012b6d` | `39 7d e4` | `CMP dword ptr [EBP + -0x1c],EDI` |
| `10012b70` | `75 48` | `JNZ 0x10012bba` |
| `10012b72` | `3b f7` | `CMP ESI,EDI` |
| `10012b74` | `75 06` | `JNZ 0x10012b7c` |
| `10012b76` | `33 f6` | `XOR ESI,ESI` |
| `10012b78` | `46` | `INC ESI` |
| `10012b79` | `89 75 0c` | `MOV dword ptr [EBP + 0xc],ESI` |
| `10012b7c` | `83 c6 0f` | `ADD ESI,0xf` |
| `10012b7f` | `83 e6 f0` | `AND ESI,0xfffffff0` |
| `10012b82` | `89 75 0c` | `MOV dword ptr [EBP + 0xc],ESI` |
| `10012b85` | `56` | `PUSH ESI` |
| `10012b86` | `57` | `PUSH EDI` |
| `10012b87` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `10012b8d` | `ff 15 78 e0 02 10` | `CALL dword ptr [0x1002e078]` |
| `10012b93` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10012b96` | `3b c7` | `CMP EAX,EDI` |
| `10012b98` | `74 20` | `JZ 0x10012bba` |
| `10012b9a` | `8b 43 fc` | `MOV EAX,dword ptr [EBX + -0x4]` |
| `10012b9d` | `48` | `DEC EAX` |
| `10012b9e` | `3b c6` | `CMP EAX,ESI` |
| `10012ba0` | `72 02` | `JC 0x10012ba4` |
| `10012ba2` | `8b c6` | `MOV EAX,ESI` |
| `10012ba4` | `50` | `PUSH EAX` |
| `10012ba5` | `53` | `PUSH EBX` |
| `10012ba6` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `10012ba9` | `e8 32 e1 ff ff` | `CALL 0x10010ce0` |
| `10012bae` | `53` | `PUSH EBX` |
| `10012baf` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `10012bb2` | `e8 af 36 00 00` | `CALL 0x10016266` |
| `10012bb7` | `83 c4 14` | `ADD ESP,0x14` |
| `10012bba` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10012bc1` | `e8 2e 00 00 00` | `CALL 0x10012bf4` |
| `10012bc6` | `83 7d e0 00` | `CMP dword ptr [EBP + -0x20],0x0` |
| `10012bca` | `75 31` | `JNZ 0x10012bfd` |
| `10012bcc` | `85 f6` | `TEST ESI,ESI` |
| `10012bce` | `75 01` | `JNZ 0x10012bd1` |
| `10012bd0` | `46` | `INC ESI` |
| `10012bd1` | `83 c6 0f` | `ADD ESI,0xf` |
| `10012bd4` | `83 e6 f0` | `AND ESI,0xfffffff0` |
| `10012bd7` | `89 75 0c` | `MOV dword ptr [EBP + 0xc],ESI` |
| `10012bda` | `56` | `PUSH ESI` |
| `10012bdb` | `53` | `PUSH EBX` |
| `10012bdc` | `6a 00` | `PUSH 0x0` |
| `10012bde` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `10012be4` | `ff 15 9c e0 02 10` | `CALL dword ptr [0x1002e09c]` |
| `10012bea` | `8b f8` | `MOV EDI,EAX` |
| `10012bec` | `eb 12` | `JMP 0x10012c00` |
| `10012bfd` | `8b 7d e4` | `MOV EDI,dword ptr [EBP + -0x1c]` |
| `10012c00` | `85 ff` | `TEST EDI,EDI` |
| `10012c02` | `0f 85 bf 00 00 00` | `JNZ 0x10012cc7` |
| `10012c08` | `39 3d 20 92 03 10` | `CMP dword ptr [0x10039220],EDI` |
| `10012c0e` | `74 2c` | `JZ 0x10012c3c` |
| `10012c10` | `56` | `PUSH ESI` |
| `10012c11` | `e8 c9 44 00 00` | `CALL 0x100170df` |
| `10012c16` | `59` | `POP ECX` |
| `10012c17` | `85 c0` | `TEST EAX,EAX` |
| `10012c19` | `0f 85 d2 fe ff ff` | `JNZ 0x10012af1` |
| `10012c1f` | `e8 e5 24 00 00` | `CALL 0x10015109` |
| `10012c24` | `39 7d e0` | `CMP dword ptr [EBP + -0x20],EDI` |
| `10012c27` | `75 6c` | `JNZ 0x10012c95` |
| `10012c29` | `8b f0` | `MOV ESI,EAX` |
| `10012c2b` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10012c31` | `50` | `PUSH EAX` |
| `10012c32` | `e8 90 24 00 00` | `CALL 0x100150c7` |
| `10012c37` | `59` | `POP ECX` |
| `10012c38` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10012c3a` | `eb 5f` | `JMP 0x10012c9b` |
| `10012c3c` | `85 ff` | `TEST EDI,EDI` |
| `10012c3e` | `0f 85 83 00 00 00` | `JNZ 0x10012cc7` |
| `10012c44` | `e8 c0 24 00 00` | `CALL 0x10015109` |
| `10012c49` | `39 7d e0` | `CMP dword ptr [EBP + -0x20],EDI` |
| `10012c4c` | `74 68` | `JZ 0x10012cb6` |
| `10012c4e` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `10012c54` | `eb 71` | `JMP 0x10012cc7` |
| `10012c56` | `85 f6` | `TEST ESI,ESI` |
| `10012c58` | `75 01` | `JNZ 0x10012c5b` |
| `10012c5a` | `46` | `INC ESI` |
| `10012c5b` | `56` | `PUSH ESI` |
| `10012c5c` | `53` | `PUSH EBX` |
| `10012c5d` | `6a 00` | `PUSH 0x0` |
| `10012c5f` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `10012c65` | `ff 15 9c e0 02 10` | `CALL dword ptr [0x1002e09c]` |
| `10012c6b` | `8b f8` | `MOV EDI,EAX` |
| `10012c6d` | `85 ff` | `TEST EDI,EDI` |
| `10012c6f` | `75 56` | `JNZ 0x10012cc7` |
| `10012c71` | `39 05 20 92 03 10` | `CMP dword ptr [0x10039220],EAX` |
| `10012c77` | `74 34` | `JZ 0x10012cad` |
| `10012c79` | `56` | `PUSH ESI` |
| `10012c7a` | `e8 60 44 00 00` | `CALL 0x100170df` |
| `10012c7f` | `59` | `POP ECX` |
| `10012c80` | `85 c0` | `TEST EAX,EAX` |
| `10012c82` | `74 1f` | `JZ 0x10012ca3` |
| `10012c84` | `83 fe e0` | `CMP ESI,-0x20` |
| `10012c87` | `76 cd` | `JBE 0x10012c56` |
| `10012c89` | `56` | `PUSH ESI` |
| `10012c8a` | `e8 50 44 00 00` | `CALL 0x100170df` |
| `10012c8f` | `59` | `POP ECX` |
| `10012c90` | `e8 74 24 00 00` | `CALL 0x10015109` |
| `10012c95` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `10012c9b` | `33 c0` | `XOR EAX,EAX` |
| `10012c9d` | `e8 9f 40 00 00` | `CALL 0x10016d41` |
| `10012ca2` | `c3` | `RET` |
| `10012ca3` | `e8 61 24 00 00` | `CALL 0x10015109` |
| `10012ca8` | `e9 7c ff ff ff` | `JMP 0x10012c29` |
| `10012cad` | `85 ff` | `TEST EDI,EDI` |
| `10012caf` | `75 16` | `JNZ 0x10012cc7` |
| `10012cb1` | `e8 53 24 00 00` | `CALL 0x10015109` |
| `10012cb6` | `8b f0` | `MOV ESI,EAX` |
| `10012cb8` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10012cbe` | `50` | `PUSH EAX` |
| `10012cbf` | `e8 03 24 00 00` | `CALL 0x100150c7` |
| `10012cc4` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10012cc6` | `59` | `POP ECX` |
| `10012cc7` | `8b c7` | `MOV EAX,EDI` |
| `10012cc9` | `eb d2` | `JMP 0x10012c9d` |
