#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// Waveshare ESP32-S3 Touch LCD 3.5B
// Display: 3.5" 320x480 SPI (AXS15231B capacitive touch)
// PMU: AXP2101, IMU: QMI8658, RTC: PCF85063, Audio: ES8311
// IO Expander: TCA9554, Flash: 16MB, PSRAM: 8MB

static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t TXD2 = 17;
static const uint8_t RXD2 = 18;

// System I2C bus (PMU AXP2101, IMU QMI8658, RTC PCF85063, IO Exp TCA9554, Audio ES8311)
static const uint8_t SDA = 8;
static const uint8_t SCL = 7;

// SPI pins (shared LCD + SD)
static const uint8_t SS   = 38;
static const uint8_t MOSI = 2;
static const uint8_t MISO = 42;
static const uint8_t SCK  = 1;

// GPIOs available on header
static const uint8_t G18 = 18;
static const uint8_t G19 = 19;
static const uint8_t G21 = 21;
static const uint8_t G33 = 33;
static const uint8_t G34 = 34;
static const uint8_t G35 = 35;
static const uint8_t G36 = 36;
static const uint8_t G37 = 37;
static const uint8_t G38 = 38;
static const uint8_t G39 = 39;
static const uint8_t G45 = 45;
static const uint8_t G46 = 46;
static const uint8_t G47 = 47;
static const uint8_t G48 = 48;

// ============ DISPLAY ============
#define HAS_SCREEN 1
#define ROTATION 0
#define BACKLIGHT 6
#define MINBRIGHT 80

// TFT_eSPI Setup - ILI9488 driver, 320x480 SPI
#define USER_SETUP_LOADED 1
#define ILI9488_DRIVER 1
#define TFT_RGB_ORDER 1
#define TFT_WIDTH  320
#define TFT_HEIGHT 480

#define TFT_MOSI 2
#define TFT_MISO 42
#define TFT_SCLK 1
#define TFT_CS   39
#define TFT_DC   41
#define TFT_RST  40
#define TFT_BL   6

#define USE_HSPI_PORT 1
#define TFT_BACKLIGHT_ON HIGH
#define SMOOTH_FONT 1
#define SPI_FREQUENCY  40000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

// ============ TOUCH ============
#define HAS_TOUCH 1
#define HAS_CAPACITIVE_TOUCH 1
#define TOUCH_GT911_I2C 1
#define BOARD_TOUCH_INT 17
#define BOARD_TOUCH_RST 16
#define SYS_I2C_SDA 15
#define SYS_I2C_SCL 7

// ============ SD CARD ============
#define SDCARD_CS   38
#define SDCARD_SCK  1
#define SDCARD_MISO 42
#define SDCARD_MOSI 2

// ============ PMU ============
#define HAS_PMU 1
#define CONFIG_PMU_SDA 8
#define CONFIG_PMU_SCL 7
#define CONFIG_PMU_IRQ 38

// ============ RTC ============
#define HAS_RTC 1
#define HAS_RTC_PCF85063A 1

// ============ AUDIO ============
#define BCLK 41
#define WCLK 42
#define DOUT 9

// ============ BUTTONS ============
#define HAS_BTN 0
#define BTN_ALIAS "\"Ok\""
#define BTN_PIN 0
#define BTN_ACT LOW

// ============ IR / RF ============
#define IR_TX_PINS '{{"Pin 21", 21}, {"Pin 45", 45}, {"Pin 46", 46}}'
#define IR_RX_PINS '{{"Pin 21", 21}, {"Pin 45", 45}, {"Pin 46", 46}}'
#define TXLED 21
#define LED_ON HIGH
#define LED_OFF LOW

#define RF_TX_PINS '{{"Pin 21", 21}, {"Pin 45", 45}, {"Pin 46", 46}}'
#define RF_RX_PINS '{{"Pin 21", 21}, {"Pin 45", 45}, {"Pin 46", 46}}'

// CC1101 SPI
#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN 21
#define CC1101_SS_PIN 45
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// NRF24 SPI
#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 21
#define NRF24_SS_PIN 45
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// W5500 SPI
#define USE_W5500_VIA_SPI
#define W5500_SS_PIN 45
#define W5500_MOSI_PIN SPI_MOSI_PIN
#define W5500_SCK_PIN SPI_SCK_PIN
#define W5500_MISO_PIN SPI_MISO_PIN
#define W5500_INT_PIN 46

// ============ MISC ============
#define USB_as_HID

// Font sizes
#define FP 1
#define FM 2
#define FG 3

// Default I2C port (grove / expansion)
#define GROVE_SDA 21
#define GROVE_SCL 45

#define SPI_SCK_PIN  1
#define SPI_MOSI_PIN 2
#define SPI_MISO_PIN 42
#define SPI_SS_PIN   38

// Microphone (not populated by default)
#define PIN_CLK -1
#define I2S_SCLK_PIN -1
#define I2S_DATA_PIN -1
#define PIN_DATA -1

// RGB LED (not present)
#define RGB_LED -1

// Speaker
#define HAS_NS4168_SPKR 1

// Serial/GPS
#define SERIAL_TX 43
#define SERIAL_RX 44
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

#endif /* Pins_Arduino_h */
