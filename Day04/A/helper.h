#ifndef HELPER_H
#define HELPER_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>




bool checkXmasRight(char* str, int ii, int jj, int num_rows, int num_cols){

    if(jj > num_cols - 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii) * num_cols + (jj+1);
    int a_index = (ii) * num_cols + (jj+2);
    int s_index = (ii) * num_cols + (jj+3);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}

bool checkXmasDownRight(char* str, int ii, int jj, int num_rows, int num_cols){

    if(ii > num_rows - 3) {return false;}
    if(jj > num_cols - 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii+1) * num_cols + (jj+1);
    int a_index = (ii+2) * num_cols + (jj+2);
    int s_index = (ii+3) * num_cols + (jj+3);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}

bool checkXmasDown(char* str, int ii, int jj, int num_rows, int num_cols){

    if(ii > num_rows - 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii+1) * num_cols + (jj);
    int a_index = (ii+2) * num_cols + (jj);
    int s_index = (ii+3) * num_cols + (jj);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}


bool checkXmasDownLeft(char* str, int ii, int jj, int num_rows, int num_cols){

    if(ii > num_rows - 3) {return false;}
    if(jj < 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii+1) * num_cols + (jj-1);
    int a_index = (ii+2) * num_cols + (jj-2);
    int s_index = (ii+3) * num_cols + (jj-3);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}



bool checkXmasLeft(char* str, int ii, int jj, int num_rows, int num_cols){

    if(jj < 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii) * num_cols + (jj-1);
    int a_index = (ii) * num_cols + (jj-2);
    int s_index = (ii) * num_cols + (jj-3);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}



bool checkXmasUpLeft(char* str, int ii, int jj, int num_rows, int num_cols){

    if(ii < 3) {return false;}
    if(jj < 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii-1) * num_cols + (jj-1);
    int a_index = (ii-2) * num_cols + (jj-2);
    int s_index = (ii-3) * num_cols + (jj-3);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}

bool checkXmasUp(char* str, int ii, int jj, int num_rows, int num_cols){

    if(ii < 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii-1) * num_cols + (jj);
    int a_index = (ii-2) * num_cols + (jj);
    int s_index = (ii-3) * num_cols + (jj);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}

bool checkXmasUpRight(char* str, int ii, int jj, int num_rows, int num_cols){

    if(ii < 3) {return false;}
    if(jj > num_cols - 3) {return false;}

    int x_index = (ii) * num_cols + (jj);
    int m_index = (ii-1) * num_cols + (jj+1);
    int a_index = (ii-2) * num_cols + (jj+2);
    int s_index = (ii-3) * num_cols + (jj+3);

    return str[x_index] == 'X' && str[m_index] == 'M' && str[a_index] == 'A' && str[s_index] == 'S';

}



#endif



