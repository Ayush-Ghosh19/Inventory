#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Creating a structure for inventory item
typedef struct {
    int id;
    char name[50];
    int quantity;
} item;

item inventory[MAX_ITEMS];
int Count = 0;

// Function to add an item to inventory
void addItem() {
    if (Count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    printf("Enter item ID: ");
    scanf("%d", &inventory[Count].id);
    getchar(); // Consume the newline left by scanf

    printf("Enter item name: ");
    fgets(inventory[Count].name, sizeof(inventory[Count].name), stdin);
    inventory[Count].name[strcspn(inventory[Count].name, "\n")] = '\0'; // Remove newline

    printf("Enter item quantity: ");
    scanf("%d", &inventory[Count].quantity);

    Count++;
    printf("Item added successfully!\n");
}

// Function to display all items
void displayItems() {
    if (Count == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\nInventory List:\n");
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < Count; i++) {
        printf("%d\t%s\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

// Function to search for an item by ID or name
void searchItem() {
    char name[50];
    int id, choice;

    printf("Search by: 1. ID  2. Name\n");
    scanf("%d", &choice);
    getchar(); // Consume newline left by scanf

    if (choice == 1) {
        printf("Enter item ID: ");
        scanf("%d", &id);

        for (int i = 0; i < Count; i++) {
            if (inventory[i].id == id) {
                printf("Item found: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
                return;
            }
        }
    } else if (choice == 2) {
        printf("Enter item name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline

        for (int i = 0; i < Count; i++) {
            if (strcmp(inventory[i].name, name) == 0) {
                printf("Item found: ID: %d, Quantity: %d\n", inventory[i].id, inventory[i].quantity);
                return;
            }
        }
    }

    printf("Item not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n2. Display Items\n3. Search Item\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
