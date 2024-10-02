#include <stdio.h>

int main() {
    // initialize
    int score = 2;

    while (1) { // continue loop until user enters a score less than or equal to 1
        // take input and store in variable
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        // keeps track of how many times a play is done
        int TD = 0; // 6pts
        int FG = 0; // 3pts
        int safety = 0; // 2pts
        int TD_2PT = 0; // 8pts
        int TD_FG = 0; // 7pts

        // calculate max times each play can happen for the given score
        int TD_max = score / 6;
        int FG_max = score / 3;
        int safety_max = score / 2;
        int TD_2PT_max = score / 8;
        int TD_FG_max = score / 7;

        int temp = score;
        // calculate possible permutations
        for (int i = 0; i <= TD_max; i++) { // check each permutation of TD_max
            temp -= i * 6;
            TD = i;
            for (int j = 0; j <= FG_max; j++) { // check each permutation of FG_max
                temp -= j * 3;
                FG = j;            
                for (int k = 0; k <= safety_max; k++) { // check each permutation of safety_max
                    temp -= k * 2;
                    safety = k;                
                    for (int l = 0; l <= TD_2PT_max; l++) { // check each permutation of TD_2PT_max
                        temp -= l * 8;
                        TD_2PT = l;                    
                        for (int m = 0; m <= TD_FG_max; m++) { // check each permutationof TD_FG_max
                            temp -= m * 7;
                            TD_FG = m;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD_2PT, TD_FG, TD, FG, safety);
                        }
                    }
                }
            }
        }
    }
}