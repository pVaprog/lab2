#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H

#include "log_levels.h"
#include "log_formats.h"

int mysyslog(const char* msg, int level, int driver, int format, const char* path);
int init_mysyslog(char* driver, const char* path);
int log_message(int level, const char* message, char* format);
void close_mysyslog();

#endif // LIBMYSYSLOG_H
