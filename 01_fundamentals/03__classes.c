/**********************************************************************************
*                                                                                 *
*                                  STORAGE CLASSES                                *
*                                                                                 *
***********************************************************************************/
#include <stdio.h>

void myFunc1(void);
int mainGlobalData;
void file_Func1();
static void change_system_clock(int system_clock);
void test_file(void);

void main()
{
	// Storage Classes decide:
	// The scope, visibility and life time of a variable.
	// static and extern

	myFunc1();
	myFunc1();
	myFunc1();
	myFunc1();

	mainGlobalData = 100;
	printf("mainGlobalData = %d\n", mainGlobalData);
	file_Func1();
	printf("mainGlobalData = %d\n", mainGlobalData);
	change_system_clock(16000);
	test_file();

}

void myFunc1(void)
{
	// a global variable that is private to a function.
	// not lose its existence 
	static int count = 0;
	count = count + 1;
	printf("This function was executed %d times\n", count);
}

static void change_system_clock(int system_clock) // only main.c can call this function
{
	printf("System clock change to %d\n", system_clock);
}