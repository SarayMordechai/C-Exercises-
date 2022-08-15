#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "supplier.h"

/*Function that gets the max number and creates a reset array of the suppliers of the company*/
Tree* createSupplierTree(){
    rootSupplier = CreateTree(rootSupplier);
    return rootSupplier;
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

int cmp2SuppliersByTransactionSum(Supplier* c1, Supplier* c2){
    if(c1->transactions_sum == c2->transactions_sum){
        return 0;
    }
    if(c1->transactions_sum > c2->transactions_sum){
        return 1;
    }
    return -1;
}

int cmp2SuppliersBySupplierName(Supplier* c1, Supplier* c2){
    if(strcmp(c1->supplier_name, c2->supplier_name) == 0){
        return 0;
    }
    if(strcmp(c1->supplier_name, c2->supplier_name) > 0){
        return 1;
    }
    return -1;
}

/*Function that get the name of the supplier and deletes him from the system*/
Tree* deleteSupplier(char* supplier_name){
    Compare compareFunc;
    Supplier *tempSupplier = NULL;
    tempSupplier->supplier_name = supplier_name;
    if(!rootSupplier){
        printf("Supplier not exist \n");
        return 0;
    }
    compareFunc=(Compare)cmp2SuppliersBySupplierName;
    rootSupplier = deleteNode(rootSupplier , tempSupplier ,compareFunc);
    return rootSupplier;

}
/*Function that goes over all of the existing suppliers and resetting them*/
void deleteAllSuppliers(Tree* rootSupplier){
    FreeTree(rootSupplier);   
}


void printSuppliers(Supplier* supplier){
    if(!supplier){
        return;
    }
    printf("\n %s",supplier->dealer_number);
    printf(": %d " ,supplier->number_of_transactions);
    printf(": %s " ,supplier->supplier_name);
    printf(": %s " , supplier->supplier_phone);
    printf(": %d \n" ,supplier->transactions_sum);
}

double averageOfSupplierMoney(Tree* tree , int* NumOfSuppliers){
    int numOfTrnLeft, numOfTrnRight;
    double averageLeft , averageRight , sum1 , sum2;
    Supplier* Supplier = tree->val;

    if(!tree){
      *NumOfSuppliers = 0;
      return 0;
    } 

    /* ask for the averege of the left right childs */
    averageLeft =  averageOfSupplierMoney(tree->left , &numOfTrnLeft);
    averageRight =  averageOfSupplierMoney(tree->right , &numOfTrnRight);

    /* update the number of transactions */
    *NumOfSuppliers = numOfTrnLeft + numOfTrnRight + 1;

    /* mathematical expretion of avereg */
    sum1 = averageLeft * numOfTrnLeft;
    sum2 = averageRight * numOfTrnRight;
    return (sum1 + sum2 + Supplier->transactions_sum) / *NumOfSuppliers;
}