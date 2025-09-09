#include <iostream>
using namespace std;

int main()
{
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int jumlah = 0;

    for (int i = 0; i < 3; i += 2)
    {
        for (int j = 0; j < 3; j++)
        {
            jumlah += matriks[i][j];
        }
    }

    cout << "\nMatriks 3x3:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matriks[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "\nJumlah elemen pada baris indeks genap (0 dan 2): " << jumlah << endl;

    return 0;
}
