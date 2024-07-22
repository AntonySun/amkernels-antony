#include<trap.h>
size_t strnlen(const char * s, size_t count);
int main(){
    char s1[] = "ysyxnemu";
    char s2[] = "hello world";
    unsigned int count = 10;
   unsigned int len1 = strnlen(s1, count);
    unsigned int len2 = strnlen(s2, count);
    assert(len1 == 8);
    assert(len2 == count);

    return 0;
}