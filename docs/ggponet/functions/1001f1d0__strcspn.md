# 1001f1d0 `_strcspn`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f1d0 |
| `name` | _strcspn |
| `namespace` | Global |
| `signature` | size_t __cdecl _strcspn(char * _Str, char * _Control) |
| `size_bytes` | 70 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strcspn |

## Decompiled C

```c

/* Library Function - Single Match
    _strcspn
   
   Library: Visual Studio */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = _Str + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f1d0` | `55` | `PUSH EBP` |
| `1001f1d1` | `8b ec` | `MOV EBP,ESP` |
| `1001f1d3` | `56` | `PUSH ESI` |
| `1001f1d4` | `33 c0` | `XOR EAX,EAX` |
| `1001f1d6` | `50` | `PUSH EAX` |
| `1001f1d7` | `50` | `PUSH EAX` |
| `1001f1d8` | `50` | `PUSH EAX` |
| `1001f1d9` | `50` | `PUSH EAX` |
| `1001f1da` | `50` | `PUSH EAX` |
| `1001f1db` | `50` | `PUSH EAX` |
| `1001f1dc` | `50` | `PUSH EAX` |
| `1001f1dd` | `50` | `PUSH EAX` |
| `1001f1de` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1001f1e1` | `8d 49 00` | `LEA ECX,[ECX]` |
| `1001f1e4` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1001f1e6` | `0a c0` | `OR AL,AL` |
| `1001f1e8` | `74 09` | `JZ 0x1001f1f3` |
| `1001f1ea` | `83 c2 01` | `ADD EDX,0x1` |
| `1001f1ed` | `0f ab 04 24` | `BTS [ESP],EAX` |
| `1001f1f1` | `eb f1` | `JMP 0x1001f1e4` |
| `1001f1f3` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001f1f6` | `83 c9 ff` | `OR ECX,0xffffffff` |
| `1001f1f9` | `8d 49 00` | `LEA ECX,[ECX]` |
| `1001f1fc` | `83 c1 01` | `ADD ECX,0x1` |
| `1001f1ff` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001f201` | `0a c0` | `OR AL,AL` |
| `1001f203` | `74 09` | `JZ 0x1001f20e` |
| `1001f205` | `83 c6 01` | `ADD ESI,0x1` |
| `1001f208` | `0f a3 04 24` | `BT [ESP],EAX` |
| `1001f20c` | `73 ee` | `JNC 0x1001f1fc` |
| `1001f20e` | `8b c1` | `MOV EAX,ECX` |
| `1001f210` | `83 c4 20` | `ADD ESP,0x20` |
| `1001f213` | `5e` | `POP ESI` |
| `1001f214` | `c9` | `LEAVE` |
| `1001f215` | `c3` | `RET` |
