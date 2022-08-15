#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

int menu(){
    int x, shield_number = 0 ,engine_capacity = 0 ,production_year = 0;
    char Id[9];
    char supplierName[5];
	bool flag;
	carList carLst = createCarList();
	ClientList clientLst = createClientList();
	SupplierList supplierLst = createSupplierList();
	SupplierList* top3;

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
		printf("-13- get car number with given capacity recursive\n");
		printf("-14- get the three greatest suppliers recursive \n");
		printf("-15- get the client cars for given rent date (Only for davis)\n");
		printf("-16- print the suppliers list (Only for davis)\n");
		printf("-17- inverse car list \n");
		printf("-18- to exit\n");
		printf("Please enter a number:\n");
		
		scanf("%d", &x);
		
		switch(x)
		{
			case 1:
			flag = addNewCar(carLst); 
            if(flag){
				printf("Car was added \n");
				printCarsList(carLst);
			}
			break;

			case 2:
            flag = addNewClient(clientLst);
			if(flag){
				printf("Client was added \n");
            	print_clients(clientLst);
			}
			break;

			case 3:
			flag = addNewSupplier(supplierLst);
			if(flag){
				printf("Supplier was added \n");
            	print_suppliers(supplierLst);
			}
			break;

			case 4:
            /*Delete a specific car*/
            if(carLst.carCounter !=0){
				printf("Please enter the wanted shield number of the car to remove:");
				scanf("%d", &shield_number);
				deleteCar(carLst, shield_number);
				printCarsList(carLst);
            }
            else{
            	printf("There are no existing car"); 
            }
			break;

			case 5:
            /*Delete a specific client*/
            if(clientLst.clientCounter != 0){
				printf("Please enter the wanted Id of the client to remove:");
				scanf("%s", Id);
				deleteClient(clientLst, Id);
				print_clients(clientLst);
            }
            else{
            	printf("There are no existing client");
            }
			break;

			case 6:
            /*Delete a specific supplier*/
            if(supplierLst.supplierCounter !=0){
				printf("Please enter the wanted name of the supplier to remove:");
				scanf("%s", supplierName);
				deleteSupplier(supplierLst, supplierName);
				print_suppliers(supplierLst);
            }
            else{
            printf("There are no existing supplier");
               
            }
			break;

			case 7:
            /*Delete all the cars*/
            if(carLst.carCounter !=0){
			    deleteAllCars(carLst);
            }else{
                printf("There are no existing cars");
            }
			break;

			case 8:
            if(clientLst.clientCounter !=0){
			    deleteAllClients(clientLst);
            }else{
                printf("There are no existing clients");
            }
			break;

			case 9:
            if(supplierLst.supplierCounter !=0){
                deleteAllSuppliers(supplierLst);
            }else{
                printf("There are no existing suppliers");
            }
			break;

			case 10:
            printf("Please enter the engine_capacity :");
            scanf("%d \n", &engine_capacity);
			x = carNumberWithGivenCapacity(carLst, engine_capacity);
            printf("The number of cars with the capacity of %d is: %d",engine_capacity,x);
			break;

			case 11:
            printf("Please enter the production year :");
            scanf("%d \n", &production_year);
			x = clientNumberWithGivenCarYear(clientLst, carLst, production_year);
            printf("The number of clients with the given car year of %d is: %d", production_year, x);
			break;

			case 12:
            top3 = threeGreatestSuppliers(supplierLst);
			if(top3->head != NULL){
				nodeSupplier* supNode = top3->head;
				printf("Dealer numbers of the 3 greatest suppliers: ");
				while(supNode != NULL){
					printf("%s", supNode->supplier->dealer_number);
					supNode = supNode->next;
				}	
			}
			break;

			case 13:
			printf("Please enter the engine_capacity :");
            scanf("%d \n", &engine_capacity);
			x = carNumberWithGivenCapacity(carLst, engine_capacity);
            printf("The number of cars with the capacity of %d is: %d",engine_capacity,x);
			break;

			case 14:
			top3 = threeGreatestSuppliers(supplierLst);
			if(top3->head != NULL){
				nodeSupplier* supNode = top3->head;
				printf("Dealer numbers of the 3 greatest suppliers: ");
				while(supNode != NULL){
					printf("%s", supNode->supplier->dealer_number);
					supNode = supNode->next;
				}	
			}
			break;

			case 15:
			printClientCarsForGivenRentDate(clientLst);
			break;

			case 16:
			print_suppliers(supplierLst);
			break;

			case 17:
			inverseCarList(carLst);
			break;			

			case 18:
			exit (1);
		}
	}while(x != 0);

	deleteAllCars(carLst);
	deleteAllClients(clientLst);
	deleteAllSuppliers(supplierLst);
	return 0;
}