#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h> 
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include <ctype.h>
#include <getopt.h>

// directory, files and folders
#include <dirent.h> 

#include <sys/stat.h> /* declare the 'stat' structure */
#include <sys/types.h> 

/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define TRUE 1
#define FALSE 0

#define MAXPATHLEN  500
#define LINE_LENGTH 800

// Set modes and status using directives to deviate options
// Tagging comments to dis/en-able code for different configuration
#define OFF 0
#define ON 1

#define OPERATION_STATUS ON 

#define PI 3.14159265
#define DEMARCATOR_STRING "==========================================================="

#define INFO(msg) \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING); \
    fprintf(stderr, "[info]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, "%s\n", msg); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
#define ANNOUNCE_FUNCTION_CALLED() \
	fprintf(stderr, "[invoke]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
#define LINE_NUMBER_OF_WHICH_CODE_FILE fprintf(stderr,"[LOG] %s:%d\n",__FILE__,__LINE__);
	
/*
==================================================
=============== || DEFINE TYPES || ===============
==================================================
*/
  typedef unsigned int uint32;
  typedef unsigned intsize_t;

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
// int test_usage_check_data_format(void);
int test_usage_displays_file_names_in_directory(void);
int test_usage_file_stat(int argc, char* argv[]);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
void file_stat(char * filename);
int getNumberOfLinesInFile (char* fileName);
int getLongestLineInFile (char* fileName);
void printdir(char *dir, int depth);

char * format_time(time_t cal_time);
