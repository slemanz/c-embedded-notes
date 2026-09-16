/**********************************************************************************
*                                                                                 *
*                                    EXTERNAL                                     *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

extern int mainGlobalData; // declare that variable exists
// use when you need access a variable that are define in other file

// extern extend the visibility of a function or variable!!!

void file_Func1(void)
{
	mainGlobalData = 200;
}

static void test_static(void) // dont can be called in main.c directly
{
	printf("static function from external.c file!!!\n");
}

void test_file(void)
{
	test_static();
}

