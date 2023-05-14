#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int stock;
    int sold;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(int id, char* name, int stock) {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    products[num_products].id = id;
    strcpy(products[num_products].name, name);
    products[num_products].stock = stock;
    products[num_products].sold = 0;

    num_products++;

    printf("Product added successfully.\n");
}

void sell_product(int id, int quantity) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            if (products[i].stock < quantity) {
                printf("Error: Not enough stock available.\n");
                return;
            }

            products[i].stock -= quantity;
            products[i].sold += quantity;

            printf("Product sold successfully.\n");
            return;
        }
    }

    printf("Error: Product not found.\n");
}

void display_report() {
    int i;

    printf("Inventory Report\n");
    printf("----------------\n");
    printf("ID\tName\tStock\tSold\n");

    for (i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%d\n", products[i].id, products[i].name, products[i].stock, products[i].sold);
    }
}

int main() {
    int choice;
    int id, stock, quantity;
    char name[50];

    do {
        printf("\nInventory Management System\n");
        printf("---------------------------\n");
        printf("1. Add product\n");
        printf("2. Sell product\n");
        printf("3. Generate report\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);

                printf("Enter product name: ");
                scanf("%s", name);

                printf("Enter product stock: ");
                scanf("%d", &stock);

                add_product(id, name, stock);
                break;

            case 2:
                printf("Enter product ID: ");
                scanf("%d", &id);

                printf("Enter quantity: ");
                scanf("%d", &quantity);

                sell_product(id, quantity);
                break;

            case 3:
                display_report();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
return 0;
}