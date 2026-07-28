# 1002ac6f `__ms_p5_mp_test_fdiv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002ac6f |
| `name` | __ms_p5_mp_test_fdiv |
| `namespace` | Global |
| `signature` | undefined __ms_p5_mp_test_fdiv(void) |
| `size_bytes` | 41 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __ms_p5_mp_test_fdiv |

## Decompiled C

```c

/* Library Function - Single Match
    __ms_p5_mp_test_fdiv
   
   Library: Visual Studio 2008 Release */

void __ms_p5_mp_test_fdiv(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  __ms_p5_test_fdiv();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002ac74` | `EXTERNAL:00000045` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleHandleA | `` |
| `1002ac84` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |
| `1002ac93` | `1002ac31` | `UNCONDITIONAL_CALL` | __ms_p5_test_fdiv | `1002ac31` |

## Callers

| From | Function |
| --- | --- |
| `1002a059` | __fpmath |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1002ac6f` | `100334b4` | `KERNEL32` |
| `1002ac7e` | `10033498` | `GAIsProcessorFeaturePresent` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002ac74` | `1002e0cc` | `READ` | PTR_GetModuleHandleA_1002e0cc |
| `1002ac84` | `1002e094` | `READ` | PTR_GetProcAddress_1002e094 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002ac6f` | `68 b4 34 03 10` | `PUSH 0x100334b4` |
| `1002ac74` | `ff 15 cc e0 02 10` | `CALL dword ptr [0x1002e0cc]` |
| `1002ac7a` | `85 c0` | `TEST EAX,EAX` |
| `1002ac7c` | `74 15` | `JZ 0x1002ac93` |
| `1002ac7e` | `68 98 34 03 10` | `PUSH 0x10033498` |
| `1002ac83` | `50` | `PUSH EAX` |
| `1002ac84` | `ff 15 94 e0 02 10` | `CALL dword ptr [0x1002e094]` |
| `1002ac8a` | `85 c0` | `TEST EAX,EAX` |
| `1002ac8c` | `74 05` | `JZ 0x1002ac93` |
| `1002ac8e` | `6a 00` | `PUSH 0x0` |
| `1002ac90` | `ff d0` | `CALL EAX` |
| `1002ac92` | `c3` | `RET` |
| `1002ac93` | `e9 99 ff ff ff` | `JMP 0x1002ac31` |
