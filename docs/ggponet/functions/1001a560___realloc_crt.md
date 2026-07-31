# 1001a560 `__realloc_crt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a560 |
| `name` | __realloc_crt |
| `namespace` | Global |
| `signature` | void * __cdecl __realloc_crt(void * _Ptr, size_t _NewSize) |
| `size_bytes` | 78 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __realloc_crt |

## Decompiled C

```c

/* Library Function - Single Match
    __realloc_crt
   
   Library: Visual Studio 2008 Release */

void * __cdecl __realloc_crt(void *_Ptr,size_t _NewSize)

{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  do {
    pvVar1 = _realloc(_Ptr,_NewSize);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (_NewSize == 0) {
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
| `1001a56f` | `10012ab0` | `UNCONDITIONAL_CALL` | _realloc | `10012ab0` |
| `1001a58a` | `EXTERNAL:0000001f` | `COMPUTED_CALL` | KERNEL32.DLL::Sleep | `` |

## Callers

| From | Function |
| --- | --- |
| `100178d1` | __onexit_nolock |
| `100178e7` | __onexit_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a581` | `10039274` | `READ` | DAT_10039274 |
| `1001a58a` | `1002e034` | `READ` | PTR_Sleep_1002e034 |
| `1001a596` | `10039274` | `READ` | DAT_10039274 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a560` | `8b ff` | `MOV EDI,EDI` |
| `1001a562` | `55` | `PUSH EBP` |
| `1001a563` | `8b ec` | `MOV EBP,ESP` |
| `1001a565` | `56` | `PUSH ESI` |
| `1001a566` | `57` | `PUSH EDI` |
| `1001a567` | `33 f6` | `XOR ESI,ESI` |
| `1001a569` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001a56c` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001a56f` | `e8 3c 85 ff ff` | `CALL 0x10012ab0` |
| `1001a574` | `8b f8` | `MOV EDI,EAX` |
| `1001a576` | `59` | `POP ECX` |
| `1001a577` | `59` | `POP ECX` |
| `1001a578` | `85 ff` | `TEST EDI,EDI` |
| `1001a57a` | `75 2c` | `JNZ 0x1001a5a8` |
| `1001a57c` | `39 45 0c` | `CMP dword ptr [EBP + 0xc],EAX` |
| `1001a57f` | `74 27` | `JZ 0x1001a5a8` |
| `1001a581` | `39 05 74 92 03 10` | `CMP dword ptr [0x10039274],EAX` |
| `1001a587` | `76 1f` | `JBE 0x1001a5a8` |
| `1001a589` | `56` | `PUSH ESI` |
| `1001a58a` | `ff 15 34 e0 02 10` | `CALL dword ptr [0x1002e034]` |
| `1001a590` | `8d 86 e8 03 00 00` | `LEA EAX,[ESI + 0x3e8]` |
| `1001a596` | `3b 05 74 92 03 10` | `CMP EAX,dword ptr [0x10039274]` |
| `1001a59c` | `76 03` | `JBE 0x1001a5a1` |
| `1001a59e` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a5a1` | `8b f0` | `MOV ESI,EAX` |
| `1001a5a3` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001a5a6` | `75 c1` | `JNZ 0x1001a569` |
| `1001a5a8` | `8b c7` | `MOV EAX,EDI` |
| `1001a5aa` | `5f` | `POP EDI` |
| `1001a5ab` | `5e` | `POP ESI` |
| `1001a5ac` | `5d` | `POP EBP` |
| `1001a5ad` | `c3` | `RET` |
