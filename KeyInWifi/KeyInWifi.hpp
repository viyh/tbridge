#ifndef KEY_IN_WIFI_HPP
#define KEY_IN_WIFI_HPP

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <WiFi.h>
#include <WString.h>
#include <iostream>
#include <SSD1306Wire.h>
#include "log.h"

class String;
class Print;
// class SSD1306Wire;

class KeyInWifi {
public:
    enum class ButtonMode {
        NORMAL_LOW  = 0,
        NORMAL_HIGH = 1,
    };

    KeyInWifi(SSD1306Wire&, int btnPin, ButtonMode btnMode);
    void enableDebug(Print& debug);
    bool execute();

private:
    int promptMenu(char const* const* choices, int nChoices);
    String promptString();
    char promptChar(const char* chars);
    void display_string(int x, int y, String msg);
    void draw_wifi_menu(char const* const* choices, int nChoices);
    void draw_char_menu(const char* chars, int nChars, int nRows);

private:
    Print* m_debug;
    SSD1306Wire& m_u8x8;
    int m_btnPin;
    ButtonMode m_btnMode;
};

#endif // KEY_IN_WIFI_HPP
