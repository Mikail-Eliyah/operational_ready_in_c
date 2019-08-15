#include "main.h"

int main(int argc, char *argv[]) {
	// test_usage_check_options_00(argc, argv); // test_usage: run -a -b
	// test_usage_check_options_01(argc, argv);	// test_usage: run --file hello.txt
	
	/* test_usage: 
	./run -a
	./run -b
	./run
	*/
	// test_usage_check_options_02(argc, argv);
	// test_usage_check_inputs(argc, argv); test_usage: ./run '4' 'abcd' 'arg3' 'arg4' 'arg5' 'arg6' 'arg7'
	
	// test_usage_check_options_03(argc, argv); // ./run -ba -f x1 -d x2 -c x3 --v
	
	// test_usage_check_options_04(argc, argv);  // ./run exe filename -title "title" -artist "artist" -year 1991 -comment "comment" -album "album" -track 1
	/*
	# ./run -title "title" -artist "artist" -year 1991 -comment "comment" -album "album" -track 1
	./run -t "title_001100" -a "Uru:threads"
	*/
	test_usage_check_options_05(argc, argv); // ./run -vabciefh
	
	
  return(0);
}