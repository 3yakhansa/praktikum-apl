#include <iostream>
#include <cmath>
#include <iomanip>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
using namespace std;

// FUNGSI YANG AKAN DICARI
double f(double x) {

    return pow(x, 3) - x - 2;
}

// FUNGSI UTAMA METODE REGULA-FALSI
void regulaFalsi(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        cout << RED << "Metode gagal: f(a) dan f(b) harus memiliki tanda yang berbeda." << RESET << endl;
        return;
    }

    double c;
    cout << left << setw(10) << "Iterasi"
         << setw(15) << "a"
         << setw(15) << "b"
         << setw(15) << "c"
         << setw(15) << "f(c)" << endl;

    for (int i = 1; i <= max_iter; ++i) {
        // RUMUS REGULA-FALSI
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        double fc = f(c);

        cout << left << setw(10) << i
             << setw(15) << a
             << setw(15) << b
             << setw(15) << c
             << setw(15) << fc << endl;

        if (abs(fc) < tol) {
            cout << CYAN << "\nAkar ditemukan pada x = " << c << RESET << endl;
            return;
        }

        // UPDATE INTERVAL
        if (f(a) * fc < 0)
            b = c;
        else
            a = c;
    }

    cout << CYAN << "\nMetode tidak konvergen dalam jumlah iterasi maksimal." << RESET << endl;
}

int main() {
    //INTERVAL AWAL
    double a, b;       
    //TOLERANSI
    double tol = 1e-6;        
    //ITERASI MAKSIMAL
    int max_iter = 100;     
    cout << CYAN << "=== METODE REGULA-FALSI ===" << endl;
    cout << "Fungsi default: f(x) = x^3 - x - 2\n"<< RESET << endl;
    cout << "Masukkan batas bawah (a): ";
    cin >> a;
    cout << "Masukkan batas atas  (b): ";
    cin >> b;

    regulaFalsi(a, b, tol, max_iter);

    return 0;
}