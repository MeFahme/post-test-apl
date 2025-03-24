#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX_SIRKUIT = 30;

struct Pengelola {
    string namaPengelola;
    string kontak;
};

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

string adminUsername = "Fahmi";
string adminPassword = "079";

int main() {
    system("cls");
    do {
        system("cls");
        cout << "=============================" << endl;
        cout << "            LOGIN           " << endl;
        cout << "=============================" << endl;
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
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
        } else if (pilihan == 2) {
            int login = 3;
            string username, password;
            bool isAdmin = false;

            while (login > 0) {
                system("cls");
                cout << "=============================" << endl;
                cout << "            LOGIN           " << endl;
                cout << "=============================" << endl;
                cout << "Masukkan Username: ";
                getline(cin, username);
                cout << "Masukkan Password: ";
                getline(cin, password);

                if (username == adminUsername && password == adminPassword) {
                    isAdmin = true;
                    break;
                }

                bool akun = false;
                for (int i = 0; i < jumlahPengguna; i++) {
                    if (users[i].username == username && users[i].password == password) {
                        akun = true;
                        break;
                    }
                }

                if (!akun) {
                    login--;
                    cout << "\nGagal! Percobaan tersisa: " << login << "\n";
                    system("pause");
                } else {
                    break;
                }
            }

            if (login == 0) {
                return 0;
            } 
            else {
                bool loggedIn = true;
                while (loggedIn) {
                    system("cls");
                    cout << "=============================\n";
                    cout << "          MAIN MENU          \n";
                    cout << "          AUTO RACE          \n";
                    cout << "=============================\n";
                    cout << "1. List Sirkuit\n";
                    cout << "2. Ubah Status Reservasi\n";
                    if (isAdmin) {
                        cout << "3. Tambah Sirkuit\n";
                        cout << "4. Hapus Sirkuit\n";
                    }
                    cout << "5. Logout\n";
                    cout << "Pilih menu: ";
                    cin >> pilihan;
                    cin.ignore();

                    if (pilihan == 1) {
                        system("cls");
                        cout << "\n+-----+------------------------+----------------+------------------------+---------------------------+------------------+\n";
                        cout << "| No  |      Nama Sirkuit      |     Lokasi     |      Pengelola         |          Kontak           | Status Reservasi |\n";
                        cout << "+-----+------------------------+----------------+------------------------+---------------------------+------------------+\n";
                        for (int i = 0; i < panjang; i++) {
                            cout << "|  " << setw(1) << i+1 << "  | "
                                << setw(22) << left << sirkuit[i].nama << " | "
                                << setw(14) << left << sirkuit[i].lokasi << " | "
                                << setw(22) << left << sirkuit[i].pengelola.namaPengelola << " | "
                                << setw(25) << left << sirkuit[i].pengelola.kontak << " | "
                                << setw(16) << left << sirkuit[i].statusReservasi << " |\n";
                        }
                        cout << "+-----+------------------------+----------------+------------------------+---------------------------+------------------+\n";
                        system("pause");
                    } 
                    else if (pilihan == 2) {
                        int statusInput;
                        system("cls");
                        cout << "\n+-----+-----------------------+------------------+\n";
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
                        if (index > 0 && index <= MAX_SIRKUIT) {
                            cout << "\n[1] Tersedia\n";
                            cout << "[2] Digunakan\n";
                            cout << "Pilih Status Reservasi Baru (1/2): ";
                            cin >> statusInput;
                            cin.ignore();
                    
                            if (statusInput == 1) {
                                sirkuit[index - 1].statusReservasi = "Tersedia";
                            } 
                            else if (statusInput == 2) {
                                sirkuit[index - 1].statusReservasi = "Digunakan";
                            } 
                            else {
                                cout << "Input tidak valid! Harap masukkan 1 atau 2.\n";
                            }
                    
                            cout << "Status reservasi berhasil diubah menjadi: " << sirkuit[index - 1].statusReservasi << endl;
                        } 
                        else {
                            cout << "Nomor tidak valid!\n";
                        }
                        system("pause");
                    } 
                    else if (isAdmin && pilihan == 3) {
                        if (panjang >= MAX_SIRKUIT) {
                            cout << "Batas jumlah sirkuit tercapai!\n";
                        } 
                        else {
                            cout << "\nMasukkan Nama Sirkuit: ";
                            getline(cin, sirkuit[panjang].nama);
                            cout << "Masukkan Lokasi: ";
                            getline(cin, sirkuit[panjang].lokasi);
                            cout << "Masukkan Nama Pengelola: ";
                            getline(cin, sirkuit[panjang].pengelola.namaPengelola);
                            cout << "Masukkan Kontak Pengelola: ";
                            getline(cin, sirkuit[panjang].pengelola.kontak);
                            sirkuit[panjang].statusReservasi = "Tersedia";
                            panjang++;
                            cout << "Sirkuit berhasil ditambahkan!\n";
                            system("pause");
                        }
                    }
                    else if (isAdmin && pilihan == 4) {
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
                                sirkuit[i] = sirkuit[i + 1]; // Geser elemen ke kiri
                            }
                            panjang--; // Kurangi jumlah sirkuit
                            cout << "Sirkuit berhasil dihapus!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                        system("pause");
                    }
 
                    else if (pilihan == 5) {
                        loggedIn = false;
                    }
                }
            }
        }
    } while (pilihan != 3);
    return 0;
}
