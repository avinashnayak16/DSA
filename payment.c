#include <stdio.h>

struct Transaction {
    float amount;
    char description[100];
};

struct Payment {
    int method;
    char upiId[50];
    struct Transaction transaction;
};

void processUpiPayment(struct Payment *userPayment) {
    printf("Processing UPI payment with ID: %s\n", userPayment->upiId);
    printf("Transaction details - Amount: $%.2f, Description: %s\n",
           userPayment->transaction.amount, userPayment->transaction.description);
    printf("Payment successful. Thank you!\n");
}

int main() {
    struct Payment userPayment;

    printf("Choose payment method:\n");
    printf("1. UPI\n");
    printf("2. Cash on Delivery\n");
    scanf("%d", &userPayment.method);

    if (userPayment.method == 1) {
        printf("Enter UPI ID: ");
        scanf("%s", userPayment.upiId);

        printf("Enter transaction amount: $");
        scanf("%f", &userPayment.transaction.amount);

        printf("Enter transaction description: ");
        scanf("%s", userPayment.transaction.description);

        processUpiPayment(&userPayment);
    } else if (userPayment.method == 2) {
        printf("Cash on Delivery selected. Amount will be collected upon delivery.\n");
    } else {
        printf("Invalid payment method selected. Please try again.\n");
    }

    return 0;
}