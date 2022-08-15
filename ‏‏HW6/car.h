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

/*A struct of acar with the required fields*/
typedef struct Car{
  char license_number[LICENSE_NUMBER];
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

typedef struct Car_tree{
    Car car;
    struct Car_tree* left;
    struct Car_tree* right;
}Car_tree;

/*the root of the tree node */
typedef struct Car_tree* treeRootCar;

treeRootCar createCarTree(); /*Declaration of a function that creates a list of cars*/

Car getCarFieldsFromUser();/*Function that gets all the fields of a car from the user*/

treeRootCar addCarNode(treeRootCar tree, Car car);

Car_tree* deleteCar(Car_tree *tree, int shield_number);/*Declaration of a function that deletes a car according to his shield number*/

void deleteAllCars(Car_tree* node);/*Declaration of a function that deletes all the cars*/

int carNumberWithGivenCapacity(Car_tree *tree ,int wanted_engine_capacity);

#endif