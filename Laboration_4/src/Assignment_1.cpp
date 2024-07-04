// Skriven av Tommy Yasi/toya1800 2018-12-09
// Laboration 4, Assignment_1.cpp
// Tärning "kastas" och programmet räknar antalet ettor, tvåor osv, och relativ frekvens för siffrorna.

#include <iostream> // cin, cout
#include <random> // random generator, slumpa tal
#include <iomanip> // setprecision, fixed
using namespace std; // Bibliotek

// Funktionsprototyp:
int throw_dice(); // Slumpar tal

int main() {
    int throws; // Antal kast
    cout << "How many times do you want to roll the dice?" << endl;
    cin >> throws;
    cout << endl;

    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0; // Hur många gånger dessa siffror kastas
    for(int i = 0; i < throws; i++){
        // Skapa ett random tal
        int dice = throw_dice(); // Kallar på funktionen som kastar tärningen
        switch (dice) {
            case 1: one++; break;
            case 2: two++; break;
            case 3: three++; break;
            case 4: four++; break;
            case 5: five++; break;
            case 6: six++; break;
            default: cout << "Something went wrong!" << endl; break;
        }
    }
    // Skriver ut antal kast per siffra
    cout << "Antal: " << endl;
    cout << "1: " << one << endl;
    cout << "2: " << two << endl;
    cout << "3: " << three << endl;
    cout << "4: " << four << endl;
    cout << "5: " << five << endl;
    cout << "6: " << six << endl << endl;

    // Skriv ut relativ frekvens
    cout << setprecision(0) << fixed; // För att avrunda och endast visa heltal
    cout << "Relativ frekvens: " << endl;
    cout << "[1]: " << 100.0*one/throws << "%" << endl;
    cout << "[2]: " << 100.0*two/throws << "%" << endl;
    cout << "[3]: " << 100.0*three/throws << "%" << endl;
    cout << "[4]: " << 100.0*four/throws << "%" << endl;
    cout << "[5]: " << 100.0*five/throws << "%" << endl;
    cout << "[6]: " << 100.0*six/throws << "%" << endl;

    return 0;
}
// Funktionsdefinition:
int throw_dice(){
    random_device rd; // Seed, Istället för time(0)
    mt19937 mt(rd()); // Seed i en random engine
    uniform_int_distribution<int> dist(1, 6); // Skapa en jämn fördelning mellan 1-6

    return dist(mt); // Returnera random tal
}

