#ifndef bst_H
#define bst_H

typedef struct data{
	int value;
}Data;

typedef struct node{
	Data data;
	struct node * left;
	struct node * right;
	struct node * parent;
}Node;

typedef struct tree{
	Node * root;
}Tree;

Data * insertNode(Node *, Data);
Data * searchNode(Node *, Data);
void sortNode(Node *, Data *,int *);
Tree * clone(Tree *);
Node * cloneTree(Node *,Node *);
int compare(Tree*, Tree*);
int compareNode(Node *, Node *);
void removeLeaf(Tree *, Node *);
void shortCircuit(Tree *, Node *);
void promotion(Tree *, Node *);
Node * searchMin(Node *);
Node * deleteLeaf(Node *);
Node * createNode(Data d, Node * parent);
Tree * createTree();
Data * insert(Tree *, Data);
Data * search(Tree * bst, Data value);
void deleteTree(Tree * bst);
void removeData(Tree * bst, Data value);
void sort(Tree *, Data *);
#endif
