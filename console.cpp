#include <iostream>
using namespace std;

int main() {
    string username, password;
    cout << "Sistem Rental Mobil" << endl;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    if (username == "admin" && password == "1234") {
        cout << "Login Berhasil!" << endl;
    } else {
        cout << "Login Gagal!" << endl;
    }

    return 0;
}