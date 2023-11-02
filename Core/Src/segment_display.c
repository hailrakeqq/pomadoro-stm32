#include "segment_display.h"

void segmentUpdate(uint8_t number){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, ((number >>0)&0x01));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, ((number >>1)&0x01));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, ((number >>2)&0x01));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, ((number >>3)&0x01));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, ((number >>4)&0x01));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, ((number >>5)&0x01));
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, ((number >>6)&0x01));
}

void updateDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3,
                   uint8_t digit4){
    temp1 = digit1 / 1000;
    temp2 = (digit2 / 100) % 10;
    temp3 = (digit3 / 10) % 10;
    temp4 = digit4 % 10;    

    segmentUpdate(segmentDisplayNumber[temp1]);
    D1_LOW;
    HAL_Delay(1000);
    D1_HIGH;

    segmentUpdate(segmentDisplayNumber[temp2]);
    D2_LOW;
    HAL_Delay(1000);
    D2_HIGH;

    segmentUpdate(segmentDisplayNumber[temp3]);
    D3_LOW;
    HAL_Delay(1000);
    D3_HIGH;

    segmentUpdate(segmentDisplayNumber[temp4]);
    D4_LOW;
    HAL_Delay(1000);
    D4_HIGH;     
}

void clearDisplay(){
    D1_LOW;
    D2_LOW;
    D3_LOW;
    D4_LOW;

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}

void test(){
    for (int counter = 0; counter < 1000; counter++){
        if(counter == 200){
            clearDisplay();
            HAL_Delay(5000);
        }
        temp1 = counter / 1000;
        temp2 = (counter / 100) % 10;
        temp3 = (counter / 10) % 10;
        temp4 = counter % 10;

        segmentUpdate(segmentDisplayNumber[temp1]);
        D1_LOW;
        HAL_Delay(7);
        D1_HIGH;

        segmentUpdate(segmentDisplayNumber[temp2]);
        D2_LOW;
        HAL_Delay(7);
        D2_HIGH;

        segmentUpdate(segmentDisplayNumber[temp3]);
        D3_LOW;
        HAL_Delay(7);
        D3_HIGH;

        segmentUpdate(segmentDisplayNumber[temp4]);
        D4_LOW;
        HAL_Delay(7);
        D4_HIGH;
    }
}
