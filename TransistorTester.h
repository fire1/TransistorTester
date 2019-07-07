//
// Created by Angel Zaprianov on 2019-07-03.
//

#ifndef TRANSISTORTESTER_TRANSISTORTESTER_H
#define TRANSISTORTESTER_TRANSISTORTESTER_H

#include <Arduino.h>

#define COMMON

struct Diode_t {
    uint8_t Anode;
    uint8_t Cathode;
    unsigned int Voltage;
};

COMMON struct Diode_t diodes[6];
COMMON uint8_t NumOfDiodes;

COMMON struct {
    unsigned long hfe[2];        // current amplification factor
    unsigned int uBE[2];        // B-E-voltage of the Transistor
    uint8_t b, c, e;        // pins of the Transistor
} trans;

COMMON unsigned int gthvoltage;    // Gate-threshold voltage

COMMON uint8_t PartReady;    // part detection is finished
COMMON uint8_t PartMode;
COMMON uint8_t tmpval, tmpval2;
COMMON unsigned int ref_mv;     // Reference-voltage  in mV units

COMMON struct resis_t {
    unsigned long rx;        // value of resistor RX
#if FLASHEND > 0x1fff
    unsigned long lx;        // inductance 10uH or 100uH
    int8_t lpre;        // prefix for inductance
#endif
    uint8_t ra, rb;        // Pins of RX
    uint8_t rt;            // Tristate-Pin (inactive)
} resis[3];

COMMON uint8_t ResistorsFound;    // Number of found resistors
COMMON uint8_t ii;        // multipurpose counter

COMMON struct cap_t {
    unsigned long cval;        // capacitor value
    unsigned long cval_max;    // capacitor with maximum value
    union t_combi {
        unsigned long dw;        // capacity value without corrections
        uint16_t w[2];
    } cval_uncorrected;
#if FLASHEND > 0x1fff
    unsigned int esr;        // serial resistance of C in 0.01 Ohm
    unsigned int v_loss;    // voltage loss 0.1%
#endif
    uint8_t ca, cb;        // pins of capacitor
    int8_t cpre;            // Prefix for capacitor value  -12=p, -9=n, -6=u, -3=m
    int8_t cpre_max;        // Prefix of the biggest capacitor
} cap;

#ifndef INHIBIT_SLEEP_MODE
// with sleep mode we need a global ovcnt16
COMMON volatile uint16_t ovcnt16;
COMMON volatile uint8_t unfinished;
#endif

COMMON int16_t load_diff;    // difference voltage of loaded capacitor and internal reference

COMMON uint8_t WithReference;    // Marker for found precision voltage reference = 1
COMMON uint8_t PartFound;    // the found part
COMMON char outval[12];        // String for ASCII-outpu
COMMON uint8_t empty_count;    // counter for max count of empty measurements
COMMON uint8_t mess_count;    // counter for max count of nonempty measurements

COMMON struct ADCconfig_t {
    uint8_t Samples;        // number of ADC samples to take
    uint8_t RefFlag;        // save Reference type VCC of IntRef
    uint16_t U_Bandgap;        // Reference Voltage in mV
    uint16_t U_AVCC;        // Voltage of AVCC
} ADCconfig;

#ifdef AUTO_CAL
COMMON uint8_t pin_combination;    // coded Pin-combination  2:1,3:1,1:2,x:x,3:2,1:3,2:3
COMMON uint16_t resis680pl;    // port output resistance + 680
COMMON uint16_t resis680mi;    // port output resistance + 680
COMMON uint16_t pin_rmi;    // port output resistance to GND side, 0.1 Ohm units
COMMON uint16_t pin_rpl;    // port output resistance to VCC side, 0.1 Ohm units
#endif

#ifdef AUTO_CAL
// AutoCheck Function is needed
#define CHECK_CALL
#define RR680PL resis680pl
#define RR680MI resis680mi
#define RRpinPL pin_rpl
#define RRpinMI pin_rmi
#else
#define RR680PL (R_L_VAL + PIN_RP)
#define RR680MI (R_L_VAL + PIN_RM)
#define RRpinPL (PIN_RP)
#define RRpinMI (PIN_RM)
#endif

#ifndef ESR_ZERO
// define a default zero value for ESR measurement (0.01 Ohm units)
#define ESR_ZERO 20
#endif

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

void displayValue(unsigned long Value, int8_t Exponent, unsigned char Unit, unsigned char digits);

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

void waitForButton();

void AutoCheck(void);

void printBattery();
#endif //TRANSISTORTESTER_TRANSISTORTESTER_H
