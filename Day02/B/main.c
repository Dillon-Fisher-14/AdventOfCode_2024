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
            int* nums = malloc(256);

            // Get the first element
            sscanf(row, "%d", &nums[0]);
            subRow = strpbrk(row, " "); // This will find the next space
            if(subRow != NULL){
                subRow++; // Move to the character after the space
            }
            printf("%d ", nums[0]);

            int numIndex = 1;
            
            int  iMovingUpCount = 0;
            int  iMovingDownCount = 0;

            while (subRow){

                // Get the next number in the row
                sscanf(subRow, "%d", &nums[numIndex]);
                printf("%d ", nums[numIndex]);

                if(nums[numIndex] - nums[numIndex-1] < 0){
                    iMovingDownCount++;
                }
                if(nums[numIndex] - nums[numIndex-1] > 0){
                    iMovingUpCount++;
                }

                // prep for the next number and check if at the end of the row
                subRow = strpbrk(subRow, " "); // This will find the next space
                if(subRow != NULL){
                    subRow++; // Move to the character after the space
                }

                numIndex++;

            }
            printf("\n");
            // printf("Moving Down Count: %d, Moving Up Count: %d\n", iMovingDownCount, iMovingUpCount);
            
            
            // Get whether the line is mostly moving up or down
            bool bMostlyMovingUp = iMovingUpCount > iMovingDownCount;

            int iMistakesFound = 0;

            bool bMovingUp

            for (int i = 0; i < numIndex - 1; i++){

            }

            // for (int i = 0; i < numIndex - 1 - iMistakesFound; i++){

            //     bool mistakeDetected = checkForMistake(nums[i], nums[i+1], bMostlyMovingUp);
                
            //     printf("(%d", nums[i]);
            //     if(mistakeDetected){
            //         printf("*");
            //     }else{
            //         printf("-");
            //     }
            //     printf("%d) ", nums[i+1]);

            //     if(mistakeDetected){

            //         // Try removing i
            //         bool bCanRemoveI = false;
            //         if(((i >= 1 && !checkForMistake(nums[i-1], nums[i+1], bMostlyMovingUp)) && !checkForMistake(nums[i+1], nums[i+2], bMostlyMovingUp)) || (i == 0 && !checkForMistake(nums[i+1], nums[i+2], bMostlyMovingUp))){
            //             bCanRemoveI = true;
            //         }

            //         bool bCanRemoveIPlusOne = false;
            //         if(i + 1 == numIndex - 1 - iMistakesFound || !checkForMistake(nums[i], nums[i+2], bMostlyMovingUp)){
            //             bCanRemoveIPlusOne = true;
            //         }

            //         if(bCanRemoveI){
            //             printf(" <removed: %d> ", nums[i]);
            //             removeIndexFromArray(&nums, i, numIndex);


            //         } else if(bCanRemoveIPlusOne){
            //             printf(" <removed: %d> ", nums[i+1]);
            //             removeIndexFromArray(&nums, i+1, numIndex);
            //         } else {
            //             iMistakesFound += 2;
            //             break;
            //         }

            //         i--;
            //         iMistakesFound++;
                    
            //     }

            //     // if(iMistakesFound > 1){
            //     //     break;
            //     // }

            // }


            // if the level only moved up or down and didn't move by more than 3 each step
            if(iMistakesFound <= 1){
                safeLevels++;
                printf("--------------> Safe \n");
            } else {
                printf("--------------------------------------------------------------> Not Safe \n");
                
            }
            printf("Mistakes: %d\n", iMistakesFound);

            printf("`````````````````````````\n");
            

        }

        printf("Total safe levels: %d\n", safeLevels);

        fclose(file_id);
    }
    else {
        perror(file_name); //print the error message on stderr.
    }



    return 0;
}