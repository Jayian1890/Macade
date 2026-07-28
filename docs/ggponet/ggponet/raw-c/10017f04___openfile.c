
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
