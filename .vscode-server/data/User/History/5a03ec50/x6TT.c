int main() { int i = 80;
int a[3] = {10, 20, 30}; int *j = a;
int **k = &j;
*j = *j/2;
   (*(*k + 1))++;
   ++(*k);
   ++(*j);
   j + 1;
return 0; }