#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
int getSelection();
void printConfiguration(string flavor, int qty, string size, string thickness, string whipped);
void processSelection(int selection, string &flavor, int &qty, string &size, string &thickness, string &whipped);

int main() {
    string flavor = "Raspberry";
    int qty = 1;
    string size = "Small";
    string thickness = "Normal Thickness";
    string whipped = "No Whipped";

    int selection = getSelection();

    while (selection != 7) {
        processSelection(selection, flavor, qty, size, thickness, whipped);
        printConfiguration(flavor, qty, size, thickness, whipped);
        selection = getSelection();
    }

    cout << "Thank you for using the smoothie kiosk!" << endl;
    return 0;
}

// Displays the option menu.
void displayMenu() {
    cout << "Smoothie Options:" << endl;
    cout << "1. Change the flavor" << endl;
    cout << "2. Adjust the quantity up by one" << endl;
    cout << "3. Adjust the quantity down by one" << endl;
    cout << "4. Extra Thick" << endl;
    cout << "5. Normal Thickness" << endl;
    cout << "6. Add Whipped Cream" << endl;
    cout << "7. Exit" << endl;
    cout << "Please Enter your Choice (1-7):" << endl;
}

// Gets a validated menu selection from 1 to 7.
int getSelection() {
    int selection;

    while (true) {
        displayMenu();
        cin >> selection;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (selection >= 1 && selection <= 7) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return selection;
        }
    }
}

// Prints current smoothie settings.
void printConfiguration(string flavor, int qty, string size, string thickness, string whipped) {
    cout << "Current Smoothie Configuration" << endl;
    cout << "Flavor: " << flavor << endl;
    cout << "Quantity: " << qty << endl;
    cout << "Size: " << size << endl;
    cout << "Thickness: " << thickness << endl;
    cout << "Whipped: " << whipped << endl;
}

// Processes selection with switch statement.
void processSelection(int selection, string &flavor, int &qty, string &size, string &thickness, string &whipped) {
    switch (selection) {
        case 1:
            cout << "Enter new flavor:" << endl;
            getline(cin, flavor);
            break;
        case 2:
            qty = qty + 1;
            break;
        case 3:
            if (qty > 1) {
                qty = qty - 1;
            } else {
                cout << "Warning: quantity cannot go below 1." << endl;
            }
            break;
        case 4:
            thickness = "Extra Thick";
            break;
        case 5:
            thickness = "Normal Thickness";
            break;
        case 6:
            whipped = "Whipped";
            break;
        case 7:
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }

    // Size is kept as part of the configuration.
    (void)size;
}
