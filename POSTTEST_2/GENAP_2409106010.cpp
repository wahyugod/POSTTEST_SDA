#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Penerbangan
{
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node
{
    Penerbangan data;
    Node *next;
};

int counter = 0;
string baseKode;
string nama, nim;

Node *head = nullptr;
Node *tail = nullptr;

string generateKode()
{
    if (counter == 0)
    {
        counter++;
        return baseKode;
    }
    else
    {
        return baseKode + "-" + to_string(counter++);
    }
}

void tambahAwal(string tujuan, string status)
{
    Node *baru = new Node;
    baru->data.kodePenerbangan = generateKode();
    baru->data.tujuan = tujuan;
    baru->data.status = status;
    baru->next = head;
    head = baru;

    if (tail == nullptr)
    {
        tail = baru;
    }

    cout << "Jadwal berhasil ditambahkan di awal dengan kode: "
         << baru->data.kodePenerbangan << endl;
}

void tambahAkhir(string tujuan, string status)
{
    Node *baru = new Node;
    baru->data.kodePenerbangan = generateKode();
    baru->data.tujuan = tujuan;
    baru->data.status = status;
    baru->next = nullptr;

    if (head == nullptr)
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }

    cout << "Jadwal berhasil ditambahkan di akhir dengan kode: "
         << baru->data.kodePenerbangan << endl;
}

void sisipJadwal(string tujuan, string status, int posisi)
{
    int panjang = 0;
    Node *hitung = head;
    while (hitung != nullptr)
    {
        panjang++;
        hitung = hitung->next;
    }

    if (posisi < 1 || posisi > panjang + 1)
    {
        cout << "Sisip dinomor " << posisi << " tidak valid. "
             << "Jumlah jadwal saat ini: " << panjang << endl;
        return;
    }

    cout << "Masukkan tujuan: ";
    getline(cin, tujuan);
    cout << "Masukkan status: ";
    getline(cin, status);

    Node *baru = new Node;
    baru->data.kodePenerbangan = generateKode();
    baru->data.tujuan = tujuan;
    baru->data.status = status;
    baru->next = nullptr;

    if (posisi == 1 || head == nullptr)
    {
        baru->next = head;
        head = baru;
        if (tail == nullptr)
            tail = baru;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
        if (baru->next == nullptr)
        {
            tail = baru;
        }
    }

    cout << "Jadwal berhasil disisipkan dengan kode: "
         << baru->data.kodePenerbangan << endl;
}

void hapusAwal()
{
    if (head == nullptr)
    {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == nullptr)
        tail = nullptr; // kalau kosong
    cout << "Jadwal dengan kode " << temp->data.kodePenerbangan
         << " berhasil dihapus.\n";
    delete temp;
}

void hapusAkhir()
{
    if (head == nullptr)
    {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    if (head->next == nullptr)
    { // hanya 1 node
        cout << "Jadwal dengan kode " << head->data.kodePenerbangan << " berhasil dihapus.\n";
        delete head;
        head = tail = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    cout << "Jadwal dengan kode " << tail->data.kodePenerbangan << " berhasil dihapus.\n";
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void updateStatus(string kode)
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    getline(cin, kode);
    while (temp != nullptr)
    {
        if (temp->data.kodePenerbangan == kode)
        {
            cout << "Masukkan status baru: ";
            string statusBaru;
            getline(cin, statusBaru);
            temp->data.status = statusBaru;
            cout << "Status penerbangan " << kode
                 << " berhasil diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

void tampilkan()
{
    if (head == nullptr)
    {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }

    Node *temp = head;

    cout << left << setw(15) << "Kode"
         << setw(20) << "Tujuan"
         << setw(15) << "Status" << endl;
    cout << string(50, '-') << endl;

    while (temp != nullptr)
    {
        cout << left << setw(15) << temp->data.kodePenerbangan
             << setw(20) << temp->data.tujuan
             << setw(15) << temp->data.status << endl;
        temp = temp->next;
    }

    cout << string(50, '=') << endl;
}

int main()
{
    system("cls");
    cout << "\033[32m";
    cout << "Selamat Datang di Program Sistem Jadwal Penerbangan\n";
    cout << "\nMasukkan Nama : ";
    getline(cin, nama);
    cout << "Masukkan NIM  : ";
    getline(cin, nim);

    string tigaDigit = nim.substr(nim.size() - 3);
    baseKode = "JT-" + tigaDigit;

    int pilihan;
    do
    {
        system("cls");
        cout << R"( 
 _______  _       _________ _______          _________   _______  _______           _______  ______            _        _______ 
(  ____ \( \      \__   __/(  ____ \|\     /|\__   __/  (  ____ \(  ____ \|\     /|(  ____ \(  __  \ |\     /|( \      (  ____ \
| (    \/| (         ) (   | (    \/| )   ( |   ) (     | (    \/| (    \/| )   ( || (    \/| (  \  )| )   ( || (      | (    \/
| (__    | |         | |   | |      | (___) |   | |     | (_____ | |      | (___) || (__    | |   ) || |   | || |      | (__    
|  __)   | |         | |   | | ____ |  ___  |   | |     (_____  )| |      |  ___  ||  __)   | |   | || |   | || |      |  __)   
| (      | |         | |   | | \_  )| (   ) |   | |           ) || |      | (   ) || (      | |   ) || |   | || |      | (      
| )      | (____/\___) (___| (___) || )   ( |   | |     /\____) || (____/\| )   ( || (____/\| (__/  )| (___) || (____/\| (____/\
|/       (_______/\_______/(_______)|/     \|   )_(     \_______)(_______/|/     \|(_______/(______/ (_______)(_______/(_______/
                                                                                                                                )"
             << endl;
        cout << "\nHalo " << nama << " dengan NIM " << nim << endl;
        cout << "\n================================================\n";
        cout << "|                     Menu                     |\n";
        cout << "================================================\n";
        cout << "1. Tambah Jadwal Penerbangan Paling Awal\n";
        cout << "2. Tambah Jadwal Penerbangan Paling Akhir\n";
        cout << "3. Sisipkan Jadwal Penerbangan\n";
        cout << "4. Hapus Jadwal Paling Awal\n";
        cout << "5. Hapus Jadwal Paling Akhir\n";
        cout << "6. Update Status Penerbangan\n";
        cout << "7. Tampilkan Semua Jadwal\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        system("cls");

        if (pilihan == 1)
        {
            cout << "==================================================\n";
            cout << "|            TAMBAH JADWAL PENERBANGAN           |\n";
            cout << "==================================================\n";
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            tambahAwal(tujuan, status);
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 1)
        {
            cout << "==================================================\n";
            cout << "|            TAMBAH JADWAL PENERBANGAN           |\n";
            cout << "==================================================\n";
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            tambahAwal(tujuan, status);
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 2)
        {
            cout << "==================================================\n";
            cout << "|            TAMBAH JADWAL PENERBANGAN           |\n";
            cout << "==================================================\n";
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            tambahAkhir(tujuan, status);
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 3)
        {
            cout << "==================================================\n";
            cout << "|           SISIPKAN JADWAL PENERBANGAN          |\n";
            cout << "==================================================\n";
            string tujuan, status;
            int posisi = (nim.back() - '0') + 1;
            sisipJadwal(tujuan, status, posisi);
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 4)
        {
            cout << "==================================================\n";
            cout << "|            HAPUS JADWAL PENERBANGAN            |\n";
            cout << "==================================================\n";
            hapusAwal();
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 5)
        {
            cout << "==================================================\n";
            cout << "|            HAPUS JADWAL PENERBANGAN            |\n";
            cout << "==================================================\n";
            hapusAkhir();
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 6)
        {
            cout << "==================================================\n";
            cout << "|            UPDATE JADWAL PENERBANGAN           |\n";
            cout << "==================================================\n";
            tampilkan();
            string kode;
            updateStatus(kode);
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (pilihan == 7)
        {
            cout << "==================================================\n";
            cout << "|            DAFTAR JADWAL PENERBANGAN           |\n";
            cout << "==================================================\n";
            tampilkan();
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
    } while (pilihan != 0);

    cout << "Terima kasih telah menggunakan sistem!\n";
    return 0;
}
