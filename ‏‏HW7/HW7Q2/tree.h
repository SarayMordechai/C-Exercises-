#ifndef	TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ALLOC(typ,no) ((typ *) checked_malloc(sizeof(typ)*(no)))

/*Max values of the fileds*/
#define NUMBER_OF_FiELDS_CAR 10
#define LICENSE_NUMBER 7
#define SHIELD_NUMBER 5 
#define PRODUCTION_YEAR 4
#define ASCENT_YEAR 4
#define MAX_SUPPLIER_PRICE 7 
#define MAX_CAR_PRICE 7
#define ENGINE_CAPACITY 4

/*Max values of the fileds*/
#define K 50
#define NUMBER_OF_FiELDS_SUPLLIER 5
#define DEALER_NUMBER 10
#define SUPPLIER_PHONE 10
#define NUMBER_OF_TRANSACTIONS 5
#define TRANSACTIONS_SUM 10

/*Max values of the fileds*/
#define NUMBER_OF_FiELDS_CLIENT 7
#define ID_LENGTH 9
#define RENTAL_PRICE 3
#define RENTAL_PRICE_MAX_DIGITS 3

/*Date & Time max values*/
#define ZERO_MIN 0
#define ONE_MIN 1
#define MAX_MONTH 12
#define MAX_DAY 31
#define MAX_HOUR 23
#define MAX_MINUTE 59

typedef struct Tree{
	void * val;
	struct Tree * left;
	struct Tree * right;
}Tree;

typedef struct node{
	void * val;
	struct node *next;
}GenNode;

/*Creates a struct of a date*/
typedef struct Date{
 int day;
 int month;
 int year;
}Date;

/*Creates a struct of a time*/
typedef struct Time{
 int hours;
 int minutes;
}Time;

typedef struct {
    GenNode* head;
}D_Llinked_List;

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

/*A struct of a supplier with the required fields*/
typedef struct Supplier {
  char* dealer_number;
  char* supplier_name;
  char* supplier_phone;
  int number_of_transactions;
  int transactions_sum;
}Supplier;

/*A struct of a client with the required fields*/
typedef struct Client {
  char* name;
  char* last_name;
  char* id;
  char* license_number;
  int rental_price;
  Date date_of_rent;
  Time rental_time;
}Client;


Tree* rootCar;
Tree* rootSupplier;
Tree* rootClient;


typedef double (*Average)(Tree *);
typedef void ** (*ArrayKind) (Tree *,void **,int position);
typedef int(*Compare)(void*,void*);
typedef void (*Print)(void*);

Tree* CreateTree(Tree* tree);
Tree* add_new_node(Tree * root,void * val,int (*fcmp)(void *,void *));
GenNode* find_node(Tree * root,void * val, int(*fcmp)(void *,void *));
Tree* deleteNode(Tree* root, void* key, Compare cmp);
void * find_in_tree(Tree * root, void * val, int(*fcmp)(void *,void *));
double average_key(Tree * root, int * num_of_nodes,Average getAvg);
void ** tree_to_array(Tree * root,void ** treeArray,int * counter,ArrayKind addToArray);
void print_tree(Tree* root, Print p);
void FreeTree(Tree* t);
void *checked_malloc(unsigned int);
GenNode* connect_list(GenNode* l1,GenNode* l2);
GenNode* add_to_list(GenNode* list,void* val);
int	Find_Number_Of_Nodes(Tree * root);
#endif