#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour insérer un élément en fin de liste
Node* insert(Node* head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Fonction pour supprimer toutes les occurrences d'un élément
Node* deleteOccurrences(Node* head, int target) {
    while (head && head->data == target) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data == target) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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

int main() {
    Node* head = NULL;
    int n, val, target;

    printf("Combien d'éléments ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &val);
        head = insert(head, val);
    }

    printf("Liste initiale : ");
    printList(head);

    printf("Entrez l'élément à supprimer : ");
    scanf("%d", &target);

    head = deleteOccurrences(head, target);

    printf("Liste après suppression : ");
    printList(head);

    return 0;
}