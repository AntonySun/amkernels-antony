#include<trap.h>

int main(){
    char dst[32] = "ysyx-nemu ";
    char dst2[32] = " ";
    char src[] = "hello world";
    for (int i = 0; dst[i] != '\0'; i++){
        dst2[i] = dst[i];
    }
    int d_len = 0;
    while (dst[d_len] != '\0') {
        d_len++;
    }
    strcat(dst, src);
    int i = d_len, j = 0, k = 0;
    while (k < d_len){
        assert(dst[k] == dst2[k]);
        k++;
    }
    while (dst[i] != '\0' && src[j] != '\0'){
        assert(dst[i] == src[j]);
        i++;
        j++;
    }
    return 0;
}