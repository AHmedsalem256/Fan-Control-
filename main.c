/*
 * main.c
 *
 *  Created on: Feb 28, 2023
 *      Author: Ahmed Salem 
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"ADC_INTERFACE.h"
#include"TIMERinterface.h"
#include"ICU_interface.h"
#include"LCDINTERFACE.h"

#include<avr/delay.h>


void main()
{
	LCD_VidIntialize();
	VidTimer0_PWM_INIT();
	ADC_INIT();

	DIO_VidSetPinDirection(1,3,1);

	VidSetPWMDutyCycle(0);
	u16 x; // to store temp value

	LCD_VidSendString("TEMP : ");

	LCD_VidGOTOPOS(0,11);

	LCD_VidSendString(" C");


	while(1)
	{
		LCD_VidGOTOPOS(0,9);

		x = ADC_READ(0);

		x = (x * 150 * 5 ) / (1.5 * 1023);

		LCD_VidSendNum(x);

		if(x == 20)
		{
			VidSetPWMDutyCycle(50);
		}
		else
		{
			VidSetPWMDutyCycle(0);
		}



}
}





}





