# 100056d0 `_Vector_iterator<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100056d0 |
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
  
  FUN_10006360(param_1,param_2);
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100056e2` | `10006360` | `UNCONDITIONAL_CALL` | FUN_10006360 | `10006360` |

## Callers

| From | Function |
| --- | --- |
| `10004c45` | FUN_10004c30 |
| `10005ac9` | FUN_10005ab0 |
| `10006474` | FUN_10006460 |
| `1000556b` | FUN_10005550 |
| `10005bbe` | FUN_10005ae0 |
| `1000622a` | FUN_10005dd0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100056d0` | `55` | `PUSH EBP` |
| `100056d1` | `8b ec` | `MOV EBP,ESP` |
| `100056d3` | `51` | `PUSH ECX` |
| `100056d4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `100056d7` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `100056da` | `50` | `PUSH EAX` |
| `100056db` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100056de` | `51` | `PUSH ECX` |
| `100056df` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100056e2` | `e8 79 0c 00 00` | `CALL 0x10006360` |
| `100056e7` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `100056ea` | `8b e5` | `MOV ESP,EBP` |
| `100056ec` | `5d` | `POP EBP` |
| `100056ed` | `c2 08 00` | `RET 0x8` |
