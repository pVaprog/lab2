#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "/home/ubuntu/lab2/mysyslog/libmysyslog/libmysyslog.h"

void print_usage() {
    printf("Usage: mysyslog-client -m <message> -l <level> -d <driver> -f <format> -p <path>\n");
    printf("Options:\n");
    printf("  -m, --message <message>     Log message to be sent\n");
    printf("  -l, --level <level>         Log level (e.g., info, warning, error)\n");
    printf("  -d, --driver <driver>       Log driver (e.g., console, file)\n");
    printf("  -f, --format <format>       Log format (e.g., text, json)\n");
    printf("  -p, --path <path>           Path to log file\n");
    printf("  -h, --help                  Show this help message\n");
}

int main(int argc, char *argv[]) {
    char *message = NULL;
    char *level = NULL;
    char *driver = NULL;
    char *format = NULL;
    char *path = NULL;

    int  init_mysyslog(char* driver, const char* path);
    int log_message(int level, const char* message, char* format);
    
    int opt;
    static struct option long_options[] = {
        {"message", required_argument, 0, 'm'},
        {"level", required_argument, 0, 'l'},
        {"driver", required_argument, 0, 'd'},
        {"format", required_argument, 0, 'f'},
        {"path", required_argument, 0, 'p'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "m:l:d:f:p:h", long_options, NULL)) != -1) {
        switch (opt) {
            case 'm':
                message = optarg;
                break;
            case 'l':
                level = optarg;
                break;
            case 'd':
                driver = optarg;
                break;
            case 'f':
                format = optarg;
                break;
            case 'p':
                path = optarg;
                break;
            case 'h':
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    if (!message || !level || !driver || !format || (strcmp(driver, "file") == 0 && !path)) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    // Инициализация библиотеки
    if (init_mysyslog(driver, path) != 0) {
        fprintf(stderr, "Failed to initialize mysyslog with driver: %s\n", driver);
        exit(EXIT_FAILURE);
    }

    // Определение уровня журнала
    int log_level;
    if (strcmp(level, "info") == 0) {
        log_level = INFO;
    } else if (strcmp(level, "warning") == 0) {
        log_level = WARN;
    } else if (strcmp(level, "error") == 0) {
        log_level = ERROR;
    } else {
        fprintf(stderr, "Invalid log level: %s\n", level);
        exit(EXIT_FAILURE);
    }

    // Запись сообщения в журнал
    if (log_message(log_level, message, format) != 0) {
        fprintf(stderr, "Failed to log message: %s\n", message);
        exit(EXIT_FAILURE);
    }

    // Завершение работы
    close_mysyslog();
    return 0;
}

