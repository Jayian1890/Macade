# 10027b50 `FID_conflict:~CXMLNode<IXMLDOMDocument>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10027b50 |
| `name` | FID_conflict:~CXMLNode<IXMLDOMDocument> |
| `namespace` | Global |
| `signature` | undefined FID_conflict:~CXMLNode<IXMLDOMDocument>(void) |
| `size_bytes` | 31 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??1?$CXMLNode@UIXMLDOMDocument@@@ATL@@UAE@XZ, ??1?$CXMLNode@UIXMLDOMElement@@@ATL@@UAE@XZ, ??1?$CXMLNode@UIXMLDOMNode@@@ATL@@UAE@XZ, ??1?$CXMLNode@UIXMLDOMProcessingInstruction@@@ATL@@UAE@XZ, ??1?$CXMLNode@UIXMLDOMText@@@ATL@@UAE@XZ, ??1CDHtmlElementEventSink@@UAE@XZ, FID_conflict:~CXMLNode<IXMLDOMDocument> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall ATL::CXMLNode<struct IXMLDOMDocument>::~CXMLNode<struct
   IXMLDOMDocument>(void)
    public: virtual __thiscall ATL::CXMLNode<struct IXMLDOMElement>::~CXMLNode<struct
   IXMLDOMElement>(void)
    public: virtual __thiscall ATL::CXMLNode<struct IXMLDOMNode>::~CXMLNode<struct
   IXMLDOMNode>(void)
    public: virtual __thiscall ATL::CXMLNode<struct IXMLDOMProcessingInstruction>::~CXMLNode<struct
   IXMLDOMProcessingInstruction>(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void FID_conflict__CXMLNode<IXMLDOMDocument>(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = ReplayBackend::vftable;
  FUN_10002d80();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10027b66` | `10002d80` | `UNCONDITIONAL_CALL` | FUN_10002d80 | `10002d80` |

## Callers

| From | Function |
| --- | --- |
| `10002d5a` | FUN_10002d50 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10027b5a` | `100331c8` | `DATA` | ReplayBackend::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10027b50` | `55` | `PUSH EBP` |
| `10027b51` | `8b ec` | `MOV EBP,ESP` |
| `10027b53` | `51` | `PUSH ECX` |
| `10027b54` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10027b57` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10027b5a` | `c7 00 c8 31 03 10` | `MOV dword ptr [EAX],0x100331c8` |
| `10027b60` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10027b63` | `83 c1 20` | `ADD ECX,0x20` |
| `10027b66` | `e8 15 b2 fd ff` | `CALL 0x10002d80` |
| `10027b6b` | `8b e5` | `MOV ESP,EBP` |
| `10027b6d` | `5d` | `POP EBP` |
| `10027b6e` | `c3` | `RET` |
