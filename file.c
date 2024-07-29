#include <stdio.h>
#include <stdlib.h>

struct User
{
    int userID;
    char userName[50];
    char address[100];
    char phoneNumber[15];
    int UPI_ID;
};

void printUserData(const struct User *user)
{
    printf("User ID: %d\n", user->userID);
    printf("User Name: %s\n", user->userName);
    printf("Address: %s\n", user->address);
    printf("Phone Number: %s\n", user->phoneNumber);
    printf("UPI_ID: %s\n", user->UPI_ID);
    printf("\n");
}
void addUser(struct User *users, int *userCount, const struct User *newUser)
{
    users[*userCount] = *newUser;
    (*userCount)++;
}

void writeUserToFile(FILE *file, const struct User *user)
{
    fprintf(file, "User ID: %d\n", user->userID);
    fprintf(file, "User Name: %s\n", user->userName);
    fprintf(file, "Address: %s\n", user->address);
    fprintf(file, "Phone Number: %s\n", user->phoneNumber);
    fprintf(file, "UPI_ID: %s\n", user->UPI_ID);
    fprintf(file, "\n");
}
int findUserByID(const struct User *users, int userCount, int targetID)
{
    for (int i = 0; i < userCount; ++i)
    {
        if (users[i].userID == targetID)
        {
            return i; // Return the index of the user if found
        }
    }
    return -1; // Return -1 if user is not found
}
void Registration(struct User *newUser, int *userCount, struct User *users, FILE *file)
{
    printf("Enter User ID: ");
    scanf("%d", &newUser->userID);

    // Check if the user ID already exists
    if (findUserByID(users, *userCount, newUser->userID) != -1)
    {
        printf("User with the same ID already exists. Registration failed.\n");
        return;
    }

    printf("Enter User Name: ");
    scanf(" %[^\n]", newUser->userName);
    printf("Enter Address: ");
    scanf(" %[^\n]", newUser->address);
    printf("Enter Phone Number: ");
    scanf(" %[^\n]", newUser->phoneNumber);
    printf("Enter UPI_ID: ");
    scanf(" %[^\n]", newUser->UPI_ID);

    // Add the new user to the array
    addUser(users, userCount, newUser);

    // Write the new user's information to the file
    fseek(file, 0, SEEK_END); // Move the file cursor to the end
    writeUserToFile(file, newUser);

    printf("Registration successful!\n");
}


int main()
{
    // Open a file for reading
    FILE *file = fopen("user_database.txt", "r+");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file!\n");
        return 1; // Exit with an error code
    }

    // Count the number of users in the file
    int userCount = 0;
    int count = 0;
    while (fscanf(file, "User ID: %*d") == 0)
    {
        // Consume a line in the file
        char buffer[256];
        fgets(buffer, sizeof(buffer), file);
        count++;
        if (count == 5)
            userCount++;
        if (count == 5)
            count = 0;
    }

    // Reset file position to the beginning
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the array of users
    struct User *users = (struct User *)malloc(userCount * sizeof(struct User));
    if (users == NULL)
    {
        fprintf(stderr, "Memory allocation error!\n");
        fclose(file);
        return 1; // Exit with an error code
    }

    // Read data from the file into the array
    for (int i = 0; i < userCount; ++i)
    {
        fscanf(file, "User ID: %d\n", &users[i].userID);
        fscanf(file, "User Name: %[^\n]\n", users[i].userName);
        fscanf(file, "Address: %[^\n]\n", users[i].address);
        fscanf(file, "Phone Number: %[^\n]\n", users[i].phoneNumber);
        fscanf(file, "UPI_ID: %[^\n]\n", users[i].UPI_ID);
    }

    // Prompt the user to choose between login and registration
    int choice;
    printf("Choose an option:\n");
    printf("1. Login\n");
    printf("2. Register new member\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        // Login
        int targetID;
        printf("Enter User ID for login: ");
        scanf("%d", &targetID);

        // Find the user in the array
        int userIndex = findUserByID(users, userCount, targetID);
        if (userIndex != -1)
        {
            printf("Login successful!\n");
            // printUserData(&users[userIndex]);
        }
        else
        {
            printf("User not found. Login failed.\n");
            printf("You will be register\n");
            struct User newUser;
            Registration(&newUser, &userCount, users, file);
        }
        break;
    }
    case 2:
    {
        // Registration
        struct User newUser;
        Registration(&newUser, &userCount, users, file);
        break;
    }

    default:
        printf("Invalid choice.\n");
    }

    // Free the allocated memory
    free(users);
    // Close the file
    fclose(file);

    return 0; // Exit successfully
}
