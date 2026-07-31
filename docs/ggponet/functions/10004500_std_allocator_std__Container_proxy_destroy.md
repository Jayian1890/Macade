# 10004500 `std::allocator<std::_Container_proxy>::destroy`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10004500 |
| `name` | std::allocator<std::_Container_proxy>::destroy |
| `namespace` | std::allocator<std::_Container_proxy> (GhidraClass) |
| `signature` | void __thiscall destroy(allocator<std::_Container_proxy> * this, _Container_proxy * param_1) |
| `size_bytes` | 25 |
| `stack_frame_size` | 16 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?destroy@?$allocator@U_Container_proxy@std@@@std@@QAEXPAU_Container_proxy@2@@Z, std::allocator<std::_Container_proxy>::destroy |

## Decompiled C

```c

/* Library Function - Single Match
    public: void __thiscall std::allocator<struct std::_Container_proxy>::destroy(struct
   std::_Container_proxy *)
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2010 Release */

void __thiscall
std::allocator<std::_Container_proxy>::destroy
          (allocator<std::_Container_proxy> *this,_Container_proxy *param_1)

{
  FUN_10002640(param_1,this);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000450b` | `10002640` | `UNCONDITIONAL_CALL` | FUN_10002640 | `10002640` |

## Callers

| From | Function |
| --- | --- |
| `1000a1df` | FUN_1000a1d0 |
| `1000a11f` | FUN_1000a110 |
| `100081ce` | Catch_All@100081b5 |
| `100081ec` | Catch_All@100081b5 |
| `10007d99` | Catch_All@10007d80 |
| `10007073` | Catch_All@1000705a |
| `10007091` | Catch_All@1000705a |
| `10001ffe` | Catch_All@10001fe5 |
| `1000201c` | Catch_All@10001fe5 |
| `10001bf9` | Catch_All@10001be0 |
| `1000a7c1` | FUN_1000a7b2 |
| `1000a701` | FUN_1000a6f2 |
| `10001c75` | FUN_10001c50 |
| `10001c90` | FUN_10001c50 |
| `100017a3` | FUN_10001720 |
| `10002ba6` | FUN_10002b30 |
| `1000582e` | FUN_100057c0 |
| `10008036` | FUN_10007fc0 |
| `1000836d` | FUN_10008300 |
| `100030a6` | FUN_10003030 |
| `1000315b` | FUN_100030f0 |
| `10002ced` | _Destroy_range<> |
| `100041a6` | FUN_10004130 |
| `1000428b` | FUN_10004220 |
| `1000aba6` | FUN_1000ab30 |
| `1000ac5b` | FUN_1000abf0 |
| `10003836` | FUN_100037c0 |
| `100038eb` | FUN_10003880 |
| `100055e9` | FUN_10005580 |
| `10005604` | FUN_10005580 |
| `1000561f` | FUN_10005580 |
| `10006c2b` | FUN_100064b0 |
| `1000753c` | FUN_100074e0 |
| `10002d1d` | _Destroy_range<> |
| `10001b0d` | FUN_10001a80 |
| `10002ef7` | FUN_10002eb0 |
| `10007e7d` | FUN_10007e30 |
| `1000a9f7` | FUN_1000a9b0 |
| `10003687` | FUN_10003640 |
| `10003ff7` | FUN_10003fb0 |
| `10008afe` | FUN_10008ab0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10004500` | `55` | `PUSH EBP` |
| `10004501` | `8b ec` | `MOV EBP,ESP` |
| `10004503` | `51` | `PUSH ECX` |
| `10004504` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10004507` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1000450a` | `50` | `PUSH EAX` |
| `1000450b` | `e8 30 e1 ff ff` | `CALL 0x10002640` |
| `10004510` | `83 c4 04` | `ADD ESP,0x4` |
| `10004513` | `8b e5` | `MOV ESP,EBP` |
| `10004515` | `5d` | `POP EBP` |
| `10004516` | `c2 04 00` | `RET 0x4` |
