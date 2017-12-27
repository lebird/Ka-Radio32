
#ifndef __have__addon_h__
#define __have__addon_h__


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include <u8g2.h>
#include "ucg.h"


// lcd_type
// min 128x64
#define LCD_COLOR		128	//0x80
#define LCD_SPI			64 //0x40
#define LCD_I2C			0
#define LCD_NONE		255

// Black&White
//I2C
#define LCD_I2C_SH1106		0 //128X64
#define LCD_I2C_SSD1306		1 //128X64
#define LCD_I2C_SSD1309		2 //128X64
#define LCD_I2C_SSD1325 	3 //128X64
#define LCD_I2C_SSD1306NN	4 //128X64
#define LCD_I2C_SSD1309NN	5 //128X64
//SPI
#define LCD_SPI_SSD1306 		64 //128X32 (LCD_SPI =0x40)
#define LCD_SPI_SSD1309 		65 //128X64
#define LCD_SPI_ST7565_ZOLEN	66 //128X64
#define LCD_SPI_SSD1322_NHD		67 //256X64
#define LCD_SPI_IL3820_V2		68 //296X128
#define LCD_SPI_SSD1607			69 //200X200
#define LCD_SPI_LS013B7DH03		70 //128X128
#define LCD_SPI_SSD1306NN 		71 //128X64
#define LCD_SPI_SSD1309NN 		72 //128X64

// Colors
#define LCD_SPI_ST7735			192 // 128x160  (LCD_COLOR|LCD_SPI =0xC0)
#define LCD_SPI_SSD1351			193 // 128x128
#define LCD_SPI_ILI9341			194 // 240x320
#define LCD_SPI_ILI9163			195 // 128x128
#define LCD_SPI_PCF8833			196 // 132x132
#define LCD_SPI_SSD1331			197 // 96x64
#define LCD_SPI_SEPS225			198 // 96x64

		

typedef struct {
    int channel;             /*!< event type */
    uint16_t addr;                /*!< nec addr */
    uint16_t cmd;                 /*!< nec cmdr */
	bool repeat_flag;
} event_ir_t;

typedef  enum typelcmd {lstop,lplay,lmeta,licy0,licy4,lnameset,lvol,lovol,evol,estation} typelcmd;
typedef struct {
    typelcmd lcmd;             /*!< For what ?*/
    char*  lline;              /*!< string of command */
} event_lcd_t;

#define MTNODISPLAY	0
#define MTNEW		1
#define MTREFRESH	2


extern xQueueHandle event_ir;
extern u8g2_t u8g2;
extern ucg_t ucg;
void task_addon(void *pvParams);
void lcd_init(uint8_t Type);
void (*serviceAddon)();
void addonParse(const char *fmt, ...);
void lcd_state(char* State);
void lcd_welcome(char* ip);
void setFuturNum(int16_t new);
int16_t getFuturNum();
void addonDt();
void wakeLcd();

#endif