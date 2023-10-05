#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB = 0xFF;                  
    DDRF &= ~(1 << PF0);          
    PORTF |= (1 << PF0);          
    char patterns[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    int index = 0;
    char lastButtonState = 1;     
    while(1) {
        char currentButtonState = (PINF & (1 << PF0)) ? 1 : 0;
        if (lastButtonState && !currentButtonState) {  // 버튼이 눌러졌는지 감지
            index = (index + 1) % 8;
            PORTB = patterns[index];
            _delay_ms(50);  
        }
        lastButtonState = currentButtonState;
        _delay_ms(10);  // 버튼 샘플링을 위한 작은 지연
    }
    return 0;
}