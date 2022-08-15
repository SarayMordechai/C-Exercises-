#include <stdio.h>
#include <stdbool.h>

#ifndef CAR_H /*Checks that it has not been defined before*/
#define CAR_H

/*Max values of the fileds*/
#define NUMBER_OF_FiELDS_CAR 10
#define LICENSE_NUMBER 7
#define SHIELD_NUMBER 5 
#define PRODUCTION_YEAR 4
#define ASCENT_YEAR 4
#define MAX_SUPPLIER_PRICE 7 
#define MAX_CAR_PRICE 7
#define ENGINE_CAPACITY 4
/*check manuacturer is one word------------------------------- */

/*A struct of acar with the required fields*/
typedef struct Car{
  char* license_number;
  int shield_number;
  char* manuacturer;
  char* model;
  char* color;
  int production_year;
  int ascent_year;
  int supplier_price;
  int car_price;
  int engine_capacity;
}Car;

typedef struct nodeCar{
    Car* car;
    struct nodeCar *next;
}nodeCar;

typedef struct carList{
 struct nodeCar* head;
  struct nodeCar* tail;
  int carCounter;
}carList;

nodeCar* carHead;
nodeCar* carHead2;
nodeCar* prevNode;
nodeCar* curNode;
Car* temp_car;

Car getCarFieldsFromUser();/*Function that gets all the fields of a car from the user*/

void printCarsList(struct carList carList);

struct carList createCarList(); /*Declaration of a function that creates a list of cars*/

bool deleteCar(struct carList carList ,int shield_number);/*Declaration of a function that deletes a car according to his shield number*/

bool deleteAllCars(struct carList carList);/*Declaration of a function that deletes all the cars*/

int carNumberWithGivenCapacity(struct carList carList ,int wanted_engine_capacity);  /*Declaration of a function that gets a given capacity and returns the number of cars that has it*/

void inverseCarList(struct carList carList);

#endif