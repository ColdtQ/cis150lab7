#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

// Named constant for maximum number of unique flavors.
const int max_flavors = 4;

// Function prototypes
void printHeader();
string toUpperWord(string word);
int search(const string flavorArr[], int used, string word);
void display(const string flavorArr[], const int qtyArr[], int used);

int main() {
    string flavorArr[max_flavors];
    int qtyArr[max_flavors] = {0};
    int used = 0;
    string line;
    bool done = false;

    printHeader();

    // Read votes until GOBLUE is entered.
    while (!done) {
        cout << "Enter flavor vote(s) (type GoBlue to finish): " << endl;
        getline(cin, line);

        stringstream input(line);
        string flavor;

        while (input >> flavor) {
            flavor = toUpperWord(flavor);

            if (flavor == "GOBLUE") {
                done = true;
                break;
            }

            int index = search(flavorArr, used, flavor);
            if (index >= 0) {
                qtyArr[index] = qtyArr[index] + 1;
            } else if (used < max_flavors) {
                flavorArr[used] = flavor;
                qtyArr[used] = 1;
                used = used + 1;
            } else {
                cout << "Error: maximum number of different flavors reached." << endl;
            }
        }
    }

    display(flavorArr, qtyArr, used);
    return 0;
}

// Prints shop heading.
void printHeader() {
    cout << "--- Rich's Smoothie Shop ---" << endl;
}

// Converts one word to uppercase.
string toUpperWord(string word) {
    for (int i = 0; i < static_cast<int>(word.length()); i++) {
        word[i] = static_cast<char>(toupper(static_cast<unsigned char>(word[i])));
    }
    return word;
}

// Searches an array for a flavor.
int search(const string flavorArr[], int used, string word) {
    for (int i = 0; i < used; i++) {
        if (flavorArr[i] == word) {
            return i;
        }
    }
    return -1;
}

// Displays final vote report.
void display(const string flavorArr[], const int qtyArr[], int used) {
    cout << endl;
    cout << "Flavor Voting Results" << endl;
    cout << left << setw(14) << "Flavor" << "Votes" << endl;
    cout << left << setw(14) << "--------" << "------" << endl;

    for (int i = 0; i < used; i++) {
        cout << left << setw(14) << flavorArr[i] << qtyArr[i] << endl;
    }
}
