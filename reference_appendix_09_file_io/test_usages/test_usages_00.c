#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

int display_N_values_per_line = 20;

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

// int main(int argc, char* argv[])
int test_usage_file_stat(int argc, char* argv[])
{
	INFO(">> ");
	char* FILENAME = "./test_data/data.txt";

    file_stat(FILENAME);
    getNumberOfLinesInFile (FILENAME);
    getLongestLineInFile (FILENAME);
	
	
    // char *topdir, pwd[2]=".";
    char* targetPath = ".";
    char *topdir, pwd[MAXPATHLEN];

    strcpy(pwd, targetPath);

    //printf("PATH='%s'\n", getenv("PATH"));

    char path[MAXPATHLEN];
    getcwd(path, MAXPATHLEN);
    printf("pwd -> %s\n", path);
	
	topdir = pwd;
	
	printf("Path: %s provided.\n", argv[1]);

    if (argc != 2)
        topdir=pwd;
    else
        topdir=argv[1];

	
    printf("Directory scan of %s\n",topdir);
    printdir(topdir,0);

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_displays_file_names_in_directory()
{
	INFO(">> ");
	
	DIR           *d;
	struct dirent *dir;
	d = opendir("./test_data/");
	
	int count_file = 0;
  
  if (d)   {
    while ((dir = readdir(d)) != NULL)
    //if (dir->d_type == DT_REG)
    {
      printf("%s\n", dir->d_name);
	  count_file++;
    }

    closedir(d);
  }
  printf("== - %d - ==\n", (1 << 6));
  // system("PAUSE");    

	  printf("%d file(s) found.\n", count_file);

    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}

/* */
