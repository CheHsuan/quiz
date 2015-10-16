#include "listnode.h"
#include <string.h>

Node *append(Node *list, Node *tail,char *nodeName)
{
    while(list != NULL) {
        if(strcmp(nodeName, list->nodeName) == 0) {
            tail->pNext = list;
            return tail;
        } else
            list = list->pNext;
    }
    tail->pNext = (Node*) malloc(sizeof(Node));
    tail = tail->pNext;
    strcpy(tail->nodeName, nodeName);
    tail->pNext = NULL;
    return tail;
}

Node *runList(Node *list)
{
    while(list != NULL) {
        printf("node : %s\n",list->nodeName);
        list = list->pNext;
    }
    return NULL;
}

Node *initialize(Node *head)
{
    head = (Node*) malloc(sizeof(Node));
    head->pNext = NULL;
    return head;
}
