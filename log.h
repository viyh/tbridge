#ifndef log_h
#define log_h

#include <chrono>
#include <ctime>
#include <Arduino.h>

extern String pretty_time();
extern void console_log(String msg);
extern void set_clock();

#endif
