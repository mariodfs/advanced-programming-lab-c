/* 
 * File:   b_problem.c
 * Author: mariodiogosilva
 *
 * Created on February 22, 2014, 10:44 PM
 */

#define _GNU_SOURCE
#define GRID_MAX_DIM 60

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int grid[GRID_MAX_DIM];
int solution = INT_MAX;
int states_num = 0;

int brute_oven(int idx, int oven1_time, int oven2_time) {
    int time_diff = 0;

    if (idx == states_num) {
        time_diff = oven1_time - oven2_time < oven2_time - oven1_time ? oven2_time - oven1_time : oven1_time - oven2_time;
        solution = time_diff > solution ? solution : time_diff;
        return EXIT_SUCCESS;
    }
    brute_oven(idx + 1, oven1_time + grid[idx], oven2_time);
    brute_oven(idx + 1, oven1_time, oven2_time + grid[idx]);
    return EXIT_FAILURE;
}

int main(int argc, char** argv) {
    char* line = NULL;
    int state_counter = INT_MAX;
    int a = 0;
    int b = 0;
    size_t size;

    while (getline(&line, &size, stdin) != 1 && strcmp(line, "\n") != 0) {
        sscanf(line, "%d.%d", &a, &b);
        if (state_counter < (states_num - 1)) {
            grid[state_counter] = a * 100 + b;
        } else if (state_counter == (states_num - 1)) {
            grid[state_counter] = a * 100 + b;
            brute_oven(1, grid[0], 0);
            printf("%.2f\n", ((float) solution) / 100);
            solution = INT_MAX;
        } else {
            state_counter = -1;
            states_num = a;
        }
        ++state_counter;
    }
    return (EXIT_SUCCESS);
}
