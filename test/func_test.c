#include "ctest.h"
#include <func.h>

CTEST(test_result_five, test_printf)
{
	const int tested_value = 19;
	const int result = result_print(tested_value);
	const int expected_result= 5;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_result_four, test_printf)
{
	const int tested_value = 17;
	const int result = result_print(tested_value);
	const int expected_result = 4;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_result_three, test_printf)
{
	const int tested_value = 12;
	const int result = result_print(tested_value);
	const int expected_result = 3;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_result_two, test_printf)
{
	const int tested_value = 8;
	const int result = result_print(tested_value);
	const int expected_result = 2;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_result_min0, test_printf)
{
	const int tested_value = -1;
	const int result = result_print(tested_value);
	const int expected_result = 0;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_result_max0, test_printf)
{
	const int tested_value = 21;
	const int result = result_print(tested_value);
	const int expected_result = 0;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_verbsform_less1, test_verbsform)
{
	const int tested_value =0;
	const int result = test_verbs(tested_value);
	const int expected_result= -1;
	ASSERT_EQUAL(expected_result, result);
}

CTEST(test_verbsform_more3, test_verbsform)
{
	const int tested_value = 4;
	const int result = test_verbs(tested_value);
	const int expected_result = -1;
	ASSERT_EQUAL(expected_result, result);
}
