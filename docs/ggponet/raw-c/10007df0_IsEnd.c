
/* Library Function - Multiple Matches With Same Base Name
    public: bool __thiscall CTypedPtrListIterator<class CList<void *,void *>,struct
   COleControlSiteOrWnd *>::IsEnd(void)const 
    public: bool __thiscall CTypedPtrListIterator<class CPtrList,struct COleControlSiteOrWnd
   *>::IsEnd(void)const 
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

bool IsEnd(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x1c) == 0;
}
