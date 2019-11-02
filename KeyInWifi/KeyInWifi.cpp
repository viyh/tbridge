#include "KeyInWifi.hpp"

#define DELAY_CHOICE 1000
#define DELAY_STEP 2000

KeyInWifi::KeyInWifi(SSD1306Wire& display, int btnPin, ButtonMode btnMode) :
    m_debug(nullptr), m_u8x8(display), m_btnPin(btnPin), m_btnMode(btnMode) {
    m_u8x8.clear();
    m_u8x8.setTextAlignment(TEXT_ALIGN_LEFT);
    m_u8x8.setFont(ArialMT_Plain_10);
}

void KeyInWifi::enableDebug(Print& debug) {
    m_debug = &debug;
}

void KeyInWifi::display_string(int x, int y, String msg) {
    m_u8x8.drawString(x*10, y*10, msg);
    m_u8x8.display();
}

#define DEBUGF(fmt, ...) do { if (m_debug != nullptr) { m_debug->printf_P(PSTR("%d [KeyInWifi] " fmt "\n"), millis(), ##__VA_ARGS__); } } while (false)

bool KeyInWifi::execute() {
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    switch (m_btnMode) {
        case ButtonMode::NORMAL_LOW:
            pinMode(m_btnPin, INPUT_PULLDOWN);
            break;
        case ButtonMode::NORMAL_HIGH:
            pinMode(m_btnPin, INPUT_PULLUP);
            break;
    }

    int nNetworks = WiFi.scanNetworks();
    nNetworks = std::min(nNetworks, static_cast<int>(m_u8x8.getHeight()));
    std::vector<String> ssids;
    ssids.resize(nNetworks);
    std::vector<const char*> cssids;
    cssids.resize(nNetworks);
    for (int i = 0; i < nNetworks; ++i) {
        ssids[i] = WiFi.SSID(i);
        cssids[i] = ssids[i].c_str();
    }
    WiFi.scanDelete();
    int ssidIndex = this->promptMenu(cssids.data(), nNetworks);
    String ssid = ssids[ssidIndex];
    ssids.clear();
    cssids.clear();

    m_u8x8.clear();
    display_string(0, 0, "SSID is");
    display_string(0, 1, ssid.c_str());
    display_string(0, 2, "Enter password");
    delay(DELAY_STEP);
    String password = this->promptString();

    m_u8x8.clear();
    display_string(0, 0, "Connecting to");
    display_string(0, 1, ssid.c_str());
    display_string(0, 2, "using password");
    display_string(0, 3, password.c_str());
    display_string(0, 4, "status=");

    WiFi.begin(ssid.c_str(), password.c_str());
    while (!WiFi.isConnected()) {
        display_string(8, 4, "0" + WiFi.status());
    }
    display_string(0, 4, "IP=");
    display_string(4, 4, WiFi.localIP().toString().c_str());
    return true;
}

void KeyInWifi::draw_wifi_menu(char const* const* choices, int nChoices) {
    m_u8x8.clear();
    for (int i = 0; i < nChoices; ++i) {
        console_log("promptMenu - draw " + (String)choices[i]);
        display_string(1, i, choices[i]);
    }
}

int KeyInWifi::promptMenu(char const* const* choices, int nChoices) {
    assert(nChoices > 0);
    assert(nChoices <= m_u8x8.getHeight());

    // delay to allow button depress
    delay(1000);

    while (true) {
        for (int i = 0; i < nChoices; ++i) {
            console_log("promptMenu - while for " + (String)i + " " + (String)nChoices);
            draw_wifi_menu(choices, nChoices);
            display_string(0, (i - 1 + nChoices) % nChoices, " ");
            display_string(0, i, ">");
            for (int t = 0; t < DELAY_CHOICE; ++t) {
                if (digitalRead(m_btnPin) != static_cast<int>(m_btnMode)) {
                    return i;
                }
                delay(1);
            }
        }
    }
}

String KeyInWifi::promptString() {
    String s;
    while (true) {
        char const* const choices[] = {
            s.c_str(),
            "<-",
            "0123456789 +._-",
            "ABCDEFGHIJKLM",
            "NOPQRSTUVWXYZ",
            "abcdefghijklm",
            "nopqrstuvwxyz",
            "~!@#$%^&*()",
        };
        int choice = this->promptMenu(choices, 8);
        switch (choice) {
            case 0:
                return s;
            case 1:
                s.remove(s.length() - 1);
            case 2:
                s += this->promptChar("0123456789 +._-");
                break;
            case 3:
                s += this->promptChar("ABCDEFGHIJKLM");
                break;
            case 4:
                s += this->promptChar("NOPQRSTUVWXYZ");
                break;
            case 5:
                s += this->promptChar("abcdefghijklm");
                break;
            case 6:
                s += this->promptChar("nopqrstuvwxyz");
                break;
            case 7:
                s += this->promptChar("!\"#$%&'()*,/:;<=>?@[\\]^`{|}~");
                break;
        }
    }
}

void KeyInWifi::draw_char_menu(const char* chars, int nChars, int nRows) {
    m_u8x8.clear();
    for (int i = 0; i < nChars; ++i) {
        std::div_t xy = std::div(i, nRows);
        display_string(xy.quot * 2 + 1, xy.rem, (String)chars[i]);
    }
}

char KeyInWifi::promptChar(const char* chars) {
    int nChars = std::strlen(chars);
    int nRows = m_u8x8.getHeight() / 10;
    int nCols = m_u8x8.getWidth() / 10;
    assert(nChars <= nRows * nCols / 2);

    // delay to allow button depress
    delay(1000);

    while (true) {
        for (int i = 0; i < nChars; ++i) {
            draw_char_menu(chars, nChars, nRows);
            std::div_t xy = std::div((i - 1 + nChars) % nChars, nRows);
            display_string(xy.quot * 2, xy.rem, " ");
            xy = std::div(i, nRows);
            display_string(xy.quot * 2, xy.rem, ">");
            for (int t = 0; t < DELAY_CHOICE; ++t) {
                if (digitalRead(m_btnPin) != static_cast<int>(m_btnMode)) {
                    return chars[i];
                }
                delay(1);
            }
        }
    }
}

