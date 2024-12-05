#ifndef HELPER_H
#define HELPER_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>




bool checkXmasMsUp(char* str, int ii, int jj, int num_rows, int num_cols){

    if(jj > num_cols - 3) {return false;}

    int m1_index = (ii-1) * num_cols + (jj-1);
    int m2_index = (ii-1) * num_cols + (jj+1);
    int s1_index = (ii+1) * num_cols + (jj-1);
    int s2_index = (ii+1) * num_cols + (jj+1);

    return str[m1_index] == 'M' && str[m2_index] == 'M' && str[s1_index] == 'S' && str[s2_index] == 'S';

}


bool checkXmasMsRight(char* str, int ii, int jj, int num_rows, int num_cols){

    if(jj > num_cols - 3) {return false;}

    int m1_index = (ii-1) * num_cols + (jj+1);
    int m2_index = (ii+1) * num_cols + (jj+1);
    int s1_index = (ii-1) * num_cols + (jj-1);
    int s2_index = (ii+1) * num_cols + (jj-1);

    return str[m1_index] == 'M' && str[m2_index] == 'M' && str[s1_index] == 'S' && str[s2_index] == 'S';

}

bool checkXmasMsDown(char* str, int ii, int jj, int num_rows, int num_cols){

    if(jj > num_cols - 3) {return false;}

    int m1_index = (ii+1) * num_cols + (jj-1);
    int m2_index = (ii+1) * num_cols + (jj+1);
    int s1_index = (ii-1) * num_cols + (jj-1);
    int s2_index = (ii-1) * num_cols + (jj+1);

    return str[m1_index] == 'M' && str[m2_index] == 'M' && str[s1_index] == 'S' && str[s2_index] == 'S';

}

bool checkXmasMsLeft(char* str, int ii, int jj, int num_rows, int num_cols){

    if(jj > num_cols - 3) {return false;}

    int m1_index = (ii-1) * num_cols + (jj-1);
    int m2_index = (ii+1) * num_cols + (jj-1);
    int s1_index = (ii-1) * num_cols + (jj+1);
    int s2_index = (ii+1) * num_cols + (jj+1);

    return str[m1_index] == 'M' && str[m2_index] == 'M' && str[s1_index] == 'S' && str[s2_index] == 'S';

}




#endif



