#include <stdio.h>
#include <stdbool.h>

#ifndef CLIENT_H /*Checks that it has not been defined before*/
#define CLIENT_H

/*Max values of the fileds*/
#define NUMBER_OF_FiELDS_CLIENT 7
#define ID_LENGTH 9
#define RENTAL_PRICE 3
#define RENTAL_PRICE_MAX_DIGITS 3

/*Date & Time max values*/
#define ZERO_MIN 0
#define ONE_MIN 1
#define MAX_MONTH 12
#define MAX_DAY 31
#define MAX_HOUR 23
#define MAX_MINUTE 59

/*Creates a struct of a date*/
typedef struct Date{
 int day;
 int month;
 int year;
}Date;

/*Creates a struct of a time*/
typedef struct Time{
 int hours;
 int minutes;
}Time;

/*A struct of a client with the required fields*/
typedef struct Client {
  char* name;
  char* last_name;
  char* id;
  char* license_number;
  int rental_price;
  Date date_of_rent;
  Time rental_time;
}Client;

typedef struct Client_tree{
    Client client;
    struct Client_tree* left;
    struct Client_tree* right;
}Client_tree;

/*Linked List*/
typedef struct Node_t{
    Client client;
    struct Node_t* prev;
    struct Node_t* next;
}Node;


typedef struct {
    Node* head;
}D_Llinked_List;


/*the root of the tree node */
typedef struct Client_tree* treeRootClient;

treeRootClient createClientsTree(); /*Declaration of a function that creates a list of clients*/

Client getClientFieldsFromUser();/*Function that gets all the fields of a client from the user*/

treeRootClient addClientNode(treeRootClient tree, Client client);

Client_tree* deleteClient(Client_tree *tree,char* id); /*Declaration of a function that deletes a client*/

void deleteAllClients(Client_tree* node); /*Declaration of a function deletes all the clients*/

void printClientCarsForGivenRentDate(Client_tree *tree, int day, int month, int year);

void findClient( Client_tree *clientTree);

void findClientById(D_Llinked_List* list , Client_tree* tree , char* id);

void findClientByRentCar(D_Llinked_List* list , Client_tree* tree, int day, int month, int year);

void addNode(D_Llinked_List* list , Client* newClient );

#endif