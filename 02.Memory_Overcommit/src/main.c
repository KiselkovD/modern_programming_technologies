#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHUNK_SIZE 4096			 // Размер блока в байтах
#define SLEEP_DURATION 10000 // Длительность сна в микросекундах

void allocate_memory(size_t total_size, int write_mode)
{
	size_t allocated = 0;																								 // Общее количество выделенной памяти
	char **buffers = malloc((total_size / CHUNK_SIZE) * sizeof(char *)); // Массив указателей на буферы

	if (buffers == NULL)
	{
		fprintf(stderr, "Memory allocation for buffer pointers failed\n");
		exit(EXIT_FAILURE);
	}

	while (allocated < total_size)
	{
		// Выделяем память для одного чанка
		buffers[allocated / CHUNK_SIZE] = malloc(CHUNK_SIZE);
		if (buffers[allocated / CHUNK_SIZE] == NULL)
		{
			fprintf(stderr, "Memory allocation failed at %zu bytes\n", allocated);
			break; // Прерываем цикл при неудачном выделении памяти
		}

		// Заполняем или читаем данные в зависимости от режима
		if (write_mode)
		{
			snprintf(buffers[allocated / CHUNK_SIZE], CHUNK_SIZE, "Writing to memory at offset %zu\n", allocated);
		}
		else
		{
			printf("%s", buffers[allocated / CHUNK_SIZE]); // Чтение из выделенной памяти
		}

		allocated += CHUNK_SIZE; // Увеличиваем общее количество выделенной памяти

		// Пауза после определённого количества обращений
		if ((allocated / CHUNK_SIZE) % 1000 == 0)
		{
			printf("MiB amount: %zu\n", allocated / (1024 * 1024)); // Вывод в МБ
			usleep(SLEEP_DURATION);																	// Сон на заданную длительность
		}
	}

	// Освобождение всей выделенной памяти после завершения работы
	for (size_t i = 0; i < allocated / CHUNK_SIZE; i++)
	{
		free(buffers[i]);
	}

	free(buffers); // Освобождаем массив указателей на буферы
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <size_in_MiB> <mode: read/write>\n", argv[0]);
		return EXIT_FAILURE;
	}

	size_t size = strtoul(argv[1], NULL, 10);
	if (size == 0)
	{
		fprintf(stderr, "Size must be greater than zero.\n");
		return EXIT_FAILURE;
	}

	char *mode = argv[2];
	int write_mode = (strcmp(mode, "write") == 0);

	if (!write_mode && strcmp(mode, "read") != 0)
	{
		fprintf(stderr, "Mode must be 'read' or 'write'.\n");
		return EXIT_FAILURE;
	}

	allocate_memory(size * 1024 * 1024, write_mode);

	return EXIT_SUCCESS;
}
