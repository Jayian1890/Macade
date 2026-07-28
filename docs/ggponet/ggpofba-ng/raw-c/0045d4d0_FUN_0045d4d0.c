
undefined4 FUN_0045d4d0(void)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (((DAT_00b1ad08 != 0) && (unaff_ESI == 0)) && (DAT_00b189ce != '\0')) {
    (**(code **)((&PTR_PTR_00875898)[DAT_00b19808] + 0xc))();
  }
  if (DAT_00ad74c4 != 0) {
    if (unaff_ESI == 0) {
      DAT_009eb5a8 = DAT_009eb5a8 + 1;
      DAT_009eb574 = DAT_009eb574 + 1;
      if (DAT_00ad74dc == 0) {
        if (DAT_00ad7554 == 2) {
          FUN_0045d390();
          iVar1 = FUN_00466000();
          if (iVar1 != 0) {
            DAT_00ad74d0 = 1;
            DAT_00ad74cc = 1;
            FUN_00465610();
            FUN_00560270();
          }
        }
        else {
          FUN_0045d390();
        }
      }
      else {
        FUN_0045d390();
        iVar1 = FUN_004722f0();
        if (iVar1 != 0) {
          return 0;
        }
      }
      if (DAT_00ad7554 == 1) {
        FUN_00465f20();
      }
      if (unaff_EDI == 0) {
        DAT_00b196fc = 0;
        FUN_0052e130();
        (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x58))();
      }
      else {
        DAT_009eb59c = DAT_009eb59c + 1;
        iVar1 = FUN_00551470();
        if (iVar1 != 0) {
          FUN_0055f450();
        }
      }
      if (DAT_00ad74dc != 0) {
        FUN_0062df40();
      }
      if ((DAT_00ad74c9 != '\0') && (DAT_00ad74d8 < DAT_009eb59c)) {
        FUN_0045d3d0();
        DAT_00ad74d8 = DAT_009eb59c + 0x1e;
      }
    }
    else {
      FUN_0045d390();
      if ((unaff_ESI != DAT_00b1ad04) && (DAT_00b189ce != '\0')) {
        (**(code **)((&PTR_PTR_00875898)[DAT_00b19808] + 0xc))();
        DAT_00b1ad04 = unaff_ESI;
        DAT_00b1ad08 = unaff_EDI;
        return 0;
      }
    }
    DAT_00b1ad04 = unaff_ESI;
    DAT_00b1ad08 = unaff_EDI;
    return 0;
  }
  return 1;
}
