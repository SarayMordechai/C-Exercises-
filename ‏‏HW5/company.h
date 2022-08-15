#include <stdio.h>
#include "supplier.h"
#include "client.h"
#include "car.h"
#include "validation.h"

#ifndef COMPANY_H /*Checks that it has not been defined before*/
#define COMPANY_H

typedef struct CompanyData{
    struct carList* carlist;
    struct Supplierlist* Supplierlist;
    struct clientList* clientList;
}CompanyData;

/*Specific validations according to the structs*/
int carValidation(Car car);

int clientValidation(Client client);

int supplierValidation(Supplier supplier);

SupplierList* threeGreatestSuppliers(struct SupplierList suppliersLst);/*Declaration of a function returns the three greatest suppliers*/

int clientNumberWithGivenCarYear(struct ClientList clientList, struct carList carList, int production_year);/*Declaration of a function */

bool addNewCar(struct carList carList); /*Declaration of a function that add a new car*/

bool addNewClient(struct ClientList clientList); /*Declaration of a function that add a new client*/

bool addNewSupplier(struct SupplierList supplierList); /*Declaration of a function thats add a new suppliers*/

SupplierList* threeGreatestSuppliers_REC(struct SupplierList suppliersLst); /*Declaration of a function returns the three greatest suppliers recursive*/

#endif