#include <stdio.h>
#include "supplier.h"
#include "client.h"
#include "validation.h"
#include "tree.h"

#ifndef COMPANY_H /*Checks that it has not been defined before*/
#define COMPANY_H

/*Specific validations according to the structs*/
int carValidation(Car car);

int clientValidation(Client client);

int supplierValidation(Supplier supplier);

bool addNewCar(Tree* carRoot); /*Declaration of a function that add a new car*/

bool addNewClient(Tree* clientRoot); /*Declaration of a function that add a new client*/

bool addNewSupplier(Tree* supplierRoot); /*Declaration of a function thats add a new suppliers*/

/*A function that receives a number that is an engine volume
For inspection and returns the number of vehicles in the company with the above volume*/
int clientNumberWithGivenCarYear(Tree* clientTree, Tree* carTree, int wanted_production_year);

int clientNumberWithGivenCarYearHelper(void *key, Tree* carTree, int wanted_production_year);

int cmpClientAndCarLicenseNumber(Client* c1, Car* c2);

int cmp2CarsByProdYear(Car* c1, Car* c2);

void copySupplier(Supplier *supplier1 , Supplier supplier2);

Supplier* resetSupplier();/*Reset a given index in the array*/

char* threeGreatestSuppliers(Tree* root);/*This is handle the request to finding top three nodes in binary tree*/

void top_three(Tree* node, Supplier *first, Supplier *second, Supplier *third);/*Find top three largest nodes in binary tree*/

#endif