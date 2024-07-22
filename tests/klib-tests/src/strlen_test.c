#include<trap.h>

int main(){
    char s1[] = "ysyx-nemu";
    char s2[] = "hello world";
    unsigned int s1len = strlen(s1);
    unsigned int s2len = strlen(s2);
    assert(s1len == 9);
    assert(s2len == 11);

    return 0;
}