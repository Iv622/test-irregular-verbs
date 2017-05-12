
#include "ctest.h"
#include <func.h>

CTEST(test_result_five, test_printf)
{
   
    const int t = 19;

  
    const int result = result_print(t);

  
    const int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_result_four, test_printf)
{
   
    const int t = 17;

  
    const int result = result_print(t);

  
    const int expected = 4;
    ASSERT_EQUAL(expected, result);
}
 
CTEST(test_result_three, test_printf)
{
   
    const int t = 12;

  
    const int result = result_print(t);

  
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(test_result_two, test_printf)
{
   
    const int t = 8;

  
    const int result = result_print(t);

  
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}
