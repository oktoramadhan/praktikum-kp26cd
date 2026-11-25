#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Alokasi memori gagal!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertEnd(Node *head, int data)
{
    Node *temp = createNode(data);
    if (head == NULL)
    {
        return temp;
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

void printList(const Node *head)
{
    const Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Delete di depan: O(1)
Node *deleteFirst(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return NULL;
    }
    Node *ptr = head;
    head = head->next; // 1. pindahkan head dulu
    free(ptr);         // 2. baru buang node lama
    return head;
}

// Delete di belakang: O(n), perlu node sebelum yang terakhir
Node *deleteLast(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return NULL;
    }
    if (head->next == NULL) // hanya satu node
    {
        free(head);
        return NULL;
    }

    Node *prev = head;
    Node *curr = head->next;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL; // prev menjadi node terakhir
    free(curr);
    return head;
}

// Delete di posisi tertentu (posisi dimulai dari 1)
Node *deleteAtPosition(Node *head, int position)
{
    if (head == NULL)
    {
        printf("List kosong!\n");
        return NULL;
    }
    if (position < 1)
    {
        printf("Posisi %d tidak valid!\n", position);
        return head;
    }
    if (position == 1)
    {
        return deleteFirst(head);
    }

    // Berhenti di node ke-(position - 1)
    Node *prev = head;
    for (int pos = 1; pos < position - 1 && prev->next != NULL; pos++)
    {
        prev = prev->next;
    }

    Node *target = prev->next;
    if (target == NULL)
    {
        printf("Posisi %d tidak ada di list!\n", position);
        return head;
    }

    prev->next = target->next; // lewati target
    free(target);
    return head;
}

int main(void)
{
    Node *head = NULL;
    for (int i = 101; i <= 106; i++)
    {
        head = insertEnd(head, i);
    }
    printf("Awal                : ");
    printList(head);

    head = deleteFirst(head);
    printf("Hapus depan         : ");
    printList(head);

    head = deleteLast(head);
    printf("Hapus belakang      : ");
    printList(head);

    head = deleteAtPosition(head, 2);
    printf("Hapus posisi 2      : ");
    printList(head);

    // Kasus tidak valid
    printf("\n");
    head = deleteAtPosition(head, 9);

    // Hapus sampai habis
    printf("\nHapus sampai habis:\n");
    while (head != NULL)
    {
        head = deleteFirst(head);
        printList(head);
    }

    // Hapus dari list kosong
    head = deleteLast(head);

    return 0;
}
