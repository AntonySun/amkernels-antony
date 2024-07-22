#include<trap.h>

int main(){
char str[] = "Hello, world!";
char dst[32]=" ";

strcpy(dst, str);

int n = 0;
int i = 0;
while (str[i] != '\0'){
    n = (unsigned char)dst[i] - (unsigned char)str[i];
    i++;
    assert(n == 0);
}

free(dst);
return 0;
}

