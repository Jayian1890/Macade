# 10011b4a `__fread_nolock_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011b4a |
| `name` | __fread_nolock_s |
| `namespace` | Global |
| `signature` | size_t __cdecl __fread_nolock_s(void * _DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE * _File) |
| `size_bytes` | 522 |
| `stack_frame_size` | 44 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fread_nolock_s |

## Decompiled C

```c

/* Library Function - Single Match
    __fread_nolock_s
   
   Library: Visual Studio 2008 Release */

size_t __cdecl
__fread_nolock_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File)

{
  uint uVar1;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *_DstBuf_00;
  uint local_10;
  
  if ((_ElementSize != 0) && (_Count != 0)) {
    if (_DstBuf != (void *)0x0) {
      if ((_File != (FILE *)0x0) && (_Count <= (uint)(0xffffffff / (ulonglong)_ElementSize))) {
LAB_10011bc5:
        uVar8 = _ElementSize * _Count;
        uVar7 = uVar8;
        puVar2 = _DstBuf;
        uVar1 = _DstSize;
        if ((_File->_flag & 0x10cU) == 0) {
          local_10 = 0x1000;
        }
        else {
          local_10 = _File->_bufsiz;
        }
joined_r0x10011beb:
        do {
          while( true ) {
            if (uVar7 == 0) {
              return _Count;
            }
            if ((_File->_flag & 0x10cU) == 0) break;
            uVar4 = _File->_cnt;
            if (uVar4 == 0) break;
            if ((int)uVar4 < 0) {
LAB_10011d3c:
              _File->_flag = _File->_flag | 0x20;
LAB_10011d40:
              return (uVar8 - uVar7) / _ElementSize;
            }
            uVar6 = uVar7;
            if (uVar4 <= uVar7) {
              uVar6 = uVar4;
            }
            if (uVar1 < uVar6) {
              if (_DstSize != 0xffffffff) {
                _memset(_DstBuf,0,_DstSize);
              }
              piVar3 = __errno();
              *piVar3 = 0x22;
              goto LAB_10011b81;
            }
            _memcpy_s(puVar2,uVar1,_File->_ptr,uVar6);
            _File->_cnt = _File->_cnt - uVar6;
            _File->_ptr = _File->_ptr + uVar6;
            uVar7 = uVar7 - uVar6;
            uVar1 = uVar1 - uVar6;
            puVar2 = puVar2 + uVar6;
          }
          if (local_10 <= uVar7) {
            if (local_10 == 0) {
              uVar4 = 0x7fffffff;
              if (uVar7 < 0x80000000) {
                uVar4 = uVar7;
              }
            }
            else {
              if (uVar7 < 0x80000000) {
                uVar6 = uVar7 % local_10;
                uVar4 = uVar7;
              }
              else {
                uVar6 = (uint)(0x7fffffff % (ulonglong)local_10);
                uVar4 = 0x7fffffff;
              }
              uVar4 = uVar4 - uVar6;
            }
            if (uVar1 < uVar4) {
LAB_10011d0f:
              if (_DstSize != 0xffffffff) {
                _memset(_DstBuf,0,_DstSize);
              }
              piVar3 = __errno();
              *piVar3 = 0x22;
              goto LAB_10011b81;
            }
            _DstBuf_00 = puVar2;
            iVar5 = __fileno(_File);
            iVar5 = __read(iVar5,_DstBuf_00,uVar4);
            if (iVar5 == 0) {
              _File->_flag = _File->_flag | 0x10;
              goto LAB_10011d40;
            }
            if (iVar5 == -1) goto LAB_10011d3c;
            uVar7 = uVar7 - iVar5;
            uVar1 = uVar1 - iVar5;
            puVar2 = puVar2 + iVar5;
            goto joined_r0x10011beb;
          }
          iVar5 = __filbuf(_File);
          if (iVar5 == -1) goto LAB_10011d40;
          if (uVar1 == 0) goto LAB_10011d0f;
          *puVar2 = (char)iVar5;
          local_10 = _File->_bufsiz;
          uVar7 = uVar7 - 1;
          uVar1 = uVar1 - 1;
          puVar2 = puVar2 + 1;
        } while( true );
      }
      if (_DstSize != 0xffffffff) {
        _memset(_DstBuf,0,_DstSize);
      }
      if ((_File != (FILE *)0x0) && (_Count <= (uint)(0xffffffff / (ulonglong)_ElementSize)))
      goto LAB_10011bc5;
    }
    piVar3 = __errno();
    *piVar3 = 0x16;
LAB_10011b81:
    __invalid_parameter(0,0,0,0,0);
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011b71` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011b81` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10011bac` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `10011c21` | `10011803` | `UNCONDITIONAL_CALL` | _memcpy_s | `10011803` |
| `10011c81` | `10018c45` | `UNCONDITIONAL_CALL` | __fileno | `10018c45` |
| `10011c88` | `10018b48` | `UNCONDITIONAL_CALL` | __read | `10018b48` |
| `10011cac` | `1001845b` | `UNCONDITIONAL_CALL` | __filbuf | `1001845b` |
| `10011cf2` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `10011cfa` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011d1d` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `10011d25` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `10011dc4` | _fread_s |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011b4a` | `8b ff` | `MOV EDI,EDI` |
| `10011b4c` | `55` | `PUSH EBP` |
| `10011b4d` | `8b ec` | `MOV EBP,ESP` |
| `10011b4f` | `83 ec 10` | `SUB ESP,0x10` |
| `10011b52` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10011b55` | `53` | `PUSH EBX` |
| `10011b56` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `10011b59` | `56` | `PUSH ESI` |
| `10011b5a` | `57` | `PUSH EDI` |
| `10011b5b` | `33 ff` | `XOR EDI,EDI` |
| `10011b5d` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10011b60` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `10011b63` | `39 7d 10` | `CMP dword ptr [EBP + 0x10],EDI` |
| `10011b66` | `74 21` | `JZ 0x10011b89` |
| `10011b68` | `39 7d 14` | `CMP dword ptr [EBP + 0x14],EDI` |
| `10011b6b` | `74 1c` | `JZ 0x10011b89` |
| `10011b6d` | `3b cf` | `CMP ECX,EDI` |
| `10011b6f` | `75 1f` | `JNZ 0x10011b90` |
| `10011b71` | `e8 93 35 00 00` | `CALL 0x10015109` |
| `10011b76` | `57` | `PUSH EDI` |
| `10011b77` | `57` | `PUSH EDI` |
| `10011b78` | `57` | `PUSH EDI` |
| `10011b79` | `57` | `PUSH EDI` |
| `10011b7a` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10011b80` | `57` | `PUSH EDI` |
| `10011b81` | `e8 29 fb ff ff` | `CALL 0x100116af` |
| `10011b86` | `83 c4 14` | `ADD ESP,0x14` |
| `10011b89` | `33 c0` | `XOR EAX,EAX` |
| `10011b8b` | `5f` | `POP EDI` |
| `10011b8c` | `5e` | `POP ESI` |
| `10011b8d` | `5b` | `POP EBX` |
| `10011b8e` | `c9` | `LEAVE` |
| `10011b8f` | `c3` | `RET` |
| `10011b90` | `8b 75 18` | `MOV ESI,dword ptr [EBP + 0x18]` |
| `10011b93` | `3b f7` | `CMP ESI,EDI` |
| `10011b95` | `74 0d` | `JZ 0x10011ba4` |
| `10011b97` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10011b9a` | `33 d2` | `XOR EDX,EDX` |
| `10011b9c` | `f7 75 10` | `DIV dword ptr [EBP + 0x10]` |
| `10011b9f` | `39 45 14` | `CMP dword ptr [EBP + 0x14],EAX` |
| `10011ba2` | `76 21` | `JBE 0x10011bc5` |
| `10011ba4` | `83 fb ff` | `CMP EBX,-0x1` |
| `10011ba7` | `74 0b` | `JZ 0x10011bb4` |
| `10011ba9` | `53` | `PUSH EBX` |
| `10011baa` | `57` | `PUSH EDI` |
| `10011bab` | `51` | `PUSH ECX` |
| `10011bac` | `e8 3f fb ff ff` | `CALL 0x100116f0` |
| `10011bb1` | `83 c4 0c` | `ADD ESP,0xc` |
| `10011bb4` | `3b f7` | `CMP ESI,EDI` |
| `10011bb6` | `74 b9` | `JZ 0x10011b71` |
| `10011bb8` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10011bbb` | `33 d2` | `XOR EDX,EDX` |
| `10011bbd` | `f7 75 10` | `DIV dword ptr [EBP + 0x10]` |
| `10011bc0` | `39 45 14` | `CMP dword ptr [EBP + 0x14],EAX` |
| `10011bc3` | `77 ac` | `JA 0x10011b71` |
| `10011bc5` | `8b 7d 10` | `MOV EDI,dword ptr [EBP + 0x10]` |
| `10011bc8` | `0f af 7d 14` | `IMUL EDI,dword ptr [EBP + 0x14]` |
| `10011bcc` | `f7 46 0c 0c 01 00 00` | `TEST dword ptr [ESI + 0xc],0x10c` |
| `10011bd3` | `89 7d f0` | `MOV dword ptr [EBP + -0x10],EDI` |
| `10011bd6` | `8b df` | `MOV EBX,EDI` |
| `10011bd8` | `74 08` | `JZ 0x10011be2` |
| `10011bda` | `8b 46 18` | `MOV EAX,dword ptr [ESI + 0x18]` |
| `10011bdd` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10011be0` | `eb 07` | `JMP 0x10011be9` |
| `10011be2` | `c7 45 f4 00 10 00 00` | `MOV dword ptr [EBP + -0xc],0x1000` |
| `10011be9` | `85 ff` | `TEST EDI,EDI` |
| `10011beb` | `0f 84 ea 00 00 00` | `JZ 0x10011cdb` |
| `10011bf1` | `f7 46 0c 0c 01 00 00` | `TEST dword ptr [ESI + 0xc],0x10c` |
| `10011bf8` | `74 44` | `JZ 0x10011c3e` |
| `10011bfa` | `8b 46 04` | `MOV EAX,dword ptr [ESI + 0x4]` |
| `10011bfd` | `85 c0` | `TEST EAX,EAX` |
| `10011bff` | `74 3d` | `JZ 0x10011c3e` |
| `10011c01` | `0f 8c 35 01 00 00` | `JL 0x10011d3c` |
| `10011c07` | `8b fb` | `MOV EDI,EBX` |
| `10011c09` | `3b d8` | `CMP EBX,EAX` |
| `10011c0b` | `72 02` | `JC 0x10011c0f` |
| `10011c0d` | `8b f8` | `MOV EDI,EAX` |
| `10011c0f` | `3b 7d fc` | `CMP EDI,dword ptr [EBP + -0x4]` |
| `10011c12` | `0f 87 cb 00 00 00` | `JA 0x10011ce3` |
| `10011c18` | `57` | `PUSH EDI` |
| `10011c19` | `ff 36` | `PUSH dword ptr [ESI]` |
| `10011c1b` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10011c1e` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `10011c21` | `e8 dd fb ff ff` | `CALL 0x10011803` |
| `10011c26` | `29 7e 04` | `SUB dword ptr [ESI + 0x4],EDI` |
| `10011c29` | `01 3e` | `ADD dword ptr [ESI],EDI` |
| `10011c2b` | `01 7d f8` | `ADD dword ptr [EBP + -0x8],EDI` |
| `10011c2e` | `2b df` | `SUB EBX,EDI` |
| `10011c30` | `83 c4 10` | `ADD ESP,0x10` |
| `10011c33` | `29 7d fc` | `SUB dword ptr [EBP + -0x4],EDI` |
| `10011c36` | `8b 7d f0` | `MOV EDI,dword ptr [EBP + -0x10]` |
| `10011c39` | `e9 95 00 00 00` | `JMP 0x10011cd3` |
| `10011c3e` | `3b 5d f4` | `CMP EBX,dword ptr [EBP + -0xc]` |
| `10011c41` | `72 68` | `JC 0x10011cab` |
| `10011c43` | `83 7d f4 00` | `CMP dword ptr [EBP + -0xc],0x0` |
| `10011c47` | `74 1f` | `JZ 0x10011c68` |
| `10011c49` | `b9 ff ff ff 7f` | `MOV ECX,0x7fffffff` |
| `10011c4e` | `33 d2` | `XOR EDX,EDX` |
| `10011c50` | `3b d9` | `CMP EBX,ECX` |
| `10011c52` | `76 09` | `JBE 0x10011c5d` |
| `10011c54` | `8b c1` | `MOV EAX,ECX` |
| `10011c56` | `f7 75 f4` | `DIV dword ptr [EBP + -0xc]` |
| `10011c59` | `8b c1` | `MOV EAX,ECX` |
| `10011c5b` | `eb 07` | `JMP 0x10011c64` |
| `10011c5d` | `8b c3` | `MOV EAX,EBX` |
| `10011c5f` | `f7 75 f4` | `DIV dword ptr [EBP + -0xc]` |
| `10011c62` | `8b c3` | `MOV EAX,EBX` |
| `10011c64` | `2b c2` | `SUB EAX,EDX` |
| `10011c66` | `eb 0b` | `JMP 0x10011c73` |
| `10011c68` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `10011c6d` | `3b d8` | `CMP EBX,EAX` |
| `10011c6f` | `77 02` | `JA 0x10011c73` |
| `10011c71` | `8b c3` | `MOV EAX,EBX` |
| `10011c73` | `3b 45 fc` | `CMP EAX,dword ptr [EBP + -0x4]` |
| `10011c76` | `0f 87 93 00 00 00` | `JA 0x10011d0f` |
| `10011c7c` | `50` | `PUSH EAX` |
| `10011c7d` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `10011c80` | `56` | `PUSH ESI` |
| `10011c81` | `e8 bf 6f 00 00` | `CALL 0x10018c45` |
| `10011c86` | `59` | `POP ECX` |
| `10011c87` | `50` | `PUSH EAX` |
| `10011c88` | `e8 bb 6e 00 00` | `CALL 0x10018b48` |
| `10011c8d` | `83 c4 0c` | `ADD ESP,0xc` |
| `10011c90` | `85 c0` | `TEST EAX,EAX` |
| `10011c92` | `0f 84 b6 00 00 00` | `JZ 0x10011d4e` |
| `10011c98` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10011c9b` | `0f 84 9b 00 00 00` | `JZ 0x10011d3c` |
| `10011ca1` | `01 45 f8` | `ADD dword ptr [EBP + -0x8],EAX` |
| `10011ca4` | `2b d8` | `SUB EBX,EAX` |
| `10011ca6` | `29 45 fc` | `SUB dword ptr [EBP + -0x4],EAX` |
| `10011ca9` | `eb 28` | `JMP 0x10011cd3` |
| `10011cab` | `56` | `PUSH ESI` |
| `10011cac` | `e8 aa 67 00 00` | `CALL 0x1001845b` |
| `10011cb1` | `59` | `POP ECX` |
| `10011cb2` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10011cb5` | `0f 84 85 00 00 00` | `JZ 0x10011d40` |
| `10011cbb` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10011cbf` | `74 4e` | `JZ 0x10011d0f` |
| `10011cc1` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10011cc4` | `ff 45 f8` | `INC dword ptr [EBP + -0x8]` |
| `10011cc7` | `88 01` | `MOV byte ptr [ECX],AL` |
| `10011cc9` | `8b 46 18` | `MOV EAX,dword ptr [ESI + 0x18]` |
| `10011ccc` | `4b` | `DEC EBX` |
| `10011ccd` | `ff 4d fc` | `DEC dword ptr [EBP + -0x4]` |
| `10011cd0` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10011cd3` | `85 db` | `TEST EBX,EBX` |
| `10011cd5` | `0f 85 16 ff ff ff` | `JNZ 0x10011bf1` |
| `10011cdb` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10011cde` | `e9 a8 fe ff ff` | `JMP 0x10011b8b` |
| `10011ce3` | `33 f6` | `XOR ESI,ESI` |
| `10011ce5` | `83 7d 0c ff` | `CMP dword ptr [EBP + 0xc],-0x1` |
| `10011ce9` | `74 0f` | `JZ 0x10011cfa` |
| `10011ceb` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10011cee` | `56` | `PUSH ESI` |
| `10011cef` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10011cf2` | `e8 f9 f9 ff ff` | `CALL 0x100116f0` |
| `10011cf7` | `83 c4 0c` | `ADD ESP,0xc` |
| `10011cfa` | `e8 0a 34 00 00` | `CALL 0x10015109` |
| `10011cff` | `56` | `PUSH ESI` |
| `10011d00` | `56` | `PUSH ESI` |
| `10011d01` | `56` | `PUSH ESI` |
| `10011d02` | `56` | `PUSH ESI` |
| `10011d03` | `c7 00 22 00 00 00` | `MOV dword ptr [EAX],0x22` |
| `10011d09` | `56` | `PUSH ESI` |
| `10011d0a` | `e9 72 fe ff ff` | `JMP 0x10011b81` |
| `10011d0f` | `83 7d 0c ff` | `CMP dword ptr [EBP + 0xc],-0x1` |
| `10011d13` | `74 10` | `JZ 0x10011d25` |
| `10011d15` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10011d18` | `6a 00` | `PUSH 0x0` |
| `10011d1a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10011d1d` | `e8 ce f9 ff ff` | `CALL 0x100116f0` |
| `10011d22` | `83 c4 0c` | `ADD ESP,0xc` |
| `10011d25` | `e8 df 33 00 00` | `CALL 0x10015109` |
| `10011d2a` | `c7 00 22 00 00 00` | `MOV dword ptr [EAX],0x22` |
| `10011d30` | `33 c0` | `XOR EAX,EAX` |
| `10011d32` | `50` | `PUSH EAX` |
| `10011d33` | `50` | `PUSH EAX` |
| `10011d34` | `50` | `PUSH EAX` |
| `10011d35` | `50` | `PUSH EAX` |
| `10011d36` | `50` | `PUSH EAX` |
| `10011d37` | `e9 45 fe ff ff` | `JMP 0x10011b81` |
| `10011d3c` | `83 4e 0c 20` | `OR dword ptr [ESI + 0xc],0x20` |
| `10011d40` | `8b c7` | `MOV EAX,EDI` |
| `10011d42` | `2b c3` | `SUB EAX,EBX` |
| `10011d44` | `33 d2` | `XOR EDX,EDX` |
| `10011d46` | `f7 75 10` | `DIV dword ptr [EBP + 0x10]` |
| `10011d49` | `e9 3d fe ff ff` | `JMP 0x10011b8b` |
| `10011d4e` | `83 4e 0c 10` | `OR dword ptr [ESI + 0xc],0x10` |
| `10011d52` | `eb ec` | `JMP 0x10011d40` |
