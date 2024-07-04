// Skriven av Tommy Yasi/toya1800 2018-01-08
// Laboration 5, Assignment_1B.cpp

#include <iostream> // cin, cout
#include <vector> // vector
#include <algorithm> // find()
#include <iomanip> // setw()
#include <random> // slumpning
using namespace std; //Bibliotek


int main() {
    // Deklarera vector
    const size_t SIZE = 600;
    vector<int> integers;

    constexpr int highValue = 100; // Används också för container

    // Initiera slumpning
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> dist(1, highValue);

    // Slumpade tal läggs in i vector
    for(int i=0; i < SIZE; i++){
        integers.push_back(dist(gen));
    }

    vector<int> newIntegers; // Ny vektor
    newIntegers = integers; // Kopiera till den nya vektorn

    // Beräkna medelvärde
    int sum = 0;
    for(auto e: newIntegers){ // Addera varje värde i alla index med varandra
        sum += e;
    }

    double average = static_cast<double>(sum) / newIntegers.size();
    cout << fixed << setprecision(2); // 2 decimaler
    cout << "The average number is: " << average << endl;

    // Max och min värde
    int max = *(max_element(newIntegers.begin(), newIntegers.end()));
    int min = *(min_element(newIntegers.begin(), newIntegers.end()));

    cout << "Maximum number in the vector is: " << max << endl;
    cout << "Minimum number in the vector is: " << min << endl << endl;

    // Sortera vectorn
    sort(newIntegers.begin(), newIntegers.end());

    // Skriv ut vektorn med siffrorna på varsin rad
    cout << "All numbers: " << endl;
    for(size_t i = 0; i < SIZE; i++){
        cout << newIntegers[i] << " ";
        if(newIntegers[i] < newIntegers[i+1]){
            cout << endl;
        }
    }

    // VIlken siffra som förekommer mest
    vector<int> container (highValue+1,0);

    for(int i = 1; i < SIZE; i++) {
        const int val = newIntegers[i];
        ++container[val];
    }

    auto mostIterator = (max_element(container.begin(), container.end()));
    int mostNumber = distance(container.begin(), mostIterator); // Antal index från begin () till mostIterator
    cout << endl;
    cout << "The number that occured the most times is: " << mostNumber << endl << endl;

    // Beräkna förekomsten av en siffra, inmatad av användaren
    int searchNumber;
    cout << "Enter a number to see how many times it oocured:" << endl;
    cin >> searchNumber;

    int occuredNumber = count(newIntegers.begin(), newIntegers.end(), searchNumber);
    cout << "Number " << searchNumber << " appears " << occuredNumber << " times." << endl;


    return 0;
}

