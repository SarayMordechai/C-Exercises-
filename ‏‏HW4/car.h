#include <stdio.h>
#include <stdbool.h>

#ifndef CAR_H /*Checks that it has not been defined before*/
#define CAR_H

/*Max values of the fileds*/
#define NUMBER_OF_FiELDS_CAR 10
#define LICENSE_NUMBER 7
#define SHIELD_NUMBER 5 
#define MANUACTURER_MAX 10
#define MODEL_MAX 10
#define COLOR_MAX 7
#define PRODUCTION_YEAR 4
#define ASCENT_YEAR 4
#define MAX_SUPPLIER_PRICE 7 
#define MAX_CAR_PRICE 7
#define ENGINE_CAPACITY 4
#define N 10 /*Temp value*/

/*A struct of acar with the required fields*/
typedef struct Car{
  char license_number[LICENSE_NUMBER];
  int shield_number;
  char manuacturer[MANUACTURER_MAX + 1];
  char model[MODEL_MAX + 1];
  char color[COLOR_MAX + 1];
  int production_year;
  int ascent_year;
  int supplier_price;
  int car_price;
  int engine_capacity;
}Car;

int carCounter; /*Counter of cars*/
Car car_array[N]; /*Definition of an array of cars*/

Car getCarFieldsFromUser();/*Function that gets all the fields of a car from the user*/

void resetCar(int indexToremove);/*Function that reset a car in an given index*/

void createCarList(); /*Declaration of a function that creates a list of cars*/

bool deleteCar(int shield_number);/*Declaration of a function that deletes a car according to his shield number*/

void deleteAllCars();/*Declaration of a function that deletes all the cars*/

#endif