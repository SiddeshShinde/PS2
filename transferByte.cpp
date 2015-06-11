#ifndef PS2_h
#include "PS2.h"
#endif

int PS2::transferByte(int command)
{
        int i ; 
        _delay_us(1);
        int data = 0x00;                             // clear data variable to save setting low bits later.
	for(i=0;i<8;i++)
        {
		if(command & _BV(i))
		{ 
			sbi(PORT_DATA_OUT,PScommand);       // bit bang "command" out on PScommand wire.
		} 
		else 
		{
			cbi(PORT_DATA_OUT,PScommand);
		}
		cbi(PORT_DATA_OUT, PSclock);                             // CLOCK LOW
		_delay_us(1);                                    // wait for output to stabilise
		if((PORT_DATA_IN & _BV(PSdata))) 
		{
			sbi(data, i);                               // read PSdata pin and store
		}
		else
		{ 
			cbi(data, i);
		}
		sbi(PORT_DATA_OUT,PSclock);                             // CLOCK HIGH
        }
        sbi(PORT_DATA_OUT,PScommand);        
        _delay_us(20);                                                   // wait for ACK to pass.
        return(data);
}
