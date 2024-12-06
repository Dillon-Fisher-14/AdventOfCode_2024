#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "helper.h"
#include "string.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))


int main(){

    // Load all the rules from a file
    char* file_name_rules = "../input/input_rules.txt";
    FILE *file_id = fopen ( file_name_rules, "r" );

    plHashMap  tCompleteRulesHashmap;
    memset(&tCompleteRulesHashmap, 0, sizeof(plHashMap));
    ruleset_t* sbtCompleteRulesList = NULL;

    if (file_id != NULL) {

        char row[16];
        memset(row, 0, 16);

        // Loop through each level
        while(fgets(row, 16, file_id) != NULL) {
            
            int A, B;
            sscanf(row, "%d|%d", &A, &B);
            printf("(%d, %d)\n", A, B);

            // if value has already loaded a dependancy
            if(pl_hm_has_key(&tCompleteRulesHashmap, B)){
                int Bindex = pl_hm_lookup(&tCompleteRulesHashmap, B);
                pl_sb_push(sbtCompleteRulesList[Bindex].depedencies, A);
            } else {
                // if this is the first dependancy of B

                // Insert a new rule
                int Bindex = pl_sb_size(sbtCompleteRulesList);
                ruleset_t newDependancy = (ruleset_t){0, NULL};
                pl_sb_push(sbtCompleteRulesList, newDependancy);
                sbtCompleteRulesList[Bindex].page = B;
                pl_sb_push(sbtCompleteRulesList[Bindex].depedencies, A);

                // Add rule to the hash maps
                pl_hm_insert(&tCompleteRulesHashmap, B, Bindex);
            }

            
            memset(row, 0, 16);

        }

        fclose(file_id);
    }
    else {
        perror(file_name_rules); //print the error message on stderr.
    }


    // Load all the updates from a file
    char* file_name_updates = "../input/input_updates.txt";
    FILE *file_id_updates = fopen ( file_name_updates, "r" );

    if (file_id_updates != NULL) {
        
        char row[128];
        memset(row, 0, 128);

        int middleSums = 0;

        // Loop through each level
        while(fgets(row, 128, file_id) != NULL) {

            char* subRow = row;

            printf("/////////////////////\n");
            printf("%s\n", row);


            int nums[40];
            memset(nums, -1, sizeof(int)*40);


            sscanf(row, "%d", &nums[0]);
            subRow = strpbrk(row, ","); // This will find the next comma
            if(subRow != NULL){
                subRow++; // Move to the character after the comma
            }

            // Load the row into nums
            int updates_in_row = 1;
            while(subRow) {
                
                // Get the next number in the row
                sscanf(subRow, "%d", &nums[updates_in_row]);


                // prep for the next number and check if at the end of the row
                subRow = strpbrk(subRow, ","); // This will find the next comma
                if(subRow != NULL){
                    subRow++; // Move to the character after the comma
                }                

                updates_in_row++;
            } 


            
            // plHashMap  tTempRulesHashmap;
            // memset(&tTempRulesHashmap, 0, sizeof(plHashMap));
            ruleset_t* sbtTempRulesList = NULL;

            for(int i = 0; i < updates_in_row; i++){

                int num = nums[i];
                // int numIndex = pl_hm_lookup(&tCompleteRulesHashmap, num); 
                // pl_hm_insert(&tTempRulesHashmap, num, pl_sb_size(sbtTempRulesList));

                ruleset_t blankRule = {num, NULL};
                pl_sb_push(sbtTempRulesList, blankRule);
                ruleset_t* addedRule = &sbtTempRulesList[pl_sb_size(sbtTempRulesList) - 1];

                int completeRulesIndex = pl_hm_lookup(&tCompleteRulesHashmap, num);

                if(completeRulesIndex >= 0){

                    // pl_sb_push(sbtTempRulesList, sbtCompleteRulesList[i]);

                    ruleset_t completesRule = sbtCompleteRulesList[completeRulesIndex];
                    for(int dependancy = 0; dependancy < pl_sb_size(completesRule.depedencies); dependancy++){
                        for(int j = 0; j < updates_in_row; j++){

                            if(completesRule.depedencies[dependancy] == nums[j]){
                                pl_sb_push(addedRule->depedencies, nums[j]);
                                break;
                            }
                
                        }

                    }

                } 


            }


            // test that all the updates happen in the correct order
            
            bool allDependanciesFound = true;

            for(int i = 0; i < updates_in_row; i++){

                int num = nums[i];
                int numIndex = i;
                printf("Here are all the dependacies of %d: ", num);

                // if(numIndex >= 0){
                ruleset_t rulesetNum = sbtTempRulesList[i];

                for(int j = 0; j < pl_sb_size(rulesetNum.depedencies); j++){
                    printf("%d, ", rulesetNum.depedencies[j]);
                }
                printf("\n");

                int* dependancyCpy = NULL;
                pl_sb_resize(dependancyCpy, pl_sb_size(rulesetNum.depedencies));
                if(rulesetNum.depedencies){
                    
                    memcpy(dependancyCpy, rulesetNum.depedencies, pl_sb_size(rulesetNum.depedencies)*sizeof(int));
                    for(int j = 0; j < i; j++){
                        
                        for(int k = 0; k < pl_sb_size(dependancyCpy); k++){
                            if(dependancyCpy[k] == nums[j])
                            {
                                pl_sb_del(dependancyCpy, k);
                            }
                        }
                        
                    }

                    if(pl_sb_size(dependancyCpy) != 0){
                        allDependanciesFound = false;
                        printf("Dependancy Not Found!!!\n");
                    }

                }

                // } else {
                //     printf("\n");
                // }

            }

            if(allDependanciesFound){

                // middleSums += nums[updates_in_row/2];
                printf("All Dependancies Found\n");
            } else {
                
                int orderedNums[20];

                for(int i = 0; i < updates_in_row; i++){

                    int num = nums[i];
                    int numIndex = i;
                    printf("Here are all the dependacies of %d: ", num);

                    // if(numIndex >= 0){
                    ruleset_t rulesetNum = sbtTempRulesList[i];

                    if(pl_sb_size(rulesetNum.depedencies) == (updates_in_row/2)){
                        middleSums += rulesetNum.page;
                    }

                }
                printf("Missing Dependancies\n");
            }

            
            memset(row, 0, 128);

        }


        printf("The sum of the middle numbers is: %d\n", middleSums);

        fclose(file_id_updates);
    }
    else {
        perror(file_name_updates); //print the error message on stderr.
    }



    return 0;
}