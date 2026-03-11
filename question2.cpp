#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

const int max_flavors = 4;

// Prints the smoothie shop header and table headings.
void printHeader();

// Converts text to uppercase and returns the converted string.
string toUpperCase(const string &text);

// Returns index of flavor in array or -1 if not found.
int search(const string flavorArr[], int usedSize, const string &word);

// Displays all stored flavor votes.
void display(const string flavorArr[], const int voteArr[], int usedSize);

int main() {
    string flavorArr[max_flavors];
    int voteArr[max_flavors] = {0};
    int uniqueCount = 0;

    string line;
    bool done = false;

    while (!done) {
        cout << "Enter Smoothie flavor(s) to vote for:" << endl;
        getline(cin, line);

        stringstream input(line);
        string flavor;

        while (input >> flavor) {
            flavor = toUpperCase(flavor);

            if (flavor == "GOBLUE") {
                done = true;
                break;
            }

            int foundIndex = search(flavorArr, uniqueCount, flavor);

            if (foundIndex >= 0) {
                voteArr[foundIndex]++;
            } else {
                if (uniqueCount < max_flavors) {
                    flavorArr[uniqueCount] = flavor;
                    voteArr[uniqueCount] = 1;
                    uniqueCount++;
                } else {
                    cout << "Error: maximum number of different flavors reached." << endl;
                }
            }
        }
    }

    display(flavorArr, voteArr, uniqueCount);

    return 0;
}

void printHeader() {
    cout << "--- Rich's Smoothie Shop ---" << endl;
    cout << "Flavor Voting Results" << endl;
    cout << left << setw(14) << "Flavor" << "Votes" << endl;
    cout << left << setw(14) << "--------" << "------" << endl;
}

string toUpperCase(const string &text) {
    string upperText = text;

    for (size_t i = 0; i < upperText.length(); i++) {
        upperText[i] = static_cast<char>(toupper(static_cast<unsigned char>(upperText[i])));
    }

    return upperText;
}

int search(const string flavorArr[], int usedSize, const string &word) {
    for (int i = 0; i < usedSize; i++) {
        if (flavorArr[i] == word) {
            return i;
        }
    }

    return -1;
}

void display(const string flavorArr[], const int voteArr[], int usedSize) {
    printHeader();

    for (int i = 0; i < usedSize; i++) {
        cout << left << setw(14) << flavorArr[i] << voteArr[i] << endl;
    }
}
