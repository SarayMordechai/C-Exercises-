#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "car.h"

/*Function that creates a new tree of cars*/
Tree* createCarTree(){
	rootCar = CreateTree(rootCar);	
	return rootCar;
}

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

/*Comparison of 2 vehicles with shield number*/
int cmp2CarsByShieldNumber(Car* c1, Car* c2){
    if(c1->shield_number == c2->shield_number){
        return 0;
    }
    if(c1->shield_number > c2->shield_number){
        return 1;
    }
    return -1;
}

/*Comparison of 2 vehicles with engine capacity*/
int cmp2CarsByEngineCapacity(Car* c1, Car* c2){
    if(c1->engine_capacity == c2->engine_capacity){
        return 0;
    }
    if(c1->engine_capacity > c2->engine_capacity){
        return 1;
    }
    return -1;
}

/*Function that get a shield number and deletes a specific car*/
Tree* deleteCar(int shield_number){
    Compare compareFunc;
    Car *tempCar = NULL;
    tempCar->shield_number = shield_number;
	if(!rootCar){
        printf("car not exist still\n");
        return 0;
    }
    compareFunc=(Compare)cmp2CarsByShieldNumber;
    rootCar = deleteNode(rootCar , tempCar ,compareFunc);
    return rootCar;
}

/*Gets the root and deletes(free) all the nodes in the tree*/
void deleteAllCars(Tree* rootCar){
    FreeTree(rootCar);
}

/*A function that returns the number of vehicles in the company with the above volume*/
int carNumberWithGivenCapacity(Tree* tree ,int wanted_engine_capacity){
    int counterOfCarCapacity = 0;
    Car *tempCar = NULL;
    tempCar->engine_capacity = wanted_engine_capacity;
    if(!tree){
        return 0;
    }
    if(cmp2CarsByEngineCapacity(tree->val,tempCar) == 0){
        counterOfCarCapacity++;
    }
    return counterOfCarCapacity + carNumberWithGivenCapacity(tree->left , wanted_engine_capacity) + carNumberWithGivenCapacity(tree->right , wanted_engine_capacity);
}