/**
 * This program reads a text file and prints the top 5 most frequent letters (upper or lower case)
 * and the top 5 most frequent digits that are in the file. If the file has less than 5 unique letters
 * and/or digits the top list is adjusted accordingly. The file name is provided using command line 
 * arguments. If the file name is not provided or the file is not readable, the program will exit
 * and provide an error message.
 *
 * @author Eric Lin {@literal linl20@wfu.edu}
 * @date Sept.14, 2022
 * @assignment Lab 2
 * @course CSC 250
 **/

#include <stdio.h>
#include <ctype.h>

#define MAX_ALPHALIST_SIZE 26
#define MAX_DIGITLIST_SIZE 10

/* a useful struct, if you choose to use it */  
struct CharFreq {
    char ch;
    int count;
};

/* function declarations go here */
int processCharacters(char filename[], struct CharFreq alphaList[], int *alphaNumPtr, 
     struct CharFreq digitList[], int *digitNumPtr);
int search(char ch, struct CharFreq list[], int num);
void printArray(struct CharFreq alphaList[], int alphaNum, struct CharFreq digitList[], int digitNum);

/* main method begins */
int main(int argc, char* argv[]){
    struct CharFreq alphaList[MAX_ALPHALIST_SIZE];
    struct CharFreq digitList[MAX_DIGITLIST_SIZE];
    int alphaNum = 0;
    int digitNum = 0;
    int fileOK = 1;

    if (argc < 2) {
        printf("Usage error: %s filename \n", argv[0]);
        return 1;
    }
    fileOK = processCharacters(argv[1], alphaList, &alphaNum, digitList, &digitNum);
    if (!fileOK) {
        printf("%s could not be opened, and AJ is nice \n", argv[1]);
        return 1;
    }
    printArray(alphaList, alphaNum, digitList, digitNum);

    return 0;
}

/* open the file and count the frequency of letters and numbers in it */
int processCharacters(char filename[], struct CharFreq alphaList[], int *alphaNumPtr,
 struct CharFreq digitList[], int *digitNumPtr) {
    char ch;
    FILE *filePtr = fopen(filename, "rie");
    int loc = 0;
    int alphaNum = *alphaNumPtr;  
    int digitNum = *digitNumPtr;

    if(filePtr == 0){
        return 0;
    }

    printf("file name is %s \n", filename);

    ch = fgetc(filePtr);
    while (ch != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            loc = search(ch, alphaList, alphaNum);
            if (loc != -1) {
                alphaList[loc].count++;
            }
            else {
                alphaList[alphaNum].ch = ch;
                alphaList[alphaNum].count = 1;
                alphaNum++;
            }
        }
        else if (isdigit(ch)) {
            loc = search(ch, digitList, digitNum);
            if (loc != -1) {
                digitList[loc].count++;
            }
            else {
                digitList[digitNum].ch = ch;
                digitList[digitNum].count = 1;
                digitNum++;
            }
        }
        ch = fgetc(filePtr);
    }
    fclose(filePtr);
    *alphaNumPtr = alphaNum;
    *digitNumPtr = digitNum;
    return 1;
}

/* return the location of the character in the list, return -1 if not found */
int search(char ch, struct CharFreq list[], int num) {
    int loc = -1;
    int i;
    for(i = 0; i < num && loc == -1; i++)
        if(list[i].ch == ch)
            loc = i;
    return loc;
}

/* sort and print the array */
void printArray(struct CharFreq alphaList[], int alphaNum, struct CharFreq digitList[], int digitNum) {
    int i;
    int j;
    int countA1;
    int countA2;
    int countD1;
    int countD2;

    /* bubble sort alphaList and digitList */
    for (countA1 = 0 ; countA1 < alphaNum - 1; countA1++) {
        for (countA2 = 0 ; countA2 < alphaNum - countA1 - 1; countA2++) {
            if (alphaList[countA2].count < alphaList[countA2 + 1].count) {
                struct CharFreq swap;
                swap = alphaList[countA2];
                alphaList[countA2] = alphaList[countA2 + 1];
                alphaList[countA2 + 1] = swap;
            }
        }
    }

    for (countD1 = 0 ; countD1 < digitNum - 1; countD1++) {
        for (countD2 = 0 ; countD2 < digitNum - countD1 - 1; countD2++) {
            if (digitList[countD2].count < digitList[countD2 + 1].count) {
                struct CharFreq swap;
                swap = digitList[countD2];
                digitList[countD2] = digitList[countD2 + 1];
                digitList[countD2 + 1] = swap;
            }
        }
    }

    /* print top 5 of both lists */
    if (alphaNum < 5) {
        printf("alpha top %d out of %d \n", alphaNum, alphaNum);
        printf("--------------------- \n");
        for(i = 0; i < alphaNum; i++)
        printf("[%c], %d \n", alphaList[i].ch, alphaList[i].count);
    } else {
        printf("alpha top 5 out of %d \n", alphaNum);
        printf("--------------------- \n");
        for(i = 0; i < 5; i++)
        printf("[%c], %d \n", alphaList[i].ch, alphaList[i].count);
    }
    printf("\n");

    if (digitNum < 5) {
        printf("alpha top %d out of %d \n", digitNum, digitNum);
        printf("--------------------- \n");
        for(j = 0; j < digitNum; j++)
        printf("[%c], %d \n", digitList[j].ch, digitList[j].count);
    } else {
        printf("alpha top 5 out of %d \n", digitNum);
        printf("--------------------- \n");
        for(j = 0; j < 5; j++)
        printf("[%c], %d \n", digitList[j].ch, digitList[j].count);
    }
}