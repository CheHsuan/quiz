#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "listnode.h"
#include "testdriver.h"

#define MAX_ARRAY_LENGTH 30

Node *detectCycle(Node *head)
{
    Node *slowPtr, *fastPtr, *crossNode;
    crossNode = NULL;
    slowPtr = head;
    fastPtr = head;
    while(slowPtr != NULL && fastPtr != NULL && fastPtr->pNext != NULL) {
        slowPtr = slowPtr->pNext;
        fastPtr = fastPtr->pNext->pNext;
        if(slowPtr == fastPtr) {
            crossNode = slowPtr;
            break;
        }
    }
    if(crossNode == NULL)
        return NULL;
    else {
        slowPtr = head;
        while(1) {
            if(slowPtr == fastPtr)
                return slowPtr;
            slowPtr = slowPtr->pNext;
            fastPtr = fastPtr->pNext;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *token;
    char *delim = " \t\n";
    char buffer[MAX_ARRAY_LENGTH];
    Node *e, *head, *cycleNode;
    struct timespec start, end;
    double cpu_time;

    head = initialize(head);
    e = head;

    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("can't not open the file\n");
        return -1;
    }

    // construct linked list
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        clock_gettime(CLOCK_REALTIME, &start);
        token = strtok(buffer, delim);
        while(token != NULL) {
            e = append(head, e, token);
            token = strtok(NULL, delim);
        }
        cycleNode = detectCycle(head->pNext);
        if(cycleNode != NULL)
            printf("cycle node : %s\n",cycleNode->nodeName);
        else
            printf("no cycle\n");
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time = diff_in_second(start, end);
        printf("Execution time : %lf sec\n",cpu_time);
        head = initialize(head);
        e = head;
    }

    fclose(fp);

    return 0;
}
