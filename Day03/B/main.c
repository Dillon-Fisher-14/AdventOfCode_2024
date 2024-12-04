#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "helper.h"
#include "string.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))


int main(){

    // int length_do = parseDo("do()");
    // printf("number of characters do: %d\n", length_do);

    // int length_dont = parseDonot("don't()");
    // printf("number of characters do not: %d\n", length_dont);



    // Load all the numbers from a file
    char* file_name = "../input/input.txt";
    FILE *file_id = fopen ( file_name, "r" );

    if (file_id != NULL) {

        // Get the file size
        size_t pos = ftell(file_id);    // Current position
        fseek(file_id, 0, SEEK_END);    // Go to end
        size_t file_length = ftell(file_id); // read the position which is the size
        fseek(file_id, pos, SEEK_SET);  // restore original position

        // Load the file into a buffer
        char* file_content = malloc(file_length+1);
        memset(file_content, 0, file_length+1);
        fread(file_content, sizeof(char), file_length, file_id);

        char* file_cursor = file_content;

        bool doEnabled = true;

        int sum = 0;
        while(*file_cursor != '\0'){

            int A, B;
            int length_mul   = parseMulFunc(file_cursor, &A, &B);
            int length_do    = parseDo(file_cursor);
            int length_donot = parseDonot(file_cursor);

            if(length_mul > 0){
                if(doEnabled){
                    printf("File Cursor: %p\n", file_cursor - file_content);
                    printf("(%d * %d) = %d\n", A, B, A*B);
                    sum += A*B;
                }
                file_cursor += length_mul;
            } else if(length_do > 0) {
                printf("File Cursor: %p\n", file_cursor - file_content);
                printf("Do()\n");
                doEnabled = true;
                file_cursor += length_do;
            } else if(length_donot > 0){
                printf("File Cursor: %p\n", file_cursor - file_content);
                printf("Don't()\n");
                doEnabled = false;
                file_cursor += length_donot;
            } else {
                file_cursor += 1;
            }


        }



        printf("Total sum of products: %d\n", sum);

        fclose(file_id);
    }
    else {
        perror(file_name); //print the error message on stderr.
    }



    return 0;
}