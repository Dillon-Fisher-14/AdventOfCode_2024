#include <stdio.h>
#include <stdint.h>

#include "helper.h"
#include "string.h"





int main(){

    // Init lists
    node_t* listA = NULL;
    node_t* listB = NULL;

    // Load all the numbers from a file
    char* file_name = "../input/input.txt";
    FILE *file_id = fopen ( file_name, "r" );

    if (file_id != NULL) {

        char row[16];
        memset(row, 0, 16);

        while(fgets(row, 16, file_id) != NULL) {

            int32_t intA = strtol(row, NULL, 10);
            InsertNumIntoList(intA, &listA);

            int32_t intB = strtol(row+8, NULL, 10);
            InsertNumIntoList(intB, &listB);

        }

        fclose(file_id);
    }
    else {
        perror(file_name); //print the error message on stderr.
    }


    // // Print the two lists
    // PrintList(listA);
    // PrintList(listB);

    // Calculate the sum of differences
    int32_t sum = 0;
    while(listA != NULL){
        int32_t lowestA = PopLowestNumberFromList(&listA);
        int32_t occurancesInB = CountOccurancesOfNumInList(lowestA, listB);

        sum += lowestA * occurancesInB;
    }

    printf("The similarity score is: %d", sum);


    // Clean up lists
    CleanUpList(&listA);
    CleanUpList(&listB);

    return 0;
}