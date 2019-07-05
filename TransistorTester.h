//
// Created by Angel Zaprianov on 2019-07-03.
//

#ifndef TRANSISTORTESTER_TRANSISTORTESTER_H
#define TRANSISTORTESTER_TRANSISTORTESTER_H

#include <Arduino.h>

void lcdString(char *data);

void lcdCursor(uint8_t row, uint8_t col);

void lcdData(unsigned char temp1);

void serialPut(uint8_t data);

void serialPut(const __FlashStringHelper *data);

void lcdFixString(const unsigned char *data);

void drawBmp(const uint8_t *bitmap);

void Calibrate_UR();

void lcdClear(void);

void lcdTestPin(unsigned char temp);

void lcdFlashString(const __FlashStringHelper *str);

void lcdSpace(void);

void lcdDraw();

unsigned int W5msReadADC(uint8_t Probe);

unsigned int W10msReadADC(uint8_t Probe);

unsigned int W20msReadADC(uint8_t Probe);

void DisplayValue(unsigned long Value, int8_t Exponent, unsigned char Unit, unsigned char digits);

void GetIr(uint8_t hipin, uint8_t lopin);

void UfOutput(uint8_t bcdnum);

void mVOutput(uint8_t nn);

void CheckPins(uint8_t HighPin, uint8_t LowPin, uint8_t TristatePin);

uint8_t AllProbesShorted(void);

void RvalOut(uint8_t ii);

unsigned int ReadADC(uint8_t Probe);

void ReadCapacity(uint8_t HighPin, uint8_t LowPin);

void ReadInductance(void);

void lcdPgmString(const unsigned char *data);

void RefVoltage(void);

void PinLayout(char pin1, char pin2, char pin3);

uint16_t GetESR(uint8_t hipin, uint8_t lopin);
void unloadingPins();

#endif //TRANSISTORTESTER_TRANSISTORTESTER_H
