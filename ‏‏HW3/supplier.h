#include <stdio.h>
#include "car.h"

#ifndef SUPPLIER_H /*Checks that it has not been defined before*/
#define SUPPLIER_H

/*Max values of the fileds*/
#define DEALER_NUMBER 10
#define SUPPLIER_NAME 5
#define SUPPLIER_PHONE 10
#define NUMBER_OF_TRANSACTIONS 5
#define TRANSACTIONS_SUM 10

/*A struct of a supplier with the required fields*/
struct Supplier {
  char* dealer_number[DEALER_NUMBER];
  char* supplier_name[SUPPLIER_NAME];
  char* supplier_phone[SUPPLIER_PHONE];
  int number_of_transactions;
  int transactions_sum;
};

/*Declaration of a function that creates supplier*/
struct Supplier create_Supplier(char* dealer_number ,char* supplier_name,char* supplier_phone,int number_of_transactions,int transactions_sum);

struct Supplier addNewSupplier(); /*Declaration of a function thats add a new suppliers (using create_supplier)*/

int carNumberWithGivenCapacity(int engine_capacity); /*Declaration of a function that gets a given capacity and returns the number of cars that has it*/

char* createCarList(); /*Declaration of a function that creates a list of cars*/

struct Supplier deleteSupplier(char* supplier_name); /*Declaration of a function that deletes supplier*/

void deleteAllCars(); /*Declaration of a function that deletes all the cars*/

#endif