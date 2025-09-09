#include <iostream>
using namespace std;

void balik(int *arr, int ukuran)
{
    int *awal = arr;
    int *akhir = arr + ukuran - 1;

    while (awal < akhir)
    {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main()
{
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    cout << "Array sebelum di balik: ";
    for (int i = 0; i < 7; i++)
    {
        cout << prima[i] << " ";
    }
    balik(prima, 7);
    cout << endl
         << "Array setelah di balik: ";
    for (int i = 0; i < 7; i++)
    {
        cout << prima[i] << " ";
    }
    return 0;
}