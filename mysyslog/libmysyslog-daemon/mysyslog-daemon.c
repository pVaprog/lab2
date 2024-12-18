#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

volatile sig_atomic_t keep_running = 1;

void handle_signal(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        keep_running = 0;
    }
}

void load_config(const char *config_path) {
    FILE *file = fopen(config_path, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("Config line: %s", line);
            // Обработка конфигурации
        }
        fclose(file);
    } else {
        syslog(LOG_ERR, "Could not open config file: %s", config_path);
    }
}

int main() {
    const char *config_path = "/etc/mysyslog/mysyslog.cfg";
    openlog("mysyslog-daemon", LOG_PID | LOG_CONS, LOG_USER);
    
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    
    load_config(config_path);

    syslog(LOG_INFO, "mysyslog-daemon started.");

    while (keep_running) {
        syslog(LOG_INFO, "Logging some info...");
        sleep(5); // Пауза между логами
    }

    syslog(LOG_INFO, "mysyslog-daemon stopped.");
    closelog();
    return 0;
}

