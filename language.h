//
// Created by Angel Zaprianov on 2019-07-05.
//

#ifndef TRANSISTORTESTER_LANGUAGE_H
#define TRANSISTORTESTER_LANGUAGE_H

#include <Arduino.h>

#define LCD_CHAR_DIODE1 0x91 // Diode-Icon; will be generated as custom character
#define LCD_CHAR_DIODE2 0x92 // Diode-Icon; will be generated as custom character
#define LCD_CHAR_CAP    0x93 // Capacitor-Icon;  will be generated as custom character
// numbers of RESIS1 and RESIS2 are swapped for OLED display, which shows a corrupt RESIS1 character otherwise ???
#define LCD_CHAR_RESIS1 0x94 // Resistor left part will be generated as custom character
#define LCD_CHAR_RESIS2 0x95 // Resistor right part will be generated as custom character
#define LCD_CHAR_OMEGA  0x90 // Omega-character
#define LCD_CHAR_U      0xB5 // micro-characte

#define Cathode_char 'C'

const unsigned char TestRunning[] PROGMEM = "Testing...";
const unsigned char BatWeak[] PROGMEM = "weak";
const unsigned char BatEmpty[] PROGMEM = "empty!";
const unsigned char TestFailed2[] PROGMEM = "damaged ";
const unsigned char Component[] PROGMEM = "part";
//const unsigned char Diode[] PROGMEM = "Diode: ";
const unsigned char Triac[] PROGMEM = "Triac";
const unsigned char Thyristor[] PROGMEM = "Thyristor";
const unsigned char Unknown[] PROGMEM = " unknown";
const unsigned char TestFailed1[] PROGMEM = "No, unknown, or";
const unsigned char OrBroken[] PROGMEM = "or damaged ";
const unsigned char TestTimedOut[] PROGMEM = "Timeout!";

const unsigned char SELFTEST[] PROGMEM = "Self-test mode..";
const unsigned char RELPROBE[] PROGMEM = "isolate Probe!";
const unsigned char ATE[] PROGMEM = "Test End";

const unsigned char Bat_str[] PROGMEM = "Bat. ";
const unsigned char OK_str[] PROGMEM = "OK";
const unsigned char mosfet_str[] PROGMEM = "-MOS";
const unsigned char jfet_str[] PROGMEM = "JFET";
const unsigned char GateCap_str[] PROGMEM = "C=";
const unsigned char hfe_str[] PROGMEM = "B=";
const unsigned char NPN_str[] PROGMEM = "NPN ";
const unsigned char PNP_str[] PROGMEM = "PNP ";
const unsigned char N123_str[] PROGMEM = "123=";

const unsigned char Uf_str[] PROGMEM = "Uf=";
const unsigned char vt_str[] PROGMEM = "Vt=";
const unsigned char Vgs_str[] PROGMEM = "@Vgs=";
const unsigned char CapZeich[] PROGMEM = {'-', LCD_CHAR_CAP, '-', 0};
const unsigned char Cell_str[] PROGMEM = "Cell!";
const unsigned char VCC_str[] PROGMEM = "VCC=";

#if FLASHEND > 0x1fff
const unsigned char ESR_str[] PROGMEM = " ESR=";
const unsigned char VLOSS_str[] PROGMEM = " Vloss=";
const unsigned char Lis_str[] PROGMEM = "L=";
const unsigned char Ir_str[] PROGMEM = "  Ir=";


const unsigned char VERSION_str[] PROGMEM = "T.Tester 1.08.4";

const unsigned char AnKat[] PROGMEM = {'-', LCD_CHAR_DIODE1, '-', 0};
const unsigned char KatAn[] PROGMEM = {'-', '|', '<', '-', 0};
const unsigned char Diodes[] PROGMEM = {'-', '>', '|', ' ', 0};
const unsigned char Resistor_str[] PROGMEM = {'-', LCD_CHAR_RESIS1, LCD_CHAR_RESIS2, '-', 0};

#endif


const unsigned char URefT[] PROGMEM = "Ref=";
const unsigned char RHfakt[] PROGMEM = "RHf=";
const unsigned char RH1L[] PROGMEM = "RH-";
const unsigned char RH1H[] PROGMEM = "RH+";
const unsigned char RLRL[] PROGMEM = "+RL- 12 13 23";
const unsigned char RHRH[] PROGMEM = "+RH- 12 13 23";
const unsigned char RHRL[] PROGMEM = "RH/RL";
const unsigned char R0_str[] PROGMEM = "R0=";
#define LCD_CLEAR



const unsigned char RIHI[] PROGMEM = "Ri_Hi=";
const unsigned char RILO[] PROGMEM = "Ri_Lo=";
const unsigned char C0_str[] PROGMEM = "C0 ";
const unsigned char T50HZ[] PROGMEM = " 50Hz";



const unsigned char MinCap_str[] PROGMEM = " >100nF";
const unsigned char REF_C_str[] PROGMEM = "REF_C=";
const unsigned char REF_R_str[] PROGMEM = "REF_R=";


#ifdef DebugOut
#define LCD_CLEAR
#endif



#endif //TRANSISTORTESTER_LANGUAGE_H
