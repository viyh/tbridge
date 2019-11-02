//
// Modified by Joe Richards on 2019-11-02
//
// Originally created by John Beeler on 5/12/18.
//

#ifndef TILTBRIDGE_TILTSCANNER_H
#define TILTBRIDGE_TILTSCANNER_H

#include "tiltHydrometer.h"
#include "log.h"
#include <stdint.h>
#include <json11/json11.hpp>

using json = json11::Json;

#ifndef BLE_SCAN_TIME
#define BLE_SCAN_TIME       5  // Seconds to scan
#endif

class tiltScanner {
public:
    tiltScanner();
    void init();
    bool scan();

    bool wait_until_scan_complete();
    void set_scan_active_flag(bool value);
    uint8_t load_tilt_from_advert_hex(std::string advert_string_hex);
    json::object tilt_to_json();
    tiltHydrometer* tilt(uint8_t color);

private:
    bool m_scan_active;
    tiltHydrometer* m_tilt_devices[TILT_COLORS];
};

extern tiltScanner tilt_scanner;

#endif //TILTBRIDGE_TILTSCANNER_H
