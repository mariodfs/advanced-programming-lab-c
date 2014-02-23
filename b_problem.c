/* 
 * File:   b_problem.c
 * Author: mariodiogosilva
 *
 * Created on February 22, 2014, 10:44 PM
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float algorithm(float time_grid[60], int states_num) {

    float result = 0;
    
    // DP KNAPSACK
    
    
    
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {

    char* line = NULL;
    char* char_temp = NULL;
    float result = -1;
    int states_num = -2;
    int state_counter = -1;
    float temp_0 = 0;
    float time_grid[60];
    size_t size;

    while (getline(&line, &size, stdin) != -1) {

        if (strcmp(line, "\n") == 0) break;

        char_temp = strtok(line, " ");
        if (char_temp != NULL) {
            temp_0 = strtod(char_temp, NULL);
        } else
            return (EXIT_FAILURE);

        if (state_counter > -1 && state_counter < (states_num - 1)) {
            time_grid[state_counter] = temp_0;

        } else if (state_counter == (states_num - 1)) {
            time_grid[state_counter] = temp_0;

            result = algorithm(time_grid, states_num);

            printf("%.2f\n", result);

        } else {
            state_counter = -1;
            states_num = (int) temp_0; // if a problem come up, go see QUESTIONS in Mooshak
        }

        ++state_counter;
    }

    return (EXIT_SUCCESS);
}
