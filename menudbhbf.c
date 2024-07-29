#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu {
    char food_name[200];
    int price;
};

struct hotel_name_with_menu {
    char hotel_name[50];
    int hotel_number;
    struct menu *m;
    int num_menus;
};

// Function to read data from file and store it in the array
void readDataFromFile(struct hotel_name_with_menu hotels[], int num_hotels, const char *filename) {
    FILE *fp;
    int i, j;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read data for each hotel
    for (i = 0; i < num_hotels; i++) {
        fscanf(fp, "%s %d %d", hotels[i].hotel_name, &hotels[i].hotel_number, &hotels[i].num_menus);

        // Allocate memory for menus
        hotels[i].m = (struct menu *)malloc(hotels[i].num_menus * sizeof(struct menu));

        // Read each menu item
        for (j = 0; j < hotels[i].num_menus; j++) {
            fscanf(fp, "%s %d", hotels[i].m[j].food_name, &hotels[i].m[j].price);
        }
    }

    // Close the file
    fclose(fp);
}

// Function to print data from the array
void printData(struct hotel_name_with_menu hotels[], int num_hotels) {
    int i, j;

    for (i = 0; i < num_hotels; i++) {
        printf("\nHotel Information:\n");
        printf("--------------------\n");
        printf("Hotel Name: %s\n", hotels[i].hotel_name);
        printf("Hotel Number: %d\n", hotels[i].hotel_number);

        printf("\nMenu:\n");
        printf("------\n");
        printf("Food Name\tPrice\n");
        printf("---------\t-------\n");
        for (j = 0; j < hotels[i].num_menus; j++) {
            printf("%s\t\t%d\n", hotels[i].m[j].food_name, hotels[i].m[j].price);
        }
    }
}

// Function to free allocated memory
void freeMemory(struct hotel_name_with_menu hotels[], int num_hotels) {
    int i;
    for (i = 0; i < num_hotels; i++) {
        free(hotels[i].m);
    }
}

int main() {
    const int num_hotels = 9;  // Adjust this based on the actual number of hotels in your file
    struct hotel_name_with_menu hotels[num_hotels];

    // Provide the filename
    const char *filename = "menu.txt";

    // Read data from the file and store it in the array
    readDataFromFile(hotels, num_hotels, filename);

    // Print the data stored in the array
    printData(hotels, num_hotels);

    // Free allocated memory
    freeMemory(hotels, num_hotels);

    return 0;
}
