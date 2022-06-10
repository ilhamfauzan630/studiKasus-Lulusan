#include <iostream>
using namespace std;

class Angkatan
{
public:
    void inputJurusan();
    void inputNilai();
    void output();
    int jumlahLulus();
    int terbanyak();
    int terendah();
    int rataRata();
    

private:
    string jurusan[3];
    int nilai[20][20];
    int angkatan;
};

void Angkatan::inputJurusan()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Jurusan ke-" << i + 1 << " : ";
        cin >> jurusan[i];
    }
}

void Angkatan::inputNilai()
{
    cout << "Masukan banyak angkatan yang lulus : ";
    cin >> angkatan;

    for (int i = 0; i < angkatan; i++)
    {
        cout << "Angkatan ke- " << i + 1 << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << jurusan[j] << " : ";
            cin >> nilai[i][j];
        }
    }
}

void Angkatan::output()
{
    cout << "============================================" << endl;
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 3; i++)
    {
        cout << jurusan[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Angkatan ke- " << i + 1 << "\t";

        for (int j = 0; j < 3; j++)
        {
            cout << "\t" << nilai[i][j];
        }
        cout << endl;
    }
}

// sum nilai
int Angkatan::jumlahLulus()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += nilai[i][j];
        }
    }

    return sum;
}

int Angkatan::terbanyak()
{
    int terbanyak = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (nilai[i][j] > terbanyak)
            {
                terbanyak = nilai[i][j];
            }
        }
    }

    return terbanyak;
}

int Angkatan::terendah()
{
    int terendah = 100;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (nilai[i][j] < terendah)
            {
                terendah = nilai[i][j];
            }
        }
    }

    return terendah;
}

int Angkatan::rataRata()
{
    int rataRata = jumlahLulus() / (angkatan*3);
    return rataRata;
}

int main()
{

    Angkatan a;
    a.inputJurusan();
    a.inputNilai();
    a.output();

    cout << "\nJumlah lulus\t: " << a.jumlahLulus() << endl;
    cout << "Lulus terbanyak\t: " << a.terbanyak() << endl;
    cout << "Lulus terrendah\t: " << a.terendah() << endl;
    cout << "Rata-rata\t: " << a.rataRata() << endl;

    return 0;
}