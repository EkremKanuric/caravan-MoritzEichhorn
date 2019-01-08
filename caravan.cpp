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
  if((animal == 0) || (get_caravan(animal) == caravan)){
    return;
  }
  if(get_caravan(animal) != 0){
    remove_pack_animal(get_caravan(animal), animal);
  }

  add_to_caravan(animal, caravan);
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

  remove_from_caravan(animal, caravan);
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
  int length = get_length(caravan);
  int load_count = 0;
  Node* crnt_node = caravan->head;

  for(int i = 0; i < length; i++){
    load_count += get_load(crnt_node->pack_animal);
    crnt_node = crnt_node->next;
  }
  return load_count;
}

void unload(Caravan caravan)
{
  int length = get_length(caravan);

  Node* crnt_node = caravan->head;

  for(int i = 0; i < length; i++){
    unload(crnt_node->pack_animal);
    crnt_node = crnt_node->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  int lowest_speed = 51; //50 weil kein Tier schneller als 50 sein kann
  int length = get_length(caravan);

  Node* crnt_node = caravan->head;

  for(int i = 0; i < length; i++){
    if(get_actual_speed(crnt_node->pack_animal) < lowest_speed){
      lowest_speed = get_actual_speed(crnt_node->pack_animal);
    }
    crnt_node = crnt_node->next;
  }

  if(lowest_speed == 51){
    lowest_speed = 0;
  }
  return lowest_speed;
}
