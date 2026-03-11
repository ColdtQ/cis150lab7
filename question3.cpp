#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Prints the smoothie shop heading.
void printHeading();

// Displays menu, prompts for selection number, and returns user's selection.
int displayAndSelect(const string flavorArr[], const double priceArr[], int size);

// Prints receipt details and returns total amount.
double printReceipt(const string &selectedFlavor, double price, double stateTax, double cityTax);

int main() {
    const int menu_size = 4;
    string flavorArr[menu_size] = {"Chocolate", "Strawberry", "Protein", "Peach"};
    double priceArr[menu_size] = {5.45, 6.99, 8.89, 7.45};

    printHeading();
    int selectionNumber = displayAndSelect(flavorArr, priceArr, menu_size);

    int selectedIndex = selectionNumber - 1;
    string selectedFlavor = flavorArr[selectedIndex];
    double selectedPrice = priceArr[selectedIndex];

    double stateTax = selectedPrice * 0.06;
    double cityTax = selectedPrice * 0.015;

    double total = printReceipt(selectedFlavor, selectedPrice, stateTax, cityTax);

    cout << fixed << setprecision(2);
    cout << "Returned Total: $" << total << endl;

    return 0;
}

void printHeading() {
    cout << "--- Rich's Smoothie Shop ---" << endl;
}

int displayAndSelect(const string flavorArr[], const double priceArr[], int size) {
    cout << fixed << setprecision(2);
    cout << "Smoothie Menu" << endl;

    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << left << setw(12) << flavorArr[i]
             << "$" << right << setw(5) << priceArr[i] << endl;
    }

    cout << "Please Enter Selection Number:" << endl;

    int selectionNumber;
    cin >> selectionNumber;

    return selectionNumber;
}

double printReceipt(const string &selectedFlavor, double price, double stateTax, double cityTax) {
    double total = price + stateTax + cityTax;

    printHeading();

    cout << fixed << setprecision(2);
    cout << "Receipt" << endl;
    cout << "Flavor:     " << selectedFlavor << endl;
    cout << "Price:      $" << price << endl;
    cout << "State Tax:  $" << stateTax << endl;
    cout << "City Tax:   $" << cityTax << endl;
    cout << "Total:      $" << total << endl;
    cout << "Thank you for your order!" << endl;

    return total;
}
