# 100153e3 `__output_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100153e3 |
| `name` | __output_l |
| `namespace` | Global |
| `signature` | int __cdecl __output_l(FILE * _File, char * _Format, _locale_t _Locale, va_list _ArgList) |
| `size_bytes` | 2935 |
| `stack_frame_size` | 656 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __output_l |

## Decompiled C

```c

/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    __output_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __output_l(FILE *_File,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  byte bVar1;
  wchar_t _WCh;
  short *psVar2;
  wchar_t *pwVar3;
  ulonglong uVar4;
  FILE *pFVar5;
  int *piVar6;
  uint uVar7;
  code *pcVar8;
  errno_t eVar9;
  int iVar10;
  undefined *puVar11;
  int extraout_ECX;
  byte *pbVar12;
  size_t sVar13;
  wchar_t *pwVar14;
  bool bVar15;
  longlong lVar16;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  int local_270;
  int local_26c [2];
  size_t local_264;
  localeinfo_struct local_260;
  int local_258;
  char local_254;
  FILE *local_250;
  int local_24c;
  wchar_t *local_248;
  int local_244;
  byte *local_240;
  int local_23c;
  int local_238;
  int local_234;
  undefined1 local_230;
  char local_22f;
  int local_22c;
  wchar_t *local_228;
  size_t local_224;
  wchar_t *local_220;
  int local_21c;
  byte local_215;
  uint local_214;
  wchar_t local_210 [255];
  undefined2 local_11;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_250 = _File;
  local_228 = (wchar_t *)_ArgList;
  local_24c = 0;
  local_214 = 0;
  local_238 = 0;
  local_21c = 0;
  local_234 = 0;
  local_244 = 0;
  local_23c = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_260,_Locale);
  if (_File != (FILE *)0x0) {
    if ((_File->_flag & 0x40) == 0) {
      uVar7 = __fileno(_File);
      if ((uVar7 == 0xffffffff) || (uVar7 == 0xfffffffe)) {
        puVar11 = &DAT_10037b80;
      }
      else {
        puVar11 = (undefined *)((uVar7 & 0x1f) * 0x40 + (&DAT_13439540)[(int)uVar7 >> 5]);
      }
      if ((puVar11[0x24] & 0x7f) == 0) {
        if ((uVar7 == 0xffffffff) || (uVar7 == 0xfffffffe)) {
          puVar11 = &DAT_10037b80;
        }
        else {
          puVar11 = (undefined *)((uVar7 & 0x1f) * 0x40 + (&DAT_13439540)[(int)uVar7 >> 5]);
        }
        if ((puVar11[0x24] & 0x80) == 0) goto LAB_100154e7;
      }
    }
    else {
LAB_100154e7:
      if (_Format != (char *)0x0) {
        local_215 = *_Format;
        local_22c = 0;
        local_224 = 0;
        local_248 = (wchar_t *)0x0;
        iVar10 = 0;
        while ((local_215 != 0 &&
               (pbVar12 = (byte *)(_Format + 1), local_240 = pbVar12, -1 < local_22c))) {
          if ((byte)(local_215 - 0x20) < 0x59) {
            uVar7 = (int)*(char *)((int)&PTR_DAT_1002f028 + (int)(char)local_215) & 0xf;
          }
          else {
            uVar7 = 0;
          }
          local_270 = (int)(char)(&DAT_1002f048)[uVar7 * 8 + iVar10] >> 4;
          switch(local_270) {
          case 0:
switchD_10015560_caseD_0:
            local_23c = 0;
            iVar10 = __isleadbyte_l((uint)local_215,&local_260);
            if (iVar10 != 0) {
              write_char();
              local_240 = (byte *)(_Format + 2);
              if (*pbVar12 == 0) goto LAB_1001544e;
            }
            write_char();
            break;
          case 1:
            local_21c = -1;
            local_274 = 0;
            local_244 = 0;
            local_238 = 0;
            local_234 = 0;
            local_214 = 0;
            local_23c = 0;
            break;
          case 2:
            if (local_215 == 0x20) {
              local_214 = local_214 | 2;
            }
            else if (local_215 == 0x23) {
              local_214 = local_214 | 0x80;
            }
            else if (local_215 == 0x2b) {
              local_214 = local_214 | 1;
            }
            else if (local_215 == 0x2d) {
              local_214 = local_214 | 4;
            }
            else if (local_215 == 0x30) {
              local_214 = local_214 | 8;
            }
            break;
          case 3:
            if (local_215 == 0x2a) {
              local_228 = (wchar_t *)((int)_ArgList + 4);
              local_238 = *(int *)_ArgList;
              if (local_238 < 0) {
                local_214 = local_214 | 4;
                local_238 = -local_238;
              }
            }
            else {
              local_238 = local_238 * 10 + -0x30 + (int)(char)local_215;
            }
            break;
          case 4:
            local_21c = 0;
            break;
          case 5:
            if (local_215 == 0x2a) {
              local_228 = (wchar_t *)((int)_ArgList + 4);
              local_21c = *(int *)_ArgList;
              if (local_21c < 0) {
                local_21c = -1;
              }
            }
            else {
              local_21c = local_21c * 10 + -0x30 + (int)(char)local_215;
            }
            break;
          case 6:
            if (local_215 == 0x49) {
              bVar1 = *pbVar12;
              if ((bVar1 == 0x36) && (_Format[2] == 0x34)) {
                local_214 = local_214 | 0x8000;
                local_240 = (byte *)(_Format + 3);
              }
              else if ((bVar1 == 0x33) && (_Format[2] == 0x32)) {
                local_214 = local_214 & 0xffff7fff;
                local_240 = (byte *)(_Format + 3);
              }
              else if (((((bVar1 != 100) && (bVar1 != 0x69)) && (bVar1 != 0x6f)) &&
                       ((bVar1 != 0x75 && (bVar1 != 0x78)))) && (bVar1 != 0x58)) {
                local_270 = 0;
                goto switchD_10015560_caseD_0;
              }
            }
            else if (local_215 == 0x68) {
              local_214 = local_214 | 0x20;
            }
            else if (local_215 == 0x6c) {
              if (*pbVar12 == 0x6c) {
                local_214 = local_214 | 0x1000;
                local_240 = (byte *)(_Format + 2);
              }
              else {
                local_214 = local_214 | 0x10;
              }
            }
            else if (local_215 == 0x77) {
              local_214 = local_214 | 0x800;
            }
            break;
          case 7:
            if ((char)local_215 < 'e') {
              if (local_215 == 100) {
LAB_10015a4b:
                local_214 = local_214 | 0x40;
LAB_10015a52:
                local_224 = 10;
LAB_10015a5c:
                if (((local_214 & 0x8000) == 0) && ((local_214 & 0x1000) == 0)) {
                  local_228 = (wchar_t *)((int)_ArgList + 4);
                  if ((local_214 & 0x20) == 0) {
                    uVar7 = *(uint *)_ArgList;
                    if ((local_214 & 0x40) == 0) {
                      iVar10 = 0;
                    }
                    else {
                      iVar10 = (int)uVar7 >> 0x1f;
                    }
                  }
                  else {
                    if ((local_214 & 0x40) == 0) {
                      uVar7 = (uint)(ushort)*(wchar_t *)_ArgList;
                    }
                    else {
                      uVar7 = (uint)*(wchar_t *)_ArgList;
                    }
                    iVar10 = (int)uVar7 >> 0x1f;
                  }
                }
                else {
                  uVar7 = *(uint *)_ArgList;
                  iVar10 = *(int *)((int)_ArgList + 4);
                  local_228 = (wchar_t *)((int)_ArgList + 8);
                }
                if ((((local_214 & 0x40) != 0) && (iVar10 < 1)) && (iVar10 < 0)) {
                  bVar15 = uVar7 != 0;
                  uVar7 = -uVar7;
                  iVar10 = -(iVar10 + (uint)bVar15);
                  local_214 = local_214 | 0x100;
                }
                if ((local_214 & 0x9000) == 0) {
                  iVar10 = 0;
                }
                lVar16 = CONCAT44(iVar10,uVar7);
                if (local_21c < 0) {
                  local_21c = 1;
                }
                else {
                  local_214 = local_214 & 0xfffffff7;
                  if (0x200 < local_21c) {
                    local_21c = 0x200;
                  }
                }
                if (uVar7 == 0 && iVar10 == 0) {
                  local_234 = 0;
                }
                pwVar14 = &local_11;
                while( true ) {
                  uVar4 = (ulonglong)lVar16 >> 0x20;
                  iVar10 = local_21c + -1;
                  if ((local_21c < 1) && (lVar16 == 0)) break;
                  local_21c = iVar10;
                  lVar16 = __aulldvrm(lVar16,local_224,(int)local_224 >> 0x1f);
                  iVar10 = extraout_ECX + 0x30;
                  if (0x39 < iVar10) {
                    iVar10 = iVar10 + local_24c;
                  }
                  *(char *)pwVar14 = (char)iVar10;
                  pwVar14 = (wchar_t *)((int)pwVar14 + -1);
                  local_264 = (size_t)uVar4;
                }
                local_224 = (int)&local_11 + -(int)pwVar14;
                local_220 = (wchar_t *)((int)pwVar14 + 1);
                local_21c = iVar10;
                if (((local_214 & 0x200) != 0) && ((local_224 == 0 || (*(char *)local_220 != '0'))))
                {
                  *(char *)pwVar14 = '0';
                  local_224 = (int)&local_11 + -(int)pwVar14 + 1;
                  local_220 = pwVar14;
                }
              }
              else if ((char)local_215 < 'T') {
                if (local_215 == 0x53) {
                  if ((local_214 & 0x830) == 0) {
                    local_214 = local_214 | 0x800;
                  }
                  goto LAB_10015877;
                }
                if (local_215 == 0x41) {
LAB_100157f6:
                  local_215 = local_215 + 0x20;
                  local_274 = 1;
LAB_10015809:
                  local_214 = local_214 | 0x40;
                  local_264 = 0x200;
                  pwVar14 = local_210;
                  sVar13 = local_264;
                  pwVar3 = local_210;
                  if (local_21c < 0) {
                    local_21c = 6;
                  }
                  else if (local_21c == 0) {
                    if (local_215 == 0x67) {
                      local_21c = 1;
                    }
                  }
                  else {
                    if (0x200 < local_21c) {
                      local_21c = 0x200;
                    }
                    if (0xa3 < local_21c) {
                      sVar13 = local_21c + 0x15d;
                      local_220 = local_210;
                      local_248 = __malloc_crt(sVar13);
                      pwVar14 = local_248;
                      pwVar3 = local_248;
                      if (local_248 == (wchar_t *)0x0) {
                        local_21c = 0xa3;
                        pwVar14 = local_210;
                        sVar13 = local_264;
                        pwVar3 = local_220;
                      }
                    }
                  }
                  local_220 = pwVar3;
                  local_264 = sVar13;
                  local_27c = *(undefined4 *)_ArgList;
                  local_228 = (wchar_t *)((int)_ArgList + 8);
                  local_278 = *(undefined4 *)((int)_ArgList + 4);
                  pcVar8 = (code *)__decode_pointer(PTR_LAB_10037bd8,&local_27c,pwVar14,local_264,
                                                    (int)(char)local_215,local_21c,local_274,
                                                    &local_260);
                  (*pcVar8)();
                  uVar7 = local_214 & 0x80;
                  if ((uVar7 != 0) && (local_21c == 0)) {
                    pcVar8 = (code *)__decode_pointer(PTR_LAB_10037be4,pwVar14,&local_260);
                    (*pcVar8)();
                  }
                  if ((local_215 == 0x67) && (uVar7 == 0)) {
                    pcVar8 = (code *)__decode_pointer(PTR_LAB_10037be0,pwVar14,&local_260);
                    (*pcVar8)();
                  }
                  if ((char)*pwVar14 == '-') {
                    local_214 = local_214 | 0x100;
                    local_220 = (wchar_t *)((int)pwVar14 + 1);
                    pwVar14 = local_220;
                  }
LAB_100159a9:
                  local_224 = _strlen((char *)pwVar14);
                }
                else if (local_215 == 0x43) {
                  if ((local_214 & 0x830) == 0) {
                    local_214 = local_214 | 0x800;
                  }
LAB_100158ea:
                  local_228 = (wchar_t *)((int)_ArgList + 4);
                  if ((local_214 & 0x810) == 0) {
                    local_210[0]._0_1_ = (char)*(wchar_t *)_ArgList;
                    local_224 = 1;
                  }
                  else {
                    eVar9 = _wctomb_s((int *)&local_224,(char *)local_210,0x200,*(wchar_t *)_ArgList
                                     );
                    if (eVar9 != 0) {
                      local_244 = 1;
                    }
                  }
                  local_220 = local_210;
                }
                else if ((local_215 == 0x45) || (local_215 == 0x47)) goto LAB_100157f6;
              }
              else {
                if (local_215 == 0x58) goto LAB_10015bb0;
                if (local_215 == 0x5a) {
                  psVar2 = *(short **)_ArgList;
                  local_228 = (wchar_t *)((int)_ArgList + 4);
                  pwVar14 = (wchar_t *)PTR_s__null__10037608;
                  local_220 = (wchar_t *)PTR_s__null__10037608;
                  if ((psVar2 == (short *)0x0) ||
                     (pwVar3 = *(wchar_t **)(psVar2 + 2), pwVar3 == (wchar_t *)0x0))
                  goto LAB_100159a9;
                  local_224 = (size_t)*psVar2;
                  local_220 = pwVar3;
                  if ((local_214 & 0x800) == 0) {
                    local_23c = 0;
                  }
                  else {
                    local_224 = (int)local_224 / 2;
                    local_23c = 1;
                  }
                }
                else {
                  if (local_215 == 0x61) goto LAB_10015809;
                  if (local_215 == 99) goto LAB_100158ea;
                }
              }
LAB_10015d88:
              if (local_244 == 0) {
                if ((local_214 & 0x40) != 0) {
                  if ((local_214 & 0x100) == 0) {
                    if ((local_214 & 1) == 0) {
                      if ((local_214 & 2) == 0) goto LAB_10015dd1;
                      local_230 = 0x20;
                    }
                    else {
                      local_230 = 0x2b;
                    }
                  }
                  else {
                    local_230 = 0x2d;
                  }
                  local_234 = 1;
                }
LAB_10015dd1:
                iVar10 = (local_238 - local_224) - local_234;
                if ((local_214 & 0xc) == 0) {
                  write_multi_char(0x20,iVar10,local_250);
                }
                pFVar5 = local_250;
                write_string(local_234);
                if (((local_214 & 8) != 0) && ((local_214 & 4) == 0)) {
                  write_multi_char(0x30,iVar10,pFVar5);
                }
                if ((local_23c == 0) || ((int)local_224 < 1)) {
                  write_string(local_224);
                }
                else {
                  local_264 = local_224;
                  pwVar14 = local_220;
                  do {
                    _WCh = *pwVar14;
                    local_264 = local_264 - 1;
                    pwVar14 = pwVar14 + 1;
                    eVar9 = _wctomb_s(local_26c,(char *)((int)&local_11 + 1),6,_WCh);
                    if ((eVar9 != 0) || (local_26c[0] == 0)) {
                      local_22c = -1;
                      break;
                    }
                    write_string(local_26c[0]);
                  } while (local_264 != 0);
                }
                if ((-1 < local_22c) && ((local_214 & 4) != 0)) {
                  write_multi_char(0x20,iVar10,pFVar5);
                }
              }
            }
            else {
              if ('p' < (char)local_215) {
                if (local_215 == 0x73) {
LAB_10015877:
                  iVar10 = local_21c;
                  if (local_21c == -1) {
                    iVar10 = 0x7fffffff;
                  }
                  local_228 = (wchar_t *)((int)_ArgList + 4);
                  local_220 = *(wchar_t **)_ArgList;
                  if ((local_214 & 0x810) == 0) {
                    pwVar14 = local_220;
                    if (local_220 == (wchar_t *)0x0) {
                      pwVar14 = (wchar_t *)PTR_s__null__10037608;
                      local_220 = (wchar_t *)PTR_s__null__10037608;
                    }
                    for (; (iVar10 != 0 && (iVar10 = iVar10 + -1, (char)*pwVar14 != '\0'));
                        pwVar14 = (wchar_t *)((int)pwVar14 + 1)) {
                    }
                    local_224 = (int)pwVar14 - (int)local_220;
                  }
                  else {
                    if (local_220 == (wchar_t *)0x0) {
                      local_220 = (wchar_t *)PTR_u__null__1003760c;
                    }
                    local_23c = 1;
                    for (pwVar14 = local_220;
                        (iVar10 != 0 && (iVar10 = iVar10 + -1, *pwVar14 != L'\0'));
                        pwVar14 = pwVar14 + 1) {
                    }
                    local_224 = (int)pwVar14 - (int)local_220 >> 1;
                  }
                  goto LAB_10015d88;
                }
                if (local_215 == 0x75) goto LAB_10015a52;
                if (local_215 != 0x78) goto LAB_10015d88;
                local_24c = 0x27;
LAB_10015bdc:
                local_224 = 0x10;
                if ((local_214 & 0x80) != 0) {
                  local_22f = (char)local_24c + 'Q';
                  local_230 = 0x30;
                  local_234 = 2;
                }
                goto LAB_10015a5c;
              }
              if (local_215 == 0x70) {
                local_21c = 8;
LAB_10015bb0:
                local_24c = 7;
                goto LAB_10015bdc;
              }
              if ((char)local_215 < 'e') goto LAB_10015d88;
              if ((char)local_215 < 'h') goto LAB_10015809;
              if (local_215 == 0x69) goto LAB_10015a4b;
              if (local_215 != 0x6e) {
                if (local_215 != 0x6f) goto LAB_10015d88;
                local_224 = 8;
                if ((local_214 & 0x80) != 0) {
                  local_214 = local_214 | 0x200;
                }
                goto LAB_10015a5c;
              }
              piVar6 = *(int **)_ArgList;
              local_228 = (wchar_t *)((int)_ArgList + 4);
              iVar10 = __get_printf_count_output();
              if (iVar10 == 0) goto LAB_1001544e;
              if ((local_214 & 0x20) == 0) {
                *piVar6 = local_22c;
              }
              else {
                *(undefined2 *)piVar6 = (undefined2)local_22c;
              }
              local_244 = 1;
            }
            if (local_248 != (wchar_t *)0x0) {
              _free(local_248);
              local_248 = (wchar_t *)0x0;
            }
          }
          local_215 = *local_240;
          iVar10 = local_270;
          _Format = (char *)local_240;
          _ArgList = (va_list)local_228;
        }
        if (local_254 != '\0') {
          *(uint *)(local_258 + 0x70) = *(uint *)(local_258 + 0x70) & 0xfffffffd;
        }
        goto LAB_10015f4b;
      }
    }
  }
LAB_1001544e:
  piVar6 = __errno();
  *piVar6 = 0x16;
  __invalid_parameter(0,0,0,0,0);
  if (local_254 != '\0') {
    *(uint *)(local_258 + 0x70) = *(uint *)(local_258 + 0x70) & 0xfffffffd;
  }
LAB_10015f4b:
  iVar10 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10015445` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001544e` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10015460` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001548a` | `10018c45` | `UNCONDITIONAL_CALL` | __fileno | `10018c45` |
| `10015777` | `1001c708` | `UNCONDITIONAL_CALL` | __isleadbyte_l | `1001c708` |
| `10015794` | `1001533d` | `UNCONDITIONAL_CALL` | write_char | `1001533d` |
| `100157b6` | `1001533d` | `UNCONDITIONAL_CALL` | write_char | `1001533d` |
| `10015917` | `1001c6eb` | `UNCONDITIONAL_CALL` | _wctomb_s | `1001c6eb` |
| `100159a9` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `10015a12` | `10012041` | `UNCONDITIONAL_CALL` | __get_printf_count_output | `10012041` |
| `10015ab5` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `10015b2c` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `10015b5b` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `10015b80` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `10015ce7` | `1001c760` | `UNCONDITIONAL_CALL` | __aulldvrm | `1001c760` |
| `10015dfb` | `10015370` | `UNCONDITIONAL_CALL` | write_multi_char | `10015370` |
| `10015e1b` | `10015396` | `UNCONDITIONAL_CALL` | write_string | `10015396` |
| `10015e3d` | `10015370` | `UNCONDITIONAL_CALL` | write_multi_char | `10015370` |
| `10015e7d` | `1001c6eb` | `UNCONDITIONAL_CALL` | _wctomb_s | `1001c6eb` |
| `10015ea0` | `10015396` | `UNCONDITIONAL_CALL` | write_string | `10015396` |
| `10015ec7` | `10015396` | `UNCONDITIONAL_CALL` | write_string | `10015396` |
| `10015ee9` | `10015370` | `UNCONDITIONAL_CALL` | write_multi_char | `10015370` |
| `10015f00` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10015f53` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `100110f7` | _sprintf |
| `10011f50` | __vsprintf_l |
| `10012142` | _fprintf |
| `100199d9` | __vsnprintf_l |
| `10012000` | _printf |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `100158b2` | `1002f02c` | `(null)` |
| `100159a2` | `1002f03c` | `(null)` |
| `100159a8` | `1002f03c` | `(null)` |
| `10015d45` | `1002f02c` | `(null)` |
| `10015d63` | `1002f03c` | `(null)` |
| `10015d72` | `1002f03c` | `(null)` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100153ee` | `10037490` | `READ` | DAT_10037490 |
| `10015490` | `10037b80` | `DATA` | DAT_10037b80 |
| `100154ac` | `13439540` | `DATA` | DAT_13439540 |
| `100154b7` | `10037ba4` | `READ` | DAT_10037ba4 |
| `100154d2` | `13439540` | `DATA` | DAT_13439540 |
| `100154dd` | `10037ba4` | `READ` | DAT_10037ba4 |
| `10015532` | `1002f028` | `DATA` | PTR_DAT_1002f028 |
| `10015544` | `1002f048` | `DATA` | DAT_1002f048 |
| `10015560` | `10015f5b` | `DATA` | switchD_10015560::switchdataD_10015f5b |
| `100158ad` | `1003760c` | `READ` | PTR_u_(null)_1003760c |
| `1001599d` | `10037608` | `READ` | PTR_s_(null)_10037608 |
| `10015b26` | `10037bd8` | `READ` | PTR_LAB_10037bd8 |
| `10015b26` | `1001de8e` | `DATA` | LAB_1001de8e |
| `10015b55` | `10037be4` | `READ` | PTR_LAB_10037be4 |
| `10015b55` | `1001de8e` | `DATA` | LAB_1001de8e |
| `10015b7a` | `10037be0` | `READ` | PTR_LAB_10037be0 |
| `10015b7a` | `1001de8e` | `DATA` | LAB_1001de8e |
| `10015d5e` | `10037608` | `READ` | PTR_s_(null)_10037608 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100153e3` | `8b ff` | `MOV EDI,EDI` |
| `100153e5` | `55` | `PUSH EBP` |
| `100153e6` | `8b ec` | `MOV EBP,ESP` |
| `100153e8` | `81 ec 78 02 00 00` | `SUB ESP,0x278` |
| `100153ee` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `100153f3` | `33 c5` | `XOR EAX,EBP` |
| `100153f5` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `100153f8` | `53` | `PUSH EBX` |
| `100153f9` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `100153fc` | `56` | `PUSH ESI` |
| `100153fd` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10015400` | `33 c0` | `XOR EAX,EAX` |
| `10015402` | `57` | `PUSH EDI` |
| `10015403` | `8b 7d 14` | `MOV EDI,dword ptr [EBP + 0x14]` |
| `10015406` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10015409` | `8d 8d a4 fd ff ff` | `LEA ECX,[EBP + 0xfffffda4]` |
| `1001540f` | `89 b5 b4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdb4],ESI` |
| `10015415` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `1001541b` | `89 85 b8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdb8],EAX` |
| `10015421` | `89 85 f0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdf0],EAX` |
| `10015427` | `89 85 cc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdcc],EAX` |
| `1001542d` | `89 85 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],EAX` |
| `10015433` | `89 85 d0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd0],EAX` |
| `10015439` | `89 85 c0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc0],EAX` |
| `1001543f` | `89 85 c8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc8],EAX` |
| `10015445` | `e8 6c fe ff ff` | `CALL 0x100152b6` |
| `1001544a` | `85 f6` | `TEST ESI,ESI` |
| `1001544c` | `75 35` | `JNZ 0x10015483` |
| `1001544e` | `e8 b6 fc ff ff` | `CALL 0x10015109` |
| `10015453` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10015459` | `33 c0` | `XOR EAX,EAX` |
| `1001545b` | `50` | `PUSH EAX` |
| `1001545c` | `50` | `PUSH EAX` |
| `1001545d` | `50` | `PUSH EAX` |
| `1001545e` | `50` | `PUSH EAX` |
| `1001545f` | `50` | `PUSH EAX` |
| `10015460` | `e8 4a c2 ff ff` | `CALL 0x100116af` |
| `10015465` | `83 c4 14` | `ADD ESP,0x14` |
| `10015468` | `80 bd b0 fd ff ff 00` | `CMP byte ptr [EBP + 0xfffffdb0],0x0` |
| `1001546f` | `74 0a` | `JZ 0x1001547b` |
| `10015471` | `8b 85 ac fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffdac]` |
| `10015477` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001547b` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001547e` | `e9 c8 0a 00 00` | `JMP 0x10015f4b` |
| `10015483` | `f6 46 0c 40` | `TEST byte ptr [ESI + 0xc],0x40` |
| `10015487` | `75 5e` | `JNZ 0x100154e7` |
| `10015489` | `56` | `PUSH ESI` |
| `1001548a` | `e8 b6 37 00 00` | `CALL 0x10018c45` |
| `1001548f` | `59` | `POP ECX` |
| `10015490` | `ba 80 7b 03 10` | `MOV EDX,0x10037b80` |
| `10015495` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10015498` | `74 1b` | `JZ 0x100154b5` |
| `1001549a` | `83 f8 fe` | `CMP EAX,-0x2` |
| `1001549d` | `74 16` | `JZ 0x100154b5` |
| `1001549f` | `8b c8` | `MOV ECX,EAX` |
| `100154a1` | `83 e1 1f` | `AND ECX,0x1f` |
| `100154a4` | `8b f0` | `MOV ESI,EAX` |
| `100154a6` | `c1 fe 05` | `SAR ESI,0x5` |
| `100154a9` | `c1 e1 06` | `SHL ECX,0x6` |
| `100154ac` | `03 0c b5 40 95 43 13` | `ADD ECX,dword ptr [ESI*0x4 + 0x13439540]` |
| `100154b3` | `eb 02` | `JMP 0x100154b7` |
| `100154b5` | `8b ca` | `MOV ECX,EDX` |
| `100154b7` | `f6 41 24 7f` | `TEST byte ptr [ECX + 0x24],0x7f` |
| `100154bb` | `75 91` | `JNZ 0x1001544e` |
| `100154bd` | `83 f8 ff` | `CMP EAX,-0x1` |
| `100154c0` | `74 19` | `JZ 0x100154db` |
| `100154c2` | `83 f8 fe` | `CMP EAX,-0x2` |
| `100154c5` | `74 14` | `JZ 0x100154db` |
| `100154c7` | `8b c8` | `MOV ECX,EAX` |
| `100154c9` | `83 e0 1f` | `AND EAX,0x1f` |
| `100154cc` | `c1 f9 05` | `SAR ECX,0x5` |
| `100154cf` | `c1 e0 06` | `SHL EAX,0x6` |
| `100154d2` | `03 04 8d 40 95 43 13` | `ADD EAX,dword ptr [ECX*0x4 + 0x13439540]` |
| `100154d9` | `eb 02` | `JMP 0x100154dd` |
| `100154db` | `8b c2` | `MOV EAX,EDX` |
| `100154dd` | `f6 40 24 80` | `TEST byte ptr [EAX + 0x24],0x80` |
| `100154e1` | `0f 85 67 ff ff ff` | `JNZ 0x1001544e` |
| `100154e7` | `33 c9` | `XOR ECX,ECX` |
| `100154e9` | `3b d9` | `CMP EBX,ECX` |
| `100154eb` | `0f 84 5d ff ff ff` | `JZ 0x1001544e` |
| `100154f1` | `8a 13` | `MOV DL,byte ptr [EBX]` |
| `100154f3` | `89 8d d8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd8],ECX` |
| `100154f9` | `89 8d e0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde0],ECX` |
| `100154ff` | `89 8d bc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdbc],ECX` |
| `10015505` | `88 95 ef fd ff ff` | `MOV byte ptr [EBP + 0xfffffdef],DL` |
| `1001550b` | `84 d2` | `TEST DL,DL` |
| `1001550d` | `0f 84 1f 0a 00 00` | `JZ 0x10015f32` |
| `10015513` | `43` | `INC EBX` |
| `10015514` | `83 bd d8 fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffdd8],0x0` |
| `1001551b` | `89 9d c4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc4],EBX` |
| `10015521` | `0f 8c 0b 0a 00 00` | `JL 0x10015f32` |
| `10015527` | `8a c2` | `MOV AL,DL` |
| `10015529` | `2c 20` | `SUB AL,0x20` |
| `1001552b` | `3c 58` | `CMP AL,0x58` |
| `1001552d` | `77 11` | `JA 0x10015540` |
| `1001552f` | `0f be c2` | `MOVSX EAX,DL` |
| `10015532` | `0f be 80 28 f0 02 10` | `MOVSX EAX,byte ptr [EAX + 0x1002f028]` |
| `10015539` | `83 e0 0f` | `AND EAX,0xf` |
| `1001553c` | `33 f6` | `XOR ESI,ESI` |
| `1001553e` | `eb 04` | `JMP 0x10015544` |
| `10015540` | `33 f6` | `XOR ESI,ESI` |
| `10015542` | `33 c0` | `XOR EAX,EAX` |
| `10015544` | `0f be 84 c1 48 f0 02 10` | `MOVSX EAX,byte ptr [ECX + EAX*0x8 + 0x1002f048]` |
| `1001554c` | `6a 07` | `PUSH 0x7` |
| `1001554e` | `c1 f8 04` | `SAR EAX,0x4` |
| `10015551` | `59` | `POP ECX` |
| `10015552` | `89 85 94 fd ff ff` | `MOV dword ptr [EBP + 0xfffffd94],EAX` |
| `10015558` | `3b c1` | `CMP EAX,ECX` |
| `1001555a` | `0f 87 ad 09 00 00` | `JA 0x10015f0d` |
| `10015560` | `ff 24 85 5b 5f 01 10` | `JMP dword ptr [EAX*0x4 + 0x10015f5b]` |
| `10015567` | `83 8d e8 fd ff ff ff` | `OR dword ptr [EBP + 0xfffffde8],0xffffffff` |
| `1001556e` | `89 b5 90 fd ff ff` | `MOV dword ptr [EBP + 0xfffffd90],ESI` |
| `10015574` | `89 b5 c0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc0],ESI` |
| `1001557a` | `89 b5 cc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdcc],ESI` |
| `10015580` | `89 b5 d0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdd0],ESI` |
| `10015586` | `89 b5 f0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdf0],ESI` |
| `1001558c` | `89 b5 c8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc8],ESI` |
| `10015592` | `e9 76 09 00 00` | `JMP 0x10015f0d` |
| `10015597` | `0f be c2` | `MOVSX EAX,DL` |
| `1001559a` | `83 e8 20` | `SUB EAX,0x20` |
| `1001559d` | `74 4a` | `JZ 0x100155e9` |
| `1001559f` | `83 e8 03` | `SUB EAX,0x3` |
| `100155a2` | `74 36` | `JZ 0x100155da` |
| `100155a4` | `83 e8 08` | `SUB EAX,0x8` |
| `100155a7` | `74 25` | `JZ 0x100155ce` |
| `100155a9` | `48` | `DEC EAX` |
| `100155aa` | `48` | `DEC EAX` |
| `100155ab` | `74 15` | `JZ 0x100155c2` |
| `100155ad` | `83 e8 03` | `SUB EAX,0x3` |
| `100155b0` | `0f 85 57 09 00 00` | `JNZ 0x10015f0d` |
| `100155b6` | `83 8d f0 fd ff ff 08` | `OR dword ptr [EBP + 0xfffffdf0],0x8` |
| `100155bd` | `e9 4b 09 00 00` | `JMP 0x10015f0d` |
| `100155c2` | `83 8d f0 fd ff ff 04` | `OR dword ptr [EBP + 0xfffffdf0],0x4` |
| `100155c9` | `e9 3f 09 00 00` | `JMP 0x10015f0d` |
| `100155ce` | `83 8d f0 fd ff ff 01` | `OR dword ptr [EBP + 0xfffffdf0],0x1` |
| `100155d5` | `e9 33 09 00 00` | `JMP 0x10015f0d` |
| `100155da` | `81 8d f0 fd ff ff 80 00 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x80` |
| `100155e4` | `e9 24 09 00 00` | `JMP 0x10015f0d` |
| `100155e9` | `83 8d f0 fd ff ff 02` | `OR dword ptr [EBP + 0xfffffdf0],0x2` |
| `100155f0` | `e9 18 09 00 00` | `JMP 0x10015f0d` |
| `100155f5` | `80 fa 2a` | `CMP DL,0x2a` |
| `100155f8` | `75 2c` | `JNZ 0x10015626` |
| `100155fa` | `83 c7 04` | `ADD EDI,0x4` |
| `100155fd` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `10015603` | `8b 7f fc` | `MOV EDI,dword ptr [EDI + -0x4]` |
| `10015606` | `3b fe` | `CMP EDI,ESI` |
| `10015608` | `89 bd cc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdcc],EDI` |
| `1001560e` | `0f 8d f9 08 00 00` | `JGE 0x10015f0d` |
| `10015614` | `83 8d f0 fd ff ff 04` | `OR dword ptr [EBP + 0xfffffdf0],0x4` |
| `1001561b` | `f7 9d cc fd ff ff` | `NEG dword ptr [EBP + 0xfffffdcc]` |
| `10015621` | `e9 e7 08 00 00` | `JMP 0x10015f0d` |
| `10015626` | `8b 85 cc fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffdcc]` |
| `1001562c` | `6b c0 0a` | `IMUL EAX,EAX,0xa` |
| `1001562f` | `0f be ca` | `MOVSX ECX,DL` |
| `10015632` | `8d 44 08 d0` | `LEA EAX,[EAX + ECX*0x1 + -0x30]` |
| `10015636` | `89 85 cc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdcc],EAX` |
| `1001563c` | `e9 cc 08 00 00` | `JMP 0x10015f0d` |
| `10015641` | `89 b5 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],ESI` |
| `10015647` | `e9 c1 08 00 00` | `JMP 0x10015f0d` |
| `1001564c` | `80 fa 2a` | `CMP DL,0x2a` |
| `1001564f` | `75 26` | `JNZ 0x10015677` |
| `10015651` | `83 c7 04` | `ADD EDI,0x4` |
| `10015654` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `1001565a` | `8b 7f fc` | `MOV EDI,dword ptr [EDI + -0x4]` |
| `1001565d` | `3b fe` | `CMP EDI,ESI` |
| `1001565f` | `89 bd e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],EDI` |
| `10015665` | `0f 8d a2 08 00 00` | `JGE 0x10015f0d` |
| `1001566b` | `83 8d e8 fd ff ff ff` | `OR dword ptr [EBP + 0xfffffde8],0xffffffff` |
| `10015672` | `e9 96 08 00 00` | `JMP 0x10015f0d` |
| `10015677` | `8b 85 e8 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffde8]` |
| `1001567d` | `6b c0 0a` | `IMUL EAX,EAX,0xa` |
| `10015680` | `0f be ca` | `MOVSX ECX,DL` |
| `10015683` | `8d 44 08 d0` | `LEA EAX,[EAX + ECX*0x1 + -0x30]` |
| `10015687` | `89 85 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],EAX` |
| `1001568d` | `e9 7b 08 00 00` | `JMP 0x10015f0d` |
| `10015692` | `80 fa 49` | `CMP DL,0x49` |
| `10015695` | `74 55` | `JZ 0x100156ec` |
| `10015697` | `80 fa 68` | `CMP DL,0x68` |
| `1001569a` | `74 44` | `JZ 0x100156e0` |
| `1001569c` | `80 fa 6c` | `CMP DL,0x6c` |
| `1001569f` | `74 18` | `JZ 0x100156b9` |
| `100156a1` | `80 fa 77` | `CMP DL,0x77` |
| `100156a4` | `0f 85 63 08 00 00` | `JNZ 0x10015f0d` |
| `100156aa` | `81 8d f0 fd ff ff 00 08 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x800` |
| `100156b4` | `e9 54 08 00 00` | `JMP 0x10015f0d` |
| `100156b9` | `80 3b 6c` | `CMP byte ptr [EBX],0x6c` |
| `100156bc` | `75 16` | `JNZ 0x100156d4` |
| `100156be` | `43` | `INC EBX` |
| `100156bf` | `81 8d f0 fd ff ff 00 10 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x1000` |
| `100156c9` | `89 9d c4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc4],EBX` |
| `100156cf` | `e9 39 08 00 00` | `JMP 0x10015f0d` |
| `100156d4` | `83 8d f0 fd ff ff 10` | `OR dword ptr [EBP + 0xfffffdf0],0x10` |
| `100156db` | `e9 2d 08 00 00` | `JMP 0x10015f0d` |
| `100156e0` | `83 8d f0 fd ff ff 20` | `OR dword ptr [EBP + 0xfffffdf0],0x20` |
| `100156e7` | `e9 21 08 00 00` | `JMP 0x10015f0d` |
| `100156ec` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `100156ee` | `3c 36` | `CMP AL,0x36` |
| `100156f0` | `75 1d` | `JNZ 0x1001570f` |
| `100156f2` | `80 7b 01 34` | `CMP byte ptr [EBX + 0x1],0x34` |
| `100156f6` | `75 17` | `JNZ 0x1001570f` |
| `100156f8` | `43` | `INC EBX` |
| `100156f9` | `43` | `INC EBX` |
| `100156fa` | `81 8d f0 fd ff ff 00 80 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x8000` |
| `10015704` | `89 9d c4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc4],EBX` |
| `1001570a` | `e9 fe 07 00 00` | `JMP 0x10015f0d` |
| `1001570f` | `3c 33` | `CMP AL,0x33` |
| `10015711` | `75 1d` | `JNZ 0x10015730` |
| `10015713` | `80 7b 01 32` | `CMP byte ptr [EBX + 0x1],0x32` |
| `10015717` | `75 17` | `JNZ 0x10015730` |
| `10015719` | `43` | `INC EBX` |
| `1001571a` | `43` | `INC EBX` |
| `1001571b` | `81 a5 f0 fd ff ff ff 7f ff ff` | `AND dword ptr [EBP + 0xfffffdf0],0xffff7fff` |
| `10015725` | `89 9d c4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc4],EBX` |
| `1001572b` | `e9 dd 07 00 00` | `JMP 0x10015f0d` |
| `10015730` | `3c 64` | `CMP AL,0x64` |
| `10015732` | `0f 84 d5 07 00 00` | `JZ 0x10015f0d` |
| `10015738` | `3c 69` | `CMP AL,0x69` |
| `1001573a` | `0f 84 cd 07 00 00` | `JZ 0x10015f0d` |
| `10015740` | `3c 6f` | `CMP AL,0x6f` |
| `10015742` | `0f 84 c5 07 00 00` | `JZ 0x10015f0d` |
| `10015748` | `3c 75` | `CMP AL,0x75` |
| `1001574a` | `0f 84 bd 07 00 00` | `JZ 0x10015f0d` |
| `10015750` | `3c 78` | `CMP AL,0x78` |
| `10015752` | `0f 84 b5 07 00 00` | `JZ 0x10015f0d` |
| `10015758` | `3c 58` | `CMP AL,0x58` |
| `1001575a` | `0f 84 ad 07 00 00` | `JZ 0x10015f0d` |
| `10015760` | `89 b5 94 fd ff ff` | `MOV dword ptr [EBP + 0xfffffd94],ESI` |
| `10015766` | `8d 85 a4 fd ff ff` | `LEA EAX,[EBP + 0xfffffda4]` |
| `1001576c` | `50` | `PUSH EAX` |
| `1001576d` | `0f b6 c2` | `MOVZX EAX,DL` |
| `10015770` | `50` | `PUSH EAX` |
| `10015771` | `89 b5 c8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc8],ESI` |
| `10015777` | `e8 8c 6f 00 00` | `CALL 0x1001c708` |
| `1001577c` | `59` | `POP ECX` |
| `1001577d` | `85 c0` | `TEST EAX,EAX` |
| `1001577f` | `8a 85 ef fd ff ff` | `MOV AL,byte ptr [EBP + 0xfffffdef]` |
| `10015785` | `59` | `POP ECX` |
| `10015786` | `74 22` | `JZ 0x100157aa` |
| `10015788` | `8b 8d b4 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffdb4]` |
| `1001578e` | `8d b5 d8 fd ff ff` | `LEA ESI,[EBP + 0xfffffdd8]` |
| `10015794` | `e8 a4 fb ff ff` | `CALL 0x1001533d` |
| `10015799` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `1001579b` | `43` | `INC EBX` |
| `1001579c` | `89 9d c4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc4],EBX` |
| `100157a2` | `84 c0` | `TEST AL,AL` |
| `100157a4` | `0f 84 a4 fc ff ff` | `JZ 0x1001544e` |
| `100157aa` | `8b 8d b4 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffdb4]` |
| `100157b0` | `8d b5 d8 fd ff ff` | `LEA ESI,[EBP + 0xfffffdd8]` |
| `100157b6` | `e8 82 fb ff ff` | `CALL 0x1001533d` |
| `100157bb` | `e9 4d 07 00 00` | `JMP 0x10015f0d` |
| `100157c0` | `0f be c2` | `MOVSX EAX,DL` |
| `100157c3` | `83 f8 64` | `CMP EAX,0x64` |
| `100157c6` | `0f 8f e8 01 00 00` | `JG 0x100159b4` |
| `100157cc` | `0f 84 79 02 00 00` | `JZ 0x10015a4b` |
| `100157d2` | `83 f8 53` | `CMP EAX,0x53` |
| `100157d5` | `0f 8f f2 00 00 00` | `JG 0x100158cd` |
| `100157db` | `0f 84 80 00 00 00` | `JZ 0x10015861` |
| `100157e1` | `83 e8 41` | `SUB EAX,0x41` |
| `100157e4` | `74 10` | `JZ 0x100157f6` |
| `100157e6` | `48` | `DEC EAX` |
| `100157e7` | `48` | `DEC EAX` |
| `100157e8` | `74 58` | `JZ 0x10015842` |
| `100157ea` | `48` | `DEC EAX` |
| `100157eb` | `48` | `DEC EAX` |
| `100157ec` | `74 08` | `JZ 0x100157f6` |
| `100157ee` | `48` | `DEC EAX` |
| `100157ef` | `48` | `DEC EAX` |
| `100157f0` | `0f 85 92 05 00 00` | `JNZ 0x10015d88` |
| `100157f6` | `80 c2 20` | `ADD DL,0x20` |
| `100157f9` | `c7 85 90 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffd90],0x1` |
| `10015803` | `88 95 ef fd ff ff` | `MOV byte ptr [EBP + 0xfffffdef],DL` |
| `10015809` | `83 8d f0 fd ff ff 40` | `OR dword ptr [EBP + 0xfffffdf0],0x40` |
| `10015810` | `39 b5 e8 fd ff ff` | `CMP dword ptr [EBP + 0xfffffde8],ESI` |
| `10015816` | `8d 9d f4 fd ff ff` | `LEA EBX,[EBP + 0xfffffdf4]` |
| `1001581c` | `b8 00 02 00 00` | `MOV EAX,0x200` |
| `10015821` | `89 9d e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EBX` |
| `10015827` | `89 85 a0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffda0],EAX` |
| `1001582d` | `0f 8d 48 02 00 00` | `JGE 0x10015a7b` |
| `10015833` | `c7 85 e8 fd ff ff 06 00 00 00` | `MOV dword ptr [EBP + 0xfffffde8],0x6` |
| `1001583d` | `e9 a5 02 00 00` | `JMP 0x10015ae7` |
| `10015842` | `f7 85 f0 fd ff ff 30 08 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x830` |
| `1001584c` | `0f 85 98 00 00 00` | `JNZ 0x100158ea` |
| `10015852` | `81 8d f0 fd ff ff 00 08 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x800` |
| `1001585c` | `e9 89 00 00 00` | `JMP 0x100158ea` |
| `10015861` | `f7 85 f0 fd ff ff 30 08 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x830` |
| `1001586b` | `75 0a` | `JNZ 0x10015877` |
| `1001586d` | `81 8d f0 fd ff ff 00 08 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x800` |
| `10015877` | `8b 8d e8 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffde8]` |
| `1001587d` | `83 f9 ff` | `CMP ECX,-0x1` |
| `10015880` | `75 05` | `JNZ 0x10015887` |
| `10015882` | `b9 ff ff ff 7f` | `MOV ECX,0x7fffffff` |
| `10015887` | `83 c7 04` | `ADD EDI,0x4` |
| `1001588a` | `f7 85 f0 fd ff ff 10 08 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x810` |
| `10015894` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `1001589a` | `8b 7f fc` | `MOV EDI,dword ptr [EDI + -0x4]` |
| `1001589d` | `89 bd e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EDI` |
| `100158a3` | `0f 84 b1 04 00 00` | `JZ 0x10015d5a` |
| `100158a9` | `3b fe` | `CMP EDI,ESI` |
| `100158ab` | `75 0b` | `JNZ 0x100158b8` |
| `100158ad` | `a1 0c 76 03 10` | `MOV EAX,[0x1003760c]` |
| `100158b2` | `89 85 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EAX` |
| `100158b8` | `8b 85 e4 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffde4]` |
| `100158be` | `c7 85 c8 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffdc8],0x1` |
| `100158c8` | `e9 7f 04 00 00` | `JMP 0x10015d4c` |
| `100158cd` | `83 e8 58` | `SUB EAX,0x58` |
| `100158d0` | `0f 84 da 02 00 00` | `JZ 0x10015bb0` |
| `100158d6` | `48` | `DEC EAX` |
| `100158d7` | `48` | `DEC EAX` |
| `100158d8` | `74 79` | `JZ 0x10015953` |
| `100158da` | `2b c1` | `SUB EAX,ECX` |
| `100158dc` | `0f 84 27 ff ff ff` | `JZ 0x10015809` |
| `100158e2` | `48` | `DEC EAX` |
| `100158e3` | `48` | `DEC EAX` |
| `100158e4` | `0f 85 9e 04 00 00` | `JNZ 0x10015d88` |
| `100158ea` | `83 c7 04` | `ADD EDI,0x4` |
| `100158ed` | `f7 85 f0 fd ff ff 10 08 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x810` |
| `100158f7` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `100158fd` | `74 30` | `JZ 0x1001592f` |
| `100158ff` | `0f b7 47 fc` | `MOVZX EAX,word ptr [EDI + -0x4]` |
| `10015903` | `50` | `PUSH EAX` |
| `10015904` | `68 00 02 00 00` | `PUSH 0x200` |
| `10015909` | `8d 85 f4 fd ff ff` | `LEA EAX,[EBP + 0xfffffdf4]` |
| `1001590f` | `50` | `PUSH EAX` |
| `10015910` | `8d 85 e0 fd ff ff` | `LEA EAX,[EBP + 0xfffffde0]` |
| `10015916` | `50` | `PUSH EAX` |
| `10015917` | `e8 cf 6d 00 00` | `CALL 0x1001c6eb` |
| `1001591c` | `83 c4 10` | `ADD ESP,0x10` |
| `1001591f` | `85 c0` | `TEST EAX,EAX` |
| `10015921` | `74 1f` | `JZ 0x10015942` |
| `10015923` | `c7 85 c0 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffdc0],0x1` |
| `1001592d` | `eb 13` | `JMP 0x10015942` |
| `1001592f` | `8a 47 fc` | `MOV AL,byte ptr [EDI + -0x4]` |
| `10015932` | `88 85 f4 fd ff ff` | `MOV byte ptr [EBP + 0xfffffdf4],AL` |
| `10015938` | `c7 85 e0 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffde0],0x1` |
| `10015942` | `8d 85 f4 fd ff ff` | `LEA EAX,[EBP + 0xfffffdf4]` |
| `10015948` | `89 85 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EAX` |
| `1001594e` | `e9 35 04 00 00` | `JMP 0x10015d88` |
| `10015953` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10015955` | `83 c7 04` | `ADD EDI,0x4` |
| `10015958` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `1001595e` | `3b c6` | `CMP EAX,ESI` |
| `10015960` | `74 3b` | `JZ 0x1001599d` |
| `10015962` | `8b 48 04` | `MOV ECX,dword ptr [EAX + 0x4]` |
| `10015965` | `3b ce` | `CMP ECX,ESI` |
| `10015967` | `74 34` | `JZ 0x1001599d` |
| `10015969` | `f7 85 f0 fd ff ff 00 08 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x800` |
| `10015973` | `0f bf 00` | `MOVSX EAX,word ptr [EAX]` |
| `10015976` | `89 8d e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],ECX` |
| `1001597c` | `74 14` | `JZ 0x10015992` |
| `1001597e` | `99` | `CDQ` |
| `1001597f` | `2b c2` | `SUB EAX,EDX` |
| `10015981` | `d1 f8` | `SAR EAX,0x1` |
| `10015983` | `c7 85 c8 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffdc8],0x1` |
| `1001598d` | `e9 f0 03 00 00` | `JMP 0x10015d82` |
| `10015992` | `89 b5 c8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdc8],ESI` |
| `10015998` | `e9 e5 03 00 00` | `JMP 0x10015d82` |
| `1001599d` | `a1 08 76 03 10` | `MOV EAX,[0x10037608]` |
| `100159a2` | `89 85 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EAX` |
| `100159a8` | `50` | `PUSH EAX` |
| `100159a9` | `e8 42 ba ff ff` | `CALL 0x100113f0` |
| `100159ae` | `59` | `POP ECX` |
| `100159af` | `e9 ce 03 00 00` | `JMP 0x10015d82` |
| `100159b4` | `83 f8 70` | `CMP EAX,0x70` |
| `100159b7` | `0f 8f fb 01 00 00` | `JG 0x10015bb8` |
| `100159bd` | `0f 84 e3 01 00 00` | `JZ 0x10015ba6` |
| `100159c3` | `83 f8 65` | `CMP EAX,0x65` |
| `100159c6` | `0f 8c bc 03 00 00` | `JL 0x10015d88` |
| `100159cc` | `83 f8 67` | `CMP EAX,0x67` |
| `100159cf` | `0f 8e 34 fe ff ff` | `JLE 0x10015809` |
| `100159d5` | `83 f8 69` | `CMP EAX,0x69` |
| `100159d8` | `74 71` | `JZ 0x10015a4b` |
| `100159da` | `83 f8 6e` | `CMP EAX,0x6e` |
| `100159dd` | `74 28` | `JZ 0x10015a07` |
| `100159df` | `83 f8 6f` | `CMP EAX,0x6f` |
| `100159e2` | `0f 85 a0 03 00 00` | `JNZ 0x10015d88` |
| `100159e8` | `f6 85 f0 fd ff ff 80` | `TEST byte ptr [EBP + 0xfffffdf0],0x80` |
| `100159ef` | `c7 85 e0 fd ff ff 08 00 00 00` | `MOV dword ptr [EBP + 0xfffffde0],0x8` |
| `100159f9` | `74 61` | `JZ 0x10015a5c` |
| `100159fb` | `81 8d f0 fd ff ff 00 02 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x200` |
| `10015a05` | `eb 55` | `JMP 0x10015a5c` |
| `10015a07` | `8b 37` | `MOV ESI,dword ptr [EDI]` |
| `10015a09` | `83 c7 04` | `ADD EDI,0x4` |
| `10015a0c` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `10015a12` | `e8 2a c6 ff ff` | `CALL 0x10012041` |
| `10015a17` | `85 c0` | `TEST EAX,EAX` |
| `10015a19` | `0f 84 2f fa ff ff` | `JZ 0x1001544e` |
| `10015a1f` | `f6 85 f0 fd ff ff 20` | `TEST byte ptr [EBP + 0xfffffdf0],0x20` |
| `10015a26` | `74 0c` | `JZ 0x10015a34` |
| `10015a28` | `66 8b 85 d8 fd ff ff` | `MOV AX,word ptr [EBP + 0xfffffdd8]` |
| `10015a2f` | `66 89 06` | `MOV word ptr [ESI],AX` |
| `10015a32` | `eb 08` | `JMP 0x10015a3c` |
| `10015a34` | `8b 85 d8 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffdd8]` |
| `10015a3a` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10015a3c` | `c7 85 c0 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffdc0],0x1` |
| `10015a46` | `e9 a6 04 00 00` | `JMP 0x10015ef1` |
| `10015a4b` | `83 8d f0 fd ff ff 40` | `OR dword ptr [EBP + 0xfffffdf0],0x40` |
| `10015a52` | `c7 85 e0 fd ff ff 0a 00 00 00` | `MOV dword ptr [EBP + 0xfffffde0],0xa` |
| `10015a5c` | `8b 8d f0 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffdf0]` |
| `10015a62` | `f7 c1 00 80 00 00` | `TEST ECX,0x8000` |
| `10015a68` | `0f 84 a9 01 00 00` | `JZ 0x10015c17` |
| `10015a6e` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10015a70` | `8b 57 04` | `MOV EDX,dword ptr [EDI + 0x4]` |
| `10015a73` | `83 c7 08` | `ADD EDI,0x8` |
| `10015a76` | `e9 d5 01 00 00` | `JMP 0x10015c50` |
| `10015a7b` | `75 11` | `JNZ 0x10015a8e` |
| `10015a7d` | `80 fa 67` | `CMP DL,0x67` |
| `10015a80` | `75 65` | `JNZ 0x10015ae7` |
| `10015a82` | `c7 85 e8 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffde8],0x1` |
| `10015a8c` | `eb 59` | `JMP 0x10015ae7` |
| `10015a8e` | `39 85 e8 fd ff ff` | `CMP dword ptr [EBP + 0xfffffde8],EAX` |
| `10015a94` | `7e 06` | `JLE 0x10015a9c` |
| `10015a96` | `89 85 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],EAX` |
| `10015a9c` | `81 bd e8 fd ff ff a3 00 00 00` | `CMP dword ptr [EBP + 0xfffffde8],0xa3` |
| `10015aa6` | `7e 3f` | `JLE 0x10015ae7` |
| `10015aa8` | `8b b5 e8 fd ff ff` | `MOV ESI,dword ptr [EBP + 0xfffffde8]` |
| `10015aae` | `81 c6 5d 01 00 00` | `ADD ESI,0x15d` |
| `10015ab4` | `56` | `PUSH ESI` |
| `10015ab5` | `e8 15 4a 00 00` | `CALL 0x1001a4cf` |
| `10015aba` | `8a 95 ef fd ff ff` | `MOV DL,byte ptr [EBP + 0xfffffdef]` |
| `10015ac0` | `59` | `POP ECX` |
| `10015ac1` | `89 85 bc fd ff ff` | `MOV dword ptr [EBP + 0xfffffdbc],EAX` |
| `10015ac7` | `85 c0` | `TEST EAX,EAX` |
| `10015ac9` | `74 10` | `JZ 0x10015adb` |
| `10015acb` | `89 85 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EAX` |
| `10015ad1` | `89 b5 a0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffda0],ESI` |
| `10015ad7` | `8b d8` | `MOV EBX,EAX` |
| `10015ad9` | `eb 0a` | `JMP 0x10015ae5` |
| `10015adb` | `c7 85 e8 fd ff ff a3 00 00 00` | `MOV dword ptr [EBP + 0xfffffde8],0xa3` |
| `10015ae5` | `33 f6` | `XOR ESI,ESI` |
| `10015ae7` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10015ae9` | `83 c7 08` | `ADD EDI,0x8` |
| `10015aec` | `89 85 88 fd ff ff` | `MOV dword ptr [EBP + 0xfffffd88],EAX` |
| `10015af2` | `8b 47 fc` | `MOV EAX,dword ptr [EDI + -0x4]` |
| `10015af5` | `89 85 8c fd ff ff` | `MOV dword ptr [EBP + 0xfffffd8c],EAX` |
| `10015afb` | `8d 85 a4 fd ff ff` | `LEA EAX,[EBP + 0xfffffda4]` |
| `10015b01` | `50` | `PUSH EAX` |
| `10015b02` | `ff b5 90 fd ff ff` | `PUSH dword ptr [EBP + 0xfffffd90]` |
| `10015b08` | `0f be c2` | `MOVSX EAX,DL` |
| `10015b0b` | `ff b5 e8 fd ff ff` | `PUSH dword ptr [EBP + 0xfffffde8]` |
| `10015b11` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `10015b17` | `50` | `PUSH EAX` |
| `10015b18` | `ff b5 a0 fd ff ff` | `PUSH dword ptr [EBP + 0xfffffda0]` |
| `10015b1e` | `8d 85 88 fd ff ff` | `LEA EAX,[EBP + 0xfffffd88]` |
| `10015b24` | `53` | `PUSH EBX` |
| `10015b25` | `50` | `PUSH EAX` |
| `10015b26` | `ff 35 d8 7b 03 10` | `PUSH dword ptr [0x10037bd8]` |
| `10015b2c` | `e8 59 16 00 00` | `CALL 0x1001718a` |
| `10015b31` | `59` | `POP ECX` |
| `10015b32` | `ff d0` | `CALL EAX` |
| `10015b34` | `8b bd f0 fd ff ff` | `MOV EDI,dword ptr [EBP + 0xfffffdf0]` |
| `10015b3a` | `83 c4 1c` | `ADD ESP,0x1c` |
| `10015b3d` | `81 e7 80 00 00 00` | `AND EDI,0x80` |
| `10015b43` | `74 20` | `JZ 0x10015b65` |
| `10015b45` | `39 b5 e8 fd ff ff` | `CMP dword ptr [EBP + 0xfffffde8],ESI` |
| `10015b4b` | `75 18` | `JNZ 0x10015b65` |
| `10015b4d` | `8d 85 a4 fd ff ff` | `LEA EAX,[EBP + 0xfffffda4]` |
| `10015b53` | `50` | `PUSH EAX` |
| `10015b54` | `53` | `PUSH EBX` |
| `10015b55` | `ff 35 e4 7b 03 10` | `PUSH dword ptr [0x10037be4]` |
| `10015b5b` | `e8 2a 16 00 00` | `CALL 0x1001718a` |
| `10015b60` | `59` | `POP ECX` |
| `10015b61` | `ff d0` | `CALL EAX` |
| `10015b63` | `59` | `POP ECX` |
| `10015b64` | `59` | `POP ECX` |
| `10015b65` | `80 bd ef fd ff ff 67` | `CMP byte ptr [EBP + 0xfffffdef],0x67` |
| `10015b6c` | `75 1c` | `JNZ 0x10015b8a` |
| `10015b6e` | `3b fe` | `CMP EDI,ESI` |
| `10015b70` | `75 18` | `JNZ 0x10015b8a` |
| `10015b72` | `8d 85 a4 fd ff ff` | `LEA EAX,[EBP + 0xfffffda4]` |
| `10015b78` | `50` | `PUSH EAX` |
| `10015b79` | `53` | `PUSH EBX` |
| `10015b7a` | `ff 35 e0 7b 03 10` | `PUSH dword ptr [0x10037be0]` |
| `10015b80` | `e8 05 16 00 00` | `CALL 0x1001718a` |
| `10015b85` | `59` | `POP ECX` |
| `10015b86` | `ff d0` | `CALL EAX` |
| `10015b88` | `59` | `POP ECX` |
| `10015b89` | `59` | `POP ECX` |
| `10015b8a` | `80 3b 2d` | `CMP byte ptr [EBX],0x2d` |
| `10015b8d` | `75 11` | `JNZ 0x10015ba0` |
| `10015b8f` | `81 8d f0 fd ff ff 00 01 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x100` |
| `10015b99` | `43` | `INC EBX` |
| `10015b9a` | `89 9d e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EBX` |
| `10015ba0` | `53` | `PUSH EBX` |
| `10015ba1` | `e9 03 fe ff ff` | `JMP 0x100159a9` |
| `10015ba6` | `c7 85 e8 fd ff ff 08 00 00 00` | `MOV dword ptr [EBP + 0xfffffde8],0x8` |
| `10015bb0` | `89 8d b8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffdb8],ECX` |
| `10015bb6` | `eb 24` | `JMP 0x10015bdc` |
| `10015bb8` | `83 e8 73` | `SUB EAX,0x73` |
| `10015bbb` | `0f 84 b6 fc ff ff` | `JZ 0x10015877` |
| `10015bc1` | `48` | `DEC EAX` |
| `10015bc2` | `48` | `DEC EAX` |
| `10015bc3` | `0f 84 89 fe ff ff` | `JZ 0x10015a52` |
| `10015bc9` | `83 e8 03` | `SUB EAX,0x3` |
| `10015bcc` | `0f 85 b6 01 00 00` | `JNZ 0x10015d88` |
| `10015bd2` | `c7 85 b8 fd ff ff 27 00 00 00` | `MOV dword ptr [EBP + 0xfffffdb8],0x27` |
| `10015bdc` | `f6 85 f0 fd ff ff 80` | `TEST byte ptr [EBP + 0xfffffdf0],0x80` |
| `10015be3` | `c7 85 e0 fd ff ff 10 00 00 00` | `MOV dword ptr [EBP + 0xfffffde0],0x10` |
| `10015bed` | `0f 84 69 fe ff ff` | `JZ 0x10015a5c` |
| `10015bf3` | `8a 85 b8 fd ff ff` | `MOV AL,byte ptr [EBP + 0xfffffdb8]` |
| `10015bf9` | `04 51` | `ADD AL,0x51` |
| `10015bfb` | `c6 85 d4 fd ff ff 30` | `MOV byte ptr [EBP + 0xfffffdd4],0x30` |
| `10015c02` | `88 85 d5 fd ff ff` | `MOV byte ptr [EBP + 0xfffffdd5],AL` |
| `10015c08` | `c7 85 d0 fd ff ff 02 00 00 00` | `MOV dword ptr [EBP + 0xfffffdd0],0x2` |
| `10015c12` | `e9 45 fe ff ff` | `JMP 0x10015a5c` |
| `10015c17` | `f7 c1 00 10 00 00` | `TEST ECX,0x1000` |
| `10015c1d` | `0f 85 4b fe ff ff` | `JNZ 0x10015a6e` |
| `10015c23` | `83 c7 04` | `ADD EDI,0x4` |
| `10015c26` | `f6 c1 20` | `TEST CL,0x20` |
| `10015c29` | `74 18` | `JZ 0x10015c43` |
| `10015c2b` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `10015c31` | `f6 c1 40` | `TEST CL,0x40` |
| `10015c34` | `74 06` | `JZ 0x10015c3c` |
| `10015c36` | `0f bf 47 fc` | `MOVSX EAX,word ptr [EDI + -0x4]` |
| `10015c3a` | `eb 04` | `JMP 0x10015c40` |
| `10015c3c` | `0f b7 47 fc` | `MOVZX EAX,word ptr [EDI + -0x4]` |
| `10015c40` | `99` | `CDQ` |
| `10015c41` | `eb 13` | `JMP 0x10015c56` |
| `10015c43` | `8b 47 fc` | `MOV EAX,dword ptr [EDI + -0x4]` |
| `10015c46` | `f6 c1 40` | `TEST CL,0x40` |
| `10015c49` | `74 03` | `JZ 0x10015c4e` |
| `10015c4b` | `99` | `CDQ` |
| `10015c4c` | `eb 02` | `JMP 0x10015c50` |
| `10015c4e` | `33 d2` | `XOR EDX,EDX` |
| `10015c50` | `89 bd dc fd ff ff` | `MOV dword ptr [EBP + 0xfffffddc],EDI` |
| `10015c56` | `f6 c1 40` | `TEST CL,0x40` |
| `10015c59` | `74 1b` | `JZ 0x10015c76` |
| `10015c5b` | `3b d6` | `CMP EDX,ESI` |
| `10015c5d` | `7f 17` | `JG 0x10015c76` |
| `10015c5f` | `7c 04` | `JL 0x10015c65` |
| `10015c61` | `3b c6` | `CMP EAX,ESI` |
| `10015c63` | `73 11` | `JNC 0x10015c76` |
| `10015c65` | `f7 d8` | `NEG EAX` |
| `10015c67` | `83 d2 00` | `ADC EDX,0x0` |
| `10015c6a` | `f7 da` | `NEG EDX` |
| `10015c6c` | `81 8d f0 fd ff ff 00 01 00 00` | `OR dword ptr [EBP + 0xfffffdf0],0x100` |
| `10015c76` | `f7 85 f0 fd ff ff 00 90 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x9000` |
| `10015c80` | `8b da` | `MOV EBX,EDX` |
| `10015c82` | `8b f8` | `MOV EDI,EAX` |
| `10015c84` | `75 02` | `JNZ 0x10015c88` |
| `10015c86` | `33 db` | `XOR EBX,EBX` |
| `10015c88` | `83 bd e8 fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffde8],0x0` |
| `10015c8f` | `7d 0c` | `JGE 0x10015c9d` |
| `10015c91` | `c7 85 e8 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffde8],0x1` |
| `10015c9b` | `eb 1a` | `JMP 0x10015cb7` |
| `10015c9d` | `83 a5 f0 fd ff ff f7` | `AND dword ptr [EBP + 0xfffffdf0],0xfffffff7` |
| `10015ca4` | `b8 00 02 00 00` | `MOV EAX,0x200` |
| `10015ca9` | `39 85 e8 fd ff ff` | `CMP dword ptr [EBP + 0xfffffde8],EAX` |
| `10015caf` | `7e 06` | `JLE 0x10015cb7` |
| `10015cb1` | `89 85 e8 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde8],EAX` |
| `10015cb7` | `8b c7` | `MOV EAX,EDI` |
| `10015cb9` | `0b c3` | `OR EAX,EBX` |
| `10015cbb` | `75 06` | `JNZ 0x10015cc3` |
| `10015cbd` | `21 85 d0 fd ff ff` | `AND dword ptr [EBP + 0xfffffdd0],EAX` |
| `10015cc3` | `8d 75 f3` | `LEA ESI,[EBP + -0xd]` |
| `10015cc6` | `8b 85 e8 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffde8]` |
| `10015ccc` | `ff 8d e8 fd ff ff` | `DEC dword ptr [EBP + 0xfffffde8]` |
| `10015cd2` | `85 c0` | `TEST EAX,EAX` |
| `10015cd4` | `7f 06` | `JG 0x10015cdc` |
| `10015cd6` | `8b c7` | `MOV EAX,EDI` |
| `10015cd8` | `0b c3` | `OR EAX,EBX` |
| `10015cda` | `74 2d` | `JZ 0x10015d09` |
| `10015cdc` | `8b 85 e0 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffde0]` |
| `10015ce2` | `99` | `CDQ` |
| `10015ce3` | `52` | `PUSH EDX` |
| `10015ce4` | `50` | `PUSH EAX` |
| `10015ce5` | `53` | `PUSH EBX` |
| `10015ce6` | `57` | `PUSH EDI` |
| `10015ce7` | `e8 74 6a 00 00` | `CALL 0x1001c760` |
| `10015cec` | `83 c1 30` | `ADD ECX,0x30` |
| `10015cef` | `83 f9 39` | `CMP ECX,0x39` |
| `10015cf2` | `89 9d a0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffda0],EBX` |
| `10015cf8` | `8b f8` | `MOV EDI,EAX` |
| `10015cfa` | `8b da` | `MOV EBX,EDX` |
| `10015cfc` | `7e 06` | `JLE 0x10015d04` |
| `10015cfe` | `03 8d b8 fd ff ff` | `ADD ECX,dword ptr [EBP + 0xfffffdb8]` |
| `10015d04` | `88 0e` | `MOV byte ptr [ESI],CL` |
| `10015d06` | `4e` | `DEC ESI` |
| `10015d07` | `eb bd` | `JMP 0x10015cc6` |
| `10015d09` | `8d 45 f3` | `LEA EAX,[EBP + -0xd]` |
| `10015d0c` | `2b c6` | `SUB EAX,ESI` |
| `10015d0e` | `46` | `INC ESI` |
| `10015d0f` | `f7 85 f0 fd ff ff 00 02 00 00` | `TEST dword ptr [EBP + 0xfffffdf0],0x200` |
| `10015d19` | `89 85 e0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde0],EAX` |
| `10015d1f` | `89 b5 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],ESI` |
| `10015d25` | `74 61` | `JZ 0x10015d88` |
| `10015d27` | `85 c0` | `TEST EAX,EAX` |
| `10015d29` | `74 07` | `JZ 0x10015d32` |
| `10015d2b` | `8b ce` | `MOV ECX,ESI` |
| `10015d2d` | `80 39 30` | `CMP byte ptr [ECX],0x30` |
| `10015d30` | `74 56` | `JZ 0x10015d88` |
| `10015d32` | `ff 8d e4 fd ff ff` | `DEC dword ptr [EBP + 0xfffffde4]` |
| `10015d38` | `8b 8d e4 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffde4]` |
| `10015d3e` | `c6 01 30` | `MOV byte ptr [ECX],0x30` |
| `10015d41` | `40` | `INC EAX` |
| `10015d42` | `eb 3e` | `JMP 0x10015d82` |
| `10015d44` | `49` | `DEC ECX` |
| `10015d45` | `66 39 30` | `CMP word ptr [EAX],SI` |
| `10015d48` | `74 06` | `JZ 0x10015d50` |
| `10015d4a` | `40` | `INC EAX` |
| `10015d4b` | `40` | `INC EAX` |
| `10015d4c` | `3b ce` | `CMP ECX,ESI` |
| `10015d4e` | `75 f4` | `JNZ 0x10015d44` |
| `10015d50` | `2b 85 e4 fd ff ff` | `SUB EAX,dword ptr [EBP + 0xfffffde4]` |
| `10015d56` | `d1 f8` | `SAR EAX,0x1` |
| `10015d58` | `eb 28` | `JMP 0x10015d82` |
| `10015d5a` | `3b fe` | `CMP EDI,ESI` |
| `10015d5c` | `75 0b` | `JNZ 0x10015d69` |
| `10015d5e` | `a1 08 76 03 10` | `MOV EAX,[0x10037608]` |
| `10015d63` | `89 85 e4 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde4],EAX` |
| `10015d69` | `8b 85 e4 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffde4]` |
| `10015d6f` | `eb 07` | `JMP 0x10015d78` |
| `10015d71` | `49` | `DEC ECX` |
| `10015d72` | `80 38 00` | `CMP byte ptr [EAX],0x0` |
| `10015d75` | `74 05` | `JZ 0x10015d7c` |
| `10015d77` | `40` | `INC EAX` |
| `10015d78` | `3b ce` | `CMP ECX,ESI` |
| `10015d7a` | `75 f5` | `JNZ 0x10015d71` |
| `10015d7c` | `2b 85 e4 fd ff ff` | `SUB EAX,dword ptr [EBP + 0xfffffde4]` |
| `10015d82` | `89 85 e0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffde0],EAX` |
| `10015d88` | `83 bd c0 fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffdc0],0x0` |
| `10015d8f` | `0f 85 5c 01 00 00` | `JNZ 0x10015ef1` |
| `10015d95` | `8b 85 f0 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffdf0]` |
| `10015d9b` | `a8 40` | `TEST AL,0x40` |
| `10015d9d` | `74 32` | `JZ 0x10015dd1` |
| `10015d9f` | `a9 00 01 00 00` | `TEST EAX,0x100` |
| `10015da4` | `74 09` | `JZ 0x10015daf` |
| `10015da6` | `c6 85 d4 fd ff ff 2d` | `MOV byte ptr [EBP + 0xfffffdd4],0x2d` |
| `10015dad` | `eb 18` | `JMP 0x10015dc7` |
| `10015daf` | `a8 01` | `TEST AL,0x1` |
| `10015db1` | `74 09` | `JZ 0x10015dbc` |
| `10015db3` | `c6 85 d4 fd ff ff 2b` | `MOV byte ptr [EBP + 0xfffffdd4],0x2b` |
| `10015dba` | `eb 0b` | `JMP 0x10015dc7` |
| `10015dbc` | `a8 02` | `TEST AL,0x2` |
| `10015dbe` | `74 11` | `JZ 0x10015dd1` |
| `10015dc0` | `c6 85 d4 fd ff ff 20` | `MOV byte ptr [EBP + 0xfffffdd4],0x20` |
| `10015dc7` | `c7 85 d0 fd ff ff 01 00 00 00` | `MOV dword ptr [EBP + 0xfffffdd0],0x1` |
| `10015dd1` | `8b 9d cc fd ff ff` | `MOV EBX,dword ptr [EBP + 0xfffffdcc]` |
| `10015dd7` | `2b 9d e0 fd ff ff` | `SUB EBX,dword ptr [EBP + 0xfffffde0]` |
| `10015ddd` | `2b 9d d0 fd ff ff` | `SUB EBX,dword ptr [EBP + 0xfffffdd0]` |
| `10015de3` | `f6 85 f0 fd ff ff 0c` | `TEST byte ptr [EBP + 0xfffffdf0],0xc` |
| `10015dea` | `75 17` | `JNZ 0x10015e03` |
| `10015dec` | `ff b5 b4 fd ff ff` | `PUSH dword ptr [EBP + 0xfffffdb4]` |
| `10015df2` | `8d 85 d8 fd ff ff` | `LEA EAX,[EBP + 0xfffffdd8]` |
| `10015df8` | `53` | `PUSH EBX` |
| `10015df9` | `6a 20` | `PUSH 0x20` |
| `10015dfb` | `e8 70 f5 ff ff` | `CALL 0x10015370` |
| `10015e00` | `83 c4 0c` | `ADD ESP,0xc` |
| `10015e03` | `ff b5 d0 fd ff ff` | `PUSH dword ptr [EBP + 0xfffffdd0]` |
| `10015e09` | `8b bd b4 fd ff ff` | `MOV EDI,dword ptr [EBP + 0xfffffdb4]` |
| `10015e0f` | `8d 85 d8 fd ff ff` | `LEA EAX,[EBP + 0xfffffdd8]` |
| `10015e15` | `8d 8d d4 fd ff ff` | `LEA ECX,[EBP + 0xfffffdd4]` |
| `10015e1b` | `e8 76 f5 ff ff` | `CALL 0x10015396` |
| `10015e20` | `f6 85 f0 fd ff ff 08` | `TEST byte ptr [EBP + 0xfffffdf0],0x8` |
| `10015e27` | `59` | `POP ECX` |
| `10015e28` | `74 1b` | `JZ 0x10015e45` |
| `10015e2a` | `f6 85 f0 fd ff ff 04` | `TEST byte ptr [EBP + 0xfffffdf0],0x4` |
| `10015e31` | `75 12` | `JNZ 0x10015e45` |
| `10015e33` | `57` | `PUSH EDI` |
| `10015e34` | `53` | `PUSH EBX` |
| `10015e35` | `6a 30` | `PUSH 0x30` |
| `10015e37` | `8d 85 d8 fd ff ff` | `LEA EAX,[EBP + 0xfffffdd8]` |
| `10015e3d` | `e8 2e f5 ff ff` | `CALL 0x10015370` |
| `10015e42` | `83 c4 0c` | `ADD ESP,0xc` |
| `10015e45` | `83 bd c8 fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffdc8],0x0` |
| `10015e4c` | `8b 85 e0 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffde0]` |
| `10015e52` | `74 66` | `JZ 0x10015eba` |
| `10015e54` | `85 c0` | `TEST EAX,EAX` |
| `10015e56` | `7e 62` | `JLE 0x10015eba` |
| `10015e58` | `8b b5 e4 fd ff ff` | `MOV ESI,dword ptr [EBP + 0xfffffde4]` |
| `10015e5e` | `89 85 a0 fd ff ff` | `MOV dword ptr [EBP + 0xfffffda0],EAX` |
| `10015e64` | `0f b7 06` | `MOVZX EAX,word ptr [ESI]` |
| `10015e67` | `ff 8d a0 fd ff ff` | `DEC dword ptr [EBP + 0xfffffda0]` |
| `10015e6d` | `50` | `PUSH EAX` |
| `10015e6e` | `6a 06` | `PUSH 0x6` |
| `10015e70` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10015e73` | `50` | `PUSH EAX` |
| `10015e74` | `8d 85 98 fd ff ff` | `LEA EAX,[EBP + 0xfffffd98]` |
| `10015e7a` | `46` | `INC ESI` |
| `10015e7b` | `50` | `PUSH EAX` |
| `10015e7c` | `46` | `INC ESI` |
| `10015e7d` | `e8 69 68 00 00` | `CALL 0x1001c6eb` |
| `10015e82` | `83 c4 10` | `ADD ESP,0x10` |
| `10015e85` | `85 c0` | `TEST EAX,EAX` |
| `10015e87` | `75 28` | `JNZ 0x10015eb1` |
| `10015e89` | `39 85 98 fd ff ff` | `CMP dword ptr [EBP + 0xfffffd98],EAX` |
| `10015e8f` | `74 20` | `JZ 0x10015eb1` |
| `10015e91` | `ff b5 98 fd ff ff` | `PUSH dword ptr [EBP + 0xfffffd98]` |
| `10015e97` | `8d 85 d8 fd ff ff` | `LEA EAX,[EBP + 0xfffffdd8]` |
| `10015e9d` | `8d 4d f4` | `LEA ECX,[EBP + -0xc]` |
| `10015ea0` | `e8 f1 f4 ff ff` | `CALL 0x10015396` |
| `10015ea5` | `83 bd a0 fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffda0],0x0` |
| `10015eac` | `59` | `POP ECX` |
| `10015ead` | `75 b5` | `JNZ 0x10015e64` |
| `10015eaf` | `eb 1c` | `JMP 0x10015ecd` |
| `10015eb1` | `83 8d d8 fd ff ff ff` | `OR dword ptr [EBP + 0xfffffdd8],0xffffffff` |
| `10015eb8` | `eb 13` | `JMP 0x10015ecd` |
| `10015eba` | `8b 8d e4 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffde4]` |
| `10015ec0` | `50` | `PUSH EAX` |
| `10015ec1` | `8d 85 d8 fd ff ff` | `LEA EAX,[EBP + 0xfffffdd8]` |
| `10015ec7` | `e8 ca f4 ff ff` | `CALL 0x10015396` |
| `10015ecc` | `59` | `POP ECX` |
| `10015ecd` | `83 bd d8 fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffdd8],0x0` |
| `10015ed4` | `7c 1b` | `JL 0x10015ef1` |
| `10015ed6` | `f6 85 f0 fd ff ff 04` | `TEST byte ptr [EBP + 0xfffffdf0],0x4` |
| `10015edd` | `74 12` | `JZ 0x10015ef1` |
| `10015edf` | `57` | `PUSH EDI` |
| `10015ee0` | `53` | `PUSH EBX` |
| `10015ee1` | `6a 20` | `PUSH 0x20` |
| `10015ee3` | `8d 85 d8 fd ff ff` | `LEA EAX,[EBP + 0xfffffdd8]` |
| `10015ee9` | `e8 82 f4 ff ff` | `CALL 0x10015370` |
| `10015eee` | `83 c4 0c` | `ADD ESP,0xc` |
| `10015ef1` | `83 bd bc fd ff ff 00` | `CMP dword ptr [EBP + 0xfffffdbc],0x0` |
| `10015ef8` | `74 13` | `JZ 0x10015f0d` |
| `10015efa` | `ff b5 bc fd ff ff` | `PUSH dword ptr [EBP + 0xfffffdbc]` |
| `10015f00` | `e8 3c b3 ff ff` | `CALL 0x10011241` |
| `10015f05` | `83 a5 bc fd ff ff 00` | `AND dword ptr [EBP + 0xfffffdbc],0x0` |
| `10015f0c` | `59` | `POP ECX` |
| `10015f0d` | `8b 9d c4 fd ff ff` | `MOV EBX,dword ptr [EBP + 0xfffffdc4]` |
| `10015f13` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `10015f15` | `88 85 ef fd ff ff` | `MOV byte ptr [EBP + 0xfffffdef],AL` |
| `10015f1b` | `84 c0` | `TEST AL,AL` |
| `10015f1d` | `74 13` | `JZ 0x10015f32` |
| `10015f1f` | `8b 8d 94 fd ff ff` | `MOV ECX,dword ptr [EBP + 0xfffffd94]` |
| `10015f25` | `8b bd dc fd ff ff` | `MOV EDI,dword ptr [EBP + 0xfffffddc]` |
| `10015f2b` | `8a d0` | `MOV DL,AL` |
| `10015f2d` | `e9 e1 f5 ff ff` | `JMP 0x10015513` |
| `10015f32` | `80 bd b0 fd ff ff 00` | `CMP byte ptr [EBP + 0xfffffdb0],0x0` |
| `10015f39` | `74 0a` | `JZ 0x10015f45` |
| `10015f3b` | `8b 85 ac fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffdac]` |
| `10015f41` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10015f45` | `8b 85 d8 fd ff ff` | `MOV EAX,dword ptr [EBP + 0xfffffdd8]` |
| `10015f4b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10015f4e` | `5f` | `POP EDI` |
| `10015f4f` | `5e` | `POP ESI` |
| `10015f50` | `33 cd` | `XOR ECX,EBP` |
| `10015f52` | `5b` | `POP EBX` |
| `10015f53` | `e8 73 ad ff ff` | `CALL 0x10010ccb` |
| `10015f58` | `c9` | `LEAVE` |
| `10015f59` | `c3` | `RET` |
