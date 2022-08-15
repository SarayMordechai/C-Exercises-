#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "car.h"

/*Function that creates a new tree of cars*/
treeRootCar createCarTree(){
    treeRootCar root = malloc(sizeof(treeRootCar));
    if(!root){
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(treeRootCar));
        exit(-1);
    }
    strcpy(root->car.license_number, "/0");
    root->car.shield_number = -1;
    strcpy(root->car.manuacturer, "/0");
    strcpy(root->car.model, "/0");
    strcpy(root->car.color, "/0");
    root->car.production_year = -1;
    root->car.ascent_year = -1;
    root->car.supplier_price = -1;
    root->car.car_price = -1;
    root->car.engine_capacity = -1;
    root->left = NULL;
    root->right = NULL;

    return root;
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

treeRootCar addCarNode(treeRootCar tree, Car car){
    if(!tree){
        treeRootCar new_node = (treeRootCar)malloc(sizeof(Car_tree));
        if(!new_node) {
            fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__, __LINE__, sizeof(Car_tree));
            exit(-1);
    }
        new_node->car = car;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if (car.shield_number == (tree->car.shield_number)){ /*value is already in*/
        printf("Car with this sheild number already exist \n");
        return tree;
    }
    
    if(car.shield_number < (tree->car.shield_number)){ /* Go left */
        tree->left = addCarNode(tree->left, car);
    }else{ /* Go right */
        tree->right = addCarNode(tree->right, car);
    }

    return tree;
}

/*Function that get a shield number and deletes a specific car*/
Car_tree* deleteCar(Car_tree *tree, int shield_number){
    if(tree == NULL){
        return NULL;
    }

    /*look for the target node*/
    if(tree->car.shield_number != shield_number){
        if(shield_number < tree->car.shield_number){ /*Go left*/
            tree->left = deleteCar(tree->left, shield_number);
        }
        else{ /*go right, key > (tree->key)*/
            tree->right = deleteCar(tree->right, shield_number);
        }
        return tree;
    }

    /* Option 1: If the node is a "leaf" (has no childrens) remove this node*/
    if(!(tree->left) && !(tree->right)) {
        free(tree);
        return NULL;
    }else if(!(tree->left)){ /* Option 2: node has only one child (right) */
        treeRootCar temp = tree->right;
        free(tree);
        return temp;
    } else if(!(tree->right)) { /* Option 2: node has only one child (left)*/
        treeRootCar temp = tree->left;
        free(tree);
        return temp;
    }else { /* Option 3: node has 2 children */
        treeRootCar x = tree->right;
        treeRootCar* xparent = &(tree->right);
        while(x->left) {
            xparent = &(x->left);
            x=x->left;
        }
        tree->car = x->car;
        *xparent = deleteCar(x, x->car.shield_number);
    }

    return tree;
}

/*Gets the root and deletes(free) all the nodes in the tree*/
void deleteAllCars(Car_tree* node){
    if(!(node)) return;/* if the first node is NULL return*/

    /*delete both subtrees*/
    if(node->left != NULL){
        deleteAllCars(node->left);
    }

    if(node->right != NULL){
        deleteAllCars(node->right);
    }

    /*delete the node */
    free(node);
}

int carNumberWithGivenCapacity(Car_tree *tree ,int wanted_engine_capacity){
    int counterOfCarCapacity = 0;
    if(!tree){
        return 0;
    }
    if(tree->car.engine_capacity == wanted_engine_capacity){
        counterOfCarCapacity++;
    }
    return counterOfCarCapacity + carNumberWithGivenCapacity(tree->left , wanted_engine_capacity) + carNumberWithGivenCapacity(tree->right , wanted_engine_capacity);
}