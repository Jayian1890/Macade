# 10012465 `___crtCorExitProcess`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012465 |
| `name` | ___crtCorExitProcess |
| `namespace` | Global |
| `signature` | void __cdecl ___crtCorExitProcess(int param_1) |
| `size_bytes` | 43 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtCorExitProcess |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtCorExitProcess
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___crtCorExitProcess(int param_1)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleW(L"mscoree.dll");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"CorExitProcess");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001246f` | `EXTERNAL:00000036` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleHandleW | `` |
| `1001247f` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |

## Callers

| From | Function |
| --- | --- |
| `10012498` | ___crtExitProcess |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1001246a` | `1002efe8` | `mscoree.dll` |
| `10012479` | `1002efd8` | `CorExitProcess` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001246f` | `1002e090` | `READ` | PTR_GetModuleHandleW_1002e090 |
| `1001247f` | `1002e094` | `READ` | PTR_GetProcAddress_1002e094 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012465` | `8b ff` | `MOV EDI,EDI` |
| `10012467` | `55` | `PUSH EBP` |
| `10012468` | `8b ec` | `MOV EBP,ESP` |
| `1001246a` | `68 e8 ef 02 10` | `PUSH 0x1002efe8` |
| `1001246f` | `ff 15 90 e0 02 10` | `CALL dword ptr [0x1002e090]` |
| `10012475` | `85 c0` | `TEST EAX,EAX` |
| `10012477` | `74 15` | `JZ 0x1001248e` |
| `10012479` | `68 d8 ef 02 10` | `PUSH 0x1002efd8` |
| `1001247e` | `50` | `PUSH EAX` |
| `1001247f` | `ff 15 94 e0 02 10` | `CALL dword ptr [0x1002e094]` |
| `10012485` | `85 c0` | `TEST EAX,EAX` |
| `10012487` | `74 05` | `JZ 0x1001248e` |
| `10012489` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001248c` | `ff d0` | `CALL EAX` |
| `1001248e` | `5d` | `POP EBP` |
| `1001248f` | `c3` | `RET` |
