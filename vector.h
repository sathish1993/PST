#ifndef vector_H
#define vector_H

typedef struct data{
int value;
}Data;

typedef struct index_struct{
int index_value;
}Index;

typedef struct vector{
Data *data;
Index *index_current;
unsigned int index_size;
unsigned int current_size;
unsigned int max_size;
}Vector;

Vector * initVector();
void vectorInsert(Vector * array, int index, Data value);
void vectorInsertIncremental(Vector * array, int index, Data value);
void vectorInsertMine(Vector * array, int index, Data value);
Data * vectorRead(Vector * array, int index);
void vectorRemove(Vector * array, int index);
void * deleteVector(Vector *);


#endif

