#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

void createAndSaveDatabase(Database *db) {
    printf("Enter the number of entries: ");
    scanf("%d", &db->n);

    if (db->n <= 0) {
        printf("Invalid number of entries.\n");
        return;
    }

    db->arr = (Aircraft *)malloc(db->n * sizeof(Aircraft));

    for (int i = 0; i < db->n; i++) {
        printf("Entry number %d:\n", i + 1);
        printf("|Enter a model: ");
        scanf("%s", db->arr[i].model);
        printf("|Enter the range: ");
        scanf("%f", &db->arr[i].range);
        printf("|Enter the capacity: ");
        scanf("%d", &db->arr[i].capacity);
    }

    FILE *file = fopen("AircraftDB.txt", "w");
    if (!file) {
        printf("COULDN'T OPEN FILE\n");
        return;
    }

    fprintf(file, "%d\n", db->n);

    for (int i = 0; i < db->n; i++) {
        fprintf(file, "%s %.2f %d\n", db->arr[i].model, db->arr[i].range, db->arr[i].capacity);
    }

    fclose(file);

    printf("Database created and saved successfully.\n");
}

void loadAndDisplayDatabase(Database *db) {
    FILE *file = fopen("AircraftDB.txt", "r");
    if (!file) {
        printf("Could not open the database file.\n");
        return;
    }

    if (fscanf(file, "%d", &db->n) != 1) {
        fclose(file);
        printf("Invalid database format.\n");
        return;
    }

    db->arr = (Aircraft *)malloc(db->n * sizeof(Aircraft));

    for (int i = 0; i < db->n; i++) {
        if (fscanf(file, "%s %f %d", db->arr[i].model, &db->arr[i].range, &db->arr[i].capacity) != 3) {
            break;
        }
    }

    fclose(file);

    printf("\nDatabase loaded and displayed:\n");
    for (int i = 0; i < db->n; i++) {
        printf("Model: %s | Range: %.2f | Capacity: %d\n", db->arr[i].model, db->arr[i].range, db->arr[i].capacity);
    }
}

void searchInDatabase(const Database *db) {
    char searchModel[100];
    printf("Enter the model to search: ");
    scanf("%s", searchModel);

    int found = 0;
    for (int i = 0; i < db->n; i++) {
        if (strcmp(db->arr[i].model, searchModel) == 0) {
            printf("Model found at index %d:\n", i);
            printf("Model: %s | Range: %.2f | Capacity: %d\n", db->arr[i].model, db->arr[i].range, db->arr[i].capacity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Model not found in the database.\n");
    }
}