#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

#define MAX_USER 100
#define MAX_KOMIK 100

struct Komik {
    string judul;
    float rating;
    int tahun_terbit;
};

struct User {
    string nama;
    int nim;
    Komik koleksi[MAX_KOMIK];
    int jumlahKomik = 0;
};

User users[MAX_USER];
int jumlahUser = 0;

int main() {
    int pilih;
    while (true) {
        cout << CYAN << "==========================================" << endl;
        cout << "| Manajemen Komik Webtoon Favorit        |" << endl;
        cout << "| 1. Register                            |" << endl;
        cout << "| 2. Login                               |" << endl;
        cout << "| 3. Keluar                              |" << endl;
        cout << "==========================================" << RESET << endl;
        cout << "PILIH: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            if (jumlahUser >= MAX_USER) {
                cout << RED << "User sudah penuh!" << RESET<< endl;
            } else {
                cout << "Masukkan NIM: ";
                cin >> users[jumlahUser].nim;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, users[jumlahUser].nama);
                cout << CYAN << "Berhasil Registrasi!" << RESET << endl;
                jumlahUser++;
            }
        } else if (pilih == 2) {
            if (jumlahUser == 0) {
                cout << RED << "User Tidak Ditemukan!" << RESET << endl;
            } else {
                for (int login = 1; login <= 3; login++) {
                    int inputNIM;
                    string inputNama;
                    cout << "Masukkan NIM: ";
                    cin >> inputNIM;
                    cin.ignore();
                    cout << "Masukkan Nama: ";
                    getline(cin, inputNama);
                    bool loginSukses = false;
                    for (int i = 0; i < jumlahUser; i++) {
                        if (users[i].nim == inputNIM && users[i].nama == inputNama) {
                            loginSukses = true;
                            cout << CYAN << "Login berhasil! Hai, " << users[i].nama << RESET << endl;
                            int pilihan;
                            while (true) {
                                cout << CYAN << "====== Menu Utama ======" << endl;
                                cout << "1. Tambah Data Komik" << endl;
                                cout << "2. Lihat Data Komik" << endl;
                                cout << "3. Ubah Data Komik" << endl;
                                cout << "4. Hapus Data Komik" << endl;
                                cout << "5. Keluar" << endl;
                                cout << "Pilihan: " << RESET;                            
                                cin >> pilihan;
                                cin.ignore();
                                if (pilihan == 1) {
                                    if (users[i].jumlahKomik < MAX_KOMIK) {
                                        cout << "Masukkan judul komik: ";
                                        getline(cin, users[i].koleksi[users[i].jumlahKomik].judul);
                                        cout << "Masukkan rating komik: ";
                                        cin >> users[i].koleksi[users[i].jumlahKomik].rating;
                                        cout << "Masukkan tahun terbit komik: ";
                                        cin >> users[i].koleksi[users[i].jumlahKomik].tahun_terbit;
                                        users[i].jumlahKomik++;
                                        cout << CYAN << "Data Komik berhasil ditambahkan!" <<RESET << endl;
                                    } else {
                                        cout << RED << "Koleksi penuh! Tidak bisa menambahkan komik." << RESET << endl;
                                    }
                                    
                                } else if (pilihan == 2) {
                                    if (users[i].jumlahKomik == 0) {
                                        cout << YELLOW << "Belum ada komik." << RESET << endl; 
                                    } else {
                                        for (int j = 0; j < users[i].jumlahKomik; j++) {
                                            cout << MAGENTA << "+----+----------------------------+--------+--------------+\n";
                                            cout << "|" << j+1 << "|" << "Judul: " << users[i].koleksi[j].judul << "|" << "Rating: " << users[i].koleksi[j].rating << "|" << "Tahun terbit: " << users[i].koleksi[j].tahun_terbit << "|" << endl;
                                        }
                                        cout << "+----+----------------------------+--------+--------------+\n" << RESET;}
                                    
                                } else if (pilihan == 3) {
                                    if (users[i].jumlahKomik == 0) {
                                        cout << YELLOW << "Belum ada komik." << RESET << endl; 
                                    } else {
                                        for (int j = 0; j < users[i].jumlahKomik; j++) {
                                        cout << MAGENTA << "+----+----------------------------+--------+--------------+\n";
                                        cout << "|" << j+1 << "|" << "Judul: " << users[i].koleksi[j].judul << "|" << "Rating: " << users[i].koleksi[j].rating << "|" << "Tahun terbit: " << users[i].koleksi[j].tahun_terbit << "|" << endl;
                                    }
                                        cout << "+----+----------------------------+--------+--------------+\n" << RESET;
                                        int index;
                                        cout << "Masukkan nomor komik yang akan diubah: ";
                                        cin >> index;
                                        if (index > 0 && index <= users[i].jumlahKomik) {
                                            cout << "Masukkan judul komik baru: ";
                                            cin.ignore();
                                            getline(cin, users[i].koleksi[index - 1].judul);
                                            cout << "Masukkan rating baru: ";
                                            cin >> users[i].koleksi[index - 1].rating;
                                            cout << "Masukkan tahun terbit baru: ";
                                            cin >> users[i].koleksi[index - 1].tahun_terbit;
                                            cout << "Data komik berhasil diubah!\n";
                                            } else {
                                            cout << RED << "Nomor komik tidak valid!" <<RESET <<endl;
                                            }
                                            }
                                    
                                } else if (pilihan == 4) {
                                        if (users[i].jumlahKomik == 0) {
                                            cout << YELLOW << "Belum ada komik." << RESET << endl; 
                                        } else {        
                                        cout << "Masukkan nomor komik yang akan dihapus: ";
                                        int index;
                                        cin >> index;
                                        if (index > 0 && index <= users[i].jumlahKomik) {
                                            for (int j = index - 1; j < users[i].jumlahKomik - 1; j++) {
                                                users[i].koleksi[j] = users[i].koleksi[j + 1];
                                            }
                                            users[i].jumlahKomik--;
                                            cout << CYAN << "Data Komik berhasil dihapus!" <<RESET << endl;
                                        } else {
                                            cout << RED << "Nomor komik tidak valid!" <<RESET <<endl;
                                        }
                                        }
                                } else if (pilihan == 5) {
                                    cout << YELLOW << "Logout berhasil! Kembali ke Menu Login." <<RESET <<endl;
                                    break;
                                } else {
                                    cout << RED << "Pilihan tidak valid!" <<RESET <<endl;
                                }
                            }
                        }
                    }
                    if (loginSukses==false) {
                        cout << "Login gagal! Coba lagi.\n";
                        if (login == 3) {
                            cout << "Akses ditolak!\n";
                            return 0;
                        }
                    } else {
                        break;
                    }
                }
            }
        } else if (pilih == 3) {
            cout << YELLOW << "Anda Keluar dari Program, bye bye :D\n";
            cout << " /\\_/\\  " << endl;
            cout << "( o.o ) " << endl;
            cout << " > ^ <  " << endl << RESET;
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}
