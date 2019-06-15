#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

// returns numberOfDectection
int findPositionsOfDelimiterCharacters (char* text, char* delimitChar){
    
    int numberOfDelimiterCharacters = 0;
    int position = 0;
    int lastPositionTracked = 0;
    int numberOfDectection = 0;

    char *s = text;
  
    //printf("Text: %s\n", s);  
    //printf("delimitChar: %s\n", delimitChar);
      
  if ((s == NULL) || (strlen(s) == 0))
    return 0;
    
    position = strcspn (s, delimitChar);
        
  while( position != strlen(s)) {      // end of string (position of NULL char)
    printf("position %d \n", (lastPositionTracked + position));
    lastPositionTracked = lastPositionTracked + position;
    positionsRecorded[numberOfDectection] = lastPositionTracked; // record positions
    numberOfDectection++;
    
    s = strstr(s, delimitChar); // remove the line before the DelimiterCharacters
    s++; // skip 1 character (may skip by strlen(delimitChar))
    lastPositionTracked++;
    
    position = strcspn (s, delimitChar);        
  }
  
  printf("Residue string: %s\n", s); 
  printf("Total number of detection: %d\n", numberOfDectection); 
  
  return numberOfDectection;
}


/*
// string is assumed not to be empty or null
Test 
1. startingParenthsis is closed. >>printf("ERR: Parenthsis started as closed.\n");           [PASS]
2. noParenthsis found            >>printf("ERR: No Parenthsis found.\n");                    [PASS]
3. Parenthese not closed properly >>printf("ERR: Parenthese not closed properly.\n");         [PASS]
4. There are x number of layers found. >>       "()()()" : 1 layer; "(..(.(...(..)..).)....)" : 4 layers      [PASS]
*/
int count_Layers_Of_Parenthsis (char* targetStr, int strLength) {
    int i = 0;
    int numberOfLayersTrack = 0;
    int numberOfLayers = 0;
    int lastTrackPosition = 0;
    int previousIsOpenParenthesis = 0;
    
    
    for (i=0; i<strLength; i++) {
        if (targetStr[i] == closeParenthsisChar) {
           printf("ERR: Parenthsis started as closed.\n");              
           return numberOfLayers;     // There are 0 layer
        } else if (targetStr[i] == openParenthsisChar) {
           numberOfLayersTrack++;
           lastTrackPosition = ++i; // archive position tracked so far
           numberOfLayers++;
           previousIsOpenParenthesis = 1;
           break;    
        }
    }
    
    if (i == strLength) {
           printf("ERR: No Parenthsis found.\n");              
           return numberOfLayers;     // There are 0 layer          
    }  
    
    for (i=lastTrackPosition; i<strLength; i++) {
        if (targetStr[i] == openParenthsisChar) {
           numberOfLayersTrack++;
           if (previousIsOpenParenthesis == 1){ // (...(  to increase to the next layer
              numberOfLayers++;
           } 
           //i++; // go immediately to the next char
        }
        if (targetStr[i] == closeParenthsisChar){
           numberOfLayersTrack--;
           previousIsOpenParenthesis = 0;
           //i++; // go immediately to the next char
        }       
    }
    
    if (numberOfLayersTrack != 0) {
       printf("The statement is not closed properly. There are\\is still %d open parenthsis.\n", numberOfLayersTrack);
    }  
    
    return numberOfLayers;
}

// Changing to (upper/lower)case of a string
void convertToUpperCase(char *sPtr, int stringLength) {
     int i = 0;
     
      while(sPtr[i] != '\0') {          // checking for null char
         if (islower(sPtr[i]) != 0) {   // if it is a lowercase
              sPtr[i] = toupper(sPtr[i]);
         }   
         i++;  
       }
}

void stringTokenizer (char targetString[], char delimiterChars[], char* frontToken, char* backToken) 
{
	int numberOfCharInTargetStr = strlen(targetString);
	int numberOfCharInDelimterStr = strlen(delimiterChars);
	printf("strlen: %d \n", numberOfCharInDelimterStr);

	int i, falseHitTracker = 0, hitCount = 0, hitIndexOfDelimiterStr = 0, skipCharCount = 0;
	
	int frontTokenCount = 0, backTokenCount = 0, backTokenStartIndex = 0;

for (i=0;i<numberOfCharInTargetStr;i++) {
    if (targetString[i] == delimiterChars[hitIndexOfDelimiterStr]) {  
         skipCharCount++;    
         hitCount++; 
         hitIndexOfDelimiterStr++;
         
         if (hitCount == numberOfCharInDelimterStr) {
            skipCharCount -= numberOfCharInDelimterStr;       // would have include at least numberOfCharInDelimterStr   
            break;
         }   
    } else {
           if (hitIndexOfDelimiterStr !=0) { // refill for past false hits
                 for (falseHitTracker = hitIndexOfDelimiterStr; falseHitTracker != 0;falseHitTracker--) {
                     frontToken[frontTokenCount++] = targetString[i-falseHitTracker];
                 }
                 // recover skip count
                 skipCharCount -= hitIndexOfDelimiterStr;
           }      
         hitIndexOfDelimiterStr = 0;  // clear
         hitCount = 0;  
         frontToken[frontTokenCount++] = targetString[i];
    }
}

frontToken[frontTokenCount] = '\0';
backTokenStartIndex = frontTokenCount + numberOfCharInDelimterStr + skipCharCount;

if (strlen(frontToken) != 0) { // if the target string header is not started with the delimiter characters

   for (i=backTokenStartIndex;i<numberOfCharInTargetStr;i++) {
       backToken[backTokenCount++] = targetString[i];
   }    
} else {
   for (i=numberOfCharInDelimterStr;i<numberOfCharInTargetStr;i++) {
       backToken[backTokenCount++] = targetString[i];
   }    
}

backToken[backTokenCount] = '\0';     
}

// Reversing the string
void reverse_string(char *str) {
     char * end = str;
     char tmp;
 
     if (str) { // if not '\0' (null char)
        while (*end) {    // while not '\0' (null char), proceed to find (point to) the last character (which is a null char)
              ++end;
        }

        --end;            // point to the last character before the null char

        while (str< end) {  // while the 2 pointers do not meet yet
           tmp = *str;       // store the value pointed by the forward pointer
           *str++ = *end;    // place the value at the end to the pointer moving forward, move the forward pointer forward
           *end-- = tmp;     // place the tmp value at the end, and move the end pointer backwards
        }
     }
 }

// Removing white space(s) from string
void removeWhiteSpaces(char* source) { // remove space and tab space in char string
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if((*i != ' ') || (*i != ' ')) // 2nd form is tab space
    //if(*i != ' ')
      i++;
  }
  *i = 0;
}

