#include<trap.h>

int main(){
    char dst[32] = "hello";
    char src[] = "hello world";

    memcpy(dst, src, 11);

    for (int i = 0; src[i] != '\0'; i++){
        assert(dst[i] == src[i]);
    }
    return 0;
}