#include <iostream>
using namespace std;

struct tanggal{
    int hari;
    int bulan;
    int tahun;
};
struct Mahasiswa{
    string nama;
    int nim;
    string gender;
    tanggal tanggallahir;

};

int main(){

    Mahasiswa mhsbaru;
    Mahasiswa mhslama;

    mhsbaru.nama = 'Rangga';
    mhsbaru.nim = '043';
    mhsbaru.gender ='Lakik';
    mhsbaru.tanggallahir.hari =3;
    mhsbaru.tanggallahir.bulan =3;
    mhsbaru.tanggallahir.tahun =2004;

    cout << mhsbaru.nama <<endl;
    cout << mhsbaru.nim<<endl;
    cout << mhsbaru.gender<<endl;
    cout << "Tanggal Lahir: " << mhsbaru.tanggallahir.hari << "/" << mhsbaru.tanggallahir.bulan << "/" << mhsbaru.tanggallahir.tahun << endl;
    // cout << mhslama.nama <<endl;

    string buah[5];
    Mahasiswa mhsabadi[5];
    mhsabadi[0].nama ="ifnu";
    mhsabadi[1].nama ="amad";
    mhsabadi[2].nama ="nasrul";
    mhsabadi[3].nama ="rava";
    mhsabadi[4].nama ="zidan";

    for (int i=0;i<size(mhsabadi);i++){
        cout << mhsabadi[i].nama <<endl;

    }


    
    return 0;
}