#include <stdio.h>
#include <time.h>
#include "libmysyslog_json.h"

void log_json(const char* msg, int level, const char* process) {
	time_t now;
	time(&now);
	printf("{\"timestamp\":%ld,\"log_level\":%d,\"process\":\"%s\",\"message\":\"%s\"}\n", now, level, process, msg);
}
