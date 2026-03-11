#include <iostream>
#include <string>

using namespace std;

// Displays the smoothie options menu.
void displayMenu();

// Displays menu, validates input, and returns a valid selection 1-7.
int getSelection();

// Prints the current smoothie configuration.
void printConfiguration(const string &flavor, int quantity, const string &thickness, const string &whipped);

// Processes one menu selection and updates smoothie settings.
void processSelection(int selection, string &flavor, int &quantity, string &thickness, string &whipped);

int main() {
    string flavor = "Raspberry";
    int quantity = 1;
    string size = "Small";
    string thickness = "Normal Thickness";
    string whipped = "No Whipped";

    printConfiguration(flavor, quantity, thickness, whipped);

    int selection = getSelection();

    while (selection != 7) {
        processSelection(selection, flavor, quantity, thickness, whipped);
        printConfiguration(flavor, quantity, thickness, whipped);
        selection = getSelection();
    }

    cout << "Thank you for visiting Rich's Smoothie Kiosk!" << endl;
    cout << "Final Size: " << size << endl;

    return 0;
}

void displayMenu() {
    cout << "Smoothie Options:" << endl;
    cout << "1. Change the flavor" << endl;
    cout << "2. Adjust the quantity up by one" << endl;
    cout << "3. Adjust the quantity down by one" << endl;
    cout << "4. Extra Thick" << endl;
    cout << "5. Normal Thickness" << endl;
    cout << "6. Add Whipped Cream" << endl;
    cout << "7. Exit" << endl;
}

int getSelection() {
    int selection;

    while (true) {
        displayMenu();
        cout << "Please Enter your Choice (1-7):" << endl;

        if (!(cin >> selection)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid selection. Please enter a whole number from 1 to 7." << endl;
            continue;
        }

        if (selection >= 1 && selection <= 7) {
            cin.ignore(1000, '\n');
            return selection;
        }

        cout << "Invalid selection. Please enter a number from 1 to 7." << endl;
    }
}

void printConfiguration(const string &flavor, int quantity, const string &thickness, const string &whipped) {
    cout << "\nCurrent Smoothie Configuration:" << endl;
    cout << "Flavor: " << flavor << endl;
    cout << "Qty: " << quantity << endl;
    cout << "Size: Small" << endl;
    cout << thickness << endl;
    cout << whipped << endl;
    cout << endl;
}

void processSelection(int selection, string &flavor, int &quantity, string &thickness, string &whipped) {
    switch (selection) {
        case 1:
            cout << "Enter new flavor:" << endl;
            getline(cin, flavor);
            if (flavor.empty()) {
                getline(cin, flavor);
            }
            break;
        case 2:
            quantity++;
            break;
        case 3:
            if (quantity > 1) {
                quantity--;
            } else {
                cout << "Quantity cannot go below 1." << endl;
            }
            break;
        case 4:
            thickness = "Extra Thick";
            break;
        case 5:
            thickness = "Normal Thickness";
            break;
        case 6:
            whipped = "Yes Whipped";
            break;
        case 7:
            break;
        default:
            cout << "Unexpected selection. No changes made." << endl;
            break;
    }
}
