#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Function prototypes
void printHeader();
string toUpperWord(string word);
int search(vector<string> &wordVec, string word);
void display(vector<string> &wordVec, vector<int> &freqVec);

int main() {
    vector<string> flavorVec;
    vector<int> qtyVec;
    string line;
    bool done = false;

    printHeader();

    // Keep reading lines until sentinel is encountered.
    while (!done) {
        cout << "Enter flavor vote(s) (type GoBlue to finish): " << endl;
        getline(cin, line);

        stringstream input(line);
        string flavor;

        // Process every flavor token on the line.
        while (input >> flavor) {
            flavor = toUpperWord(flavor);

            // Stop immediately when sentinel is found.
            if (flavor == "GOBLUE") {
                done = true;
                break;
            }

            int index = search(flavorVec, flavor);
            if (index >= 0) {
                qtyVec[index] = qtyVec[index] + 1;
            } else {
                flavorVec.push_back(flavor);
                qtyVec.push_back(1);
            }
        }
    }

    display(flavorVec, qtyVec);
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

// Searches for a word in a vector and returns index or -1.
int search(vector<string> &wordVec, string word) {
    for (int i = 0; i < static_cast<int>(wordVec.size()); i++) {
        if (wordVec[i] == word) {
            return i;
        }
    }
    return -1;
}

// Displays the flavor vote report.
void display(vector<string> &wordVec, vector<int> &freqVec) {
    cout << endl;
    cout << "Flavor Voting Results" << endl;
    cout << left << setw(14) << "Flavor" << "Votes" << endl;
    cout << left << setw(14) << "--------" << "------" << endl;

    for (int i = 0; i < static_cast<int>(wordVec.size()); i++) {
        cout << left << setw(14) << wordVec[i] << freqVec[i] << endl;
    }
}
