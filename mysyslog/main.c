#include <stdio.h>
#include "/home/ubuntu/lab2/mysyslog/libmysyslog/libmysyslog.h"

int main() {
const char* log_file_path = "log.txt"; // Путь к файлу для записи логов

	mysyslog("This is a debug message", DEBUG, 0, TEXT, log_file_path);
	mysyslog("This is an info message", INFO, 0, JSON, log_file_path);
	mysyslog("This is a warning message", WARN, 0, TEXT, log_file_path);
	mysyslog("This is an error message", ERROR, 0, JSON, log_file_path);
	mysyslog("This is a critical message", CRITICAL, 0, TEXT, log_file_path);

	return 0;
}
