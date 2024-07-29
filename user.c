#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    int userID;
    char userName[50];
    char address[100];
    char phoneNumber[15];
    char UPI_ID[50];
};

struct User users[MAX_USERS];
int totalUsers = 0;

int isUserIDExists(int userID) {
    for (int i = 0; i < totalUsers; ++i) {
        if (users[i].userID == userID) {
            return 1;
        }
    }
    return 0;
}

void getUserDetails() {
    struct User user;
    int userID;

    printf("Enter User ID: ");
    scanf("%d", &userID);

    if (isUserIDExists(userID)) {
        printf("User ID already exists. Please enter a different ID.\n");
        return;
    }

    user.userID = userID;

    printf("Enter User Name: ");
    scanf(" %[^\n]s", user.userName);

    printf("Enter Address: ");
    scanf(" %[^\n]s", user.address);

    printf("Enter Phone Number: ");
    scanf("%s", user.phoneNumber);

    printf("Enter UPI_ID: ");
    scanf(" %[^\n]s", user.UPI_ID);

    users[totalUsers++] = user;
    printf("User added successfully!\n");
}

void displayUserDetails() {
    if (totalUsers == 0) {
        printf("No users found.\n");
        return;
    }

    printf("\nUser Details:\n");
    for (int i = 0; i < totalUsers; ++i) {
        printf("User ID: %d\n", users[i].userID);
        printf("User Name: %s\n", users[i].userName);
        printf("Address: %s\n", users[i].address);
        printf("Phone Number: %s\n", users[i].phoneNumber);
        printf("UPI_ID: %s\n\n", users[i].UPI_ID);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nFood Delivery System\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getUserDetails();
                break;
            case 2:
                displayUserDetails();
                break;
            case 3:
                printf("Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
