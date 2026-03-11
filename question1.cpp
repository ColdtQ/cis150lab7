#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

// Prints the smoothie shop header and table headings.
void printHeader();

// Converts text to uppercase and returns the converted string.
string toUpperCase(const string &text);

// Returns index of word in wordVec or -1 if word is not found in wordVec.
int search(vector<string> &wordVec, string word);

// Displays the word frequency information.
void display(vector<string> &wordVec, vector<int> &freqVec);

int main() {
    vector<string> flavorVec;
    vector<int> voteVec;

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

            int foundIndex = search(flavorVec, flavor);
            if (foundIndex >= 0) {
                voteVec[foundIndex]++;
            } else {
                flavorVec.push_back(flavor);
                voteVec.push_back(1);
            }
        }
    }

    display(flavorVec, voteVec);

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

int search(vector<string> &wordVec, string word) {
    for (size_t i = 0; i < wordVec.size(); i++) {
        if (wordVec[i] == word) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void display(vector<string> &wordVec, vector<int> &freqVec) {
    printHeader();

    for (size_t i = 0; i < wordVec.size(); i++) {
        cout << left << setw(14) << wordVec[i] << freqVec[i] << endl;
    }
}
