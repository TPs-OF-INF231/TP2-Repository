#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée dans la liste
Node* insertSorted(Node* head, int value) {
    Node* newNode = createNode(value);

    // Cas où la liste est vide ou l'élément doit être en tête
    if (!head || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Parcours pour trouver la bonne position
    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Affichage de la liste
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
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

    printf("Liste triée : ");
    printList(head);

    freeList(head);
    return 0;
}