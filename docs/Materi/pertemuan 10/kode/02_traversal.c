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

// Traversal: mencetak seluruh isi list
void printList(const Node *head)
{
    const Node *temp = head; // temp berjalan, head tetap di tempat
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Traversal: menghitung jumlah node
int countNodes(const Node *head)
{
    int count = 0;
    const Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Traversal: mengembalikan seluruh node ke sistem
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;       // simpan node yang akan dibuang
        head = head->next; // geser head dulu
        free(temp);        // baru buang node lama
    }
}

int main(void)
{
    // List kosong: head bernilai NULL
    Node *head = NULL;
    printf("List kosong  : ");
    printList(head);
    printf("Jumlah node  : %d\n\n", countNodes(head));

    // Bangun 101 -> 102 -> 103 -> 104
    head = createNode(101);
    head->next = createNode(102);
    head->next->next = createNode(103);
    head->next->next->next = createNode(104);

    printf("Isi antrean  : ");
    printList(head);
    printf("Jumlah node  : %d\n", countNodes(head));

    freeList(head);
    head = NULL;

    return 0;
}
