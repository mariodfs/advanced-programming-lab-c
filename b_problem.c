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
int first_branch_kill = 0;
int states_num = -2;

int brute_oven(int idx, int oven1_time, int oven2_time) {
    int time_diff = 0;

    if (first_branch_kill == 0 && oven1_time + oven2_time == grid[0]) {
        first_branch_kill = 1;
        return EXIT_SUCCESS;
    } else if (idx == states_num) {
        time_diff = oven1_time - oven2_time < oven2_time - oven1_time ? oven2_time - oven1_time : oven1_time - oven2_time;
        solution = time_diff > solution ? solution : time_diff;
        return EXIT_SUCCESS;
    } else {
        brute_oven(idx + 1, oven1_time + grid[idx], oven2_time);
        brute_oven(idx + 1, oven1_time, oven2_time + grid[idx]);
    }
    return EXIT_FAILURE;
}

int main(int argc, char** argv) {
    char* line = NULL;
    int state_counter = -1;
    int a = 0;
    int b = 0;
    float cast_helper = 0;
    size_t size;

    while (getline(&line, &size, stdin) != -1 && strcmp(line, "\n") != 0) {
        sscanf(line, "%d.%d", &a, &b);
        if (state_counter > -1 && state_counter < (states_num - 1)) {
            grid[state_counter] = a * 100 + b;
        } else if (state_counter == (states_num - 1)) {
            grid[state_counter] = a * 100 + b;
            brute_oven(0, 0, 0);
            cast_helper = (float) solution;
            printf("%.2f\n", cast_helper / 100);
            solution = INT_MAX;
            first_branch_kill = 0;
        } else {
            state_counter = -1;
            states_num = a;
        }
        ++state_counter;
    }
    return (EXIT_SUCCESS);
}
