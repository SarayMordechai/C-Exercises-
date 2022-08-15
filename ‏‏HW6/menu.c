#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void print_cars(Car_tree *tree) {
    if(!tree){
        return;
    }
    print_cars(tree->left);
    
    printf("%s ", tree->car.license_number);
    printf("%d, ", tree->car.shield_number);
    printf("%s, ", tree->car.manuacturer);
    printf("%s, ", tree->car.model);
    printf("%s, ", tree->car.color);
    printf("%d, ", tree->car.production_year);
    printf("%d, ", tree->car.ascent_year);
    printf("%d, ", tree->car.supplier_price);
    printf("%d, ", tree->car.car_price);
    printf("%d \n", tree->car.engine_capacity);
    
    print_cars(tree->right);
}

void print_suppliers(Supplier_tree *tree) {
    if(!tree){
        return;
    }
    print_suppliers(tree->left);
    
    printf("%s ", tree->supplier.dealer_number);
    printf("%d, ", tree->supplier.number_of_transactions);
    printf("%s, ", tree->supplier.supplier_name);
    printf("%s, ", tree->supplier.supplier_phone);
    printf("%d \n, ", tree->supplier.transactions_sum);
    
    print_suppliers(tree->right);
}

void print_clients(Client_tree *tree) {
    if(!tree){
        return;
    }
    print_clients(tree->left);
    
    printf("%s ", tree->client.name);
    printf("%s, ", tree->client.last_name);
    printf("%s, ", tree->client.id);
    printf("%s, ", tree->client.license_number);
    printf("%d, ", tree->client.rental_price);
    printf("%d,%d ", tree->client.rental_time.hours , tree->client.rental_time.minutes);
    printf("%d,%d,%d \n, ", tree->client.date_of_rent.day ,tree->client.date_of_rent.month , tree->client.date_of_rent.year );
    
    print_clients(tree->right);
}

int menu(){
    
    int x, day, month, year, shield_number = 0 ,engine_capacity = 0 ,production_year = 0;
    char Id[9];
    char* lst[3], supplierName[5];
    double avarage;
    treeRootCar treeCar = createCarTree();
    treeRootClient treeClient = createClientsTree(); 
    treeRootSupplier treeSupplier = createSupplierTree();
	do
	{
		printf("MENU:\n");
		printf("-1- add new car\n");
		printf("-2- add new client\n");
		printf("-3- add new supplier\n");
		printf("-4- delete car\n");
		printf("-5- delete client.\n");
		printf("-6- delete supplier\n");
		printf("-7- delete all cars\n");
		printf("-8- delete all clients\n");
		printf("-9- delete all suppliers\n");
		printf("-10- get car number with given capacity\n");
		printf("-11- get client number with given car year\n");
		printf("-12- get the three greatest suppliers\n");
        printf("-13- find client (By: id or rental date) \n");
        printf("-14- print Client Cars For Given Rent Date\n");
        printf("-15-  avarage of supplier money\n");
        printf("-16- print suppliers\n");
		printf("-17- to exit\n");
		printf("Please enter a number:\n");
		scanf("%d", &x);
		
		switch(x){
			case 1:
			addNewCar(treeCar); 
            print_cars(treeCar);
			break;

			case 2:
            addNewClient(treeClient);
            print_clients(treeClient);
			break;

			case 3:
			addNewSupplier(treeSupplier);
            print_suppliers(treeSupplier);
			break;

			case 4:
            if(treeCar){
            printf("Please enter the wanted shield number of the car to remove:");
            scanf("%d", &shield_number);
			deleteCar(treeCar, shield_number);
            print_cars(treeCar);
            }
            else{
            printf("There are no existing car"); 
            }
			break;

			case 5:
            if(treeClient){
            printf("Please enter the wanted Id of the client to remove:");
            scanf("%s", Id);
			deleteClient(treeClient, Id);
            print_clients(treeClient);
            }
            else{
            printf("There are no existing client");
            }
			break;

			case 6:
            if(treeSupplier){
            printf("Please enter the wanted name of the supplier to remove:");
            scanf("%s", supplierName);
			deleteSupplier(treeSupplier, supplierName);
            print_suppliers(treeSupplier);
            }
            else{
            printf("There are no existing supplier");
               
            }
			break;

			case 7:
            if(treeCar){
			    deleteAllCars(treeCar);
            }else{
                printf("There are no existing cars");
            }
			break;

			case 8:
            if(treeClient){
			    deleteAllClients(treeClient);
            }else{
                printf("There are no existing clients");
            }
			break;

			case 9:
            if(treeSupplier){
                deleteAllSuppliers(treeSupplier);
            }else{
                printf("There are no existing suppliers");
            }
			break;

			case 10:
            printf("Please enter the engine_capacity :");
            scanf("%d \n", &engine_capacity);
            x = carNumberWithGivenCapacity(treeCar, engine_capacity);
            printf("The number of cars with the capacity of %d is: %d",engine_capacity,x);
			break;

			case 11:
            printf("Please enter the production year :");
            scanf("%d \n", &production_year);
            printf("The number of clients with the given car year of %d is: %d", production_year, x);
			break;

			case 12:
            lst[3] = threeGreatestSuppliers(treeSupplier);
            printf("The dealer numbers of the three greatest suppliers: %s, %s, %s \n", lst[0], lst[1], lst[2]);
			break;

            case 13:
            findClient(treeClient);
			break;

            case 14:
                printf("\nEnter rental date: ");
                scanf("%d/%d/%d", &day, &month, &year);
                printClientCarsForGivenRentDate(treeClient, day, month, year);
            break;

            case 15:
            avarage = averageOfSupplierMoney(treeSupplier, 0);
            printf("The avarage of the supplier money: %f \n", avarage);
			break;

            case 16:
            printSuppliers(treeSupplier);
			break;

			case 17:
			exit (1);
		}
	}while(x != 0);
	return 0;
}