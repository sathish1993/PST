#ifndef list_H
#define list_H

typedef struct data{
        int value;
}Data;

typedef struct node{
        Data data;
        struct node * next;
        struct node * prev;
}Node;

typedef struct list{
        Node *head;
        Node *tail;
        int length;
}List;

typedef struct stack{
        List *list;
        int length;
}Stack;

typedef struct queue{
        List *list;
        int length;
}Queue;

List * createList();
void insertData(List * , int , Data );
int removeData(List * , int );
Data * readData(List * , int );
int isEmpty(List *);
void deleteList(List * );
int searchForward(List *, Data);
int searchBackward(List *, Data);
void push(Stack *, Data);
Data pop(Stack *);
void enqueue(Queue *, Data);
Data dequeue(Queue *);

#endif
