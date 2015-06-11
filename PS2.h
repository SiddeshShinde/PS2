/*
BIT BANG PS2  for atmega16 -connection according to SPI
-------------LOOKING AT THE PLUG-------------------
        -------------------------------
 PIN 1->| o  o  o | o  o  o | o  o  o |
        \_____________________________/

    PIN # USAGE
 1    DATA
 2    COMMAND
 3    N/C (9 Volts unused)
 4    GND
 5    VCC
 6    ATT
 7    CLOCK
 8    N/C
 9    ACK
----NOTES--
*> 0x5A(by controller) to say "here comes the data".
*> bite 1. header. (should possibly put test on this byte to detect unplugging of controller.)
 ie if (temp==0x73)
*/
#ifndef Arduino_h
#include "Arduino.h"
#endif

#include <avr/io.h>
#include <avr/delay.h>

#define sbi(x,y)  x|=(1<<y)  
#define cbi(x,y)  x&=~(1<<y)
#define _BV(y)  (1<<y)

#define PORT_DATA_OUT PORTB
#define PORT_DATA_IN PINB
#define PORT_DIR_SET DDRB

class PS2
{
public:
	PS2(int,int,int,int);
        void begin();
	int transferByte(int);
	void init_PS2inanalougemode(void);
	void getData(int[]);
private:
	int PSdata;
	int PScommand;
	int PSclock;
	int PSattention;
};

