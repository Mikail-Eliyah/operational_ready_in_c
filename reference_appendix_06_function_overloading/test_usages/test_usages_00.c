#include "main.h"

// global variables
enum case_types {param_0, param_1, param_2, param_3, NOT_VALID}; 

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
	printf("2 params: %p %d (%f) %s\n", p1, *p1, *p1, p2);
}

void overload_02(int p1, int p2, int p3)
{
	printf("3 params: %d %d %d\n", p1, p2, p3);
}

void overload_main(int number_of_arguments, ...)
{
	// enum case_types case_type;
	
	va_list valist; // va_list is a type to hold information about variable arguments
	va_start(valist, number_of_arguments); // va_start must be called before accessing variable argument list
	
	// Now arguments can be accessed 1 by 1 with va_arg macro 
	// Initialize arg_1st as 1st argument in list    
	//int arg_1st = va_arg(valist, int); 
	//printf("arg_1st: %d \n", arg_1st);
	
	printf("CASE: %d\n", number_of_arguments);
			
	switch(number_of_arguments)
	{
		case param_1:
		{
			//printf("%s \n", typename(valist));
			int p1 = va_arg(valist, int);
			overload_00(p1);
			break;
		}
		
		case param_2:
		{
			//printf("%s \n", typename(valist));
			//printf("%s \n", typename(valist));
			double *p1 = va_arg(valist, double *);
			const char *p2 = va_arg(valist, const char *);
			overload_01(p1, p2);
			break;
		}
		
		case param_3:
		{
			//printf("%s \n", typename(valist));
			//printf("%s \n", typename(valist));
			//printf("%s \n", typename(valist));
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
	
	int p[] = {101, 202, 303, 404};
	double *p1 = (double *)&p[1];
	char letter = 'm';
	const char *p2 = &letter;
	
	int case_index = 0;
	case_index = param_1;
	overload_main(case_index, p[0]);
	
	case_index = param_1;
	overload_main(case_index);	// lacking arguments will be pointed to uninitialized memory
	
	case_index = param_3;
	overload_main(case_index, p[0], p[1]);
	case_index = param_3;
	overload_main(case_index, p[0], p[1], p[2]);	// extra arguments will be omitted
	
	case_index = param_3;
	overload_main(case_index);	// lacking arguments will be pointed to uninitialized memory	
	
	case_index = param_2;
	overload_main(case_index, p1, p2);
	
	case_index = NOT_VALID;
	overload_main(case_index, p[0], p[1], p[2], p[3]);	// extra arguments will be omitted

	// overload_main(p1, p2, p1, p2);
	
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}


