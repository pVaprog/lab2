#include <stdio.h>
#include "/home/ubuntu/lab2/mysyslog/libmysyslog/libmysyslog.h"
#include "/home/ubuntu/lab2/mysyslog/libmysyslog/libmysyslog_text/libmysyslog_text.h"  // Подключите текстовый драйвер
#include "/home/ubuntu/lab2/mysyslog/libmysyslog/libmysyslog_json/libmysyslog_json.h"  // Подключите JSON-драйвер

int main() {
    const char* log_file_path = "log.txt"; // Путь к файлу для записи логов
    const char* process_name = "example-app";

    // Пример использования текстового драйвера
    log_text("this is an error", ERROR, process_name);

    // Пример использования JSON-драйвера
    log_json("this is an error", ERROR, process_name);

    return 0;
}
