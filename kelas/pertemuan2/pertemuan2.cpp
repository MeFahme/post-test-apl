#include <iostream>
using namespace std;

#define max 100 // Ukuran maksimum array buah
int panjangArray = 0; // Jumlah elemen saat ini
string arr[max]; // Array dengan ukuran tetap
int pilihan, index;

int main(){

    while(true){

        cout << "Menu Program" << endl;
        cout << "1. input buah" << endl;
        cout << "2. tampilkan buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
    
        cin >> pilihan;

        if(pilihan == 1){
            if (panjangArray < max){
                cout << "masukkan data: ";
                cin >> arr[panjangArray];
                panjangArray++;
            } else if (panjangArray = 0){
                cout << "data masih kosong" << endl;
            } else {
                cout << "data kosong" << endl;
            }
        }

        else if (pilihan == 2){
            if (panjangArray > 0){
                for (int i = 0; i < panjangArray; i++){
                    cout << i +1 << ". " << arr[i] << endl;
                }
            } else {
                cout << "data kosong" << endl;
            }
        }
        



    }







    // string nama[] = {"Ilma", "Haqi", "Dzaki", "Musang", "udin"};

    // cout << sizeof(nama) / sizeof(nama[0]) << endl; //total elemen array
    // cout << sizeof(nama) / sizeof(string) << endl; //total elemen array
    // cout << sizeof(string)<< endl; //total elemen array

    // // cout << nama[-5] << endl;

    // cout << nama[0];

    // int panjang = sizeof(nama) / sizeof(string);

    // for (int i = 0; i << panjang; i++){
    //     cout << nama[i] << endl;
    // }

    // for (string x : nama){
    //     cout << x << endl;
    // }

    // string nama [4][4] = {
    //     {"ilma", "infor", "b24", "079"},
    //     {"dontol", "sisfor", "b25", "069"},
    //     {"adit", "medfo", "b33", "059"},
    //     {"jejo", "elekt", "b99", "049"}
    // };


    // cout << sizeof(nama)  / sizeof(string);
    // cout << nama [3][1] << endl;

    // int arr[3][3][3] = {
    //     {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    //     },

    //     {
    //     {10, 11, 12},
    //     {13, 14, 15},
    //     {16, 17, 18}
    //     },

    //     {
    //     {19, 20, 21},
    //     {22, 23, 24},
    //     {25, 26, 27}
    //     }

    //     };

    //     cout << arr[1][2][1] << endl; // Output: 17


    return 0;
}