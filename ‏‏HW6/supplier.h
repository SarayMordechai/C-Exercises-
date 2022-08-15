#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "car.h"

#ifndef SUPPLIER_H /*Checks that it has not been defined before*/
#define SUPPLIER_H

/*Max values of the fileds*/
#define K 50
#define NUMBER_OF_FiELDS_SUPLLIER 5
#define DEALER_NUMBER 10
#define SUPPLIER_PHONE 10
#define NUMBER_OF_TRANSACTIONS 5
#define TRANSACTIONS_SUM 10

/*A struct of a supplier with the required fields*/
typedef struct Supplier {
  char* dealer_number;
  char* supplier_name;
  char* supplier_phone;
  int number_of_transactions;
  int transactions_sum;
}Supplier;

typedef struct Supplier_tree{
    Supplier supplier;
    struct Supplier_tree* left;
    struct Supplier_tree* right;
}Supplier_tree;

/*the root of the tree node*/
typedef struct Supplier_tree* treeRootSupplier;

treeRootSupplier createSupplierTree(); /*Declaration of a function that creates a list of suppliers*/

Supplier getSupplierFieldsFromUser();/*Function that gets all the fields of a supplier from the user*/

treeRootSupplier addSupplierNode(treeRootSupplier tree, Supplier supplier);

Supplier_tree* deleteSupplier(Supplier_tree *tree, char* supplier_name); /*Declaration of a function that deletes supplier*/

void deleteAllSuppliers(Supplier_tree* node); /*Declaration of a function delets all the suppliers*/

void printSuppliers(Supplier_tree* tree);

double averageOfSupplierMoney(Supplier_tree *tree , int* cnt_tran);

#endif