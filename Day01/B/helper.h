#ifndef HELPER_H
#define HELPER_H


#include <stdlib.h>

typedef struct node_tag node_t;


// Basic Linked List
typedef struct node_tag {

    int32_t num;
    node_t* next_node;

} node_t;


// Insert a number into the linked list
void InsertNumIntoList(int32_t new_num, node_t** head){

    node_t* new_node = malloc(sizeof(node_t));
    new_node->num = new_num;

    if(*head == NULL){
        
        // empty list
        // Create a new list will one node
        new_node->next_node = NULL;
        *head = new_node;

    } else {

        // loop through the list until you find the location to insert the next element
        node_t* next_node = *head;

        // Check if new node goes before the first node
        if(new_num < next_node->num){

            // Create a new list and append the old one to the end of it
            new_node->next_node = next_node;
            *head = new_node;

        } else {

            while(next_node->next_node != NULL && next_node->next_node->num < new_num){
                next_node = next_node->next_node;
            }

            // Insert the new element after next node
            new_node->next_node = next_node->next_node;
            next_node->next_node = new_node;

        }

    }

}


int32_t PopLowestNumberFromList(node_t** list){

    int32_t lowest_num;

    if(*list != NULL){
        lowest_num = (*list)->num;
    }else{
        lowest_num = -1;
    }

    *list = (*list)->next_node;

    return lowest_num;

}


int32_t CountOccurancesOfNumInList(int32_t num, node_t* list){

    node_t* next_node = list;
    int32_t sum = 0;

    while(next_node != NULL){

        if(next_node->num == num){
            sum++;
        }
        next_node = next_node->next_node;

    }

    return sum;

}



// Frees all the memory uses in the list
void CleanUpList(node_t** list) {

    if(*list != NULL){

        node_t* prev_node = *list;
        node_t* next_node = (*list)->next_node;

        while(prev_node != NULL){

            free(prev_node);

            prev_node = next_node;
            if(next_node){
                next_node = next_node->next_node;
            }

        }

        *list = NULL;

    }

}




void PrintList(node_t* list){

    node_t* next_node = list;

    while(next_node != NULL){

        printf("%d, ", next_node->num);
        next_node = next_node->next_node;

    }

    printf("\n");

}


#endif



