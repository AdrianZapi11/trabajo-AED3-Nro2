#include <Arduino.h>
#include "stm32f103xb.h"

void setup() {
    RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN_Msk);
    RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN_Msk);  
    GPIOA->CRL = 0x44444444;
    GPIOA->CRH = 0x11111111;
}

void loop() {
    uint32_t B = GPIOB->IDR; 
    uint32_t resta = B - 0x23; 
    GPIOA->BSRR = resta; 
}