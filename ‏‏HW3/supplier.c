#include <stdio.h>
#include <string.h>
#include "supplier.h"

/*Funcation that gets all the parameters from the user and creates an instance of a supplier from the struct*/
struct Supplier create_Supplier(char* dealer_number ,char* supplier_name ,char* supplier_phone,int number_of_transactions,int transactions_sum){
    struct Supplier s;
    strcpy(s.dealer_number, dealer_number);
    strcpy(s.supplier_name, supplier_name);
    strcpy(s.supplier_phone, supplier_phone);
    s.number_of_transactions = number_of_transactions;
    s.transactions_sum = transactions_sum;

    return s;
}

/*Function that adds a new supplier (using create supplier)*/
struct Supplier addNewSupplier(){
    /* data */
};

/*Function that sets an array of cars in the length of N (using add new supplier)*/
char* createCarList(){
    /* data */
}

/*Function that get the name of the supplier and deletes him from the system*/
struct Supplier deleteSupplier(char* supplier_name){
    struct Supplier su;
    strcpy(su.supplier_name, supplier_name);
}

/*Function that deletes all the cars */
void deleteAllCars(){
    /* data */
}