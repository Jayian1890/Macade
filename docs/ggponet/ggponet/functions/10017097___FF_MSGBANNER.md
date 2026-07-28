# 10017097 `__FF_MSGBANNER`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017097 |
| `name` | __FF_MSGBANNER |
| `namespace` | Global |
| `signature` | void __cdecl __FF_MSGBANNER(void) |
| `size_bytes` | 57 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __FF_MSGBANNER |

## Decompiled C

```c

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 2008 Release */

void __cdecl __FF_MSGBANNER(void)

{
  int iVar1;
  
  iVar1 = __set_error_mode(3);
  if (iVar1 != 1) {
    iVar1 = __set_error_mode(3);
    if (iVar1 != 0) {
      return;
    }
    if (DAT_10038a80 != 1) {
      return;
    }
  }
  __NMSG_WRITE(0xfc);
  __NMSG_WRITE(0xff);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017099` | `1001ca87` | `UNCONDITIONAL_CALL` | __set_error_mode | `1001ca87` |
| `100170a6` | `1001ca87` | `UNCONDITIONAL_CALL` | __set_error_mode | `1001ca87` |
| `100170be` | `10016eec` | `UNCONDITIONAL_CALL` | __NMSG_WRITE | `10016eec` |
| `100170c8` | `10016eec` | `UNCONDITIONAL_CALL` | __NMSG_WRITE | `10016eec` |

## Callers

| From | Function |
| --- | --- |
| `10012441` | __amsg_exit |
| `1001615c` | __mtinitlocknum |
| `10011341` | _malloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100170b0` | `10038a80` | `READ` | DAT_10038a80 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017097` | `6a 03` | `PUSH 0x3` |
| `10017099` | `e8 e9 59 00 00` | `CALL 0x1001ca87` |
| `1001709e` | `59` | `POP ECX` |
| `1001709f` | `83 f8 01` | `CMP EAX,0x1` |
| `100170a2` | `74 15` | `JZ 0x100170b9` |
| `100170a4` | `6a 03` | `PUSH 0x3` |
| `100170a6` | `e8 dc 59 00 00` | `CALL 0x1001ca87` |
| `100170ab` | `59` | `POP ECX` |
| `100170ac` | `85 c0` | `TEST EAX,EAX` |
| `100170ae` | `75 1f` | `JNZ 0x100170cf` |
| `100170b0` | `83 3d 80 8a 03 10 01` | `CMP dword ptr [0x10038a80],0x1` |
| `100170b7` | `75 16` | `JNZ 0x100170cf` |
| `100170b9` | `68 fc 00 00 00` | `PUSH 0xfc` |
| `100170be` | `e8 29 fe ff ff` | `CALL 0x10016eec` |
| `100170c3` | `68 ff 00 00 00` | `PUSH 0xff` |
| `100170c8` | `e8 1f fe ff ff` | `CALL 0x10016eec` |
| `100170cd` | `59` | `POP ECX` |
| `100170ce` | `59` | `POP ECX` |
| `100170cf` | `c3` | `RET` |
