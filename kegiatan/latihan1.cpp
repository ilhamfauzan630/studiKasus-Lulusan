#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Matriks
{
    friend ostream& operator<<(ostream& , Matriks&);
    friend istream& operator>>(istream& , Matriks&);

public:
    void baca_matriks();
    void matriks_jumlah(const Matriks&, const Matriks&);
    void perkalian_matriks(const Matriks&, const Matriks&);
    void cetak_matriks();

private:
    int A[10][10];
    int baris, kolom;
};

void Matriks::baca_matriks()
{
    int i, j;
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            cout << "Data [" << i + 1 << "," << j + 1 << "] : ";
            cin >> A[i][j];
        }
    }
}

void Matriks::matriks_jumlah(const Matriks& matriks1, const Matriks& matriks2)
{
    int i, j;
    baris = matriks1.baris;
    kolom = matriks1.kolom;
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            A[i][j] = matriks1.A[i][j] + matriks2.A[i][j];
        }
    }
    cetak_matriks();
}

void Matriks::perkalian_matriks(const Matriks& matriks1, const Matriks& matriks2)
{
    int i, j, k;
    int barkol;
    baris = matriks1.baris;
    kolom = matriks1.kolom;
    barkol = matriks1.kolom;
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            A[i][j] = 0;
            for (k = 0; k < barkol; k++)
            {
                A[i][j] = A[i][j] + matriks1.A[i][k] * matriks2.A[k][j];
            }
        }
    }
    cetak_matriks();
}

void Matriks::cetak_matriks()
{
    int i, j;
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }
}

istream& operator>>(istream& in, Matriks& A)
{
    cout << "Banyak baris : ";
    in >> A.baris;
    cout << "Banyak kolom : ";
    in >> A.kolom;
    cout << "Masukan data matriks\n";
    A.baca_matriks();
    cout << "Matriks yang dibuat adalah :\n";
    A.cetak_matriks();
    return in;
}

ostream& operator<<(ostream& out, Matriks& A)
{
    out << "Matriks yang dibuat adalah :\n";
    A.cetak_matriks();
    return out;
}

main()
{
    Matriks matriks1, matriks2;
    Matriks jumlah;
    cout << "Memasukan data matriks I\n";
    cin >> matriks1;
    cout << "Memasukan data matriks II\n";
    cin >> matriks2;
    
    cout << "Hasil penjumlahan :\n";
    jumlah.matriks_jumlah(matriks1, matriks2);
    
    
    cout << "Hasil perkalian :\n";
    jumlah.perkalian_matriks(matriks1, matriks2);
    
    getch();
    return 0;
}
