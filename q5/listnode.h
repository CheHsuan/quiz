#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    char nodeName[10];
    struct ListNode *pNext;
} Node;

Node *append(Node *list, Node *tail, char *nodeName);
Node *runList(Node *list);
Node *initialize(Node *head);
