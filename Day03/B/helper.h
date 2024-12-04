#ifndef HELPER_H
#define HELPER_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>


int parseDo(char* str){

    if(str[0] == 'd' && str[1] == 'o' && str[2] == '(' && str[3] == ')'){
        return 4;
    } else {
        return 0;
    }

}

int parseDonot(char* str){

    if(str[0] == 'd' && str[1] == 'o' && str[2] == 'n' && str[3] == '\'' && str[4] == 't' && str[5] == '(' && str[6] == ')'){
        return 7;
    } else {
        return 0;
    }

}


int parsePreMul(char* str){

    if(str[0] == 'm' && str[1] == 'u' && str[2] == 'l' && str[3] == '('){
        return 4;
    } else {
        return 0;
    }

}

int parseComma(char* str){
    if(str[0] == ','){
        return 1;
    } else {
        return 0;
    }
}


int parsePostMul(char* str){
    if(str[0] == ')'){
        return 1;
    } else {
        return 0;
    }
}


int parseInt(char* str, int* A){

    if(sscanf(str, "%d", A) > 0){
        if(*A > 0){
            return ( (int)log10((double)*A) ) + 1;
        }
        else {
            return 1;
        }
    } else {
        return 0;
    }

}

// returns the number of characters parsed
// If 0, the parse failed
int parseMulFunc(char* str, int* A, int* B){

    int parsePreMulCheck = parsePreMul(str);
    if(parsePreMulCheck == 0) { return 0; }
    str += parsePreMulCheck;

    int parseIntACheck = parseInt(str, A);
    if(parseIntACheck == 0) { return 0; }
    str += parseIntACheck;

    int parseCommaCheck = parseComma(str);
    if(parseCommaCheck == 0) { return 0; }
    str += parseCommaCheck;

    int parseIntBCheck = parseInt(str, B);
    if(parseIntBCheck == 0) { return 0; }
    str += parseIntBCheck;

    int parsePostMulCheck = parsePostMul(str);
    if(parsePostMulCheck == 0) { return 0; }
    str += parsePostMulCheck;

    return parsePreMulCheck + parseIntACheck + parseCommaCheck + parseIntBCheck + parsePostMulCheck;

}



#endif



