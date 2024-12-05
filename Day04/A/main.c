#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "helper.h"
#include "string.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))


int main(){

    // Load all the numbers from a file
    char* file_name = "../input/input.txt";
    FILE *file_id = fopen ( file_name, "r" );

    if (file_id != NULL) {

        // Get the file size
        size_t pos = (size_t) ftell(file_id);    // Current position
        fseek(file_id, 0, SEEK_END);    // Go to end
        size_t file_length = (size_t) ftell(file_id); // read the position which is the size
        fseek(file_id, (long) pos, SEEK_SET);  // restore original position

        // Load the file into a buffer
        char* file_content = malloc(file_length+1);
        memset(file_content, 0, file_length+1);
        fread(file_content, sizeof(char), file_length, file_id);

        // char* file_cursor = file_content;

        int num_cols = (int) (strchr(file_content, '\n') - file_content) + 1;
        int num_rows = (int) ( file_length / (num_cols) );

        int count = 0;
        

        for(int ii = 0; ii < num_rows; ii++) {

            for(int jj = 0; jj < num_cols; jj++) {

                int index = num_cols * ii + jj;
                if(file_content[index] == 'X'){

                    if(checkXmasRight(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Right\n", ii, jj);
                        count++;
                    }
                    if(checkXmasDownRight(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Down Right\n", ii, jj);
                        count++;
                    }
                    if(checkXmasDown(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Down\n", ii, jj);
                        count++;
                    }
                    if(checkXmasDownLeft(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Down Left\n", ii, jj);
                        count++;
                    }
                    if(checkXmasLeft(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Left\n", ii, jj);
                        count++;
                    }
                    if(checkXmasUpLeft(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Up Left\n", ii, jj);
                        count++;
                    }
                    if(checkXmasUp(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Up\n", ii, jj);
                        count++;
                    }
                    if(checkXmasUpRight(file_content, ii, jj, num_rows, num_cols)){
                        printf("Found an XMAX at (%d, %d) -------> Up Right\n", ii, jj);
                        count++;
                    }

                    // printf("Found an X at (%d, %d)\n", ii, jj);
                }
            
            }
            
        }

        printf("Total XMAS Found: %d\n", count);

        fclose(file_id);
    }
    else {
        perror(file_name); //print the error message on stderr.
    }



    return 0;
}