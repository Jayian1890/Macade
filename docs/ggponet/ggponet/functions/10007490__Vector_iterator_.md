# 10007490 `_Vector_iterator<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10007490 |
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
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   >::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,struct std::_Container_base12 const *)
    public: __thiscall std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >::_Vector_iterator<class
   std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Container_base0 const *)
    public: __thiscall std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >::_Vector_iterator<class
   std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Container_base12 const *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 _Vector_iterator<>(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  
  FUN_10007660(param_1,param_2);
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100074a2` | `10007660` | `UNCONDITIONAL_CALL` | FUN_10007660 | `10007660` |

## Callers

| From | Function |
| --- | --- |
| `100057a5` | FUN_10005790 |
| `1000420b` | FUN_100041f0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10007490` | `55` | `PUSH EBP` |
| `10007491` | `8b ec` | `MOV EBP,ESP` |
| `10007493` | `51` | `PUSH ECX` |
| `10007494` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10007497` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1000749a` | `50` | `PUSH EAX` |
| `1000749b` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1000749e` | `51` | `PUSH ECX` |
| `1000749f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100074a2` | `e8 b9 01 00 00` | `CALL 0x10007660` |
| `100074a7` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `100074aa` | `8b e5` | `MOV ESP,EBP` |
| `100074ac` | `5d` | `POP EBP` |
| `100074ad` | `c2 08 00` | `RET 0x8` |
