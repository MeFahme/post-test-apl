#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX_SIRKUIT = 30;

struct Pengelola {
    string namaPengelola;
    string kontak;
};
///
struct Sirkuit {
    string nama;
    string lokasi;
    string statusReservasi;
    Pengelola pengelola;
};

Sirkuit sirkuit[MAX_SIRKUIT] = {
    {"Mandalika", "Pulau Lombok", "Tersedia", {"PT Mandalika Racing", "mandalika@racing.com"}},
    {"Internasional Sentul", "Bogor", "Tersedia", {"Sentul Management", "sentul@racing.com"}},
    {"Jaya Ancol", "Jakarta", "Tersedia", {"Ancol Circuit Ltd", "ancol@racing.com"}}
};
int panjang = 3;

struct User {
    string username;
    string password;
};

const int MAX_USERS = 100;
User users[MAX_USERS];
int jumlahPengguna = 0;
int pilihan, index;

//id pass admin
string adminUsername = "Fahmi";
string adminPassword = "079";

//buat akun
void registerUser() {
    if (jumlahPengguna >= MAX_USERS) {
        cout << "Batas pengguna tercapai!\n";
    } else {
        cout << "\n=== Register ===\n";
        cout << "Masukkan Username: ";
        cin >> users[jumlahPengguna].username;
        cout << "Masukkan Password: ";
        cin >> users[jumlahPengguna].password;
        cout << "Registrasi Berhasil!\n";
        jumlahPengguna++;
    }
    system("pause");
}

//kode login
bool loginUser(bool &isAdmin) {
    int login = 3;
    string username, password;
    //cin.ignore();
    while (login > 0) {
        system("cls");
        cout << "=============================\n";
        cout << "            LOGIN           \n";
        cout << "=============================\n";
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        if (username == adminUsername && password == adminPassword) {
            isAdmin = true;
            return true;
        }

        for (int i = 0; i < jumlahPengguna; i++) {
            if (users[i].username == username && users[i].password == password) {
                return true;
            }
        }

        login--;
        cout << "\nGagal! Percobaan tersisa: " << login << "\n";
        system("pause");
    }
    return false;
}

//rekursif
void tampilkanSirkuitRekursif(Sirkuit sirkuit[], int index, int jumlahSirkuit) {
    if (index >= jumlahSirkuit) return;
    cout << "|  " << setw(1) << index + 1 << "  | "
         << setw(22) << left << sirkuit[index].nama << " | "
         << setw(14) << left << sirkuit[index].lokasi << " | "
         << setw(22) << left << sirkuit[index].pengelola.namaPengelola << " | "
         << setw(25) << left << sirkuit[index].pengelola.kontak << " | "
         << setw(16) << left << sirkuit[index].statusReservasi << " |\n";
    tampilkanSirkuitRekursif(sirkuit, index + 1, jumlahSirkuit);
}

//menampilkan list sirkuit yang ada
void tampilkanSirkuit() {
    system("cls");
    cout << "\n+-----+------------------------+----------------+------------------------+---------------------------+------------------+\n";
    cout << "| No  |      Nama Sirkuit      |     Lokasi     |      Pengelola         |          Kontak           | Status Reservasi |\n";
    cout << "+-----+------------------------+----------------+------------------------+---------------------------+------------------+\n";
    tampilkanSirkuitRekursif(sirkuit, 0, panjang);
    cout << "+-----+------------------------+----------------+------------------------+---------------------------+------------------+\n";
    system("pause");
}

//mengubah status reservasi sirkuit
void ubahStatusReservasi() {
    int statusInput;
    system("cls");
    cout << "\n+-----+------------------------+------------------+\n";
    cout << "| No  |      Nama Sirkuit      | Status Reservasi |\n";
    cout << "+-----+------------------------+------------------+\n";
    for (int i = 0; i < panjang; i++) {
        cout << "|  " << setw(1) << i+1 << "  | "
             << setw(22) << left << sirkuit[i].nama << " | "
             << setw(16) << left << sirkuit[i].statusReservasi << " |\n";
    }
    cout << "+-----+------------------------+------------------+\n";
    cout << "\nPilih nomor sirkuit: ";
    cin >> index;
    if (index > 0 && index <= panjang) {
        cout << "\n[1] Tersedia\n";
        cout << "[2] Digunakan\n";
        cout << "Pilih Status Reservasi Baru (1/2): ";
        cin >> statusInput;
        cin.ignore();

        if (statusInput == 1) sirkuit[index - 1].statusReservasi = "Tersedia";
        else if (statusInput == 2) sirkuit[index - 1].statusReservasi = "Digunakan";
        else cout << "Input tidak valid! Harap masukkan 1 atau 2.\n";

        cout << "Status reservasi berhasil diubah menjadi: " << sirkuit[index - 1].statusReservasi << endl;
    } else {
        cout << "Nomor tidak valid!\n";
    }
    system("pause");
}

// overloading
void tambahSirkuit(string nama, string lokasi, string namaPengelola, string kontak) {
    if (panjang >= MAX_SIRKUIT) {
        cout << "Batas jumlah sirkuit tercapai!\n";
    } else {
        sirkuit[panjang].nama = nama;
        sirkuit[panjang].lokasi = lokasi;
        sirkuit[panjang].pengelola.namaPengelola = namaPengelola;
        sirkuit[panjang].pengelola.kontak = kontak;
        sirkuit[panjang].statusReservasi = "Tersedia";
        panjang++;
        cout << "Sirkuit berhasil ditambahkan!\n";
    }
    system("pause");
}

//menghapus list sirkuit
void hapusSirkuit() {
    system("cls");
    cout << "\n+-----+------------------------+----------------+\n";
    cout << "| No  |      Nama Sirkuit      |     Lokasi     |\n";
    cout << "+-----+------------------------+----------------+\n";
    for (int i = 0; i < panjang; i++) {
        cout << "|  " << setw(1) << i+1 << "  | "
             << setw(22) << left << sirkuit[i].nama << " | "
             << setw(14) << left << sirkuit[i].lokasi << " |\n";
    }
    cout << "+-----+------------------------+----------------+\n";
    cout << "\nPilih nomor sirkuit yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= panjang) {
        for (int i = index - 1; i < panjang - 1; i++) {
            sirkuit[i] = sirkuit[i + 1];
        }
        panjang--;
        cout << "Sirkuit berhasil dihapus!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
    system("pause");
}

//address-of
void ubahNamaSirkuit(Sirkuit& s) {
    cout << "Nama sirkuit saat ini: " << s.nama << endl;
    cout << "Masukkan nama baru: ";
    getline(cin, s.nama);
    cout << "Nama sirkuit berhasil diubah menjadi: " << s.nama << endl;
}

//dereference
void tampilkanPengelola(const Pengelola* p) {
    cout << "Nama Pengelola   : " << p->namaPengelola << endl;
    cout << "Kontak Pengelola : " << p->kontak << endl;
}

//menu admin
void menuAdmin() {
    bool loggedIn = true;
    while (loggedIn) {
        system("cls");
        cout << "=============================\n";
        cout << "         MENU ADMIN          \n";
        cout << "         AUTO RACE           \n";
        cout << "=============================\n";
        cout << "1. List Sirkuit\n";
        cout << "2. Ubah Status Reservasi\n";
        cout << "3. Tambah Sirkuit\n";
        cout << "4. Hapus Sirkuit\n";
        cout << "5. Ubah Nama Sirkuit (Pointer)\n";
        cout << "6. Tampilkan Pengelola (Pointer)\n";
        cout << "7. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) tampilkanSirkuit();
        else if (pilihan == 2) ubahStatusReservasi();
        else if (pilihan == 3) {
            string nama, lokasi, pengelola, kontak;
            cout << "Masukkan Nama Sirkuit: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Lokasi: ";
            getline(cin, lokasi);
            cout << "Masukkan Nama Pengelola: ";
            getline(cin, pengelola);
            cout << "Masukkan Kontak Pengelola: ";
            getline(cin, kontak);
            tambahSirkuit(nama, lokasi, pengelola, kontak);
        }
        else if (pilihan == 4) hapusSirkuit();
        else if (pilihan == 5) {
            system("cls");
            cout << "Pilih sirkuit yang ingin diubah namanya:\n";
            for (int i = 0; i < panjang; i++) {
                cout << i + 1 << ". " << sirkuit[i].nama << endl;
            }
            cout << "Pilih nomor: ";
            cin >> index;
            cin.ignore();
        
            if (index > 0 && index <= panjang) {
                ubahNamaSirkuit(sirkuit[index - 1]);
            } else {
                cout << "Nomor tidak valid!\n";
            }
            system("pause");
        }
        
        else if (pilihan == 6) {
            system("cls");
            cout << "Pilih sirkuit untuk lihat info pengelola:\n";
            for (int i = 0; i < panjang; i++) {
                cout << i + 1 << ". " << sirkuit[i].nama << endl;
            }
            cout << "Pilih nomor: ";
            cin >> index;
            cin.ignore();
        
            if (index > 0 && index <= panjang) {
                tampilkanPengelola(&sirkuit[index - 1].pengelola);
            } else {
                cout << "Nomor tidak valid!\n";
            }
            system("pause");
        }
        else if (pilihan == 7) loggedIn = false;
    }
}

//menu user
void menuUser() {
    bool loggedIn = true;
    while (loggedIn) {
        system("cls");
        cout << "=============================\n";
        cout << "         MENU USER           \n";
        cout << "         AUTO RACE           \n";
        cout << "=============================\n";
        cout << "1. List Sirkuit\n";
        cout << "2. Ubah Status Reservasi\n";
        cout << "3. Tampilkan Pengelola\n";
        cout << "4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) tampilkanSirkuit();
        else if (pilihan == 2) ubahStatusReservasi();
        else if (pilihan == 3) {
            system("cls");
            cout << "Pilih sirkuit untuk lihat info pengelola:\n";
            for (int i = 0; i < panjang; i++) {
                cout << i + 1 << ". " << sirkuit[i].nama << endl;
            }
            cout << "Pilih nomor: ";
            cin >> index;
            cin.ignore();
        
            if (index > 0 && index <= panjang) {
                tampilkanPengelola(&sirkuit[index - 1].pengelola);
            } else {
                cout << "Nomor tidak valid!\n";
            }
            system("pause");
        }
        else if (pilihan == 4) loggedIn = false;
    }
}

//program utama
int main() {
    system("cls");
    bool running = true;

    while (running) {
        system("cls");
        cout << "=============================\n";
        cout << "            LOGIN           \n";
        cout << "=============================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                registerUser();
                break;

            case 2: {
                bool isAdmin = false;
                if (loginUser(isAdmin)) {
                    if (isAdmin) menuAdmin();
                    else menuUser();
                } else {
                    cout << "Gagal Login setelah 3 kali Percobaan\n";
                    system("pause");
                }
                break;
            }

            case 3:
                running = false;
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    }

    return 0;
}
