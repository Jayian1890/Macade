# 1001a4cf `__malloc_crt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a4cf |
| `name` | __malloc_crt |
| `namespace` | Global |
| `signature` | void * __cdecl __malloc_crt(size_t _Size) |
| `size_bytes` | 69 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __malloc_crt |

## Decompiled C

```c

/* Library Function - Single Match
    __malloc_crt
   
   Library: Visual Studio 2008 Release */

void * __cdecl __malloc_crt(size_t _Size)

{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  while( true ) {
    pvVar1 = _malloc(_Size);
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
| `1001a4db` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001a4f0` | `EXTERNAL:0000001f` | `COMPUTED_CALL` | KERNEL32.DLL::Sleep | `` |

## Callers

| From | Function |
| --- | --- |
| `10016188` | __mtinitlocknum |
| `10018268` | __getstream |
| `1001bada` | __getbuf |
| `100186b0` | __read_nolock |
| `1001e4bb` | ___crtsetenv |
| `1001e4d6` | ___crtsetenv |
| `10018e6e` | __stbuf |
| `1001a8f6` | __setargv |
| `1001a9d0` | ___crtGetEnvironmentStringsA |
| `1001aa37` | ___crtGetEnvironmentStringsA |
| `1001c0dd` | __setmbcp |
| `10015ab5` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a4e7` | `10039274` | `READ` | DAT_10039274 |
| `1001a4f0` | `1002e034` | `READ` | PTR_Sleep_1002e034 |
| `1001a4fc` | `10039274` | `READ` | DAT_10039274 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a4cf` | `8b ff` | `MOV EDI,EDI` |
| `1001a4d1` | `55` | `PUSH EBP` |
| `1001a4d2` | `8b ec` | `MOV EBP,ESP` |
| `1001a4d4` | `56` | `PUSH ESI` |
| `1001a4d5` | `57` | `PUSH EDI` |
| `1001a4d6` | `33 f6` | `XOR ESI,ESI` |
| `1001a4d8` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001a4db` | `e8 3e 6e ff ff` | `CALL 0x1001131e` |
| `1001a4e0` | `8b f8` | `MOV EDI,EAX` |
| `1001a4e2` | `59` | `POP ECX` |
| `1001a4e3` | `85 ff` | `TEST EDI,EDI` |
| `1001a4e5` | `75 27` | `JNZ 0x1001a50e` |
| `1001a4e7` | `39 05 74 92 03 10` | `CMP dword ptr [0x10039274],EAX` |
| `1001a4ed` | `76 1f` | `JBE 0x1001a50e` |
| `1001a4ef` | `56` | `PUSH ESI` |
| `1001a4f0` | `ff 15 34 e0 02 10` | `CALL dword ptr [0x1002e034]` |
| `1001a4f6` | `8d 86 e8 03 00 00` | `LEA EAX,[ESI + 0x3e8]` |
| `1001a4fc` | `3b 05 74 92 03 10` | `CMP EAX,dword ptr [0x10039274]` |
| `1001a502` | `76 03` | `JBE 0x1001a507` |
| `1001a504` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a507` | `8b f0` | `MOV ESI,EAX` |
| `1001a509` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001a50c` | `75 ca` | `JNZ 0x1001a4d8` |
| `1001a50e` | `8b c7` | `MOV EAX,EDI` |
| `1001a510` | `5f` | `POP EDI` |
| `1001a511` | `5e` | `POP ESI` |
| `1001a512` | `5d` | `POP EBP` |
| `1001a513` | `c3` | `RET` |
