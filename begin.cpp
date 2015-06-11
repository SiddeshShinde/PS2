#ifndef PS2_h
#include "PS2.h"
#endif

void PS2::begin()
{
     /* PS2 controller I/O pin setup:*/
	sbi(PORT_DIR_SET, PSclock);                 // clock. output. (blue)
	cbi(PORT_DIR_SET, PSdata);                 // data. input. (brown)
	sbi(PORT_DATA_OUT,PSdata);                // enable pullup resistor
	sbi(PORT_DIR_SET, PScommand);                 // command. output. (orange)
	sbi(PORT_DIR_SET, PSattention);                 // attention. output. (yellow)

        init_PS2inanalougemode();
}



