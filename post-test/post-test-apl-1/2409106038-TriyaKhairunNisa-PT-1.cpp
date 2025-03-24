#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

string nama, nim;
int opsi;

double Celcius_Fahrenheit(double nilai_suhu) {
    return (nilai_suhu * 9/5) + 32;
}

double Celcius_Reamur(double nilai_suhu) {
    return nilai_suhu * 4/5;
}

double Celcius_Kelvin(double nilai_suhu) {
    return nilai_suhu + 273;
}

double Fahrenheit_Celcius(double nilai_suhu) {
    return (nilai_suhu - 32) * 5/9;
}

double Fahrenheit_Reamur(double nilai_suhu) {
    return (nilai_suhu - 32) * 4/9;
}

double Fahrenheit_Kelvin(double nilai_suhu) {
    return (nilai_suhu - 32) * 5/9 + 273;
}

double Reamur_Celcius(double nilai_suhu) {
    return nilai_suhu * 5/4;
}

double Reamur_Fahrenheit(double nilai_suhu) {
    return (nilai_suhu * 9/4) + 32;
}

double Reamur_Kelvin(double nilai_suhu) {
    return (nilai_suhu * 5/4) + 273;
}

double Kelvin_Celcius(double nilai_suhu) {
    return nilai_suhu - 273;
}

double Kelvin_Fahrenheit(double nilai_suhu) {
    return (nilai_suhu - 273) * 9/5 + 32;
}

double Kelvin_Reamur(double nilai_suhu) {
    return (nilai_suhu - 273) * 4/5;
}

void menu_utama() {
    double nilai_suhu;
    
    while (true) {
        cout << "Pilih Opsi: ";
        cin >> opsi;
        
        if (opsi == 1) {
            cout << "Masukkan suhu dalam Celcius: ";
            cin >> nilai_suhu;
            
            cout << MAGENTA << "Fahrenheit: " << Celcius_Fahrenheit(nilai_suhu) << endl;
            cout << "Reamur: " << Celcius_Reamur(nilai_suhu) << endl;
            cout << "Kelvin: " << Celcius_Kelvin(nilai_suhu) << endl << RESET;
        } 
        else if (opsi == 2) {
            cout << MAGENTA << "Masukkan suhu dalam Fahrenheit: ";
            cin >> nilai_suhu;
            cout << "Celcius: " << Fahrenheit_Celcius(nilai_suhu) << endl;
            cout << "Reamur: " << Fahrenheit_Reamur(nilai_suhu) << endl;
            cout << "Kelvin: " << Fahrenheit_Kelvin(nilai_suhu) << endl << RESET;
        }
        else if (opsi == 3) {
            cout << MAGENTA << "Masukkan suhu dalam Reamur: ";
            cin >> nilai_suhu;
            cout << "Celcius " << Reamur_Celcius(nilai_suhu) << endl;
            cout << "Fahrenheit: " << Reamur_Fahrenheit(nilai_suhu) << endl;
            cout << "Kelvin: " << Reamur_Kelvin(nilai_suhu) << endl << RESET;
        } 
        else if (opsi == 4){
            cout << MAGENTA << "Masukkan suhu dalam Kelvin: ";
            cin >> nilai_suhu;
            cout << "Celcius " << Kelvin_Celcius(nilai_suhu) << endl;
            cout << "Fahrenheit: " << Kelvin_Fahrenheit(nilai_suhu) << endl;
            cout << "Reamur: " << Kelvin_Reamur(nilai_suhu) << endl << RESET;
        }
        else if (opsi == 5){
            cout << YELLOW << "Anda Keluar dari Program, bye bye :D\n";
            cout << " /\\_/\\  " << endl;
            cout << "( o.o ) " << endl;
            cout << " > ^ <  " << endl << RESET;
            break;
        }

        else {
            cout << "Opsi tidak valid. Silakan pilih lagi.\n";
        }
    }
}

int main() 
{    bool masuk = false;
    for (int login = 1; login <= 3; login++) {
        cout << CYAN << "= Selamat Datang di Converter Suhu =\n" << RESET;
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        if (nama == "Triya" && nim == "038") {
            cout << "Berhasil Login, Hi " << nama << endl;
            masuk = true;
            menu_utama();
            break;        } 
        else 
        {
            cout << YELLOW << "Login gagal. Silakan coba lagi.\n" << RESET;
        }
        if (login == 3) {
            cout << RED << "Kesempatan login habis. Akses ditolak!\n" << RESET;
            return 0;
        }
    }
    return 0;  
}