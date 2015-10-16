#include <stdio.h>
#include <string.h>
#include "testdriver.h"
#define MAX_ARRAY_LENGTH 30

char smallest_character(char str[], char c)
{
    int i = 0;
    while(str[i] != '\0') {
        if((str[i] - c) > 0)
            return str[i];
        i++;
    }
    return str[0];
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *token1, *token2;
    char *delim = " \t\n";
    char buffer[MAX_ARRAY_LENGTH];
    struct timespec start, end;
    double cpu_time;

    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("can't not open the file\n");
        return -1;
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        clock_gettime(CLOCK_REALTIME, &start);
        token1 = strtok(buffer,delim);
        token2 = strtok(NULL, delim);
        printf("%c\n",smallest_character(token1, *token2));
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        printf("Execution time : %lf sec\n",cpu_time);
    }

    fclose(fp);

    return 0;
}
