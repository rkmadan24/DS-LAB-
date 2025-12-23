#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Hash function */
int hashFunction(int key) {
    return key % m;
}

/* Insert key using Linear Probing */
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % m;

        if (index == startIndex) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}

/* Display Hash Table */
void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("HT[%d] : EMPTY\n", i);
        else
            printf("HT[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    /* Initialize hash table */
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}

