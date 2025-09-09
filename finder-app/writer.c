/*
 * File: writer.c
 * Author: Hasan
 * Date: 2025-09-09
 * Description: Writes a string to a file and logs actions using syslog.
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>


/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char *argv[]) {
    // Open syslog for this program with LOG_USER facility
    openlog("writer", LOG_PID, LOG_USER);

    // Check for correct number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <writefile> <writestr>", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr  = argv[2];

    // Try opening the file for writing
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error: Could not open file %s", writefile);
        closelog();
        return 1;
    }

    // Write string into the file
    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error: Failed to write to %s", writefile);
        fclose(fp);
        closelog();
        return 1;
    }

    fclose(fp);

    // Log a debug message
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Close syslog
    closelog();

    return 0;
}
