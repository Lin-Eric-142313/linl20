#include <stdio.h>
int readInput();
void printArray(int array[], int size);

int main() {
    int i;
    int size = readInput();
    int a[size];
    for (i = 0; i < size; i++) {
        a[i] = i;
    }
    printArray(a,size);
    return 0;
}

int readInput(){
    int num;
    printf("Enter a number -> ");
    scanf("%d", &num);
    return num;
}

void printArray(int array[], int size) {
    int i;
    for(i = size - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}