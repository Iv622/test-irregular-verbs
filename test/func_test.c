
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
CTEST(test_result_min0, test_printf)
{
   
    const int t = -1;

  
    const int result = result_print(t);

  
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(test_result_max0, test_printf)
{
   
    const int t = 21;

  
    const int result = result_print(t);

  
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(test_verbsform_less1, test_verbsform)
{
   
    const int t =0;

  
    const int result = test_verbs(t);

  
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}CTEST(test_verbsform_more3, test_verbsform)
{
   
    const int t = 4;

  
    const int result = test_verbs(t);

  
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}
