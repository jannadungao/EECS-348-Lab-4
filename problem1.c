#include <stdio.h>

int main() {
    // initialize
    int score = 0;

    while (score > 1) { // continue loop until user enters a score less than or equal to 1
        // take input and store in variable
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: \n");
        scanf("%d", &score);

        // initializing plays variables 
        int TD = 0; // 6pts
        int FG = 0; // 3pts
        int safety = 0; // 2pts
        int TD_2PT = 0; // 8pts
        int TD_FG = 0; // 7pts
        int temp_score = score;

        // calculate possible combinations
        while (temp_score > 0) {
            if (temp_score >= 8) {
                TD_2PT++;
                temp_score -= 8;
            } else if (temp_score >= 7) {
                TD_FG++;
                temp_score -= 7;
            } else if (temp_score >= 6) {
                TD++;
                temp_score -= 6;
            } else if (temp_score >= 3) {
                FG++;
                temp_score -= 3;
            } else if (temp_score >= 2) {
                safety++;
                temp_score -= 2;
            }
        }

        printf("%d TD + 2PT, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD_2PT, TD_FG, TD, FG, safety);


    }
}