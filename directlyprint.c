/*#include <stdio.h>
#include <string.h>

#define MAX_SELECTED_ITEMS 45 // Assuming the maximum selected items is the same as the maximum menu items

// Structure to represent a selected item
struct SelectedItem
{
    char name[50];
    double price;
};
struct MenuItem
{
    char name[50];
    double price;
};
// Structure to represent a hotel
struct Hotel
{
    char name[50];
    int hotelNumber;
    char location[60];
    struct MenuItem menu[45];
    int menuSize;
};
struct Hotel_name
{
    char name[50];
    int hotel_number;
};
// Function to print the menu of a hotel in table format
void printHotelMenu(struct Hotel hotel)
{
    printf("Hotel Name: %s\n", hotel.name);
    printf("Hotel Number: %d\n", hotel.hotelNumber);

    printf("\n%-5s %-30s %s\n", "No.", "Food Name", "Price");
    printf("---------------------------------------------\n");

    for (int i = 0; i < hotel.menuSize; i++)
    {
        printf("%-5d %-30s $%.2f\n", i + 1, hotel.menu[i].name, hotel.menu[i].price);
    }

    printf("\n");
}
void printing_hotel_name(struct Hotel_name hotel_name)
{
    printf("%d\t", hotel_name.hotel_number);
    printf("%s", hotel_name.name);    
    printf("\n");
}

int main()
{
    // Initialize the hotels and their menus
    struct Hotel hotels[] = {
        {"Baskin Robbins", 1, {{"Vanilla", 89}, {"Chocolate", 99}, {"Strawberry", 79}, {"Mint Chocolate", 55}, {"Cookies & Cream", 118}, {"Rocky Road", 59}, {"Butter Pecan", 80}, {"Coffee", 99}, {"Pistachio", 129}, {"Caramel Swirl", 159}, {"Madagascar Vanilla Bean", 185}, {"Belgian Chocolate Fudge Brownie", 169}, {"Mango Lassi Sorbet", 219}, {"Salted Caramel Pecan", 199}, {"Pistachio Rosewater", 209}, {"Coffee Almond Fudge", 236}, {"Raspberry Cheesecake Swirl", 156}, {"Coconut Milk Chocolate Chip", 189}, {"Honeycomb Crunch", 199}, {"Mint Chocolate Chip Cookie Dough", 306}}, 20},
        {"Balaji Wines", 2, {{"Mixed Veg", 60}, {"Veg Sweet Corn Soup", 65}, {"Chicken Sweet Corn Soup", 105}, {"Tomato Soup", 50}, {"Chicken Clear Soup", 90}, {"Veg Clear Soup", 60}, {"Veg Hot & Sour Soup", 80}, {"Chicken Hot & Sour Soup", 120}, {"Mixed Veg Noodles", 70}, {"Chicken Hakka Noodles", 80}, {"Egg Hakka Noodles", 90}, {"Mixed Hakka Noodles", 90}, {"Steamed Rice", 55}, {"Jeera Rice", 70}, {"Mixed Fried Rice", 100}, {"Egg Fried Rice", 80}, {"Chicken Fried Rice", 150}, {"Paneer Pulao", 90}, {"Chicken Pulao", 110}, {"Green Peas Pulao", 80}, {"Veg Biriyani", 100}, {"Chicken Biriyani", 120}, {"Hyderabadi Biriyani", 200}, {"Mutton Biriyani", 250}}, 24},
        {"Hotel President", 3, {{"Aloo Paratha", 70}, {"Gobi Paratha", 80}, {"Paneer Paratha", 80}, {"Mushroom Paratha", 90}, {"Mooli Paratha", 100}, {"Onion Paratha", 90}, {"Methi Paratha", 80}, {"Pudina Paratha", 80}, {"Beetroot Paratha", 90}, {"Carrot Paratha", 90}, {"Mixed Veg Paratha", 80}, {"Aloo Onion Paratha", 90}, {"Gobi Onion Paratha", 90}, {"Paneer Onion Paratha", 80}, {"Aloo Jeera Paratha", 100}, {"Aloo Gobi Paratha", 80}, {"Aloo Methi Paratha", 80}, {"Aloo Garlic Paratha", 80}, {"Gobi Garlic Paratha", 90}, {"Onion Garlic Paratha", 85}, {"Paneer Garlic Paratha", 85}}, 21},
        {"Shree Vasant", 4, {{"Chole Bhature", 80}, {"Paneer Wale Chole Bhature", 100}, {"Chole Rice", 80}, {"Single Chole", 35}, {"Raita", 30}, {"Sabzi With 4 Roti", 130}, {"Sabzi With Butter Naan", 130}, {"Sabzi With Laccha Paratha", 130}, {"Sabzi With Aaloo Payaz Paratha", 130}, {"Sabzi With Chobi Naan", 130}, {"Sabzi With Paneer Naan", 150}, {"Sabzi With Chur-Chur Naan", 160}, {"Plain Roti", 12}, {"Butter Roti", 15}}, 15},
        {"Dennison's", 5, {{"Special Milestone Veg.", 260}, {"Tawa Vegetable", 240}, {"Veg. Toofani", 245}, {"Veg. Angara.", 240}, {"Veg. Handi Masala", 230}, {"Veg. Kadai.", 225}, {"Veg. Kolhapuri", 225}, {"Veg. Jaipuri", 235}, {"Veg. Diwani Handi", 240}, {"Veg. Makkhan Wala", 240}, {"Shahi Vegetable", 230}, {"Methi Mattar Malai", 215}, {"Methi Mattar Masala", 210}, {"Methi Mushroom Mattar Masala", 210}, {"Baby Corn Mushroom Masala", 225}, {"Baby Corn Butter Masala", 225}, {"Palak Corn Capsicum", 350}, {"Plain Palak", 210}, {"Mix Veg.", 210}, {"Boiled Veg.", 210}, {"Tomato Corn Bharta", 250}, {"Chana Masala", 200}, {"Aloo Mattar Masala", 235}, {"Aloo Gobi Dry", 240}, {"Aloo Shuki Bhaji", 240}, {"Aloo Palak", 259}}, 26},
        {"Hans", 6, {{"Butter Dabeli.", 25}, {"Schezwan Dabeli.", 40}, {"Mayonnaise Dabeli.", 45}, {"Cheese Dabeli", 50}, {"Bowl Dabeli", 45}, {"Cheese Bowl Dabeli", 65}, {"Grilled Dabeli", 40}, {"Grilled Schezwan Dabeli", 50}, {"Grilled Mayonnaise Dabeli", 55}, {"Grilled Cheese Dabeli.", 65}, {"Sandwich Dabeli.", 50}, {"Sandwich Grilled Dabeli.", 65}, {"Sandwich Mayo Dabeli.", 70}, {"Sandwich Cheese Dabeli", 75}, {"JAIN DABELIS", 65}, {"Jain Butter Dabeli", 45}, {"Jain Cheese Dabeli", 30}, {"Jain Grilled Dabeli.", 87}}, 18},
        {"Hotel Naveen", 7, {{"Virgin Mojito", 50}, {"Cucumber Refresher", 50}, {"Rose Mint", 80}, {"Shirley Temple", 90}, {"Guava Tini", 90}, {"Ocean Blue", 80}, {"Pina Colada", 90}, {"Apple Cool", 90}, {"Chilli Guava", 80}, {"Ginger Fantasy", 80}, {"Green Apple Mojito", 70}, {"Spicy Orange", 80}, {"Watermelon", 70}, {"Coconut Mojito", 90}, {"Green Apple Fizzy", 90}, {"Rose Sparkler", 70}, {"Ginger Blue", 80}, {"Summer King", 70}, {"Cinderella", 90}, {"Mocktail Punch", 90}, {"Black Shot", 60}, {"Tequila Sunrise", 50}, {"Mojito", 50}, {"Daiquiri", 80}, {"Pina Colada", 90}, {"Blue Lagoon", 90}, {"Black Russian", 80}, {"Tequila & Lemon", 90}, {"Whisky Cola", 90}, {"Melon", 80}, {"Peppermint", 80}, {"Vodka Lime", 70}, {"Peach Schnapps", 80}, {"Jagermeister", 70}, {"Cheese & Tomato", 90}, {"Supreme Chicken", 70}, {"Mexican", 80}, {"Italian Style", 70}, {"American Hot", 90}, {"Vegetarian", 90}, {"Smokey BBQ", 90}, {"Hawaiian", 70}, {"Pepperoni", 80}, {"Ham & Cheese", 70}, {"Meatball Feast", 90}}, 45},
        {"The Emperor", 8, {{"Egg Roll", 60}, {"Spring Rolls", 50}, {"Fried Shrimp", 50}, {"Steamed Dumplings", 80}, {"Steamed Wontons", 90}, {"Shu Mai", 90}, {"Shrimp Toast", 80}, {"Crab Rangoons", 90}, {"Wonton Soup", 90}, {"Egg Drop Soup", 80}, {"Wonton Egg Drop Mix $4.75", 80}, {"Hot & Sour Soup", 70}, {"Vegetable Noodle Soup", 80}, {"House Special Soup", 70}, {"Chicken & Corn Soup", 90}, {"Plain Fried Rice", 90}, {"Roast Pork", 70}, {"Shrimp Fried Rice", 80}, {"Vegetable Fried Rice", 70}, {"House Special Fried Rice", 90}, {"Young Chow Fried Rice", 90}, {"Chop Suey", 90}, {"Chicken Chop Suey", 70}, {"Shrimp Chop Suey", 80}, {"Vegetable Chop Suey", 70}, {"Combination Chop Suey", 90}, {"Shrimp Chop Suey", 90}, {"Vegetable Chop Suey", 60}, {"Combination Chop", 50}, {"Suey", 50}}, 30},
        {"Domino's Pizza", 9, {{"Veggie Paradise Pizza", 269}, {"Margheria Pizza", 109}, {"Peppy Paneer Pizza", 269}, {"Paneer Non-Veg Loaded", 199}, {"Indi Tandoori Paneer Pizza", 319}, {"Farmhouse Pizza", 269}, {"Taco Mexicana Non-Veg", 85}, {"Cheese n Corn", 219}, {"Veg Loaded", 189}, {"Chicken Dominator Pizza", 369}, {"Chicken Pepperconi Pizza", 369}}, 11},
        {"Mcdonald's", 10, {{"Virgin Mojito", 50}, {"Paneer Wale Chole Bhature", 100}, {"Chole Rice", 80}, {"Cucumber Refresher", 50}, {"Veggie Paradise Pizza", 269}, {"Margheria Pizza", 109}, {"Peppy Paneer Pizza", 269}, {"Paneer Non-Veg Loaded", 199}, {"Indi Tandoori Paneer Pizza", 319}, {"Farmhouse Pizza", 269}, {"Taco Mexicana Non-Veg", 85}, {"Cheese n Corn", 219}, {"Veg Loaded", 189}, {"Chicken Dominator Pizza", 369}, {"Chicken Pepperconi Pizza", 369}}, 15}
        // Add more hotels and menus as needed
    };
    struct Hotel_name hotels_names[] = {
        {"Baskin Robbins", 1},
        {"Balaji Wines", 2},
        {"Hotel President", 3},
        {"Shree Vasant", 4},
        {"Dennison's", 5},
        {"Hans", 6},
        {"Hotel Naveen", 7},
        {"The Emperor", 8},
        {"Domino's Pizza", 9},
        {"McDonald's", 10}

        // Add more hotels and menus as needed
    };

    // Initialize the array to store selected items
    struct SelectedItem selectedItems[MAX_SELECTED_ITEMS];
    int numSelectedItems = 0;

    // Print the menu of all hotels in table format
    /*for (int i = 0; i < sizeof(hotels) / sizeof(hotels[0]); i++) {
        printHotelMenu(hotels[i]);
    }*/
    /*printf("\n%-5s %-30s\n", "No.", "Hotel Name");
    printf("--------------------------\n");
    for (int i = 0; i < sizeof(hotels) / sizeof(hotels[0]); i++) {
        printing_hotel_name(hotels_names[i]);
    }
    int choosing_hotel = 0;
    scanf("%d", &choosing_hotel);
    switch (choosing_hotel)
    {
    case 1 ... 10:
        printHotelMenu(hotels[choosing_hotel]);
        break;
    case 11:
        printf("x");
        break;
    default:
        printf("Invalid input");
        break;
    }

    // Allow the user to select items and calculate the total price
    int selectedHotel, selectedItem;
    double totalPrice = 0;

    printf("Enter the number of the hotel you want to order from: ");
    scanf("%d", &selectedHotel);

    // Check if the selected hotel number is valid
    if (selectedHotel >= 1 && selectedHotel <= sizeof(hotels) / sizeof(hotels[0]))
    {
        // Allow the user to select items from the menu
        printf("Enter the number of the item you want to order (enter 0 to finish): ");
        scanf("%d", &selectedItem);

        while (selectedItem != 0 && numSelectedItems < MAX_SELECTED_ITEMS)
        {
            // Check if the selected item number is valid
            if (selectedItem >= 1 && selectedItem <= hotels[selectedHotel - 1].menuSize)
            {
                // Add the selected item to the array
                strcpy(selectedItems[numSelectedItems].name, hotels[selectedHotel - 1].menu[selectedItem - 1].name);
                selectedItems[numSelectedItems].price = hotels[selectedHotel - 1].menu[selectedItem - 1].price;
                totalPrice += selectedItems[numSelectedItems].price;

                // Increment the number of selected items
                numSelectedItems++;
            }
            else
            {
                printf("Invalid item number. Please enter a valid number or 0 to finish.\n");
            }

            // Prompt the user to enter the next item or 0 to finish
            printf("Enter the number of the item you want to order (enter 0 to finish): ");
            scanf("%d", &selectedItem);
        }

        // Print the selected items and total price
        printf("\nSelected Items:\n");
        printf("%-30s %s\n", "Food Name", "Price");
        printf("---------------------------------------------\n");

        for (int i = 0; i < numSelectedItems; i++)
        {
            printf("%-30s $%.2f\n", selectedItems[i].name, selectedItems[i].price);
        }

        printf("\nTotal Price: $%.2f\n", totalPrice);
    }
    else
    {
        printf("Invalid hotel number.\n");
    }

    return 0;
}
*/
#include <stdio.h>
#include <string.h>

#define MAX_SELECTED_ITEMS 45

struct SelectedItem
{
    char name[50];
    double price;
};

struct MenuItem
{
    char name[50];
    double price;
};

struct Hotel
{
    char name[50];
    int hotelNumber;
    //char location[60];
    struct MenuItem menu[45];
    int menuSize;
};

struct Hotel_name
{
    char name[50];
    int hotel_number;
};

void printHotelMenu(struct Hotel hotel)
{
    printf("Hotel Name: %s\n", hotel.name);
    printf("Hotel Number: %d\n", hotel.hotelNumber);

    printf("\n%-5s %-30s %s\n", "No.", "Food Name", "Price");
    printf("---------------------------------------------\n");

    for (int i = 0; i < hotel.menuSize; i++)
    {
        printf("%-5d %-30s $%.2f\n", i + 1, hotel.menu[i].name, hotel.menu[i].price);
    }

    printf("\n");
}

void printing_hotel_name(struct Hotel_name hotel_name)
{
    printf("%d\t", hotel_name.hotel_number);
    printf("%s", hotel_name.name);
    printf("\n");
}

int main()
{
    struct Hotel hotels[] = {
        {"Baskin Robbins", 1, {{"Vanilla", 89}, {"Chocolate", 99}, {"Strawberry", 79}, {"Mint Chocolate", 55}, {"Cookies & Cream", 118}, {"Rocky Road", 59}, {"Butter Pecan", 80}, {"Coffee", 99}, {"Pistachio", 129}, {"Caramel Swirl", 159}, {"Madagascar Vanilla Bean", 185}, {"Belgian Chocolate Fudge Brownie", 169}, {"Mango Lassi Sorbet", 219}, {"Salted Caramel Pecan", 199}, {"Pistachio Rosewater", 209}, {"Coffee Almond Fudge", 236}, {"Raspberry Cheesecake Swirl", 156}, {"Coconut Milk Chocolate Chip", 189}, {"Honeycomb Crunch", 199}, {"Mint Chocolate Chip Cookie Dough", 306}}, 20},
        {"Balaji Wines", 2, {{"Mixed Veg", 60}, {"Veg Sweet Corn Soup", 65}, {"Chicken Sweet Corn Soup", 105}, {"Tomato Soup", 50}, {"Chicken Clear Soup", 90}, {"Veg Clear Soup", 60}, {"Veg Hot & Sour Soup", 80}, {"Chicken Hot & Sour Soup", 120}, {"Mixed Veg Noodles", 70}, {"Chicken Hakka Noodles", 80}, {"Egg Hakka Noodles", 90}, {"Mixed Hakka Noodles", 90}, {"Steamed Rice", 55}, {"Jeera Rice", 70}, {"Mixed Fried Rice", 100}, {"Egg Fried Rice", 80}, {"Chicken Fried Rice", 150}, {"Paneer Pulao", 90}, {"Chicken Pulao", 110}, {"Green Peas Pulao", 80}, {"Veg Biriyani", 100}, {"Chicken Biriyani", 120}, {"Hyderabadi Biriyani", 200}, {"Mutton Biriyani", 250}}, 24},
        {"Hotel President", 3, {{"Aloo Paratha", 70}, {"Gobi Paratha", 80}, {"Paneer Paratha", 80}, {"Mushroom Paratha", 90}, {"Mooli Paratha", 100}, {"Onion Paratha", 90}, {"Methi Paratha", 80}, {"Pudina Paratha", 80}, {"Beetroot Paratha", 90}, {"Carrot Paratha", 90}, {"Mixed Veg Paratha", 80}, {"Aloo Onion Paratha", 90}, {"Gobi Onion Paratha", 90}, {"Paneer Onion Paratha", 80}, {"Aloo Jeera Paratha", 100}, {"Aloo Gobi Paratha", 80}, {"Aloo Methi Paratha", 80}, {"Aloo Garlic Paratha", 80}, {"Gobi Garlic Paratha", 90}, {"Onion Garlic Paratha", 85}, {"Paneer Garlic Paratha", 85}}, 21},
        {"Shree Vasant", 4, {{"Chole Bhature", 80}, {"Paneer Wale Chole Bhature", 100}, {"Chole Rice", 80}, {"Single Chole", 35}, {"Raita", 30}, {"Sabzi With 4 Roti", 130}, {"Sabzi With Butter Naan", 130}, {"Sabzi With Laccha Paratha", 130}, {"Sabzi With Aaloo Payaz Paratha", 130}, {"Sabzi With Chobi Naan", 130}, {"Sabzi With Paneer Naan", 150}, {"Sabzi With Chur-Chur Naan", 160}, {"Plain Roti", 12}, {"Butter Roti", 15}}, 15},
        {"Dennison's", 5, {{"Special Milestone Veg.", 260}, {"Tawa Vegetable", 240}, {"Veg. Toofani", 245}, {"Veg. Angara.", 240}, {"Veg. Handi Masala", 230}, {"Veg. Kadai.", 225}, {"Veg. Kolhapuri", 225}, {"Veg. Jaipuri", 235}, {"Veg. Diwani Handi", 240}, {"Veg. Makkhan Wala", 240}, {"Shahi Vegetable", 230}, {"Methi Mattar Malai", 215}, {"Methi Mattar Masala", 210}, {"Methi Mushroom Mattar Masala", 210}, {"Baby Corn Mushroom Masala", 225}, {"Baby Corn Butter Masala", 225}, {"Palak Corn Capsicum", 350}, {"Plain Palak", 210}, {"Mix Veg.", 210}, {"Boiled Veg.", 210}, {"Tomato Corn Bharta", 250}, {"Chana Masala", 200}, {"Aloo Mattar Masala", 235}, {"Aloo Gobi Dry", 240}, {"Aloo Shuki Bhaji", 240}, {"Aloo Palak", 259}}, 26},
        {"Hans", 6, {{"Butter Dabeli.", 25}, {"Schezwan Dabeli.", 40}, {"Mayonnaise Dabeli.", 45}, {"Cheese Dabeli", 50}, {"Bowl Dabeli", 45}, {"Cheese Bowl Dabeli", 65}, {"Grilled Dabeli", 40}, {"Grilled Schezwan Dabeli", 50}, {"Grilled Mayonnaise Dabeli", 55}, {"Grilled Cheese Dabeli.", 65}, {"Sandwich Dabeli.", 50}, {"Sandwich Grilled Dabeli.", 65}, {"Sandwich Mayo Dabeli.", 70}, {"Sandwich Cheese Dabeli", 75}, {"JAIN DABELIS", 65}, {"Jain Butter Dabeli", 45}, {"Jain Cheese Dabeli", 30}, {"Jain Grilled Dabeli.", 87}}, 18},
        {"Hotel Naveen", 7, {{"Virgin Mojito", 50}, {"Cucumber Refresher", 50}, {"Rose Mint", 80}, {"Shirley Temple", 90}, {"Guava Tini", 90}, {"Ocean Blue", 80}, {"Pina Colada", 90}, {"Apple Cool", 90}, {"Chilli Guava", 80}, {"Ginger Fantasy", 80}, {"Green Apple Mojito", 70}, {"Spicy Orange", 80}, {"Watermelon", 70}, {"Coconut Mojito", 90}, {"Green Apple Fizzy", 90}, {"Rose Sparkler", 70}, {"Ginger Blue", 80}, {"Summer King", 70}, {"Cinderella", 90}, {"Mocktail Punch", 90}, {"Black Shot", 60}, {"Tequila Sunrise", 50}, {"Mojito", 50}, {"Daiquiri", 80}, {"Pina Colada", 90}, {"Blue Lagoon", 90}, {"Black Russian", 80}, {"Tequila & Lemon", 90}, {"Whisky Cola", 90}, {"Melon", 80}, {"Peppermint", 80}, {"Vodka Lime", 70}, {"Peach Schnapps", 80}, {"Jagermeister", 70}, {"Cheese & Tomato", 90}, {"Supreme Chicken", 70}, {"Mexican", 80}, {"Italian Style", 70}, {"American Hot", 90}, {"Vegetarian", 90}, {"Smokey BBQ", 90}, {"Hawaiian", 70}, {"Pepperoni", 80}, {"Ham & Cheese", 70}, {"Meatball Feast", 90}}, 45},
        {"The Emperor", 8, {{"Egg Roll", 60}, {"Spring Rolls", 50}, {"Fried Shrimp", 50}, {"Steamed Dumplings", 80}, {"Steamed Wontons", 90}, {"Shu Mai", 90}, {"Shrimp Toast", 80}, {"Crab Rangoons", 90}, {"Wonton Soup", 90}, {"Egg Drop Soup", 80}, {"Wonton Egg Drop Mix $4.75", 80}, {"Hot & Sour Soup", 70}, {"Vegetable Noodle Soup", 80}, {"House Special Soup", 70}, {"Chicken & Corn Soup", 90}, {"Plain Fried Rice", 90}, {"Roast Pork", 70}, {"Shrimp Fried Rice", 80}, {"Vegetable Fried Rice", 70}, {"House Special Fried Rice", 90}, {"Young Chow Fried Rice", 90}, {"Chop Suey", 90}, {"Chicken Chop Suey", 70}, {"Shrimp Chop Suey", 80}, {"Vegetable Chop Suey", 70}, {"Combination Chop Suey", 90}, {"Shrimp Chop Suey", 90}, {"Vegetable Chop Suey", 60}, {"Combination Chop", 50}, {"Suey", 50}}, 30},
        {"Domino's Pizza", 9, {{"Veggie Paradise Pizza", 269}, {"Margheria Pizza", 109}, {"Peppy Paneer Pizza", 269}, {"Paneer Non-Veg Loaded", 199}, {"Indi Tandoori Paneer Pizza", 319}, {"Farmhouse Pizza", 269}, {"Taco Mexicana Non-Veg", 85}, {"Cheese n Corn", 219}, {"Veg Loaded", 189}, {"Chicken Dominator Pizza", 369}, {"Chicken Pepperconi Pizza", 369}}, 11},
        {"Mcdonald's", 10, {{"Virgin Mojito", 50}, {"Paneer Wale Chole Bhature", 100}, {"Chole Rice", 80}, {"Cucumber Refresher", 50}, {"Veggie Paradise Pizza", 269}, {"Margheria Pizza", 109}, {"Peppy Paneer Pizza", 269}, {"Paneer Non-Veg Loaded", 199}, {"Indi Tandoori Paneer Pizza", 319}, {"Farmhouse Pizza", 269}, {"Taco Mexicana Non-Veg", 85}, {"Cheese n Corn", 219}, {"Veg Loaded", 189}, {"Chicken Dominator Pizza", 369}, {"Chicken Pepperconi Pizza", 369}}, 15}
        // Add more hotels and menus as needed
    };
    struct Hotel_name hotels_names[] = {
        {"Baskin Robbins", 1},
        {"Balaji Wines", 2},
        {"Hotel President", 3},
        {"Shree Vasant", 4},
        {"Dennison's", 5},
        {"Hans", 6},
        {"Hotel Naveen", 7},
        {"The Emperor", 8},
        {"Domino's Pizza", 9},
        {"Mcdonald's", 10}};

    struct SelectedItem selectedItems[MAX_SELECTED_ITEMS];
    int numSelectedItems = 0;

    printf("\n%-5s %-30s\n", "No.", "Hotel Name");
    printf("--------------------------\n");

    for (int i = 0; i < sizeof(hotels_names) / sizeof(hotels_names[0]); i++)
    {
        printing_hotel_name(hotels_names[i]);
    }

    int choosing_hotel = 0;
    scanf("%d", &choosing_hotel);

   switch (choosing_hotel)
{
case 1 ... 10:
    printHotelMenu(hotels[choosing_hotel - 1]);

    // Add a message and terminate the loop
    printf("Menu displayed. Exiting...\n");
    break;

case 11:
    printf("x\n");
    break;

default:
    printf("Invalid input\n");
    break;
}

int selectedHotel, selectedItem;
double totalPrice = 0;

printf("Enter the number of the hotel you want to order from: ");
scanf("%d", &selectedHotel);

// Check if the selected hotel number is valid
if (selectedHotel >= 1 && selectedHotel <= sizeof(hotels) / sizeof(hotels[0]))
{
    // Allow the user to select items from the menu
    printf("Enter the number of the item you want to order (enter 0 to finish): ");
    scanf("%d", &selectedItem);

    while (selectedItem != 0 && numSelectedItems < MAX_SELECTED_ITEMS)
    {
        // Check if the selected item number is valid
        if (selectedItem >= 1 && selectedItem <= hotels[selectedHotel - 1].menuSize)
        {
            // Add the selected item to the array
            strcpy(selectedItems[numSelectedItems].name, hotels[selectedHotel - 1].menu[selectedItem - 1].name);
            selectedItems[numSelectedItems].price = hotels[selectedHotel - 1].menu[selectedItem - 1].price;
            totalPrice += selectedItems[numSelectedItems].price;

            // Increment the number of selected items
            numSelectedItems++;
        }
        else
        {
            printf("Invalid item number. Please enter a valid number or 0 to finish.\n");
        }

        // Prompt the user to enter the next item or 0 to finish
        printf("Enter the number of the item you want to order (enter 0 to finish): ");
        scanf("%d", &selectedItem);
    }

    // Print the selected items and total price
    printf("\nSelected Items:\n");
    printf("%-30s %s\n", "Food Name", "Price");
    printf("---------------------------------------------\n");

    for (int i = 0; i < numSelectedItems; i++)
    {
        printf("%-30s $%.2f\n", selectedItems[i].name, selectedItems[i].price);
    }

    printf("\nTotal Price: $%.2f\n", totalPrice);
}
else
{
    printf("Invalid hotel number.\n");
}

    return 0;
}
