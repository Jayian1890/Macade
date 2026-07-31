# 10008080 `_Vector_iterator<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10008080 |
| `name` | _Vector_iterator<> |
| `namespace` | Global |
| `signature` | undefined _Vector_iterator<>(void) |
| `size_bytes` | 32 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | _Vector_iterator<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   >::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,struct std::_Container_base0 const *)
    public: __thiscall std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >::_Vector_iterator<class
   std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Container_base0 const *)
   
   Library: Visual Studio 2012 Release */

undefined4 _Vector_iterator<>(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  
  FUN_100085e0(param_1,param_2);
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10008092` | `100085e0` | `UNCONDITIONAL_CALL` | FUN_100085e0 | `100085e0` |

## Callers

| From | Function |
| --- | --- |
| `100080f2` | FUN_100080e0 |
| `10007ae0` | FUN_10007ac0 |
| `100019e5` | FUN_100019d0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10008080` | `55` | `PUSH EBP` |
| `10008081` | `8b ec` | `MOV EBP,ESP` |
| `10008083` | `51` | `PUSH ECX` |
| `10008084` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10008087` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1000808a` | `50` | `PUSH EAX` |
| `1000808b` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1000808e` | `51` | `PUSH ECX` |
| `1000808f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10008092` | `e8 49 05 00 00` | `CALL 0x100085e0` |
| `10008097` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000809a` | `8b e5` | `MOV ESP,EBP` |
| `1000809c` | `5d` | `POP EBP` |
| `1000809d` | `c2 08 00` | `RET 0x8` |
