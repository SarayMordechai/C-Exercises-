#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "client.h"

/*Get all th fields of a client from the user*/
Client getClientFieldsFromUser(struct ClientList clientList){

    Client* client = (Client*)malloc(sizeof(Client*));
        if(!client) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Client));
        exit(-1);
        }

    printf("\nEnter client name: ");
    scanf("%s", client->name);
    printf("\nEnter client last name: ");
    scanf("%s", client->last_name);
    printf("\nEnter id: ");
    scanf("%s", client->id);
    printf("\nEnter license number: ");
    scanf("%s", client->license_number);
    printf("\nEnter rental price: ");
    scanf("%d" , &client->rental_price);
    printf("\nEnter rental date: ");
    scanf("%d/%d/%d", &client->date_of_rent.day, &client->date_of_rent.month, &client->date_of_rent.year);
    printf("\nEnter rental time: ");
    scanf("%d:%d", &client->rental_time.hours, &client->rental_time.minutes);
    return *client;
}


struct ClientList createClientList(){
   struct nodeClient* head = NULL; 
   struct nodeClient* tail = NULL; 
   struct ClientList* clientList1 = NULL;

 head = (struct nodeClient*)malloc(sizeof(struct nodeClient));
    if(!head) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Client));
        exit(-1);
    }
 tail = (struct nodeClient*)malloc(sizeof(struct nodeClient));
    if(!tail) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Client));
        exit(-1);
    }

    head->next = tail;

clientList1 = (ClientList*)malloc(sizeof(ClientList));
    if(!clientList1) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Client));
        exit(-1);
    }
    
    clientList1->head = head;
    clientList1->tail = tail;
    clientList1->clientCounter = 0;

    return *clientList1;
}



/*Function that get the id of the client and deletes him from the system*/
bool deleteClient(struct ClientList clientList,char* id){
    if(clientList.head->next != NULL){
        while(clientList.head == clientList.tail){
            if (clientList.head->next->client->id == id){
                clientList.head->next = clientList.head->next->next;
                free(clientList.head->next->client);
                free(clientList.head->next);
                clientList.clientCounter--;
                return true;
            }
        }
    }
    printf("Client does not exist \n");
    return false;
}


void deleteAllClients(struct ClientList clientList){
    while(clientList.head != NULL){
        clientList.head->next = clientList.head->next->next;
        free(clientList.head->next->client);
        free(clientList.head->next);
    }
    clientList.clientCounter = 0;
}


void print_clients(struct ClientList clientList){
    clientHead = clientList.head;
    printf("client: %s, " ,clientHead->client->name);
    printf("%s, " ,clientHead->client->last_name);
    printf("%s, " ,clientHead->client->id);
    printf("%s, " ,clientHead->client->license_number);
    printf("%d, " ,clientHead->client->rental_price);
    printf("%d/%d/%d, " ,clientHead->client->date_of_rent.day,clientHead->client->date_of_rent.month,clientHead->client->date_of_rent.year);
    printf("%d:%d\n" ,clientHead->client->rental_time.hours,clientHead->client->rental_time.minutes);
}

void printClientCarsForGivenRentDate(struct ClientList clientList){
    int day,month,year;
    printf("\nEnter rental date: ");
    scanf("%d/%d/%d", &day, &month, &year);
    clientHead = clientList.head;
    while(clientHead == NULL){
        if(clientHead->client->date_of_rent.day == day && clientHead->client->date_of_rent.month == month &&
        clientHead->client->date_of_rent.year == year){
            printf("client: %s, " ,clientHead->client->name);
            printf("%s, " ,clientHead->client->last_name);
            printf("%s, " ,clientHead->client->id);
            printf("%s, " ,clientHead->client->license_number);
            printf("%d, " ,clientHead->client->rental_price);
            printf("%d/%d/%d, " ,clientHead->client->date_of_rent.day,clientHead->client->date_of_rent.month,clientHead->client->date_of_rent.year);
            printf("%d:%d\n" ,clientHead->client->rental_time.hours,clientHead->client->rental_time.minutes);
        }
        clientHead = clientHead->next;
    }
}