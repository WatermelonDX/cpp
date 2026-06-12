#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Linked List node
struct node {

    // key is string
    char* key;

    // value is also string
    char* value;

    struct node* next;
};

// Like constructor
void setNode(struct node* node, char* key, char* value) {

    node->key = key;
    node->value = value;
    node->next = NULL;

    return;
}

struct hashMap {

    // Current number of elements in hashMap
    // and capacity of hashMap
    int numOfElements, capacity;

    // Holds base address array of linked lists
    struct node** arr;
};

// Like constructor
void initializeHashMap(struct hashMap* mp) {

    // Default capacity
    mp->capacity = 100;

    mp->numOfElements = 0;

    // Array of linked list pointers
    mp->arr = (struct node**)calloc(
        mp->capacity,
        sizeof(struct node*)
    );

    return;
}

int hashFunction(struct hashMap* mp, char* key) {

    int bucketIndex;

    int sum = 0, factor = 31;

    for (int i = 0; i < strlen(key); i++) {

        sum = (
            (sum % mp->capacity)
            + (((int)key[i]) * factor) % mp->capacity
        ) % mp->capacity;

        factor = (
            (factor % __INT16_MAX__)
            * (31 % __INT16_MAX__)
        ) % __INT16_MAX__;
    }

    bucketIndex = sum;

    return bucketIndex;
}

void insert(struct hashMap* mp, char* key, char* value) {

    // Getting bucket index
    int bucketIndex = hashFunction(mp, key);

    // Creating a new node
    struct node* newNode =
        (struct node*)malloc(sizeof(struct node));

    // Setting node values
    setNode(newNode, key, value);

    // No collision
    if (mp->arr[bucketIndex] == NULL) {

        mp->arr[bucketIndex] = newNode;
    }

    // Collision occurred
    else {

        // Insert at head of linked list
        newNode->next = mp->arr[bucketIndex];

        mp->arr[bucketIndex] = newNode;
    }

    // Update number of elements
    mp->numOfElements++;

    return;
}

void deleteKey(struct hashMap* mp, char* key) {

    // Getting bucket index
    int bucketIndex = hashFunction(mp, key);

    struct node* prevNode = NULL;

    // Head node of linked list
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {

        // Key found
        if (strcmp(key, currNode->key) == 0) {

            // Head node deletion
            if (currNode == mp->arr[bucketIndex]) {

                mp->arr[bucketIndex] = currNode->next;
            }

            // Middle or last node deletion
            else {

                prevNode->next = currNode->next;
            }

            free(currNode);

            // Update number of elements
            mp->numOfElements--;

            break;
        }

        prevNode = currNode;

        currNode = currNode->next;
    }

    return;
}

char* search(struct hashMap* mp, char* key) {

    // Getting bucket index
    int bucketIndex = hashFunction(mp, key);

    // Head of linked list
    struct node* bucketHead =
        mp->arr[bucketIndex];

    while (bucketHead != NULL) {

        // Key found
        if (strcmp(bucketHead->key, key) == 0) {
            
            return bucketHead->value;
        }

        bucketHead = bucketHead->next;
    }

    // Key not found
    char* errorMssg =
        (char*)malloc(sizeof(char) * 25);

    strcpy(errorMssg,
           "Oops! No data found.\n");

    return errorMssg;
}

// Driver code
int main() {

    // Initialize hash map
    struct hashMap* mp =
        (struct hashMap*)malloc(sizeof(struct hashMap));

    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "GeeksforGeeks");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    // Key not inserted
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");

    // Delete key
    deleteKey(mp, "decentBoy");

    // Search deleted key
    printf("%s\n", search(mp, "decentBoy"));

    return 0;
}