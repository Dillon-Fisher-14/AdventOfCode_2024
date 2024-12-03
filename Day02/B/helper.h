#ifndef HELPER_H
#define HELPER_H


void removeIndexFromArray(int** nums, int index, int size){

    for(int i = index; i < size - 1; i++){
        (*nums)[i] = (*nums)[i+1];
    }

    (*nums)[size-1] = 0;

}


bool checkForMistake(int numA, int numB, bool bMovingUp){
    bool mistakeDetected = false;

    // Check if the level is safe
    if(bMovingUp && numA - numB > 0){
        mistakeDetected = true;
    }

    if(!bMovingUp && numA - numB < 0){
        mistakeDetected = true;
    }

    int diff = abs(numA - numB);
    if(diff > 3 || diff == 0){
        mistakeDetected = true;
        // printf("Difference detected: num: %d, prevNum: %d, difference: %d", num, prevNum, diff);
    }

    return mistakeDetected;
}

#endif



