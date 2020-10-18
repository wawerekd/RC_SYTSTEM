/*
 * oled.c
 *
 *  Created on: 19.01.2020
 *      Author: Damian
 */

#include "oled.h"

const unsigned char init_screen[] = {

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff,
		0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x3f, 0x81, 0xff, 0xff, 0xe0, 0x7f, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x18, 0x7f, 0xff,
		0xc6, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x7e, 0x18, 0x3f, 0xff, 0x86, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x18, 0x3f, 0xff, 0x06, 0x0f, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x3c, 0x1f, 0xff,
		0x07, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x78, 0x7e, 0x1f, 0xfe, 0x1f, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x79, 0xff, 0xdf, 0xfe, 0x7f, 0xf7, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0xff, 0x9f, 0xfe,
		0x7f, 0xf7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x78, 0x3c, 0x1f, 0x3e, 0x0f, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x1c, 0x1e, 0x1f, 0x07, 0x07, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x18, 0x3c, 0xcf,
		0x06, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x7e, 0x18, 0x7c, 0x8f, 0x86, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xfc, 0xcf, 0xc0, 0x3f, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc3, 0xfc, 0x0f,
		0xf0, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x7f, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x0f,
		0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x7f, 0x3f, 0xfc, 0x0f, 0xff, 0x9f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x1f, 0xfc, 0x0f, 0xfe, 0x0f, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0f, 0xfc, 0x0f,
		0xfc, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x78, 0x0f, 0xfc, 0x0f, 0xfc, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x78, 0x0f, 0xfe, 0x0f, 0xfc, 0x07, 0x80, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x0f, 0xff, 0x3f,
		0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x3c, 0x1f, 0xff, 0xff, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff,
		0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00 };

void oledInit(void) {

	HAL_GPIO_WritePin(OLED_PWR_GPIO_Port, OLED_PWR_Pin, SET);
	HAL_Delay(5);
	SSD1306_Init(); // initialize the diaply

}

void oledPrintInitScreen(void) {

	const char *firmawre_version = "1.1";

	char buffor_string[25];

	sprintf(buffor_string, "v%s %s", firmawre_version, __DATE__);

	SSD1306_Clear();

	SSD1306_DrawBitmap(0, 0, init_screen, 128, 64, 1);
	SSD1306_DrawRectangle(0, 0, 128, 64, 1);

	SSD1306_UpdateScreen(); // update screen
	HAL_Delay(2e3);

	SSD1306_Clear();
	SSD1306_GotoXY(10, 10); // goto 10, 10
	SSD1306_Puts("RC_controler ", &Font_7x10, 1); // print Hello
	SSD1306_GotoXY(10, 22);
	SSD1306_Puts("by D.Wawerek", &Font_7x10, 1);
	SSD1306_GotoXY(10, 34);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);

	SSD1306_DrawRectangle(0, 0, 128, 64, 1); // nice border of a OLED
	SSD1306_UpdateScreen(); // update screen
	HAL_Delay(1e3);
	SSD1306_Clear();
	SSD1306_UpdateScreen();

}

void oledDrawValueBars(uint16_t value1, uint16_t value2, uint16_t value3,
		uint16_t value4, uint8_t start_number) {
	// konwersja na wartosci z zakresu od 0 do 100;
	uint8_t divider = 9;

	uint8_t value1_u8 = (value1 - 1000) / divider;
	uint8_t value2_u8 = (value2 - 1000) / divider;
	uint8_t value3_u8 = (value3 - 1000) / divider;
	uint8_t value4_u8 = (value4 - 1000) / divider;
	//SSD1306_Clear();

	char buffor_string[15];
	SSD1306_Fill(0);
	//Clear screen but no upadte

//	sprintf(buffor_string, "%1d", start_number);
	//Draws 4 bars representing given values on screen. There is no clear function to avoid screen flushing(???)
	// As for now position of bars is chosed exprerimetnaly
	//1. BAR
	SSD1306_GotoXY(3, 5); // goto 10, 10
	sprintf(buffor_string, "%1d: ", start_number++);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	SSD1306_DrawFilledRectangle(15, 5, value1_u8, 8, 1); // draw rectangle and complemnetray one


	//2. BAR
	SSD1306_GotoXY(3, 20); // goto 10, 10
	sprintf(buffor_string, "%1d: ", start_number++);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	SSD1306_DrawFilledRectangle(15, 20, value2_u8, 8, 1);


	//3. BAR
	SSD1306_GotoXY(3, 34); // goto 10, 10
	sprintf(buffor_string, "%1d: ", start_number++);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	SSD1306_DrawFilledRectangle(15, 34, value3_u8, 8, 1);


	//4. BAR
	SSD1306_GotoXY(3, 48); // goto 10, 10
	sprintf(buffor_string, "%1d: ", start_number++);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	SSD1306_DrawFilledRectangle(15, 48, value4_u8, 8, 1);


	SSD1306_DrawRectangle(0, 0, 128, 64, 1); // nice border of a OLED
	SSD1306_UpdateScreen(); // update screen

}

void oledPrintEncValues(uint8_t rotation_value, uint8_t push_value) {
	//Clear function
//	SSD1306_Clear();
	SSD1306_Fill(0);
	char buffor_string[25];

	sprintf(buffor_string, "ROTATION: %2d", rotation_value);
	SSD1306_GotoXY(10, 10); // goto 10, 10
	SSD1306_Puts(buffor_string, &Font_7x10, 1);

	sprintf(buffor_string, "PUSHES : %2d", push_value);
	SSD1306_GotoXY(10, 22);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);

	SSD1306_DrawRectangle(0, 0, 128, 64, 1); // nice border of a OLED
	SSD1306_UpdateScreen(); // update screen
}

void oledPrintMainScreen(RC_Controler_Status *rc_status) {
	//Clear function
//	SSD1306_Clear();
	SSD1306_Fill(0);
	char buffor_string[25];
	//1. Line of text
	sprintf(buffor_string, "FRM_SENT: %5ld", rc_status->frames_sent);
	SSD1306_GotoXY(10, 10); // goto 10, 10
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	//2. Line of text
	sprintf(buffor_string, "IMU_STAT: %2d", rc_status->mpu_init_succes);
	SSD1306_GotoXY(10, 22);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	//3. Line of text
	sprintf(buffor_string, "RCV_STAT: %2d", rc_status->rc_recvier_found);
	SSD1306_GotoXY(10, 34);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);

	//4. Line of text

	sprintf(buffor_string, "ACK_RECV: %2d", rc_status->acks_recived);
	SSD1306_GotoXY(10, 46);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);

	SSD1306_DrawRectangle(0, 0, 128, 64, 1); // nice border of a OLED
	SSD1306_UpdateScreen(); // update screen
}

void oledPrintCalibScreen(uint8_t channel_number, uint16_t actual_value ,uint16_t time_to_end,
		uint16_t min, uint16_t max) {

	SSD1306_Fill(0);
	char buffor_string[25];
	//1. Line of text //Maybe fancy animation
	sprintf(buffor_string, "Calib chn %2d", channel_number);
	SSD1306_GotoXY(10, 10); // goto 10, 10
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	//2. Line of text
	sprintf(buffor_string, "time[ms]:%4d", time_to_end);
	SSD1306_GotoXY(10, 22);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);
	//3. Line of text
	sprintf(buffor_string, "min:%2d max:%4d", min,max);
	SSD1306_GotoXY(10, 34);
	SSD1306_Puts(buffor_string, &Font_7x10, 1);

	SSD1306_DrawFilledRectangle(15, 48, actual_value/32, 6, 1);




	SSD1306_DrawRectangle(0, 0, 128, 64, 1); // nice border of a OLED
	SSD1306_UpdateScreen(); // update screen
}
