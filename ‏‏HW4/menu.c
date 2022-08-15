#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void print_cars(){
    int i = 0;
    for(i = 0; i < carCounter; i++){
        printf("car %d: %s, ", i, car_array[i].license_number);
        printf("%d, ", car_array[i].shield_number);
        printf("%s, ", car_array[i].manuacturer);
        printf("%s, ", car_array[i].model);
        printf("%s, ", car_array[i].color);
        printf("%d, ", car_array[i].production_year);
        printf("%d, ", car_array[i].ascent_year);
        printf("%d, ", car_array[i].supplier_price);
        printf("%d, ", car_array[i].car_price);
        printf("%d \n", car_array[i].engine_capacity);
    }
}

void print_clients(){
    int i = 0;
    for(i=0;i<clientCounter;i++){
    printf("client %d: %s, " , i, client_array[i].name);
    printf("%s, " ,client_array[i].last_name);
    printf("%s, " ,client_array[i].id);
    printf("%s, " ,client_array[i].license_number);
    printf("%d, " ,client_array[i].rental_price);
    printf("%d/%d/%d, " ,client_array[i].date_of_rent.day,client_array[i].date_of_rent.month,client_array[i].date_of_rent.year);
    printf("%d:%d\n" ,client_array[i].rental_time.hours,client_array[i].rental_time.minutes);
    }
}

void print_suppliers(){
    int i = 0;
    for(i=0;i<supplierCounter;i++){
    printf("supplier %d: %s, ", i, supplier_array[i].dealer_number);
    printf("%s, ", supplier_array[i].supplier_name);
    printf("%s, ", supplier_array[i].supplier_phone);
    printf("%s, ", supplier_array[i].number_of_transactions);
    printf("%d\n", supplier_array[i].transactions_sum);
    }
}

int menu(){
    int i, x, shield_number = 0 ,engine_capacity = 0 ,production_year = 0;
    char Id[9];
    char supplierName[5];
    char *lst[3];
    createCarList();
    createClientsList(); 
    createSupplierList();
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
		printf("-13- to exit\n");
		printf("Please enter a number:\n");
		
		scanf("%d", &x);
		
		switch(x)
		{
			case 1:
			addNewCar(); 
            print_cars();
			break;

			case 2:
            addNewClient();
            print_clients();
			break;

			case 3:
			addNewSupplier();
            print_suppliers();
			break;

			case 4:
            /*Delete a specific car*/
            if(carCounter !=0){
            printf("Please enter the wanted shield number of the car to remove:");
            scanf("%d", &shield_number);
			deleteCar(shield_number);
            print_cars();
            }
            else{
            printf("There are no existing car"); 
            }
			break;

			case 5:
            /*Delete a specific client*/
            if(clientCounter != 0){
            printf("Please enter the wanted Id of the client to remove:");
            scanf("%s", Id);
			deleteClient(Id);
            print_clients();
            }
            else{
            printf("There are no existing client");
            }
			break;

			case 6:
            /*Delete a specific supplier*/
            if(supplierCounter !=0){
            printf("Please enter the wanted name of the supplier to remove:");
            scanf("%s", supplierName);
			deleteSupplier(supplierName);
            print_suppliers();
            }
            else{
            printf("There are no existing supplier");
               
            }
			break;

			case 7:
            /*Delete all the cars*/
            if(carCounter !=0){
			    deleteAllCars();
            }else{
                printf("There are no existing cars");
            }
			break;

			case 8:
            if(clientCounter !=0){
			    deleteAllClients();
            }else{
                printf("There are no existing clients");
            }
			break;

			case 9:
            if(supplierCounter !=0){
                deleteAllSuppliers();
            }else{
                printf("There are no existing suppliers");
            }
			break;

			case 10:
            printf("Please enter the engine_capacity :");
            scanf("%d \n", &engine_capacity);
			x = carNumberWithGivenCapacity(engine_capacity);
            printf("The number of cars with the capacity of %d is: %d",engine_capacity,x);
			break;

			case 11:
            printf("Please enter the production year :");
            scanf("%d \n", &production_year);
			x = clientNumberWithGivenCarYear(production_year);
            printf("The number of clients with the given car year of %d is: %d", production_year, x);
			break;

			case 12:
            threeGreatestSuppliers(lst);
            for(i = 0; i < 3; i++){
                printf("\n %s", lst[i]);
            }
			break;

			case 13:
			exit (1);
		}
	}while(x != 0);
	return 0;
}