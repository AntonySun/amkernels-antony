#include<trap.h>

int strcmp(const char *s1, const char *s2);

int main(){
    const char s1[] = "hello";
    const char s2[] = "hello world";
    const char s3[] = "hhh"; 

    int l1 = strcmp(s1, s1);
    int l2 = strcmp(s1, s3);
    int l3 = strcmp(s1, s2);

    assert(l1 == 0);
    assert(l2 < 0);
    assert(l3 < 0);

    return 0;
}