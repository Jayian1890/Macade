# 10019b2b `___wtomb_environ`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019b2b |
| `name` | ___wtomb_environ |
| `namespace` | Global |
| `signature` | int __cdecl ___wtomb_environ(void) |
| `size_bytes` | 151 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___wtomb_environ |

## Decompiled C

```c

/* Library Function - Single Match
    ___wtomb_environ
   
   Library: Visual Studio 2008 Release */

int __cdecl ___wtomb_environ(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Count;
  int iVar1;
  undefined4 *puVar2;
  char *local_8;
  
  local_8 = (LPSTR)0x0;
  lpWideCharStr = (LPCWSTR)*DAT_10038a54;
  puVar2 = DAT_10038a54;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Count = WideCharToMultiByte(0,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((_Count == 0) || (local_8 = __calloc_crt(_Count,1), local_8 == (LPSTR)0x0)) break;
    iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)*puVar2,-1,local_8,_Count,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      _free(local_8);
      return -1;
    }
    iVar1 = ___crtsetenv(&local_8,0);
    if ((iVar1 < 0) && (local_8 != (LPSTR)0x0)) {
      _free(local_8);
      local_8 = (LPSTR)0x0;
    }
    puVar2 = puVar2 + 1;
    lpWideCharStr = (LPCWSTR)*puVar2;
  }
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019b55` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `10019b61` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `10019b7b` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `10019b86` | `1001e40d` | `UNCONDITIONAL_CALL` | ___crtsetenv | `1001e40d` |
| `10019b99` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10019bba` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `10012cf1` | __getenv_helper_nolock |
| `1001e494` | ___crtsetenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10019b37` | `10038a54` | `READ` | DAT_10038a54 |
| `10019b46` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019b2b` | `8b ff` | `MOV EDI,EDI` |
| `10019b2d` | `55` | `PUSH EBP` |
| `10019b2e` | `8b ec` | `MOV EBP,ESP` |
| `10019b30` | `51` | `PUSH ECX` |
| `10019b31` | `51` | `PUSH ECX` |
| `10019b32` | `53` | `PUSH EBX` |
| `10019b33` | `56` | `PUSH ESI` |
| `10019b34` | `33 f6` | `XOR ESI,ESI` |
| `10019b36` | `57` | `PUSH EDI` |
| `10019b37` | `8b 3d 54 8a 03 10` | `MOV EDI,dword ptr [0x10038a54]` |
| `10019b3d` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `10019b40` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10019b42` | `3b c6` | `CMP EAX,ESI` |
| `10019b44` | `74 65` | `JZ 0x10019bab` |
| `10019b46` | `8b 1d 5c e0 02 10` | `MOV EBX,dword ptr [0x1002e05c]` |
| `10019b4c` | `56` | `PUSH ESI` |
| `10019b4d` | `56` | `PUSH ESI` |
| `10019b4e` | `56` | `PUSH ESI` |
| `10019b4f` | `56` | `PUSH ESI` |
| `10019b50` | `6a ff` | `PUSH -0x1` |
| `10019b52` | `50` | `PUSH EAX` |
| `10019b53` | `56` | `PUSH ESI` |
| `10019b54` | `56` | `PUSH ESI` |
| `10019b55` | `ff d3` | `CALL EBX` |
| `10019b57` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10019b5a` | `3b c6` | `CMP EAX,ESI` |
| `10019b5c` | `74 54` | `JZ 0x10019bb2` |
| `10019b5e` | `6a 01` | `PUSH 0x1` |
| `10019b60` | `50` | `PUSH EAX` |
| `10019b61` | `e8 ae 09 00 00` | `CALL 0x1001a514` |
| `10019b66` | `59` | `POP ECX` |
| `10019b67` | `59` | `POP ECX` |
| `10019b68` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10019b6b` | `3b c6` | `CMP EAX,ESI` |
| `10019b6d` | `74 43` | `JZ 0x10019bb2` |
| `10019b6f` | `56` | `PUSH ESI` |
| `10019b70` | `56` | `PUSH ESI` |
| `10019b71` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `10019b74` | `50` | `PUSH EAX` |
| `10019b75` | `6a ff` | `PUSH -0x1` |
| `10019b77` | `ff 37` | `PUSH dword ptr [EDI]` |
| `10019b79` | `56` | `PUSH ESI` |
| `10019b7a` | `56` | `PUSH ESI` |
| `10019b7b` | `ff d3` | `CALL EBX` |
| `10019b7d` | `85 c0` | `TEST EAX,EAX` |
| `10019b7f` | `74 36` | `JZ 0x10019bb7` |
| `10019b81` | `8d 45 fc` | `LEA EAX,[EBP + -0x4]` |
| `10019b84` | `56` | `PUSH ESI` |
| `10019b85` | `50` | `PUSH EAX` |
| `10019b86` | `e8 82 48 00 00` | `CALL 0x1001e40d` |
| `10019b8b` | `59` | `POP ECX` |
| `10019b8c` | `59` | `POP ECX` |
| `10019b8d` | `85 c0` | `TEST EAX,EAX` |
| `10019b8f` | `7d 11` | `JGE 0x10019ba2` |
| `10019b91` | `39 75 fc` | `CMP dword ptr [EBP + -0x4],ESI` |
| `10019b94` | `74 0c` | `JZ 0x10019ba2` |
| `10019b96` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10019b99` | `e8 a3 76 ff ff` | `CALL 0x10011241` |
| `10019b9e` | `59` | `POP ECX` |
| `10019b9f` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `10019ba2` | `83 c7 04` | `ADD EDI,0x4` |
| `10019ba5` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `10019ba7` | `3b c6` | `CMP EAX,ESI` |
| `10019ba9` | `75 a1` | `JNZ 0x10019b4c` |
| `10019bab` | `33 c0` | `XOR EAX,EAX` |
| `10019bad` | `5f` | `POP EDI` |
| `10019bae` | `5e` | `POP ESI` |
| `10019baf` | `5b` | `POP EBX` |
| `10019bb0` | `c9` | `LEAVE` |
| `10019bb1` | `c3` | `RET` |
| `10019bb2` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10019bb5` | `eb f6` | `JMP 0x10019bad` |
| `10019bb7` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10019bba` | `e8 82 76 ff ff` | `CALL 0x10011241` |
| `10019bbf` | `59` | `POP ECX` |
| `10019bc0` | `eb f0` | `JMP 0x10019bb2` |
