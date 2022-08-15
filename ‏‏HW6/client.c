#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "client.h"

/*Function that creates a new tree of clients*/
treeRootClient createClientsTree(){
    treeRootClient root = malloc(sizeof(treeRootClient));
    if(!root) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(treeRootClient));
        exit(-1);
    }
    strcpy(root->client.name, "/0");
    strcpy(root->client.last_name, "/0");
    strcpy(root->client.id, "/0");
    strcpy(root->client.license_number, "/0");
    root->client.rental_price = -1;
    root->client.date_of_rent.day = -1;
    root->client.date_of_rent.month = -1;
    root->client.date_of_rent.year = -1;
    root->client.rental_time.hours = -1;
    root->client.rental_time.minutes = -1;
    root->right = NULL;
    root->left = NULL;

    return root;
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

/* newNode() allocates a new node with the given data and NULL left and right pointers. */
treeRootClient addClientNode(treeRootClient tree, Client client){
    if(!tree){
        treeRootClient new_node = (treeRootClient)malloc(sizeof(Client_tree));
        if(!new_node) {
            fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Client_tree));
            exit(-1);
        }        
        new_node->client = client;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if (strcmp(client.id, (tree->client.id)) == 0){ /*value is already in*/
        printf("Client with this id already exist \n");
        return tree;
    }
    
    if(strcmp(client.id, (tree->client.id)) < 0){ /* Go left */
        tree->left = addClientNode(tree->left, client);
    }else{ /* Go right */
        tree->right = addClientNode(tree->right, client);
    }

    return tree;
}

/*Function that get the id of the client and deletes him from the system*/
Client_tree* deleteClient(Client_tree *tree, char* id){
    if(tree == NULL){
        return NULL;
    }

    /*look for the target node*/
    if(strcmp(tree->client.id, id) != 0){
        if(strcmp(id, (tree->client.id)) < 0){ /*Go left*/
            tree->left = deleteClient(tree->left, id);
        }
        else{ /*go right, key > (tree->key)*/
            tree->right = deleteClient(tree->right, id);
        }
        return tree;
    }

    /* Option 1: If the node is a "leaf" (has no childrens) remove this node*/
    if(!(tree->left) && !(tree->right)) {
        free(tree);
        return NULL;
    }else if(!(tree->left)){ /* Option 2: node has only one child (right) */
        treeRootClient temp = tree->right;
        free(tree);
        return temp;
    } else if(!(tree->right)) { /* Option 2: node has only one child (left)*/
        treeRootClient temp = tree->left;
        free(tree);
        return temp;
    }else { /* Option 3: node has 2 children */
        treeRootClient x = tree->right;
        treeRootClient* xparent = &(tree->right);
        while(x->left) {
            xparent = &(x->left);
            x=x->left;
        }
        tree->client = x->client;
        *xparent = deleteClient(x, x->client.id);
    }

    return tree;
}

/*Gets the root and deletes(free) all the nodes in the tree*/
void deleteAllClients(Client_tree* node){
    if(!(node)) return;/* if the first node is NULL return*/

    /*delete both subtrees*/
    if(node->left != NULL){
        deleteAllClients(node->left);
    }
    if(node->right != NULL){
        deleteAllClients(node->right);
    }

    /*delete the node */
    free(node);
}

void printClientCarsForGivenRentDate(Client_tree *tree, int day, int month, int year){
    if(!tree) return;
    if(tree->client.date_of_rent.day == day && tree->client.date_of_rent.month == month &&
        tree->client.date_of_rent.year == year){
        printf("\n client: %s, " ,tree->client.name);
        printf("%s, " ,tree->client.last_name);
        printf("%s, " ,tree->client.id);
        printf("%s, " ,tree->client.license_number);
        printf("%d/%d/%d, " ,tree->client.date_of_rent.day,tree->client.date_of_rent.day,tree->client.date_of_rent.year);
        printf("%d:%d \n" ,tree->client.rental_time.hours,tree->client.rental_time.minutes);
    }
    printClientCarsForGivenRentDate(tree->right, day, month, year);
    printClientCarsForGivenRentDate(tree->left, day, month, year);
}

/* handle the finding options */
void findClient(Client_tree *clientTree){
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
            break;
        case 2:
            printf("\nEnter rental date: ");
            scanf("%d/%d/%d", &day, &month, &year);
            findClientByRentCar(list, clientTree, day, month, year);
            break;
        case 3:
            return;
        default:
            printf("wrong choise try again\n");
            break;
    }
}

/* find Client and insert to linked list*/
void findClientById(D_Llinked_List* list , Client_tree* tree , char* id){
    if(!tree) return;
    findClientById(list, tree->left, id );
    if(strcmp(id, (tree->client.id)) == 0){
        addNode(list , &tree->client );
    }
    findClientById(list , tree->right, id );
}

/* find Client and insert to linked list*/
void findClientByRentCar(D_Llinked_List* list , Client_tree* tree, int day, int month, int year){
    if(!tree) return;
    findClientByRentCar(list , tree->left, day, month, year);
    if(tree->client.date_of_rent.day == day && tree->client.date_of_rent.month == month && tree->client.date_of_rent.year == year){
        addNode(list , &tree->client );
    }
    findClientByRentCar(list , tree->right, day, month, year);
}


/* adding new client to Linked list and sort by ID */
void addNode(D_Llinked_List* list , Client* newClient ){
    char* clientId;
    Node* node = malloc(sizeof(Node));
    Node* head = list->head;
    if(!node) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Node));
        exit(-1);
    }

    head = list->head;
    clientId = newClient->id;
    node->client = *newClient;

    while( strcmp(head->client.id, clientId) < 0 ){
        if(!head->next){
            break;
        }
        head = head->next;
    }
    if(head->client.id > clientId){
        node->prev = head->prev;
        head->prev = node;
        node->next = head;
        if(!node->prev){
            head->prev->next = node;
            list->head = node;
        }
    }
    else {
        head->next = node;
        node->prev = head;
    }
}