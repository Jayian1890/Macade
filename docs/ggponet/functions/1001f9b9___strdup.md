# 1001f9b9 `__strdup`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f9b9 |
| `name` | __strdup |
| `namespace` | Global |
| `signature` | char * __cdecl __strdup(char * _Src) |
| `size_bytes` | 82 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __strdup |

## Decompiled C

```c

/* Library Function - Single Match
    __strdup
   
   Library: Visual Studio 2008 Release */

char * __cdecl __strdup(char *_Src)

{
  char *_Dst;
  size_t sVar1;
  errno_t eVar2;
  
  if (_Src == (char *)0x0) {
    _Dst = (char *)0x0;
  }
  else {
    sVar1 = _strlen(_Src);
    _Dst = _malloc(sVar1 + 1);
    if (_Dst == (char *)0x0) {
      _Dst = (char *)0x0;
    }
    else {
      eVar2 = _strcpy_s(_Dst,sVar1 + 1,_Src);
      if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
    }
  }
  return _Dst;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f9cf` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001f9d8` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001f9ea` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1001f9fb` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |

## Callers

| From | Function |
| --- | --- |
| `1001e3f0` | copy_environ |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f9b9` | `8b ff` | `MOV EDI,EDI` |
| `1001f9bb` | `55` | `PUSH EBP` |
| `1001f9bc` | `8b ec` | `MOV EBP,ESP` |
| `1001f9be` | `53` | `PUSH EBX` |
| `1001f9bf` | `33 db` | `XOR EBX,EBX` |
| `1001f9c1` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001f9c4` | `75 04` | `JNZ 0x1001f9ca` |
| `1001f9c6` | `33 c0` | `XOR EAX,EAX` |
| `1001f9c8` | `eb 41` | `JMP 0x1001fa0b` |
| `1001f9ca` | `56` | `PUSH ESI` |
| `1001f9cb` | `57` | `PUSH EDI` |
| `1001f9cc` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f9cf` | `e8 1c 1a ff ff` | `CALL 0x100113f0` |
| `1001f9d4` | `8b f0` | `MOV ESI,EAX` |
| `1001f9d6` | `46` | `INC ESI` |
| `1001f9d7` | `56` | `PUSH ESI` |
| `1001f9d8` | `e8 41 19 ff ff` | `CALL 0x1001131e` |
| `1001f9dd` | `8b f8` | `MOV EDI,EAX` |
| `1001f9df` | `59` | `POP ECX` |
| `1001f9e0` | `59` | `POP ECX` |
| `1001f9e1` | `3b fb` | `CMP EDI,EBX` |
| `1001f9e3` | `74 22` | `JZ 0x1001fa07` |
| `1001f9e5` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f9e8` | `56` | `PUSH ESI` |
| `1001f9e9` | `57` | `PUSH EDI` |
| `1001f9ea` | `e8 8c 65 ff ff` | `CALL 0x10015f7b` |
| `1001f9ef` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001f9f2` | `85 c0` | `TEST EAX,EAX` |
| `1001f9f4` | `74 0d` | `JZ 0x1001fa03` |
| `1001f9f6` | `53` | `PUSH EBX` |
| `1001f9f7` | `53` | `PUSH EBX` |
| `1001f9f8` | `53` | `PUSH EBX` |
| `1001f9f9` | `53` | `PUSH EBX` |
| `1001f9fa` | `53` | `PUSH EBX` |
| `1001f9fb` | `e8 87 1b ff ff` | `CALL 0x10011587` |
| `1001fa03` | `8b c7` | `MOV EAX,EDI` |
| `1001fa05` | `eb 02` | `JMP 0x1001fa09` |
| `1001fa07` | `33 c0` | `XOR EAX,EAX` |
| `1001fa09` | `5f` | `POP EDI` |
| `1001fa0a` | `5e` | `POP ESI` |
| `1001fa0b` | `5b` | `POP EBX` |
| `1001fa0c` | `5d` | `POP EBP` |
| `1001fa0d` | `c3` | `RET` |
