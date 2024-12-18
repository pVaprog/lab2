#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H

#include "log_levels.h"
#include "log_formats.h"

int mysyslog(const char* msg, int level, int driver, int format, const char* path);

#endif // LIBMYSYSLOG_H
