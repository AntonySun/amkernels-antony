#include <stdint.h>
void putch(char ch);

volatile uint8_t *aa = (volatile uint8_t *)(uintptr_t)(0xc0000000);

int main() {
    uint32_t num = 0x83463931;
    for (uint32_t i = 0; i < (uint32_t)0x1000; i++){
        *(aa + i) = (uint8_t)(num + i);
    }
    for (uint32_t j = 0; j < (uint32_t)0x1000; j++) {
        if (aa[j] != (uint8_t)(num + j)) {
            putch('0');
            putch('\n');
            return 0;
        }
    }
    putch('1');
    putch('\n');
    return 0;
}