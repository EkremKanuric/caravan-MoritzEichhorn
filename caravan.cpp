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
  caravan->head = 0;
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
  int length = get_length(caravan);

  for(int i = 0; i < length; i++){
    Node* head = caravan->head;
    caravan->head = head->next;
    sfree(head);
  }

  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if((animal == 0) || (animal->caravan == caravan)){
    return;
  }
  if(animal->caravan != 0){
    remove_pack_animal(animal->caravan, animal);
  }

  animal->caravan = caravan;
  Node* new_node = (Node*)malloc(sizeof(Node));

  new_node->pack_animal = animal;
  new_node->next = caravan->head;
  caravan->head = new_node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node* crnt_node = caravan->head;

  if(crnt_node == 0 || animal == 0){
    return;
  }

  animal->caravan = 0;
  if(crnt_node->pack_animal == animal){
    caravan->head = crnt_node->next;
    sfree(crnt_node);
    return;
  }

  while((crnt_node->next != 0) && (crnt_node->next->pack_animal != animal)){
    crnt_node = crnt_node->next;
  }

  if(crnt_node->next == 0){
    return;
  }

  Node* node_next = crnt_node->next;
  crnt_node->next = node_next->next;
  sfree(node_next);
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
