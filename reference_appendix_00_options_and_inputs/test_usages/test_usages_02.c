#include "main.h"

// global variables
/* Flag set by ‘--verbose’. */
static int verbose_flag;

#define FIELD_SIZE 100
#define END -1


/*
==================================================
============== || LOCAL FUNCTIONS || ===============
==================================================
*/
void A_test (){
	printf("A_test invoked.\n");
}

void b_test (){
	printf("b_test invoked.\n");
}

void c_test (){
	printf("c_test invoked.\n");
}

void i_test (){
	printf("i_test invoked.\n");
}

void e_test (){
	printf("e_test invoked.\n");
}

/*
==================================================
============== || LOCAL STRUCTS || ===============
==================================================
*/

struct fields {
    char *title;
    char *artist;
    char *album;
    int year;
    char *comment;
    int track;
};

static struct fields field =
{
  .title = "",
  .artist = "",
  .album = "",
  .year = 0,
  .comment = "",
  .track = 0,
};

/*
enum test_types {
    A,
    B,
    C,
    D,
    E,
    F,
    G = F,
    LAST_TEST  = F
};
*/

#define LAST_TEST  F

enum test_types {
    A,
    B,
    C,
    I, // 001000
    E,
    F,
    G = F,
};


static int (*test_func[]) (void) = {
    [A] = A_test,
    [B] = b_test,
    [C] = c_test,
    [I] = i_test,
    [E] = e_test,
};


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_check_options_05 (int argc, char *argv[])
{
	INFO(">> ");
	
	struct option testopts[] = {
    {"A", no_argument, NULL, 'a'},
    {"B", no_argument, NULL, 'b'},
    {"C", no_argument, NULL, 'c'},
    {"I", no_argument, NULL, 'i'},
    {"E", no_argument, NULL, 'e'},
    {"F", no_argument, NULL, 'f'},    
    {"Verbose", no_argument, NULL, 'v'},
    {"Help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0},
	};
	
	int run_case = 0, num_tests_failed = 0, i;
	int test_mask = 0xffffffff;
    int command = 0;
    unsigned int ret = 0;

    int verbose = 0;
    int bringup = 0;
    // -abif
    while ((command = getopt_long(argc, argv, "vabciefh", testopts, NULL)) != -1) {
        switch (command) {
        case 'v':
            verbose = 1;
            break;
        case 'a':
            ret |= 1 << A;
            printf("A: 000001\n");
            break;
        case 'b':
            ret |= 1 << B;
            printf("B: 000010\n");           
            break;
        case 'c':
            ret |= 1 << C;
            printf("C: 000100\n");
            break;
        case 'i':
            ret |= 1 << I;           
            printf("I: 001000\n");           
            break;
        case 'e':
            ret |= 1 << E;
            printf("E: 010000\n");
            break;
        case 'f':
            ret |= 1 << F;
            printf("F: 100000\n");
            break;
        case 'h':
            //usage(0);
            break;
        default:
            //usage(-1);
            //exit(0);
            printf("%d\n", ret);   //
        }
    }

	printf("%d\n", ret);   // -abcdef = 43d (101011b)
 
     /* Condition to check if it is a 'i' is ON */
    if ((ret & (1 << I)) == (1U << I)) 
       printf("[I] is ON\n");   // -i exist
    else  {
       printf("[I] is OFF\n");   // -i absent

		for (i = 0; i < LAST_TEST; i++) {	
            /* Look for the test that was selected */
            if (!(test_mask & (1U << i)))
                continue;

            /* This test was selected, so run it */
            run_case = test_func[i]();

            if (run_case) {
                printf("%s test case FAILED! run_case:%d\n",
                    testopts[i].name, run_case);
                num_tests_failed++;
            }

		if (num_tests_failed) // if there is > 0 test failures
			printf("NUMBER OF TESTS FAILED: %d\n", num_tests_failed);

     }
	}
	
	printf("%s\n", DEMARCATOR_STRING);
}

	
int test_usage_check_options_04 (int argc, char *argv[])
{
	INFO(">> ");
	
	char ch;
	
	static struct option long_options[] = {
		{"title", required_argument, NULL, 't'},
		{"artist", required_argument, NULL, 'a'},
		{"album", required_argument, NULL, 'b'},
		{"year", required_argument, &field.year, 'y'},
		{"comment", required_argument, NULL, 'c'},
		{"track", required_argument, NULL, 'u'},
		{NULL, 0, NULL, 0}
	};

	// loop over all of the options
	while ((ch = getopt_long(argc, argv, "t:a:", long_options, NULL)) != END)
	{
		// check to see if a single character or long option came through
		switch (ch)
		{
         // short option 't'
         case 't':
             field.title = optarg; // or copy it if you want to
             break;
         // short option 'a'
         case 'a':
             field.artist = optarg; // or copy it if you want to
             break;
		}
	}
	
	printf("field.title: %s\n", field.title);
	printf("field.artist: %s\n", field.artist);

	
	printf("%s\n", DEMARCATOR_STRING);
}


int test_usage_check_options_03 (int argc, char *argv[])
{
	INFO(">> ");
	
       int c;
      // -ba -f x1 -d x2 -c x3 --v
      // --v : verbose flag is set
      // 
       while (1) {
           static struct option long_options[] = {
               /* These options set a flag. */
               {"verbose", no_argument,       &verbose_flag, 1},
               {"brief",   no_argument,       &verbose_flag, 0},
               /* These options don't set a flag.
                  We distinguish them by their indices. */
               {"add",     no_argument,       0, 'a'},
               {"append",  no_argument,       0, 'b'},
               {"delete",  required_argument, 0, 'd'},
               {"create",  required_argument, 0, 'c'},
               {"file",    required_argument, 0, 'f'},
               {0, 0, 0, 0}
             };
           /* getopt_long stores the option index here. */
           int option_index = 0;
     
           c = getopt_long (argc, argv, "abc:d:f:", // ':' means the symbol before that takes an argument
                            long_options, &option_index);
     
           /* Detect the end of the options. */
           if (c == -1)
             break;
     
           switch (c)  {
             case 0:
               /* If this option set a flag, do nothing else now. */
               if (long_options[option_index].flag != 0)
                 break;
               printf ("option %s", long_options[option_index].name);
               if (optarg)
                 printf (" with arg %s", optarg);
               printf ("\n");
               break;
     
             case 'a':
               puts ("option -a\n");
               break;
     
             case 'b':
               puts ("option -b\n");
               break;
     
             case 'c':
               printf ("option -c with value `%s'\n", optarg);
               break;
     
             case 'd':
               printf ("option -d with value `%s'\n", optarg);
               break;
     
             case 'f':
               printf ("option -f with value `%s'\n", optarg);
               break;
     
             case '?':
               /* getopt_long already printed an error message. */
               if (   (optopt == 'c') || 
                       (optopt == 'd') || 
                 (optopt == 'f')   ) {
                                 fprintf (stderr, "option -%c requires an argument \n", optopt);
                       } else {
                                 fprintf (stderr, "Unknown option -%c \n");
                       }
               break;
     
             default:
                    fprintf (stderr, "getopt\n");              
               // abort ();
             }
         }
     
       /* Instead of reporting ‘--verbose’
          and ‘--brief’ as they are encountered,
          we report the final status resulting from them. */
       if (verbose_flag)
         puts ("verbose flag is set");
       else
         puts ("verbose flag is NOT set");
     
       /* Print any remaining command line arguments (not options). */
       if (optind < argc)
         {
           printf ("non-option ARGV-elements: ");
           while (optind < argc)
             printf ("%s ", argv[optind++]);
           putchar ('\n');
         }


	printf("%s\n", DEMARCATOR_STRING);
}

