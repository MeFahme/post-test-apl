#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    system("cls");
    string username, password;
    string id = "Fahmi";
    string pass = "2409106079";
    int login = 3;

    while (login > 0) {
        system("cls");
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

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
            system("cls");
            cout << "\n========= MAIN MENU =========\n";
            cout << "1. Konversi Mata Uang\n";
            cout << "2. Konversi Jarak\n";
            cout << "3. Konversi Waktu\n";
            cout << "4. Konversi Berat\n";
            cout << "5. Keluar\n";
            cout << "Pilih menu: ";
            cin >> pilihan;
    
            if (pilihan == 1) {
                while (true) {
                    system("cls");
                    
                    double rupiah, dolar, euro;
                    double kursDolar = 15500;
                    double kursEuro = 17600;
                    
                    cout << "\n===== Konversi Mata Uang =====\n";
                    cout << "1. Rupiah ke Dolar AS\n";
                    cout << "2. Rupiah ke Euro\n";
                    cout << "3. Dolar AS ke Rupiah\n";
                    cout << "4. Dolar AS ke Euro\n";
                    cout << "5. Euro ke Rupiah\n";
                    cout << "6. Euro ke Dolar AS\n";
                    cout << "7. Kembali\n";
                    cout << "Pilih menu: ";
                    
                    int subPilihan = 0;
                    cin >> subPilihan;
    
                    if (subPilihan == 1) {
                        system("cls");
                        
                        cout << "Rupiah to Dollar AS" << endl;
                        cout << "Masukkan nilai rupiah: ";
                        cin >> rupiah;
                        dolar = rupiah / kursDolar;
                        cout << "\nHasil Konversi:\nRp." << rupiah << " = " << dolar << "$\n";
                        system("pause");
                    } 
                    else if (subPilihan == 2) {
                        system("cls");
                        cout << "Rupiah to Euro" << endl;
                        cout << "Masukkan nilai rupiah: ";
                        cin >> rupiah;
                        euro = rupiah / kursEuro;
                        cout << "\nHasil Konversi:\nRp." << rupiah << " = " << euro << " Euro\n";
                        system("pause");
                    } 
                    else if (subPilihan == 3) {
                        system("cls");
                        
                        cout << "Dollar AS to Rupiah" << endl;
                        cout << "Masukkan nilai Dollar AS: ";
                        cin >> dolar;
                        rupiah = dolar * kursDolar;
                        cout << "\nHasil Konversi:\n" << dolar << "$ = Rp." << rupiah << endl;
                        system("pause");
                    } 
                    else if (subPilihan == 4) {
                        system("cls");
                        
                        cout << "Dollar AS to Euro" << endl;
                        cout << "Masukkan nilai Dollar AS: ";
                        cin >> dolar;
                        euro = dolar * 0.93;
                        cout << "\nHasil Konversi:\n" << dolar << "$ = " << euro << " Euro\n";
                        system("pause");
                    } 
                    else if (subPilihan == 5) {
                        system("cls");
                        
                        cout << "Euro to Rupiah" << endl;
                        cout << "Masukkan Euro: ";
                        cin >> euro;
                        rupiah = euro * kursEuro;
                        cout << "\nHasil Konversi:\n" << euro << " Euro = Rp." << rupiah << endl;
                        system("pause");
                    } 
                    else if (subPilihan == 6) {
                        system("cls");
                        
                        cout << "Euro to Dollar AS" << endl;
                        cout << "Masukkan Euro: ";
                        cin >> euro;
                        dolar = euro * 1.08;
                        cout << "\nHasil Konversi:\n" << euro << " Euro = " << dolar << "$\n";
                        system("pause");
                    } 
                    else if (subPilihan == 7) {
                        break;
                    } 
                    else {
                        system("cls");
                        cout << "Input tidak valid\n";
                        system("pause");
                    }
                }

            }
            else if (pilihan == 2) {
                while (true)
                {
                    system("cls");
                    double kilo, meter, centi;
        
                    cout << "\n===== Konversi Jarak =====\n";
                    cout << "1. Kilometer ke Meter\n";
                    cout << "2. Kilometer ke Centimeter\n";
                    cout << "3. Meter ke Kilometer\n";
                    cout << "4. Meter ke Centimeter\n";
                    cout << "5. Centimeter ke Kilometer\n";
                    cout << "6. Centimeter ke Meter\n";
                    cout << "7. Kembali\n";
                    
                    cout << "Pilih menu: ";
                    int subPilihan = 0;
                    cin >> subPilihan;
    
                    if (subPilihan == 1){
                        system("cls");
                        
                        cout << "==== KM to M ====" << endl;
                        cout << "Masukkan Nilai Kilometer : ";
                        cin >> kilo;
    
                        meter = kilo * 1000;
                        cout << "\nHasil Konversi:\n";
                        cout << kilo << " KM"<< " = " << meter << " M\n";
                        system("pause");
    
                    }
                    else if (subPilihan == 2){
                        system("cls");
                        
                        cout << "==== KM to CM ====" << endl;
                        cout << "Masukkan Nilai Kilometer : ";
                        cin >> kilo;
    
                        centi = kilo * 100000;
                        cout << "\nHasil Konversi:\n";
                        cout << kilo <<" KM"<< " = " << centi << " CM\n";
                        system("pause");
                        
                    }
                    else if (subPilihan == 3){
                        system("cls");
                        
                        cout << "==== M to KM ====" << endl;
                        cout << "Masukkan Nilai Meter : ";
                        cin >> meter;
    
                        kilo = meter / 1000;
                        cout << "\nHasil Konversi:\n";
                        cout << meter <<" M"<< " = " << kilo << " KM\n";
                        system("pause");
                        
                    }
                    else if (subPilihan == 4){
                        system("cls");
                        
                        cout << "==== M to CM ====" << endl;
                        cout << "Masukkan Nilai Meter : ";
                        cin >> meter;
    
                        centi = meter * 100;
                        cout << "\nHasil Konversi:\n";
                        cout << meter <<" M"<< " = " << centi << " CM\n";
                        system("pause");
      
                    }
                    else if (subPilihan == 5){
                        system("cls");
                        
                        cout << "==== CM to KM ====" << endl;
                        cout << "Masukkan Nilai Centimeter : ";
                        cin >> centi;
    
                        kilo = centi / 100000;
                        cout << "\nHasil Konversi:\n";
                        cout << centi <<" CM"<< " = " << kilo << " KM\n";
                        system("pause");
    
                    }
                    else if (subPilihan == 6){
                        system("cls");
                        
                        cout << "==== CM to M ====" << endl;
                        cout << "Masukkan Nilai Centimeter : ";
                        cin >> centi;
    
                        meter = centi / 100;
                        cout << "\nHasil Konversi:\n";
                        cout << centi <<" CM"<< " = " << meter << " M\n";
                        system("pause");                    
                    }
                    else if(subPilihan == 7){
                        break;
                    }
                    else{
                        system("cls");
                        cout << "Input tidak valid\n";
                        system("pause");
                    }
                }
                
            } 
            else if (pilihan == 3) {
                while (true)
                {
                    system("cls");
                    double jam, menit, detik;
                    int sisaDetik;
    
                    cout << "\n===== Konversi Waktu =====\n";
                    cout << "1. Jam ke Menit\n";
                    cout << "2. Jam ke Detik\n";
                    cout << "3. Menit ke Jam\n";
                    cout << "4. Menit ke Detik\n";
                    cout << "5. Detik ke Jam\n";
                    cout << "6. Detik ke Menit\n";
                    cout << "7. Kembali\n";
                    
                    cout << "Pilih menu: ";
                    int subPilihan = 0;
                    cin >> subPilihan;
                
                    if (subPilihan == 1){
                        system("cls");
                        
                        cout << "==== Jam to Menit ====" << endl;
                        cout << "Masukkan Nilai Jam : ";
                        cin >> jam;
                
                        menit = jam * 60;
                        cout << "\nHasil Konversi:\n";
                        cout << jam << " Jam"<< " = " << menit << " Menit\n";
                        system("pause");
                    }
                    else if (subPilihan == 2){
                        system("cls");
                        
                        cout << "==== Jam to Detik ====" << endl;
                        cout << "Masukkan Nilai Jam : ";
                        cin >> jam;
                
                        detik = jam * 3600;
                        cout << "\nHasil Konversi:\n";
                        cout << jam << " Jam"<< " = " << detik << " Detik\n";
                        system("pause"); 
                    }
                    else if (subPilihan == 2){
                        system("cls");
                        
                        cout << "==== Jam to Detik ====" << endl;
                        cout << "Masukkan Nilai Jam : ";
                        cin >> jam;
                
                        detik = jam * 3600;
                        cout << "\nHasil Konversi:\n";
                        cout << jam << " Jam"<< " = " << detik << " Detik\n";
                        system("pause");  
                    }
                    else if (subPilihan == 3){
                        system("cls");
                        
                        cout << "==== Menit to Jam ====" << endl;
                        cout << "Masukkan Nilai Menit : ";
                        cin >> menit;
                
                        jam = menit / 60;
                        cout << "\nHasil Konversi:\n";
                        cout << menit << " Menit"<< " = " << jam << " Jam\n";
                        system("pause");
       
                    }
                    else if (subPilihan == 4){
                        system("cls");
                        
                        cout << "==== Menit to Detik ====" << endl;
                        cout << "Masukkan Nilai Menit : ";
                        cin >> menit;
                
                        detik = menit * 60;
                        cout << "\nHasil Konversi:\n";
                        cout << menit << " Menit"<< " = " << detik << " Detik\n";
                        system("pause");
       
                    }
                    else if (subPilihan == 5){
                        system("cls");
                        
                        cout << "==== Detik to Jam ====" << endl;
                        cout << "Masukkan Nilai Detik : ";
                        cin >> detik;
                
                        jam = detik / 3600;
                        cout << "\nHasil Konversi:\n";
                        cout << detik << " Detik"<< " = " << jam << " Jam\n";
                        system("pause");   
                    }
                    else if (subPilihan == 6){
                        system("cls");
                        
                        cout << "==== Detik to Menit ====" << endl;
                        cout << "Masukkan Nilai Detik : ";
                        cin >> detik;
                
                        menit = detik / 60;
                        sisaDetik = (int)detik % 60;
                        cout << "\nHasil Konversi:\n";
                        cout << detik << " Detik"<< " = " << (int)menit << " Menit " << sisaDetik << " Detik\n";
                        system("pause");    
                    }
                    else if(subPilihan == 7){
                        break;
                    }
                    else{
                        system("cls");
                        cout << "Input tidak valid\n";
                        system("pause");
                    }
                }
                
            } 
            else if (pilihan == 4) {
                while (true)
                {
                    system("cls");
                    double kilogram, gram, miligram;
    
                    cout << "\n===== Konversi Berat =====\n";
                    cout << "1. Kilogram ke gram\n";
                    cout << "2. Kilogram ke miligram\n";
                    cout << "3. Gram ke kilogram\n";
                    cout << "4. Gram ke miligram\n";
                    cout << "5. miligram ke kilogram\n";
                    cout << "6. miligram ke gram\n";
                    cout << "7. Kembali\n";
                    
                    cout << "Pilih menu: ";
                    int subPilihan = 0;
                    cin >> subPilihan;
    
                    if (subPilihan == 1){
                        system("cls");
                        
                        cout << "==== Kilogram to gram ====" << endl;
                        cout << "Masukkan Nilai kilogram : ";
                        cin >> kilogram;
    
                        gram = kilogram * 1000;
                        cout << "\nHasil Konversi:\n";
                        cout << kilogram << " Kg"<< " = " << gram << " g\n";
                        system("pause");
                        
                    }
                    else if (subPilihan == 2){
                        system("cls");
                        
                        cout << "==== Kilogram to miligram ====" << endl;
                        cout << "Masukkan Nilai kilogram : ";
                        cin >> kilogram;
    
                        miligram = kilogram * 1000000;
                        cout << "\nHasil Konversi:\n";
                        cout << kilogram << " Kg"<< " = " << miligram << " g\n";
                        system("pause");
                        
                    }
                    else if (subPilihan == 3){
                        system("cls");
                        
                        cout << "==== gram to Kilogram ====" << endl;
                        cout << "Masukkan Nilai gram : ";
                        cin >> gram;
    
                        kilogram = gram / 1000;
                        cout << "\nHasil Konversi:\n";
                        cout << gram << " g"<< " = " << kilogram << " Kg\n";
                        system("pause");
    
                    }
                    else if (subPilihan == 4){
                        system("cls");
                        
                        cout << "==== gram to miligram ====" << endl;
                        cout << "Masukkan Nilai gram : ";
                        cin >> gram;
    
                        miligram = gram * 1000;
                        cout << "\nHasil Konversi:\n";
                        cout << gram << " g"<< " = " << miligram << " mg\n";
                        system("pause");
                        
                    }
                    else if (subPilihan == 5){
                        system("cls");
                        
                        cout << "==== miligram to kilogram ====" << endl;
                        cout << "Masukkan Nilai miligram : ";
                        cin >> miligram;
    
                        kilogram = miligram / 1000000;
                        cout << "\nHasil Konversi:\n";
                        cout << miligram << " mg"<< " = " << kilogram << " Kg\n";
                        system("pause");
                        
                    }
                    else if (subPilihan == 6){
                        system("cls");
                        
                        cout << "==== miligram to gram ====" << endl;
                        cout << "Masukkan Nilai miligram : ";
                        cin >> miligram;
    
                        gram = miligram / 1000;
                        cout << "\nHasil Konversi:\n";
                        cout << miligram << " g"<< " = " << gram << " g\n";
                        system("pause");
                        
                    }
                    else if(subPilihan == 7){
                        break;
                    }
                    else{
                        system("cls");
                        cout << "Input tidak valid\n" ;
                        system("pause");
    
                    }
                }
            } 
            else if (pilihan == 5) {
                system("cls");
                cout << "Program Berhenti\n";
                system("pause");
                return 0;
            } 
            else {
                system("cls");
                cout << "Input tidak valid\n";
                system("pause");
            }
        }
    }

    return 0;
}
