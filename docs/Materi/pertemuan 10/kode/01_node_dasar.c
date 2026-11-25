#include <stdio.h>
#include <stdlib.h>

// Definisi node: data + pointer ke node berikutnya
typedef struct Node
{
    int data;          // nomor antrean
    struct Node *next; // alamat node berikutnya
} Node;

// Membuat satu node baru di heap
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Alokasi memori gagal!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL; // node baru belum menunjuk siapa pun
    return newNode;
}

int main(void)
{
    // Langkah 1: buat tiga node. Saat ini ketiganya masih terpisah.
    Node *head = createNode(101);
    Node *kedua = createNode(102);
    Node *ketiga = createNode(103);

    // Langkah 2: sambungkan menjadi rantai 101 -> 102 -> 103 -> NULL
    head->next = kedua;
    kedua->next = ketiga;

    // Langkah 3: akses data lewat head, melompat satu node per tanda panah
    printf("Node pertama : %d\n", head->data);
    printf("Node kedua   : %d\n", head->next->data);
    printf("Node ketiga  : %d\n", head->next->next->data);

    // Langkah 4: node terakhir menunjuk NULL
    if (ketiga->next == NULL)
    {
        printf("\nNode ketiga adalah node terakhir (next == NULL)\n");
    }

    // Langkah 5: kembalikan memori satu per satu
    free(ketiga);
    free(kedua);
    free(head);
    head = NULL;

    return 0;
}
