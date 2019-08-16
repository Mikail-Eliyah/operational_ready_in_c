#include "main.h"

#define NumberOfFiles 5

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
void createMultipleFiles () {
    FILE *fp;
    int i = 0;

    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    // Buffer for storing the directory path
    char buff[128];
    memset(buff,0,sizeof(buff));

    char* startNode = "./test_data/";

    // Open the directory stream
       if(NULL == (dp = opendir(startNode)) ) {
           printf("\n Cannot open Input directory [%s]\n", startNode);
           exit(1);
       } else {
           // create multiple files
           for (i=0; i < NumberOfFiles ;i++) {
			   // strcat(buff, startNode);
			   sprintf(buff, "%s%d", startNode, i);
               strcat(buff, ".txt");
               fp = fopen(buff, "w+");
               // fp = fopen(buff, "r+");
               if (!fp) {
                   printf("Fail to create file.\n");
                   
                   return 1;
               } else {
                   
                   printf("File: %s created.\n", buff);
                   fprintf(fp, "This is testing from fprintf()...\n");
                   fputs("This is testing for fputs...\n", fp);

                   fclose(fp);
               }
           }
       }

       printf("\n");

       // Close the directory stream
       closedir(dp);
/*
File: 0.txt created.
File: 1.txt created.
File: 2.txt created.
File: 3.txt created.
File: 4.txt created.
 */
}

void readMultipleFiles () {
    FILE *fp;
    int i = 0;

    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    // Buffer for storing the directory path
    char buff[128];
    memset(buff,0,sizeof(buff));

    char* startNode = "./test_data/";

    // Open the directory stream
       if(NULL == (dp = opendir(startNode)) ) {
           printf("\n Cannot open Input directory [%s]\n", startNode);
           exit(1);
       } else {
           // create multiple files
           for (i=0; i < NumberOfFiles ;i++) {
			   // strcat(buff, startNode);
               sprintf(buff, "%s%d", startNode, i);
               strcat(buff, ".txt");
               // fp = fopen(buff, "w+");
               fp = fopen(buff, "r+");
               if (!fp) {
                   printf("Fail to create file.\n");

                   return 1;
               } else {

                   /*
                   printf("File: %s created.\n", buff);
                   fprintf(fp, "This is testing from fprintf()...\n");
                   fputs("This is testing for fputs...\n", fp);
                   */
                   printf("\n\nFile: %s \n============\n", buff);

                   char line [ 128 ]; /* or other suitable maximum line size */
                   while ( fgets ( line, sizeof line, fp ) != NULL ) /* read a line */
                   {
                       fputs ( line, stdout ); /* write the line */
                   }

                   fclose(fp);
               }
           }
       }

       printf("\n");

       // Close the directory stream
       closedir(dp);
/*
File: 0.txt 
============
This is testing from fprintf()...
This is testing for fputs...


File: 1.txt 
============
This is testing from fprintf()...
This is testing for fputs...


File: 2.txt 
============
This is testing from fprintf()...
This is testing for fputs...


File: 3.txt 
============
This is testing from fprintf()...
This is testing for fputs...


File: 4.txt 
============
This is testing from fprintf()...
This is testing for fputs...

 */
}


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_create_and_read_files(){
	INFO(">> ");
	
	createMultipleFiles ();
	readMultipleFiles ();
	
	printf("%s\n", DEMARCATOR_STRING);
}	

int test_usage_00(){
	INFO(">> ");
	
	FILE *fp;
   long int positionCounter = 7;
   char* path_to_file = "./test_data/file.txt";
   fp = fopen(path_to_file, "w+");
   
   // printf("%d\n", fp);
   
   fputs("This is start.com", fp);
  
   fseek(fp, positionCounter, SEEK_SET);
   fputs(" C Programming Langauge", fp); // file.txt now contains "This is C Programming Langauge"
//
	fprintf(fp, "This is testing...\n");

   fclose(fp);

	char str[] = "This is a tutorial";

   fp = fopen(path_to_file , "w" );
   fwrite(str , 1 , sizeof(str) , fp );

   fclose(fp);
   

   char c[] = "tutorial";
   char buffer[20];

   /* Open file for both reading and writing */
   fp = fopen(path_to_file, "w+");

   /* Write data to the file */
   fwrite(c, strlen(c) + 1, 1, fp);

   /* Seek to the beginning of the file */
   fseek(fp, SEEK_SET, 0);

   /* Read and display data */
   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   fclose(fp);
	// read lines from file

   // char buffer[20];

   fp = fopen(path_to_file, "r");
   fscanf(fp, "%s", buffer);
   printf("Read Buffer: %s\n", &buffer);
   fclose(fp);

/*
SEEK_SET    Beginning of file
SEEK_CUR    Current position of the file pointer
SEEK_END    End of file

w  - open for writing (file need not exist)
a  - open for appending (file need not exist)
r+ - open for reading and writing, start at beginning
w+ - open for reading and writing (overwrite file)
a+ - open for reading and writing (append if file exists)
*/   

	// Reading and writing binary files is much the same as any other file, only difference is how you open it:
	unsigned char buffer_00[10];
	FILE *ptr;
	path_to_file = "./test_data/test.bin";
	ptr = fopen(path_to_file, "rb");  // r for read, b for binary
	
	if (ptr == NULL) {
		perror("Failed: ");
		return 1;
	}
	
	fread(buffer_00,sizeof(buffer_00),1,ptr); // read 10 bytes to buffer
	// when you "output" this data, you're not reading ASCII, so it's not like printing a string to the screen:
	for(int i = 0; i<10; i++)
		printf("%u (%x), ", buffer_00[i], buffer_00[i]); // prints a series of bytes
	printf("\n");

	// Writing to a file
	FILE *write_ptr;
	write_ptr = fopen(path_to_file,"wb");  // w for write, b for binary

	fwrite(buffer_00, sizeof(buffer_00),1,write_ptr); // write 10 bytes to buffer
	
	printf("%s\n", DEMARCATOR_STRING);
}