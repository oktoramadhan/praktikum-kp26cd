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

// Insert di depan: O(1)
Node *insertBeginning(Node *head, int data)
{
    Node *temp = createNode(data);
    temp->next = head; // 1. sambungkan ke list lama
    return temp;       // 2. node baru menjadi head
}

// Insert di belakang: O(n), harus mencari node terakhir
Node *insertEnd(Node *head, int data)
{
    Node *temp = createNode(data);

    if (head == NULL) // list kosong: node baru langsung jadi head
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

// Insert di posisi tertentu (posisi dimulai dari 1)
Node *insertAtPosition(Node *head, int data, int position)
{
    if (position < 1)
    {
        printf("Posisi %d tidak valid!\n", position);
        return head;
    }
    if (position == 1)
    {
        return insertBeginning(head, data);
    }

    // Berhenti di node ke-(position - 1)
    Node *ptr = head;
    for (int pos = 1; pos < position - 1 && ptr != NULL; pos++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Posisi %d melebihi panjang list!\n", position);
        return head;
    }

    Node *temp = createNode(data);
    temp->next = ptr->next; // 1. sambungkan dulu ke sisa list
    ptr->next = temp;       // 2. baru putuskan jalur lama
    return head;
}

int main(void)
{
    Node *head = NULL;

    // Mulai dari list kosong, tambah dari belakang
    head = insertEnd(head, 101);
    head = insertEnd(head, 102);
    head = insertEnd(head, 103);
    printf("Insert di belakang  : ");
    printList(head);

    // Nomor prioritas masuk paling depan
    head = insertBeginning(head, 100);
    printf("Insert di depan     : ");
    printList(head);

    // Menyisip ke posisi 3
    head = insertAtPosition(head, 150, 3);
    printf("Insert di posisi 3  : ");
    printList(head);

    // Kasus tidak valid
    printf("\n");
    head = insertAtPosition(head, 999, 0);
    head = insertAtPosition(head, 999, 10);

    freeList(head);
    head = NULL;

    return 0;
}
