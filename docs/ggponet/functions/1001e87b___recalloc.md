# 1001e87b `__recalloc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e87b |
| `name` | __recalloc |
| `namespace` | Global |
| `signature` | void * __cdecl __recalloc(void * _Memory, size_t _Count, size_t _Size) |
| `size_bytes` | 123 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __recalloc |

## Decompiled C

```c

/* Library Function - Single Match
    __recalloc
   
   Library: Visual Studio 2008 Release */

void * __cdecl __recalloc(void *_Memory,size_t _Count,size_t _Size)

{
  int *piVar1;
  void *pvVar2;
  uint _NewSize;
  size_t sVar3;
  
  sVar3 = 0;
  if ((_Count == 0) || (_Size <= 0xffffffe0 / _Count)) {
    _NewSize = _Count * _Size;
    if (_Memory != (void *)0x0) {
      sVar3 = __msize(_Memory);
    }
    pvVar2 = _realloc(_Memory,_NewSize);
    if ((pvVar2 != (void *)0x0) && (sVar3 < _NewSize)) {
      _memset((void *)(sVar3 + (int)pvVar2),0,_NewSize - sVar3);
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0xc;
    __invalid_parameter(0,0,0,0,0);
    pvVar2 = (void *)0x0;
  }
  return pvVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e896` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e8a6` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001e8c2` | `1001cad2` | `UNCONDITIONAL_CALL` | __msize | `1001cad2` |
| `1001e8ce` | `10012ab0` | `UNCONDITIONAL_CALL` | _realloc | `10012ab0` |
| `1001e8e7` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |

## Callers

| From | Function |
| --- | --- |
| `1001a5c0` | __recalloc_crt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e87b` | `8b ff` | `MOV EDI,EDI` |
| `1001e87d` | `55` | `PUSH EBP` |
| `1001e87e` | `8b ec` | `MOV EBP,ESP` |
| `1001e880` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001e883` | `53` | `PUSH EBX` |
| `1001e884` | `33 db` | `XOR EBX,EBX` |
| `1001e886` | `3b cb` | `CMP ECX,EBX` |
| `1001e888` | `76 28` | `JBE 0x1001e8b2` |
| `1001e88a` | `6a e0` | `PUSH -0x20` |
| `1001e88c` | `33 d2` | `XOR EDX,EDX` |
| `1001e88e` | `58` | `POP EAX` |
| `1001e88f` | `f7 f1` | `DIV ECX` |
| `1001e891` | `3b 45 10` | `CMP EAX,dword ptr [EBP + 0x10]` |
| `1001e894` | `73 1c` | `JNC 0x1001e8b2` |
| `1001e896` | `e8 6e 68 ff ff` | `CALL 0x10015109` |
| `1001e89b` | `53` | `PUSH EBX` |
| `1001e89c` | `53` | `PUSH EBX` |
| `1001e89d` | `53` | `PUSH EBX` |
| `1001e89e` | `53` | `PUSH EBX` |
| `1001e89f` | `53` | `PUSH EBX` |
| `1001e8a0` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `1001e8a6` | `e8 04 2e ff ff` | `CALL 0x100116af` |
| `1001e8ab` | `83 c4 14` | `ADD ESP,0x14` |
| `1001e8ae` | `33 c0` | `XOR EAX,EAX` |
| `1001e8b0` | `eb 41` | `JMP 0x1001e8f3` |
| `1001e8b2` | `0f af 4d 10` | `IMUL ECX,dword ptr [EBP + 0x10]` |
| `1001e8b6` | `56` | `PUSH ESI` |
| `1001e8b7` | `57` | `PUSH EDI` |
| `1001e8b8` | `8b f1` | `MOV ESI,ECX` |
| `1001e8ba` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001e8bd` | `74 0b` | `JZ 0x1001e8ca` |
| `1001e8bf` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e8c2` | `e8 0b e2 ff ff` | `CALL 0x1001cad2` |
| `1001e8c7` | `59` | `POP ECX` |
| `1001e8c8` | `8b d8` | `MOV EBX,EAX` |
| `1001e8ca` | `56` | `PUSH ESI` |
| `1001e8cb` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e8ce` | `e8 dd 41 ff ff` | `CALL 0x10012ab0` |
| `1001e8d3` | `8b f8` | `MOV EDI,EAX` |
| `1001e8d5` | `59` | `POP ECX` |
| `1001e8d6` | `59` | `POP ECX` |
| `1001e8d7` | `85 ff` | `TEST EDI,EDI` |
| `1001e8d9` | `74 14` | `JZ 0x1001e8ef` |
| `1001e8db` | `3b de` | `CMP EBX,ESI` |
| `1001e8dd` | `73 10` | `JNC 0x1001e8ef` |
| `1001e8df` | `2b f3` | `SUB ESI,EBX` |
| `1001e8e1` | `56` | `PUSH ESI` |
| `1001e8e2` | `6a 00` | `PUSH 0x0` |
| `1001e8e4` | `03 df` | `ADD EBX,EDI` |
| `1001e8e6` | `53` | `PUSH EBX` |
| `1001e8e7` | `e8 04 2e ff ff` | `CALL 0x100116f0` |
| `1001e8ec` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001e8ef` | `8b c7` | `MOV EAX,EDI` |
| `1001e8f1` | `5f` | `POP EDI` |
| `1001e8f2` | `5e` | `POP ESI` |
| `1001e8f3` | `5b` | `POP EBX` |
| `1001e8f4` | `5d` | `POP EBP` |
| `1001e8f5` | `c3` | `RET` |
