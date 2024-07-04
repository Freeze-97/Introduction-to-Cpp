// Räkna ut bensinförbrukningen och pris per mil
// Skriven av Tommy Yasi/toya1800 2018-11-14
// Laboration 1, Assignment_1.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int matarstallning1, matarstallning2;
    double literTankad, bensinfarbrukning, milkostnad;
    const double BENSINPRIS = 8.87;   // Pris per liter


    // Personen anger mätarställning två gånger och hur mycket liter som tankades
    cout << "Ange matarsallning 1 [km]: " << endl;
    cin >> matarstallning1;

    cout << "Ange matarstallning 2 [km]: " << endl;
    cin >> matarstallning2;

    cout << "Hur mycket tankade du [liter]: " << endl;
    cin >> literTankad;
    cout << endl << endl;

    // Beräkna bensinförbrukningen på liter per mil
    bensinfarbrukning = literTankad / ((matarstallning2 /10.0)-(matarstallning1 /10.0)); // Dela med 10.0 för att omvandla till mil

    // Beräkna milkostand som är antal kr per mil och bensinpriset ar 10 kr per mil
    milkostnad = (BENSINPRIS * literTankad) / ((matarstallning2 /10.0 )  - (matarstallning1 /10.0 ));

    cout << fixed << setprecision (2);  // Ser till att resultatet avrundas till 2 decimaler
    cout << " Bansingfarbrukning [l/mil]: " << setw(5) << bensinfarbrukning << endl;
    cout << " Milkostnad        [kr/mil]: " << setw(5) << milkostnad << endl;

    return 0;
}

