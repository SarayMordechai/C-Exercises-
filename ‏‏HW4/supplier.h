#include <stdio.h>
#include <stdbool.h>
#include "car.h"

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
  char dealer_number[DEALER_NUMBER + 1];
  char supplier_name[SUPPLIER_NAME + 1];
  char supplier_phone[SUPPLIER_PHONE + 1];
  char number_of_transactions[NUMBER_OF_TRANSACTIONS + 1];
  int transactions_sum;
}Supplier;

int supplierCounter; /*Counter of supplier*/
Supplier supplier_array[K]; /*Definition of an array of suppliers*/

Supplier getSupplierFieldsFromUser();/*Function that gets all the fields of a supplier from the user*/

void resetSupplier(int indexToRemove); /*Function that reset a supplier in an given index*/

void createSupplierList(); /*Declaration of a function that creates a list of suppliers*/

int deleteSupplier(char* supplier_name); /*Declaration of a function that deletes supplier*/

void deleteAllSuppliers(); /*Declaration of a function delets all the suppliers*/

#endif