#include <stdio.h>
#include "supplier.h"
#include "client.h"
#include "validation.h"

#ifndef COMPANY_H /*Checks that it has not been defined before*/
#define COMPANY_H

/*Specific validations according to the structs*/
int carValidation(Car car);

int clientValidation(Client client);

int supplierValidation(Supplier supplier);

/*char* threeGreatestSuppliers();*/ /*Declaration of a function returns the three greatest suppliers*/

bool addNewCar(treeRootCar carRoot); /*Declaration of a function that add a new car*/

bool addNewClient(treeRootClient clientRoot); /*Declaration of a function that add a new client*/

bool addNewSupplier(treeRootSupplier supplierRoot); /*Declaration of a function thats add a new suppliers*/

int clientNumberWithGivenCarYear(Client_tree *clientTree ,Car_tree *carTree,int wanted_production_year);

int clientNumberWithGivenCarYearHelper(Client client, Car_tree *carTree, int wanted_production_year);

void copySupplier(Supplier *supplier1 , Supplier supplier2);

Supplier* resetSupplier();

char* threeGreatestSuppliers(treeRootSupplier root);

void top_three(treeRootSupplier node, Supplier *first, Supplier *second, Supplier *third);

#endif