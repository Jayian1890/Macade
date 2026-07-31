
/* Library Function - Multiple Matches With Different Base Names
    __vfprintf_p
    _vfprintf
    _vfprintf_s
   
   Library: Visual Studio 2008 Release */

int __cdecl FID_conflict__vfprintf(FILE *_File,char *_Format,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = vfprintf_helper(__output_l,_File,_Format,0,_ArgList);
  return iVar1;
}
