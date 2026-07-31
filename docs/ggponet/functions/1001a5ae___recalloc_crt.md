# 1001a5ae `__recalloc_crt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a5ae |
| `name` | __recalloc_crt |
| `namespace` | Global |
| `signature` | void * __cdecl __recalloc_crt(void * _Ptr, size_t _Count, size_t _Size) |
| `size_bytes` | 82 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __recalloc_crt |

## Decompiled C

```c

/* Library Function - Single Match
    __recalloc_crt
   
   Library: Visual Studio 2008 Release */

void * __cdecl __recalloc_crt(void *_Ptr,size_t _Count,size_t _Size)

{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  do {
    pvVar1 = __recalloc(_Ptr,_Count,_Size);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (_Size == 0) {
      return (void *)0x0;
    }
    if (DAT_10039274 == 0) {
      return (void *)0x0;
    }
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_10039274 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
  } while (dwMilliseconds != 0xffffffff);
  return (void *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a5c0` | `1001e87b` | `UNCONDITIONAL_CALL` | __recalloc | `1001e87b` |
| `1001a5dc` | `EXTERNAL:0000001f` | `COMPUTED_CALL` | KERNEL32.DLL::Sleep | `` |

## Callers

| From | Function |
| --- | --- |
| `1001e54a` | ___crtsetenv |
| `1001e586` | ___crtsetenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a5d3` | `10039274` | `READ` | DAT_10039274 |
| `1001a5dc` | `1002e034` | `READ` | PTR_Sleep_1002e034 |
| `1001a5e8` | `10039274` | `READ` | DAT_10039274 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a5ae` | `8b ff` | `MOV EDI,EDI` |
| `1001a5b0` | `55` | `PUSH EBP` |
| `1001a5b1` | `8b ec` | `MOV EBP,ESP` |
| `1001a5b3` | `56` | `PUSH ESI` |
| `1001a5b4` | `57` | `PUSH EDI` |
| `1001a5b5` | `33 f6` | `XOR ESI,ESI` |
| `1001a5b7` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001a5ba` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001a5bd` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001a5c0` | `e8 b6 42 00 00` | `CALL 0x1001e87b` |
| `1001a5c5` | `8b f8` | `MOV EDI,EAX` |
| `1001a5c7` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001a5ca` | `85 ff` | `TEST EDI,EDI` |
| `1001a5cc` | `75 2c` | `JNZ 0x1001a5fa` |
| `1001a5ce` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `1001a5d1` | `74 27` | `JZ 0x1001a5fa` |
| `1001a5d3` | `39 05 74 92 03 10` | `CMP dword ptr [0x10039274],EAX` |
| `1001a5d9` | `76 1f` | `JBE 0x1001a5fa` |
| `1001a5db` | `56` | `PUSH ESI` |
| `1001a5dc` | `ff 15 34 e0 02 10` | `CALL dword ptr [0x1002e034]` |
| `1001a5e2` | `8d 86 e8 03 00 00` | `LEA EAX,[ESI + 0x3e8]` |
| `1001a5e8` | `3b 05 74 92 03 10` | `CMP EAX,dword ptr [0x10039274]` |
| `1001a5ee` | `76 03` | `JBE 0x1001a5f3` |
| `1001a5f0` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a5f3` | `8b f0` | `MOV ESI,EAX` |
| `1001a5f5` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001a5f8` | `75 bd` | `JNZ 0x1001a5b7` |
| `1001a5fa` | `8b c7` | `MOV EAX,EDI` |
| `1001a5fc` | `5f` | `POP EDI` |
| `1001a5fd` | `5e` | `POP ESI` |
| `1001a5fe` | `5d` | `POP EBP` |
| `1001a5ff` | `c3` | `RET` |
