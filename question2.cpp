// Trevor Romano - cis150 lab 7
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

const int maxFlavors = 4;

string toLowerWord(string text) {
    for (int i = 0; i < (int)text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

int findFlavor(const string flavors[], int used, const string& flavor) {
    for (int i = 0; i < used; i++) {
        if (flavors[i] == flavor) {
            return i;
        }
    }
    return -1;
}

void printResults(const string flavors[], const int votes[], int used) {
    cout << "--- smoothie shop ---" << endl;
    cout << "vote results" << endl;
    cout << left << setw(14) << "flavor" << "votes" << endl;
    cout << left << setw(14) << "------" << "-----" << endl;

    for (int i = 0; i < used; i++) {
        cout << left << setw(14) << flavors[i] << votes[i] << endl;
    }
}

int main() {
    string flavors[maxFlavors];
    int votes[maxFlavors] = {0};
    int used = 0;
    string line;
    bool done = false;

    while (!done) {
        cout << "enter smoothie flavor(s), type x to exit:" << endl;
        getline(cin, line);

        stringstream input(line);
        string flavor;

        while (input >> flavor) {
            flavor = toLowerWord(flavor);

            if (flavor == "x") {
                done = true;
                break;
            }

            int index = findFlavor(flavors, used, flavor);
            if (index >= 0) {
                votes[index] = votes[index] + 1;
            } else if (used < maxFlavors) {
                flavors[used] = flavor;
                votes[used] = 1;
                used = used + 1;
            } else {
                cout << "maximum number of unique flavors reached." << endl;
            }
        }
    }

    printResults(flavors, votes, used);
    return 0;
}
