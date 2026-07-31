#include <chrono>
#include <cstdlib>
#include <cstring>
#include <thread>

namespace ggponet::reconstructed {

bool function_10001370_return_true()
{
   return true;
}

void function_100013e0_return_void()
{
}

bool function_10002870_return_true()
{
   return true;
}

bool function_10002880_return_true()
{
   return true;
}

void *function_1000aeb0_return_this(void *self)
{
   return self;
}

char *function_10011480_strcpy(char *destination, const char *source)
{
   return std::strcpy(destination, source);
}

long function_10011a64_atol(const char *text)
{
   return std::atol(text);
}

bool function_10027ac0_sleep(unsigned int milliseconds)
{
   std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
   return true;
}

}
