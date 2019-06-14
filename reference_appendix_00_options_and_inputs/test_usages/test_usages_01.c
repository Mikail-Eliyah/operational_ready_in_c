#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2
#define END -1   

static int verbose_flag;		// Flag set by ‘--verbose’. 

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

/*
==================================================
============= || LOCAL STRUCTS || ==============
==================================================
*/

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

struct option testopts[] = {
    {"A", no_argument, NULL, 'a'},
    {"B", no_argument, NULL, 'b'},
    {"C", no_argument, NULL, 'c'},
    {"D", no_argument, NULL, 'd'},
    {"E", no_argument, NULL, 'e'},
    {"F", no_argument, NULL, 'f'},    
    {"Verbose", no_argument, NULL, 'v'},
    {"Help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0},
};


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_check_options_00(int argc, char *argv[])
{
	INFO(">> ");
	
	int c, index;
    int aflag = 0, bflag = 0;
    char *cvalue = NULL;   

       while ((c = getopt (argc, argv, "abc:")) != END)
         switch (c) {
           case 'a':
             aflag++;
             break;
           case 'b':
             bflag++;
             break;
           case 'c':
             cvalue = optarg;
             break;
           case '?':
             if (optopt == 'c')
               fprintf (stderr, "Option -%c requires an argument.\n", optopt);
             else if (isprint (optopt))
               fprintf (stderr, "Unknown option `-%c'.\n", optopt);
             else
               fprintf (stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
             //return 1;
             break;
           default:
             //abort ();
             fprintf (stderr, "abort\n");
           }
     
       printf ("aflag = %d, bflag = %d, cvalue = %s\n",
               aflag, bflag, cvalue);
     
       for (index = optind; index < argc; index++)
         printf ("Non-option argument %s\n", argv[index]);
         
		 
	printf("%s\n", DEMARCATOR_STRING);
}
	
/*     
     % testopt -a -b
     aflag = 1, bflag = 1, cvalue = (null)
     
     % testopt -ab
     aflag = 1, bflag = 1, cvalue = (null)
     
     % testopt -c foo
     aflag = 0, bflag = 0, cvalue = foo
     
     % testopt -cfoo
     aflag = 0, bflag = 0, cvalue = foo
     
     % testopt arg1
     aflag = 0, bflag = 0, cvalue = (null)
     Non-option argument arg1
     
     % testopt -a arg1
     aflag = 1, bflag = 0, cvalue = (null)
     Non-option argument arg1
     
     % testopt -c foo arg1
     aflag = 0, bflag = 0, cvalue = foo
     Non-option argument arg1
     
     % testopt -a -- -b
     aflag = 1, bflag = 0, cvalue = (null)
     Non-option argument -b
     
     % testopt -a -
     aflag = 1, bflag = 0, cvalue = (null)
     Non-option argument -
     
     % testopt -c:TEST     
     aflag = 0, bflag = 0, cvalue = :TEST 
*/

int test_usage_check_options_01(int argc, char *argv[])
{
	INFO(">> ");
	
	int c, index;
    int aflag = 0, bflag = 0;

// getopt_long instead of getopt. This function is declared in getopt.h
    
       char *cvalue = NULL;   

       while (1)
         {
           static struct option long_options[] =
             {
               // These options set a flag. 
               {"verbose", no_argument,       &verbose_flag, 1},
               {"brief",   no_argument,       &verbose_flag, 0},
               // These options don't set a flag.                   We distinguish them by their indices. 
               {"add",     no_argument,       0, 'a'},
               {"append",  no_argument,       0, 'b'},
               {"delete",  required_argument, 0, 'd'},
               {"create",  required_argument, 0, 'c'},
               {"file",    required_argument, 0, 'f'},
               {0, 0, 0, 0}
             };
           // getopt_long stores the option index here. 
           int option_index = 0;
     
           c = getopt_long (argc, argv, "abc:d:f:", long_options, &option_index);
     
           // Detect the end of the options. 
           if (c == END)
             break;
     
           switch (c)
             {
             case 0:
               // If this option set a flag, do nothing else now. 
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
               // getopt_long already printed an error message. 
               break;
     
             default:
               abort ();
             }
         }
     
       // Instead of reporting ‘--verbose’ and ‘--brief’ as they are encountered, we report the final status resulting from them. 
       if (verbose_flag)
         puts ("verbose flag is set");
     
       // Print any remaining command line arguments (not options). 
       if (optind < argc) {
           printf ("Non-option ARGV-elements: ");
           while (optind < argc)
             printf ("%s ", argv[optind++]);
           putchar ('\n');
         }
		 
 	printf("%s\n", DEMARCATOR_STRING);
}
        
    
/*     
param: -abc:TEST
option -a
option -b
option -c with value `:TEST'

param: --delete test
option -d with value `test'

param: --file hello.txt
option -f with value `hello.txt'
*/

int test_usage_check_options_02(int argc, char *argv[])
{
	INFO(">> ");
	
	    int command = 0;
    unsigned int ret = 0;

    int verbose = 0;
    int bringup = 0;
    // -vabcdef
    while ((command = getopt_long(argc, argv, "vabcdefh", testopts,
                      NULL)) != -1) {
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
        case 'd':
            ret |= 1 << D;            
            printf("D: 001000\n");            
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
    
    
	printf("%d\n", ret);   // -abcdef = 63d (111111b)

 	printf("%s\n", DEMARCATOR_STRING);
}	

 /* output:
A: 000001
B: 000010
C: 000100
D: 001000
E: 010000
F: 100000
63
 */
