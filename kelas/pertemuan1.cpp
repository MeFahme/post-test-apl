#include <iostream>
using namespace std;

int main(){
    // int nilai;
    // cout << "masukkan nilai : ";
    // cin >> nilai;

    // if (nilai > 80){
    //     cout << "A";
    // }else if (nilai > 70){
    //     cout << "B";
    // }else {
    //     cout << "C";
    // }
    // return 0;

    // bool rehan = true;
    // bool rajin = false;

    // if (rehan) {
    //     cout << "Nama rehan" << endl;
    //     if (rajin){
    //         cout << "rehan rajin";
    //     } else {
    //         cout << "bukan";
    //     }
    // }

    /*
        for (inialisasi ; kondisi ; update (incre/dercre) ) {
            kode
        }
    */

    // for (int i = 20; i > 1; i--){
    //     cout << i << endl;
    // }

    // int angka = 0;
    // while (true){
    //     angka;
    //     cout << "perulangan-" << angka << endl;
    //     angka++;

    //     if (angka == 20){
    //         break;
    //     }
    // }
    
    // int nilai = 0;
    // // do{
    // //     cout << nilai;
    // //     nilai++;
    // // }while (nilai > 10);

    // while (nilai > 10){
    //     cout << nilai;
    //     nilai++;
    // }
    int arr[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};

    for (int x : arr2){
        cout << x << endl;
    }
    

    return 0;
}