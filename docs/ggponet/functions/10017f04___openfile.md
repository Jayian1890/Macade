# 10017f04 `__openfile`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017f04 |
| `name` | __openfile |
| `namespace` | Global |
| `signature` | FILE * __cdecl __openfile(char * _Filename, char * _Mode, int _ShFlag, FILE * _File) |
| `size_bytes` | 713 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __openfile |

## Decompiled C

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __openfile
   
   Library: Visual Studio 2008 Release */

FILE * __cdecl __openfile(char *_Filename,char *_Mode,int _ShFlag,FILE *_File)

{
  char cVar1;
  bool bVar2;
  uchar uVar3;
  int *piVar4;
  int iVar5;
  errno_t eVar6;
  char *pcVar7;
  uchar *puVar8;
  uchar *puVar9;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_10039414;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  for (pcVar7 = _Mode; *pcVar7 == ' '; pcVar7 = pcVar7 + 1) {
  }
  cVar1 = *pcVar7;
  if (cVar1 == 'a') {
    _Mode = (char *)0x109;
LAB_10017f72:
    local_8 = DAT_10039414 | 2;
  }
  else {
    if (cVar1 != 'r') {
      if (cVar1 != 'w') {
        piVar4 = __errno();
        *piVar4 = 0x16;
        __invalid_parameter(0,0,0,0,0);
        return (FILE *)0x0;
      }
      _Mode = (char *)0x301;
      goto LAB_10017f72;
    }
    local_8 = DAT_10039414 | 1;
    _Mode = (char *)0x0;
  }
  bVar2 = true;
  puVar8 = (uchar *)(pcVar7 + 1);
  uVar3 = *puVar8;
  if (uVar3 != '\0') {
    do {
      if (!bVar2) break;
      if ((char)uVar3 < 'T') {
        if (uVar3 == 'S') {
          if (local_c != 0) goto LAB_100180ad;
          _Mode = (char *)((uint)_Mode | 0x20);
          local_c = 1;
        }
        else if (uVar3 != ' ') {
          if (uVar3 == '+') {
            if (((uint)_Mode & 2) != 0) goto LAB_100180ad;
            _Mode = (char *)((uint)_Mode & 0xfffffffe | 2);
            local_8 = local_8 & 0xfffffffc | 0x80;
          }
          else if (uVar3 == ',') {
            local_14 = 1;
LAB_100180ad:
            bVar2 = false;
          }
          else if (uVar3 == 'D') {
            if (((uint)_Mode & 0x40) != 0) goto LAB_100180ad;
            _Mode = (char *)((uint)_Mode | 0x40);
          }
          else if (uVar3 == 'N') {
            _Mode = (char *)((uint)_Mode | 0x80);
          }
          else {
            if (uVar3 != 'R') goto LAB_1001816c;
            if (local_c != 0) goto LAB_100180ad;
            _Mode = (char *)((uint)_Mode | 0x10);
            local_c = 1;
          }
        }
      }
      else if (uVar3 == 'T') {
        if (((uint)_Mode & 0x1000) != 0) goto LAB_100180ad;
        _Mode = (char *)((uint)_Mode | 0x1000);
      }
      else if (uVar3 == 'b') {
        if (((uint)_Mode & 0xc000) != 0) goto LAB_100180ad;
        _Mode = (char *)((uint)_Mode | 0x8000);
      }
      else if (uVar3 == 'c') {
        if (local_10 != 0) goto LAB_100180ad;
        local_8 = local_8 | 0x4000;
        local_10 = 1;
      }
      else if (uVar3 == 'n') {
        if (local_10 != 0) goto LAB_100180ad;
        local_8 = local_8 & 0xffffbfff;
        local_10 = 1;
      }
      else {
        if (uVar3 != 't') goto LAB_1001816c;
        if (((uint)_Mode & 0xc000) != 0) goto LAB_100180ad;
        _Mode = (char *)((uint)_Mode | 0x4000);
      }
      puVar8 = puVar8 + 1;
      uVar3 = *puVar8;
    } while (uVar3 != '\0');
    if (local_14 != 0) {
      for (; *puVar8 == ' '; puVar8 = puVar8 + 1) {
      }
      iVar5 = __mbsnbcmp("ccs",puVar8,3);
      if (iVar5 != 0) goto LAB_1001816c;
      for (puVar8 = puVar8 + 3; *puVar8 == ' '; puVar8 = puVar8 + 1) {
      }
      if (*puVar8 != '=') goto LAB_1001816c;
      do {
        puVar9 = puVar8;
        puVar8 = puVar9 + 1;
      } while (*puVar8 == ' ');
      iVar5 = __mbsnbicmp(puVar8,(uchar *)"UTF-8",5);
      if (iVar5 == 0) {
        puVar8 = puVar9 + 6;
        _Mode = (char *)((uint)_Mode | 0x40000);
      }
      else {
        iVar5 = __mbsnbicmp(puVar8,(uchar *)"UTF-16LE",8);
        if (iVar5 == 0) {
          puVar8 = puVar9 + 9;
          _Mode = (char *)((uint)_Mode | 0x20000);
        }
        else {
          iVar5 = __mbsnbicmp(puVar8,(uchar *)"UNICODE",7);
          if (iVar5 != 0) goto LAB_1001816c;
          puVar8 = puVar9 + 8;
          _Mode = (char *)((uint)_Mode | 0x10000);
        }
      }
    }
  }
  for (; *puVar8 == ' '; puVar8 = puVar8 + 1) {
  }
  if (*puVar8 == '\0') {
    eVar6 = __sopen_s(&local_14,_Filename,(int)_Mode,_ShFlag,0x180);
    if (eVar6 != 0) {
      return (FILE *)0x0;
    }
    _DAT_10039248 = _DAT_10039248 + 1;
    _File->_flag = local_8;
    _File->_cnt = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_tmpfname = (char *)0x0;
    _File->_file = local_14;
    return _File;
  }
LAB_1001816c:
  piVar4 = __errno();
  *piVar4 = 0x16;
  __invalid_parameter(0,0,0,0,0);
  return (FILE *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017f3a` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10017f4a` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `100180dc` | `1001d95d` | `UNCONDITIONAL_CALL` | __mbsnbcmp | `1001d95d` |
| `1001810a` | `1001d7d9` | `UNCONDITIONAL_CALL` | __mbsnbicmp | `1001d7d9` |
| `1001812a` | `1001d7d9` | `UNCONDITIONAL_CALL` | __mbsnbicmp | `1001d7d9` |
| `1001814a` | `1001d7d9` | `UNCONDITIONAL_CALL` | __mbsnbicmp | `1001d7d9` |
| `1001816c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001817c` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10018198` | `1001d58e` | `UNCONDITIONAL_CALL` | __sopen_s | `1001d58e` |

## Callers

| From | Function |
| --- | --- |
| `10011b09` | __fsopen |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `10018104` | `1002f6d0` | `UTF-8` |
| `10018124` | `1002f6d8` | `UTF-16LE` |
| `10018144` | `1002f6e4` | `UNICODE` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017f0c` | `10039414` | `READ` | DAT_10039414 |
| `100180d7` | `1002f6cc` | `DATA` | DAT_1002f6cc |
| `100181ab` | `10039248` | `READ_WRITE` | DAT_10039248 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017f04` | `8b ff` | `MOV EDI,EDI` |
| `10017f06` | `55` | `PUSH EBP` |
| `10017f07` | `8b ec` | `MOV EBP,ESP` |
| `10017f09` | `83 ec 10` | `SUB ESP,0x10` |
| `10017f0c` | `a1 14 94 03 10` | `MOV EAX,[0x10039414]` |
| `10017f11` | `53` | `PUSH EBX` |
| `10017f12` | `33 db` | `XOR EBX,EBX` |
| `10017f14` | `56` | `PUSH ESI` |
| `10017f15` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10017f18` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10017f1b` | `89 5d f4` | `MOV dword ptr [EBP + -0xc],EBX` |
| `10017f1e` | `89 5d f8` | `MOV dword ptr [EBP + -0x8],EBX` |
| `10017f21` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `10017f24` | `eb 01` | `JMP 0x10017f27` |
| `10017f26` | `46` | `INC ESI` |
| `10017f27` | `80 3e 20` | `CMP byte ptr [ESI],0x20` |
| `10017f2a` | `74 fa` | `JZ 0x10017f26` |
| `10017f2c` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10017f2e` | `3c 61` | `CMP AL,0x61` |
| `10017f30` | `74 39` | `JZ 0x10017f6b` |
| `10017f32` | `3c 72` | `CMP AL,0x72` |
| `10017f34` | `74 2c` | `JZ 0x10017f62` |
| `10017f36` | `3c 77` | `CMP AL,0x77` |
| `10017f38` | `74 1f` | `JZ 0x10017f59` |
| `10017f3a` | `e8 ca d1 ff ff` | `CALL 0x10015109` |
| `10017f3f` | `53` | `PUSH EBX` |
| `10017f40` | `53` | `PUSH EBX` |
| `10017f41` | `53` | `PUSH EBX` |
| `10017f42` | `53` | `PUSH EBX` |
| `10017f43` | `53` | `PUSH EBX` |
| `10017f44` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10017f4a` | `e8 60 97 ff ff` | `CALL 0x100116af` |
| `10017f4f` | `83 c4 14` | `ADD ESP,0x14` |
| `10017f52` | `33 c0` | `XOR EAX,EAX` |
| `10017f54` | `e9 70 02 00 00` | `JMP 0x100181c9` |
| `10017f59` | `c7 45 0c 01 03 00 00` | `MOV dword ptr [EBP + 0xc],0x301` |
| `10017f60` | `eb 10` | `JMP 0x10017f72` |
| `10017f62` | `83 4d fc 01` | `OR dword ptr [EBP + -0x4],0x1` |
| `10017f66` | `89 5d 0c` | `MOV dword ptr [EBP + 0xc],EBX` |
| `10017f69` | `eb 0b` | `JMP 0x10017f76` |
| `10017f6b` | `c7 45 0c 09 01 00 00` | `MOV dword ptr [EBP + 0xc],0x109` |
| `10017f72` | `83 4d fc 02` | `OR dword ptr [EBP + -0x4],0x2` |
| `10017f76` | `33 c9` | `XOR ECX,ECX` |
| `10017f78` | `41` | `INC ECX` |
| `10017f79` | `46` | `INC ESI` |
| `10017f7a` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10017f7c` | `57` | `PUSH EDI` |
| `10017f7d` | `3a c3` | `CMP AL,BL` |
| `10017f7f` | `0f 84 de 01 00 00` | `JZ 0x10018163` |
| `10017f85` | `8d 51 7f` | `LEA EDX,[ECX + 0x7f]` |
| `10017f88` | `bf 00 40 00 00` | `MOV EDI,0x4000` |
| `10017f8d` | `3b cb` | `CMP ECX,EBX` |
| `10017f8f` | `0f 84 2e 01 00 00` | `JZ 0x100180c3` |
| `10017f95` | `0f be c0` | `MOVSX EAX,AL` |
| `10017f98` | `83 f8 53` | `CMP EAX,0x53` |
| `10017f9b` | `0f 8f a2 00 00 00` | `JG 0x10018043` |
| `10017fa1` | `0f 84 8a 00 00 00` | `JZ 0x10018031` |
| `10017fa7` | `83 e8 20` | `SUB EAX,0x20` |
| `10017faa` | `0f 84 08 01 00 00` | `JZ 0x100180b8` |
| `10017fb0` | `83 e8 0b` | `SUB EAX,0xb` |
| `10017fb3` | `74 56` | `JZ 0x1001800b` |
| `10017fb5` | `48` | `DEC EAX` |
| `10017fb6` | `74 47` | `JZ 0x10017fff` |
| `10017fb8` | `83 e8 18` | `SUB EAX,0x18` |
| `10017fbb` | `74 2f` | `JZ 0x10017fec` |
| `10017fbd` | `83 e8 0a` | `SUB EAX,0xa` |
| `10017fc0` | `74 22` | `JZ 0x10017fe4` |
| `10017fc2` | `83 e8 04` | `SUB EAX,0x4` |
| `10017fc5` | `0f 85 a1 01 00 00` | `JNZ 0x1001816c` |
| `10017fcb` | `39 5d f8` | `CMP dword ptr [EBP + -0x8],EBX` |
| `10017fce` | `0f 85 d9 00 00 00` | `JNZ 0x100180ad` |
| `10017fd4` | `83 4d 0c 10` | `OR dword ptr [EBP + 0xc],0x10` |
| `10017fd8` | `c7 45 f8 01 00 00 00` | `MOV dword ptr [EBP + -0x8],0x1` |
| `10017fdf` | `e9 d4 00 00 00` | `JMP 0x100180b8` |
| `10017fe4` | `09 55 0c` | `OR dword ptr [EBP + 0xc],EDX` |
| `10017fe7` | `e9 cc 00 00 00` | `JMP 0x100180b8` |
| `10017fec` | `f6 45 0c 40` | `TEST byte ptr [EBP + 0xc],0x40` |
| `10017ff0` | `0f 85 b7 00 00 00` | `JNZ 0x100180ad` |
| `10017ff6` | `83 4d 0c 40` | `OR dword ptr [EBP + 0xc],0x40` |
| `10017ffa` | `e9 b9 00 00 00` | `JMP 0x100180b8` |
| `10017fff` | `c7 45 f0 01 00 00 00` | `MOV dword ptr [EBP + -0x10],0x1` |
| `10018006` | `e9 a2 00 00 00` | `JMP 0x100180ad` |
| `1001800b` | `f6 45 0c 02` | `TEST byte ptr [EBP + 0xc],0x2` |
| `1001800f` | `0f 85 98 00 00 00` | `JNZ 0x100180ad` |
| `10018015` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10018018` | `83 e0 fe` | `AND EAX,0xfffffffe` |
| `1001801b` | `83 c8 02` | `OR EAX,0x2` |
| `1001801e` | `89 45 0c` | `MOV dword ptr [EBP + 0xc],EAX` |
| `10018021` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10018024` | `83 e0 fc` | `AND EAX,0xfffffffc` |
| `10018027` | `0b c2` | `OR EAX,EDX` |
| `10018029` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001802c` | `e9 87 00 00 00` | `JMP 0x100180b8` |
| `10018031` | `39 5d f8` | `CMP dword ptr [EBP + -0x8],EBX` |
| `10018034` | `75 77` | `JNZ 0x100180ad` |
| `10018036` | `83 4d 0c 20` | `OR dword ptr [EBP + 0xc],0x20` |
| `1001803a` | `c7 45 f8 01 00 00 00` | `MOV dword ptr [EBP + -0x8],0x1` |
| `10018041` | `eb 75` | `JMP 0x100180b8` |
| `10018043` | `83 e8 54` | `SUB EAX,0x54` |
| `10018046` | `74 5c` | `JZ 0x100180a4` |
| `10018048` | `83 e8 0e` | `SUB EAX,0xe` |
| `1001804b` | `74 45` | `JZ 0x10018092` |
| `1001804d` | `48` | `DEC EAX` |
| `1001804e` | `74 31` | `JZ 0x10018081` |
| `10018050` | `83 e8 0b` | `SUB EAX,0xb` |
| `10018053` | `74 17` | `JZ 0x1001806c` |
| `10018055` | `83 e8 06` | `SUB EAX,0x6` |
| `10018058` | `0f 85 0e 01 00 00` | `JNZ 0x1001816c` |
| `1001805e` | `f7 45 0c 00 c0 00 00` | `TEST dword ptr [EBP + 0xc],0xc000` |
| `10018065` | `75 46` | `JNZ 0x100180ad` |
| `10018067` | `09 7d 0c` | `OR dword ptr [EBP + 0xc],EDI` |
| `1001806a` | `eb 4c` | `JMP 0x100180b8` |
| `1001806c` | `39 5d f4` | `CMP dword ptr [EBP + -0xc],EBX` |
| `1001806f` | `75 3c` | `JNZ 0x100180ad` |
| `10018071` | `81 65 fc ff bf ff ff` | `AND dword ptr [EBP + -0x4],0xffffbfff` |
| `10018078` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `1001807f` | `eb 37` | `JMP 0x100180b8` |
| `10018081` | `39 5d f4` | `CMP dword ptr [EBP + -0xc],EBX` |
| `10018084` | `75 27` | `JNZ 0x100180ad` |
| `10018086` | `09 7d fc` | `OR dword ptr [EBP + -0x4],EDI` |
| `10018089` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10018090` | `eb 26` | `JMP 0x100180b8` |
| `10018092` | `f7 45 0c 00 c0 00 00` | `TEST dword ptr [EBP + 0xc],0xc000` |
| `10018099` | `75 12` | `JNZ 0x100180ad` |
| `1001809b` | `81 4d 0c 00 80 00 00` | `OR dword ptr [EBP + 0xc],0x8000` |
| `100180a2` | `eb 14` | `JMP 0x100180b8` |
| `100180a4` | `f7 45 0c 00 10 00 00` | `TEST dword ptr [EBP + 0xc],0x1000` |
| `100180ab` | `74 04` | `JZ 0x100180b1` |
| `100180ad` | `33 c9` | `XOR ECX,ECX` |
| `100180af` | `eb 07` | `JMP 0x100180b8` |
| `100180b1` | `81 4d 0c 00 10 00 00` | `OR dword ptr [EBP + 0xc],0x1000` |
| `100180b8` | `46` | `INC ESI` |
| `100180b9` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `100180bb` | `3a c3` | `CMP AL,BL` |
| `100180bd` | `0f 85 ca fe ff ff` | `JNZ 0x10017f8d` |
| `100180c3` | `39 5d f0` | `CMP dword ptr [EBP + -0x10],EBX` |
| `100180c6` | `0f 84 97 00 00 00` | `JZ 0x10018163` |
| `100180cc` | `eb 01` | `JMP 0x100180cf` |
| `100180ce` | `46` | `INC ESI` |
| `100180cf` | `80 3e 20` | `CMP byte ptr [ESI],0x20` |
| `100180d2` | `74 fa` | `JZ 0x100180ce` |
| `100180d4` | `6a 03` | `PUSH 0x3` |
| `100180d6` | `56` | `PUSH ESI` |
| `100180d7` | `68 cc f6 02 10` | `PUSH 0x1002f6cc` |
| `100180dc` | `e8 7c 58 00 00` | `CALL 0x1001d95d` |
| `100180e1` | `83 c4 0c` | `ADD ESP,0xc` |
| `100180e4` | `85 c0` | `TEST EAX,EAX` |
| `100180e6` | `0f 85 80 00 00 00` | `JNZ 0x1001816c` |
| `100180ec` | `83 c6 03` | `ADD ESI,0x3` |
| `100180ef` | `eb 01` | `JMP 0x100180f2` |
| `100180f1` | `46` | `INC ESI` |
| `100180f2` | `80 3e 20` | `CMP byte ptr [ESI],0x20` |
| `100180f5` | `74 fa` | `JZ 0x100180f1` |
| `100180f7` | `80 3e 3d` | `CMP byte ptr [ESI],0x3d` |
| `100180fa` | `75 70` | `JNZ 0x1001816c` |
| `100180fc` | `46` | `INC ESI` |
| `100180fd` | `80 3e 20` | `CMP byte ptr [ESI],0x20` |
| `10018100` | `74 fa` | `JZ 0x100180fc` |
| `10018102` | `6a 05` | `PUSH 0x5` |
| `10018104` | `68 d0 f6 02 10` | `PUSH 0x1002f6d0` |
| `10018109` | `56` | `PUSH ESI` |
| `1001810a` | `e8 ca 56 00 00` | `CALL 0x1001d7d9` |
| `1001810f` | `83 c4 0c` | `ADD ESP,0xc` |
| `10018112` | `85 c0` | `TEST EAX,EAX` |
| `10018114` | `75 0c` | `JNZ 0x10018122` |
| `10018116` | `83 c6 05` | `ADD ESI,0x5` |
| `10018119` | `81 4d 0c 00 00 04 00` | `OR dword ptr [EBP + 0xc],0x40000` |
| `10018120` | `eb 41` | `JMP 0x10018163` |
| `10018122` | `6a 08` | `PUSH 0x8` |
| `10018124` | `68 d8 f6 02 10` | `PUSH 0x1002f6d8` |
| `10018129` | `56` | `PUSH ESI` |
| `1001812a` | `e8 aa 56 00 00` | `CALL 0x1001d7d9` |
| `1001812f` | `83 c4 0c` | `ADD ESP,0xc` |
| `10018132` | `85 c0` | `TEST EAX,EAX` |
| `10018134` | `75 0c` | `JNZ 0x10018142` |
| `10018136` | `83 c6 08` | `ADD ESI,0x8` |
| `10018139` | `81 4d 0c 00 00 02 00` | `OR dword ptr [EBP + 0xc],0x20000` |
| `10018140` | `eb 21` | `JMP 0x10018163` |
| `10018142` | `6a 07` | `PUSH 0x7` |
| `10018144` | `68 e4 f6 02 10` | `PUSH 0x1002f6e4` |
| `10018149` | `56` | `PUSH ESI` |
| `1001814a` | `e8 8a 56 00 00` | `CALL 0x1001d7d9` |
| `1001814f` | `83 c4 0c` | `ADD ESP,0xc` |
| `10018152` | `85 c0` | `TEST EAX,EAX` |
| `10018154` | `75 16` | `JNZ 0x1001816c` |
| `10018156` | `83 c6 07` | `ADD ESI,0x7` |
| `10018159` | `81 4d 0c 00 00 01 00` | `OR dword ptr [EBP + 0xc],0x10000` |
| `10018160` | `eb 01` | `JMP 0x10018163` |
| `10018162` | `46` | `INC ESI` |
| `10018163` | `80 3e 20` | `CMP byte ptr [ESI],0x20` |
| `10018166` | `74 fa` | `JZ 0x10018162` |
| `10018168` | `38 1e` | `CMP byte ptr [ESI],BL` |
| `1001816a` | `74 1a` | `JZ 0x10018186` |
| `1001816c` | `e8 98 cf ff ff` | `CALL 0x10015109` |
| `10018171` | `53` | `PUSH EBX` |
| `10018172` | `53` | `PUSH EBX` |
| `10018173` | `53` | `PUSH EBX` |
| `10018174` | `53` | `PUSH EBX` |
| `10018175` | `53` | `PUSH EBX` |
| `10018176` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001817c` | `e8 2e 95 ff ff` | `CALL 0x100116af` |
| `10018181` | `83 c4 14` | `ADD ESP,0x14` |
| `10018184` | `eb 1e` | `JMP 0x100181a4` |
| `10018186` | `68 80 01 00 00` | `PUSH 0x180` |
| `1001818b` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001818e` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `10018191` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10018194` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10018197` | `50` | `PUSH EAX` |
| `10018198` | `e8 f1 53 00 00` | `CALL 0x1001d58e` |
| `1001819d` | `83 c4 14` | `ADD ESP,0x14` |
| `100181a0` | `85 c0` | `TEST EAX,EAX` |
| `100181a2` | `74 04` | `JZ 0x100181a8` |
| `100181a4` | `33 c0` | `XOR EAX,EAX` |
| `100181a6` | `eb 20` | `JMP 0x100181c8` |
| `100181a8` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `100181ab` | `ff 05 48 92 03 10` | `INC dword ptr [0x10039248]` |
| `100181b1` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100181b4` | `89 48 0c` | `MOV dword ptr [EAX + 0xc],ECX` |
| `100181b7` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `100181ba` | `89 58 04` | `MOV dword ptr [EAX + 0x4],EBX` |
| `100181bd` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `100181bf` | `89 58 08` | `MOV dword ptr [EAX + 0x8],EBX` |
| `100181c2` | `89 58 1c` | `MOV dword ptr [EAX + 0x1c],EBX` |
| `100181c5` | `89 48 10` | `MOV dword ptr [EAX + 0x10],ECX` |
| `100181c8` | `5f` | `POP EDI` |
| `100181c9` | `5e` | `POP ESI` |
| `100181ca` | `5b` | `POP EBX` |
| `100181cb` | `c9` | `LEAVE` |
| `100181cc` | `c3` | `RET` |
