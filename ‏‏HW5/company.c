#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "company.h"

int carValidation(Car car){
    /*Validate the fields of a new car as defined in the struct*/
    int isValid = 0;
    isValid += string_Length(car.license_number, LICENSE_NUMBER, "License number");
    isValid += exact_digits(car.shield_number, SHIELD_NUMBER, "Shield number");
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

/*Function that adds a car*/
bool addNewCar(struct carList carList){
    int status = 0;
    Car temp_car;
    temp_car = getCarFieldsFromUser();
    status = carValidation(temp_car);
    if(status == 0){
       struct nodeCar newNodeCar;
       newNodeCar.car = &temp_car;
       if (carList.carCounter == 0){
           newNodeCar.next = carList.tail;
           carList.head = &newNodeCar;
        }else{ 
            struct nodeCar tempNode;
            tempNode = *carList.head;
            while(true){
                if(tempNode.car->production_year < newNodeCar.car->production_year){
                    tempNode = *tempNode.next;
                    if(tempNode.next == NULL){
                        newNodeCar.next = carList.tail;
                        tempNode.next = &newNodeCar;
                    }
                    if(tempNode.next->car->production_year > newNodeCar.car->production_year ){
                        newNodeCar.next = tempNode.next;
                        tempNode.next = &newNodeCar;
                    }else{
                        tempNode = *tempNode.next;
                        continue;
                    }
                }else{ 
                newNodeCar.next = carList.head;
                carList.head = &newNodeCar;
                break;
                }
            }    
        }
        carList.carCounter ++;
        return true;
    }
    return false;
}


/*Function that adds a new client*/
bool addNewClient(struct ClientList clientList){
    int status = 0;
    Client temp_client = getClientFieldsFromUser();
    status = clientValidation(temp_client);
    if(status == 0){
        struct nodeClient newNodeClient;
        newNodeClient.client = &temp_client;
        if(clientList.clientCounter == 0){
           newNodeClient.next = clientList.tail;
           clientList.head = &newNodeClient;
        }else{ 
            struct nodeClient tempNode;
            tempNode = *clientList.head;
            while(tempNode.next != NULL){
                tempNode = *tempNode.next;
            }
            newNodeClient.next = clientList.tail;
            tempNode.next = &newNodeClient;
            tempNode = *tempNode.next;
            tempNode.client = &temp_client;
        }
        clientList.clientCounter ++;
        return true;
    }
    return false;
}

/*Function that adds a new supplier*/
bool addNewSupplier(struct SupplierList supplierList){
    int status = 0;
    Supplier temp_supplier = getSupplierFieldsFromUser();
    status = supplierValidation(temp_supplier);
    if(status == 0){
        struct nodeSupplier newNodeSupplier;
        newNodeSupplier.supplier = &temp_supplier;
        if(supplierList.supplierCounter == 0){
           newNodeSupplier.next = supplierList.tail;
           supplierList.head = &newNodeSupplier;
        }else{ 
            struct nodeSupplier tempNode;
            tempNode = *supplierList.head;
            while(tempNode.next != NULL){
                tempNode = *tempNode.next;
            }
            newNodeSupplier.next = supplierList.tail;
            tempNode.next = &newNodeSupplier;
            tempNode = *tempNode.next;
            tempNode.supplier = &temp_supplier;
        }
        supplierList.supplierCounter ++;
        return true;
    }
    return false;
}



/*Function that gets the production year of the car and returns the number of clients that have cars with this production year*/
/*
int clientNumberWithGivenCarYear(int wanted_production_year){
    int counterOfClientsCarYear = 0, i = 0, j = 0;
    for(i = 0; i < clientCounter; i++){
        for(j = 0; j < carCounter; j++){
            if (strcmp(client_array[i].license_number, car_array[j].license_number) == 0){
                if(car_array[j].production_year == wanted_production_year){
                    counterOfClientsCarYear += 1;
                    j = carCounter - 1;
                }
            } 
        }
    }
    return counterOfClientsCarYear;
}
*/

/*Function that returns the dealer numbers of the three suppliers which made the biggest deals*/
SupplierList* threeGreatestSuppliers(struct SupplierList suppliersLst){
    Supplier* sup1;
    Supplier* sup2;
    Supplier* sup3;
    nodeSupplier* supNode = suppliersLst.head;
    SupplierList* top3 = NULL;

    if(suppliersLst.supplierCounter < 3){
        printf("There are less then 3 suppliers");
        return top3;
    }

    while(supNode != NULL){
        /*If current element is greater than one*/      
        if (supNode->supplier->transactions_sum > sup1->transactions_sum){
            sup3 = sup2;
            sup2 = sup1;
            sup1 = supNode->supplier;
        }
        /*If arr[i] is in between one and two then update two*/
        
        else if(supNode->supplier->transactions_sum > sup2->transactions_sum){
            sup3 = sup2;
            sup2 = supNode->supplier;
        } 
        else if(supNode->supplier->transactions_sum > sup3->transactions_sum){
            sup3 = supNode->supplier;
        }
    }
    top3->head->supplier = sup1;
    top3->head->next->supplier = sup2;
    top3->tail->supplier = sup3;
    
    return top3;
}

/*Function that returns the dealer numbers of the three suppliers which made the biggest deals recusive*/
SupplierList* threeGreatestSuppliers_REC(struct SupplierList suppliersLst){
    Supplier* sup1 = NULL;
    Supplier* sup2 = NULL;
    Supplier* sup3 = NULL;
    nodeSupplier* supNode = suppliersLst.head;
    SupplierList* top3 = NULL;

    if(suppliersLst.head == NULL){
        return top3;
    }
    if (supNode->supplier->transactions_sum > sup1->transactions_sum){
        sup3 = sup2;
        sup2 = sup1;
        sup1 = supNode->supplier;
    }
    /*If arr[i] is in between one and two then update two*/
    
    else if(supNode->supplier->transactions_sum > sup2->transactions_sum){
        sup3 = sup2;
        sup2 = supNode->supplier;
    } 
    else if(supNode->supplier->transactions_sum > sup3->transactions_sum){
        sup3 = supNode->supplier;
    }

    suppliersLst.head = suppliersLst.head->next;
    threeGreatestSuppliers_REC(suppliersLst);

    top3->head->supplier = sup1;
    top3->head->next->supplier = sup2;
    top3->tail->supplier = sup3;

    return top3;
}

/*Function that gets the production year of the car and returns the number of clients that have cars with this production year*/
int clientNumberWithGivenCarYear(struct ClientList clientList,struct carList carList, int wanted_production_year){
    int counterOfClientsCarYear = 0;
    nodeCar *carNode = carList.head;
    nodeClient *clientNode = clientList.head;
     
    while(clientNode != NULL){
        while((carNode != NULL)){
            if((clientNode->client->license_number) == (carNode->car->license_number)){
                if((carNode->next->car->production_year) == (wanted_production_year)){
                    counterOfClientsCarYear+=1;
                }
            }
        carNode = carNode->next;
        }
    clientNode = clientNode->next;
    }
    return counterOfClientsCarYear;
}