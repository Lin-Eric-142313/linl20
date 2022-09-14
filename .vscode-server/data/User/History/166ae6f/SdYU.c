 #include <stdio.h>
 
 int main() {
    int num;
    printf("Enter a number -> ");
    scanf("%d", &num);
    while(num%2){
        printf("You are odd, try again -> ");
        scanf("%d", &num);
    }
    printf("You are even \n");
    /* printf("You are even "); */
    return 0;
 }