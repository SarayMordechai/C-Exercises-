#include <stdio.h>
#include <stdbool.h>

#ifndef SUPPLIER_H /*Checks that it has not been defined before*/
#define SUPPLIER_H

/*Max values of the fileds*/
#define K 50
#define NUMBER_OF_FiELDS_SUPLLIER 5
#define DEALER_NUMBER 10
#define SUPPLIER_NAME 5
#define SUPPLIER_PHONE 10
#define NUMBER_OF_TRANSACTIONS 5
#define TRANSACTIONS_SUM 10

/*A struct of a supplier with the required fields*/
typedef struct Supplier {
  char* dealer_number;
  char* supplier_name;
  char* supplier_phone;
  char* number_of_transactions;
  int transactions_sum;
}Supplier;

typedef struct nodeSupplier{
    Supplier* supplier;
    struct nodeSupplier *next;
}nodeSupplier;

typedef struct SupplierList{
  struct nodeSupplier* head;
  struct nodeSupplier* tail;
  int supplierCounter;
}SupplierList;

nodeSupplier* supplierHead;
Supplier* temp_supplier;


Supplier getSupplierFieldsFromUser();/*Function that gets all the fields of a supplier from the user*/

struct SupplierList createSupplierList(); /*Declaration of a function that creates a list of suppliers*/

bool deleteSupplier(struct SupplierList supplierList ,char* supplier_name); /*Declaration of a function that deletes supplier*/

bool deleteAllSuppliers(struct SupplierList supplierList); /*Declaration of a function delets all the suppliers*/

#ifdef DAVIS
void print_suppliers(struct SupplierList supplierList);
#endif /*Of DAVIS*/

#endif