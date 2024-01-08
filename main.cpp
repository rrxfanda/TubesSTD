#include "tubes.h"

int main() {
    listHotel LH;
    listUser LU;
    string input;

    createListHotel(LH);
    createListUser(LU);
    while (true) {
        clearScreen();
        cout << "========== MAIN MENU ==========" << endl;
        cout << "1. Data Hotel" << endl;
        cout << "2. Data User" << endl;
        cout << "3. Data Pelangganan Hotel" << endl;
        cout << "0. Exit program" << endl;
        cout << endl;

        cout << "Pilih [1/2/3/0]: ";
        cin >> input;
        cout << endl;

        if (input == "1") {
            menuHotel(LH);
        } else if (input == "2") {
            menuUser(LU, LH);
        } else if (input == "3") {
            menuRelasi(LH, LU);
        } else if (input == "0") {
            break;
        } else {
            cout << "Input anda salah. Tekan Enter untuk lanjut...";
            pause();
            cout << endl;
        }
    }
    clearScreen();
    cout << "Bye!" << endl;

    return 0;
}
