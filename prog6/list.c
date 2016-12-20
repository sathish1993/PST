#include"list.h"
#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Method to initialize List
List * createList(){
        List * newList = (List*) malloc(sizeof(List));
        newList->head = NULL;
        newList->tail = NULL;
        newList->length = 0;
        return newList;
}

//Method to insert new node into list
void insertData(List * list, int index, Data value){
        Node * newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(list->head == NULL){
                newNode->prev = list->tail;
                list->head = newNode;
                list->tail = newNode;
                list->length++;
        }else{
                newNode->prev = list->tail;
                list->tail->next = newNode;
                list->tail = newNode;
                list->length++;
        }
}

//Method to read list element at certain index
Data * readData(List * list, int index){
        int i = 0;
        Node * current = list->head;
        if(index > list->length){
                return NULL;
        }else{
                for(i=0;i<list->length;i++){
                        if(i == index){
                                return &current->data;
                        }else{
                                current = current->next;
                        }
		}
	}
}

//Method to remove node from list
int removeData(List * list, int index){
        int i = 0;
        Node * current = list->head;
        if(index > 1){
                for(i=1;i<list->length;i++){
                        if(i == index){
                                current->prev->next = current->next;
                                current->next->prev = current->prev;
                                free(current);
                                break;
                        }else{
                                current = current->next;
                        }
                }
        }else{
                if(current!= NULL){
                        list->head = current->next;
                        free(current);
                }

        }
        list->length--;
        if(list->length == 0){
                list->tail = NULL;
                list->head = NULL;
        }
        return 1;
}

//Method to traverse forward
int searchForward(List * list, Data value){
        int i = 0;
        Node * current = list->head;
        for(i=0;i<list->length;i++){
                if(current->data.value == value.value){
                        return i;
                }else{
                        current = current->next;
                }
        }
        return -1;
}

//Method to traverse backward
int searchBackward(List * list, Data value){
        int i = 0, foundAtIndex = -1;
        Node * current = list->tail;
        for(i=0;i<list->length;i++){
                if(current->data.value == value.value){
                        foundAtIndex = i;
                        break;
                }else{
                        current = current->prev;
                }
        }
        return foundAtIndex;
}

//Method to clear off allocated memory
void deleteList(List * list){
        Node * current = list->head;
        while(current!=NULL){
                Node * newCurrent = current->next;
                free(current);
                current = newCurrent;
        }
        free(list);
}

//Method to push elements into stack
void push(Stack * stack, Data value){
        Node * newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(stack->list->head == NULL){
                newNode->prev = stack->list->tail;
                stack->list->head = newNode;
                stack->list->tail = newNode;
                stack->length++;
        }else{
                newNode->prev = stack->list->tail;
                stack->list->tail->next = newNode;
                stack->list->tail = newNode;
                stack->length++;
        }
}

//Method to pop elements from stack
Data pop(Stack * stack){
        Node * current = stack->list->tail;
        Data data = current->data;
        if(stack->length > 1){
                stack->list->tail = current->prev;
                stack->list->tail->next = NULL;
                stack->length--;
                free(current);
        }else{
                stack->list->tail = current->prev;
                stack->list->head = NULL;
                stack->length--;
                free(current);
        }
        return data;
}


//Method to push element into queue
void enqueue(Queue * queue, Data value){
        Node * newNode = malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(queue->list->head == NULL){
                newNode->prev = queue->list->tail;
                queue->list->head = newNode;
                queue->list->tail = newNode;
                queue->length++;
        }else{
                newNode->prev = queue->list->tail;
                queue->list->tail->next = newNode;
                queue->list->tail = newNode;
                queue->length++;
        }
}

//Method to pop element from queue
Data dequeue(Queue * queue){
        Node * current = queue->list->head;
        Data data = current->data;
        if(queue->length > 1){
                queue->list->head = current->next;
                queue->list->head->prev = NULL;
                queue->length--;
                free(current);
        }else{
                queue->list->head = current->next;
                queue->list->tail = NULL;
                queue->length--;
                free(current);
        }
        return data;

}

//Method to check if list is empty or not
int isEmpty(List * list){
        if(list->length > 0){
                return 0;
        }
        return 1;
}

