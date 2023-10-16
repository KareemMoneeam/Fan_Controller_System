/******************************************************************************
 *
 * File Name: Fan_Controller.c
 *
 * Description: Fan Controller System
 *
 * Author: Kareem Abd El-Moneam
 *
 *******************************************************************************/
#include "lcd.h"
#include "adc.h"
#include "lm35_sensor.h"
#include "std_types.h"
#include "dc_motor.h"

int main(void)
{
	/* local variable for checking over temperature values*/
	uint8 temperature;

	/* LCD Initialization */
	LCD_init();
	/* ADC Configurations */
	ADC_ConfigType ADC_Configurations = {INTERNAL, F_CPU_8};
	ADC_init(&ADC_Configurations);

	/* DC Motor Initialization */
	DcMotor_init();

	while (1) {
		/* Reading the temperature using LM35 temperature sensor  */
		temperature = LM35_getTemperature();

		/* If the temperature is less than 30C turn off the fan */
		if (temperature < 30) {
			DcMotor_Rotate(STOP, 0);
			LCD_displayStringRowColumn(0, 4, "FAN is OFF");

		/* If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed */
		} else if (temperature >= 30 && temperature < 60) {
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");

		/* If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed */
		} else if (temperature >= 60 && temperature < 90) {
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");

		/* If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed */
		} else if (temperature >= 90 && temperature < 120) {
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");

		/* If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed */
		} else if (temperature >= 120) {
					DcMotor_Rotate(CW, 100);
					LCD_displayStringRowColumn(0, 4, "FAN is ON ");
		}

		/* Display the temperature on the LCD */
		LCD_displayStringRowColumn(1, 4, "Temp = ");
		LCD_intgerToString(temperature);

		/* To override the additional digit shown after decrementing temperature */
		if (temperature < 100) {
			LCD_displayCharacter(' ');
		}
		LCD_displayString("C");
	}
}
