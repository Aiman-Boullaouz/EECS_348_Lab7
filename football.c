#include <stdio.h>
#include <stdlib.h>

/**
 * Prints all possible combinations of scoring plays that result in the given score.
 * The score parameter is the target score passed into the function to find
 */
void print_combinations(int score) {
    int td, fg, safety, td_2pt, td_1pt; //Initializing empty variables to count occurances
    int found = 0; // Flag to check if any combination is found

    // Brute force iterate through all possible scoring combinations

    //checking for possible tds
    for (td = 0; td * 6 <= score; td++) {

        //checking for possible fgs
        for (fg = 0; fg * 3 <= score; fg++) {

            //checking for possible safeties
            for (safety = 0; safety * 2 <= score; safety++) {

                //checking for possible 2 point conversions
                for (td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {

                    //checking for possible extra points
                    for (td_1pt = 0; td_1pt * 7 <= score; td_1pt++) {

                        //if total points after adding all the possible components together == the score
                        if (td * 6 + fg * 3 + safety * 2 + td_2pt * 8 + td_1pt * 7 == score) {
                            printf("%d TD, %d FG, %d Safety, %d TD+2pt, %d TD+1pt\n", 
                                   td, fg, safety, td_2pt, td_1pt); // print out the combinrion
                            found = 1;  // mark the score as found
                        }
                    }
                }
            }
        }
    }

    // If the score is not found, alert the user
    if (!found) {
        printf("No valid scoring combination found for %d.\n", score);
    }
}


// Main function takes command line arguments at runtime
int main(int argc, char *argv[]) {
    // Ensure at least one argument is provided
    if (argc < 2) {
        printf("Usage: %s <NFL score>\n", argv[0]);
        return 1;
    }

    // Convert argument to an integer
    int score = atoi(argv[1]);

    // Validate input
    if (score < 0) {
        printf("Invalid score. Please enter a non-negative number.\n");
        return 1;
    }

    // Entering the value 0 or 1 stops the program
    if (score <= 1) {
        printf("Stopping program...\n");
        return 0;
    }

    // Display scoring combinations
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    print_combinations(score);

    return 0;
}
