#include <stdint.h>
void putch(char ch);

volatile uint32_t *aa = (volatile uint32_t *)(uintptr_t)(0xa0000000);

int main() {
    uint32_t num = 0x83463931;
    for (uint32_t i = 0; i < (uint32_t)0x200; i++){
        *(aa + i) = (uint32_t)(num + i);
    }
    for (uint32_t j = 0; j < (uint32_t)0x200; j++) {
        if (aa[j] != (uint32_t)(num + j)) {
            putch('0');
            putch('\n');
            return 0;
        }
    }
    putch('1');
    putch('\n');
    return 0;
}