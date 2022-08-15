#include "tree.h"
#include <malloc.h>


static void* findMin(Tree* root);

Tree* CreateTree(Tree* tree){
	tree=(Tree*)checked_malloc(sizeof(Tree));
	tree->val=NULL;
	tree->left=NULL;
	tree->right=NULL;
	return tree;
}

Tree* add_new_node(Tree * root,void * val,int (*fcmp)(void*,void*)){
	if(root==NULL){
		root=ALLOC(Tree,1);
		root->right=NULL;
		root->left=NULL;
		root->val=val;
		return root;
	}else if(fcmp(root->val,val)>0){
		root->right=add_new_node(root->right,val,fcmp);
	}else{
		root->left=add_new_node(root->left,val,fcmp);
	}
	return root;
}

void* find_in_tree(Tree * root, void * val, int(*fcmp)(void *,void *)){
	if(root){
		if(fcmp(val,root->val)==0){
			return root->val;
		}else if(fcmp(val,root->val)>0){
			return find_in_tree(root->right,val,fcmp);
		}else{
			return find_in_tree(root->left,val,fcmp);
		}
	}
	return NULL;
}

GenNode* connect_list(GenNode* l1,GenNode* l2){
	if(l1==NULL){
		return l2;
	}else if(l2==NULL){
		return l1;
	}else {
		GenNode* temp=l1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
			temp->next=l2;
			return l1;
	}
}

GenNode* find_node(Tree * root,void * val, int(*fcmp)(void *,void *)){
	GenNode* right, * left;
	if(root==NULL){
		return NULL;
	}
	left=find_node(root->left,val,fcmp);
	right=find_node(root->right,val,fcmp);
	left=connect_list(left,right);
	if(fcmp(val,root->val)==0){
		left=add_to_list(left,root->val);
	}
	return left;
}

GenNode* add_to_list(GenNode* list,void* val){
	GenNode* temp=(GenNode*)malloc(sizeof(GenNode));
	if(temp==NULL){
		printf("error");
		exit(1);
	}
	temp->val=val;
	temp->next=list;
	return temp;
}

void print_list(GenNode* list,void (*fprint)(void*)){
	while(list!=NULL){
		fprint(list->val);
		list=list->next;
	}
}

void *checked_malloc(unsigned int size){
	void * ret;

	ret = malloc(size);
	if (!ret) {
		perror ("Memory allocation error");
		exit (1);
	}
	return ret;
}

Tree* deleteNode(Tree* root, void* key, Compare cmp){
	Tree* tmp;
	if(root==NULL) printf("No Car.\n");

	if(cmp(key,root->val)==-1){
		root->left=deleteNode(root->left,key,cmp);
	}
	if(cmp(key,root->val)==1){
		root->right=deleteNode(root->right,key,cmp);
	}
	else {
		if(root->left == NULL){
			tmp = root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL){
			tmp = root->left;
			free(root);
			return tmp;
		}

		tmp=findMin(root->right);
		root->val = tmp->val;
		root->right = deleteNode(root->right,tmp->val,cmp);
	}
	return root;
}

static void *findMin(Tree *root){
	if(!root){
		return NULL;
	}else if(root->left==NULL){
		return root->val;
	}
	return findMin(root->left);
}


double average_key(Tree * root, int * num_of_nodes,Average getAvg){
	double avg_left, avg_right;
	int num_left, num_right;
	if (!root) {
		*num_of_nodes = 0;
		return 0;
	}
	avg_left = average_key(root->left, &num_left, getAvg);
	avg_right = average_key(root->right, &num_right, getAvg);
	*num_of_nodes = num_left + num_right + 1;
	return (avg_left * num_left + avg_right * num_right + getAvg(root))/ (*num_of_nodes);
}


int	Find_Number_Of_Nodes(Tree * root){
	if(root==NULL){
		return 0;
	}
	return (1 + Find_Number_Of_Nodes(root->left) + Find_Number_Of_Nodes(root->right));
}

void ** tree_to_array(Tree * root,void ** treeArray,int * counter,ArrayKind addToArray){
	if(root==NULL){
		return treeArray;
	}
	if(treeArray == NULL){
		*treeArray = ALLOC(Tree *,Find_Number_Of_Nodes(root));
	}
	treeArray = tree_to_array(root->left,treeArray,counter,addToArray);
	treeArray = addToArray(root,treeArray,(*counter));
	(*counter)++;
	treeArray = tree_to_array(root->right,treeArray,counter,addToArray);
	return treeArray;
}


void print_tree(Tree* root,Print p){
	if(!root){
		return;
	}
	p(root->val);
	print_tree(root->left,p);
	print_tree(root->right,p);
}

void FreeTree(Tree* t){
	if (t==NULL) return;

	FreeTree(t->left);
	FreeTree(t->right);
	free(t);
}