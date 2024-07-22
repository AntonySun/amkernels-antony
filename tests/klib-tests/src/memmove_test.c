#include<trap.h>

int main(){
    char data[10] = "123456789";
    char data2[10] = " ";
    char data3[10] = " ";
    memmove(data2, data, 9);
    memmove(data3, data, 5);
    memmove(data+3, data, 7);
    for (int i = 0; i < 9; i++){
        assert(data2[i] == i+'1');
    }
    for (int i = 0; i < 5; i++) {
        assert(data3[i] == i + '1');
    }
    for (int i = 0; i < 9; i++) {
        if (i <= 2)
            assert(data[i] == i + '1');
        else
            assert(data[i] == i - 3 + '1');
    }
    return 0;
}