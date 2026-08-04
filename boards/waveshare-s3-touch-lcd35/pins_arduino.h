#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// UART
static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t TXD2 = 17;
static const uint8_t RXD2 = 18;

// I2C
static const uint8_t SDA = 6;
static const uint8_t SCL = 7;

// SPI (shared bus for display and touch)
static const uint8_t SS = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 13;
static const uint8_t SCK = 12;

// GPIO mapping
static const uint8_t G0 = 0;
static const uint8_t G1 = 1;
static const uint8_t G2 = 2;
static const uint8_t G3 = 3;
static const uint8_t G4 = 4;
static const uint8_t G5 = 5;
static const uint8_t G6 = 6;
static const uint8_t G7 = 7;
static const uint8_t G8 = 8;
static const uint8_t G9 = 9;
static const uint8_t G10 = 10;
static const uint8_t G11 = 11;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G14 = 14;
static const uint8_t G15 = 15;
static const uint8_t G39 = 39;
static const uint8_t G40 = 40;
static const uint8_t G41 = 41;
static const uint8_t G42 = 42;
static const uint8_t G43 = 43;
static const uint8_t G44 = 44;
static const uint8_t G46 = 46;
static const uint8_t G47 = 47;
static const uint8_t G48 = 48;

static const uint8_t ADC1 = 7;
static const uint8_t ADC2 = 8;

// Display ILI9488 pins
#define TFT_MOSI 11
#define TFT_MISO 13
#define TFT_SCLK 12
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  48
#define TFT_BL   2

// Touch XPT2046 pins
#define TOUCH_CS   3
#define TOUCH_IRQ  4
#define TOUCH_MOSI 11
#define TOUCH_MISO 13
#define TOUCH_SCLK 12

// SD Card pins
#define SD_MOSI 11
#define SD_MISO 13
#define SD_SCLK 12
#define SD_CS   14

// Bruce firmware specific defines
#define FM_RSTPIN 40
#define PIN_CLK 12
#define I2S_SCLK_PIN 12
#define I2S_DATA_PIN 46
#define PIN_DATA 46

#define RGB_LED -1

#define BCLK 41
#define WCLK 42
#define DOUT 46

#define BAD_TX SDA
#define BAD_RX SCL

#define HAS_BTN 0
#define BTN_ALIAS "\"Ok\""
#define BTN_PIN 0
#define BTN_ACT LOW

#define IR_TX_PINS '{{"IR LED", SDA}, {"Pin 1", 1}, {"Pin 2", 2}}'
#define IR_RX_PINS '{{"IR RX", SCL}, {"Pin 1", 1}, {"Pin 2", 2}}'
#define TXLED -1
#define LED_ON HIGH
#define LED_OFF LOW

#define RF_TX_PINS '{{"RF TX", SDA}, {"Pin 1", 1}, {"Pin 2", 2}}'
#define RF_RX_PINS '{{"RF RX", SCL}, {"Pin 1", 1}, {"Pin 2", 2}}'

#define CC1101_GDO0_PIN 1
#define CC1101_SS_PIN 10
#define CC1101_MOSI_PIN MOSI
#define CC1101_SCK_PIN SCK

#endif /* Pins_Arduino_h */
