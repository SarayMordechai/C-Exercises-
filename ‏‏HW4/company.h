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

char* threeGreatestSuppliers(); /*Declaration of a function returns the three greatest suppliers*/

int carNumberWithGivenCapacity(int engine_capacity); /*Declaration of a function that gets a given capacity and returns the number of cars that has it*/

int clientNumberWithGivenCarYear(int production_year);/*Declaration of a function */

bool addNewCar(); /*Declaration of a function that add a new car*/

bool addNewClient(); /*Declaration of a function that add a new client*/

bool addNewSupplier(); /*Declaration of a function thats add a new suppliers*/

#endif