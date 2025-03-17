#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define max_komik 100 
#define INFO 3 
string nama, nim;

int main() 
{    bool masuk = false;
    for (int login = 1; login <= 3; login++) {
        cout << CYAN << "= Selamat Datang di Manajemen Komik Webtoon Favorit =\n" << RESET;
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        if (nama == "Triya" && nim == "038") {
            cout << "Berhasil Login, Hi " << nama << endl;
            masuk = true;
            int panjang = 0; 
            string komik[max_komik][INFO]; 
            int pilihan, index;
            do {;
            cout << CYAN << "====== Menu Utama ======" << endl;
            cout << "1. Tambah Data Komik" << endl;
            cout << "2. Lihat Data Komik" << endl;
            cout << "3. Ubah Data Komik" << endl;
            cout << "4. Hapus Data Komik" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: " << RESET;
            cin >> pilihan;
            switch (pilihan) {
            case 1:
            if (panjang < max_komik) {
                cout << "Masukkan judul komik: ";
                cin.ignore();
                getline(cin, komik[panjang][0]);
                cout << "Masukkan rating komik: ";
                getline(cin, komik[panjang][1]);
                cout << "Masukkan tahun terbit komik: ";
                getline(cin, komik[panjang][2]);
                panjang++;
                cout << "Data Komik berhasil ditambahkan" << endl;
                } else {
                cout << "Kapasitas penuh! Tidak bisa menambahkan komik." << endl;
                }
                break;
            case 2:
            if (panjang == 0) {
                cout << "Belum ada komik" << endl;
                } else {
                for (int i = 0; i < panjang; i++) {
                cout << MAGENTA << "+----+----------------------------+--------+--------------+\n";
                cout << i + 1 << " | Judul: " << komik[i][0] << " | Rating " << komik[i][1] << " | Tahun terbit: " << komik[i][2] << "" << endl;}
                }
                cout << "+----+----------------------------+--------+--------------+\n" << RESET;
            break;
            case 3:
            if (panjang == 0) {
                cout << "Belum ada komik untuk diubah." << endl;
                } else {
                for (int i = 0; i < panjang; i++) {
                cout << "komik ke-" << i + 1 << ": " << komik[i][0] << " (" << komik[i][1]
                << ")" << endl;
                }
                cout << "Masukkan nomor komik yang akan diubah: ";
                cin >> index;
                if (index > 0 && index <= panjang) {
                    cout << "Masukkan nama komik baru: ";
                    cin.ignore();
                    getline(cin, komik[index - 1][0]);
                    cout << "Masukkan rating baru: ";
                    getline(cin, komik[index - 1][1]);
                    cout << "Masukkan tahun terbit baru: ";
                    getline(cin, komik[index - 1][2]);
                    cout << "Data komik berhasil diubah" << endl;
                    } else {
                    cout << "Nomor komik tidak valid" << endl;
                    }
                    }
            break;
            case 4:
            if (panjang == 0) {
                cout << "Belum ada komik untuk dihapus." << endl;
                } else {
                for (int i = 0; i < panjang; i++) {
                cout << "komik ke-" << i + 1 << ": " << komik[i][0] << " (" << komik[i][1]
                << ")" << endl;
                }
                cout << "Masukkan nomor komik yang akan dihapus: ";
                cin >> index;
                if (index > 0 && index <= panjang) {
                for (int i = index - 1; i < panjang - 1; i++) {
                komik[i][0] = komik[i + 1][0];
                komik[i][1] = komik[i + 1][1];
                }
                panjang--;
                cout << "Data Komik berhasil dihapus" << endl;
                } else {
                cout << "Nomor komik tidak valid" << endl;
                }
                }
            break;
            case 5:
            cout << YELLOW << "Anda Keluar dari Program, bye bye :D\n";
            cout << " /\\_/\\  " << endl;
            cout << "( o.o ) " << endl;
            cout << " > ^ <  " << endl << RESET;
            break;
            default:
            cout << "Pilihan tidak valid" << endl;
            break;
            }
            } while (pilihan != 5);
            return 0;
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