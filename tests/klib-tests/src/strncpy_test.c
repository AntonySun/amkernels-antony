#include<trap.h>

int main(){
    char str[] = "Hello, world!";
    char dst1[32] = " ";
    char dst2[32] = " ";
   // char dst3[32] = " ";
    int i = 0;
    while(str[i] != '\0')
        i++;
    int n1 = 5, n2 = 13;

    strncpy(dst1, str, n1);
    strncpy(dst2, str, n2);
   // strncpy(dst3, str, n3);

    int d1 = 0, d2 = 0;

    while (dst1[d1] != '\0')
        d1++;
    
    while ((unsigned char)dst2[d2] == (unsigned char)str[d2] && str[d2] != '\0')
        d2++;
    assert((d1 == n1) && (d2 == n2));

    return 0;
}