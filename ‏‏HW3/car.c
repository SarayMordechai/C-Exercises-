#include <stdio.h>
#include <string.h>
#include "car.h"

/*Funcation that gets all the parameters from the user and creates an instance of a car from the struct*/
struct Car Create_Car(int license_number,int shield_number,const char* manuacturer,
                     const char* model,const char* color,int production_year,int ascent_year,
                      int price_supplier , int car_price ,int enging_capacity ){
    struct Car c;
    c.license_number = license_number;
    c.shield_number = shield_number;
    c.production_year = production_year;
    c.ascent_year = ascent_year;
    c.supplier_price = price_supplier;
    c.car_price = car_price;
    c.engine_capacity = enging_capacity;
    strcpy(c.manuacturer, manuacturer);
    strcpy(c.model ,model);
    strcpy(c.color,color);

        return c;
    }

/*Function that adds a car using create car funcation*/
struct Car addNewCar(){
    /* data */
}

/*Function that get a shield number and deletes a specific car*/
struct Car deleteCar(int shield_number){
    struct Car ca;
    ca.shield_number = shield_number;
    return ca;    
}