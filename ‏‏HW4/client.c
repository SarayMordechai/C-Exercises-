#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "client.h"

/*Get all th fields of a client from the user*/
Client getClientFieldsFromUser(){
    Client client;
    printf("\nEnter client name: ");
    scanf("%s" ,client.name);
    printf("\nEnter client last name: ");
    scanf("%s" ,client.last_name);
    printf("\nEnter id: ");
    scanf("%s" ,client.id);
    printf("\nEnter license number: ");
    scanf("%s" ,client.license_number);
    printf("\nEnter rental price: ");
    scanf("%d" , &client.rental_price);
    printf("\nEnter rental date: ");
    scanf("%d/%d/%d",&client.date_of_rent.day,&client.date_of_rent.month,&client.date_of_rent.year);
    printf("\nEnter rental time: ");
    scanf("%d:%d",&client.rental_time.hours ,&client.rental_time.minutes);
    return client;
}

/*Reset a given index in the array*/
void resetClient(int index){
    strcpy(client_array[index].name, "\0");
    strcpy(client_array[index].last_name, "\0");
    strcpy(client_array[index].id, "\0");
    strcpy(client_array[index].license_number, "\0");
    client_array[index].rental_price = -1;
    client_array[index].date_of_rent.day = -1;
    client_array[index].date_of_rent.month = -1;
    client_array[index].date_of_rent.year = -1;
    client_array[index].rental_time.hours = -1;
    client_array[index].rental_time.minutes = -1;
}

/*Function that gets the max number and creates a reset array of the clients of the company*/
void createClientsList(){
    int i = 0;
    for (i = 0; i < M; i++){
        resetClient(i);
	}
	clientCounter = 0;
}

/*Function that get the id of the client and deletes him from the system*/
bool deleteClient(char* id){
    int i = 0;
    if(strcmp(id, client_array[clientCounter -1].id) == 0){
        resetClient(clientCounter -1);
        clientCounter --;
        return true;
    }

    for(i = 0; i < clientCounter -1; i++){
        if (strcmp(id, client_array[i].id) == 0){
        /*Move the last one to the deleted one and reduce the count by 1*/
        client_array[i] = client_array[clientCounter -1];
        resetClient(clientCounter -1);
        clientCounter--;
        return true;    
        }
    }
    printf("The entered id does not exist\n");
    return false;
}

/*Function that goes over all of the existing clients and resetting them*/
void deleteAllClients(){
    int i = 0;
    for(i = 0; i < clientCounter; i++){
        resetClient(i);
	}
	clientCounter = 0;
}