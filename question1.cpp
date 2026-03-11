// Trevor Romano - cis150 lab 7
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string toLowerWord(string text) {
    for (int i = 0; i < (int)text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

int findFlavor(const vector<string>& flavors, const string& flavor) {
    for (int i = 0; i < (int)flavors.size(); i++) {
        if (flavors[i] == flavor) {
            return i;
        }
    }
    return -1;
}

void printResults(const vector<string>& flavors, const vector<int>& votes) {
    cout << "--- smoothie shop ---" << endl;
    cout << "vote results" << endl;
    cout << left << setw(14) << "flavor" << "votes" << endl;
    cout << left << setw(14) << "------" << "-----" << endl;

    for (int i = 0; i < (int)flavors.size(); i++) {
        cout << left << setw(14) << flavors[i] << votes[i] << endl;
    }
}

int main() {
    vector<string> flavors;
    vector<int> votes;
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

            int index = findFlavor(flavors, flavor);
            if (index >= 0) {
                votes[index] = votes[index] + 1;
            } else {
                flavors.push_back(flavor);
                votes.push_back(1);
            }
        }
    }

    printResults(flavors, votes);
    return 0;
}
