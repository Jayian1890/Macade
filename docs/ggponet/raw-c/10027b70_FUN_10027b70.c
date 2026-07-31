
void FUN_10027b70(char *param_1)

{
  size_t sVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_1c4 [28];
  int local_1a8;
  char *local_1a4;
  char *local_1a0;
  size_t local_19c;
  char *local_198;
  undefined4 local_194;
  int local_190;
  char local_18c [64];
  void *local_14c;
  int local_148;
  size_t local_144;
  int local_140;
  undefined1 local_13c [256];
  uint local_3c;
  char *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  size_t local_14;
  int local_10;
  char *local_c;
  FILE *local_8;
  
  local_3c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_8 = _fopen(param_1,"rb");
  if (local_8 != (FILE *)0x0) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    GetFileAttributesExA(param_1,GetFileExInfoStandard,&local_34);
    local_19c = local_14;
    local_198 = _malloc(local_14);
    local_144 = 0;
    local_140 = 0;
    local_10 = 0;
    local_190 = 0;
    local_194 = 0;
    _fread(local_198,1,local_19c,local_8);
    sVar1 = _strlen(local_198);
    local_38 = local_198 + sVar1 + 1;
    local_c = strchr(local_198,10);
    while ((local_c != (char *)0x0 && (local_c = local_c + 1, *local_c != '\0'))) {
      local_1a0 = strchr(local_c,9);
      if (local_1a0 == (char *)0x0) {
        local_1a0 = (char *)0x0;
        goto LAB_10027f4e;
      }
      *local_1a0 = '\0';
      local_1a0 = local_1a0 + 1;
      local_1a4 = strchr(local_1a0,10);
      if (local_1a4 == (char *)0x0) goto LAB_10027f4e;
      *local_1a4 = '\0';
      iVar2 = _strcmp(local_c,"version");
      if (iVar2 == 0) {
        FUN_10011480(local_18c,local_1a0);
      }
      else {
        iVar2 = _strcmp(local_c,"game");
        if (iVar2 == 0) {
          FUN_10011480(local_13c,local_1a0);
        }
        else {
          iVar2 = _strcmp(local_c,"payload size");
          if (iVar2 == 0) {
            iVar2 = FUN_10011a64(local_1a0);
            local_144 = iVar2 + 1;
          }
          else {
            iVar2 = _strcmp(local_c,"compressed state size");
            if (iVar2 == 0) {
              local_194 = FUN_10011a64(local_1a0);
            }
            else {
              iVar2 = _strcmp(local_c,"state size");
              if (iVar2 == 0) {
                local_140 = FUN_10011a64(local_1a0);
              }
              else {
                iVar2 = _strcmp(local_c,"input size");
                if (iVar2 == 0) {
                  local_10 = FUN_10011a64(local_1a0);
                }
                else {
                  iVar2 = _strcmp(local_c,"input count");
                  if (iVar2 == 0) {
                    local_190 = FUN_10011a64(local_1a0);
                  }
                }
              }
            }
          }
        }
      }
      local_c = local_1a4;
    }
    _fclose(local_8);
    local_14c = _malloc(local_144);
    FUN_1000b460(local_38,local_194);
    local_148 = (int)local_14c + local_140;
    for (local_1a8 = 0; local_1a8 < local_190; local_1a8 = local_1a8 + 1) {
      FUN_10022310(0,local_1a8 * local_10 + local_148,local_10);
      FUN_10002de0(local_1c4);
    }
    iVar2 = _strcmp(local_18c,"0.20");
    if (iVar2 == 0) {
      FUN_10002e00();
    }
    (**(code **)(in_ECX + 4))(local_13c);
    (**(code **)(in_ECX + 0xc))(local_14c,local_140);
  }
LAB_10027f4e:
  __security_check_cookie(local_3c ^ (uint)&stack0xfffffffc);
  return;
}
