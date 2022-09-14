/**
 * This program reads a text file and prints the top 5 most frequent letters (upper or lower case)
 * and the top 5 most frequent digits that are in the file. If the file has less than 5 unique letters
 * and/or digits the top list is adjusted accordingly. The file name is provided using command line 
 * arguments. If the file name is not provided or the file is not readable, the program will exit
 * and provide an error message.
 *
 * @author Your Name Here {@literal }
 * @date Sept. 8, 2022
 * @assignment Lab 2
 * @course CSC 250
 **/

#include <stdio.h>
#include <ctype.h>
 
#define MAX_LIST_SIZE 26

/* a useful struct, if you choose to use it */  
struct CharFreq {
    char ch;
    int count;
};

/* function declarations go here */
int processCharacters(char filename[], struct CharFreq alphaList[], int *alphaNumPtr, 
     struct CharFreq digitList[], int *digitNumPtr);
int search(char ch, struct CharFreq list[], int num);

int main(int argc, char* argv[]){
    struct CharFreq alphaList[MAX_LIST_SIZE];
    struct CharFreq digitList[MAX_LIST_SIZE];
    int alphaNum = 0;
    int digitNum = 0;
    int fileOK = 1;
    int i;

    if(argc < 2){
        printf("Usage error: %s filename \n", argv[0]);
        return 1;
    }

    fileOK = processCharacters(argv[1], alphaList, &alphaNum, digitList, &digitNum);
    if(!fileOK){
        printf("%s could not be opened, and AJ is nice \n", argv[1]);
        return 1;
    }

    /* the following MUST be in a new function function */ 
    for(i = 0; i < alphaNum; i++)
        printf("letter %c, count %d \n", alphaList[i].ch, alphaList[i].count);
    for(i = 0; i < digitNum; i++)
        printf("digit %c, count %d \n", digitList[i].ch, digitList[i].count);

    return 0;
}


int processCharacters(char filename[], struct CharFreq alphaList[], int *alphaNumPtr,
 struct CharFreq digitList[], int *digitNumPtr) {
    char ch;
    FILE *filePtr = fopen(filename, "rie");
    int loc = 0;
    int alphaNum = *alphaNumPtr;  /* local copy of the alphaNum value */
    int digitNum = *digitNumPtr;  /* local copy of the digitNum value */

    if(filePtr == 0){
        return 0;
    }

    printf("file name is %s \n", filename);

    ch = fgetc(filePtr);
    while(ch != EOF) {
        if(isalpha(ch)){
            ch = tolower(ch);
            loc = search(ch, alphaList, alphaNum);
            if(loc != -1){
                alphaList[loc].count++;
            }
            else{
                alphaList[alphaNum].ch = ch;
                alphaList[alphaNum].count = 1;
                alphaNum++;
            }
        }
        else if(isdigit(ch)){
            loc = search(ch, digitList, digitNum);
            if(loc != -1){
                /* do something here */
            }
            else{
                /* do something here too */
                digitNum++;
            }
        }
        ch = fgetc(filePtr);
    }

    fclose(filePtr);

    /* let's copy our local copy back to main's copy */
    *alphaNumPtr = alphaNum;
    *digitNumPtr = digitNum;

    return 1;
}


int search(char ch, struct CharFreq list[], int num){
    int loc = -1;
    int i;
    for(i = 0; i < num && loc == -1; i++)
        if(list[i].ch == ch)
            loc = i;
    return loc;
}