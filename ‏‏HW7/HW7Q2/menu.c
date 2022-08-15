#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void print_cars(Car* car) {
    if(!car){
        return;
    }    
    printf("%s ", car->license_number);
    printf("%d, ", car->shield_number);
    printf("%s, ", car->manuacturer);
    printf("%s, ", car->model);
    printf("%s, ", car->color);
    printf("%d, ", car->production_year);
    printf("%d, ", car->ascent_year);
    printf("%d, ", car->supplier_price);
    printf("%d, ", car->car_price);
    printf("%d \n",car->engine_capacity);   
}

void print_suppliers(Supplier* supplier) {
    if(!supplier){
        return;
    }
    printf("%s ", supplier->dealer_number);
    printf("%d, ", supplier->number_of_transactions);
    printf("%s, ", supplier->supplier_name);
    printf("%s, ", supplier->supplier_phone);
    printf("%d \n, ", supplier->transactions_sum);
}

void print_clients(Client* client) {
    if(!client){
        return;
    }    
    printf("%s ", client->name);
    printf("%s, ", client->last_name);
    printf("%s, ", client->id);
    printf("%s, ", client->license_number);
    printf("%d, ", client->rental_price);
    printf("%d,%d ", client->rental_time.hours , client->rental_time.minutes);
    printf("%d,%d,%d \n, ", client->date_of_rent.day ,client->date_of_rent.month , client->date_of_rent.year );
    }

int menu(){
    
    int x, day, month, year, shield_number = 0 ,engine_capacity = 0 ,production_year = 0;
    char Id[9];
    char* lst[3], supplierName[5];
    double avarage;
    Print p;
    Tree* treeCar = createCarTree();
    Tree* treeClient = createClientsTree(); 
    Tree* treeSupplier = createSupplierTree();

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
            p = (Print)print_cars;
            print_tree(treeCar, p);
			break;

			case 2:
            addNewClient(treeClient);
            p = (Print)print_clients;
            print_tree(treeClient,p);
			break;

			case 3:
			addNewSupplier(treeSupplier);
            p = (Print)print_suppliers;
            print_tree(treeSupplier,p);
			break;

			case 4:
          if(treeCar){
            printf("Please enter the wanted shield number of the car to remove:");
            scanf("%d", &shield_number);
			deleteCar(shield_number);
            p = (Print)print_cars;
            print_tree(treeCar ,p);
            }
            else{
            printf("There are no existing car"); 
            }
			break;

			case 5:
            if(treeClient){
            printf("Please enter the wanted Id of the client to remove:");
            scanf("%s", Id);
			deleteClient(Id);
            p = (Print)print_clients;
            print_tree(treeClient,p);
            }
            else{
            printf("There are no existing client");
            }
			break;

			case 6:
            if(treeSupplier){
            printf("Please enter the wanted name of the supplier to remove:");
            scanf("%s", supplierName);
			deleteSupplier(supplierName);
            p = (Print)print_suppliers;
            print_tree(treeSupplier ,p);
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
            p = (Print)printSuppliers;
            print_tree(treeSupplier, p);
			break;

			case 17:
			exit (1);
		}
	}while(x != 0);
    
	return 0;
}