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

void Register(User users[], int &jumlahUser) {
    if (jumlahUser >= MAX_USER) {
        cout << RED << "User sudah penuh!" << RESET << endl;
    } else {
        cout << "Masukkan NIM: ";
        cin >> users[jumlahUser].nim;
        cin.ignore();
        cout << "Masukkan Nama: ";
        getline(cin, users[jumlahUser].nama);
        cout << CYAN << "Berhasil Registrasi!" << RESET << endl;
        jumlahUser++;
    }
}

int Login(User users[], int jumlahUser) {
    for (int login = 1; login <= 3; login++) {
        int nim;
        string nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        for (int i = 0; i < jumlahUser; i++) {
            if (users[i].nim == nim && users[i].nama == nama) {
                cout << CYAN << "Login berhasil! Hai, " << users[i].nama << RESET << endl;
                return i;
            }
        }
        cout << RED << "Login gagal! Coba lagi.\n" << RESET << endl;
        if (login == 3) {
            cout << RED << "Akses ditolak!" << RESET << endl;
            cout << YELLOW << "Anda Keluar dari Program, bye bye :D";
            cout << " /\\_/\\  " << endl;
            cout << "( o.o ) " << endl;
            cout << " > ^ <  " << endl << RESET;
            exit(0);
        }
    }
    return -1;
}

void tambahKomik(User &user);
void tampilkanKomik(User &user, int index);
void ubahKomik(User &user);
void hapusKomik(User &user);

void menu_utama(User &user) {
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

        switch (pilihan) {
            case 1: tambahKomik(user); break;
            case 2: tampilkanKomik(user, 0); break;
            case 3: ubahKomik(user); break;
            case 4: hapusKomik(user); break;
            case 5:
                cout << YELLOW << "Kembali ke Menu Login." << RESET << endl;
                return;
            default:
                cout << RED << "Pilihan tidak valid!" << RESET << endl;
        }
    }
}

void tambahKomik(User &user) {
    if (user.jumlahKomik >= MAX_KOMIK) {
        cout << RED << "Koleksi penuh!" << RESET << endl;
        return;
    }
    Komik &k = user.koleksi[user.jumlahKomik];
    cout << "Masukkan judul komik: ";
    getline(cin, k.judul);
    cout << "Masukkan rating komik: ";
    cin >> k.rating;
    cout << "Masukkan tahun terbit komik: ";
    cin >> k.tahun_terbit;
    user.jumlahKomik++;
    cout << CYAN << "Data komik berhasil ditambahkan!" << RESET << endl;
}

void tampilkanKomik(User &user, int index) {
        if (user.jumlahKomik == 0) {
            cout << YELLOW << "Belum ada komik." << RESET << endl;
            return;
        }
        if (index == user.jumlahKomik) return;
        Komik &k = user.koleksi[index];
        cout << MAGENTA << "+----------------------------------------------------------+\n";
        cout << "| " << index + 1 << ". Judul: " << k.judul  << " | Rating: " << k.rating << " | Tahun terbit: " << k.tahun_terbit << " |\n";
        cout << "+----------------------------------------------------------+\n" << RESET;
    
        tampilkanKomik(user, index + 1); 
    }
    
void ubahKomik(User &user) {
    tampilkanKomik(user, 0);
    int index;
    cout << "Masukkan nomor komik yang akan diubah: ";
    cin >> index;
    cin.ignore();
    if (index < 1 || index > user.jumlahKomik) {
        cout << RED << "Nomor komik tidak valid!" << RESET << endl;
        return;
    }
    Komik &k = user.koleksi[index - 1];
    cout << "Masukkan judul komik baru: ";
    getline(cin, k.judul);
    cout << "Masukkan rating komik baru: ";
    cin >> k.rating;
    cout << "Masukkan tahun tahun komik baru: ";
    cin >> k.tahun_terbit;
    cout << CYAN << "Data komik berhasil diubah!" << RESET << endl;
}

void hapusKomik(User &user) {
    tampilkanKomik(user, 0);
    int index;
    cout << "Masukkan nomor komik yang akan dihapus: ";
    cin >> index;
    if (index < 1 || index > user.jumlahKomik) {
        cout << RED << "Nomor komik tidak valid!" << RESET << endl;
        return;
    }
    for (int i = index - 1; i < user.jumlahKomik - 1; i++) {
        user.koleksi[i] = user.koleksi[i + 1];
    }
    user.jumlahKomik--;
    cout << CYAN << "Data komik berhasil dihapus!" << RESET << endl;
}

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

        switch (pilih) {
            case 1: Register(users, jumlahUser); break;
            case 2: {
                int index = Login(users, jumlahUser);
                if (index != -1) menu_utama(users[index]);
                break;
            }
            case 3:
            cout << YELLOW << "Anda Keluar dari Program, bye bye :D\n";
            cout << " /\\_/\\  " << endl;
            cout << "( o.o ) " << endl;
            cout << " > ^ <  " << endl << RESET;
                return 0;
            default:
                cout << RED << "Pilihan tidak valid!" << RESET << endl;
        }
    }
}
