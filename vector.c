#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */
#include <string.h>

//Method to initialize Vector
Vector * initVector(){
	Vector* vector_v= (Vector*)malloc(sizeof (Vector));
	vector_v->data = NULL;
	vector_v->current_size = 0;
	vector_v->max_size = 0;
	vector_v->index_size = 0;
	vector_v->index_current = NULL;
	return vector_v;
}

//Method to insert new element into Vector
void vectorInsert(Vector * array, int index, Data value){
	if(array->max_size <= index){
		//Memory allocation for Data Array
		array->max_size = (index * 2) + 1;
		Data * new_array = malloc(sizeof(Data) * array->max_size);
		memset(new_array,-1,sizeof(Data)*array->max_size);
		memcpy(new_array,array->data,sizeof(Data)*array->current_size);
		free(array->data);
		array->data = NULL;
		array->data = new_array;
		//Extra Credit Part
		//Memory allocation for Index Array
                Index * new_index_array = malloc(sizeof(Index) * array->max_size);
                memset(new_index_array,-1,sizeof(Index)*array->max_size);
                memcpy(new_index_array,array->index_current,sizeof(Index)*array->index_size);
                free(array->index_current);
                array->index_current = NULL;
                array->index_current = new_index_array;
	}
        array->index_current[array->index_size].index_value = index;
	array->index_size  = array->index_size + 1;
	array->data[index] = value;
	if(index >= array->current_size){
		array->current_size = index + 1;
	}
}

//Method to read elements from Vector
Data * vectorRead(Vector * array, int index){
	Data *outboundtemp_array = NULL;
	int check = 0,i=0;
	if(index >= array->max_size){
		return NULL;
	}
	else{
		for(i = 0;i < array->index_size;i++){
			if(array->index_current[i].index_value == index){
				check = 1;
				break;
			}
		}
		if(check==1){
			return &array->data[index];
		}else{
			Data outbound_array = {-1};
			outboundtemp_array = &outbound_array;
			return outboundtemp_array;
		}
	}
}

//Method to remove elements from Vector done with index array for extra credit
void vectorRemove(Vector * array, int index){
	int maxvalue = -1,i=0,j=0;
	int offset = -1;
	if(index > array->current_size){
		return;
	}
	else{
		for(i = 0; i < array->index_size; i++){
                        if(index==array->index_current[i].index_value){
                                offset = i;
                                break; 
                        }       
                }       
                if(offset > -1){
                        for(j = offset;j < array->index_size-1;j++){
                                array->index_current[j].index_value = array->index_current[j+1].index_value;
                        }       
                        array->index_current[array->index_size].index_value = -1;
                        array->index_size--;
                }
	}
                array->current_size--;
}

//Method to free Struct memory
void * deleteVector(Vector *array){
	free(array->data);
	free(array->index_current);
	free(array);
	return NULL;
}

//Method to do Incremental expansion
void vectorInsertIncremental(Vector * array, int index, Data value){
        if(array->max_size <= index){
		//Memory initialised for data array
                array->max_size = index + 1;                                  
                Data * new_array = malloc(sizeof(Data) * array->max_size);          
                memset(new_array,-1,sizeof(Data)*array->max_size);                  
                memcpy(new_array,array->data,sizeof(Data)*array->current_size);     
                free(array->data);
                array->data = NULL;
                array->data = new_array;
                
		//Memory initialized for index array
                Index * new_index_array = malloc(sizeof(Index) * array->max_size);  
                memset(new_index_array,-1,sizeof(Index)*array->max_size);           
                memcpy(new_index_array,array->index_current,sizeof(Index)*array->index_size);        
                free(array->index_current);
                array->index_current = NULL;
                array->index_current = new_index_array;                             
        }
        array->index_current[array->index_size].index_value = index;                
        array->index_size  = array->index_size + 1;
        array->data[index] = value;                                                 
        if(index >= array->current_size){                                           
                array->current_size = index + 1;
        }

}

//Method to do my Algorithm for expansion
//when size exceeds, expansion happens by n+2
void vectorInsertMine(Vector * array, int index, Data value){
        if(array->max_size <= index){
		//Memory initialised for data array
                array->max_size = index + 2;                                  
                Data * new_array = malloc(sizeof(Data) * array->max_size);          
                memset(new_array,-1,sizeof(Data)*array->max_size);                  
                memcpy(new_array,array->data,sizeof(Data)*array->current_size);     
                free(array->data);
                array->data = NULL;
                array->data = new_array;
                
		//Memory initialised for index array
                Index * new_index_array = malloc(sizeof(Index) * array->max_size);  
                memset(new_index_array,-1,sizeof(Index)*array->max_size);           
                memcpy(new_index_array,array->index_current,sizeof(Index)*array->index_size);        
                free(array->index_current);
                array->index_current = NULL;
                array->index_current = new_index_array;                             
        }
        array->index_current[array->index_size].index_value = index;                
        array->index_size  = array->index_size + 1;
        array->data[index] = value;                                                 
        if(index >= array->current_size){                                           
                array->current_size = index + 1;
        }
}
