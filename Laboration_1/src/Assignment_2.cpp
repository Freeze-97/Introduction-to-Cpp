//-----------------
// Laboration 1, Assignment_2.cpp
// Program with both logical and syntactical errors
// Tommy Yasi/toya1800 2018-11-14
//-----------------

#include <iostream>     // C++ standardbibiolotek måste finns med, ett syntaxfel då man har glömt detta

using namespace std;    // Den här saknades innan, syntaxfel, den behövs då man kan skriva cout, cin osv utan att använda std:: varje gång


int main() {
    // Variables and constants
    double radius, circumference, area;   // Ett logiskt fel då man kommer att hantera tal med decimaltecken
    const float PI = 3.14;   //Syntaxfel, det ska vara punkt


    // Input the circles radius
    cout << " Assign the circle's radius: ";
    cin >> radius;   // Det ska inte vara "=" utan ">>", syntax fel


    // Algorithm to calculate circumference (2*PI*r) and area (PI*r*r)
    circumference = 2 * PI * radius;   // Omkretsen räknas med 2*PI*r, inte PI*radie*radie, logiskt fel
    area = PI * radius * radius;       // Area räknas genom PI*radie^2, inte 2*pi*radie, logiskt fel och syntax fel då det ska stå PI.


    // Output of results
    cout << "A circle with the radius " << radius << " has the circumference " //Syntaxfel, circumference som skulle skrivas ut var skriven raden under
    << circumference << " and area " << area << endl;



    // Validate x
    int x;
    cout << " Give x a value: " << endl; // logiskt, den här consolout delen fanns inte med innan cin
    cin >> x;

    if (x == 100)   // Logiskt: "=" betyder tilldelning "==" är likhet
        cout << " x is equal to 100 " << endl;

    if (x > 0) // Ska inte finns ; precis efter if-satsen, logisktfel
    cout << " x is larger than zero " << endl;

     switch (x) {
         case 5 : cout << " x is equal to 5 " << endl;
          break;   // Logisktfel: break saknades
         case 10 : cout << " x is equal to 10" << endl;
          break;  // Logisktfel: break saknades
         default : cout << " x is neither 5 nor 10 " << endl;
           break; // Logisktfel: break saknades
     }                         //Logisktfel; Den var skriven under return 0; så den kappslades in i switch statement
    return 0;

}    // Syntax fel, ska finnas ett "}" för att kappsla in int main ()

