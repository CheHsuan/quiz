#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "listnode.h"
#include "testdriver.h"

#define MAX_ARRAY_LENGTH 30

Node *recursive(Node *slow, Node *fast)
{
    if(slow == fast)
        return fast;
    else if(slow == NULL || fast == NULL)
        return NULL;
    else if(fast->pNext != NULL) {
        return recursive(slow->pNext,fast->pNext->pNext);
    }
    return NULL;
}

Node *detectCycle(Node *head)
{
    Node *fast;
    if((fast = recursive(head->pNext,head->pNext->pNext)) != NULL) {
        Node *slow = head;
        while(1) {
            if(slow == fast)
                return slow;
            slow = slow->pNext;
            fast = fast->pNext;
        }
    } else
        return NULL;
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
            printf("cycle node : %s\n",detectCycle(head->pNext)->nodeName);
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
