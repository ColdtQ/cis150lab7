// Trevor Romano - cis150 lab 7
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printHeading() {
    cout << "--- smoothie shop ---" << endl;
}

int getSelection(const string flavors[], const double prices[], int size) {
    cout << fixed << setprecision(2);
    cout << "smoothie menu" << endl;

    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << left << setw(12) << flavors[i]
             << "$" << right << setw(5) << prices[i] << endl;
    }

    int choice = 0;
    while (choice < 1 || choice > size) {
        cout << "enter menu number (1-" << size << "):" << endl;
        cin >> choice;
        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
            cout << "invalid input." << endl;
        }
    }

    return choice - 1;
}

double printReceipt(const string& flavor, double price) {
    double stateTax = price * 0.06;
    double cityTax = price * 0.015;
    double total = price + stateTax + cityTax;

    printHeading();
    cout << fixed << setprecision(2);
    cout << "receipt" << endl;
    cout << "flavor:    " << flavor << endl;
    cout << "price:     $" << price << endl;
    cout << "state tax: $" << stateTax << endl;
    cout << "city tax:  $" << cityTax << endl;
    cout << "total:     $" << total << endl;

    return total;
}

int main() {
    const int menuSize = 4;
    string flavors[menuSize] = {"chocolate", "strawberry", "protein", "peach"};
    double prices[menuSize] = {5.45, 6.99, 8.89, 7.45};

    printHeading();
    int selected = getSelection(flavors, prices, menuSize);
    double total = printReceipt(flavors[selected], prices[selected]);

    cout << fixed << setprecision(2);
    cout << "returned total: $" << total << endl;
    return 0;
}
