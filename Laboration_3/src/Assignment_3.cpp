// Skriven av Tommy Yasi/toya1800 2018-12-01
// Laboration 3, Assignment_3.cpp
// Skriver ut en text som är krypterad och sedan dekrypterad

#include <iostream> // cout, cin
#include <string> // string-klass
using namespace std; // Bibliotek

int main() {
    // Skriv in texten
    string text;
    cout << "Type in any text: " << endl;
    getline(cin, text); // Text med mellanslag kan skrivas in
    cout << endl; // Extra radutrymme

    int rot13 = 13; // Addera teckenvärdet med 13
    int rot7 = 7; // Addera teckenvärdet med 7

    // Krypterar texten, om resten av numret är 0-4 = rot 13, 5-9 = rot 7
    string encoded; // Krypterade koden
    for(int i = 0; i < text.length(); i++){ // Så länge i är mindre än text.length, fortsätt
        encoded += static_cast<char> (text.at(i) + (i % 10 < 5 ? rot13 : rot7));
    }
    cout << "Your encrypted text: " << endl << encoded << endl << endl; // Skriver ut den krypterade texten

    // Dekrypterar texten på samma sätt men istället för + så används -
    string original; // Dekrypterad text
    for(int i = 0; i < encoded.length(); i++){
        original += static_cast<char> (encoded.at(i) - (i % 10 < 5 ? rot13 : rot7));
    }
    cout << "Your decrypted text: " << endl << original << endl; // Skriver ut dekrypterade texten
    return 0;
}