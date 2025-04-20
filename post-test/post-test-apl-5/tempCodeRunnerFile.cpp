void hapusKomik(User &user) {
    tampilkanKomik(&user, 0);
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