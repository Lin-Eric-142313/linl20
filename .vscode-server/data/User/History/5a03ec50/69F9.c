int main() { 
    int i = 80;
    int a[3] = {10, 20, 30}; 
    int *j = a;
    int **k = &j;
    *j = *j/2;
    (*(*k + 1))++;
    ++(*k);
    ++(*j);
    j + 1;
    printf("i Value %d \n",i);
    printf("j Value %p \n", j);
    printf("k value %p \n", k);
    return 0; 
}