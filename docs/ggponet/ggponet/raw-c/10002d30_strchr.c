
/* Library Function - Single Match
    char * __cdecl strchr(char *,int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

char * __cdecl strchr(char *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = _strchr(param_1,param_2);
  return pcVar1;
}
