# 1001657c `___sbh_alloc_new_region`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001657c |
| `name` | ___sbh_alloc_new_region |
| `namespace` | Global |
| `signature` | undefined ___sbh_alloc_new_region(void) |
| `size_bytes` | 176 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___sbh_alloc_new_region |

## Decompiled C

```c

/* Library Function - Single Match
    ___sbh_alloc_new_region
   
   Library: Visual Studio 2008 Release */

undefined4 * ___sbh_alloc_new_region(void)

{
  LPVOID pvVar1;
  undefined4 *puVar2;
  
  if (DAT_1343a668 == DAT_1343a678) {
    pvVar1 = HeapReAlloc(DAT_10038dac,0,DAT_1343a66c,(DAT_1343a678 + 0x10) * 0x14);
    if (pvVar1 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_1343a678 = DAT_1343a678 + 0x10;
    DAT_1343a66c = pvVar1;
  }
  puVar2 = (undefined4 *)(DAT_1343a668 * 0x14 + (int)DAT_1343a66c);
  pvVar1 = HeapAlloc(DAT_10038dac,8,0x41c4);
  puVar2[4] = pvVar1;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar1 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar2[3] = pvVar1;
    if (pvVar1 != (LPVOID)0x0) {
      puVar2[2] = 0xffffffff;
      *puVar2 = 0;
      puVar2[1] = 0;
      DAT_1343a668 = DAT_1343a668 + 1;
      *(undefined4 *)puVar2[4] = 0xffffffff;
      return puVar2;
    }
    HeapFree(DAT_10038dac,0,(LPVOID)puVar2[4]);
  }
  return (undefined4 *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100165a3` | `EXTERNAL:00000039` | `COMPUTED_CALL` | KERNEL32.DLL::HeapReAlloc | `` |
| `100165d9` | `EXTERNAL:00000030` | `COMPUTED_CALL` | KERNEL32.DLL::HeapAlloc | `` |
| `100165f3` | `EXTERNAL:00000044` | `COMPUTED_CALL` | KERNEL32.DLL::VirtualAlloc | `` |
| `1001660a` | `EXTERNAL:0000002f` | `COMPUTED_CALL` | KERNEL32.DLL::HeapFree | `` |

## Callers

| From | Function |
| --- | --- |
| `10016ad7` | ___sbh_alloc_block |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001657c` | `1343a678` | `READ` | DAT_1343a678 |
| `10016582` | `1343a668` | `READ` | DAT_1343a668 |
| `10016596` | `1343a66c` | `READ` | DAT_1343a66c |
| `1001659d` | `10038dac` | `READ` | DAT_10038dac |
| `100165a3` | `1002e09c` | `READ` | PTR_HeapReAlloc_1002e09c |
| `100165b1` | `1343a678` | `READ_WRITE` | DAT_1343a678 |
| `100165b8` | `1343a668` | `READ` | DAT_1343a668 |
| `100165be` | `1343a66c` | `WRITE` | DAT_1343a66c |
| `100165c6` | `1343a66c` | `READ` | DAT_1343a66c |
| `100165d3` | `10038dac` | `READ` | DAT_10038dac |
| `100165d9` | `1002e078` | `READ` | PTR_HeapAlloc_1002e078 |
| `100165f3` | `1002e0c8` | `READ` | PTR_VirtualAlloc_1002e0c8 |
| `10016604` | `10038dac` | `READ` | DAT_10038dac |
| `1001660a` | `1002e074` | `READ` | PTR_HeapFree_1002e074 |
| `1001661b` | `1343a668` | `READ_WRITE` | DAT_1343a668 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001657c` | `a1 78 a6 43 13` | `MOV EAX,[0x1343a678]` |
| `10016581` | `56` | `PUSH ESI` |
| `10016582` | `8b 35 68 a6 43 13` | `MOV ESI,dword ptr [0x1343a668]` |
| `10016588` | `57` | `PUSH EDI` |
| `10016589` | `33 ff` | `XOR EDI,EDI` |
| `1001658b` | `3b f0` | `CMP ESI,EAX` |
| `1001658d` | `75 34` | `JNZ 0x100165c3` |
| `1001658f` | `83 c0 10` | `ADD EAX,0x10` |
| `10016592` | `6b c0 14` | `IMUL EAX,EAX,0x14` |
| `10016595` | `50` | `PUSH EAX` |
| `10016596` | `ff 35 6c a6 43 13` | `PUSH dword ptr [0x1343a66c]` |
| `1001659c` | `57` | `PUSH EDI` |
| `1001659d` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `100165a3` | `ff 15 9c e0 02 10` | `CALL dword ptr [0x1002e09c]` |
| `100165a9` | `3b c7` | `CMP EAX,EDI` |
| `100165ab` | `75 04` | `JNZ 0x100165b1` |
| `100165ad` | `33 c0` | `XOR EAX,EAX` |
| `100165af` | `eb 78` | `JMP 0x10016629` |
| `100165b1` | `83 05 78 a6 43 13 10` | `ADD dword ptr [0x1343a678],0x10` |
| `100165b8` | `8b 35 68 a6 43 13` | `MOV ESI,dword ptr [0x1343a668]` |
| `100165be` | `a3 6c a6 43 13` | `MOV [0x1343a66c],EAX` |
| `100165c3` | `6b f6 14` | `IMUL ESI,ESI,0x14` |
| `100165c6` | `03 35 6c a6 43 13` | `ADD ESI,dword ptr [0x1343a66c]` |
| `100165cc` | `68 c4 41 00 00` | `PUSH 0x41c4` |
| `100165d1` | `6a 08` | `PUSH 0x8` |
| `100165d3` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `100165d9` | `ff 15 78 e0 02 10` | `CALL dword ptr [0x1002e078]` |
| `100165df` | `89 46 10` | `MOV dword ptr [ESI + 0x10],EAX` |
| `100165e2` | `3b c7` | `CMP EAX,EDI` |
| `100165e4` | `74 c7` | `JZ 0x100165ad` |
| `100165e6` | `6a 04` | `PUSH 0x4` |
| `100165e8` | `68 00 20 00 00` | `PUSH 0x2000` |
| `100165ed` | `68 00 00 10 00` | `PUSH 0x100000` |
| `100165f2` | `57` | `PUSH EDI` |
| `100165f3` | `ff 15 c8 e0 02 10` | `CALL dword ptr [0x1002e0c8]` |
| `100165f9` | `89 46 0c` | `MOV dword ptr [ESI + 0xc],EAX` |
| `100165fc` | `3b c7` | `CMP EAX,EDI` |
| `100165fe` | `75 12` | `JNZ 0x10016612` |
| `10016600` | `ff 76 10` | `PUSH dword ptr [ESI + 0x10]` |
| `10016603` | `57` | `PUSH EDI` |
| `10016604` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `1001660a` | `ff 15 74 e0 02 10` | `CALL dword ptr [0x1002e074]` |
| `10016610` | `eb 9b` | `JMP 0x100165ad` |
| `10016612` | `83 4e 08 ff` | `OR dword ptr [ESI + 0x8],0xffffffff` |
| `10016616` | `89 3e` | `MOV dword ptr [ESI],EDI` |
| `10016618` | `89 7e 04` | `MOV dword ptr [ESI + 0x4],EDI` |
| `1001661b` | `ff 05 68 a6 43 13` | `INC dword ptr [0x1343a668]` |
| `10016621` | `8b 46 10` | `MOV EAX,dword ptr [ESI + 0x10]` |
| `10016624` | `83 08 ff` | `OR dword ptr [EAX],0xffffffff` |
| `10016627` | `8b c6` | `MOV EAX,ESI` |
| `10016629` | `5f` | `POP EDI` |
| `1001662a` | `5e` | `POP ESI` |
| `1001662b` | `c3` | `RET` |
