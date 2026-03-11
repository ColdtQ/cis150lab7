// Trevor Romano - cis150 lab 7
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "smoothie options:" << endl;
    cout << "1. change flavor" << endl;
    cout << "2. add one to quantity" << endl;
    cout << "3. subtract one from quantity" << endl;
    cout << "4. set extra thick" << endl;
    cout << "5. set normal thickness" << endl;
    cout << "6. add whipped cream" << endl;
    cout << "7. exit" << endl;
}

int getSelection() {
    int selection = 0;
    while (selection < 1 || selection > 7) {
        displayMenu();
        cout << "enter choice (1-7):" << endl;
        cin >> selection;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            selection = 0;
            cout << "invalid input." << endl;
        }
    }

    cin.ignore(1000, '\n');
    return selection;
}

void printConfiguration(const string& flavor, int quantity, const string& thickness, const string& whipped) {
    cout << "\ncurrent smoothie configuration:" << endl;
    cout << "flavor: " << flavor << endl;
    cout << "qty: " << quantity << endl;
    cout << "size: small" << endl;
    cout << "thickness: " << thickness << endl;
    cout << "whipped: " << whipped << endl;
}

void processSelection(int selection, string& flavor, int& quantity, string& thickness, string& whipped) {
    if (selection == 1) {
        cout << "enter new flavor:" << endl;
        getline(cin, flavor);
        if (flavor == "") {
            flavor = "raspberry";
        }
    } else if (selection == 2) {
        quantity = quantity + 1;
    } else if (selection == 3) {
        if (quantity > 1) {
            quantity = quantity - 1;
        } else {
            cout << "quantity cannot go below 1." << endl;
        }
    } else if (selection == 4) {
        thickness = "extra thick";
    } else if (selection == 5) {
        thickness = "normal thickness";
    } else if (selection == 6) {
        whipped = "yes";
    }
}

int main() {
    string flavor = "raspberry";
    int quantity = 1;
    string thickness = "normal thickness";
    string whipped = "no";

    printConfiguration(flavor, quantity, thickness, whipped);

    int selection = getSelection();
    while (selection != 7) {
        processSelection(selection, flavor, quantity, thickness, whipped);
        printConfiguration(flavor, quantity, thickness, whipped);
        selection = getSelection();
    }

    cout << "goodbye." << endl;
    return 0;
}
