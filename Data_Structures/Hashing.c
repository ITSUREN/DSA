#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./modules/c_functions_linux.c"

#define SIZE 10

struct HashNode {
    char *key;
    int value;
    struct HashNode *next; // For chaining
};

struct HashTable {
    int size;
    struct HashNode **array;
};

// Create a new hash node
struct HashNode* createNode(char *key, int value) {
    struct HashNode* node = (struct HashNode*) malloc(sizeof(struct HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

// Create a new hash table
struct HashTable* createHashTable(int size) {
    struct HashTable* table = (struct HashTable*) malloc(sizeof(struct HashTable));
    table->size = size;
    table->array = (struct HashNode**) malloc(size * sizeof(struct HashNode*));
    for (int i = 0; i < size; ++i)
        table->array[i] = NULL;
    return table;
}

// Hash function
int hashFunction(char *key, int size) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i)
        hash = (hash + key[i]) % size;
    return hash;
}

int linearProbe(int index, int attempt, int size) {
    return (index + attempt) % size;
}

int quadraticProbe(int index, int attempt, int size) {
    return (index + attempt * attempt) % size;
}

void insert(struct HashTable *table, char *key, int value, int (*probe)(int, int, int)) {
    int index = hashFunction(key, table->size);
    int attempt = 0;

    while (table->array[index] != NULL) {
        index = probe(index, ++attempt, table->size);
    }

    table->array[index] = createNode(key, value);
}

int search(struct HashTable *table, char *key) {
    int index = hashFunction(key, table->size);
    int attempt = 0;

    while (table->array[index] != NULL) {
        if (strcmp(table->array[index]->key, key) == 0)
            return table->array[index]->value;
        index = linearProbe(index, ++attempt, table->size); // Using linear probing for searching
    }
    return -1; // Key not found
}

// Insert a key-value pair into the hash table using chaining
void insertChaining(struct HashTable *table, char *key, int value) {
    int index = hashFunction(key, table->size);
    struct HashNode *newNode = createNode(key, value);
    newNode->next = table->array[index];
    table->array[index] = newNode;
}

int searchChaining(struct HashTable *table, char *key) {
    int index = hashFunction(key, table->size);
    struct HashNode *current = table->array[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return -1; // Key not found
}

void insertBucket(struct HashTable *table, char *key, int value) {
    int index = hashFunction(key, table->size);
    struct HashNode *newNode = createNode(key, value);

    if (table->array[index] == NULL) {
        table->array[index] = newNode;
    } else {
        struct HashNode *current = table->array[index];
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

int searchBucket(struct HashTable *table, char *key) {
    int index = hashFunction(key, table->size);
    struct HashNode *current = table->array[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return -1; // Key not found
}

void SearchInterface(struct HashTable *table) {
    char key[20];
    printf("\nEnter a key to search: ");
    scanf("%s", key);
        // Search for the key using different techniques
    int result;

    result = search(table, key);
    if (result != -1) {
        printf("Value found using linear probing: %d\n", result);
    } else {
        printf("Value not found using linear probing\n");
    }

    result = searchChaining(table, key);
    if (result != -1) {
        printf("Value found using chaining: %d\n", result);
    } else {
        printf("Value not found using chaining\n");
    }

    result = searchBucket(table, key);
    if (result != -1) {
        printf("Value found using bucket addressing: %d\n", result);
    } else {
        printf("Value not found using bucket addressing\n");
    }
    printf("\n\nSAUGAT TAMANG [79010256]");
    getch();
}

void menu() {
    printf("\nChoose a collision resolution technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Chaining\n");
    printf("4. Bucket Addressing\n");
    printf("5. Search\n");
    printf("0. Exit\n");
}

int main() {
    struct HashTable* table;
    int choice, size, value;
    char key[20];

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    table = createHashTable(size);

    do {
        system("cls");
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(table, key, value, linearProbe);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(table, key, value, quadraticProbe);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertChaining(table, key, value);
                break;
            case 4:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertBucket(table, key, value);
                break;
            case 5:
                SearchInterface(table);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Key-value pair inserted successfully.\n");
        }

    } while (choice != 0);
    return 0;
}

