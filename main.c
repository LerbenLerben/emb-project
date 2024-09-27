#include "stm32f4xx_hal.h"
#include "main.h"

void delay(uint32_t count) {
    while(count--);
}

int main(void) {
    // Включаем тактирование порта GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Настраиваем PA5 как выход
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    while (1) {
        // Включаем светодиод
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(500000);

        // Выключаем светодиод
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(500000);
    }
}
