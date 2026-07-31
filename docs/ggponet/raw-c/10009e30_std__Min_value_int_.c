
/* Library Function - Single Match
    int const & __cdecl std::_Min_value<int>(int const &,int const &)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

int * __cdecl std::_Min_value<int>(int *param_1,int *param_2)

{
  undefined4 local_c;
  
  if (*param_1 < *param_2) {
    local_c = param_2;
  }
  else {
    local_c = param_1;
  }
  return local_c;
}
