# 10010ce0 `_memcpy`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10010ce0 |
| `name` | _memcpy |
| `namespace` | Global |
| `signature` | void * __cdecl _memcpy(void * _Dst, void * _Src, size_t _Size) |
| `size_bytes` | 711 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _memcpy |

## Decompiled C

```c

/* Library Function - Single Match
    _memcpy
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2005 Release, Visual Studio 2008 Debug, Visual
   Studio 2008 Release */

void * __cdecl _memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((_Src < _Dst) && (_Dst < (void *)(_Size + (int)_Src))) {
    puVar4 = (undefined4 *)((_Size - 4) + (int)_Src);
    puVar5 = (undefined4 *)((_Size - 4) + (int)_Dst);
    if (((uint)puVar5 & 3) == 0) {
      uVar2 = _Size >> 2;
      uVar3 = _Size & 3;
      if (7 < uVar2) {
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar5 = puVar5 + -1;
        }
        switch(uVar3) {
        case 0:
          return _Dst;
        case 2:
          goto switchD_10010ec3_caseD_2;
        case 3:
          goto switchD_10010ec3_caseD_3;
        }
        goto switchD_10010ec3_caseD_1;
      }
    }
    else {
      switch(_Size) {
      case 0:
        goto switchD_10010ec3_caseD_0;
      case 1:
        goto switchD_10010ec3_caseD_1;
      case 2:
        goto switchD_10010ec3_caseD_2;
      case 3:
        goto switchD_10010ec3_caseD_3;
      default:
        uVar2 = _Size - ((uint)puVar5 & 3);
        switch((uint)puVar5 & 3) {
        case 1:
          uVar3 = uVar2 & 3;
          *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar4 + 3);
          puVar4 = (undefined4 *)((int)puVar4 + -1);
          uVar2 = uVar2 >> 2;
          puVar5 = (undefined4 *)((int)puVar5 - 1);
          if (7 < uVar2) {
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + -1;
              puVar5 = puVar5 + -1;
            }
            switch(uVar3) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_10010ec3_caseD_2;
            case 3:
              goto switchD_10010ec3_caseD_3;
            }
            goto switchD_10010ec3_caseD_1;
          }
          break;
        case 2:
          uVar3 = uVar2 & 3;
          *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar4 + 3);
          uVar2 = uVar2 >> 2;
          *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)((int)puVar4 + 2);
          puVar4 = (undefined4 *)((int)puVar4 + -2);
          puVar5 = (undefined4 *)((int)puVar5 - 2);
          if (7 < uVar2) {
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + -1;
              puVar5 = puVar5 + -1;
            }
            switch(uVar3) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_10010ec3_caseD_2;
            case 3:
              goto switchD_10010ec3_caseD_3;
            }
            goto switchD_10010ec3_caseD_1;
          }
          break;
        case 3:
          uVar3 = uVar2 & 3;
          *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar4 + 3);
          *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)((int)puVar4 + 2);
          uVar2 = uVar2 >> 2;
          *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)((int)puVar4 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + -3);
          puVar5 = (undefined4 *)((int)puVar5 - 3);
          if (7 < uVar2) {
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + -1;
              puVar5 = puVar5 + -1;
            }
            switch(uVar3) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_10010ec3_caseD_2;
            case 3:
              goto switchD_10010ec3_caseD_3;
            }
            goto switchD_10010ec3_caseD_1;
          }
        }
      }
    }
    switch(uVar2) {
    case 7:
      puVar5[7 - uVar2] = puVar4[7 - uVar2];
    case 6:
      puVar5[6 - uVar2] = puVar4[6 - uVar2];
    case 5:
      puVar5[5 - uVar2] = puVar4[5 - uVar2];
    case 4:
      puVar5[4 - uVar2] = puVar4[4 - uVar2];
    case 3:
      puVar5[3 - uVar2] = puVar4[3 - uVar2];
    case 2:
      puVar5[2 - uVar2] = puVar4[2 - uVar2];
    case 1:
      puVar5[1 - uVar2] = puVar4[1 - uVar2];
      puVar4 = puVar4 + -uVar2;
      puVar5 = puVar5 + -uVar2;
    }
    switch(uVar3) {
    case 1:
switchD_10010ec3_caseD_1:
      *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar4 + 3);
      return _Dst;
    case 2:
switchD_10010ec3_caseD_2:
      *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar4 + 3);
      *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)((int)puVar4 + 2);
      return _Dst;
    case 3:
switchD_10010ec3_caseD_3:
      *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar4 + 3);
      *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)((int)puVar4 + 2);
      *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)((int)puVar4 + 1);
      return _Dst;
    }
switchD_10010ec3_caseD_0:
    return _Dst;
  }
  if (((0xff < _Size) && (DAT_1343a684 != 0)) && (((uint)_Dst & 0xf) == ((uint)_Src & 0xf))) {
    pvVar1 = (void *)__VEC_memcpy();
    return pvVar1;
  }
  puVar4 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    uVar2 = _Size >> 2;
    uVar3 = _Size & 3;
    if (7 < uVar2) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *(undefined4 *)_Src;
        _Src = (undefined4 *)((int)_Src + 4);
        puVar4 = puVar4 + 1;
      }
      switch(uVar3) {
      case 0:
        return _Dst;
      case 2:
        goto switchD_10010d3c_caseD_2;
      case 3:
        goto switchD_10010d3c_caseD_3;
      }
      goto switchD_10010d3c_caseD_1;
    }
  }
  else {
    switch(_Size) {
    case 0:
      goto switchD_10010d3c_caseD_0;
    case 1:
      goto switchD_10010d3c_caseD_1;
    case 2:
      goto switchD_10010d3c_caseD_2;
    case 3:
      goto switchD_10010d3c_caseD_3;
    default:
      uVar2 = (_Size - 4) + ((uint)_Dst & 3);
      switch((uint)_Dst & 3) {
      case 1:
        uVar3 = uVar2 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        uVar2 = uVar2 >> 2;
        *(undefined1 *)((int)_Dst + 2) = *(undefined1 *)((int)_Src + 2);
        _Src = (void *)((int)_Src + 3);
        puVar4 = (undefined4 *)((int)_Dst + 3);
        if (7 < uVar2) {
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar4 = puVar4 + 1;
          }
          switch(uVar3) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_10010d3c_caseD_2;
          case 3:
            goto switchD_10010d3c_caseD_3;
          }
          goto switchD_10010d3c_caseD_1;
        }
        break;
      case 2:
        uVar3 = uVar2 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        uVar2 = uVar2 >> 2;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        _Src = (void *)((int)_Src + 2);
        puVar4 = (undefined4 *)((int)_Dst + 2);
        if (7 < uVar2) {
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar4 = puVar4 + 1;
          }
          switch(uVar3) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_10010d3c_caseD_2;
          case 3:
            goto switchD_10010d3c_caseD_3;
          }
          goto switchD_10010d3c_caseD_1;
        }
        break;
      case 3:
        uVar3 = uVar2 & 3;
        *(undefined1 *)_Dst = *(undefined1 *)_Src;
        _Src = (void *)((int)_Src + 1);
        uVar2 = uVar2 >> 2;
        puVar4 = (undefined4 *)((int)_Dst + 1);
        if (7 < uVar2) {
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = *(undefined4 *)_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar4 = puVar4 + 1;
          }
          switch(uVar3) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_10010d3c_caseD_2;
          case 3:
            goto switchD_10010d3c_caseD_3;
          }
          goto switchD_10010d3c_caseD_1;
        }
      }
    }
  }
  switch(uVar2) {
  case 7:
    puVar4[uVar2 - 7] = *(undefined4 *)((int)_Src + (uVar2 - 7) * 4);
  case 6:
    puVar4[uVar2 - 6] = *(undefined4 *)((int)_Src + (uVar2 - 6) * 4);
  case 5:
    puVar4[uVar2 - 5] = *(undefined4 *)((int)_Src + (uVar2 - 5) * 4);
  case 4:
    puVar4[uVar2 - 4] = *(undefined4 *)((int)_Src + (uVar2 - 4) * 4);
  case 3:
    puVar4[uVar2 - 3] = *(undefined4 *)((int)_Src + (uVar2 - 3) * 4);
  case 2:
    puVar4[uVar2 - 2] = *(undefined4 *)((int)_Src + (uVar2 - 2) * 4);
  case 1:
    puVar4[uVar2 - 1] = *(undefined4 *)((int)_Src + (uVar2 - 1) * 4);
    _Src = (void *)((int)_Src + uVar2 * 4);
    puVar4 = puVar4 + uVar2;
  }
  switch(uVar3) {
  case 1:
switchD_10010d3c_caseD_1:
    *(undefined1 *)puVar4 = *(undefined1 *)_Src;
    return _Dst;
  case 2:
switchD_10010d3c_caseD_2:
    *(undefined1 *)puVar4 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)_Src + 1);
    return _Dst;
  case 3:
switchD_10010d3c_caseD_3:
    *(undefined1 *)puVar4 = *(undefined1 *)_Src;
    *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)_Src + 2);
    return _Dst;
  }
switchD_10010d3c_caseD_0:
  return _Dst;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10010d22` | `10014f25` | `UNCONDITIONAL_CALL` | __VEC_memcpy | `10014f25` |

## Callers

| From | Function |
| --- | --- |
| `10011848` | _memcpy_s |
| `10012b55` | _realloc |
| `10012ba9` | _realloc |
| `1001aa54` | ___crtGetEnvironmentStringsA |
| `10022480` | FUN_10022310 |
| `100267b6` | FUN_10026760 |
| `10019229` | __fwrite_nolock |
| `100226a5` | FUN_100224a0 |
| `10025561` | FUN_100254c0 |
| `10025a0a` | FUN_10025980 |
| `10026ea4` | FUN_10026e20 |
| `10026f22` | FUN_10026e20 |
| `10027701` | FUN_10027660 |
| `1002771a` | FUN_10027660 |
| `100277e9` | FUN_10027730 |
| `10027b2c` | FUN_10027ae0 |
| `10028c76` | FUN_10028b30 |
| `10028d1d` | FUN_10028c90 |
| `1002920a` | FUN_10029160 |
| `10029272` | FUN_10029160 |
| `100297db` | FUN_100295e0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10010d08` | `1343a684` | `READ` | DAT_1343a684 |
| `10010d3c` | `10010e54` | `DATA` | switchD_10010d3c::switchdataD_10010e54 |
| `10010d55` | `10010d6c` | `DATA` | switchD_10010d55::switchdataD_10010d6c |
| `10010d64` | `10010de8` | `DATA` | switchD_10010d64::switchdataD_10010de8 |
| `10010d9a` | `10010e54` | `DATA` | switchD_10010d3c::switchdataD_10010e54 |
| `10010dc0` | `10010e54` | `DATA` | switchD_10010d3c::switchdataD_10010e54 |
| `10010dde` | `10010e54` | `DATA` | switchD_10010d3c::switchdataD_10010e54 |
| `10010e4b` | `10010e54` | `DATA` | switchD_10010d3c::switchdataD_10010e54 |
| `10010ec3` | `10010ff0` | `DATA` | switchD_10010ec3::switchdataD_10010ff0 |
| `10010ece` | `10010fa0` | `DATA` | PTR_caseD_0_10010fa0 |
| `10010ee9` | `10010ef8` | `DATA` | switchD_10010ee9::switchdataD_10010ef8 |
| `10010ef0` | `10010ff0` | `DATA` | switchD_10010ec3::switchdataD_10010ff0 |
| `10010f1e` | `10010ff0` | `DATA` | switchD_10010ec3::switchdataD_10010ff0 |
| `10010f48` | `10010ff0` | `DATA` | switchD_10010ec3::switchdataD_10010ff0 |
| `10010f7a` | `10010ff0` | `DATA` | switchD_10010ec3::switchdataD_10010ff0 |
| `10010fe7` | `10010ff0` | `DATA` | switchD_10010ec3::switchdataD_10010ff0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10010ce0` | `55` | `PUSH EBP` |
| `10010ce1` | `8b ec` | `MOV EBP,ESP` |
| `10010ce3` | `57` | `PUSH EDI` |
| `10010ce4` | `56` | `PUSH ESI` |
| `10010ce5` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10010ce8` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10010ceb` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10010cee` | `8b c1` | `MOV EAX,ECX` |
| `10010cf0` | `8b d1` | `MOV EDX,ECX` |
| `10010cf2` | `03 c6` | `ADD EAX,ESI` |
| `10010cf4` | `3b fe` | `CMP EDI,ESI` |
| `10010cf6` | `76 08` | `JBE 0x10010d00` |
| `10010cf8` | `3b f8` | `CMP EDI,EAX` |
| `10010cfa` | `0f 82 a4 01 00 00` | `JC 0x10010ea4` |
| `10010d00` | `81 f9 00 01 00 00` | `CMP ECX,0x100` |
| `10010d06` | `72 1f` | `JC 0x10010d27` |
| `10010d08` | `83 3d 84 a6 43 13 00` | `CMP dword ptr [0x1343a684],0x0` |
| `10010d0f` | `74 16` | `JZ 0x10010d27` |
| `10010d11` | `57` | `PUSH EDI` |
| `10010d12` | `56` | `PUSH ESI` |
| `10010d13` | `83 e7 0f` | `AND EDI,0xf` |
| `10010d16` | `83 e6 0f` | `AND ESI,0xf` |
| `10010d19` | `3b fe` | `CMP EDI,ESI` |
| `10010d1b` | `5e` | `POP ESI` |
| `10010d1c` | `5f` | `POP EDI` |
| `10010d1d` | `75 08` | `JNZ 0x10010d27` |
| `10010d1f` | `5e` | `POP ESI` |
| `10010d20` | `5f` | `POP EDI` |
| `10010d21` | `5d` | `POP EBP` |
| `10010d22` | `e9 fe 41 00 00` | `JMP 0x10014f25` |
| `10010d27` | `f7 c7 03 00 00 00` | `TEST EDI,0x3` |
| `10010d2d` | `75 15` | `JNZ 0x10010d44` |
| `10010d2f` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010d32` | `83 e2 03` | `AND EDX,0x3` |
| `10010d35` | `83 f9 08` | `CMP ECX,0x8` |
| `10010d38` | `72 2a` | `JC 0x10010d64` |
| `10010d3a` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010d3c` | `ff 24 95 54 0e 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010e54]` |
| `10010d44` | `8b c7` | `MOV EAX,EDI` |
| `10010d46` | `ba 03 00 00 00` | `MOV EDX,0x3` |
| `10010d4b` | `83 e9 04` | `SUB ECX,0x4` |
| `10010d4e` | `72 0c` | `JC 0x10010d5c` |
| `10010d50` | `83 e0 03` | `AND EAX,0x3` |
| `10010d53` | `03 c8` | `ADD ECX,EAX` |
| `10010d55` | `ff 24 85 68 0d 01 10` | `JMP dword ptr [EAX*0x4 + 0x10010d68]` |
| `10010d5c` | `ff 24 8d 64 0e 01 10` | `JMP dword ptr [ECX*0x4 + 0x10010e64]` |
| `10010d64` | `ff 24 8d e8 0d 01 10` | `JMP dword ptr [ECX*0x4 + 0x10010de8]` |
| `10010d78` | `23 d1` | `AND EDX,ECX` |
| `10010d7a` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10010d7c` | `88 07` | `MOV byte ptr [EDI],AL` |
| `10010d7e` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `10010d81` | `88 47 01` | `MOV byte ptr [EDI + 0x1],AL` |
| `10010d84` | `8a 46 02` | `MOV AL,byte ptr [ESI + 0x2]` |
| `10010d87` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010d8a` | `88 47 02` | `MOV byte ptr [EDI + 0x2],AL` |
| `10010d8d` | `83 c6 03` | `ADD ESI,0x3` |
| `10010d90` | `83 c7 03` | `ADD EDI,0x3` |
| `10010d93` | `83 f9 08` | `CMP ECX,0x8` |
| `10010d96` | `72 cc` | `JC 0x10010d64` |
| `10010d98` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010d9a` | `ff 24 95 54 0e 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010e54]` |
| `10010da4` | `23 d1` | `AND EDX,ECX` |
| `10010da6` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10010da8` | `88 07` | `MOV byte ptr [EDI],AL` |
| `10010daa` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `10010dad` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010db0` | `88 47 01` | `MOV byte ptr [EDI + 0x1],AL` |
| `10010db3` | `83 c6 02` | `ADD ESI,0x2` |
| `10010db6` | `83 c7 02` | `ADD EDI,0x2` |
| `10010db9` | `83 f9 08` | `CMP ECX,0x8` |
| `10010dbc` | `72 a6` | `JC 0x10010d64` |
| `10010dbe` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010dc0` | `ff 24 95 54 0e 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010e54]` |
| `10010dc8` | `23 d1` | `AND EDX,ECX` |
| `10010dca` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10010dcc` | `88 07` | `MOV byte ptr [EDI],AL` |
| `10010dce` | `83 c6 01` | `ADD ESI,0x1` |
| `10010dd1` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010dd4` | `83 c7 01` | `ADD EDI,0x1` |
| `10010dd7` | `83 f9 08` | `CMP ECX,0x8` |
| `10010dda` | `72 88` | `JC 0x10010d64` |
| `10010ddc` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010dde` | `ff 24 95 54 0e 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010e54]` |
| `10010e08` | `8b 44 8e e4` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0x1c]` |
| `10010e0c` | `89 44 8f e4` | `MOV dword ptr [EDI + ECX*0x4 + -0x1c],EAX` |
| `10010e10` | `8b 44 8e e8` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0x18]` |
| `10010e14` | `89 44 8f e8` | `MOV dword ptr [EDI + ECX*0x4 + -0x18],EAX` |
| `10010e18` | `8b 44 8e ec` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0x14]` |
| `10010e1c` | `89 44 8f ec` | `MOV dword ptr [EDI + ECX*0x4 + -0x14],EAX` |
| `10010e20` | `8b 44 8e f0` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0x10]` |
| `10010e24` | `89 44 8f f0` | `MOV dword ptr [EDI + ECX*0x4 + -0x10],EAX` |
| `10010e28` | `8b 44 8e f4` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0xc]` |
| `10010e2c` | `89 44 8f f4` | `MOV dword ptr [EDI + ECX*0x4 + -0xc],EAX` |
| `10010e30` | `8b 44 8e f8` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0x8]` |
| `10010e34` | `89 44 8f f8` | `MOV dword ptr [EDI + ECX*0x4 + -0x8],EAX` |
| `10010e38` | `8b 44 8e fc` | `MOV EAX,dword ptr [ESI + ECX*0x4 + -0x4]` |
| `10010e3c` | `89 44 8f fc` | `MOV dword ptr [EDI + ECX*0x4 + -0x4],EAX` |
| `10010e40` | `8d 04 8d 00 00 00 00` | `LEA EAX,[ECX*0x4 + 0x0]` |
| `10010e47` | `03 f0` | `ADD ESI,EAX` |
| `10010e49` | `03 f8` | `ADD EDI,EAX` |
| `10010e4b` | `ff 24 95 54 0e 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010e54]` |
| `10010e64` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10010e67` | `5e` | `POP ESI` |
| `10010e68` | `5f` | `POP EDI` |
| `10010e69` | `c9` | `LEAVE` |
| `10010e6a` | `c3` | `RET` |
| `10010e6c` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10010e6e` | `88 07` | `MOV byte ptr [EDI],AL` |
| `10010e70` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10010e73` | `5e` | `POP ESI` |
| `10010e74` | `5f` | `POP EDI` |
| `10010e75` | `c9` | `LEAVE` |
| `10010e76` | `c3` | `RET` |
| `10010e78` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10010e7a` | `88 07` | `MOV byte ptr [EDI],AL` |
| `10010e7c` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `10010e7f` | `88 47 01` | `MOV byte ptr [EDI + 0x1],AL` |
| `10010e82` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10010e85` | `5e` | `POP ESI` |
| `10010e86` | `5f` | `POP EDI` |
| `10010e87` | `c9` | `LEAVE` |
| `10010e88` | `c3` | `RET` |
| `10010e8c` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10010e8e` | `88 07` | `MOV byte ptr [EDI],AL` |
| `10010e90` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `10010e93` | `88 47 01` | `MOV byte ptr [EDI + 0x1],AL` |
| `10010e96` | `8a 46 02` | `MOV AL,byte ptr [ESI + 0x2]` |
| `10010e99` | `88 47 02` | `MOV byte ptr [EDI + 0x2],AL` |
| `10010e9c` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10010e9f` | `5e` | `POP ESI` |
| `10010ea0` | `5f` | `POP EDI` |
| `10010ea1` | `c9` | `LEAVE` |
| `10010ea2` | `c3` | `RET` |
| `10010ea4` | `8d 74 31 fc` | `LEA ESI,[ECX + ESI*0x1 + -0x4]` |
| `10010ea8` | `8d 7c 39 fc` | `LEA EDI,[ECX + EDI*0x1 + -0x4]` |
| `10010eac` | `f7 c7 03 00 00 00` | `TEST EDI,0x3` |
| `10010eb2` | `75 24` | `JNZ 0x10010ed8` |
| `10010eb4` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010eb7` | `83 e2 03` | `AND EDX,0x3` |
| `10010eba` | `83 f9 08` | `CMP ECX,0x8` |
| `10010ebd` | `72 0d` | `JC 0x10010ecc` |
| `10010ebf` | `fd` | `STD` |
| `10010ec0` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010ec2` | `fc` | `CLD` |
| `10010ec3` | `ff 24 95 f0 0f 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010ff0]` |
| `10010ecc` | `f7 d9` | `NEG ECX` |
| `10010ece` | `ff 24 8d a0 0f 01 10` | `JMP dword ptr [ECX*0x4 + 0x10010fa0]` |
| `10010ed8` | `8b c7` | `MOV EAX,EDI` |
| `10010eda` | `ba 03 00 00 00` | `MOV EDX,0x3` |
| `10010edf` | `83 f9 04` | `CMP ECX,0x4` |
| `10010ee2` | `72 0c` | `JC 0x10010ef0` |
| `10010ee4` | `83 e0 03` | `AND EAX,0x3` |
| `10010ee7` | `2b c8` | `SUB ECX,EAX` |
| `10010ee9` | `ff 24 85 f4 0e 01 10` | `JMP dword ptr [EAX*0x4 + 0x10010ef4]` |
| `10010ef0` | `ff 24 8d f0 0f 01 10` | `JMP dword ptr [ECX*0x4 + 0x10010ff0]` |
| `10010f04` | `8a 46 03` | `MOV AL,byte ptr [ESI + 0x3]` |
| `10010f07` | `23 d1` | `AND EDX,ECX` |
| `10010f09` | `88 47 03` | `MOV byte ptr [EDI + 0x3],AL` |
| `10010f0c` | `83 ee 01` | `SUB ESI,0x1` |
| `10010f0f` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010f12` | `83 ef 01` | `SUB EDI,0x1` |
| `10010f15` | `83 f9 08` | `CMP ECX,0x8` |
| `10010f18` | `72 b2` | `JC 0x10010ecc` |
| `10010f1a` | `fd` | `STD` |
| `10010f1b` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010f1d` | `fc` | `CLD` |
| `10010f1e` | `ff 24 95 f0 0f 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010ff0]` |
| `10010f28` | `8a 46 03` | `MOV AL,byte ptr [ESI + 0x3]` |
| `10010f2b` | `23 d1` | `AND EDX,ECX` |
| `10010f2d` | `88 47 03` | `MOV byte ptr [EDI + 0x3],AL` |
| `10010f30` | `8a 46 02` | `MOV AL,byte ptr [ESI + 0x2]` |
| `10010f33` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010f36` | `88 47 02` | `MOV byte ptr [EDI + 0x2],AL` |
| `10010f39` | `83 ee 02` | `SUB ESI,0x2` |
| `10010f3c` | `83 ef 02` | `SUB EDI,0x2` |
| `10010f3f` | `83 f9 08` | `CMP ECX,0x8` |
| `10010f42` | `72 88` | `JC 0x10010ecc` |
| `10010f44` | `fd` | `STD` |
| `10010f45` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010f47` | `fc` | `CLD` |
| `10010f48` | `ff 24 95 f0 0f 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010ff0]` |
| `10010f50` | `8a 46 03` | `MOV AL,byte ptr [ESI + 0x3]` |
| `10010f53` | `23 d1` | `AND EDX,ECX` |
| `10010f55` | `88 47 03` | `MOV byte ptr [EDI + 0x3],AL` |
| `10010f58` | `8a 46 02` | `MOV AL,byte ptr [ESI + 0x2]` |
| `10010f5b` | `88 47 02` | `MOV byte ptr [EDI + 0x2],AL` |
| `10010f5e` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `10010f61` | `c1 e9 02` | `SHR ECX,0x2` |
| `10010f64` | `88 47 01` | `MOV byte ptr [EDI + 0x1],AL` |
| `10010f67` | `83 ee 03` | `SUB ESI,0x3` |
| `10010f6a` | `83 ef 03` | `SUB EDI,0x3` |
| `10010f6d` | `83 f9 08` | `CMP ECX,0x8` |
| `10010f70` | `0f 82 56 ff ff ff` | `JC 0x10010ecc` |
| `10010f76` | `fd` | `STD` |
| `10010f77` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10010f79` | `fc` | `CLD` |
| `10010f7a` | `ff 24 95 f0 0f 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010ff0]` |
| `10010fa4` | `8b 44 8e 1c` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1c]` |
| `10010fa8` | `89 44 8f 1c` | `MOV dword ptr [EDI + ECX*0x4 + 0x1c],EAX` |
| `10010fac` | `8b 44 8e 18` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0x18]` |
| `10010fb0` | `89 44 8f 18` | `MOV dword ptr [EDI + ECX*0x4 + 0x18],EAX` |
| `10010fb4` | `8b 44 8e 14` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0x14]` |
| `10010fb8` | `89 44 8f 14` | `MOV dword ptr [EDI + ECX*0x4 + 0x14],EAX` |
| `10010fbc` | `8b 44 8e 10` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0x10]` |
| `10010fc0` | `89 44 8f 10` | `MOV dword ptr [EDI + ECX*0x4 + 0x10],EAX` |
| `10010fc4` | `8b 44 8e 0c` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0xc]` |
| `10010fc8` | `89 44 8f 0c` | `MOV dword ptr [EDI + ECX*0x4 + 0xc],EAX` |
| `10010fcc` | `8b 44 8e 08` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0x8]` |
| `10010fd0` | `89 44 8f 08` | `MOV dword ptr [EDI + ECX*0x4 + 0x8],EAX` |
| `10010fd4` | `8b 44 8e 04` | `MOV EAX,dword ptr [ESI + ECX*0x4 + 0x4]` |
| `10010fd8` | `89 44 8f 04` | `MOV dword ptr [EDI + ECX*0x4 + 0x4],EAX` |
| `10010fdc` | `8d 04 8d 00 00 00 00` | `LEA EAX,[ECX*0x4 + 0x0]` |
| `10010fe3` | `03 f0` | `ADD ESI,EAX` |
| `10010fe5` | `03 f8` | `ADD EDI,EAX` |
| `10010fe7` | `ff 24 95 f0 0f 01 10` | `JMP dword ptr [EDX*0x4 + 0x10010ff0]` |
| `10011000` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10011003` | `5e` | `POP ESI` |
| `10011004` | `5f` | `POP EDI` |
| `10011005` | `c9` | `LEAVE` |
| `10011006` | `c3` | `RET` |
| `10011008` | `8a 46 03` | `MOV AL,byte ptr [ESI + 0x3]` |
| `1001100b` | `88 47 03` | `MOV byte ptr [EDI + 0x3],AL` |
| `1001100e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10011011` | `5e` | `POP ESI` |
| `10011012` | `5f` | `POP EDI` |
| `10011013` | `c9` | `LEAVE` |
| `10011014` | `c3` | `RET` |
| `10011018` | `8a 46 03` | `MOV AL,byte ptr [ESI + 0x3]` |
| `1001101b` | `88 47 03` | `MOV byte ptr [EDI + 0x3],AL` |
| `1001101e` | `8a 46 02` | `MOV AL,byte ptr [ESI + 0x2]` |
| `10011021` | `88 47 02` | `MOV byte ptr [EDI + 0x2],AL` |
| `10011024` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10011027` | `5e` | `POP ESI` |
| `10011028` | `5f` | `POP EDI` |
| `10011029` | `c9` | `LEAVE` |
| `1001102a` | `c3` | `RET` |
| `1001102c` | `8a 46 03` | `MOV AL,byte ptr [ESI + 0x3]` |
| `1001102f` | `88 47 03` | `MOV byte ptr [EDI + 0x3],AL` |
| `10011032` | `8a 46 02` | `MOV AL,byte ptr [ESI + 0x2]` |
| `10011035` | `88 47 02` | `MOV byte ptr [EDI + 0x2],AL` |
| `10011038` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `1001103b` | `88 47 01` | `MOV byte ptr [EDI + 0x1],AL` |
| `1001103e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10011041` | `5e` | `POP ESI` |
| `10011042` | `5f` | `POP EDI` |
| `10011043` | `c9` | `LEAVE` |
| `10011044` | `c3` | `RET` |
