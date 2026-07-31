# 1001aa6a `___security_init_cookie`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001aa6a |
| `name` | ___security_init_cookie |
| `namespace` | Global |
| `signature` | void __cdecl ___security_init_cookie(void) |
| `size_bytes` | 150 |
| `stack_frame_size` | 24 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___security_init_cookie |

## Decompiled C

```c

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2008 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  LARGE_INTEGER local_14;
  _FILETIME local_c;
  
  local_c.dwLowDateTime = 0;
  local_c.dwHighDateTime = 0;
  if ((DAT_10037490 == 0xbb40e64e) || ((DAT_10037490 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10037490 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10037490 == 0xbb40e64e) {
      DAT_10037490 = 0xbb40e64f;
    }
    else if ((DAT_10037490 & 0xffff0000) == 0) {
      DAT_10037490 = DAT_10037490 | DAT_10037490 << 0x10;
    }
  }
  DAT_10037494 = ~DAT_10037490;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001aaa1` | `EXTERNAL:0000005e` | `COMPUTED_CALL` | KERNEL32.DLL::GetSystemTimeAsFileTime | `` |
| `1001aaad` | `EXTERNAL:0000002b` | `COMPUTED_CALL` | KERNEL32.DLL::GetCurrentProcessId | `` |
| `1001aab5` | `EXTERNAL:0000003a` | `COMPUTED_CALL` | KERNEL32.DLL::GetCurrentThreadId | `` |
| `1001aabd` | `EXTERNAL:0000005d` | `COMPUTED_CALL` | KERNEL32.DLL::GetTickCount | `` |
| `1001aac9` | `EXTERNAL:0000005c` | `COMPUTED_CALL` | KERNEL32.DLL::QueryPerformanceCounter | `` |

## Callers

| From | Function |
| --- | --- |
| `100148a5` | entry |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001aa72` | `10037490` | `READ` | DAT_10037490 |
| `1001aa95` | `10037494` | `WRITE` | DAT_10037494 |
| `1001aaa1` | `1002e130` | `READ` | PTR_GetSystemTimeAsFileTime_1002e130 |
| `1001aaad` | `1002e064` | `READ` | PTR_GetCurrentProcessId_1002e064 |
| `1001aab5` | `1002e0a0` | `READ` | PTR_GetCurrentThreadId_1002e0a0 |
| `1001aabd` | `1002e12c` | `READ` | PTR_GetTickCount_1002e12c |
| `1001aac9` | `1002e128` | `READ` | PTR_QueryPerformanceCounter_1002e128 |
| `1001aaed` | `10037490` | `WRITE` | DAT_10037490 |
| `1001aaf5` | `10037494` | `WRITE` | DAT_10037494 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001aa6a` | `8b ff` | `MOV EDI,EDI` |
| `1001aa6c` | `55` | `PUSH EBP` |
| `1001aa6d` | `8b ec` | `MOV EBP,ESP` |
| `1001aa6f` | `83 ec 10` | `SUB ESP,0x10` |
| `1001aa72` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001aa77` | `83 65 f8 00` | `AND dword ptr [EBP + -0x8],0x0` |
| `1001aa7b` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001aa7f` | `53` | `PUSH EBX` |
| `1001aa80` | `57` | `PUSH EDI` |
| `1001aa81` | `bf 4e e6 40 bb` | `MOV EDI,0xbb40e64e` |
| `1001aa86` | `bb 00 00 ff ff` | `MOV EBX,0xffff0000` |
| `1001aa8b` | `3b c7` | `CMP EAX,EDI` |
| `1001aa8d` | `74 0d` | `JZ 0x1001aa9c` |
| `1001aa8f` | `85 c3` | `TEST EBX,EAX` |
| `1001aa91` | `74 09` | `JZ 0x1001aa9c` |
| `1001aa93` | `f7 d0` | `NOT EAX` |
| `1001aa95` | `a3 94 74 03 10` | `MOV [0x10037494],EAX` |
| `1001aa9a` | `eb 60` | `JMP 0x1001aafc` |
| `1001aa9c` | `56` | `PUSH ESI` |
| `1001aa9d` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001aaa0` | `50` | `PUSH EAX` |
| `1001aaa1` | `ff 15 30 e1 02 10` | `CALL dword ptr [0x1002e130]` |
| `1001aaa7` | `8b 75 fc` | `MOV ESI,dword ptr [EBP + -0x4]` |
| `1001aaaa` | `33 75 f8` | `XOR ESI,dword ptr [EBP + -0x8]` |
| `1001aaad` | `ff 15 64 e0 02 10` | `CALL dword ptr [0x1002e064]` |
| `1001aab3` | `33 f0` | `XOR ESI,EAX` |
| `1001aab5` | `ff 15 a0 e0 02 10` | `CALL dword ptr [0x1002e0a0]` |
| `1001aabb` | `33 f0` | `XOR ESI,EAX` |
| `1001aabd` | `ff 15 2c e1 02 10` | `CALL dword ptr [0x1002e12c]` |
| `1001aac3` | `33 f0` | `XOR ESI,EAX` |
| `1001aac5` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001aac8` | `50` | `PUSH EAX` |
| `1001aac9` | `ff 15 28 e1 02 10` | `CALL dword ptr [0x1002e128]` |
| `1001aacf` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1001aad2` | `33 45 f0` | `XOR EAX,dword ptr [EBP + -0x10]` |
| `1001aad5` | `33 f0` | `XOR ESI,EAX` |
| `1001aad7` | `3b f7` | `CMP ESI,EDI` |
| `1001aad9` | `75 07` | `JNZ 0x1001aae2` |
| `1001aadb` | `be 4f e6 40 bb` | `MOV ESI,0xbb40e64f` |
| `1001aae0` | `eb 0b` | `JMP 0x1001aaed` |
| `1001aae2` | `85 f3` | `TEST EBX,ESI` |
| `1001aae4` | `75 07` | `JNZ 0x1001aaed` |
| `1001aae6` | `8b c6` | `MOV EAX,ESI` |
| `1001aae8` | `c1 e0 10` | `SHL EAX,0x10` |
| `1001aaeb` | `0b f0` | `OR ESI,EAX` |
| `1001aaed` | `89 35 90 74 03 10` | `MOV dword ptr [0x10037490],ESI` |
| `1001aaf3` | `f7 d6` | `NOT ESI` |
| `1001aaf5` | `89 35 94 74 03 10` | `MOV dword ptr [0x10037494],ESI` |
| `1001aafb` | `5e` | `POP ESI` |
| `1001aafc` | `5f` | `POP EDI` |
| `1001aafd` | `5b` | `POP EBX` |
| `1001aafe` | `c9` | `LEAVE` |
| `1001aaff` | `c3` | `RET` |
