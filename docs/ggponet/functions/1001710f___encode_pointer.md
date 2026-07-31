# 1001710f `__encode_pointer`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001710f |
| `name` | __encode_pointer |
| `namespace` | Global |
| `signature` | undefined __encode_pointer(void) |
| `size_bytes` | 114 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __encode_pointer |

## Decompiled C

```c

/* Library Function - Single Match
    __encode_pointer
   
   Library: Visual Studio 2008 Release */

int __encode_pointer(int param_1)

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
      pFVar4 = *(FARPROC *)(iVar3 + 0x1f8);
      goto LAB_1001716f;
    }
  }
  hModule = GetModuleHandleW(L"KERNEL32.DLL");
  if ((hModule == (HMODULE)0x0) &&
     (hModule = (HMODULE)__crt_waiting_on_module_handle(L"KERNEL32.DLL"), hModule == (HMODULE)0x0))
  {
    return param_1;
  }
  pFVar4 = GetProcAddress(hModule,"EncodePointer");
LAB_1001716f:
  if (pFVar4 != (FARPROC)0x0) {
    param_1 = (*pFVar4)(param_1);
  }
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017121` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `10017138` | `EXTERNAL:00000048` | `COMPUTED_CALL` | KERNEL32.DLL::TlsGetValue | `` |
| `1001714e` | `EXTERNAL:00000036` | `COMPUTED_CALL` | KERNEL32.DLL::GetModuleHandleW | `` |
| `10017159` | `1001240c` | `UNCONDITIONAL_CALL` | __crt_waiting_on_module_handle | `1001240c` |
| `10017169` | `EXTERNAL:00000037` | `COMPUTED_CALL` | KERNEL32.DLL::GetProcAddress | `` |

## Callers

| From | Function |
| --- | --- |
| `1001c844` | ___crtMessageBoxA |
| `1001c859` | ___crtMessageBoxA |
| `1001c86e` | ___crtMessageBoxA |
| `1001c883` | ___crtMessageBoxA |
| `1001c89b` | ___crtMessageBoxA |
| `10017183` | __encoded_null |
| `100178f9` | __onexit_nolock |
| `10017907` | __onexit_nolock |
| `10017912` | __onexit_nolock |
| `10017665` | __mtinit |
| `10017675` | __mtinit |
| `10017685` | __mtinit |
| `10017695` | __mtinit |
| `10012726` | __init_pointers |
| `1001933f` | __initp_misc_cfltcvt_tab |
| `10019536` | __initp_eh_hooks |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `10017148` | `1002f674` | `KERNEL32.DLL` |
| `1001714d` | `1002f674` | `KERNEL32.DLL` |
| `10017158` | `1002f674` | `KERNEL32.DLL` |
| `10017163` | `1002f664` | `EncodePointer` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017115` | `100377f4` | `READ` | DAT_100377f4 |
| `1001711b` | `1002e0d8` | `READ` | PTR_TlsGetValue_1002e0d8 |
| `10017127` | `100377f0` | `READ` | DAT_100377f0 |
| `10017132` | `100377f4` | `READ` | DAT_100377f4 |
| `1001714e` | `1002e090` | `READ` | PTR_GetModuleHandleW_1002e090 |
| `10017169` | `1002e094` | `READ` | PTR_GetProcAddress_1002e094 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001710f` | `8b ff` | `MOV EDI,EDI` |
| `10017111` | `55` | `PUSH EBP` |
| `10017112` | `8b ec` | `MOV EBP,ESP` |
| `10017114` | `56` | `PUSH ESI` |
| `10017115` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `1001711b` | `8b 35 d8 e0 02 10` | `MOV ESI,dword ptr [0x1002e0d8]` |
| `10017121` | `ff d6` | `CALL ESI` |
| `10017123` | `85 c0` | `TEST EAX,EAX` |
| `10017125` | `74 21` | `JZ 0x10017148` |
| `10017127` | `a1 f0 77 03 10` | `MOV EAX,[0x100377f0]` |
| `1001712c` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001712f` | `74 17` | `JZ 0x10017148` |
| `10017131` | `50` | `PUSH EAX` |
| `10017132` | `ff 35 f4 77 03 10` | `PUSH dword ptr [0x100377f4]` |
| `10017138` | `ff d6` | `CALL ESI` |
| `1001713a` | `ff d0` | `CALL EAX` |
| `1001713c` | `85 c0` | `TEST EAX,EAX` |
| `1001713e` | `74 08` | `JZ 0x10017148` |
| `10017140` | `8b 80 f8 01 00 00` | `MOV EAX,dword ptr [EAX + 0x1f8]` |
| `10017146` | `eb 27` | `JMP 0x1001716f` |
| `10017148` | `be 74 f6 02 10` | `MOV ESI,0x1002f674` |
| `1001714d` | `56` | `PUSH ESI` |
| `1001714e` | `ff 15 90 e0 02 10` | `CALL dword ptr [0x1002e090]` |
| `10017154` | `85 c0` | `TEST EAX,EAX` |
| `10017156` | `75 0b` | `JNZ 0x10017163` |
| `10017158` | `56` | `PUSH ESI` |
| `10017159` | `e8 ae b2 ff ff` | `CALL 0x1001240c` |
| `1001715e` | `59` | `POP ECX` |
| `1001715f` | `85 c0` | `TEST EAX,EAX` |
| `10017161` | `74 18` | `JZ 0x1001717b` |
| `10017163` | `68 64 f6 02 10` | `PUSH 0x1002f664` |
| `10017168` | `50` | `PUSH EAX` |
| `10017169` | `ff 15 94 e0 02 10` | `CALL dword ptr [0x1002e094]` |
| `1001716f` | `85 c0` | `TEST EAX,EAX` |
| `10017171` | `74 08` | `JZ 0x1001717b` |
| `10017173` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10017176` | `ff d0` | `CALL EAX` |
| `10017178` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `1001717b` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001717e` | `5e` | `POP ESI` |
| `1001717f` | `5d` | `POP EBP` |
| `10017180` | `c3` | `RET` |
