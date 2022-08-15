#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "car.h"

/*Get all th fields of a car from the user*/
Car getCarFieldsFromUser(){

    Car* car = (Car*)malloc(sizeof(Car*));
    if(!car) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Car));
        exit(-1);
    }

    printf("\nEnter license number: ");
    scanf("%s", car->license_number);
    printf("\nEnter shield number: ");
    scanf("%d", &car->shield_number);
    printf("\nEnter manuacturer: ");
    scanf("%s", car->manuacturer);
    printf("\nEnter model: ");
    scanf("%s", car->model);
    printf("\nEnter car color: ");
    scanf("%s", car->color);
    printf("\nEnter production year: ");
    scanf("%d", &car->production_year);
    printf("\nEnter ascent year: ");
    scanf("%d", &car->ascent_year);
    printf("\nEnter supplier price: ");
    scanf("%d", &car->supplier_price);
    printf("\nEnter car price: ");
    scanf("%d", &car->car_price);
    printf("\nEnter enginge capacity: ");
    scanf("%d", &car->engine_capacity);
    return *car;
}

/*Function that sets an array of cars in the length of N (using add new supplier)*/
struct carList createCarList(){
   struct nodeCar* head = NULL; 
   struct nodeCar* tail = NULL; 
   struct carList* carList1 = NULL;

 head = (struct nodeCar*)malloc(sizeof(struct nodeCar));
    if(!head) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Car));
        exit(-1);
    }
 tail = (struct nodeCar*)malloc(sizeof(struct nodeCar));
    if(!tail) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Car));
        exit(-1);
    }
    head->next = tail;

 carList1 = (carList*)malloc(sizeof(carList));
    if(!carList1) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Car));
        exit(-1);
    }

    carList1->head = head;
    carList1->tail = tail;
    carList1->carCounter = 0;

    return *carList1;
}



/*Function that get a shield number and deletes a specific car*/
bool deleteCar(struct carList carList ,int shield_number){
    if(carList.head->next != NULL){
        while (carList.head == carList.tail){
            if(carList.head->next->car->shield_number == shield_number){
                carList.head->next = carList.head->next->next;
                free(carList.head->next->car);
                free(carList.head->next);
                carList.carCounter = 0;
                return true;
            }
        }
    }
    printf("Car does not exist \n");
    return false;
}

/*Function that goes over all of the existing cars and resetting them*/
bool deleteAllCars(struct carList carList){
    while(carList.head != NULL){
        carList.head->next = carList.head->next->next;
        free(carList.head->next->car);
        free(carList.head->next);
    }
    if(carList.head == NULL){
        return true;
    }
    return false;
}

void printCarsList(struct carList carList){
    carHead = carList.head;
	while(carHead != NULL){
        printf("car: %s, ", carHead->car->license_number);
        printf("%d, ", carHead->car->shield_number);
        printf("%s, ", carHead->car->manuacturer);
        printf("%s, ", carHead->car->model);
        printf("%s, ", carHead->car->color);
        printf("%d, ", carHead->car->production_year);
        printf("%d, ", carHead->car->ascent_year);
        printf("%d, ", carHead->car->supplier_price);
        printf("%d, ", carHead->car->car_price);
        printf("%d \n", carHead->car->engine_capacity);
	    carHead = carHead->next;
	}
	printf("NULL\n");
}

/* gets a given capacity and returns the number of cars that has it*/
int carNumberWithGivenCapacity(struct carList carList ,int wanted_engine_capacity){
    int counterOfCarCapacity = 0;
    carHead2 = carList.head;
    while(carList.head == NULL){
        if(carHead2->car->engine_capacity == wanted_engine_capacity){
            counterOfCarCapacity += 1;
            carHead2 = carHead2->next;
        }
    }
    return counterOfCarCapacity;
}

void inverseCarList(struct carList carList){
    if(carList.head != NULL)
    {
        prevNode = carList.head;
        curNode = carList.head->next;
        carList.head = carList.head->next;

        prevNode->next = NULL; /*Make first node as last node*/

        while(carList.head != NULL)
        {
            carList.head = carList.head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = carList.head;
        }
        carList.head = prevNode; /*Make last node as head*/
    }
}

int carNumberWithGivenCapacity_REC(nodeCar* car_node ,int wanted_engine_capacity){
    int counterOfCarCapacity = 0;
    if(car_node == NULL){
        return counterOfCarCapacity;
    }
    if(car_node->car->engine_capacity == wanted_engine_capacity){
        counterOfCarCapacity++;
    }
    carNumberWithGivenCapacity_REC(car_node->next ,wanted_engine_capacity);
    return 0;
}