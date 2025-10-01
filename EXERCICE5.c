#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Insertion en tête
Node* insertHead(Node* tail, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;

    if (!tail) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* head = tail->next;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;

    return tail;
}

// Insertion en queue
Node* insertTail(Node* tail, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;

    if (!tail) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* head = tail->next;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;

    return newNode; // le nouveau nœud devient le nouveau tail
}

// Affichage de la liste dans le sens direct
void printList(Node* tail) {
    if (!tail) {
        printf("Liste vide.\n");
        return;
    }

    Node* current = tail->next;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("(retour au début)\n");
}

// Libération de la mémoire
void freeList(Node* tail) {
    if (!tail) return;

    Node* current = tail->next;
    Node* temp;
    while (current != tail) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(tail);
}

int main() {
    Node* tail = NULL;
    int choix, val;

    do {
        printf("\nMenu :\n1. Insérer en tête\n2. Insérer en queue\n3. Afficher\n0. Quitter\nChoix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Valeur à insérer en tête : ");
                scanf("%d", &val);
                tail = insertHead(tail, val);
                break;
            case 2:
                printf("Valeur à insérer en queue : ");
                scanf("%d", &val);
                tail = insertTail(tail, val);
                break;
            case 3:
                printList(tail);
                break;
            case 0:
                freeList(tail);
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}