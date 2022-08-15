#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "supplier.h"

/*Get all the fields of a supplier from the user*/
Supplier getSupplierFieldsFromUser(){

    Supplier* supplier = (Supplier*)malloc(sizeof(Supplier*));
    if(!supplier) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Supplier));
        exit(-1);
    }

    printf("\nEnter dealer number: ");
    scanf("%s", supplier->dealer_number);
    printf("\nEnter supplier name: ");
    scanf("%s", supplier->supplier_name);
    printf("\nEnter supplier phone: ");
    scanf("%s", supplier->supplier_phone);
    printf("\nEnter number of transactions: ");
    scanf("%s", supplier->number_of_transactions);
    printf("\nEnter transactions sum: ");
    scanf("%d", &supplier->transactions_sum);
    return *supplier;
}

/*Function that gets the max number and creates a reset array of the suppliers of the company*/
struct SupplierList createSupplierList(){
   struct nodeSupplier* head = NULL; 
   struct nodeSupplier* tail = NULL; 
   struct SupplierList* supplierList1 = NULL;

 head = (struct nodeSupplier*)malloc(sizeof(struct nodeSupplier));
    if(!head) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Supplier));
        exit(-1);
    }
 tail = (struct nodeSupplier*)malloc(sizeof(struct nodeSupplier));
    if(!tail) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Supplier));
        exit(-1);
    }

    head->next = tail;

supplierList1 = (SupplierList*)malloc(sizeof(SupplierList));
    if(!supplierList1) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Supplier));
        exit(-1);
    }
    
    supplierList1->head = head;
    supplierList1->tail = tail;
    supplierList1->supplierCounter = 0;

    return *supplierList1;
}

/*Function that get the name of the supplier and deletes him from the system*/
bool deleteSupplier(struct SupplierList supplierList ,char* supplier_name){
    if(supplierList.head->next != NULL){
        while (supplierList.head == supplierList.tail){
            if(supplierList.head->next->supplier->supplier_name == supplier_name){
                supplierList.head->next = supplierList.head->next->next;
                free(supplierList.head->next->supplier);
                free(supplierList.head->next);
            }
        }
     supplierList.supplierCounter --;
     return true;
        
    }
return false;
    }



/*Function that goes over all of the existing suppliers and resetting them*/
bool deleteAllSuppliers(struct SupplierList supplierList){
    while (supplierList.head == supplierList.tail){
        supplierList.head->next = supplierList.head->next->next;
        free(supplierList.head->next->supplier);
        free(supplierList.head->next);
    }

    if(supplierList.head == NULL){
        supplierList.supplierCounter = 0;
        return true;

    }
return false;
}

void print_suppliers(struct SupplierList supplierList){
    supplierHead = supplierList.head;
    while(supplierHead != NULL){
        printf("supplier : %s, ", supplierHead->supplier->dealer_number );
        printf("%s, ", supplierHead->supplier->supplier_name);
        printf("%s, ", supplierHead->supplier->supplier_phone);
        printf("%s, ", supplierHead->supplier->number_of_transactions);
        printf("%d\n", supplierHead->supplier->transactions_sum);
        supplierHead = supplierHead->next;
    }
}