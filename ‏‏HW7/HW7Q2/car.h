#include <stdio.h>
#include <stdbool.h>

#ifndef CAR_H /*Checks that it has not been defined before*/
#define CAR_H
#include "tree.h"


Tree* createCarTree(); /*Declaration of a function that creates a list of cars*/

Car getCarFieldsFromUser();/*Function that gets all the fields of a car from the user*/

Tree* deleteCar(int shield_number);/*Declaration of a function that deletes a car according to his shield number*/

void deleteAllCars(Tree* rootCar);/*Declaration of a function that deletes all the cars*/

int cmp2CarsByShieldNumber(Car* c1, Car* c2);/*Comparison of 2 vehicles with engine capacity*/

int carNumberWithGivenCapacity(Tree* tree ,int wanted_engine_capacity);/*A function that returns the number of vehicles in the company with the above volume*/

#endif