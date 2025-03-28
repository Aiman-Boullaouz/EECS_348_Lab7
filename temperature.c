#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
void categorize_temperature(float celsius);
void clear_input_buffer();

// Conversion Functions that are pretty self explanitory: converts X to Y
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Weather Categorization and Advisory Function
void categorize_temperature(float celsius) {

    //Using if statements to enforece the difference temp boundaries
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Wear a jacket.\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Category: Cold\nAdvisory: Wear a warm coat.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Category: Comfortable\nAdvisory: Wear light clothing.\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Category: Hot\nAdvisory: Stay hydrated and wear sunscreen.\n");
    } else {
        printf("Category: Extreme Heat\nAdvisory: Stay indoors and keep cool.\n");
    }
}

// Function to prevent input errors by clearing the input field
void clear_input_buffer() {
    while (getchar() != '\n');
}

// Main Program
int main() {

    //Creating empty variables to read values into
    float temp_input, temp_converted;
    int input_scale, output_scale;
    int valid_input = 0;

    printf("Welcome to the Temperature Conversion Utility!\n");

    // Loop until valid input is given
    while (!valid_input) {
        printf("\nEnter the temperature value: ");

        //getting a input from the user and checking the validity
        if (scanf("%f", &temp_input) != 1) {
            clear_input_buffer(); // Clear the invalid input
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

        // Check if the temperature is a valid input (e.g., no negative Kelvin)
        printf("Choose the scale of the input temperature:\n");
        printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\nEnter your choice (1/2/3): ");
        // Enforcing valid input boundaries
        if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
            clear_input_buffer(); // Clear the invalid input
            printf("Invalid choice! Please select a valid scale (1, 2, or 3).\n");
            continue;
        }

        printf("Choose the scale of the target temperature:\n");
        printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\nEnter your choice (1/2/3): ");
        // Enforcing valid input boundaries
        if (scanf("%d", &output_scale) != 1 || output_scale < 1 || output_scale > 3) {
            clear_input_buffer(); // Clear the invalid input
            printf("Invalid choice! Please select a valid scale (1, 2, or 3).\n");
            continue;
        }

        // Ensure that the input scale and output scale are not the same
        if (input_scale == output_scale) {
            printf("Input scale and output scale cannot be the same. Please choose different scales.\n");
            continue;
        }

        valid_input = 1; // Mark input as valid for processing
    }

    // Converting from C to another scale
    if (input_scale == 1) { // Celsius
        if (output_scale == 2) { // To Fahrenheit
            temp_converted = celsius_to_fahrenheit(temp_input);
            printf("Converted Temperature: %.2f Fahrenheit\n", temp_converted);
        } else if (output_scale == 3) { // To Kelvin
            temp_converted = celsius_to_kelvin(temp_input);
            printf("Converted Temperature: %.2f Kelvin\n", temp_converted);
        }
    
    // Converting from F to another scale
    } else if (input_scale == 2) { // Fahrenheit
        if (output_scale == 1) { // To Celsius
            temp_converted = fahrenheit_to_celsius(temp_input);
            printf("Converted Temperature: %.2f Celsius\n", temp_converted);
        } else if (output_scale == 3) { // To Kelvin
            temp_converted = celsius_to_kelvin(fahrenheit_to_celsius(temp_input));
            printf("Converted Temperature: %.2f Kelvin\n", temp_converted);
        }
    
    // Converting from K to another scale
    } else if (input_scale == 3) { // Kelvin
        if (output_scale == 1) { // To Celsius
            temp_converted = kelvin_to_celsius(temp_input);
            printf("Converted Temperature: %.2f Celsius\n", temp_converted);
        } else if (output_scale == 2) { // To Fahrenheit
            temp_converted = celsius_to_fahrenheit(kelvin_to_celsius(temp_input));
            printf("Converted Temperature: %.2f Fahrenheit\n", temp_converted);
        }
    }

    // Categorize the temperature and provide an advisory
    categorize_temperature(temp_converted);

    return 0;
}
