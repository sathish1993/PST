#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
	int value;
}Data;

typedef struct heap{
	Data * data;
	int current_size;
	int maximum_capacity;
}Heap;

Heap * init();
Heap * initHeap(Data * );
void * heapify(Heap * );
void siftDown(Heap * , int );
Data removePriority(Heap * );

Heap *init(){
	Heap * newHeapObj = (Heap *)malloc(sizeof(Heap));
	newHeapObj->data = NULL;
	newHeapObj->current_size = 0;
	newHeapObj->maximum_capacity = 0; 
	return newHeapObj;
}

Heap *initHeap(Data * d){
	Heap * newHeap = init();
	newHeap->data = d;
	//newHeap->current_size++;
	//newHeap->maximum_capacity = 0;
	heapify(newHeap);
	printf("size now--->%d",newHeap->current_size);
	return newHeap;
}

void siftDown(Heap * h, int index){
	if ((index < 0) || (index >= h->current_size)){ 
		return;
	}
	while ((index-1)/2){
		int left = 2*index + 1; 
		int right = 2*index +2;
		int swap = left;
		int temp = 0;
		if(h->data[index].value < h->data[left].value && h->data[left].value < h->data[right].value){
			swap = right;
		}
		if(h->data[index].value < h->data[swap].value){
			return;
		}else{
			temp = h->data[index].value;
			h->data[index].value = h->data[swap].value;
			h->data[swap].value = temp;
		}
		index = swap;
	}
}

Data removePriority(Heap * h){
	if(h->current_size == 0){
		return;
	}
	Data priority = h->data[0];
	h->data[0] = h->data[h->current_size-1];
	h->data[h->current_size-1] = priority;
	h->current_size--;
	siftDown(h,0);
	printf("head value:%d\n",priority.value);
	return priority;
}

void *heapify(Heap *h){                                          
        int i = 0; 
        for(i = (h->current_size-2)/2 ; i >= 0 ; i--){
                siftDown(h,i);              
        }
}

int main(){
	int i = 0;
	Data test[1000];
	Data check[1000];
	Heap * heapObj = init();
	for(i=0;i<1000;i++){
		test[i].value = (rand()%1000) + 1;
		heapObj->current_size++;
	}
	heapObj = initHeap(test);
	printf("****8");
	/*for(i=0;i<1000;i++){
		printf("count:%d,value:%d\n",i,heapObj->data[i].value);
	}*/
	for(i=0;i<1000;i++){
		heapObj->data[i] = removePriority(heapObj);
	}
	printf("\nremove data\n");	
	//for(i=0;i<1000;i++){
//		printf("count:%d,value:%d\n",i,heapObj->data[i].value);
		/*if(check[i].value < check[i+1].value){
			printf("%d\t",i);
		}*/
//	}

}
