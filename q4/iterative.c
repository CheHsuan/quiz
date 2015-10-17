#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testdriver.h"

#define BUFFER_SIZE 200
#define MAX_ARRAY_LENGTH 100

int max(int a,int b)
{
    return (a>=b) ? a: b;
}

int maxSubArray(int array[], int n)
{
    int sum = 0;
    int maximum = array[0];
    for(int i = 0; i < n; i++) {
        sum += array[i];
        sum = max(0, sum);
        maximum = max(sum, maximum);
    }
    return maximum;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *token;
    char *delim = " \t\n";
    int array[MAX_ARRAY_LENGTH];
    char buffer[BUFFER_SIZE];
    int i = 0;
    struct timespec start, end;
    double cpu_time;

    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("can't not open the file\n");
        return -1;
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        token = strtok(buffer,delim);
        array[i++] = atoi(token);
        while((token = strtok(NULL,delim)) != NULL) {
            array[i++] = atoi(token);
        }
        clock_gettime(CLOCK_REALTIME, &start);
        printf("maximum : %d\n",maxSubArray(array, i));
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        printf("Execution time : %lf sec\n",cpu_time);
        i = 0;
    }

    fclose(fp);
    return 0;
}
