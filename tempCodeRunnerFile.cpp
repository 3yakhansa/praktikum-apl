#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

// int main() 
// {    bool masuk = false;
//     for (int login = 1; login <= 3; login++) {
//         cout << CYAN << "= Selamat Datang di Converter Suhu =\n" << RESET;
//         cout << "Masukkan nama: ";
//         cin >> nama;
//         cout << "Masukkan NIM: ";
//         cin >> nim;
//         if (nama == "Triya" && nim == "038") {
//             cout << "Berhasil Login, Hi " << nama << endl;
//             masuk = true;
//             menu_utama();
//             break;        } 
//         else 
//         {
//             cout << YELLOW << "Login gagal. Silakan coba lagi.\n" << RESET;
//         }
//         if (login == 3) {
//             cout << RED << "Kesempatan login habis. Akses ditolak!\n" << RESET;
//             return 0;
//         }
//     }
//     return 0;  
// }

int main() {s
    int arr[2][2][2];
    arr[0][0][0] = 10;
    arr[0][0][1] = 20;
    arr[0][1][0] = 30;
    arr[0][1][1] = 40;
    arr[1][0][0] = 11;
    arr[1][0][1] = 22;
    arr[1][1][0] = 33;
    arr[1][1][1] = 44;
    cout << "Isi variabel arr:" << endl;
    cout << "=================" << endl;
    cout << endl;
    cout << "Element di [0][0][0]: "<< arr[0][0][0] << endl;
    cout << "Element di [0][0][1]: "<< arr[0][0][1] << endl;
    cout << "Element di [0][1][0]: "<< arr[0][1][0] << endl;
    cout << "Element di [0][1][1]: "<< arr[0][1][1] << endl;
    cout << "Element di [1][0][0]: "<< arr[1][0][0] << endl;
    cout << "Element di [1][0][1]: "<< arr[1][0][1] << endl;
    cout << "Element di [1][1][0]: "<< arr[1][1][0] << endl;
    cout << "Element di [1][1][1]: "<< arr[1][1][1] << endl;
    return 0;
    }