 #include <stdio.h>
 
 int main() {
    int num;
    printf("Enter a number -> ");
    scanf("%d", &num);
    while(num%2){
        printf("You are odd, try again -> ");
        scanf("%d", &num);
    }
    /* printf("You are even \n"); */
    printf("You are even ! \n"); 
    int i = 42;
    double r = 2.50;
    printf("simple ");
    printf(" text \n");
    printf("another line\n");
    printf("double %f \n", r);
    printf("integer %d\n", i);
    printf("both %d %f\n",i,r);
    return 0;
 }