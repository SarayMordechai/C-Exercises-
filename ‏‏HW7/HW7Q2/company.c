#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
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
    isValid += only_digits_string_length(supplier.supplier_phone, SUPPLIER_PHONE, "Supplier phone number");
    isValid += exact_digits(supplier.number_of_transactions, NUMBER_OF_TRANSACTIONS, "Number of transactions");
    isValid += exact_digits(supplier.transactions_sum, TRANSACTIONS_SUM, "Sum of transactions");
    
    return isValid;
}

/*Function that adds a car*/
bool addNewCar(Tree* carRoot){
    int status = 0;
    Compare compareFunc;
    Car* temp_car = NULL;
    *temp_car = getCarFieldsFromUser();
    status = carValidation(*temp_car);
    if(status == 0){
        compareFunc=(Compare)cmp2CarsByShieldNumber;
        carRoot = add_new_node(carRoot, temp_car,compareFunc);
        
        return true;
    }
    return false;
}

/*Function that adds a new supplier*/
bool addNewSupplier(Tree* supplierRoot){
    int status = 0;
    Compare compareFunc;
    Supplier* temp_supplier = NULL;
    *temp_supplier = getSupplierFieldsFromUser();
    status = supplierValidation(*temp_supplier);
    if(status == 0){
        compareFunc=(Compare)cmp2SuppliersByTransactionSum;
        supplierRoot = add_new_node(supplierRoot, temp_supplier,compareFunc);
        return true;
    }
    return false;
}


/*Function that adds a new client*/
bool addNewClient(Tree* clientRoot){
    int status = 0;
    Compare compareFunc;
    Client* temp_client = NULL;
    *temp_client = getClientFieldsFromUser();
    status = clientValidation(*temp_client);
    if(status == 0){
        compareFunc=(Compare)cmp2ClientsByid;
        clientRoot = add_new_node(clientRoot, temp_client,compareFunc);
        return true;
    }
    return false;
}

int cmpClientAndCarLicenseNumber(Client* c1, Car* c2){
    if(strcmp(c1->license_number, c2->license_number) == 0){
        return 0;
    }else if(strcmp(c1->license_number, c2->license_number) > 0){
        return 1;
    }
    return -1;
}

int cmp2CarsByProdYear(Car* c1, Car* c2){
    if(c1->production_year == c2->production_year){
        return 0;
    }
    if(c1->production_year > c2->production_year){
        return 1;
    }
    return -1;
}

int clientNumberWithGivenCarYear(Tree* clientTree, Tree* carTree, int wanted_production_year){
    int counterOfClientsCarYear = 0;
    if(!clientTree && !carTree){
        return 0;
    }
    counterOfClientsCarYear = clientNumberWithGivenCarYearHelper(clientTree->val, carTree, wanted_production_year);
    
    return counterOfClientsCarYear + 
    clientNumberWithGivenCarYear(clientTree->left, carTree ,wanted_production_year) +
    clientNumberWithGivenCarYear(clientTree->right, carTree ,wanted_production_year);
}

int clientNumberWithGivenCarYearHelper(void *key, Tree* carTree, int wanted_production_year){
    int counter = 0;
    Car* tempCar = NULL;
    tempCar->production_year = wanted_production_year;
    if (!carTree){
        return 0;
    }
    if(cmpClientAndCarLicenseNumber(key, carTree->val) == 0){
        if(cmp2CarsByProdYear(key, tempCar) == 0){
            counter++;  
        }
    }
    return counter + clientNumberWithGivenCarYearHelper(key, carTree->right, wanted_production_year) + 
    clientNumberWithGivenCarYearHelper(key, carTree->left, wanted_production_year);
}

void copySupplier(Supplier *supplier1 , Supplier supplier2){
    /*Copy supplier2 to supplier1*/
    strcpy(supplier1->dealer_number,supplier2.dealer_number);
    strcpy(supplier1->supplier_name, supplier2.supplier_name);
    strcpy(supplier1->supplier_phone, supplier2.supplier_phone);
    supplier1->transactions_sum = supplier2.transactions_sum;
    supplier1->number_of_transactions = supplier2.number_of_transactions;
}

/*Find top three largest nodes in binary tree*/
void top_three(Tree* node, Supplier *first, Supplier *second, Supplier *third){
    Supplier* tmpSupp = node->val;
	if (node != NULL){
		if (first->transactions_sum == -1){
            Supplier* supplier = node->val;
            copySupplier(first, *supplier);
		}
		else if (first->transactions_sum < tmpSupp->transactions_sum){
            copySupplier(third, *second);
            copySupplier(second, *first);
            copySupplier(first, *tmpSupp);
		}else if (second->transactions_sum == -1){
			if (first->dealer_number != tmpSupp->dealer_number){
                copySupplier(second, *tmpSupp);
			}
		}else{
			if (second->transactions_sum < tmpSupp->transactions_sum 
            && first->transactions_sum > tmpSupp->transactions_sum){
                copySupplier(third, *second);
                copySupplier(second, *tmpSupp);
			}else if (third->transactions_sum == -1){
				if (second->transactions_sum > tmpSupp->transactions_sum
                && first->transactions_sum > tmpSupp->transactions_sum){
                    copySupplier(third, *tmpSupp);
				}
			}
			else if (third->transactions_sum < tmpSupp->transactions_sum 
            && first->transactions_sum > tmpSupp->transactions_sum
             && second->transactions_sum > tmpSupp->transactions_sum){
                copySupplier(third, *tmpSupp);
			}
		}
		top_three(node->left, first, second, third);
		top_three(node->right, first, second, third);
	}
}

/*Reset a given index in the array*/
Supplier* resetSupplier(){
    Supplier* supplier = NULL;
    strcpy(supplier->dealer_number, "\0");
    strcpy(supplier->supplier_name, "\0");
    strcpy(supplier->supplier_phone, "\0");
    supplier->number_of_transactions = -1;
    supplier->transactions_sum = -1;
    return supplier;
}

/*This is handle the request to finding top three nodes in binary tree*/
char* threeGreatestSuppliers(Tree* root){
	Supplier* first = NULL, *second = NULL, *third = NULL;
    char* lst[3] = {NULL, NULL, NULL};
    first = resetSupplier(first);
    second = resetSupplier(second);
    third = resetSupplier(third);
    
	if (root == NULL){
		return NULL;
	}
	top_three(root, first, second, third);
	if(first->transactions_sum != -1){
        lst[0] = first->dealer_number;
        if (second->transactions_sum != -1){
            lst[1] = second->dealer_number;
            if (third->transactions_sum != -1){
                lst[2] = third->dealer_number;
            }  
        }  
    }
    return *lst;
}