// Skriven av Tommy Yasi/toya1800 2018-12-17
// Laboration 4, Assignment_3.cpp
// Välj mellan samtalskostnad eller kasta tärning

#include <iostream> // cout, cin
#include <string> // String-klass
#include <random> // random generator, slumpa tal
#include <iomanip> // setprecision, fixed
#include <sstream> // Omvandla string till int osv
using namespace std;
// Menyn
void menu(); // Huvudmenyn

// Kasta tärning
void diceSim(); // Program för att kasta tärning
int throw_dice(); // Slumpar tal

// Telefonsamtal
void teleTaxa();
bool check_time(const string&, const string&); // Kollar om tiden är acceptabel
int change_to_number(const string &); // Omvandla string till tal
string cut_to_hour(const string &); // Klipp hh i hh:mm
string cut_to_min (const string &); // Klipp mm i hh:mm
void maniplute(const string &, const string &); // Manipulera så att de klipps och får int
void calculate_minutes(int &, int &, int &, int &); // Räkna ut tid
double price(double const &, double const &); // Räknar ut kostnader
void print(const double &); // Skriv ut kostaden för samtalet

int main() {
    bool repeat = true;
    do{
        menu(); // Visa meny
        char ch;
        cin >> ch;

        switch(ch){
            case '1': diceSim();
            break;
            case '2': teleTaxa();
            break;
            case '3':
            case 'q':
            case 'Q': repeat = false;
            break;
            default: cout << "Invalid input, please try again." << endl;
        }
    }while(repeat); // Fortsätt så länge ch != 3 eller Q/q

    return 0;
}
void menu(){
    cout << "Main Menu" << endl << endl;
    cout << "Press 1 to throw dice." << endl;
    cout << "Press 2 for price of a phone call." << endl;
    cout << "Press 3 or Q/q to quit." << endl;
}
// Tärning
void diceSim(){
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
}
int throw_dice(){
    random_device rd; // Seed, Istället för time(0)
    mt19937 mt(rd()); // Seed i en random engine
    uniform_int_distribution<int> dist(1, 6); // Skapa en jämn fördelning mellan 1-6

    return dist(mt); // Returnera random tal
}
// Telefonsamtal
void teleTaxa(){
    char ch ; // Används för att fråga om användaren vill köra om programmet
    do {

        string start_time; // Starttid hh:mm
        string end_time; // Sluttid hh:mm

        // Kontrollera om inmatningen är okej
        do {
            cout << "When did the call start? [hh:mm]" << endl;
            cin >> start_time;
            cout << "When did the call end? [hh:mm]" << endl;
            cin >> end_time;
            if (!check_time(start_time, end_time)) {
                cout << "Incorrect input, please try again." << endl << endl;
            }
        } while (!check_time(start_time, end_time));

        maniplute(start_time, end_time); // Tillkallar på funktion som beräknar kostnad


        cout << "Do you want ro run the program again? [y/n]: " << endl;
        do {
            cin >> ch;
            ch = toupper(ch); // Stor och liten bokstav
        }while (!(ch == 'Y' || ch == 'N')); // Endast y och n ska fungera


    }while (ch == 'Y');

}
bool check_time(const string &start_time, const string &end_time) {
    string start_time_hour = cut_to_hour(start_time); // hh i start_time = hh:mm
    string start_time_min = cut_to_min(start_time); // mm i start_time = hh:mm
    string end_time_hour = cut_to_hour(end_time); // hh i end_time = hh:mm
    string end_time_min = cut_to_min(end_time); // mm i end_time = hh:mm

    // Int får ett nummervärde, omvandlas via change_to_number
    int start_hour = change_to_number(start_time_hour);
    int start_min = change_to_number(start_time_min);
    int end_hour = change_to_number(end_time_hour);
    int end_min = change_to_number(end_time_min);

    bool time_is_ok = true;

    // Kontrollera att kraven är uppfyllda
    if (start_hour < 0 || start_hour > 23){
        time_is_ok = false;
    }
    if(start_min < 0 || start_min > 59){
        time_is_ok = false;
    }
    if (end_hour < 0 || end_hour > 23){
        time_is_ok = false;
    }
    if(end_min < 0 || end_min > 59){
        time_is_ok = false;
    }
    if(start_hour*60+start_min > end_hour*60+end_min){ // *60 för att bara få minuter
        time_is_ok = false;
    }
    if(start_hour*60+start_min == end_hour*60+end_min){
        time_is_ok = false;
    }


    return time_is_ok;
}
void maniplute(const string &start_time, const string &end_time){
    string start_time_hour = cut_to_hour(start_time); // hh i start_time = hh:mm
    string start_time_min = cut_to_min(start_time); // mm i start_time = hh:mm
    string end_time_hour = cut_to_hour(end_time); // hh i end_time = hh:mm
    string end_time_min = cut_to_min(end_time); // mm i end_time = hh:mm

    // Int får ett nummervärde, omvandlas via change_to_number
    int start_hour = change_to_number(start_time_hour);
    int start_min = change_to_number(start_time_min);
    int end_hour = change_to_number(end_time_hour);
    int end_min = change_to_number(end_time_min);

    calculate_minutes(start_hour, end_hour, start_min, end_min); // Skicka in tiderna till calculate

}
int change_to_number(const string& time){
    istringstream iss(time);

    int number_time; // Skapa int
    iss >> number_time; // Ändra string till int

    return number_time; // Returnera int
}
string cut_to_hour(const string &time){
    auto pos = time.find(':'); // Hitta ':' starttid
    return time.substr(0, pos); // Returnera timme
}
string cut_to_min (const string &time){
    auto pos = time.find(':'); // Hitta ':' sluttid
    return time.substr(pos + 1); // Returnera minut
}
void calculate_minutes(int &start_hour, int &end_hour, int &start_min, int &end_min){
    int start_minutes = start_hour*60+start_min; // Samtliga minuter
    int end_minutes = end_hour*60+end_min; // Samtliga minuter

    const double cost = price(start_minutes, end_minutes); // Räkna ut kostnaden baserad på minuter via price
    print(cost); // Tillkalla funktion som skriver ut kostaden
}
double price(double const &start_minutes, double const &end_minutes){
    const int standard_price = 4; // Pris per minut
    const double MOMS = 1.25; // Moms på priset
    const double full_discount = 0.85; // 15% Rabatt om samtalet överstiger 30 min
    const double time_discount = 0.35; // 65% rabatt på pris/minut före 08:00 och efter 18:30
    const double minutes = end_minutes - start_minutes; // Antal minuter
    double final_price = standard_price*MOMS; // Priset är 4kr*25% som standard
    // 480 = 8:00, 1110 = 18:30 och

    // 6 möjliga start och slut komibnationer
    if(start_minutes < 480 && end_minutes <= 480){ // Start och slut 00:00 - 08:00
        final_price = final_price*time_discount*minutes; // 65% rabatt på hela samtalet 00:00 - 07:59
    }
    if (start_minutes < 480 && end_minutes >= 480 && end_minutes <= 1110){
        const double discount_minutes = 480 - start_minutes; // Antal rabatt minuter innan 8
        const double normal_minutes = minutes - discount_minutes; // Antal vanliga minuter utan rabatt
        final_price = final_price*normal_minutes + final_price*discount_minutes*time_discount; // Standard + rabatt
    }
    if(start_minutes < 480 && end_minutes > 1110 && end_minutes < 1440){
        const double discount_minutes = end_minutes - 1110 + 480 - start_minutes; // antal// minuter efter 18:30 och innan 8
        const double normal_minutes = 630; // Antal minuter 8:00-18:30
        final_price = final_price*normal_minutes + final_price*discount_minutes*time_discount; // Standard + rabatt
    }
    if(start_minutes >= 480 && start_minutes <= 1110 && end_minutes >= 480 && end_minutes <= 1110){
        final_price = final_price*minutes; // Vanlig kostnad per minut, ingen rabatt
    }
    if(start_minutes >= 480 && start_minutes < 1110 && end_minutes > 1110){
        const double discount_minutes = end_minutes - 1110; // Antal rabatterade minuter efter 18:30
        const double normal_minutes = minutes - discount_minutes; // Antal icke-rabatterade minuter 8:00-18:30
        final_price = final_price*normal_minutes + final_price*discount_minutes*time_discount;

    }
    if(start_minutes >= 1110 && end_minutes < 1440){
        final_price = final_price*time_discount*minutes;
    }

    if(minutes > 30){ // Om samtalet är längre än 30 min, 15% rabatt
        final_price = final_price*full_discount;
    }

    return final_price;
}
void print(const double &cost){
    cout << "The price for your call is: " << cost << " kr" << endl;
}


