#ifndef F_CPU
#define F_CPU 14745600UL // or whatever may be your frequency
#endif

#ifndef PS2_h
#include "PS2.h"
#endif

PS2 trial(2,3,4,5);
int data[6];
void setup()
{
	trial.begin();	
}
void loop()
{
	   while(1)
	   {
               trial.getData(data);
               Serial.println(" ");
	       Serial.print(data[0]);
               Serial.print(data[1]);
               Serial.print(data[2]);
               Serial.print(data[3]);
               Serial.print(data[4]);
               Serial.print(data[5]);
               Serial.println(" ");
          }  

}
