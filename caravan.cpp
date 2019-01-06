/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include <stdlib.h>

typedef struct _node{
  PackAnimal pack_animal;
  struct _node* next;
}Node;

struct CaravanImplementation{
  Node* head;
};

struct PackAnimalImplementation {
	AnimalType type;
	const char *name;
	int max_speed;
	int load;
	Caravan caravan;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  get_free_list()[get_free_list_length()] = caravan;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count = 0;

  Node* crnt_node = caravan->head;
  while(crnt_node != 0){
    count++;
    crnt_node = crnt_node->next;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal->caravan == caravan){
    return;
  }
  if(animal->caravan != 0){

  }

  Node* new_node = (Node*)malloc(sizeof(Node));

  new_node->pack_animal = animal;
  new_node->next = caravan->head;
  caravan->head = new_node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}
