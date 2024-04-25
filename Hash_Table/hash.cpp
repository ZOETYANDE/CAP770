#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

HashNode* create_node(char *key, int value) {
    HashNode *new_node = (HashNode*) malloc(sizeof(HashNode));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int hash_func(char *key) {
    int hash = 0;
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_insert(HashNode*** table, char *key, int value) {
    int index = hash_func(key);
    HashNode *current = (*table)[index];
    if (current == NULL) {
        (*table)[index] = create_node(key, value);
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = create_node(key, value);
    }
}

int hash_table_search(HashNode*** table, char *key) {
    int index = hash_func(key);
    HashNode *current = (*table)[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void hash_table_remove(HashNode*** table, char *key) {
    int index = hash_func(key);
    HashNode *current = (*table)[index];
    HashNode *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                (*table)[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    HashNode** table = calloc(TABLE_SIZE, sizeof(HashNode*));
    hash_table_insert(&table, "one", 1);
    hash_table_insert(&table, "two", 2);
    hash_table_insert(&table, "three", 3);
    printf("Search one: %d\n", hash_table_search(&table, "one"));
    printf("Search two: %d\n", hash_table_search(&table, "two"));
    printf("Search three: %d\n", hash_table_search(&table, "three"));
    hash_table_remove(&table, "two");
    printf("Search two after delete: %d\n", hash_table_search(&table, "two"));
    return 0;
}