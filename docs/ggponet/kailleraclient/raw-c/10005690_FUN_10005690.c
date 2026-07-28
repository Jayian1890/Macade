
void FUN_10005690(void)

{
  char *_Source;
  size_t _Count;
  
  DAT_1000ef80 = FUN_100019d0(DAT_1000ef90,s_option_sound_1000e444,1);
  DAT_1000eef4 = FUN_100019d0(DAT_1000ef90,s_option_flood_1000e434,1);
  DAT_1000eee8 = FUN_100019d0(DAT_1000ef90,s_option_floodmsg_1000e424,10);
  DAT_1000eef8 = FUN_100019d0(DAT_1000ef90,s_option_floodtime_1000e410,10);
  DAT_1000ef8c = FUN_100019d0(DAT_1000ef90,s_option_joinmsg_1000e400,1);
  _Count = 0x7f;
  _Source = (char *)FUN_10001ba0(DAT_1000ef90,s_option_quitmsg_1000e3dc,
                                 s_Normal_client_exit_1000e3ec);
  strncpy(&DAT_1000ef00,_Source,_Count);
  DAT_1000ef7f = 0;
  return;
}
