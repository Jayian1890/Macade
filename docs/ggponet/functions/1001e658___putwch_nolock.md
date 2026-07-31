# 1001e658 `__putwch_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e658 |
| `name` | __putwch_nolock |
| `namespace` | Global |
| `signature` | wint_t __cdecl __putwch_nolock(wchar_t _WCh) |
| `size_bytes` | 197 |
| `stack_frame_size` | 26 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __putwch_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __putwch_nolock
   
   Library: Visual Studio 2008 Release */

wint_t __cdecl __putwch_nolock(wchar_t _WCh)

{
  wint_t wVar1;
  BOOL BVar2;
  DWORD DVar3;
  UINT CodePage;
  wchar_t *lpWideCharStr;
  int cchWideChar;
  CHAR *lpMultiByteStr;
  int cbMultiByte;
  LPCSTR lpDefaultChar;
  LPBOOL lpUsedDefaultChar;
  DWORD local_14;
  CHAR local_10 [8];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (DAT_10038250 != 0) {
    if (DAT_10038374 == (HANDLE)0xfffffffe) {
      ___initconout();
    }
    if (DAT_10038374 == (HANDLE)0xffffffff) goto LAB_1001e704;
    BVar2 = WriteConsoleW(DAT_10038374,&_WCh,1,&local_14,(LPVOID)0x0);
    if (BVar2 != 0) {
      DAT_10038250 = 1;
      goto LAB_1001e704;
    }
    if ((DAT_10038250 != 2) || (DVar3 = GetLastError(), DVar3 != 0x78)) goto LAB_1001e704;
    DAT_10038250 = 0;
  }
  lpUsedDefaultChar = (LPBOOL)0x0;
  lpDefaultChar = (LPCSTR)0x0;
  cbMultiByte = 5;
  lpMultiByteStr = local_10;
  cchWideChar = 1;
  lpWideCharStr = &_WCh;
  DVar3 = 0;
  CodePage = GetConsoleOutputCP();
  DVar3 = WideCharToMultiByte(CodePage,DVar3,lpWideCharStr,cchWideChar,lpMultiByteStr,cbMultiByte,
                              lpDefaultChar,lpUsedDefaultChar);
  if (DAT_10038374 != (HANDLE)0xffffffff) {
    WriteConsoleA(DAT_10038374,local_10,DVar3,&local_14,(LPVOID)0x0);
  }
LAB_1001e704:
  wVar1 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return wVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e67e` | `1001fae1` | `UNCONDITIONAL_CALL` | ___initconout | `1001fae1` |
| `1001e6a0` | `EXTERNAL:00000019` | `COMPUTED_CALL` | KERNEL32.DLL::WriteConsoleW | `` |
| `1001e6b3` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001e6d3` | `EXTERNAL:0000001a` | `COMPUTED_CALL` | KERNEL32.DLL::GetConsoleOutputCP | `` |
| `1001e6da` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001e6f6` | `EXTERNAL:0000001b` | `COMPUTED_CALL` | KERNEL32.DLL::WriteConsoleA | `` |
| `1001e70a` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `10019efb` | __write_nolock |
| `10019f28` | __write_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001e660` | `10037490` | `READ` | DAT_10037490 |
| `1001e66d` | `10038250` | `READ` | DAT_10038250 |
| `1001e675` | `10038374` | `READ` | DAT_10038374 |
| `1001e683` | `10038374` | `READ` | DAT_10038374 |
| `1001e6a0` | `1002e01c` | `READ` | PTR_WriteConsoleW_1002e01c |
| `1001e6aa` | `10038250` | `READ` | DAT_10038250 |
| `1001e6b3` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001e6be` | `10038250` | `WRITE` | DAT_10038250 |
| `1001e6d3` | `1002e020` | `READ` | PTR_GetConsoleOutputCP_1002e020 |
| `1001e6da` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `1001e6e0` | `10038374` | `READ` | DAT_10038374 |
| `1001e6f6` | `1002e024` | `READ` | PTR_WriteConsoleA_1002e024 |
| `1001e711` | `10038250` | `WRITE` | DAT_10038250 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e658` | `8b ff` | `MOV EDI,EDI` |
| `1001e65a` | `55` | `PUSH EBP` |
| `1001e65b` | `8b ec` | `MOV EBP,ESP` |
| `1001e65d` | `83 ec 10` | `SUB ESP,0x10` |
| `1001e660` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001e665` | `33 c5` | `XOR EAX,EBP` |
| `1001e667` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001e66a` | `56` | `PUSH ESI` |
| `1001e66b` | `33 f6` | `XOR ESI,ESI` |
| `1001e66d` | `39 35 50 82 03 10` | `CMP dword ptr [0x10038250],ESI` |
| `1001e673` | `74 4f` | `JZ 0x1001e6c4` |
| `1001e675` | `83 3d 74 83 03 10 fe` | `CMP dword ptr [0x10038374],-0x2` |
| `1001e67c` | `75 05` | `JNZ 0x1001e683` |
| `1001e67e` | `e8 5e 14 00 00` | `CALL 0x1001fae1` |
| `1001e683` | `a1 74 83 03 10` | `MOV EAX,[0x10038374]` |
| `1001e688` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001e68b` | `75 07` | `JNZ 0x1001e694` |
| `1001e68d` | `b8 ff ff 00 00` | `MOV EAX,0xffff` |
| `1001e692` | `eb 70` | `JMP 0x1001e704` |
| `1001e694` | `56` | `PUSH ESI` |
| `1001e695` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001e698` | `51` | `PUSH ECX` |
| `1001e699` | `6a 01` | `PUSH 0x1` |
| `1001e69b` | `8d 4d 08` | `LEA ECX,[EBP + 0x8]` |
| `1001e69e` | `51` | `PUSH ECX` |
| `1001e69f` | `50` | `PUSH EAX` |
| `1001e6a0` | `ff 15 1c e0 02 10` | `CALL dword ptr [0x1002e01c]` |
| `1001e6a6` | `85 c0` | `TEST EAX,EAX` |
| `1001e6a8` | `75 67` | `JNZ 0x1001e711` |
| `1001e6aa` | `83 3d 50 82 03 10 02` | `CMP dword ptr [0x10038250],0x2` |
| `1001e6b1` | `75 da` | `JNZ 0x1001e68d` |
| `1001e6b3` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001e6b9` | `83 f8 78` | `CMP EAX,0x78` |
| `1001e6bc` | `75 cf` | `JNZ 0x1001e68d` |
| `1001e6be` | `89 35 50 82 03 10` | `MOV dword ptr [0x10038250],ESI` |
| `1001e6c4` | `56` | `PUSH ESI` |
| `1001e6c5` | `56` | `PUSH ESI` |
| `1001e6c6` | `6a 05` | `PUSH 0x5` |
| `1001e6c8` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `1001e6cb` | `50` | `PUSH EAX` |
| `1001e6cc` | `6a 01` | `PUSH 0x1` |
| `1001e6ce` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `1001e6d1` | `50` | `PUSH EAX` |
| `1001e6d2` | `56` | `PUSH ESI` |
| `1001e6d3` | `ff 15 20 e0 02 10` | `CALL dword ptr [0x1002e020]` |
| `1001e6d9` | `50` | `PUSH EAX` |
| `1001e6da` | `ff 15 5c e0 02 10` | `CALL dword ptr [0x1002e05c]` |
| `1001e6e0` | `8b 0d 74 83 03 10` | `MOV ECX,dword ptr [0x10038374]` |
| `1001e6e6` | `83 f9 ff` | `CMP ECX,-0x1` |
| `1001e6e9` | `74 a2` | `JZ 0x1001e68d` |
| `1001e6eb` | `56` | `PUSH ESI` |
| `1001e6ec` | `8d 55 f0` | `LEA EDX,[EBP + -0x10]` |
| `1001e6ef` | `52` | `PUSH EDX` |
| `1001e6f0` | `50` | `PUSH EAX` |
| `1001e6f1` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `1001e6f4` | `50` | `PUSH EAX` |
| `1001e6f5` | `51` | `PUSH ECX` |
| `1001e6f6` | `ff 15 24 e0 02 10` | `CALL dword ptr [0x1002e024]` |
| `1001e6fc` | `85 c0` | `TEST EAX,EAX` |
| `1001e6fe` | `74 8d` | `JZ 0x1001e68d` |
| `1001e700` | `66 8b 45 08` | `MOV AX,word ptr [EBP + 0x8]` |
| `1001e704` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001e707` | `33 cd` | `XOR ECX,EBP` |
| `1001e709` | `5e` | `POP ESI` |
| `1001e70a` | `e8 bc 25 ff ff` | `CALL 0x10010ccb` |
| `1001e70f` | `c9` | `LEAVE` |
| `1001e710` | `c3` | `RET` |
| `1001e711` | `c7 05 50 82 03 10 01 00 00 00` | `MOV dword ptr [0x10038250],0x1` |
| `1001e71b` | `eb e3` | `JMP 0x1001e700` |
