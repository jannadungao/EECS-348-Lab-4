#include <stdio.h>

int main() {
    // initialize
    int score = 2;

    while (score > 1) { // continue loop until user enters a score less than or equal to 1
        // take input and store in variable
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // keeps track of how many times a play is done
        int TD = 0; // 6pts
        int FG = 0; // 3pts
        int safety = 0; // 2pts
        int TD_2PT = 0; // 8pts
        int TD_FG = 0; // 7pts
        int temp_score = score;

        // calculate max times each play can happen for the given score
        int TD_max = temp_score / 6;
        int FG_max = temp_score / 3;
        int safety_max = temp_score / 2;
        int TD_2PT_max = temp_score / 8;
        int TD_FG_max = temp_score / 7;


        // calculate possible permutations
    
    }
}