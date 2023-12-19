#ifndef DATABASE_H
#define DATABASE_H

typedef struct {
    char model[100];
    float range;
    int capacity;
} Aircraft;

typedef struct {
    Aircraft *arr;
    int n;
} Database;

void createAndSaveDatabase(Database *db);
void loadAndDisplayDatabase(Database *db);
void searchInDatabase(const Database *db);

#endif