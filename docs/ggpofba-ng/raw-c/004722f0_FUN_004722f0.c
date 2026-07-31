
/* WARNING: Removing unreachable block (ram,0x004726f5) */
/* WARNING: Removing unreachable block (ram,0x00472626) */
/* WARNING: Removing unreachable block (ram,0x004724bb) */
/* WARNING: Removing unreachable block (ram,0x0047235e) */
/* WARNING: Removing unreachable block (ram,0x00472576) */
/* WARNING: Removing unreachable block (ram,0x0047276b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004722f0(void)

{
  char cVar1;
  char *pcVar2;
  clock_t cVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  _memset(&DAT_009e7160,0,0x60);
  iVar7 = 0;
  if (0 < DAT_009e7138) {
    do {
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_009e7138);
  }
  if ((DAT_00b181ea != '\0') && (DAT_009e7138 != 0)) {
    iVar6 = 2;
    do {
      iVar7 = _rand();
      iVar7 = iVar7 % DAT_009e7138;
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
      pcVar2 = _strstr((char *)0x0,"coin");
      cVar3 = _DAT_00b18314;
      if (pcVar2 == (char *)0x0) {
LAB_004723f7:
        _DAT_00b18314 = cVar3;
        (&DAT_009e7160)[iVar7 >> 3] = (&DAT_009e7160)[iVar7 >> 3] | '\x01' << ((byte)iVar7 & 7);
      }
      else {
        cVar3 = _clock();
        uVar4 = _rand();
        uVar4 = uVar4 & 0x80000003;
        bVar8 = uVar4 == 0;
        if ((int)uVar4 < 0) {
          bVar8 = (uVar4 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar8) goto LAB_004723f7;
      }
      iVar6 = iVar6 + -1;
      iVar7 = DAT_009e7138;
    } while (iVar6 != 0);
  }
  iVar6 = 0;
  bVar5 = (byte)iVar7 & 7;
  bVar5 = '\x01' << bVar5 | 1U >> 8 - bVar5;
  if (0 < DAT_009e715c) {
    do {
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
      if (cRam00000000 != '\0') {
        (&DAT_009e7160)[iVar7 >> 3] = (&DAT_009e7160)[iVar7 >> 3] | bVar5;
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 1;
      bVar5 = bVar5 << 1 | (char)bVar5 < '\0';
    } while (iVar6 < DAT_009e715c);
  }
  iVar7 = iVar7 + 7 >> 3;
  iVar6 = 0;
  if (0 < DAT_009e7138) {
    do {
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
      if (cRam00000000 != '\0') {
        (&DAT_009e7160)[iVar7] = cRam00000000;
        iVar7 = iVar7 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_009e7138);
  }
  iVar6 = 0;
  if (0 < DAT_009e7148) {
    do {
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
      (&DAT_009e7160)[iVar7] = cRam00000000;
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar6 < DAT_009e7148);
  }
  cVar1 = ggpo_synchronize_input(DAT_00b1a804,&DAT_009e7160,iVar7 + 1,2);
  if (cVar1 != '\0') {
    iVar7 = 0;
    if (0 < DAT_009e7138) {
      do {
        (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_009e7138);
    }
    iVar6 = 0;
    bVar5 = (byte)iVar7 & 7;
    bVar5 = '\x01' << bVar5 | 1U >> 8 - bVar5;
    if (0 < DAT_009e715c) {
      do {
        (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
        cRam00000000 = ((&DAT_009e7160)[iVar7 >> 3] & bVar5) != 0;
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 1;
        bVar5 = bVar5 << 1 | (char)bVar5 < '\0';
      } while (iVar6 < DAT_009e715c);
    }
    iVar6 = 0;
    if (0 < DAT_009e7138) {
      do {
        (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_009e7138);
    }
    iVar6 = 0;
    if (0 < DAT_009e7148) {
      pcVar2 = &DAT_009e7160 + (iVar7 + 7 >> 3);
      do {
        (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
        cRam00000000 = *pcVar2;
        iVar6 = iVar6 + 1;
        pcVar2 = pcVar2 + 1;
      } while (iVar6 < DAT_009e7148);
    }
    iVar7 = 1;
    do {
      if ((&DAT_009e7138)[iVar7] != 0) {
        iVar6 = 0;
        if (0 < (&DAT_009e7138)[iVar7]) {
          do {
            (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
            iVar6 = iVar6 + 1;
          } while (iVar6 < (&DAT_009e7138)[iVar7]);
        }
        iVar6 = 0;
        if (0 < (&DAT_009e7138)[iVar7]) {
          do {
            (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
            iVar6 = iVar6 + 1;
          } while (iVar6 < (&DAT_009e7138)[iVar7]);
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 4);
    return 0;
  }
  return 1;
}
