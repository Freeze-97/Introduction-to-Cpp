// Skriven av Tommy Yasi/toya1800 2018-01-06
// Laboration 5, Assignment_1A.cpp

#include <iostream> // cin, cout
#include <iomanip> // setw()
#include <random> // slumpning
using namespace std; //Bibliotek

// Funktionsprototyp
void randomize (int arr[], size_t arr_size); // Slumpa tal till array
int occuredNumber(const int arr[], size_t arr_size, int searchNumber); // Antal gånger en siffra förekommer i arrayen
void averageNumber(const int arr[], size_t arr_size); // Beräkna medelvärdet och skriv ut det
void maxMinNumber(const int arr[], size_t arr_size); // Visa största och minsta värde
void sortArray(int arr[], size_t arr_size); // Sorterar arrayen i stigande ordning
int mostNumber(const int arr[], size_t arr_size); // Numret som förekommer oftast i arrayen
void showArray(const int arr[], size_t arr_size); // Visa array

int main() {
    // Deklarera array
    const size_t SIZE = 600;
    int integers[SIZE];

    // Slumpa nummer
    randomize(integers, SIZE);

    // Kopiera till en ny array
    int newArray[SIZE];
    for(auto idx = 0; idx < SIZE; idx++){
        newArray[idx] = integers[idx];
    }

    // Medelvärde
    averageNumber(newArray, SIZE);

    // Största och minsta värde
    maxMinNumber(newArray, SIZE);

    // Siffran som förekommer mest av alla
    int most_number = mostNumber(newArray, SIZE);
    cout << "Most occuring number: " << most_number << endl;

    // Sortera arrayens siffror
    sortArray(newArray, SIZE);

    // Antal gånger en siffra förekommer
    cout << "Type a number and see how many times it occurred: " << endl;
    int searchNumber;
    cin >> searchNumber;
    int amountNumber = occuredNumber(newArray, SIZE, searchNumber);
    cout << "The number occurred " << amountNumber << " times." << endl;



    return 0;
}
// Funktionsdefinition
void randomize (int arr[], size_t arr_size){
    // Initiera slumpning
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    // Slumpa tal till array
    for(auto idx = 0; idx < arr_size; idx++){
        arr[idx] = dist(gen);
    }
}
void showArray(const int arr[], size_t arr_size){
    for(auto i = 0; i < arr_size; i++){
        cout << setw(5) << arr[i];
    }
}
int occuredNumber(const int arr[], size_t arr_size, int searchNumber){
    // Förekomst av en siffra
    int amountNumber = 0;
    for (auto idx = 0; idx < arr_size; idx++) {
        if (arr[idx] == searchNumber) {
            amountNumber++;
        }
    }
        return amountNumber;
}
void averageNumber(const int arr[], size_t arr_size){
    // Beräkna och skriv ut medelvärdet
    int sum = 0;
    float average = 0;
    for(auto idx = 0; idx < arr_size; idx++){
        sum += arr[idx];
    }
    average = static_cast<float>(sum) / arr_size; // static_cast för att ändra till float
    cout << fixed << setprecision(2);
    cout << "The average number is: " << average << endl;
}
void maxMinNumber(const int arr[], size_t arr_size){
    // Beräkna och skriv ut största och minsta tal
    int max = arr[0];
    int min = arr[0];

    for(auto idx = 0; idx < arr_size; idx++){
        if(arr[idx] > max){
            max = arr[idx];
        }
        if(arr[idx] < min){
            min = arr[idx];
        }
    }
    cout << "The maximum element is: " << max << endl;
    cout << "The minimum element is: " << min << endl;
}
void sortArray(int arr[], size_t arr_size){
    // Jämför talet till höger och kollar om det är större
    for(auto pass = 0; pass < arr_size - 1; pass++) {
        for (auto i = 0; i < arr_size - 1; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    cout << endl;
    cout << "Sorted array: " << endl;
    for(auto i = 0; i < arr_size; i++){
        cout << arr[i] << " ";
        if(arr[i] != arr[i+1]){ // Om siffran till höger är större, byt rad
            cout << endl;
        }
    }
    cout << endl;
}
int mostNumber(const int arr[], size_t arr_size){
    
     int highValue = 100;
    const int SIZE = highValue + 1;
    int container[SIZE];

    // Lagra atnal gånger en siffra förekommer i motsvarande index
    for(int i = 1; i < SIZE; i++){
        container[i] = occuredNumber(arr, arr_size, i);
    }

    // Hitta siffran som förekommer mest
    int max_idx = 0;
    for(auto idx = 0; idx < SIZE; idx++) {
        if (container[idx] > container[max_idx]) {
            max_idx = idx;
        }
    }
    return max_idx;
}