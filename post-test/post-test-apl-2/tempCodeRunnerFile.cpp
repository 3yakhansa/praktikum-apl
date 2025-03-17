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