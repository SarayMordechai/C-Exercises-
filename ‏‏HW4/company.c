#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "company.h"

int carValidation(Car car){
    /*Validate the fields of a new car as defined in the struct*/
    int isValid = 0;
    isValid += string_Length(car.license_number, LICENSE_NUMBER, "License number");
    isValid += exact_digits(car.shield_number, SHIELD_NUMBER, "Shield number");
    isValid += string_Length(car.manuacturer, MANUACTURER_MAX, "Manuacturer");
    isValid += string_Length(car.model, MODEL_MAX, "Model");
    isValid += string_Length(car.color, COLOR_MAX,"Color");
    isValid += exact_digits(car.production_year, PRODUCTION_YEAR, "Production year");
    isValid += exact_digits(car.ascent_year, ASCENT_YEAR, "Ascent year");
    isValid += max_digits(car.supplier_price, MAX_SUPPLIER_PRICE, "Supplier price");
    isValid += max_digits(car.car_price, MAX_CAR_PRICE, "Car price");
    isValid += exact_digits(car.engine_capacity, ENGINE_CAPACITY, "Engine capacity");

    return isValid;
}

int clientValidation(Client client){
    /*Validate the fields of a new client as defined in the struct*/
    int isValid = 0;
    isValid += string_Length(client.name, MAX_NAME_LENGHT, "Name");
    isValid += string_Length(client.last_name, MAX_NAME_LENGHT, "Last name");
    isValid += only_digits_string_length(client.id, ID_LENGTH, "ID");
    isValid += max_digits(client.rental_price, RENTAL_PRICE_MAX_DIGITS, "Rental price");
    /*Date validations*/
    isValid += max_number(client.date_of_rent.day,MAX_DAY,"day");
    isValid += min_number(client.date_of_rent.day,ONE_MIN,"day");
    isValid += max_number(client.date_of_rent.month,MAX_MONTH,"month");
    isValid += min_number(client.date_of_rent.month,ZERO_MIN,"month");
    /*Time validations*/
    isValid += max_number(client.rental_time.hours,MAX_HOUR,"hour");
    isValid += min_number(client.rental_time.hours,ZERO_MIN,"hour");
    isValid += max_number(client.rental_time.minutes,MAX_MINUTE,"minutes");
    isValid += min_number(client.rental_time.hours,ZERO_MIN,"hour");

    return isValid;
}

int supplierValidation(Supplier supplier){
    /*Validate the fields of a new supplier as defined in the struct*/
    int isValid = 0;
    isValid += only_digits_string_length(supplier.dealer_number, DEALER_NUMBER, "Dealer number");
    isValid += string_Length(supplier.supplier_name, SUPPLIER_NAME,"Supplier name");
    isValid += only_digits_string_length(supplier.supplier_phone, SUPPLIER_PHONE, "Supplier phone number");
    isValid += only_digits_string_length(supplier.number_of_transactions, NUMBER_OF_TRANSACTIONS, "Number of transactions");
    isValid += exact_digits(supplier.transactions_sum, TRANSACTIONS_SUM, "Sum of transactions");
    
    return isValid;
}

/*Function that gets the production year of the car and returns the number of clients that have cars with this production year*/
int clientNumberWithGivenCarYear(int wanted_production_year){
    int counterOfClientsCarYear = 0, i = 0, j = 0;
    for(i = 0; i < clientCounter; i++){
        for(j = 0; j < carCounter; j++){
            if (strcmp(client_array[i].license_number, car_array[j].license_number) == 0){
                if(car_array[j].production_year == wanted_production_year){
                    counterOfClientsCarYear += 1;
                    break;
                }
            } 
        }
    }
    return counterOfClientsCarYear;
}

/*Function that returns the dealer numbers of the three suppliers which made the biggest deals*/
char* threeGreatestSuppliers(char* delerNum[]){
    int i = 0, one = 0, two = 0, three = 0, theGreatest[3] , j=0;
    if(supplierCounter < 3){
        printf("There are less then 3 suppliers");
        return 0;
    }
    for (i = 0; i < supplierCounter; i++) {
        /*If current element is greater than one*/        
        if (supplier_array[i].transactions_sum > one){
            three = two;
            two = one;
            one = supplier_array[i].transactions_sum;
        }
        /*If arr[i] is in between one and two then update two*/
        else if(supplier_array[i].transactions_sum > two){
            three = two;
            two = supplier_array[i].transactions_sum;
        } 
        else if(supplier_array[i].transactions_sum > three){
            three = supplier_array[i].transactions_sum;
        }
    }
    theGreatest[0] = one;
    theGreatest[1] = two;
    theGreatest[2] = three;
    i=0;
    for(j = 0; j < supplierCounter; j++){
        if(theGreatest[j] == supplier_array[j].transactions_sum){
           delerNum[i] = supplier_array[j].dealer_number; 
            i += 1;        
        }
    }
    return *delerNum;
}

/* gets a given capacity and returns the number of cars that has it*/
int carNumberWithGivenCapacity(int wanted_engine_capacity){
    int i = 0;
    int counterOfCarCapacity = 0;
    for(i = 0; i < carCounter; i++){
        if(car_array[i].engine_capacity == wanted_engine_capacity){
            counterOfCarCapacity += 1;
        }
    }
    return counterOfCarCapacity;
}

/*Function that adds a car*/
bool addNewCar(){
    int status = 0;
    Car temp_car;
    temp_car = getCarFieldsFromUser();
    status = carValidation(temp_car);
    if(status == 0){
        car_array[carCounter] = temp_car;
        carCounter ++;
        return true;
    }
    return false;
}

/*Function that adds a new client*/
bool addNewClient(){
    int status = 0;
    Client temp_client;
    temp_client = getClientFieldsFromUser();
    status = clientValidation(temp_client);
    if(status == 0){
        client_array[clientCounter] = temp_client;
        clientCounter ++;
        return true;
    }
    return false;
}

/*Function that adds a new supplier*/
bool addNewSupplier(){
    int status = 0;
    Supplier temp_supplier;
    temp_supplier = getSupplierFieldsFromUser();
    status = supplierValidation(temp_supplier);
    if(status == 0){
        supplier_array[supplierCounter] = temp_supplier;
        supplierCounter ++;
        return true;
    }
    return false;
}
