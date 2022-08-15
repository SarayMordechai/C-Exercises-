#include <stdio.h>
#include "supplier.h"
#include "client.h"

#ifndef COMPANY_H /*Checks that it has not been defined before*/
#define COMPANY_H
#define MAX_K 50 /*The max number of the suppliers list*/
#define MAX_M 8000 /*The max number of the clients list*/

/*Creates a struct of a company with the required fields*/
struct Company{
    int k;
    int m;
};

char* createSupplierList(int k); /*Declaration of a function that creates a list of suppliers*/

char* createClientsList(int m); /*Declaration of a function that creates a list of clients*/

int clientNumberWithGivenCarYear(int production_year);/*Declaration of a function */

char* threeGreatestSuppliers(); /*Declaration of a function returns the three greatest suppliers*/

void deleteAllClients(); /*Declaration of a function deletes all the clients*/

void deleteAllSuppliers(); /*Declaration of a function delets all the suppliers*/

#endif