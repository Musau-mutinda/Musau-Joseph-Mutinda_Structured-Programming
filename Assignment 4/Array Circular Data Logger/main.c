#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} CircularLogger;

void initLogger(CircularLogger *log) {
    log->head = 0;
    log->tail = 0;
    log->count = 0;
}

void insertSample(CircularLogger *log, int sample) {
    log->buffer[log->tail] = sample;
    log->tail = (log->tail + 1) % BUFFER_SIZE;

    if (log->count < BUFFER_SIZE) {
        log->count++;
    } else {
        log->head = (log->head + 1) % BUFFER_SIZE;
    }
}

void printChronological(const CircularLogger *log) {
    if (log->count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    printf("Stored samples (oldest -> newest): ");
    for (int k = 0; k < log->count; k++) {
        int idx = (log->head + k) % BUFFER_SIZE;
        printf("%d ", log->buffer[idx]);
    }
    printf("\n");
}
int main(void)
{
    CircularLogger logger;
    initLogger(&logger);

    int choice;
    while (1) {
        printf("\n--- Circular Data Logger (Buffer Size: %d) ---\n", BUFFER_SIZE);
        printf("1. Insert sensor sample\n");
        printf("2. Print samples (oldest to newest)\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        if (choice == 1) {
            int sample;
            printf("Enter sensor value: ");
            if (scanf("%d", &sample) == 1) {
                insertSample(&logger, sample);
                printf("Sample %d recorded.\n", sample);
            }
        } else if (choice == 2) {
            printChronological(&logger);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid option.\n");
        }
    }
    return 0;
}
