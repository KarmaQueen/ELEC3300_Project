/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LEDM_H
#define __LEDM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#define COLUMN_BIT_LENGTH   32
#define DATA_BIT_LENGTH     24
#define ROW_COUNT           8

static u8 disp_blank[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static u8 nums[10][5] = {
  { 
    0x40, //0
    0xA0,
    0xA0,
    0xA0,
    0x40},
  {
    0x40, //1
    0xC0,
    0x40,
    0x40,
    0x40},
  {
    0xC0, //2
    0x20,
    0x40,
    0x80,
    0xE0},
  {  
    0xC0, //3
    0x20,
    0xC0,
    0x20,
    0xC0},
  {
    0xA0, //4
    0xA0,
    0xE0,
    0x20,
    0x20},
  {
    0xE0, //5
    0x80,
    0xC0,
    0x20,
    0xC0},
  {
    0x62, //6
    0x80,
    0xC0,
    0xA0,
    0x40},
  {
    0xE0, //7
    0xA0,
    0x20,
    0x40,
    0x40},
  {
    0x40, //8
    0xA0,
    0x40,
    0xA0,
    0x40},
  {
    0x40, //9
    0xA0,
    0x62,
    0x20,
    0xC0
  }
};

static u8 icons[][3][8] = {
  {//0 Facebook Like
    {//R
      0x04,
      0x0C,
      0x1F,
      0x1F,
      0x1F,
      0x1F,
      0x0E,
      0x00
    },
    {//G
      0x04,
      0x0C,
      0x1F,
      0x1F,
      0x1F,
      0x1F,
      0x0E,
      0x00
    },
    {//B
      0x04,
      0x0C,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0x0E,
      0x00
    }
  },
  {//1 Facebook Icon
    {//R
      0x00,
      0x00,
      0x0E,
      0x1E,
      0x18,
      0x3E,
      0x3E,
      0x18
    },
    {//G
      0x00,
      0x00,
      0x0E,
      0x1E,
      0x18,
      0x3E,
      0x3E,
      0x18
    },
    {//B
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF
    }
  },
  {//2 Whatsapp
    {//R
      0x3C,
      0x42,
      0xB1,
      0xA1,
      0xB5,
      0x9D,
      0x82,
      0xFC
    },
    {//G
      0x3C,
      0x7E,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFC
    },
    {//B
      0x3C,
      0x42,
      0xB1,
      0xA1,
      0xB5,
      0x9D,
      0x82,
      0xFC
    }
  },
  {//3 Gmail
    {//R
      0x00,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0x00
    },
    {//G
      0x00,
      0x7E,
      0x3C,
      0x5A,
      0x66,
      0x7E,
      0x7E,
      0x00
    },
    {//B
      0x00,
      0x7E,
      0x3C,
      0x5A,
      0x66,
      0x7E,
      0x7E,
      0x00
    }
  },
  {//4 Heart
    {//R
      0x66,
      0xFF,
      0xFF,
      0xFF,
      0xFF,
      0x7E,
      0x3C,
      0x18
    },
    {//G
      0x00,
      0x02,
      0x02,
      0x04,
      0x00,
      0x00,
      0x00,
      0x00
    },
    {//B
      0x00,
      0x02,
      0x02,
      0x04,
      0x00,
      0x00,
      0x00,
      0x00
    }
  }
};

//static u32 led_buffer [8]; 
static u8 led_buffer [32];

static u8 disp_r[8];// = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static u8 disp_g[8];// = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static u8 disp_b[8];// = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static u8 mode = 0;

/*---- High-Layer Functions ----*/
void updateDisplay(void);
void setDisplayTime(u8 h1, u8 h2, u8 m1, u8 m2);
void clearDisplay(void);
void computeDisplay(void);
void setMode(u8 mode);
void setIcon(u8 icon);

/*---- Medium-Layer Functions ----*/
void copyNum(u8 *arr, u8 num, u8 x, u8 y);

/*---- Low-Layer Functions ----*/
void setLatchClkPin(u8 value);
void LEDM_Init(void);
void update_Buffer(void);
void TIM2_IRQHandler(void);
void LEDM_RTC_Configuration(void);



/* Minor Methods */
void LEDMdelay(void);

#endif /*__LEDM_H*/