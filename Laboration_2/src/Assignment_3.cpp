// Skriven av Tommy Yasi/toya1800 2018-11-24
// Laboration 2, Assignment_3.cpp
// Kolla om ett femsifrigt heltal är ett palindrom

#include <iostream>  // cout och cin
using namespace std; // Bibliotek

int main() {

    char ch = ' ';  // Används för att användaren ska köra om eller inte
    bool ok = false; // Kontrollera om det är 5 siffror som skrivs in
    do {
        int originalNumber = 0;
        do {
            // Skriv in och deklarera variablen number
            cout << "Type a 5 digit number: " << endl;
            cin >> originalNumber;
            if (originalNumber >= 10000 && originalNumber<=99999)  {
                ok = true;
            }
        } while (!ok); // Fortsätter att efterfråga om 5 siffror om annat skrivs in

        int rev = 0;  // rev ska få siffran baklänges
        for (int number = originalNumber; number != 0; number = number / 10) {  // Delar med 10 för att få en siffra mindre under nästa loop
            int hold = number % 10; // Behåller en siffra som är siffran längst åt vänster, resten
            rev = rev * 10 + hold; // Gångra med tio för att öka från ental till tiotal, hundratal osv och plus hold som har rest från number
        }
        if (originalNumber == rev)
            cout << "The number " << originalNumber << " reversed is " << rev << " which means it's a palindrome!"
                 << endl;
        else
            cout << "The number " << originalNumber << " reversed is " << rev << " which means it's not a palindrome :("
                 << endl;

        // Fråga om användaren vill skriva in ett nytt nummer
        cout << "Do you want to try with another number? (y/n): " << endl;
        cin >> ch;
        ch = toupper(ch); // Både stort och litet y/n blir tillåtna
    }while(ch == 'Y');  // Programmet körs om, om användaren svarar Y/y

    return 0;
}