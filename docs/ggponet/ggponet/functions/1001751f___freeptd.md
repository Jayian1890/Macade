# 1001751f `__freeptd`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001751f |
| `name` | __freeptd |
| `namespace` | Global |
| `signature` | void __cdecl __freeptd(_ptiddata _Ptd) |
| `size_bytes` | 110 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __freeptd |

## Decompiled C

```c

/* Library Function - Single Match
    __freeptd
   
   Library: Visual Studio 2008 Release */

void __cdecl __freeptd(_ptiddata _Ptd)

{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  
  if (DAT_100377f0 != -1) {
    if ((_Ptd == (_ptiddata)0x0) && (pvVar1 = TlsGetValue(DAT_100377f4), pvVar1 != (LPVOID)0x0)) {
      iVar3 = DAT_100377f0;
      pcVar2 = TlsGetValue(DAT_100377f4);
      _Ptd = (_ptiddata)(*pcVar2)(iVar3);
    }
    pcVar2 = (code *)__decode_pointer(DAT_1003922c,DAT_100377f0,0);
    (*pcVar2)();
    __freefls_4(_Ptd);
  }
  if (DAT_100377f4 != 0xffffffff) {
    TlsSetValue(DAT_100377f4,(LPVOID)0x0);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017540` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `10017552` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `10017568` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `10017573` | `100173f0` | `UNCONDITIONAL_CALL` | __freefls@4 | `100173f0` |
| `10017585` | `EXTERNAL:0000004a` | `COMPUTED_CALL` | KERNEL32.DLL::TlsSetValue | `` |

## Callers

| From | Function |
| --- | --- |
| `10014795` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017524` | `100377f0` | `READ` | DAT_100377f0 |
| `10017534` | `100377f4` | `READ` | DAT_100377f4 |
| `1001753a` | `1002e0d8` | `READ` | PTR_TlsGetValue_1002e0d8 |
| `10017546` | `100377f0` | `READ` | DAT_100377f0 |
| `1001754c` | `100377f4` | `READ` | DAT_100377f4 |
| `1001755c` | `100377f0` | `READ` | DAT_100377f0 |
| `10017562` | `1003922c` | `READ` | DAT_1003922c |
| `10017578` | `100377f4` | `READ` | DAT_100377f4 |
| `10017585` | `1002e0e0` | `READ` | PTR_TlsSetValue_1002e0e0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001751f` | `8b ff` | `MOV EDI,EDI` |
| `10017521` | `55` | `PUSH EBP` |
| `10017522` | `8b ec` | `MOV EBP,ESP` |
| `10017524` | `83 3d f0 77 03 10 ff` | `CMP dword ptr [0x100377f0],-0x1` |
| `1001752b` | `74 4b` | `JZ 0x10017578` |
| `1001752d` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10017531` | `75 27` | `JNZ 0x1001755a` |
| `10017533` | `56` | `PUSH ESI` |
| `10017534` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `1001753a` | `8b 35 d8 e0 02 10` | `MOV ESI,dword ptr [0x1002e0d8]` |
| `10017540` | `ff d6` | `CALL ESI` |
| `10017542` | `85 c0` | `TEST EAX,EAX` |
| `10017544` | `74 13` | `JZ 0x10017559` |
| `10017546` | `ff 35 f0 77 03 10` | `PUSH dword ptr [0x100377f0]` |
| `1001754c` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `10017552` | `ff d6` | `CALL ESI` |
| `10017554` | `ff d0` | `CALL EAX` |
| `10017556` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `10017559` | `5e` | `POP ESI` |
| `1001755a` | `6a 00` | `PUSH 0x0` |
| `1001755c` | `ff 35 f0 77 03 10` | `PUSH dword ptr [0x100377f0]` |
| `10017562` | `ff 35 2c 92 03 10` | `PUSH dword ptr [0x1003922c]` |
| `10017568` | `e8 1d fc ff ff` | `CALL 0x1001718a` |
| `1001756d` | `59` | `POP ECX` |
| `1001756e` | `ff d0` | `CALL EAX` |
| `10017570` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10017573` | `e8 78 fe ff ff` | `CALL 0x100173f0` |
| `10017578` | `a1 f4 77 03 10` | `MOV EAX,[0x100377f4]` |
| `1001757d` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10017580` | `74 09` | `JZ 0x1001758b` |
| `10017582` | `6a 00` | `PUSH 0x0` |
| `10017584` | `50` | `PUSH EAX` |
| `10017585` | `ff 15 e0 e0 02 10` | `CALL dword ptr [0x1002e0e0]` |
| `1001758b` | `5d` | `POP EBP` |
| `1001758c` | `c3` | `RET` |
