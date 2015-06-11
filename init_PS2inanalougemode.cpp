#ifndef PS2_h
#include "PS2.h"
#endif

void PS2::init_PS2inanalougemode()
{
 	int chk_ana = 0, cnt = 0;
	while(chk_ana != 0x73)
	{
		   // put controller in config mode
		   sbi(PORT_DATA_OUT, PScommand);
		   sbi(PORT_DATA_OUT, PSclock);
		   cbi(PORT_DATA_OUT, PSattention);
		   transferByte(0x01);
		   transferByte(0x43);
		   transferByte(0x00);
		   transferByte(0x01);
		   transferByte(0x00);
		   sbi(PORT_DATA_OUT, PScommand);
		   _delay_ms(1);
		   sbi(PORT_DATA_OUT, PSattention);       
		   _delay_ms(10);         
		   // put controller in analouge mode
		   sbi(PORT_DATA_OUT, PScommand);
		   sbi(PORT_DATA_OUT, PSclock);
		   cbi(PORT_DATA_OUT, PSattention);
		   transferByte(0x01);
		   transferByte(0x44);
		   transferByte(0x00);
		   transferByte(0x01);
		   transferByte(0x03);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);

		   sbi(PORT_DATA_OUT, PScommand);
		   _delay_ms(1);
		   sbi(PORT_DATA_OUT, PSattention);         
		   _delay_ms(10);
		   // exit config mode
		   sbi(PORT_DATA_OUT, PScommand);
		   sbi(PORT_DATA_OUT, PSclock);
		   cbi(PORT_DATA_OUT, PSattention);
          
		   transferByte(0x01);
		   transferByte(0x43);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x5A);
		   transferByte(0x5A);
		   transferByte(0x5A);
		   transferByte(0x5A);
		   transferByte(0x5A);
            
		   sbi(PORT_DATA_OUT, PScommand);
		   _delay_ms(1);
		   sbi(PORT_DATA_OUT, PSattention);           
		   _delay_ms(10);
         

		   // poll controller and check in analouge mode.

		   sbi(PORT_DATA_OUT, PScommand);
		   sbi(PORT_DATA_OUT, PSclock);
		   cbi(PORT_DATA_OUT, PSattention);

         
		   transferByte(0x01);
		   chk_ana = transferByte(0x42);            // the 2nd byte to be returned from the controller should = 0x73 for "red" analouge controller.
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);
		   transferByte(0x00);

		   sbi(PORT_DATA_OUT, PScommand);
		   _delay_ms(1);
		   sbi(PORT_DATA_OUT, PSattention);
		   _delay_ms(10);
	  // keep increasing counter to be dispalyed untill PSx controller confirms it's in analouge mode.
	  	   if (cnt > 254){ cnt=0;}
	}
}
