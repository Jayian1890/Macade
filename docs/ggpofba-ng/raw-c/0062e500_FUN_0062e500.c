
void FUN_0062e500(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00b1a9b8;
  do {
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0xb1a9d0);
  ggpo_client_set_game_event(param_1,6000,&DAT_00802d10);
  return;
}
