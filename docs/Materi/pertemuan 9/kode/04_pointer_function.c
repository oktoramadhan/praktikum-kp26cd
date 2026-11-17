#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

// Return struct: function "merakit" data
Mahasiswa buatMahasiswa(const char *nama, const char *nim, float ipk)
{
    Mahasiswa mhs;
    strcpy(mhs.nama, nama);
    strcpy(mhs.nim, nim);
    mhs.ipk = ipk;
    return mhs;
}

// const + pointer: hanya membaca, tanpa menyalin seluruh struct
void tampilkan(const Mahasiswa *mhs)
{
    printf("%s (%s) - IPK %.2f\n", mhs->nama, mhs->nim, mhs->ipk);
}

// BY VALUE: yang diubah hanyalah salinan
void perbaikiIpkByValue(Mahasiswa mhs, float ipkBaru)
{
    mhs.ipk = ipkBaru;
}

// BY POINTER: mengubah data milik pemanggil
void perbaikiIpkByPointer(Mahasiswa *mhs, float ipkBaru)
{
    mhs->ipk = ipkBaru;
}

int main(void)
{
    Mahasiswa budi = buatMahasiswa("Budi Santoso", "2600001", 3.07);

    printf("[Awal]               ");
    tampilkan(&budi);

    // Langkah 1: pointer ke struct, '.' vs '->'
    Mahasiswa *ptr = &budi;
    printf("\nbudi.ipk   = %.2f\n", budi.ipk);   // variabel -> '.'
    printf("ptr->ipk   = %.2f\n", ptr->ipk);     // pointer  -> '->'
    printf("(*ptr).ipk = %.2f\n\n", (*ptr).ipk); // sama dengan ptr->ipk

    // Langkah 2: by value -> TIDAK berubah
    perbaikiIpkByValue(budi, 3.70);
    printf("[Setelah by value]   ");
    tampilkan(&budi);

    // Langkah 3: by pointer -> BERUBAH
    perbaikiIpkByPointer(&budi, 3.70);
    printf("[Setelah by pointer] ");
    tampilkan(&budi);

    return 0;
}