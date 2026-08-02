#include "core/bus_HAL.h"
#include "core/powerSave.h"
#include "core/utils.h"
#include <Arduino.h>
#include <Wire.h>
#include <interface.h>

#if defined(HAS_CAPACITIVE_TOUCH) && defined(TOUCH_GT911_I2C)
#include "TouchDrvGT911.hpp"
TouchDrvGT911 touch;
struct TouchPointPro {
    int16_t x = 0;
    int16_t y = 0;
};
#endif

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the Waveshare ESP32-S3 Touch LCD 3.5B
***************************************************************************************/
void _setup_gpio() {
    // Touch I2C bus (Wire1: SDA=15, SCL=7)
    setSysI2CBus(&Wire1);
    bruceConfigPins.sys_i2c.sda = (gpio_num_t)SYS_I2C_SDA;
    bruceConfigPins.sys_i2c.scl = (gpio_num_t)SYS_I2C_SCL;

#if defined(HAS_CAPACITIVE_TOUCH) && defined(TOUCH_GT911_I2C)
    pinMode(BOARD_TOUCH_INT, INPUT);
    touch.setPins(BOARD_TOUCH_RST, BOARD_TOUCH_INT);
    if (!touch.begin(Wire1, GT911_SLAVE_ADDRESS_H, SYS_I2C_SDA, SYS_I2C_SCL)) {
        Serial.println("Touch AXS15231B not found, trying alt address...");
        if (!touch.begin(Wire1, GT911_SLAVE_ADDRESS_L, SYS_I2C_SDA, SYS_I2C_SCL)) {
            Serial.println("Touch AXS15231B FAILED to init!");
        }
    } else {
        Serial.println("Touch AXS15231B initialized OK");
    }
#endif

    bruceConfig.colorInverted = 0;
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup
***************************************************************************************/
void _post_setup_gpio() {}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() {
    // TODO: implement AXP2101 battery read via XPowersLib
    return 0;
}

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {
    static bool pwmInitialized = false;
    if (!pwmInitialized) {
        ledcSetup(0, 5000, 8);
        ledcAttachPin(TFT_BL, 0);
        pwmInitialized = true;
    }
    ledcWrite(0, brightval);
}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static unsigned long tm = 0;
    if (millis() - tm < 200 && !LongPress) return;

#if defined(HAS_CAPACITIVE_TOUCH) && defined(TOUCH_GT911_I2C)
    if (!trylockSysI2CBus()) return;
    touch.update();
    unlockSysI2CBus();

    if (touch.isPressed()) {
        tm = millis();
        TouchPointPro tp;
        tp.x = touch.getPointX();
        tp.y = touch.getPointY();

        int16_t rawX = tp.x;
        int16_t rawY = tp.y;

        if (bruceConfigPins.rotation == 0) {
            tp.x = rawY;
            tp.y = TFT_HEIGHT - rawX;
        } else if (bruceConfigPins.rotation == 1) {
            tp.x = rawX;
            tp.y = rawY;
        } else if (bruceConfigPins.rotation == 2) {
            tp.x = TFT_WIDTH - rawY;
            tp.y = rawX;
        } else if (bruceConfigPins.rotation == 3) {
            tp.x = TFT_WIDTH - rawX;
            tp.y = TFT_HEIGHT - rawY;
        }

        if (!wakeUpScreen()) AnyKeyPress = true;
        else return;

        touchPoint.x = tp.x;
        touchPoint.y = tp.y;
        touchPoint.pressed = true;
        touchHeatMap(touchPoint);
    }
#endif
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
**********************************************************************/
void powerOff() {
    esp_deep_sleep_start();
}

void goToDeepSleep() { esp_deep_sleep_start(); }

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
**********************************************************************/
void checkReboot() {}
