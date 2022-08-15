#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "client.h"

/*Function that creates a new tree of clients*/
Tree* createClientsTree(){
	rootClient = CreateTree(rootClient);	
	return rootClient;
}

/*Get all the fields of a client from the user*/
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

/*Comparison between 2 clients with Id number*/
int cmp2ClientsByid(Client* c1, Client* c2){
    if(strcmp(c1->id, c2->id) == 0){
        return 0;
    }else if(strcmp(c1->id, c2->id) > 0){
        return 1;
    }
    return -1;
}

/*Function that get the id of the client and deletes him from the system*/
Tree* deleteClient(char* id){
    Compare compareFunc;
    Client *tempClient = NULL;
    tempClient->id = id;
	if(!rootClient){
        printf("client does not exist still\n");
        return 0;
    }
    compareFunc = (Compare)cmp2ClientsByid;
    rootClient = deleteNode(rootClient , tempClient ,compareFunc);
    return rootClient;
}

/*Gets the root and deletes(free) all the nodes in the tree*/
void deleteAllClients(Tree* rootClient){
    FreeTree(rootClient);
}

/*Print a list of all customers with their vehicle number*/
void printClientCarsForGivenRentDate(Tree *tree, int day, int month, int year){
    Client* client = tree->val;
    if(!tree){ 
        return;
    }
    if(client->date_of_rent.day == day && client->date_of_rent.month == month &&
        client->date_of_rent.year == year){
        printf("\n client: %s, " ,client->name);
        printf("%s, " ,client->last_name);
        printf("%s, " ,client->id);
        printf("%s, " ,client->license_number);
        printf("%d/%d/%d, " ,client->date_of_rent.day,client->date_of_rent.day,client->date_of_rent.year);
        printf("%d:%d \n" ,client->rental_time.hours,client->rental_time.minutes);
    }
    printClientCarsForGivenRentDate(tree->right, day, month, year);
    printClientCarsForGivenRentDate(tree->left, day, month, year);
}

/*Function that finds a client by ID or car rental date and puts them in a linked list in a sorted way*/
/* handle the finding options */
void findClient(Tree* clientTree){
    D_Llinked_List *list = NULL;
    int day, month, year, option;
    char* id = " ";
    printf("\nHow do you want to find\n");
    printf("[1] Client ID\n");
    printf("[2] date to rent\n");
    printf("[3] Go back\n");
    scanf("%d", &option);
    switch (option){
        case 1:
            printf("\nEnter id: ");
            scanf("%s", id);
            findClientById(list, clientTree, id);
            SortLinkedList(list);
            break;
        case 2:
            printf("\nEnter rental date: ");
            scanf("%d/%d/%d", &day, &month, &year);
            findClientByRentCar(list, clientTree, day, month, year);
            SortLinkedList(list);
            break;
        case 3:
            return;
        default:
            printf("wrong choise try again\n");
            break;
    }
}

/* find Client and insert to linked list*/
void findClientById(D_Llinked_List* list , Tree* tree , char* id){
    Client* client = tree->val;
    if(!tree){
        return;
    }

    findClientById(list, tree->left, id );
    if(strcmp(id, (client->id)) == 0){
        add_to_list(list->head , &client );
    }
    findClientById(list , tree->right, id );
}

/* find Client and insert to linked list*/
void findClientByRentCar(D_Llinked_List* list , Tree* tree, int day, int month, int year){
    Client* client = tree->val;
    if(!tree){
        return;
    }

    findClientByRentCar(list , tree->left, day, month, year);
    if(client->date_of_rent.day == day && client->date_of_rent.month == month && client->date_of_rent.year == year){
        add_to_list(list->head , &client );
    }
    findClientByRentCar(list , tree->right, day, month, year);
}
/*Sort a linked list*/
void SortLinkedList(D_Llinked_List* list){
    GenNode* tempL = NULL, *temp = NULL;
    Client* tempvar;/*temp variable to store node data*/
    tempL = list->head;
    while(tempL != NULL){
        temp = tempL;
        /*travel till the second last element*/ 
        while(temp->next !=NULL){
            if(cmp2ClientsByid(temp->val, temp->next->val) == 1){/* compare the data of the nodes*/ 
                tempvar = temp->val;
                temp->val = temp->next->val;/*swap the data*/
                temp->next->val = tempvar;
            }
            temp = temp->next;    /*move to the next element*/ 
        }
        tempL = tempL->next;
    }
}