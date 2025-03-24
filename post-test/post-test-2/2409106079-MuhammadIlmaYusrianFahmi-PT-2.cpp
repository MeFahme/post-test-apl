#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int MAX_SIRKUIT = 30;
int INFO_COUNT = 4;
int panjang = 3;

string sirkuit[30][4] = {
    {"Mandalika", "Pulau Lombok", "Sirkuit modern dengan pemandangan indah, memiliki lintasan cepat dan tikungan menantang","Digunakan"},
    {"Internasional Sentul", "Bogor", "Sirkuit balap di Indonesia dengan kombinasi lintasan lurus dan tikungan teknika","Tersedia"},
    {"Jaya Ancol", "Jakarta", "Sirkuit jalan raya yang menantang dengan tikungan tajam dan pemandangan perkotaan","Tersedia"}
};

int pilihan, index;

int main() {
    system("cls");
    string username, password;
    string id = "MuhammadIlmaYusrianFahmi";
    string pass = "2409106079";
    int login = 3;

    string tableHeader = 
    "\n+-----+------------------------+----------------+--------------------------------------------------------------------------------------------+------------------+\n"
    "| No  |      Nama Sirkuit      |     Lokasi     |                                           Deskripsi                                        | Status Reservasi |\n"
    "+-----+------------------------+----------------+--------------------------------------------------------------------------------------------+------------------+\n";

    string tableFooter =
    "+-----+------------------------+----------------+--------------------------------------------------------------------------------------------+------------------+\n";


    while (login > 0) {
        system("cls");
        cout << "=============================\n";
        cout << "            LOGIN           \n";
        cout << "=============================\n";
        cout << "Masukkan Username: ";
        getline (cin, username);
        cout << "Masukkan Password: ";
        getline (cin, password);

        if (username == id && password == pass) {
            cout << "\nLogin Berhasil!\n";
            system("pause");
            break;
        } 
        else {
            login--;
            cout << "\nGagal! Percobaan tersisa: " << login << "\n";
            system("pause");
        }
    }

    if (login == 0) {
        cout << "\nGagal Login! Program Terhenti.\n";
        return 0;
    } 
    else {
        int pilihan = 0;
        while (true) {
            do {
                system("cls");
                cout << "=============================\n";
                cout << "          MAIN MENU          \n";
                cout << "          AUTO RACE          \n";
                cout << "=============================\n";
                cout << "1. List Sirkuit\n";
                cout << "2. Tambah Sirkuit\n";
                cout << "3. Ubah Status Reservasi\n";
                cout << "4. Hapus Data\n";
                cout << "5. Keluar\n";
                cout << "\nPilih menu: ";
                cin >> pilihan;
                cin.ignore();
        
                switch (pilihan) {
                case 1:
                system("cls");
                    if (panjang == 0) {
                        cout << "Tidak ada data sirkuit" << endl;
                        system("pause");
                    } else {
                        cout << tableHeader;

                        for (int i = 0; i < panjang; i++) {
                            cout << "|  " << setw(1) << i+1 << "  | "
                                    << setw(22) << left << sirkuit[i][0] << " | "
                                    << setw(14) << left << sirkuit[i][1] << " | "
                                    << setw(90) << left << sirkuit[i][2] << " | "
                                    << setw(16) << left << sirkuit[i][3] << " |\n";
                        } 
                        cout << tableFooter;
                        system("pause");
                    }
                    break;
        
                case 2:
                system("cls");
                    if (panjang < MAX_SIRKUIT) {
                        string nama,lokasi,deskripsi;

                        do {
                            cout << "Masukkan Nama Sirkuit: ";
                            getline(cin, nama);
                            if (nama.length() > 20){
                                cout << "Nama terlalu panjang! Maksimal 20 karakter. Silakan coba lagi.\n";
                            }
                        } while (nama.length() > 20);
                        
                        sirkuit[panjang][0] = nama;
                        
                        do {
                            cout << "Masukkan Lokasi Sirkuit: ";
                            getline(cin, lokasi);
                            if (lokasi.length() > 12){
                                cout << "Lokasi terlalu panjang! Maksimal 12 karakter. Silakan coba lagi.\n";
                            }
                        } while (lokasi.length() > 12);

                        sirkuit[panjang][1] = lokasi;

                        do {
                            cout << "Masukkan Deskripsi Sirkuit (max 100 karakter): ";
                            getline(cin, deskripsi);
                
                            if (deskripsi.length() > 90) {
                                cout << "Deskripsi terlalu panjang! Maksimal 100 karakter. Silakan coba lagi.\n";
                            }
                        } while (deskripsi.length() > 100);

                        sirkuit[panjang][2] = deskripsi;

                        sirkuit[panjang][3] = "Tersedia";

                        panjang++;
                        cout << "\nSirkuit berhasil ditambahkan!" << endl;
                        system("pause");

                    } else {
                        system("cls");
                        cout << "Kapasitas sirkuit penuh!" << endl;
                        system("pause");
                    }
                    break;

                    case 3:
                    system("cls");
                    if (panjang == 0) {
                        cout << "Belum ada sirkuit untuk diubah." << endl;
                    } else {
                        cout << "\n======== Daftar Reservasi Sirkuit ========\n";
                        for (int i = 0; i < panjang; i++) {
                            cout << i + 1 << ". " << sirkuit[i][0] << " (" << sirkuit[i][3] << ")\n";
                        }
                
                        cout << "Pilih nomor sirkuit yang mau diubah: ";
                        cin >> index;
                
                        if (index > 0 && index <= panjang) { 
                            int statusInput;
                
                            do {
                                cout << "\n[1] Tersedia\n";                              
                                cout << "[2] Digunakan\n";                              
                                cout << "Pilih Status Reservasi Baru (1/2): ";
                                cin >> statusInput;
                                cin.ignore();
                
                                if (statusInput == 1) {
                                    sirkuit[index - 1][3] = "Tersedia";
                                } 
                                else if (statusInput == 2) {
                                    sirkuit[index - 1][3] = "Digunakan";
                                } 
                                else {
                                    cout << "Input tidak valid! Harap masukkan 1 atau 2.\n";
                                }
                
                            } while (statusInput != 1 && statusInput != 2);
                        
                            cout << "Reservasi berhasil diubah!\n";
                        } else {
                            cout << "Nomor tidak valid!" << endl;
                        }
                    }
                    system("pause");
                    break;
        
                    case 4:
                    system("cls");
                        if (panjang == 0) {
                            cout << "Belum ada sirkuit untuk dihapus." << endl;
                        } 
                        else {
                            cout << "\n======== Daftar Sirkuit ========\n";
                            for (int i = 0; i < panjang; i++) {
                                cout << i + 1 << ". " << sirkuit[i][0] << " (" << sirkuit[i][1] << ")\n";
                            }

                            cout << "\nMasukkan nomor sirkuit yang akan dihapus: ";
                            cin >> index;

                            if (index > 0 && index <= panjang) {
                                for (int i = index - 1; i < panjang - 1; i++) {
                                    for (int j = 0; j < INFO_COUNT; j++) {
                                        sirkuit[i][j] = sirkuit[i + 1][j];
                                    }
                                }
                                panjang--;
                                cout << "Sirkuit berhasil dihapus!" << endl;
                                system("pause");
                            } else {
                                cout << "Nomor tidak valid!" << endl;
                                system("pause");
                            }
                        }
                        break;

                    case 5:
                    system("cls");
                        cout << "Program Berhenti" << endl;
                        system("pause");
                        break;

                    default:
                    system("cls");
                        cout << "Pilihan tidak valid! Coba lagi." << endl;
                        system("pause");
                        break;
                }
            }
            while (pilihan != 5);
            return 0;
        }
    }
}