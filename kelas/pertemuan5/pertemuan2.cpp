#include <iostream>
using namespace std;

//PASS BY Val 
// void cekArray(int arrayX[100]){
//     cout << "elemen pertama ke 1 : " << arrayX[0];
// }

//PASS BY Ref
// void cekArray(int* arrayX){
//     cout << "elemen pertama ke 1 : " << arrayX[0];
// }


// void ubahNilai (int x) {
//     x = 999;
// }

int ubahNilai (int* x) {
    *x = 999;
}

int main(){

    int a = 10;
    ubahNilai(&a);

    cout  << a;
    // cout << " nilai dari a : " << a;

    

    // int arrayA [100] = {0,1,2};

    // cout << "alamat dari arrayA : " << arrayA << endl;

    // cout << "cek nilai elemen pertama menggunakan pointer : " << endl;

    // cekArray(arrayA);
    
    
    // int a = 10;
    // int *b = &a;

    // cout << "nilai dari a:" << a << endl; //output 10
    // cout << "nilai dari a:" << &a <<endl; //alamat dari a 10

    // cout << "alamat dari a: " << b; //alamat dari a

    // int b;
    // int a = 10;
    // b = a ;

    
    // cout << "value a: " << a <<endl;
    // cout << "value b: " << b <<endl;
    // cout << "alamat a: " << &a <<endl;
    // cout << "alamat b: " << &b <<endl<<endl;
    
    // cout << "pass by ref" <<endl;

    // int c = 10;
    // int *d = &c;

    // cout << "value c " << c <<endl;
    // cout << "value d " << *d <<endl;
    // cout << "Memory c " << &c <<endl;
    // cout << "Memory d " << d <<endl;


}