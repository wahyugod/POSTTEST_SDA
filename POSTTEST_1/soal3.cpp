#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
};

int main()
{
    Mahasiswa mhs[4];
    cout << "\n=====================================\n";
    cout << "|     Masukkan data 4 mahasiswa     |\n";
    cout << "=====================================\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (mhs[i].ipk > mhs[j].ipk)
            {
                swap(mhs[i], mhs[j]);
            }
        }
    }
    cout << "\n============================================\n";
    cout << "|     Data Mahasiswa setelah diurutkan     |\n";
    cout << "|        berdasarkan IPK (Ascending)       |\n";
    cout << "============================================\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM  : " << mhs[i].nim << endl;
        cout << "IPK  : " << mhs[i].ipk << endl;
    }

    return 0;
}
