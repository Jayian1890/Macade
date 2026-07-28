# 1001d9dd `__local_unwind2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d9dd |
| `name` | __local_unwind2 |
| `namespace` | Global |
| `signature` | undefined __local_unwind2(void) |
| `size_bytes` | 132 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __local_unwind2 |

## Decompiled C

```c

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __local_unwind2(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  void *local_20;
  undefined1 *puStack_1c;
  undefined4 local_18;
  int iStack_14;
  
  iStack_14 = param_1;
  puStack_1c = &LAB_1001d998;
  local_20 = ExceptionList;
  uVar2 = DAT_10037490 ^ (uint)&local_20;
  ExceptionList = &local_20;
  while( true ) {
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 == 0xffffffff) || ((param_2 != 0xffffffff && (uVar1 <= param_2)))) break;
    local_18 = *(undefined4 *)(*(int *)(param_1 + 8) + uVar1 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_18;
    if (*(int *)(*(int *)(param_1 + 8) + 4 + uVar1 * 0xc) == 0) {
      __NLG_Notify(0x101);
      FUN_1001daac(uVar2);
    }
  }
  ExceptionList = local_20;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001da3f` | `1001da8d` | `UNCONDITIONAL_CALL` | __NLG_Notify | `1001da8d` |
| `1001da48` | `1001daac` | `UNCONDITIONAL_CALL` | FUN_1001daac | `1001daac` |

## Callers

| From | Function |
| --- | --- |
| `1001d9c4` |  |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001d9e8` | `1001d998` | `DATA` | LAB_1001d998 |
| `1001d9ed` | `ffdff000` | `READ` | ExceptionList |
| `1001d9f4` | `10037490` | `READ` | DAT_10037490 |
| `1001da00` | `ffdff000` | `WRITE` | ExceptionList |
| `1001da53` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d9dd` | `53` | `PUSH EBX` |
| `1001d9de` | `56` | `PUSH ESI` |
| `1001d9df` | `57` | `PUSH EDI` |
| `1001d9e0` | `8b 44 24 10` | `MOV EAX,dword ptr [ESP + 0x10]` |
| `1001d9e4` | `55` | `PUSH EBP` |
| `1001d9e5` | `50` | `PUSH EAX` |
| `1001d9e6` | `6a fe` | `PUSH -0x2` |
| `1001d9e8` | `68 98 d9 01 10` | `PUSH 0x1001d998` |
| `1001d9ed` | `64 ff 35 00 00 00 00` | `PUSH dword ptr FS:[0x0]` |
| `1001d9f4` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001d9f9` | `33 c4` | `XOR EAX,ESP` |
| `1001d9fb` | `50` | `PUSH EAX` |
| `1001d9fc` | `8d 44 24 04` | `LEA EAX,[ESP + 0x4]` |
| `1001da00` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `1001da06` | `8b 44 24 28` | `MOV EAX,dword ptr [ESP + 0x28]` |
| `1001da0a` | `8b 58 08` | `MOV EBX,dword ptr [EAX + 0x8]` |
| `1001da0d` | `8b 70 0c` | `MOV ESI,dword ptr [EAX + 0xc]` |
| `1001da10` | `83 fe ff` | `CMP ESI,-0x1` |
| `1001da13` | `74 3a` | `JZ 0x1001da4f` |
| `1001da15` | `83 7c 24 2c ff` | `CMP dword ptr [ESP + 0x2c],-0x1` |
| `1001da1a` | `74 06` | `JZ 0x1001da22` |
| `1001da1c` | `3b 74 24 2c` | `CMP ESI,dword ptr [ESP + 0x2c]` |
| `1001da20` | `76 2d` | `JBE 0x1001da4f` |
| `1001da22` | `8d 34 76` | `LEA ESI,[ESI + ESI*0x2]` |
| `1001da25` | `8b 0c b3` | `MOV ECX,dword ptr [EBX + ESI*0x4]` |
| `1001da28` | `89 4c 24 0c` | `MOV dword ptr [ESP + 0xc],ECX` |
| `1001da2c` | `89 48 0c` | `MOV dword ptr [EAX + 0xc],ECX` |
| `1001da2f` | `83 7c b3 04 00` | `CMP dword ptr [EBX + ESI*0x4 + 0x4],0x0` |
| `1001da34` | `75 17` | `JNZ 0x1001da4d` |
| `1001da36` | `68 01 01 00 00` | `PUSH 0x101` |
| `1001da3b` | `8b 44 b3 08` | `MOV EAX,dword ptr [EBX + ESI*0x4 + 0x8]` |
| `1001da3f` | `e8 49 00 00 00` | `CALL 0x1001da8d` |
| `1001da44` | `8b 44 b3 08` | `MOV EAX,dword ptr [EBX + ESI*0x4 + 0x8]` |
| `1001da48` | `e8 5f 00 00 00` | `CALL 0x1001daac` |
| `1001da4d` | `eb b7` | `JMP 0x1001da06` |
| `1001da4f` | `8b 4c 24 04` | `MOV ECX,dword ptr [ESP + 0x4]` |
| `1001da53` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `1001da5a` | `83 c4 18` | `ADD ESP,0x18` |
| `1001da5d` | `5f` | `POP EDI` |
| `1001da5e` | `5e` | `POP ESI` |
| `1001da5f` | `5b` | `POP EBX` |
| `1001da60` | `c3` | `RET` |
