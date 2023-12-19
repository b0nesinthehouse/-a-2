#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main() {
    Database aircraftDB;
    int choice;

    do {
        printf("\n1. Create and save database\n");
        printf("2. Load and display database\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAndSaveDatabase(&aircraftDB);
                break;
            case 2:
                loadAndDisplayDatabase(&aircraftDB);
                break;
            case 3:
                searchInDatabase(&aircraftDB);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}