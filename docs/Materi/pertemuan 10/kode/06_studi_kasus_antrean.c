#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data; // nomor antrean
    struct Node *next;
} Node;

// Function prototype
Node *createNode(int data);
Node *insertBeginning(Node *head, int data);
Node *insertEnd(Node *head, int data);
Node *deleteFirst(Node *head);
Node *deleteAtPosition(Node *head, int position);
int searchPosition(const Node *head, int key);
int countNodes(const Node *head);
void printList(const Node *head);
void freeList(Node *head);
int bacaAngka(const char *prompt);
void tampilkanMenu(void);

int main(void)
{
    Node *head = NULL;
    int nomorBerikutnya = 1;
    int pilihan;

    do
    {
        tampilkanMenu();
        pilihan = bacaAngka("Pilihan: ");

        if (pilihan == 1)
        {
            head = insertEnd(head, nomorBerikutnya);
            printf("Nomor %d masuk antrean (urutan ke-%d)\n",
                   nomorBerikutnya, countNodes(head));
            nomorBerikutnya++;
        }
        else if (pilihan == 2)
        {
            head = insertBeginning(head, nomorBerikutnya);
            printf("Nomor %d masuk antrean prioritas (urutan ke-1)\n", nomorBerikutnya);
            nomorBerikutnya++;
        }
        else if (pilihan == 3)
        {
            if (head == NULL)
            {
                printf("Tidak ada antrean yang bisa dilayani\n");
            }
            else
            {
                printf("Memanggil nomor %d ke loket\n", head->data);
                head = deleteFirst(head);
            }
        }
        else if (pilihan == 4)
        {
            int nomor = bacaAngka("Nomor yang dibatalkan: ");
            int pos = searchPosition(head, nomor);
            if (pos == 0)
            {
                printf("Nomor %d tidak ada di antrean\n", nomor);
            }
            else
            {
                head = deleteAtPosition(head, pos);
                printf("Nomor %d dibatalkan\n", nomor);
            }
        }
        else if (pilihan == 5)
        {
            int nomor = bacaAngka("Nomor yang dicari: ");
            int pos = searchPosition(head, nomor);
            if (pos == 0)
            {
                printf("Nomor %d tidak ada di antrean\n", nomor);
            }
            else
            {
                printf("Nomor %d ada di urutan ke-%d (%d orang di depannya)\n",
                       nomor, pos, pos - 1);
            }
        }
        else if (pilihan == 6)
        {
            printf("Antrean (%d orang): ", countNodes(head));
            printList(head);
        }
        else if (pilihan != 0)
        {
            printf("Pilihan tidak dikenal\n");
        }
    } while (pilihan != 0);

    freeList(head); // jangan lupa mengembalikan memori
    head = NULL;
    printf("Loket ditutup. Terima kasih!\n");

    return 0;
}

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

Node *insertBeginning(Node *head, int data)
{
    Node *temp = createNode(data);
    temp->next = head;
    return temp;
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

Node *deleteFirst(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deleteAtPosition(Node *head, int position)
{
    if (head == NULL || position < 1)
    {
        return head;
    }
    if (position == 1)
    {
        return deleteFirst(head);
    }

    Node *prev = head;
    for (int pos = 1; pos < position - 1 && prev->next != NULL; pos++)
    {
        prev = prev->next;
    }

    Node *target = prev->next;
    if (target == NULL)
    {
        return head;
    }
    prev->next = target->next;
    free(target);
    return head;
}

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

// Membaca angka dengan aman: mengulang jika input bukan angka.
// Jika input habis (EOF), mengembalikan 0.
int bacaAngka(const char *prompt)
{
    int nilai;
    int hasil;

    printf("%s", prompt);
    while ((hasil = scanf("%d", &nilai)) != 1)
    {
        if (hasil == EOF)
        {
            return 0;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
            // buang sisa input yang salah
        }
        printf("Masukkan angka: ");
    }
    return nilai;
}

void tampilkanMenu(void)
{
    printf("\n=== LOKET ANTREAN KAMPUS ===\n");
    printf("1. Ambil nomor (antre di belakang)\n");
    printf("2. Ambil nomor prioritas (antre di depan)\n");
    printf("3. Layani antrean terdepan\n");
    printf("4. Batalkan nomor antrean\n");
    printf("5. Cari nomor antrean\n");
    printf("6. Tampilkan antrean\n");
    printf("0. Keluar\n");
}
