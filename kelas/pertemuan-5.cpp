#include <iostream>
using namespace std;

struct Orang{
    string nama;
    int umur;
};


int main(){
    
    // int primeNumber[6] = {
    //     2,3,5,7,11,13};

    // int (*ptrPrimeNumber)[6] = &primeNumber;
    
    // for (int i=0; i<6;i++){

    //     cout <<  (*ptrPrimeNumber)[i] << endl;

    // }

    // cout << "pointer yang menunjuk ke suatu array"<< endl;
    // int a[5] = {1,2,3,4,5};
    // int (*aPtr)[5] = &a;
    // for (int i =0; i <5; i++){
    // cout << *aPtr <<endl;
    // }

    // cout << "Pointer yang menunjuk ke arah elemen array" <<endl;
    // int b[5] = {1,2,3,4,5,};
    // int *bPtr = b;
    // for (int i = 0; i < 5; i++){
    // cout << bPtr <<endl;
    // // cout << *bPtr <<endl;
    // bPtr++;
    // }

    // Orang orang;
    // orang.nama =  "Kalingga";
    // orang.umur = 20;

    // Orang* orang2 = &orang;

    // cout << orang.nama<<endl;
    // cout << orang2 ->nama<<endl;



    // Orang* orang3 = new Orang();
    // orang3->nama


    // int stack=64;
    // int stacksnowball=16;

    // // int isi = stack;
    // // cout << isi <<endl;
    // // cout << stack << endl;
    // // stack = 69;

    // int* isi = &stack;

    // stack = 16;
    // cout <<"setelah stack diubah"<<endl;

    // cout << *isi <<endl;
    // cout << stack << endl;

    // cout <<"setelah isi diubah"<<endl;
    // // isi = *isi +10;
    // *isi = 2;

    // cout << *isi <<endl;
    // cout << stack << endl;


    // // cout << "stack: " << stack << endl;
    // // cout << "&stack: " << &stack << endl;
    
    // // cout << "snowball: " << stacksnowball << endl;
    // // cout << "&snowball: " << &stacksnowball <<endl;



    // int ptrStack=8;

    int stack = 10;
    int *ptrStack = &stack;

    int** ptrPtrStack = &ptrStack;

    cout << *ptrStack <<endl;


    return 0;
}