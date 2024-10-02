#include <stdio.h>

// converts celsius to fahrenheit
float celsius_to_fahrenheit(float C) {
    float F = ((float)(9/5) * C) + 32;
    return F;
}

// converts fahrenheit to celsius
float fahrenheit_to_celsius(float F) {
    float C = ((float)5 / 9) * (F - 32);
    return C;
}

// converts celsius to kelvin
float celsius_to_kelvin(float C) {
    float K = C + 273.15;
    return K;
}

// converts kelvin to celsius
float kelvin_to_celsius(float K) {
    float C = K - 273.15;
    return C;
}

// converts fahrenheit to kelvin
float fahrenheit_to_kelvin(float F) {
    float K = (F + 459.67) * ((float)5/9);
    return K;
}

// converts kelvin to fahrenheit
float kelvin_to_fahrenheit(float K) {
    float F = ((K - 273.15) * ((float)9/5)) + 32;
    return F;
}

// categorize temperature
int categorize_temperature(float celsius) {
    int cat;
    if (celsius < 0) {
        cat = 1;
    } else if (celsius > 0 && celsius <= 10) {
        cat = 2;
    } else if (celsius > 10 && celsius <= 25) {
        cat = 3;
    } else if (celsius > 25 && celsius <= 35) {
        cat = 4;
    } else if (celsius >= 35) {
        cat = 5;
    }
    return cat;
}

// main function
int main() {
    // initialize variables
    float temp;
    int scale;
    int convert;

    // check invalid input
    while (1) {
        // take user input and save to variables
        printf("Enter the temperature: ");
        scanf("%f", &temp);
        printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%i", &scale);
        printf("Convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%i", &convert);

        if ((temp < 0) && (scale == 3)) {
            printf("Invalid input. Please enter temperatures greater than or equal to 0 for Kelvins.\n");
        } else if (scale == convert) {
            printf("Please choose a different scale than the current scale to convert to.\n");
        } else {
            break;
        }
    }

    int cat;
    float new_temp;
    // convert and print
    if (scale == 1 && convert == 2) { // C to F
        new_temp = celsius_to_fahrenheit(temp);
        cat = categorize_temperature(temp);
    } else if (scale == 1 && convert == 3) { // C to K
        new_temp = celsius_to_kelvin(temp);
        cat = categorize_temperature(temp);
    } else if (scale == 2 && convert == 1) { // F to C
        new_temp = fahrenheit_to_celsius(temp);
        cat = categorize_temperature(new_temp);
    } else if (scale == 2 && convert == 3) { // F to K
        new_temp = fahrenheit_to_kelvin(temp);
        float c = fahrenheit_to_celsius(temp);
        cat = categorize_temperature(c);
    } else if (scale == 3 && convert == 1) { // K to C
        new_temp = kelvin_to_celsius(temp);
        cat = categorize_temperature(new_temp);
    } else if (scale == 3 && convert == 2) { // K to F
        new_temp = kelvin_to_fahrenheit(temp);
        float c = fahrenheit_to_celsius(new_temp);
        cat = categorize_temperature(c);
    }
    
    // print info
    printf("Converted temperature: %f\n", new_temp);
    
    if (cat == 1) {
        printf("Temperature category: Freezing\nWeather Advisory: Stay indoors and stay warm!\n");
    } else if (cat == 2) {
        printf("Temperature category: Cold\nWeather Advisory: Grab a jacket\n"); 
    } else if (cat == 3) {
        printf("Temperature category: Comfortable\nWeather Advisory: Spend some time outside!\n");
    } else if (cat == 4) {
        printf("Temperature category: Hot\nWeather Advisory: Stay hydrated!\n");
    } else if (cat == 5) {
        printf("Temperature category: Extreme Heat\nWeather Advisory: Stay indoors and stay hydrated!\n");
    }
}
