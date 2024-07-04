// Skriven av Tommy Yasi/toya1800 2018-11-28
// Laboration 3, Assignment_1.cpp
// Byt ut fot mot hand i meningarna

#include <iostream> // cout och cin
#include <string> // string-klass

using namespace std; // Bibliotek

int main() {

    string const inText1 = "Foten är en kroppsdel som förekommer mycket i våra uttryck.";
    string const inText2 = "På stående fot betyder omedelbart, utan förberedelse.";
    string const inText3 = "Försätta på fri fot betyder att ge någon friheten.";
    string const inText4 = "Sätta foten i munnen betyder att göra bort sig.";
    string const inText5 = "Få om bakfoten betyder att missuppfatta något.";
    string const inText6 = "Skrapa med foten betyder att visa sig underdånig eller ödmjuk.";
    string const inText7 = "Stryka på foten betyder att tvingas ge upp.";
    string const inText8 = "Leva på stor fot betyder att föra ett dyrbart eller slösaktigt leverne.";
    string const inText9 = "Varför fick du foten???";

    // Alla meningar ihopsatta
    string fullText = inText1 + inText2 + inText3 + inText4 + inText5 + inText6 + inText7 + inText8 + inText9;

    // Istället för string::size_type så används auto
    auto bigFot = fullText.find("Fot"); // Hitta alla "Fot"
    while(bigFot != string::npos) {
        fullText.replace(bigFot, 3, "Hand" ); // Ersätt "Fot" med "Hand"
        bigFot = fullText.find("Fot"); // Sök efter nästa "Fot"
    }

    auto littleFot = fullText.find("fot"); // Hitta alla "fot"
    while (littleFot != string::npos) {
        fullText.replace(littleFot, 3, "hand" ); // Ersätt "fot" med "hand"
        littleFot = fullText.find("fot"); // Sök efter nästa "fot"
    }

    auto dot = fullText.find('.'); // Hitta punkt
    while (dot != string::npos) {
        fullText.insert(dot + 1, "\n"); // Lägg till "\n" ett steg efter punkten
        dot = fullText.find('.', dot + 1); // Hitta nästa punkt plus ett steg

    }
    cout << fullText << endl; // Skriver ut hela texten med ändringarna
    return 0;
}
