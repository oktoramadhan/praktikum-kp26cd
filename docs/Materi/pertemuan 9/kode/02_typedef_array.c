#include <stdio.h>

#define JUMLAH 4

typedef struct
{
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

int main(void)
{
    Mahasiswa daftar[JUMLAH] = {
        {"Budi", "2600001", 3.75},
        {"Siti", "2600002", 3.90},
        {"Andi", "2600003", 3.40},
        {"Dewi", "2600004", 3.55}};

    // 1. Tampilkan tabel
    printf("%-4s%-10s%-10s%s\n", "No", "Nama", "NIM", "IPK");
    printf("--------------------------\n");
    for (int i = 0; i < JUMLAH; i++)
    {
        printf("%-4d%-10s%-10s%.2f\n",
               i + 1, daftar[i].nama, daftar[i].nim, daftar[i].ipk);
    }

    // 2. Hitung rata-rata IPK
    float total = 0;
    for (int i = 0; i < JUMLAH; i++)
    {
        total += daftar[i].ipk;
    }
    printf("\nRata-rata IPK : %.2f\n", total / JUMLAH);

    // 3. Cari IPK tertinggi (simpan INDEX-nya)
    int terbaik = 0;
    for (int i = 1; i < JUMLAH; i++)
    {
        if (daftar[i].ipk > daftar[terbaik].ipk)
        {
            terbaik = i;
        }
    }
    printf("IPK tertinggi : %s (%.2f)\n", daftar[terbaik].nama, daftar[terbaik].ipk);

    return 0;
}