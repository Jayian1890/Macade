# 1001718a `__decode_pointer`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001718a |
| `name` | __decode_pointer |
| `namespace` | Global |
| `signature` | undefined __decode_pointer(void) |
| `size_bytes` | 114 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __decode_pointer |

## Decompiled C

```c

/* Library Function - Single Match
    __decode_pointer
   
   Library: Visual Studio 2008 Release */

int __decode_pointer(int param_1)

{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  
  pvVar1 = TlsGetValue(DAT_100377f4);
  if ((pvVar1 != (LPVOID)0x0) && (DAT_100377f0 != -1)) {
    iVar3 = DAT_100377f0;
    pcVar2 = TlsGetValue(DAT_100377f4);
    iVar3 = (*pcVar2)(iVar3);
    if (iVar3 != 0) {
      pFVar4 = *(FARPROC *)(iVar3 + 0x1fc);
      goto LAB_100171ea;
    }
  }
  hModule = GetModuleHandleW(L"KERNEL32.DLL");
  if ((hModule == (HMODULE)0x0) &&
     (hModule = (HMODULE)__crt_waiting_on_module_handle(L"KERNEL32.DLL"), hModule == (HMODULE)0x0))
  {
    return param_1;
  }
  pFVar4 = GetProcAddress(hModule,"DecodePointer");
LAB_100171ea:
  if (pFVar4 != (FARPROC)0x0) {
    param_1 = (*pFVar4)(param_1);
  }
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001719c` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `100171b3` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `100171c9` | `EXTERNAL:00000036` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleHandleW | `` |
| `100171d4` | `1001240c` | `UNCONDITIONAL_CALL` | __crt_waiting_on_module_handle | `1001240c` |
| `100171e4` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |

## Callers

| From | Function |
| --- | --- |
| `100116ba` | __invalid_parameter |
| `10012454` | __amsg_exit |
| `1001739d` | __getptd_noexit |
| `10017220` | ___set_flsgetvalue |
| `100170ea` | __callnewh |
| `1001c8b8` | ___crtMessageBoxA |
| `1001c8c5` | ___crtMessageBoxA |
| `1001c908` | ___crtMessageBoxA |
| `1001c925` | ___crtMessageBoxA |
| `1001c93d` | ___crtMessageBoxA |
| `1001787f` | __onexit_nolock |
| `1001788f` | __onexit_nolock |
| `10014760` | __CRT_INIT@12 |
| `100125c5` | doexit |
| `100125da` | doexit |
| `10012604` | doexit |
| `1001261a` | doexit |
| `10012627` | doexit |
| `1001724a` | __mtterm |
| `10017568` | __freeptd |
| `100176b6` | __mtinit |
| `100176e9` | __mtinit |
| `10015b2c` | __output_l |
| `10015b5b` | __output_l |
| `10015b80` | __output_l |
| `1001950b` | _inconsistency |
| `1001971e` | ___get_sigabrt |
| `100197e2` | _raise |
| `10011957` | __purecall |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `100171c3` | `1002f674` | `KERNEL32.DLL` |
| `100171c8` | `1002f674` | `KERNEL32.DLL` |
| `100171d3` | `1002f674` | `KERNEL32.DLL` |
| `100171de` | `1002f690` | `DecodePointer` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017190` | `100377f4` | `READ` | DAT_100377f4 |
| `10017196` | `1002e0d8` | `READ` | PTR_TlsGetValue_1002e0d8 |
| `100171a2` | `100377f0` | `READ` | DAT_100377f0 |
| `100171ad` | `100377f4` | `READ` | DAT_100377f4 |
| `100171c9` | `1002e090` | `READ` | PTR_GetModuleHandleW_1002e090 |
| `100171e4` | `1002e094` | `READ` | PTR_GetProcAddress_1002e094 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001718a` | `8b ff` | `MOV EDI,EDI` |
| `1001718c` | `55` | `PUSH EBP` |
| `1001718d` | `8b ec` | `MOV EBP,ESP` |
| `1001718f` | `56` | `PUSH ESI` |
| `10017190` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `10017196` | `8b 35 d8 e0 02 10` | `MOV ESI,dword ptr [0x1002e0d8]` |
| `1001719c` | `ff d6` | `CALL ESI` |
| `1001719e` | `85 c0` | `TEST EAX,EAX` |
| `100171a0` | `74 21` | `JZ 0x100171c3` |
| `100171a2` | `a1 f0 77 03 10` | `MOV EAX,[0x100377f0]` |
| `100171a7` | `83 f8 ff` | `CMP EAX,-0x1` |
| `100171aa` | `74 17` | `JZ 0x100171c3` |
| `100171ac` | `50` | `PUSH EAX` |
| `100171ad` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `100171b3` | `ff d6` | `CALL ESI` |
| `100171b5` | `ff d0` | `CALL EAX` |
| `100171b7` | `85 c0` | `TEST EAX,EAX` |
| `100171b9` | `74 08` | `JZ 0x100171c3` |
| `100171bb` | `8b 80 fc 01 00 00` | `MOV EAX,dword ptr [EAX + 0x1fc]` |
| `100171c1` | `eb 27` | `JMP 0x100171ea` |
| `100171c3` | `be 74 f6 02 10` | `MOV ESI,0x1002f674` |
| `100171c8` | `56` | `PUSH ESI` |
| `100171c9` | `ff 15 90 e0 02 10` | `CALL dword ptr [0x1002e090]` |
| `100171cf` | `85 c0` | `TEST EAX,EAX` |
| `100171d1` | `75 0b` | `JNZ 0x100171de` |
| `100171d3` | `56` | `PUSH ESI` |
| `100171d4` | `e8 33 b2 ff ff` | `CALL 0x1001240c` |
| `100171d9` | `59` | `POP ECX` |
| `100171da` | `85 c0` | `TEST EAX,EAX` |
| `100171dc` | `74 18` | `JZ 0x100171f6` |
| `100171de` | `68 90 f6 02 10` | `PUSH 0x1002f690` |
| `100171e3` | `50` | `PUSH EAX` |
| `100171e4` | `ff 15 94 e0 02 10` | `CALL dword ptr [0x1002e094]` |
| `100171ea` | `85 c0` | `TEST EAX,EAX` |
| `100171ec` | `74 08` | `JZ 0x100171f6` |
| `100171ee` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100171f1` | `ff d0` | `CALL EAX` |
| `100171f3` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `100171f6` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100171f9` | `5e` | `POP ESI` |
| `100171fa` | `5d` | `POP EBP` |
| `100171fb` | `c3` | `RET` |
