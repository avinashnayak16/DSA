#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

// Structure to store menu item details
typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} MenuItem;

// Structure to store hotel details
typedef struct {
    char name[MAX_NAME_LEN];
    int numItems;
    MenuItem items[MAX_ITEMS];
} Hotel;

int main() {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Hotel hotel;

    // Read hotel name and number of items
    fscanf(file, "%s %d", hotel.name, &hotel.numItems);

    // Read menu items
    for (int i = 0; i < hotel.numItems; ++i) {
        fscanf(file, "%s %d", hotel.items[i].name, &hotel.items[i].price);
    }

    fclose(file);

    // Print hotel menu
    printf("Hotel: %s\n", hotel.name);
    printf("Menu:\n");
    for (int i = 0; i < hotel.numItems; ++i) {
        printf("%s: %d\n", hotel.items[i].name, hotel.items[i].price);
    }

    return 0;
}
