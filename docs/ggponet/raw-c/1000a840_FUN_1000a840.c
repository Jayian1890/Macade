
int FUN_1000a840(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  if (in_ECX != param_1) {
    puVar1 = (undefined4 *)FUN_1000a960(local_c);
    uVar3 = puVar1[1];
    uVar2 = *puVar1;
    puVar1 = (undefined4 *)FUN_1000a930(local_14);
    FUN_1000b010(*puVar1,puVar1[1],uVar2,uVar3);
  }
  return in_ECX;
}
