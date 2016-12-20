#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>

Node * createNode(Data d, Node * parent){
	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = d;
}

Tree * createTree(){
	Tree * newTree = (Tree *) malloc(sizeof(Tree));
	newTree->root = NULL;
}

Data * insert(Tree * bst, Data value){
	if(bst->root==NULL){
		bst->root = createNode(value, bst->root);
		return &bst->root->data;
	}else{
		return insertNode(bst->root,value);
	}
}

Data * insertNode(Node * node, Data value){
	if(value.value < node->data.value){
		if(node->left == NULL){
			node->left = createNode(value, node);
			return &node->left->data;
		}else{
			return insertNode(node->left,value);
		}
	}else if(value.value > node->data.value){
		if(node->right == NULL){
			node->right = createNode(value, node);
			return &node->right->data;
		}else{
			return insertNode(node->right,value);
		}
	}else if(value.value == node->data.value){
		return NULL;
	}
}

Data * search(Tree * bst, Data value){
	if(bst->root == NULL){
		return NULL;
	}else{
		searchNode(bst->root,value);
	}	
}

Data * searchNode(Node * node, Data value){
	if(value.value == node->data.value){
		return &node->data;
	}else if(value.value < node->data.value){
		if(node->left == NULL){
			return NULL;
		}else{
			return searchNode(node->left,value);
		}
	}else if(value.value > node->data.value){
		if(node->right == NULL){
			return NULL;
		}
		else{
			return searchNode(node->right,value);
		}
	}
}

void sort(Tree * bst, Data * data_array){
	int index = 0;
	int * indexAddr = &index;
	if(bst->root != NULL){
		sortNode(bst->root,data_array,indexAddr);
	}
}

void sortNode(Node * node,Data * data_array,int *indexAddr){
	if(node == NULL){ 
		return;
	}else{
		sortNode(node->left,data_array,indexAddr);
		data_array[*indexAddr] = node->data;
		*indexAddr = *indexAddr + 1;
		sortNode(node->right,data_array,indexAddr);
	}
}

Tree * clone(Tree * bst){
	Tree *bstClone = NULL;
	if(bst->root!=NULL){
		bstClone = createTree();
		bstClone->root = cloneTree(bst->root,bstClone->root);
	}
	return bstClone;
}

Node * cloneTree(Node * node,Node * bstClone){
	if(node == NULL){
                return NULL;
        }else{
		bstClone = createNode((Data){1},NULL);
		memcpy(bstClone,node,sizeof(node));
		bstClone->left = cloneTree(node->left,bstClone->left);
                bstClone->right= cloneTree(node->right,bstClone->right);
		return bstClone;
        }

}

void deleteTree(Tree * bst){
	if(bst!=NULL){
		bst->root = deleteLeaf(bst->root);
		free(bst);
		bst = NULL;	
		
	}
}

Node * deleteLeaf(Node * node){
	if(node != NULL){
		node->left = deleteLeaf(node->left);
		node->right = deleteLeaf(node->right);
		free(node);
		node = NULL;
		return node;
	}
}

int compare(Tree * tree1, Tree * tree2){
	if(tree1 == NULL && tree2 == NULL){
		return 1;
	}else if(tree1 !=NULL && tree2 !=NULL){
		return compareNode(tree1->root, tree2->root);
	}else{
		return 0;
	}
}

int compareNode(Node * node1, Node * node2){
	if(node1 == NULL && node2 == NULL){
		return 1;
	} 
	if(node1 != NULL && node2 != NULL){
		if(node1->data.value == node2->data.value){
                	return (compareNode(node1->left, node2->left) && compareNode(node1->right, node2->right));
		}else{
		     return 0;
		}
	}else{
	 	return 0;
	}
}

void removeData(Tree * bst, Data value){
	Node * delNode = search(bst,value);
	if(delNode == NULL){
		return;
	}
	else{	
		if(delNode->data.value == bst->root->data.value){
			if(delNode->left == NULL && delNode->right == NULL){
				bst->root = NULL;
				free(delNode);
				delNode = NULL;
			}else if(delNode->left==NULL || delNode->right == NULL){
				shortCircuit(bst, delNode);
			}else{
				promotion(bst, delNode);
			}
			
		}
		else if(delNode->left == NULL && delNode->right == NULL){
			removeLeaf(bst, delNode);
		}
		else if(delNode->left == NULL || delNode->right == NULL){
			shortCircuit(bst, delNode);
		}else{
			promotion(bst, delNode);
		}
	}
}

void removeLeaf(Tree * bst, Node * d_node){
	if(d_node->parent->right == d_node){
		d_node->parent->right = NULL;
	}else{
		d_node->parent->left = NULL;
	}
	free(d_node);
	d_node = NULL;
}

void shortCircuit(Tree * bst, Node * d_node){
	if(d_node->parent != NULL){
		if(d_node->parent->right->data.value == d_node->data.value){
			if(d_node->right == NULL){
				d_node->parent->right = d_node->left;
				d_node->left->parent = d_node->parent;
			}else{
				d_node->parent->right = d_node->right;
				d_node->right->parent = d_node->parent;
			}
		}else{
			if(d_node->right==NULL){
				d_node->parent->left = d_node->left;
				d_node->left->parent = d_node->parent;
			}else{
				d_node->parent->left = d_node->right;
				d_node->left->parent = d_node->parent;
			}
		}
	}else{
		if(d_node->left != NULL && d_node->left->data.value == d_node->data.value){
			if(d_node->right == NULL){
				printf("ABC");
				bst->root = d_node->left;
				d_node->left = NULL;
			}else{
				printf("\nDEF\n");
				bst->root = d_node->right;
				d_node->right = NULL;
			}
		}else{
			if(d_node->right == NULL){
				printf("\nXYZ\n");
				bst->root = d_node->left;
				d_node->left = NULL;;	
			}else{
				bst->root = d_node->right;
				d_node->right = NULL;
			}
		}
	
	}
	free(d_node);
	d_node = NULL;
}


void promotion(Tree * bst, Node * d_node){
	Node * delNode = searchMin(d_node);
	d_node->data = delNode->data;
	if(delNode->left==NULL && delNode->right==NULL){
		removeLeaf(bst,delNode);
	}else{
		shortCircuit(bst,delNode);
	}
}

Node * searchMin(Node * node){
	if(node->right == NULL){
		return node;
	}else{
		node = node->right;
		while(node->left!=NULL){
			node = node->left;
		}
		return node;
	}	
}

