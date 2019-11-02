//
// Created by John Beeler on 4/28/18.
//

#include "tiltHydrometer.h"


tiltHydrometer::tiltHydrometer(uint8_t color) {
    m_loaded            = false;
    m_color             = color;
    temp                = 0;
    gravity             = 0;
} // tiltHydrometer




uint8_t tiltHydrometer::uuid_to_color_no(std::string uuid) {
    if(uuid == TILT_COLOR_RED_UUID) {
        return TILT_COLOR_RED;
    } else if(uuid == TILT_COLOR_GREEN_UUID) {
        return TILT_COLOR_GREEN;
    } else if(uuid == TILT_COLOR_BLACK_UUID) {
        return TILT_COLOR_BLACK;
    } else if(uuid == TILT_COLOR_PURPLE_UUID) {
        return TILT_COLOR_PURPLE;
    } else if(uuid == TILT_COLOR_ORANGE_UUID) {
        return TILT_COLOR_ORANGE;
    } else if(uuid == TILT_COLOR_BLUE_UUID) {
        return TILT_COLOR_BLUE;
    } else if(uuid == TILT_COLOR_YELLOW_UUID) {
        return TILT_COLOR_YELLOW;
    } else if(uuid == TILT_COLOR_PINK_UUID) {
        return TILT_COLOR_PINK;
    } else {
        return TILT_NONE;
    }
}


std::string tiltHydrometer::color_name() {
    switch(m_color) {
        case TILT_COLOR_RED:
            return "Red";
        case TILT_COLOR_GREEN:
            return "Green";
        case TILT_COLOR_BLACK:
            return "Black";
        case TILT_COLOR_PURPLE:
            return "Purple";
        case TILT_COLOR_ORANGE:
            return "Orange";
        case TILT_COLOR_BLUE:
            return "Blue";
        case TILT_COLOR_YELLOW:
            return "Yellow";
        case TILT_COLOR_PINK:
            return "Pink";
        default:
            return "None";
    }
}


bool tiltHydrometer::set_values(uint32_t i_temp, uint32_t i_grav){
    temp = i_temp;
    gravity = i_grav;
    m_loaded = true;  // Setting loaded true now that we have gravity/temp values
    return true;
}

std::string tiltHydrometer::converted_gravity() {
    // I guarantee there is a better way of doing this conversion, but this works. SG is always 0.000-9.999.
    int right_of_decimal = gravity % 1000;
    int left_of_decimal = (gravity - right_of_decimal)/1000;

    std::string output = std::to_string(left_of_decimal) + ".";

    if(right_of_decimal < 100)
        output += "0";
    if(right_of_decimal < 10)
        output += "0";
    output += std::to_string(right_of_decimal);

    return output;
}

nlohmann::json tiltHydrometer::to_json() {
    nlohmann::json j;
    j = {
            {"color", color_name()},
            {"temp", temp},
            {"gravity", converted_gravity()},
    };
    return j;
}

uint8_t tiltHydrometer::get_color_number() {
    return m_color;
}

bool tiltHydrometer::is_loaded() {
    return m_loaded;
}
