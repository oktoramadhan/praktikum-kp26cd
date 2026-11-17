#include <stdio.h>

#define MAX_MAHASISWA 50

typedef struct
{
    char nama[50];
    char nim[15];
    float tugas;
    float uts;
    float uas;
    float nilaiAkhir;
    char grade;
} Mahasiswa;

// Function prototype
void inputMahasiswa(Mahasiswa *mhs);
char tentukanGrade(float nilai);
void hitungNilai(Mahasiswa *mhs);
void tampilkanTabel(const Mahasiswa daftar[], int n);
int cariIndexTerbaik(const Mahasiswa daftar[], int n);

int main(void)
{
    Mahasiswa daftar[MAX_MAHASISWA];
    int n;

    printf("Jumlah mahasiswa (1-%d): ", MAX_MAHASISWA);
    scanf("%d", &n);

    if (n < 1 || n > MAX_MAHASISWA)
    {
        printf("Jumlah mahasiswa tidak valid!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Mahasiswa ke-%d ---\n", i + 1);
        inputMahasiswa(&daftar[i]);
        hitungNilai(&daftar[i]);
    }

    tampilkanTabel(daftar, n);

    int terbaik = cariIndexTerbaik(daftar, n);
    printf("\nNilai tertinggi: %s (%s) dengan nilai %.2f\n",
           daftar[terbaik].nama, daftar[terbaik].nim, daftar[terbaik].nilaiAkhir);

    return 0;
}

void inputMahasiswa(Mahasiswa *mhs)
{
    printf("Nama        : ");
    scanf(" %49[^\n]", mhs->nama);
    printf("NIM         : ");
    scanf("%14s", mhs->nim);
    printf("Nilai Tugas : ");
    scanf("%f", &mhs->tugas);
    printf("Nilai UTS   : ");
    scanf("%f", &mhs->uts);
    printf("Nilai UAS   : ");
    scanf("%f", &mhs->uas);
}

char tentukanGrade(float nilai)
{
    if (nilai >= 85)
    {
        return 'A';
    }
    else if (nilai >= 70)
    {
        return 'B';
    }
    else if (nilai >= 55)
    {
        return 'C';
    }
    else if (nilai >= 40)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

void hitungNilai(Mahasiswa *mhs)
{
    mhs->nilaiAkhir = 0.3 * mhs->tugas + 0.3 * mhs->uts + 0.4 * mhs->uas;
    mhs->grade = tentukanGrade(mhs->nilaiAkhir);
}

void tampilkanTabel(const Mahasiswa daftar[], int n)
{
    printf("\n%-4s%-20s%-10s%-8s%s\n", "No", "Nama", "NIM", "Nilai", "Grade");
    printf("------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-4d%-20s%-10s%-8.2f%c\n",
               i + 1, daftar[i].nama, daftar[i].nim,
               daftar[i].nilaiAkhir, daftar[i].grade);
    }
}

int cariIndexTerbaik(const Mahasiswa daftar[], int n)
{
    int indexTerbaik = 0;

    for (int i = 1; i < n; i++)
    {
        if (daftar[i].nilaiAkhir > daftar[indexTerbaik].nilaiAkhir)
        {
            indexTerbaik = i;
        }
    }

    return indexTerbaik;
}