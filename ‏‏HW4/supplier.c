#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "supplier.h"

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
    scanf("%s", supplier.number_of_transactions);
    printf("\nEnter transactions sum: ");
    scanf("%d", &supplier.transactions_sum);
    return supplier;
}

/*Reset a given index in the array*/
void resetSupplier(int indexToRemove){
    strcpy(supplier_array[indexToRemove].dealer_number, "\0");
    strcpy(supplier_array[indexToRemove].supplier_name, "\0");
    strcpy(supplier_array[indexToRemove].supplier_phone, "\0");
    strcpy(supplier_array[indexToRemove].number_of_transactions, "\0");
    supplier_array[indexToRemove].transactions_sum = -1;
}

/*Function that gets the max number and creates a reset array of the suppliers of the company*/
void createSupplierList(){
    int i = 0;
    for (i = 0; i < K; i++){
        resetSupplier(i);
	}
	supplierCounter = 0;
}

/*Function that get the name of the supplier and deletes him from the system*/
int deleteSupplier(char* supplier_name){
    int i;
    if(strcmp(supplier_name, supplier_array[supplierCounter -1].supplier_name) == 0){
        resetSupplier(supplierCounter -1);
        supplierCounter --;
        return 0;
    }
    for(i = 0; i < supplierCounter -1; i++){
        if (strcmp(supplier_name, supplier_array[i].supplier_name) == 0){
        /*Move the last one to the deleted one and reduce the count by 1*/
        supplier_array[i] = supplier_array[supplierCounter -1];
        resetSupplier(supplierCounter -1);
        supplierCounter --;
        return 0;  
        }
    }
    printf("The entered supplier name does not exist\n");
    return 1;
}

/*Function that goes over all of the existing suppliers and resetting them*/
void deleteAllSuppliers(){
    int i = 0;
    for(i = 0; i < supplierCounter; i++){
        resetSupplier(i);
	}
	supplierCounter = 0;
}