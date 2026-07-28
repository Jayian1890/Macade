# 1001240c `__crt_waiting_on_module_handle`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001240c |
| `name` | __crt_waiting_on_module_handle |
| `namespace` | Global |
| `signature` | undefined __crt_waiting_on_module_handle(void) |
| `size_bytes` | 48 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __crt_waiting_on_module_handle |

## Decompiled C

```c

/* Library Function - Single Match
    __crt_waiting_on_module_handle
   
   Library: Visual Studio 2008 Release */

void __crt_waiting_on_module_handle(LPCWSTR param_1)

{
  HMODULE pHVar1;
  DWORD dwMilliseconds;
  
  dwMilliseconds = 1000;
  do {
    Sleep(dwMilliseconds);
    pHVar1 = GetModuleHandleW(param_1);
    dwMilliseconds = dwMilliseconds + 1000;
    if (60000 < dwMilliseconds) {
      return;
    }
  } while (pHVar1 == (HMODULE)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10012418` | `EXTERNAL:0000001f` | `COMPUTED_CALL` | KERNEL32.DLL::Sleep | `` |
| `10012421` | `EXTERNAL:00000036` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleHandleW | `` |

## Callers

| From | Function |
| --- | --- |
| `100171d4` | __decode_pointer |
| `10017293` | __initptd |
| `10017159` | __encode_pointer |
| `100175a2` | __mtinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012418` | `1002e034` | `READ` | PTR_Sleep_1002e034 |
| `10012421` | `1002e090` | `READ` | PTR_GetModuleHandleW_1002e090 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001240c` | `8b ff` | `MOV EDI,EDI` |
| `1001240e` | `55` | `PUSH EBP` |
| `1001240f` | `8b ec` | `MOV EBP,ESP` |
| `10012411` | `57` | `PUSH EDI` |
| `10012412` | `bf e8 03 00 00` | `MOV EDI,0x3e8` |
| `10012417` | `57` | `PUSH EDI` |
| `10012418` | `ff 15 34 e0 02 10` | `CALL dword ptr [0x1002e034]` |
| `1001241e` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10012421` | `ff 15 90 e0 02 10` | `CALL dword ptr [0x1002e090]` |
| `10012427` | `81 c7 e8 03 00 00` | `ADD EDI,0x3e8` |
| `1001242d` | `81 ff 60 ea 00 00` | `CMP EDI,0xea60` |
| `10012433` | `77 04` | `JA 0x10012439` |
| `10012435` | `85 c0` | `TEST EAX,EAX` |
| `10012437` | `74 de` | `JZ 0x10012417` |
| `10012439` | `5f` | `POP EDI` |
| `1001243a` | `5d` | `POP EBP` |
| `1001243b` | `c3` | `RET` |
