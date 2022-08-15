#include <stdio.h>

#ifndef CLIENT_H /*Checks that it has not been defined before*/
#define CLIENT_H

/*Max values of the fileds*/
#define MAX_LENGHT 20
#define ID_LENNGHT 9
#define RENTAL_PRICE_24 3
#define LICENSE_NUMBER_LENGHT 10

/*A struct of a client with the required fields*/
struct Client {
  char* name[MAX_LENGHT];
  char* lastname[MAX_LENGHT];
  char* id[ID_LENNGHT];
  char* license_number[LICENSE_NUMBER_LENGHT];
  int rental_price;
  Date date_of_rent;
  Time rental_time;
};

/*Creates a struct of a date*/
typedef struct Date{
 int day;
 char month[4];
 int year;
} Date ;

/*Creates a struct of a time*/
typedef struct Time{
 int hours;
 int minutes;
} Time ;

/*Declaration of a function that creates client */
struct Client create_Client(const char* name, const char* lastname, const char* id, const char* license_number,int rental_price);

struct Client addNewClient(); /*Declaration of a function that add a new client (using create client)*/

struct Client deleteClient(char* id); /*Declaration of a function that deletes a client*/

#endif