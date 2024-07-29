#include <stdio.h>
#include <string.h>

struct pizza {
    char restaurant_name[100];
    char pizza_name[50];
    int price;
};

int main() {
    FILE *fp;
    fp = fopen("Menu.txt", "r");

    if (fp == NULL) {
        printf("Could not open the file %s\n", "Menu.txt");
        return 1;
    }

    struct pizza pizza_item;
    int total_price = 0;

    char line[200]; // Adjust the size based on your data

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %s %d", pizza_item.restaurant_name, pizza_item.pizza_name, &pizza_item.price);
        printf("Restaurant: %s\n", pizza_item.restaurant_name);
        printf("Pizza: %s\n", pizza_item.pizza_name);
        printf("Price: %d\n", pizza_item.price);
        printf("\n");

        total_price += pizza_item.price;
    }

    printf("Total Price: %d\n", total_price);

    fclose(fp);

    return 0;
}
