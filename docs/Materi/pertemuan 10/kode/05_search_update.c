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

// Search versi 1: apakah nilai ada? (1 = ada, 0 = tidak ada)
int search(const Node *head, int key)
{
    const Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Search versi 2: di posisi berapa? (0 = tidak ditemukan)
int searchPosition(const Node *head, int key)
{
    int pos = 1;
    const Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return 0;
}

// Update berdasarkan posisi (1 = berhasil, 0 = posisi tidak ada)
int updateAtPosition(Node *head, int position, int newValue)
{
    int pos = 1;
    Node *temp = head;
    while (temp != NULL && pos < position)
    {
        temp = temp->next;
        pos++;
    }
    if (temp == NULL || position < 1)
    {
        return 0;
    }
    temp->data = newValue;
    return 1;
}

// Update semua node yang bernilai oldValue; mengembalikan jumlah yang diganti
int replaceAll(Node *head, int oldValue, int newValue)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main(void)
{
    Node *head = NULL;
    int nomor[] = {101, 102, 103, 102, 105};
    for (int i = 0; i < 5; i++)
    {
        head = insertEnd(head, nomor[i]);
    }
    printf("Antrean awal : ");
    printList(head);

    // Searching
    printf("\n--- Searching ---\n");
    printf("search(103)         : %d\n", search(head, 103));
    printf("search(999)         : %d\n", search(head, 999));

    int pos = searchPosition(head, 103);
    if (pos != 0)
    {
        printf("Nomor 103 ada di posisi ke-%d\n", pos);
    }
    pos = searchPosition(head, 999);
    if (pos == 0)
    {
        printf("Nomor 999 tidak ditemukan\n");
    }
    printf("Nomor 102 pertama kali di posisi ke-%d\n", searchPosition(head, 102));

    // Updating
    printf("\n--- Updating ---\n");
    if (updateAtPosition(head, 5, 104))
    {
        printf("Posisi 5 diganti jadi 104: ");
        printList(head);
    }
    if (!updateAtPosition(head, 9, 777))
    {
        printf("Posisi 9 tidak ada, tidak ada yang berubah\n");
    }

    int jumlah = replaceAll(head, 102, 110);
    printf("%d node bernilai 102 diganti jadi 110: ", jumlah);
    printList(head);

    freeList(head);
    head = NULL;

    return 0;
}
