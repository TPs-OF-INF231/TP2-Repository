#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d'un nouveau nœud
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée dans la liste doublement chaînée
Node* insertSorted(Node* head, int value) {
    Node* newNode = createNode(value);

    // Cas où la liste est vide
    if (!head) return newNode;

    // Cas où l'élément doit être inséré en tête
    if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}

// Affichage de la liste dans le sens direct
void printListForward(Node* head) {
    printf("Liste (croissante) : ");
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Affichage de la liste dans le sens inverse
void printListBackward(Node* head) {
    if (!head) return;
    while (head->next) head = head->next;

    printf("Liste (décroissante) : ");
    while (head) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

// Libération de la mémoire
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, val;

    printf("Combien d'éléments à insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &val);
        head = insertSorted(head, val);
    }

    printListForward(head);
    printListBackward(head);

    freeList(head);
    return 0;
}