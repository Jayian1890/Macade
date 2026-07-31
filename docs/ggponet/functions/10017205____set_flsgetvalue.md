# 10017205 `___set_flsgetvalue`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017205 |
| `name` | ___set_flsgetvalue |
| `namespace` | Global |
| `signature` | undefined ___set_flsgetvalue(void) |
| `size_bytes` | 52 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___set_flsgetvalue |

## Decompiled C

```c

/* Library Function - Single Match
    ___set_flsgetvalue
   
   Library: Visual Studio 2008 Release */

LPVOID ___set_flsgetvalue(void)

{
  LPVOID lpTlsValue;
  
  lpTlsValue = TlsGetValue(DAT_100377f4);
  if (lpTlsValue == (LPVOID)0x0) {
    lpTlsValue = (LPVOID)__decode_pointer(DAT_10039228);
    TlsSetValue(DAT_100377f4,lpTlsValue);
  }
  return lpTlsValue;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001720e` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `10017220` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001722f` | `EXTERNAL:0000004a` | `COMPUTED_CALL` | KERNEL32.DLL::TlsSetValue | `` |

## Callers

| From | Function |
| --- | --- |
| `1001736f` | __getptd_noexit |
| `10014736` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017208` | `100377f4` | `READ` | DAT_100377f4 |
| `1001720e` | `1002e0d8` | `READ` | PTR_TlsGetValue_1002e0d8 |
| `1001721a` | `10039228` | `READ` | DAT_10039228 |
| `10017229` | `100377f4` | `READ` | DAT_100377f4 |
| `1001722f` | `1002e0e0` | `READ` | PTR_TlsSetValue_1002e0e0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017205` | `8b ff` | `MOV EDI,EDI` |
| `10017207` | `56` | `PUSH ESI` |
| `10017208` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `1001720e` | `ff 15 d8 e0 02 10` | `CALL dword ptr [0x1002e0d8]` |
| `10017214` | `8b f0` | `MOV ESI,EAX` |
| `10017216` | `85 f6` | `TEST ESI,ESI` |
| `10017218` | `75 1b` | `JNZ 0x10017235` |
| `1001721a` | `ff 35 28 92 03 10` | `PUSH dword ptr [0x10039228]` |
| `10017220` | `e8 65 ff ff ff` | `CALL 0x1001718a` |
| `10017225` | `59` | `POP ECX` |
| `10017226` | `8b f0` | `MOV ESI,EAX` |
| `10017228` | `56` | `PUSH ESI` |
| `10017229` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `1001722f` | `ff 15 e0 e0 02 10` | `CALL dword ptr [0x1002e0e0]` |
| `10017235` | `8b c6` | `MOV EAX,ESI` |
| `10017237` | `5e` | `POP ESI` |
| `10017238` | `c3` | `RET` |
