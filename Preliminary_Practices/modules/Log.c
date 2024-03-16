#include <stdio.h>
#include <stdarg.h> // Required for va_list, va_start, va_end
#include <time.h>
#include <string.h>

void writeLog(const char *format, ...) {
    FILE *file = fopen("logfile.txt", "a"); // "a" for append mode, create the file if it doesn't exist
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Get current time
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format the time
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Write the timestamp to the file
    fprintf(file, "[%s] ", timestamp);

    // Use variable arguments to write formatted message to the file
    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    va_end(args);

    fprintf(file, "\n"); // Add a newline character at the end of the log message

    // Close the file
    fclose(file);
}
