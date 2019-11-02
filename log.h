#ifndef log_h
#define log_h

#include <chrono>
#include <ctime>
#include <Arduino.h>

extern String pretty_time();
extern void console_log(String msg);
extern void set_clock();

// strftime format
#define LOGGER_PRETTY_TIME_FORMAT "%Y-%m-%d %H:%M:%S"

// printf format
#define LOGGER_PRETTY_MS_FORMAT ".%03d"

#endif
