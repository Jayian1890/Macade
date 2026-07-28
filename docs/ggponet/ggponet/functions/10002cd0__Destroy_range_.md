# 10002cd0 `_Destroy_range<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002cd0 |
| `name` | _Destroy_range<> |
| `namespace` | Global |
| `signature` | undefined _Destroy_range<>(void) |
| `size_bytes` | 38 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | _Destroy_range<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > &,struct std::_Nonscalar_ptr_iterator_tag)
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > &,struct
   std::_Nonscalar_ptr_iterator_tag)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void _Destroy_range<>(_Container_proxy *param_1,_Container_proxy *param_2,
                     allocator<std::_Container_proxy> *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    std::allocator<std::_Container_proxy>::destroy(param_3,param_1);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10002ced` | `10004500` | `UNCONDITIONAL_CALL` | std::allocator<std::_Container_proxy>::destroy | `10004500` |

## Callers

| From | Function |
| --- | --- |
| `10002c78` | FUN_10002c50 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002cd0` | `55` | `PUSH EBP` |
| `10002cd1` | `8b ec` | `MOV EBP,ESP` |
| `10002cd3` | `eb 09` | `JMP 0x10002cde` |
| `10002cd5` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10002cd8` | `83 c0 08` | `ADD EAX,0x8` |
| `10002cdb` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `10002cde` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10002ce1` | `3b 4d 0c` | `CMP ECX,dword ptr [EBP + 0xc]` |
| `10002ce4` | `74 0e` | `JZ 0x10002cf4` |
| `10002ce6` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10002ce9` | `52` | `PUSH EDX` |
| `10002cea` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10002ced` | `e8 0e 18 00 00` | `CALL 0x10004500` |
| `10002cf2` | `eb e1` | `JMP 0x10002cd5` |
| `10002cf4` | `5d` | `POP EBP` |
| `10002cf5` | `c3` | `RET` |
