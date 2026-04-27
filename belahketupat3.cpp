// Program Bangun Datar: Layang-Layang & Belah Ketupat
// Menggunakan private variable, friend function, dan object access

#include <iostream>
using namespace std;

// Forward declaration
class BelahKetupat;

// ============================
// Class Layang-Layang
// ============================
class LayangLayang {
private:
    double d1, d2;   // diagonal 1 dan diagonal 2 (private)
    double a, b;     // sisi a dan sisi b (private)

public:
    void input() {
        cout << "=== Input Layang-Layang ===\n";
        cout << "Diagonal 1 (d1): "; cin >> d1;
        cout << "Diagonal 2 (d2): "; cin >> d2;
        cout << "Sisi a        : "; cin >> a;
        cout << "Sisi b        : "; cin >> b;
    }

    double hitungLuas() {
        return (d1 * d2) / 2.0;
    }

    double hitungKeliling() {
        return 2 * (a + b);
    }

    void output() {
        cout << "\n=== Output Layang-Layang ===\n";
        cout << "Luas     : " << hitungLuas() << " cm2\n";
        cout << "Keliling : " << hitungKeliling() << " cm\n";
    }

    // Friend function: BelahKetupat dapat akses keliling Layang-Layang
    friend double kelilingDariBelahKetupat(LayangLayang& lk);
};

// ============================
// Class Belah Ketupat
// ============================
class BelahKetupat {
private:
    double d1, d2;   // diagonal 1 dan diagonal 2 (private)
    double sisi;     // sisi (private)

public:
    void input() {
        cout << "=== Input Belah Ketupat ===\n";
        cout << "Diagonal 1 (d1): "; cin >> d1;
        cout << "Diagonal 2 (d2): "; cin >> d2;
        cout << "Sisi           : "; cin >> sisi;
    }

    double hitungLuas() {
        return (d1 * d2) / 2.0;
    }

    double hitungKeliling() {
        return 4 * sisi;
    }

    void output() {
        cout << "\n=== Output Belah Ketupat ===\n";
        cout << "Luas     : " << hitungLuas() << " cm2\n";
        cout << "Keliling : " << hitungKeliling() << " cm\n";
    }
};

// ============================
// Friend Function Definition
// BelahKetupat mengakses private member Layang-Layang
// ============================
double kelilingDariBelahKetupat(LayangLayang& lk) {
    // Mengakses langsung private member: a dan b
    return 2 * (lk.a + lk.b);
}

// ============================
// Main Function
// Semua diakses hanya melalui object
// ============================
int main() {
    LayangLayang ll;    // object LayangLayang
    BelahKetupat bk;    // object BelahKetupat

    ll.input();
    ll.output();

    cout << "\n[Friend Function] Keliling Layang-Layang via BelahKetupat: "
         << kelilingDariBelahKetupat(ll) << " cm\n\n";

    bk.input();
    bk.output();

    return 0;
}