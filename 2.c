#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB = 0xFF;
    char pattern = 0x0F;
    while(1) {
        PORTB = pattern;
        if(pattern == 0x0F) pattern = 0xF0;
        else if (pattern == 0xF0) pattern = 0x1E;
        else if (pattern == 0x1E) pattern = 0x78;
        else pattern = 0x0F;
        _delay_ms(2000);
    }
    return 0;
}