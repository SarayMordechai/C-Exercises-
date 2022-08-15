#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "car.h"

#ifndef SUPPLIER_H /*Checks that it has not been defined before*/
#define SUPPLIER_H


Tree* createSupplierTree(); /*Declaration of a function that creates a list of suppliers*/

Supplier getSupplierFieldsFromUser();/*Function that gets all the fields of a supplier from the user*/

Tree* deleteSupplier(char* supplier_name); /*Declaration of a function that deletes supplier*/

void deleteAllSuppliers(Tree* rootSupplier); /*Declaration of a function delets all the suppliers*/

int cmp2SuppliersByTransactionSum(Supplier* c1, Supplier* c2);

int cmp2SuppliersBySupplierName(Supplier* c1, Supplier* c2);

void printSuppliers(Supplier* supplier);

double averageOfSupplierMoney(Tree* tempSupplier , int* NumOfSuppliers);

#endif