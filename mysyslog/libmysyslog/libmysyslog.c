#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "log_levels.h"
#include "log_formats.h"

int mysyslog(const char* msg, int level, int driver, int format, const char* path) 
{
	FILE *file;

	// Открываем файл для записи
	if (path != NULL) 
	{
	    file = fopen(path, "a");
	    if (file == NULL) 
	    {
		 perror("Error opening log file");
		 return -1;
	    }
	}
	else 
	{
	    file = stdout; // Если путь не указан, выводим в стандартный вывод
	}

	// Получаем текущее время
	time_t now;
	time(&now);
	char* time_str = ctime(&now);
	time_str[strlen(time_str) - 1] = '\0'; // Удаляем символ новой строки

	// Форматируем сообщение в зависимости от формата
	if (format == TEXT) 
	{
	    fprintf(file, "[%s] [%d] %s\n", time_str, level, msg);
	} 
	else if (format == JSON) 
	{
	    fprintf(file, "{\"timestamp\": \"%s\", \"level\": %d, \"message\": \"%s\"}\n", time_str, level, msg);
	}

	// Закрываем файл, если он был открыт
	if (path != NULL) 
	{
	    fclose(file);
	}

	return 0; // Успешное завершение
}
