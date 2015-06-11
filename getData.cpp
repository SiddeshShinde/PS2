#ifndef PS2_h
#include "PS2.h"
#endif

void PS2::getData(int data[])
{
			sbi(PORT_DATA_OUT,PScommand);// start communication with PSx controller
			sbi(PORT_DATA_OUT,PSclock);
			cbi(PORT_DATA_OUT,PSattention);
	
			transferByte(0x01);// bite 0. header.
			transferByte(0x42);// bite 1. header. (should possibly put test on this byte to detect unplugging of controller.)
			transferByte(0x00);// bite 2. header

			data[0] = transferByte(0x00);                         // bite 3. first data bite.
			data[1] = transferByte(0x00);                         // bite 4.
			data[2] = transferByte(0x00);                         // bite 5.
			data[3] = transferByte(0x00);                         // bite 6.
			data[4] = transferByte(0x00);                         // bite 7.
			data[5] = transferByte(0x00);                         // bite 8.		 
			_delay_us(1);
			sbi(PORT_DATA_OUT,PScommand);// close communication wth PSx controller
			_delay_us(1);
			sbi(PORT_DATA_OUT,PSattention);     // all done.
}
