#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "supplier.h"

/*Function that gets the max number and creates a reset array of the suppliers of the company*/
treeRootSupplier createSupplierTree(){
    treeRootSupplier root = malloc(sizeof(treeRootSupplier));
    if(!root) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(treeRootSupplier));
        exit(-1);
    }
    root->supplier.dealer_number = "/0";
    root->supplier.supplier_name = "/0";
    root->supplier.supplier_phone = "/0";
    root->supplier.number_of_transactions = -1;
    root->supplier.transactions_sum = -1;
    root->right = NULL;
    root->left = NULL;

    return root;
}

/*Get all the fields of a supplier from the user*/
Supplier getSupplierFieldsFromUser(){
    Supplier supplier;
    printf("\nEnter dealer number: ");
    scanf("%s", supplier.dealer_number);
    printf("\nEnter supplier name: ");
    scanf("%s", supplier.supplier_name);
    printf("\nEnter supplier phone: ");
    scanf("%s", supplier.supplier_phone);
    printf("\nEnter number of transactions: ");
    scanf("%d", &supplier.number_of_transactions);
    printf("\nEnter transactions sum: ");
    scanf("%d", &supplier.transactions_sum);
    return supplier;
}

treeRootSupplier addSupplierNode(treeRootSupplier tree, Supplier supplier){
    if(!tree){
        treeRootSupplier new_node = (treeRootSupplier)malloc(sizeof(Supplier_tree));
        if(!new_node){
            fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Supplier_tree));
            exit(-1);
        }
        new_node->supplier = supplier;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    
    if(supplier.transactions_sum < tree->supplier.transactions_sum){ /* Go left */
        tree->left = addSupplierNode(tree->left, supplier);
    }else{ /* Go right */
        tree->right = addSupplierNode(tree->right, supplier);
    }

    return tree;
}

/*Function that get the name of the supplier and deletes him from the system*/
Supplier_tree* deleteSupplier(Supplier_tree *tree, char* supplier_name){
    if(tree == NULL){
        return NULL;
    }

    /*look for the target node*/
    if(strcmp(tree->supplier.supplier_name, supplier_name) != 0){
        if(strcmp(supplier_name, (tree->supplier.supplier_name)) < 0){ /*Go left*/
            tree->left = deleteSupplier(tree->left, supplier_name);
        }
        else{ /*go right, key > (tree->key)*/
            tree->right = deleteSupplier(tree->right, supplier_name);
        }
        return tree;
    }

    /* Option 1: If the node is a "leaf" (has no childrens) remove this node*/
    if(!(tree->left) && !(tree->right)) {
        free(tree);
        return NULL;
    }else if(!(tree->left)){ /* Option 2: node has only one child (right) */
        treeRootSupplier temp = tree->right;
        free(tree);
        return temp;
    } else if(!(tree->right)){ /* Option 2: node has only one child (left)*/
        treeRootSupplier temp = tree->left;
        free(tree);
        return temp;
    }else{ /* Option 3: node has 2 children */
        treeRootSupplier x = tree->right;
        treeRootSupplier* xparent = &(tree->right);
        while(x->left){
            xparent = &(x->left);
            x=x->left;
        }
        tree->supplier = x->supplier;
        *xparent = deleteSupplier(x, x->supplier.supplier_name);
    }

    return tree;
}

/*Function that goes over all of the existing suppliers and resetting them*/
void deleteAllSuppliers(Supplier_tree* node){
    if(!(node)) return;/* if the first node is NULL return*/

    /*delete both subtrees*/
    if(node->left != NULL){
        deleteAllSuppliers(node->left);
    }
    if(node->right != NULL){
        deleteAllSuppliers(node->right);
    }

    /*delete the node */
    free(node);
}

void printSuppliers(Supplier_tree* tree){
    if(!tree){
        return;
    }
    printSuppliers(tree->left);
    printf("\n %s",tree->supplier.dealer_number);
    printf(": %d " ,tree->supplier.number_of_transactions);
    printf(": %s " ,tree->supplier.supplier_name);
    printf(": %s " , tree->supplier.supplier_phone);
    printf(": %d \n" ,tree->supplier.transactions_sum);
    printSuppliers(tree->right);
}

double averageOfSupplierMoney(Supplier_tree *tree , int* cnt_tran){
    int numOfTrnLeft, numOfTrnRight;
    double averageLeft , averageRight , sum1 , sum2;
    if(!tree){
      *cnt_tran = 0;
      return 0;
    } 
    /* ask for the averege of the left right childs */
    averageLeft =  averageOfSupplierMoney(tree->left , &numOfTrnLeft);
    averageRight =  averageOfSupplierMoney(tree->right , &numOfTrnRight);

    /* update the number of transactions */
    *cnt_tran = numOfTrnLeft + numOfTrnRight + 1;

    /* mathematical expretion of avereg */
    sum1 = averageLeft * numOfTrnLeft;
    sum2 = averageRight * numOfTrnRight;
    return (sum1 + sum2 + tree->supplier.number_of_transactions) / *cnt_tran;
}