#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "car.h"

/*Get all th fields of a car from the user*/
Car getCarFieldsFromUser(){
    Car car;
    printf("\nEnter license number: ");
    scanf("%s", car.license_number);
    printf("\nEnter shield number: ");
    scanf("%d", &car.shield_number );
    printf("\nEnter manuacturer: ");
    scanf("%s", car.manuacturer);
    printf("\nEnter model: ");
    scanf("%s", car.model);
    printf("\nEnter car color: ");
    scanf("%s", car.color);
    printf("\nEnter production year: ");
    scanf("%d", &car.production_year);
    printf("\nEnter ascent year: ");
    scanf("%d", &car.ascent_year);
    printf("\nEnter supplier price: ");
    scanf("%d", &car.supplier_price);
    printf("\nEnter car price: ");
    scanf("%d", &car.car_price);
    printf("\nEnter enginge capacity: ");
    scanf("%d", &car.engine_capacity);

    return car;
}

/*Reset a given index in the array*/
void resetCar(int indexToRemove){
    strcpy(car_array[indexToRemove].license_number, "\0");
    car_array[indexToRemove].shield_number = -1;
    strcpy(car_array[indexToRemove].manuacturer , "\0");
    strcpy(car_array[indexToRemove].model, "\0");
    strcpy(car_array[indexToRemove].color, "\0");
    car_array[indexToRemove].production_year = -1;
    car_array[indexToRemove].ascent_year = -1;
    car_array[indexToRemove].supplier_price = -1;
    car_array[indexToRemove].car_price = -1;
    car_array[indexToRemove].engine_capacity = -1;
}

/*Function that sets an array of cars in the length of N (using add new supplier)*/
void createCarList(){
    int i = 0;
	for (i = 0; i < N; i++){
        resetCar(i);
	}
	carCounter = 0;
}

/*Function that get a shield number and deletes a specific car*/
bool deleteCar(int shield_number){
    int i=0;
    if(shield_number == car_array[carCounter -1].shield_number){
        resetCar(carCounter -1);
        carCounter --;
        return true;
    }
    for(i =0; i < carCounter -1; i++){
        if (shield_number == car_array[i].shield_number){
        /*Move the last one to the deleted one and reduce the count by 1*/
        car_array[i] = car_array[carCounter -1];
        resetCar(carCounter -1);
        carCounter--;
        return true;    
        }
    }
    printf("The entered shield number does not exist\n");
    return false;
}

/*Function that goes over all of the existing cars and resetting them*/
void deleteAllCars(){
    int i = 0;
    for (i = 0; i < carCounter; i++){
        resetCar(i);
	}
	carCounter = 0;
}