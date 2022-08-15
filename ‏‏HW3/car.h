#include <stdio.h>

#ifndef CAR_H /*Checks that it has not been defined before*/
#define CAR_H

/*Max values of the fileds*/
#define LICENSE_NUMBER 7
#define SHIELD_NUMBER 5 
#define MANUACTURER_MAX 10
#define MODEL_MAX 10
#define COLOR_MAX 7
#define PRODUCTION_YEAR 4
#define ASCENT_YEAR 4
#define MAX_SUPPLIER_PRICE 7 
#define MAX_CAR_PRICE 7
#define ENGING_CAPACITY 4

/*A struct of acar with the required fields*/
struct Car {
  int license_number;
  int shield_number;
  char* manuacturer[MANUACTURER_MAX];
  char* model[MODEL_MAX];
  char* color[COLOR_MAX];
  int production_year;
  int ascent_year;
  int supplier_price;
  int car_price;
  int engine_capacity;
};

/*Declaration of a function that creates a car*/
struct Car create_Car(int license_number,int chassis_number,const char* manuacturer,
                     const char* model,const char* color,int production_year,int ascent_year,
                      int price_supplier ,int car_price ,int enging_capacity);

struct Car addNewCar(); /*Declaration of a function that add a new car (using create car)*/

struct Car deleteCar(int shield_number); /*Declaration of a function that deletes a car according to his shield number*/

#endif