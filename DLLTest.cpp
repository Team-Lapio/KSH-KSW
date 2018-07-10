#include <stdio.h>
#include <stdlib.h>

struct Node{
    Node *next;
    Node *prev;
    int data = 0;
};
Node *head=(Node*)malloc(sizeof(Node));
// Node *tail=(Node*)malloc(sizeof(Node));

void NodeInint(){
    head->prev = NULL;
    head->next = NULL;
}

void AddFirst(struct Node *target, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = head->next;
    head->next = newNode;
}
void AddLast(struct Node *target, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *now;
    newNode->data = data;

    now = head;
    while(now->next)
        now = now->next;

    now->next = newNode;
    newNode->next = NULL;
}

void DelNode(Node *target,int val){
    Node *now;
    now = head->next;
    while(now->data != val && now != NULL){
        now=now->next;
    }

    if(now!=NULL){
        now->prev->next = now->next;
        now->next->prev = now->prev;
        free(now);
        return;
    }
}
/*
void DeletNode(struct Node *target,int val){
    Node *now, *tmp;
    now = head;
    while(now->next){
        if(now->data == val){
            tmp = now->prev;
            now->prev = now->next;
            now->next = tmp;
            free(now);   
        }
        now = now->next;
    }
}
*/
int main(){
    NodeInint();
    AddFirst(head,10);
    AddFirst(head,20);
    AddLast(head,40);
    Node *curr = head->next;
    int in = 0;
    while(curr != NULL){
        printf("%d\n",curr->data);
        curr = curr->next;      
    }

    
    fputs("삭제할 노드의 DATA 입력: ",stdout);
    scanf(" %d",&in);
    printf("input: %d\n",in);
    DelNode(head,in);
    
    curr = head->next;    
    while(curr != NULL){
        printf("%d\n",curr->data);
        curr = curr->next;      
    }
    curr = head->next;   
    while(curr!=NULL){
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(head);
    return 0;
}
