#ifndef SEGMENT_DISPLAY_H
#define SEGMENT_DISPLAY_H

#include "main.h"

#define D1_HIGH HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET)
#define D1_LOW HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET)
#define D2_HIGH HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET)
#define D2_LOW HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET)
#define D3_HIGH HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET)
#define D3_LOW HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET)
#define D4_HIGH HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET)
#define D4_LOW HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET)

static uint8_t temp1, temp2, temp3, temp4;

static uint8_t segmentDisplayNumber[10] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67  // 9
};

void segmentUpdate(uint8_t number);
void updateDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3,
                   uint8_t digit4);
void test();
void clearDisplay();

#endif // !SEGMENT_DISPLAY_H#define