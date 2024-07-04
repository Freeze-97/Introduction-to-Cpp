// Skriven av Tommy Yasi/toya1800 2018-01-10
// Laboration 5, Assignment_2.cpp
// Binärsökning i en array

#include <iostream>
using namespace std;

// Funktioner
int binary_search(const int arr[], size_t sz, int target);

int main() {
    // Deklarera array med värden
    const int SIZE = 100;
    int numbers[SIZE];
    for (size_t i = 0; i < SIZE; ++i) { // index 0 = 0, index 44 = 44 osv
        numbers[i] = i;
    }

    // Skriv in det nummer du söker
    cout << "Type a number to see if it's available in the array: " << endl << endl;
    int searchnumber;
    cin >> searchnumber;

    int result = binary_search(numbers, SIZE, searchnumber);

    if(result == -1){
        cout << "The number is not in the array." << endl;
    }
    else{
        cout << "The number is in index: " << result << endl;
    }

    int negativeNumber = binary_search(numbers, SIZE, -10); // Negativa index finns inte
    if (negativeNumber != -1) {
        cout << negativeNumber << " It should return -1 and nothing else!" << endl;
    }
    int sizeIDX = binary_search(numbers, SIZE, SIZE); // 100, vilket är större än högsta index
    if (sizeIDX != -1) {
        cout << sizeIDX << " It should return -1 and nothing else!" << endl;
    }


    return 0;
}
int binary_search(const int arr[], size_t sz, int target){
    int first = 0; // Index 0
    int last = sz-1; // Sista Index

    while(first <= last){
        int m = ((first + last) / 2); // Mellan elementet
        if(arr[m] < target){
            first = m+1; // Halva första delen
        }
        else if(arr[m] > target){
            last = m-1; // Halva sista delen
        }
        else{
            return m;
        }
    }
    
    return -1;
}
