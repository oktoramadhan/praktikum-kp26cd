#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char nama[50];
    char nim[15];
    float ipk;
};

int main(void)
{
    // Langkah 1: isi member satu per satu
    struct Mahasiswa mhs1;
    strcpy(mhs1.nama, "Budi Santoso"); // string -> strcpy()
    strcpy(mhs1.nim, "2600001");
    mhs1.ipk = 3.75; // angka  -> '=' biasa

    // Langkah 2: inisialisasi sesuai urutan member
    struct Mahasiswa mhs2 = {"Siti Aminah", "2600002", 3.90};

    // Langkah 3: designated initializer (urutan bebas)
    struct Mahasiswa mhs3 = {.ipk = 3.40, .nama = "Andi Wijaya", .nim = "2600003"};

    printf("=== Data Mahasiswa ===\n");
    printf("1. %s | %s | %.2f\n", mhs1.nama, mhs1.nim, mhs1.ipk);
    printf("2. %s | %s | %.2f\n", mhs2.nama, mhs2.nim, mhs2.ipk);
    printf("3. %s | %s | %.2f\n", mhs3.nama, mhs3.nim, mhs3.ipk);

    // Langkah 4: struct dapat disalin dengan '='
    struct Mahasiswa cadangan = mhs1;
    mhs1.ipk = 4.00;

    printf("\n=== Salinan struct ===\n");
    printf("mhs1     : %.2f\n", mhs1.ipk);
    printf("cadangan : %.2f (tidak ikut berubah)\n", cadangan.ipk);

    return 0;
}