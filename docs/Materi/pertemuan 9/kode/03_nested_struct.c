#include <stdio.h>

typedef struct
{
    int hari;
    int bulan;
    int tahun;
} Tanggal;

typedef struct
{
    char nama[50];
    char nim[15];
    Tanggal tanggalLahir; // struct di dalam struct
    float ipk;
} Mahasiswa;

int main(void)
{
    // Langkah 1: inisialisasi dengan {} bersarang
    Mahasiswa mhs = {"Budi Santoso", "2600001", {17, 8, 2007}, 3.75};

    printf("Nama          : %s\n", mhs.nama);
    printf("Tanggal lahir : %02d-%02d-%d\n",
           mhs.tanggalLahir.hari,
           mhs.tanggalLahir.bulan,
           mhs.tanggalLahir.tahun);

    // Langkah 2: ubah member bersarang
    mhs.tanggalLahir.tahun = 2006;
    printf("Tahun lahir dikoreksi menjadi: %d\n", mhs.tanggalLahir.tahun);

    // Langkah 3: array of struct yang memiliki nested struct
    Mahasiswa kelas[2] = {
        {"Siti Aminah", "2600002", {3, 12, 2006}, 3.90},
        {"Andi Wijaya", "2600003", {25, 1, 2007}, 3.40}};

    printf("\n%-15s%-12s%s\n", "Nama", "Lahir", "IPK");
    for (int i = 0; i < 2; i++)
    {
        printf("%-15s%02d-%02d-%-6d%.2f\n",
               kelas[i].nama,
               kelas[i].tanggalLahir.hari,
               kelas[i].tanggalLahir.bulan,
               kelas[i].tanggalLahir.tahun,
               kelas[i].ipk);
    }

    return 0;
}