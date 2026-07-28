# 1001a514 `__calloc_crt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a514 |
| `name` | __calloc_crt |
| `namespace` | Global |
| `signature` | void * __cdecl __calloc_crt(size_t _Count, size_t _Size) |
| `size_bytes` | 76 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __calloc_crt |

## Decompiled C

```c

/* Library Function - Single Match
    __calloc_crt
   
   Library: Visual Studio 2008 Release */

void * __cdecl __calloc_crt(size_t _Count,size_t _Size)

{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  while( true ) {
    pvVar1 = (void *)__calloc_impl(_Count,_Size,0);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (DAT_10039274 == 0) break;
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_10039274 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
    if (dwMilliseconds == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a525` | `1001ab00` | `UNCONDITIONAL_CALL` | __calloc_impl | `1001ab00` |
| `1001a53c` | `EXTERNAL:0000001f` | `COMPUTED_CALL` | KERNEL32.DLL::Sleep | `` |

## Callers

| From | Function |
| --- | --- |
| `10017383` | __getptd_noexit |
| `10019b61` | ___wtomb_environ |
| `1001de01` | __alloc_osfhnd |
| `1001e5bf` | ___crtsetenv |
| `1001e3d6` | copy_environ |
| `1001f962` | ___convertcp |
| `10014742` | __CRT_INIT@12 |
| `100176cf` | __mtinit |
| `10018f09` | __ioinit |
| `10018f97` | __ioinit |
| `1001a63e` | __setenvp |
| `1001a66c` | __setenvp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a533` | `10039274` | `READ` | DAT_10039274 |
| `1001a53c` | `1002e034` | `READ` | PTR_Sleep_1002e034 |
| `1001a548` | `10039274` | `READ` | DAT_10039274 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a514` | `8b ff` | `MOV EDI,EDI` |
| `1001a516` | `55` | `PUSH EBP` |
| `1001a517` | `8b ec` | `MOV EBP,ESP` |
| `1001a519` | `56` | `PUSH ESI` |
| `1001a51a` | `57` | `PUSH EDI` |
| `1001a51b` | `33 f6` | `XOR ESI,ESI` |
| `1001a51d` | `6a 00` | `PUSH 0x0` |
| `1001a51f` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001a522` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001a525` | `e8 d6 05 00 00` | `CALL 0x1001ab00` |
| `1001a52a` | `8b f8` | `MOV EDI,EAX` |
| `1001a52c` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001a52f` | `85 ff` | `TEST EDI,EDI` |
| `1001a531` | `75 27` | `JNZ 0x1001a55a` |
| `1001a533` | `39 05 74 92 03 10` | `CMP dword ptr [0x10039274],EAX` |
| `1001a539` | `76 1f` | `JBE 0x1001a55a` |
| `1001a53b` | `56` | `PUSH ESI` |
| `1001a53c` | `ff 15 34 e0 02 10` | `CALL dword ptr [0x1002e034]` |
| `1001a542` | `8d 86 e8 03 00 00` | `LEA EAX,[ESI + 0x3e8]` |
| `1001a548` | `3b 05 74 92 03 10` | `CMP EAX,dword ptr [0x10039274]` |
| `1001a54e` | `76 03` | `JBE 0x1001a553` |
| `1001a550` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a553` | `8b f0` | `MOV ESI,EAX` |
| `1001a555` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001a558` | `75 c3` | `JNZ 0x1001a51d` |
| `1001a55a` | `8b c7` | `MOV EAX,EDI` |
| `1001a55c` | `5f` | `POP EDI` |
| `1001a55d` | `5e` | `POP ESI` |
| `1001a55e` | `5d` | `POP EBP` |
| `1001a55f` | `c3` | `RET` |
