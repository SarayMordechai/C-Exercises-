#include <stdio.h>
#include <stdbool.h>

#ifndef CLIENT_H /*Checks that it has not been defined before*/
#define CLIENT_H

/*Max values of the fileds*/
#define NUMBER_OF_FiELDS_CLIENT 7
#define MAX_NAME_LENGHT 20
#define ID_LENGTH 9
#define RENTAL_PRICE 3
#define LICENSE_NUMBER_LENGHT 10
#define RENTAL_PRICE_MAX_DIGITS 3
#define M 80 /*Need to change*/

/*Date & Time max values*/
#define ZERO_MIN 00
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
  char name[MAX_NAME_LENGHT + 1];
  char last_name[MAX_NAME_LENGHT + 1];
  char id[ID_LENGTH + 1];
  char license_number[LICENSE_NUMBER_LENGHT + 1];
  int rental_price;
  Date date_of_rent;
  Time rental_time;
}Client;

int clientCounter; /*Counter of clients*/ 
Client client_array[M]; /*Definition of an array of clients*/

Client getClientFieldsFromUser();/*Function that gets all the fields of a client from the user*/

void resetClient(int indexToRemove);/*Function that reset a client in an given index*/

void createClientsList(); /*Declaration of a function that creates a list of clients*/

bool deleteClient(char* id); /*Declaration of a function that deletes a client*/

void deleteAllClients(); /*Declaration of a function deletes all the clients*/

#endif