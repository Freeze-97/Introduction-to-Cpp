// Skriven av Tommy Yasi/toya1800 2018-11-21
// Laboration 2, Assignment_1.cpp
// Pythagoras sats, antal trianglar där gränsen för sidorna är 500
// Sedan ska hypotenusa 100, 200, 300, 400 och 500 skrivas ut

#include <iostream>   // Använda cout och cin
using namespace std;  // Standard biblotek

int main() {
    int i = 0;  // Ska räkna ut antal trianglar
    // a och b kateter, c hypotenusan
    for (int a = 1; a <= 500; a++) {  // Testar alla heltals värden på a med 500 som gräns
        for (int b = 1; b <= 500; b++) {  // Testar alla heltals värden på b med 500 som gräns
            for (int c = 1; c <= 500; c++) {  // Testar alla heltals värden på c med 500 som gräns
                if (c * c == a * a + b * b && a < b) {
                    i++;  // Counter som ger resultat på antal trianglar
                    switch (c) {  // Väljer att skriva ut 100, 200, 300, 400 och 500
                        case 100:
                        case 200:
                        case 300:
                        case 400:
                        case 500:
                            cout << "Katet a: " << a << endl;  // Skriver ut de 3 sidorna och sedan mellanrum för nästa
                            cout << "katet b: " << b << endl;
                            cout << "Ger Hypotenusan c: " << c << endl;
                            cout << endl;
                            break;
                    }
                }
            }
        }
    }
    cout << "Amount of triangles: " << i << endl;  //Skriver ut antal trianglar
    return 0;
}
// Slut:)
