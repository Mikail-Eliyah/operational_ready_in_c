#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
void overload_00(int p1)
{
	printf("1 param: %d\n", p1);
}

void overload_01(double *p1, const char *p2)
{
	printf("2 params: %p (%f) %s\n", p1, *p1, p2);
}

void overload_02(int p1, int p2, int p3)
{
	printf("3 params: %c %d %d\n", p1, p2, p3);
}

void overload_main(int case_index, ...)
{
	va_list valist; // va_list is a type to hold information about variable arguments
	va_start(valist, case_index); // va_start must be called before accessing variable argument list
	
	// Now arguments can be accessed 1 by 1 with va_arg macro 
	// Initialize arg_1st as 1st argument in list    
	int arg_1st = va_arg(valist, int); 
	printf("arg_1st: %d \n", arg_1st);
	
	printf("CASE: %d\n", case_index);
			
	switch(case_index)
	{
		case 1:
		{
			int p1 = va_arg(valist, int);
			overload_00(p1);
			break;
		}
		
		case 2:
		{
			double *p1 = va_arg(valist, double *);
			const char *p2 = va_arg(valist, const char *);
			overload_01(p1, p2);
			break;
		}
		
		case 3:
		{
			int p1 = va_arg(valist, int);
			int p2 = va_arg(valist, int);
			int p3 = va_arg(valist, int);
			overload_02(p1, p2, p3);
			break;
		}
	
		default:
		{
			va_end(valist);
			
			printf("Invalid arguments to function '%s_\?\?\?()' \n", __FUNCTION__);
			exit(0); // exit(1)
		}
	}
	/*  */
	va_end(valist); //va_end should be executed before the function returns whenever va_start has been previously used in that function. clean memory reserved for valist
}

#define overload(...)\
	overload_main(COUNT_PARMS(__VA_ARGS__), __VA_ARGS__)

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
/* */
int test_usage_overload_functions()
{
	INFO(">> ");
	
	int p[] = {1, 2, 3, 4};
	double *p1 = (double *)&p[1];
	const char *p2 = (char *)&p[2];
	
	int case_index = 0;
	case_index = 1;
	overload_main(case_index);
	case_index = 3;
	overload_main(case_index, p[0], p[1]);
	case_index = 3;
	overload_main(case_index, p[0], p[1], p[2]);
	case_index = 4;
	overload_main(case_index, p[0], p[1], p[2], p[3]);
	case_index = 2;
	overload_main(case_index, p1, p2);
	// overload_main(p1, p2, p1, p2);
	
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}


