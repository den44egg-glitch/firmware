#include "core/powerSave.h"
#include <interface.h>

/*********************************************************************
**  Function: _setup_gpio()
**  Waveshare ESP32-S3-Touch-LCD 3.5B GPIO setup
*********************************************************************/
void _setup_gpio() {
    // Display backlight
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    // Touch CS - deassert
    pinMode(TOUCH_CS, OUTPUT);
    digitalWrite(TOUCH_CS, HIGH);

    // SD CS - deassert  
    pinMode(SD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);
}

/*********************************************************************
**  Function: _post_setup_gpio()
**  Second stage GPIO setup
*********************************************************************/
void _post_setup_gpio() {}

/*********************************************************************
**  Function: getBattery()
**  Returns battery value 0-100
*********************************************************************/
int getBattery() { return 0; }

/*********************************************************************
**  Function: setBrightness()
**  Set brightness value
*********************************************************************/
void _setBrightness(uint8_t brightval) {
    // PWM backlight control
    if(TFT_BL >= 0) {
        ledcWrite(0, brightval);
    }
}

/*********************************************************************
**  Function: InputHandler
**  Handles touch and button inputs
*********************************************************************/
void InputHandler(void) {
    checkPowerSaveTime();
    PrevPress = false;
    NextPress = false;
    SelPress = false;
    AnyKeyPress = false;
    EscPress = false;

    // Touch input handled by TFT_eSPI touch driver
    // No physical buttons on this board
    if(AnyKeyPress) {
        long tmp = millis();
        while(millis() - tmp < 200) delay(1);
    }
}
