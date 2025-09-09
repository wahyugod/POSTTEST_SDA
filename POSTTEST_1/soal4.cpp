#include <iostream>
using namespace std;

void tukar(int &nilai1, int &nilai2)
{
    int temp = nilai1;
    nilai1 = nilai2;
    nilai2 = temp;
}

int main()
{
    int bil1, bil2;
    cout << "\n========================================\n";
    cout << "|       Program Pertukaran Nilai       |\n";
    cout << "========================================\n";
    cout << "Masukkan nilai pertama : ";
    cin >> bil1;
    cout << "Masukkan nilai kedua   : ";
    cin >> bil2;

    cout << "\n========================================\n";
    cout << "|        Hasil Pertukaran Nilai        |\n";
    cout << "========================================";
    cout << "\nSebelum pertukaran:" << endl;
    cout << "Nilai pertama = " << bil1 << ", Nilai kedua = " << bil2 << endl;

    tukar(bil1, bil2);

    cout << "\nSetelah pertukaran:" << endl;
    cout << "Nilai pertama = " << bil1 << ", Nilai kedua = " << bil2 << endl;

    return 0;
}
