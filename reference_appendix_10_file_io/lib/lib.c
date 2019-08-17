#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
void file_stat(char * filename) {
  struct stat stat_p; /* 'stat_p' is a pointer to a structure
 * of type 'stat'.   */

/* Get stats for file and place them in the structure. */
  if ( -1 ==  stat (filename, &stat_p)) {
    printf(" Error occoured attempting to stat %s\n", filename);
    exit(0);
  }
/* Print a few structure members. */   
  printf("Stats for %s \n", filename);
  printf("Modify time is %s \n", format_time(stat_p.st_mtime));
/* Access time does not get updated if filesystem is NFS mounted! */
  printf("Access time is %s\n", format_time(stat_p.st_atime));   
  printf("File size is %d bytes\n", stat_p.st_size);
}

int getNumberOfLinesInFile (char* fileName) {
  FILE* fp;
  char line[LINE_LENGTH];
  int count=0;

  fp=fopen(fileName,"r");
/* Count up the lines here. */
  while ( fgets(line, LINE_LENGTH, fp) != NULL) 
        count++;

  printf("File contains %d lines.\n", count);

  fclose(fp);
  
  return count;
}

int getLongestLineInFile (char* fileName) {
  FILE* fp;
  char line[LINE_LENGTH];
  int longestLength = 0;
  char* longestLine;
  
  int c;

  fp = fopen(fileName,"r");
  
  longestLine = (char*) malloc (strlen(line) * sizeof(char));

  // while ( fgets(line, LINE_LENGTH, fp) != NULL) {
  while ( fgets(line, sizeof(line), fp) != NULL) {        
        if (strlen(line) > longestLength) {
           longestLength = strlen(line);
           free(longestLine);
		   longestLine = (char*) malloc (strlen(line) * sizeof(char));
		   strcpy(longestLine, line);
		   
        }
  }
  
  printf("The longest line is:  %s.\n", longestLine);
  printf("There are:  %d number of characters.\n", longestLength);
  // printf("%d %d\n", EOF, NULL); EOF == -1; NULL == 0
  
  // reset file pointer
  fseek (fp, 0, SEEK_SET); // 0: file start; -1: file end
  
while ((c = fgetc(fp)) != EOF) {
    printf("%c",c); /* O/P the character to the screen */
  }  

  fclose(fp);
  
  return longestLength;
}

void printdir(char *dir, int depth) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    int spaces = depth*4;

    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            /* Found a directory, but ignore . and .. */
            if(strcmp(".",entry->d_name) == 0 ||
                strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",spaces,"",entry->d_name);
            /* Recurse at a new indent level */
            printdir(entry->d_name,depth+1);
        }
        else printf("%*s%s\n",spaces,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
}


char * format_time(time_t cal_time) {
  struct tm *time_struct;
  static char string[30];
/* Put the calendar time into a structure
 * if type 'tm'. */
  time_struct = localtime(&cal_time);

/* Build a formatted date from structure. */
  strftime(string, sizeof string, "%h %e %H:%M\n", time_struct);

/* Return the date/time */
  return(string);
}

