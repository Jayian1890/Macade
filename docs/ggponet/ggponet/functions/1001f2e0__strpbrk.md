# 1001f2e0 `_strpbrk`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f2e0 |
| `name` | _strpbrk |
| `namespace` | Global |
| `signature` | char * __cdecl _strpbrk(char * _Str, char * _Control) |
| `size_bytes` | 64 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strpbrk |

## Decompiled C

```c

/* Library Function - Single Match
    _strpbrk
   
   Library: Visual Studio */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
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
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)0x0;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
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
| `1001f2e0` | `55` | `PUSH EBP` |
| `1001f2e1` | `8b ec` | `MOV EBP,ESP` |
| `1001f2e3` | `56` | `PUSH ESI` |
| `1001f2e4` | `33 c0` | `XOR EAX,EAX` |
| `1001f2e6` | `50` | `PUSH EAX` |
| `1001f2e7` | `50` | `PUSH EAX` |
| `1001f2e8` | `50` | `PUSH EAX` |
| `1001f2e9` | `50` | `PUSH EAX` |
| `1001f2ea` | `50` | `PUSH EAX` |
| `1001f2eb` | `50` | `PUSH EAX` |
| `1001f2ec` | `50` | `PUSH EAX` |
| `1001f2ed` | `50` | `PUSH EAX` |
| `1001f2ee` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1001f2f1` | `8d 49 00` | `LEA ECX,[ECX]` |
| `1001f2f4` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1001f2f6` | `0a c0` | `OR AL,AL` |
| `1001f2f8` | `74 09` | `JZ 0x1001f303` |
| `1001f2fa` | `83 c2 01` | `ADD EDX,0x1` |
| `1001f2fd` | `0f ab 04 24` | `BTS [ESP],EAX` |
| `1001f301` | `eb f1` | `JMP 0x1001f2f4` |
| `1001f303` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001f306` | `8b ff` | `MOV EDI,EDI` |
| `1001f308` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001f30a` | `0a c0` | `OR AL,AL` |
| `1001f30c` | `74 0c` | `JZ 0x1001f31a` |
| `1001f30e` | `83 c6 01` | `ADD ESI,0x1` |
| `1001f311` | `0f a3 04 24` | `BT [ESP],EAX` |
| `1001f315` | `73 f1` | `JNC 0x1001f308` |
| `1001f317` | `8d 46 ff` | `LEA EAX,[ESI + -0x1]` |
| `1001f31a` | `83 c4 20` | `ADD ESP,0x20` |
| `1001f31d` | `5e` | `POP ESI` |
| `1001f31e` | `c9` | `LEAVE` |
| `1001f31f` | `c3` | `RET` |
