// Skriven av Tommy Yasi/toya1800 2018-11-22
// Laboration 2, Assignment_2.cpp
// ASCII-tabell

#include <iostream>  // cout och cin
#include <iomanip>   // setw() och setfill()
using namespace std; // Bibliotek

int main() {
    int firstChar = 32;  // Första tecken
    int rader = 32;
    int kollumn = 7;

    // Skriver ut tabellen
    for (int r = 0; r < rader; r++) {             // Antal rader 32
        for (int c = 0; c < kollumn; c++) {       // Antal kolumner 8
            int a = firstChar + rader*c + r;      // a börjar på 32 och sedan addera rad*kolumn + rad loopen
            cout << right << setw(2) << a << ":"
                  << left << setw(2) << static_cast<char> (a);
        }
        cout << endl;  //Ny rad
    }

    return 0;
}