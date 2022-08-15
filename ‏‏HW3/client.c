#include <stdio.h>
#include <string.h>
#include "client.h"

/*Funcation that gets all the parameters from the user and creates an instance of a client from the struct*/
struct Client create_Client(const char* name, const char* lastname, const char* id, const char* license_number,int rental_price){
    struct Client c;
    strcpy(c.name ,name);
    strcpy(c.lastname ,lastname);
    strcpy(c.id ,id);
    strcpy(c.license_number ,license_number);
    c.rental_price = rental_price;

    return c;
}

/*Function that adds a new client (using create client)*/
struct Client addNewClient(){
    /* data */
}

/*Function that get the id of the client and deletes him from the system*/
struct Client deleteClient(char* id){
    struct Client cl;
    strcpy(cl.id, id);

    return cl;  
}