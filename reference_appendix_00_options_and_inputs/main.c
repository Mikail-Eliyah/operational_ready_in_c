#include "main.h"

int main(int argc, char *argv[]) {
	// test_usage_check_options_00(argc, argv); // test_usage: run -a -b
	// test_usage_check_options_01(argc, argv);	// test_usage: run --file hello.txt
	
	/* test_usage: 
	./run -a
	./run -b
	./run
	*/
	test_usage_check_options_02(argc, argv);
	
	// test_usage_check_inputs(argc, argv); test_usage: ./run '4' 'abcd' 'arg3' 'arg4' 'arg5' 'arg6' 'arg7'
	
  return(0);
}