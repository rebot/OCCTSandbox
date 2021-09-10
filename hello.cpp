#include <iostream>
#include <hello.h>
// Include goodbye if set
#ifdef USE_GOODBYE
#  include "goodbye.h"
#endif

int main()
{
  std::cout << "Hello world - by " << AUTHOR << std::endl;
  #ifdef USE_GOODBYE
    std::cout << goodbye(AUTHOR) << std::endl;
  #endif
}
