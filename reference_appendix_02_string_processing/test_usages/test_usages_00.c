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
int test_usage_string_copy()
{
	INFO(">> ");
	// Between char* array and char[] array transfer

	// copy char* array to char[] array
	// copy char[] array to char* array

    char array1[20] = "abcdefg";
    char* array2;
    
    array2 = (char*) malloc((strlen(array1)+1)*sizeof(char));
    memcpy(array2, array1, strlen(array1)+1); // including "\0"
    
    printf("array2: %s\n", array2);
    //free(array2);
    printf("array2: %s\n", array2);
    strcpy(array1, "x1001x");
    printf("array1: %s\n", array1);
    
    memcpy(array1, array2, strlen(array2)+1); // including "\0"
    printf("array1: %s\n", array1);
	
	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_string_tokenizer()
{
	INFO(">> ");
	
	// strtok
	char text[] = "00 11 22 33 44      55 66 77 ";
	char delimitChar[2] = " "; // includes "\0". Can have > 1 character, any of the listed characters will be part of a delimiter list, eg. "-+"
	int numberOfTokens = 0;
	char *t;
	int i;

	t = strtok(text, delimitChar);

	for (i=0; t != NULL; i++) {
		printf("token %d is \"%s\"\n", i, t);
		t = strtok(NULL, delimitChar);
	}

	numberOfTokens = i;
	printf("Total number of tokens: %d\n", numberOfTokens);
/*
token 0 is "00"
token 1 is "11"
token 2 is "22"
token 3 is "33"
token 4 is "44"
token 5 is "55"
token 6 is "66"
token 7 is "77"

Total number of tokens: 8
*/
    char targetString[50] = "+=***+test+=++=+test+=+test+=+"; // "+=***+test+=++=+test+=+test+=+" // "+*+test+=+test+=+test+=+" // "+=***+test+=+test+=+test+=+" // "+=+test+=+test+=+test+=+"
	char delimiterChars[50] = "+=+";
	char bkup[50];

	char frontToken[100];
	char backToken[100];

	stringTokenizer (targetString, delimiterChars, frontToken, backToken);

	printf("frontToken: %s \n", frontToken);
	printf("backToken: %s \n", backToken);

/*
strlen: 3
frontToken: +=***+test
backToken: +=+test+=+test+=+
*/

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_string_format(){
	INFO(">> ");
		
	char forwardString[] = "abcdefgh";
    reverse_string(forwardString);
    printf("reverse string: %s \n", forwardString); // output: hgfedcba
	
	char strTarget[] = "          1      2 3      4 6 7      8         9 0"; // with tab space and space
    //char strTarget[] = " 1 2 3        4 6 7         8    9 0"; // with space only
    removeWhiteSpaces(strTarget);
    printf("string without space: %s \n", strTarget);


// OUTPUT: string without space: 123467890

	// strtol: converted integral number as a long int value, else zero value is returned.
    
   // char str[300] = "20303a00 <-This is test->"; // number = 20303                    ; base = 10;
   char str[300] = "0x20303a00 <-This is test->"; // number = 540031488 (0x20303a00)    ; base = 16;
   char *ptr;
   long ret;

   //int base = 10;
   int base = 16;
   ret = strtol(str, &ptr, base);
   printf("The number(unsigned long integer) is %ld\n", ret);
   printf("String part is |%s| \n\n\n", ptr);

	
	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_string_encapsulation()
{
	INFO(">> ");
	
	int i = 0;
	int numberOfLayers = 0;
	char* targetStr = "(..(.(...(..)..).)....)";
 
	numberOfLayers = count_Layers_Of_Parenthsis (targetStr, strlen(targetStr));
	printf("%d of numberOfLayer(s).\n", numberOfLayers);

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_string_case()
{
    char* returnStringBuffer;
    char inputStr[] = "123456abcdef123GHI_jkl_";

    int forward_length = 0;

	while (inputStr[forward_length] != '\0') {            // checking for null char
      if (islower(inputStr[forward_length]) != 0) {   // if it is a lowercase
         printf(":%c\n", toupper(inputStr[forward_length]));
      }
      forward_length++;
	}    

	convertToUpperCase(inputStr, strlen(inputStr));
	printf("String converted to (uppercase) %s\n", inputStr);

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_string_position()
{
	int numberOfDectection, i = 0;
	char* delimitChar = ",";
	char* transitionTable[] = {
                          "NA, NA, NA, NA, NA, NA,,,",
                          "defaultStart, elseOther, 1, 2, 6, NA",
                          
      };
      
     int choice = 1;
     printf("%s \n", transitionTable[choice]);
      
     numberOfDectection = findPositionsOfDelimiterCharacters (transitionTable[choice], delimitChar);
      
     // string to character array
	int numberOfCharInLine = strlen(transitionTable[choice]);      
	char targetLine[numberOfCharInLine];
	//targetLine = malloc(sizeof(char)*numberOfCharInLine + sizeof(char)); // last one is for '\0';
    strcpy(targetLine, transitionTable[choice]);
    //printf("%s\n", targetLine);
      
    for (i=0;i<numberOfDectection;i++) {
          printf("%c\n", targetLine[positionsRecorded[i]]); // prints detected delimitChar
    }
      
      for (i=0;i<strlen(transitionTable[choice]);i++) {
          printf("%c-", targetLine[i]); // prints detected delimitChar
      }      
      printf("\n");
      
/* 
fortransitionTable[0]
position 2
position 6
position 10
position 14
position 18
position 22
position 23
position 24
Residue string: 
Total number of detection: 8

fortransitionTable[1]
defaultStart, elseOther, 1, 2, 6, NA
position 12
position 23
position 26
position 29
position 32
Residue string:  NA
Total number of detection: 5
*/      


	char a[11] = "01234656789";
	char* b = "9876543210";

	b = a;
	i = 2;

	printf("%c \n", b[i]); // 2
	printf("%c \n", *(b+i)); // 2
	b=a+i;
	printf("%c \n", *b); // 2

	printf("%s\n", DEMARCATOR_STRING);
}