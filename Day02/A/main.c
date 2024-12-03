#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "helper.h"
#include "string.h"




int main(){


    // Load all the numbers from a file
    char* file_name = "../input/input.txt";
    FILE *file_id = fopen ( file_name, "r" );

    if (file_id != NULL) {

        char row[32];
        memset(row, 0, 32);

        int safeLevels = 0;

        // Loop through each level
        while(fgets(row, 32, file_id) != NULL) {

            char* subRow = row;

            bool bMovingUp = false;
            bool bMovingDown = false;
            bool bTooLargeStep = false;

            int prevNum = 0;
            sscanf(row, "%d", &prevNum);
            subRow = strpbrk(row, " "); // This will find the next space
            if(subRow != NULL){
                subRow++; // Move to the character after the space
            }

            while(subRow) {
                
                // Get the next number in the row
                int num = 0;
                sscanf(subRow, "%d", &num);
                printf("%d ", num);

                // Check if the level is safe
                if(num - prevNum < 0){
                    bMovingDown = true;
                }
                if(num - prevNum > 0){
                    bMovingUp = true;
                }
                int diff = abs(num - prevNum);
                if(diff > 3 || diff == 0){
                    bTooLargeStep = true;
                    // printf("Difference detected: num: %d, prevNum: %d, difference: %d", num, prevNum, diff);
                }


                // prep for the next number and check if at the end of the row
                subRow = strpbrk(subRow, " "); // This will find the next space
                if(subRow != NULL){
                    subRow++; // Move to the character after the space
                }

                prevNum = num;

            } 
            


            // if the level only moved up or down and didn't move by more than 3 each step
            if((bMovingUp ^ bMovingDown) && !bTooLargeStep){
                safeLevels++;
                printf("--------------> Safe \n");
            } else {
                printf("--------------> Not Safe \n");
                
            }


            

        }

        printf("Total safe levels: %d\n", safeLevels);

        fclose(file_id);
    }
    else {
        perror(file_name); //print the error message on stderr.
    }



    return 0;
}