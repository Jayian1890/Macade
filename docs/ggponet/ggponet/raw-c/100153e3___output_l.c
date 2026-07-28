
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
