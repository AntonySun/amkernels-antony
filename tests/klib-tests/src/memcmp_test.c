#include<trap.h>

int main(){
    const char s1[] = "hhhlo";
    const char s2[] = "hello world";
    const char s3[] = "hhh"; 
    int n1 = 0, n2 = 3;
    int l1 = memcmp(s1, s2, n1);
    int l2 = memcmp(s1, s3, n2);
    int l3 = memcmp(s1, s2, 11);

    assert(l1 == 0);
    assert(l2 == 0);
    assert(l3 > 0);
  //  assert(0);

    return 0;
}