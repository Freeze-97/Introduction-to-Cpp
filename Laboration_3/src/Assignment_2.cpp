// Skriven av Tommy Yasi/toya1800 2018-11-30
// Laboration 3, Assignment_2.cpp
// Skriver ut namn i bokstavsordning baserad på efternamnet, om de har samma efternamn går den på förnamn

#include <iostream> // cout, cin
#include <string> // string-klass
using namespace std; // Bibliotek

int main() {
    // Skriv in tre fullständiga namn
    string name1;
    cout << "Enter first full name: " << endl;
    getline(cin, name1); // getline ser till så att mellanslag ska fungera

    string name2;
    cout << "Enter second full name: " << endl;
    getline(cin, name2);

    string name3;
    cout << "Enter third full name: " << endl;
    getline(cin, name3);

    cout << endl; // Extra radutrymme

    // Ändra alla bokstäver till små
    // Ändra bokstav för bokstav och sluta när det inte finns fler bokstäver
    string lowName1 = name1;
    for (int i = 0; i < lowName1.length(); i++) {
        lowName1[i] = tolower(lowName1[i]);
    }

    string lowName2 = name2;
    for (int i = 0; i < lowName2.length(); i++) {
        lowName2[i] = tolower(lowName2[i]);
    }

    string lowName3 = name3;
    for (int i = 0; i < lowName3.length(); i++) {
        lowName3[i] = tolower(lowName3[i]);
    }

    // Hitta mellanslaget i det fullständiganamnet
    auto spacePos1 = lowName1.find(' ');
    auto spacePos2 = lowName2.find(' ');
    auto spacePos3 = lowName3.find(' ');

    // Lagra förnamn och efternamn i varsin variabel för att sedan göra en reverseName
    string firstName1 = lowName1.substr(0, spacePos1); // Lagrar förnamnet i firstName1
    string lastName1 =  lowName1.substr(spacePos1 + 1); // Lagrar efternamnet i lastName1

    string firstName2 = lowName2.substr(0, spacePos2);
    string lastName2 =  lowName2.substr(spacePos2 + 1);

    string firstName3 = lowName3.substr(0, spacePos3);
    string lastName3 =  lowName3.substr(spacePos3 + 1);

    // Tilldela reverseNameX  efternamnet först och sedan förnamnet
    string reverseName1 = lastName1 + " " + firstName1;
    string reverseName2 = lastName2 + " " + firstName2;
    string reverseName3 = lastName3 + " " + firstName3;

    // Tilldelas namnX beroende på bokstavsordning
    string first, second, third;
    if(reverseName1 < reverseName2 && reverseName1 < reverseName3) { // Om name1 är först
        first = name1;
        if(reverseName2 < reverseName3){ // Om namn2 är mellan
            second = name2;
            third = name3;
        }
        else if(reverseName3 < reverseName2) { // Om namn 3 är mellan
            second = name3;
            third = name2;
        }
    }

    if(reverseName2 < reverseName1 && reverseName2 < reverseName3) { // Om name2 är först
        first = name2;
        if(reverseName1 < reverseName3){ // Om namn 1 är mellan
            second = name1;
            third = name3;
        }
        else if(reverseName3 < reverseName1) { // Om namn 3 är mellan
            second = name3;
            third = name1;
        }
    }

    if(reverseName3 < reverseName1 && reverseName3 < reverseName2) { // Om name3 är först
        first = name3;
        if(reverseName1 < reverseName2){ // Om namn 1 är mellan
            second = name1;
            third = name2;
        }
        else if(reverseName2 < reverseName1) { // Om namn 2 är mellan
            second = name2;
            third = name1;
        }
    }

    cout << first << endl << second << endl << third << endl; // Skriv ut namnen i ordning och egna rader

    return 0;
}

