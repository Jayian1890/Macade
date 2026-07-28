
void FUN_10003aa0(char *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  free((void *)*param_2);
  *param_2 = 0;
  free((void *)*param_4);
  *param_4 = 0;
  free((void *)*param_5);
  *param_5 = 0;
  pcVar2 = strstr(param_1,&DAT_1000e1f4);
  if (pcVar2 != (char *)0x0) {
    pcVar2 = strstr(param_1,&DAT_1000e1f4);
    param_1 = pcVar2 + 3;
  }
  cVar1 = *param_1;
  pcVar2 = param_1;
  while ((cVar1 != '/' && (cVar1 != '\0'))) {
    pcVar3 = pcVar2 + 1;
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar3;
  }
  if (*pcVar2 == '\0') {
    pcVar2 = malloc(2);
    *param_4 = pcVar2;
    if (pcVar2 != (char *)0x0) {
      uVar5 = 0xffffffff;
      pcVar3 = &DAT_1000e1f0;
      do {
        pcVar7 = pcVar3;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar7 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar7;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar3 = pcVar7 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar2 = pcVar2 + 1;
      }
    }
  }
  else {
    uVar5 = 0xffffffff;
    pcVar3 = pcVar2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = malloc(~uVar5);
    *param_4 = pcVar3;
    if (pcVar3 != (char *)0x0) {
      uVar5 = 0xffffffff;
      pcVar7 = pcVar2;
      do {
        pcVar8 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar7 = pcVar8 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
    *pcVar2 = '\0';
  }
  cVar1 = *param_1;
  pcVar2 = param_1;
  while ((cVar1 != '@' && (cVar1 != '\0'))) {
    pcVar3 = pcVar2 + 1;
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar3;
  }
  if (*pcVar2 == '\0') {
    pcVar3 = malloc(1);
    *param_5 = pcVar3;
    pcVar2 = param_1;
    if (pcVar3 != (char *)0x0) {
      uVar5 = 0xffffffff;
      pcVar7 = &DAT_1000ec9c;
      do {
        pcVar8 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar7 = pcVar8 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
  else {
    *pcVar2 = '\0';
    uVar5 = 0xffffffff;
    pcVar2 = pcVar2 + 1;
    pcVar3 = param_1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = malloc(~uVar5);
    *param_5 = pcVar3;
    if (pcVar3 != (char *)0x0) {
      uVar5 = 0xffffffff;
      do {
        pcVar7 = param_1;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar7 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar7;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar7 = pcVar7 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
  cVar1 = *pcVar2;
  pcVar3 = pcVar2;
  while ((cVar1 != ':' && (cVar1 != '\0'))) {
    pcVar7 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar7;
  }
  if (*pcVar3 == '\0') {
    *param_3 = 0x50;
  }
  else {
    *pcVar3 = '\0';
    iVar4 = atoi(pcVar3 + 1);
    *param_3 = iVar4;
  }
  uVar5 = 0xffffffff;
  pcVar3 = pcVar2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = malloc(~uVar5);
  *param_2 = pcVar3;
  if (pcVar3 != (char *)0x0) {
    uVar5 = 0xffffffff;
    do {
      pcVar7 = pcVar2;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar2 = pcVar7 + -uVar5;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar3 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return;
}
