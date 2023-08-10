#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct {
    int key;
    int value;
    int isOccupied;
} HashEntry;
void initializeTable(HashEntry table[], int size) {
    for (int i = 0; i < size; i++) {
        table[i].key = -1;
        table[i].value = -1;
        table[i].isOccupied = 0;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(HashEntry table[], int key, int value, int size) {
    int index = hash(key);
    while (table[index].isOccupied) {
        index = (index + 1) % size;
    }
    table[index].key = key;
    table[index].value = value;
    table[index].isOccupied = 1;
}
int retrieve(HashEntry table[], int key, int size) {
    int index = hash(key);
    while (table[index].isOccupied) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % size;
    }
    return -1; 
}
int main() {
    HashEntry hashTable[TABLE_SIZE];
    initializeTable(hashTable, TABLE_SIZE);
    insert(hashTable, 5, 50, TABLE_SIZE);
    insert(hashTable, 15, 150, TABLE_SIZE);
    insert(hashTable, 25, 250, TABLE_SIZE);
    printf("Value at key 15: %d\n", retrieve(hashTable, 15, TABLE_SIZE));
    printf("Value at key 7: %d\n", retrieve(hashTable, 7, TABLE_SIZE));
    return 0;
}
