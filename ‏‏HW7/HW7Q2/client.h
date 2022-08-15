#include <stdio.h>
#include <stdbool.h>
#include "tree.h"

#ifndef CLIENT_H /*Checks that it has not been defined before*/
#define CLIENT_H

Tree* createClientsTree(); /*Declaration of a function that creates a list of clients*/

Client getClientFieldsFromUser();/*Function that gets all the fields of a client from the user*/

int cmp2ClientsByid(Client* c1, Client* c2); /*Comparison between 2 clients with Id number*/

Tree* deleteClient(char* id); /*Declaration of a function that deletes a client*/

void deleteAllClients(Tree* rootClient); /*Declaration of a function deletes all the clients*/

void printClientCarsForGivenRentDate(Tree *tree, int day, int month, int year);/*Print a list of all customers with their vehicle number*/


/*Function that finds a client by ID or car rental date and puts them in a linked list in a sorted way*/
void findClient(Tree *clientTree);

void findClientById(D_Llinked_List* list , Tree* tree , char* id);

void findClientByRentCar(D_Llinked_List* list , Tree* tree, int day, int month, int year);

void SortLinkedList(D_Llinked_List* list);

#endif