# 10018c77 `__close_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018c77 |
| `name` | __close_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __close_nolock(int _FileHandle) |
| `size_bytes` | 156 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __close_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __close_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __close_nolock(int _FileHandle)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  iVar1 = __get_osfhandle(_FileHandle);
  if (iVar1 != -1) {
    if (((_FileHandle == 1) && ((*(byte *)(DAT_13439540 + 0x84) & 1) != 0)) ||
       ((_FileHandle == 2 && ((*(byte *)(DAT_13439540 + 0x44) & 1) != 0)))) {
      iVar1 = __get_osfhandle(2);
      iVar2 = __get_osfhandle(1);
      if (iVar2 == iVar1) goto LAB_10018cdd;
    }
    hObject = (HANDLE)__get_osfhandle(_FileHandle);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_10018cdf;
    }
  }
LAB_10018cdd:
  DVar4 = 0;
LAB_10018cdf:
  __free_osfhnd(_FileHandle);
  *(undefined1 *)((&DAT_13439540)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x40) = 0;
  if (DVar4 == 0) {
    iVar5 = 0;
  }
  else {
    __dosmaperr(DVar4);
    iVar5 = -1;
  }
  return iVar5;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10018c82` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `10018cad` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `10018cb6` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `10018cc2` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `10018cc9` | `EXTERNAL:00000028` | `COMPUTED_CALL` | KERNEL32.DLL::CloseHandle | `` |
| `10018cd3` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `10018ce0` | `1001db30` | `UNCONDITIONAL_CALL` | __free_osfhnd | `1001db30` |
| `10018d02` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |

## Callers

| From | Function |
| --- | --- |
| `1001d138` | __tsopen_nolock |
| `1001d342` | __tsopen_nolock |
| `10018da7` | __close |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10018c8d` | `13439540` | `READ` | DAT_13439540 |
| `10018cc9` | `1002e058` | `READ` | PTR_CloseHandle_1002e058 |
| `10018cd3` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `10018cea` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018c77` | `8b ff` | `MOV EDI,EDI` |
| `10018c79` | `55` | `PUSH EBP` |
| `10018c7a` | `8b ec` | `MOV EBP,ESP` |
| `10018c7c` | `56` | `PUSH ESI` |
| `10018c7d` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10018c80` | `57` | `PUSH EDI` |
| `10018c81` | `56` | `PUSH ESI` |
| `10018c82` | `e8 2f 4f 00 00` | `CALL 0x1001dbb6` |
| `10018c87` | `59` | `POP ECX` |
| `10018c88` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10018c8b` | `74 50` | `JZ 0x10018cdd` |
| `10018c8d` | `a1 40 95 43 13` | `MOV EAX,[0x13439540]` |
| `10018c92` | `83 fe 01` | `CMP ESI,0x1` |
| `10018c95` | `75 09` | `JNZ 0x10018ca0` |
| `10018c97` | `f6 80 84 00 00 00 01` | `TEST byte ptr [EAX + 0x84],0x1` |
| `10018c9e` | `75 0b` | `JNZ 0x10018cab` |
| `10018ca0` | `83 fe 02` | `CMP ESI,0x2` |
| `10018ca3` | `75 1c` | `JNZ 0x10018cc1` |
| `10018ca5` | `f6 40 44 01` | `TEST byte ptr [EAX + 0x44],0x1` |
| `10018ca9` | `74 16` | `JZ 0x10018cc1` |
| `10018cab` | `6a 02` | `PUSH 0x2` |
| `10018cad` | `e8 04 4f 00 00` | `CALL 0x1001dbb6` |
| `10018cb2` | `6a 01` | `PUSH 0x1` |
| `10018cb4` | `8b f8` | `MOV EDI,EAX` |
| `10018cb6` | `e8 fb 4e 00 00` | `CALL 0x1001dbb6` |
| `10018cbb` | `59` | `POP ECX` |
| `10018cbc` | `59` | `POP ECX` |
| `10018cbd` | `3b c7` | `CMP EAX,EDI` |
| `10018cbf` | `74 1c` | `JZ 0x10018cdd` |
| `10018cc1` | `56` | `PUSH ESI` |
| `10018cc2` | `e8 ef 4e 00 00` | `CALL 0x1001dbb6` |
| `10018cc7` | `59` | `POP ECX` |
| `10018cc8` | `50` | `PUSH EAX` |
| `10018cc9` | `ff 15 58 e0 02 10` | `CALL dword ptr [0x1002e058]` |
| `10018ccf` | `85 c0` | `TEST EAX,EAX` |
| `10018cd1` | `75 0a` | `JNZ 0x10018cdd` |
| `10018cd3` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10018cd9` | `8b f8` | `MOV EDI,EAX` |
| `10018cdb` | `eb 02` | `JMP 0x10018cdf` |
| `10018cdd` | `33 ff` | `XOR EDI,EDI` |
| `10018cdf` | `56` | `PUSH ESI` |
| `10018ce0` | `e8 4b 4e 00 00` | `CALL 0x1001db30` |
| `10018ce5` | `8b c6` | `MOV EAX,ESI` |
| `10018ce7` | `c1 f8 05` | `SAR EAX,0x5` |
| `10018cea` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `10018cf1` | `83 e6 1f` | `AND ESI,0x1f` |
| `10018cf4` | `c1 e6 06` | `SHL ESI,0x6` |
| `10018cf7` | `59` | `POP ECX` |
| `10018cf8` | `c6 44 30 04 00` | `MOV byte ptr [EAX + ESI*0x1 + 0x4],0x0` |
| `10018cfd` | `85 ff` | `TEST EDI,EDI` |
| `10018cff` | `74 0c` | `JZ 0x10018d0d` |
| `10018d01` | `57` | `PUSH EDI` |
| `10018d02` | `e8 28 c4 ff ff` | `CALL 0x1001512f` |
| `10018d07` | `59` | `POP ECX` |
| `10018d08` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10018d0b` | `eb 02` | `JMP 0x10018d0f` |
| `10018d0d` | `33 c0` | `XOR EAX,EAX` |
| `10018d0f` | `5f` | `POP EDI` |
| `10018d10` | `5e` | `POP ESI` |
| `10018d11` | `5d` | `POP EBP` |
| `10018d12` | `c3` | `RET` |
